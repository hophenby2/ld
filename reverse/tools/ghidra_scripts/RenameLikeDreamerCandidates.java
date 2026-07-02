// Rename candidate functions for Like Dreamer reverse reconstruction.
// @category LikeDreamer
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import ghidra.program.model.symbol.SourceType;
import ghidra.util.task.ConsoleTaskMonitor;
import java.io.*;

public class RenameLikeDreamerCandidates extends GhidraScript {
    private static class RenameItem {
        String addr, name;
        RenameItem(String a, String n) { addr = a; name = n; }
    }
    private String safeName(String s) { return s.replaceAll("[^A-Za-z0-9_.-]+", "_"); }
    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        File outDir = new File(args.length > 0 ? args[0] : ".");
        outDir.mkdirs();
        Listing listing = currentProgram.getListing();
        FunctionManager fm = currentProgram.getFunctionManager();
        RenameItem[] items = new RenameItem[] {
            new RenameItem("1400f4f70", "game_startup_init_candidate"),
            new RenameItem("1400ced90", "load_primary_resources_candidate"),
            new RenameItem("1400d0e50", "load_secondary_localized_resources_candidate"),
            new RenameItem("1401b23b0", "dxarchive_set_key_candidate"),
            new RenameItem("140155c60", "dxlib_load_graph_candidate"),
            new RenameItem("140155bf0", "dxlib_load_div_graph_candidate"),
            new RenameItem("140115880", "replay_or_save_handler_candidate_A"),
            new RenameItem("1401171d0", "replay_handler_candidate_B"),
            new RenameItem("140114580", "replay_or_save_handler_candidate_C"),
            new RenameItem("1401019e0", "config_handler_candidate"),
            new RenameItem("1400d0a30", "save_init_or_reset_candidate")
        };
        PrintWriter log = new PrintWriter(new OutputStreamWriter(new FileOutputStream(new File(outDir, "rename-log.tsv")), "UTF-8"));
        log.println("address\told_name\tnew_name\tstatus");
        for (RenameItem item: items) {
            Address addr = toAddr(item.addr);
            Function f = fm.getFunctionAt(addr);
            if (f == null) f = fm.getFunctionContaining(addr);
            if (f == null) {
                log.printf("%s\t\t%s\tNO_FUNCTION%n", item.addr, item.name);
                continue;
            }
            String old = f.getName();
            try {
                f.setName(item.name, SourceType.USER_DEFINED);
                log.printf("%s\t%s\t%s\tOK%n", item.addr, old, item.name);
            } catch (Exception e) {
                log.printf("%s\t%s\t%s\tERR:%s%n", item.addr, old, item.name, e.getMessage());
            }
        }
        log.close();

        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        File decDir = new File(outDir, "renamed-decompiled");
        decDir.mkdirs();
        for (RenameItem item: items) {
            Function f = fm.getFunctionAt(toAddr(item.addr));
            if (f == null) f = fm.getFunctionContaining(toAddr(item.addr));
            if (f == null) continue;
            DecompileResults res = ifc.decompileFunction(f, 90, new ConsoleTaskMonitor());
            File out = new File(decDir, item.addr + "_" + safeName(f.getName()) + ".c");
            PrintWriter pw = new PrintWriter(new OutputStreamWriter(new FileOutputStream(out), "UTF-8"));
            pw.println("// Function: " + f.getName() + " @ " + f.getEntryPoint());
            pw.println("// Decompile completed: " + res.decompileCompleted());
            if (res.decompileCompleted() && res.getDecompiledFunction() != null) {
                pw.println(res.getDecompiledFunction().getC());
            } else {
                pw.println("// " + res.getErrorMessage());
            }
            pw.close();
        }
    }
}
