// Export Like Dreamer reverse-analysis anchors from a Ghidra program.
// @category LikeDreamer
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.util.task.ConsoleTaskMonitor;
import java.io.*;
import java.util.*;

public class ExportLikeDreamerAnchors extends GhidraScript {
    private String esc(String s) {
        if (s == null) return "";
        return s.replace("\\", "\\\\").replace("\t", "\\t").replace("\r", "\\r").replace("\n", "\\n");
    }
    private String safeName(String s) {
        return s.replaceAll("[^A-Za-z0-9_.-]+", "_");
    }
    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        File outDir = new File(args.length > 0 ? args[0] : ".");
        outDir.mkdirs();
        Listing listing = currentProgram.getListing();
        FunctionManager fm = currentProgram.getFunctionManager();
        ReferenceManager rm = currentProgram.getReferenceManager();

        String[] targets = new String[] {
            "VanillaFever11",
            "media\\\\text\\\\text01.csv", "media\\text\\text01.csv",
            "media\\\\system\\\\TitleLogo.png", "media\\system\\TitleLogo.png",
            "media\\\\bgm\\\\Stage1.ogg", "media\\bgm\\Stage1.ogg",
            "replay\\\\LD_replay%02d.dat", "replay\\LD_replay%02d.dat",
            "save\\\\save.dat", "save\\save.dat",
            "save\\\\config.dat", "save\\config.dat",
            "Failed to initialize SteamAPI.", "SteamAPI_Init", "DXBDXARC", "DxArchive_.cpp", "DxLib"
        };

        PrintWriter funcs = new PrintWriter(new OutputStreamWriter(new FileOutputStream(new File(outDir, "functions.tsv")), "UTF-8"));
        funcs.println("entry\tname\tbody\tsource_type\tparam_count");
        int fcount = 0;
        for (Function f : fm.getFunctions(true)) {
            funcs.printf("%s\t%s\t%s\t%s\t%d%n", f.getEntryPoint(), esc(f.getName()), f.getBody(), f.getSymbol().getSource(), f.getParameterCount());
            fcount++;
        }
        funcs.close();

        PrintWriter strings = new PrintWriter(new OutputStreamWriter(new FileOutputStream(new File(outDir, "defined-strings.tsv")), "UTF-8"));
        strings.println("address\tvalue");
        List<Data> stringData = new ArrayList<>();
        DataIterator it = listing.getDefinedData(true);
        while (it.hasNext()) {
            Data d = it.next();
            Object v = null;
            try { v = d.getValue(); } catch (Exception e) { }
            if (v instanceof String) {
                String s = (String)v;
                strings.printf("%s\t%s%n", d.getMinAddress(), esc(s));
                stringData.add(d);
            }
        }
        strings.close();

        Map<String, Set<Function>> targetFunctions = new LinkedHashMap<>();
        PrintWriter xrefs = new PrintWriter(new OutputStreamWriter(new FileOutputStream(new File(outDir, "anchor-xrefs.tsv")), "UTF-8"));
        xrefs.println("target\tstring_address\tstring_value\tref_from\tfunction_entry\tfunction_name");
        for (Data d : stringData) {
            String s = (String)d.getValue();
            for (String target : targets) {
                if (!s.contains(target)) continue;
                ReferenceIterator refs = rm.getReferencesTo(d.getMinAddress());
                boolean any = false;
                while (refs.hasNext()) {
                    any = true;
                    Reference ref = refs.next();
                    Address from = ref.getFromAddress();
                    Function fn = fm.getFunctionContaining(from);
                    String fe = fn == null ? "" : fn.getEntryPoint().toString();
                    String fnn = fn == null ? "" : fn.getName();
                    xrefs.printf("%s\t%s\t%s\t%s\t%s\t%s%n", esc(target), d.getMinAddress(), esc(s), from, fe, esc(fnn));
                    if (fn != null) targetFunctions.computeIfAbsent(target, k -> new LinkedHashSet<>()).add(fn);
                }
                if (!any) {
                    xrefs.printf("%s\t%s\t%s\t\t\t%n", esc(target), d.getMinAddress(), esc(s));
                }
            }
        }
        xrefs.close();

        PrintWriter summary = new PrintWriter(new OutputStreamWriter(new FileOutputStream(new File(outDir, "summary.md")), "UTF-8"));
        summary.println("# Ghidra Export Summary");
        summary.println();
        summary.println("- Program: `" + currentProgram.getName() + "`");
        summary.println("- Image base: `" + currentProgram.getImageBase() + "`");
        summary.println("- Functions: " + fcount);
        summary.println("- Defined strings: " + stringData.size());
        summary.println();
        summary.println("## Anchor functions");
        for (String target : targetFunctions.keySet()) {
            summary.println();
            summary.println("### `" + target + "`");
            for (Function fn : targetFunctions.get(target)) {
                summary.println("- `" + fn.getEntryPoint() + "` `" + fn.getName() + "`");
            }
        }

        File decompDir = new File(outDir, "decompiled-anchors");
        decompDir.mkdirs();
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        Set<Function> all = new LinkedHashSet<>();
        for (Set<Function> s : targetFunctions.values()) all.addAll(s);
        int n = 0;
        for (Function fn : all) {
            if (n++ >= 80) break;
            DecompileResults res = ifc.decompileFunction(fn, 60, new ConsoleTaskMonitor());
            File out = new File(decompDir, fn.getEntryPoint().toString() + "_" + safeName(fn.getName()) + ".c");
            PrintWriter pw = new PrintWriter(new OutputStreamWriter(new FileOutputStream(out), "UTF-8"));
            pw.println("// Function: " + fn.getName() + " @ " + fn.getEntryPoint());
            pw.println("// Decompile completed: " + res.decompileCompleted());
            if (res.decompileCompleted() && res.getDecompiledFunction() != null) {
                pw.println(res.getDecompiledFunction().getC());
            } else {
                pw.println("// " + res.getErrorMessage());
            }
            pw.close();
        }
        summary.println();
        summary.println("Decompiled anchor functions written: " + Math.min(n, 80));
        summary.close();
    }
}
