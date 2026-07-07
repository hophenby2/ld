// Export one or more functions by address from a Ghidra program.
// @category LikeDreamer
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import ghidra.util.task.ConsoleTaskMonitor;
import java.io.*;

public class ExportSingleFunctionByAddress extends GhidraScript {
    private String safeName(String s) {
        return s.replaceAll("[^A-Za-z0-9_.-]+", "_");
    }

    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 2) {
            throw new IllegalArgumentException("usage: <outDir> <address> [address...]");
        }
        File outDir = new File(args[0]);
        outDir.mkdirs();
        FunctionManager fm = currentProgram.getFunctionManager();
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        for (int i = 1; i < args.length; ++i) {
            Address address = currentProgram.getAddressFactory().getAddress(args[i]);
            if (address == null) {
                println("No address: " + args[i]);
                continue;
            }
            Function fn = fm.getFunctionAt(address);
            if (fn == null) fn = fm.getFunctionContaining(address);
            if (fn == null) {
                println("No function at/containing: " + args[i]);
                continue;
            }
            DecompileResults res = ifc.decompileFunction(fn, 120, new ConsoleTaskMonitor());
            File out = new File(outDir, fn.getEntryPoint().toString() + "_" + safeName(fn.getName()) + ".c");
            PrintWriter pw = new PrintWriter(new OutputStreamWriter(new FileOutputStream(out), "UTF-8"));
            pw.println("// Function: " + fn.getName() + " @ " + fn.getEntryPoint());
            pw.println("// Decompile completed: " + res.decompileCompleted());
            if (res.decompileCompleted() && res.getDecompiledFunction() != null) {
                pw.println(res.getDecompiledFunction().getC());
            } else {
                pw.println("// " + res.getErrorMessage());
            }
            pw.close();
            println("Wrote " + out.getAbsolutePath());
        }
    }
}
