// Export callees/callers and decompilation for selected functions.
// @category LikeDreamer
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import ghidra.program.model.symbol.*;
import ghidra.util.task.ConsoleTaskMonitor;
import java.io.*;
import java.util.*;

public class ExportFunctionNeighborhood extends GhidraScript {
    private String safeName(String s) { return s.replaceAll("[^A-Za-z0-9_.-]+", "_"); }
    @Override public void run() throws Exception {
        String[] args=getScriptArgs();
        File outDir=new File(args.length>0?args[0]:"."); outDir.mkdirs();
        FunctionManager fm=currentProgram.getFunctionManager();
        ReferenceManager rm=currentProgram.getReferenceManager();
        String[] addrs = args.length>1 ? Arrays.copyOfRange(args,1,args.length) : new String[]{"1401b23b0","1401ae820","1401ae2f0","1401ae790","140155560","140155800"};
        PrintWriter edges=new PrintWriter(new OutputStreamWriter(new FileOutputStream(new File(outDir,"function-neighborhood.tsv")),"UTF-8"));
        edges.println("root\tdirection\tref_addr\tfunction_entry\tfunction_name");
        Set<Function> funcs=new LinkedHashSet<>();
        for(String a:addrs){
            Function root=fm.getFunctionAt(toAddr(a)); if(root==null) root=fm.getFunctionContaining(toAddr(a));
            if(root==null){ edges.printf("%s\tROOT_MISSING\t\t\t%n",a); continue; }
            funcs.add(root);
            // outgoing calls
            AddressSetView body=root.getBody();
            ReferenceIterator refs=rm.getReferenceIterator(root.getEntryPoint());
            // Better iterate instructions refs from body
            for(Address addr: body.getAddresses(true)){
                Reference[] rs=rm.getReferencesFrom(addr);
                for(Reference r:rs){
                    if(!r.getReferenceType().isCall()) continue;
                    Function callee=fm.getFunctionAt(r.getToAddress());
                    if(callee==null) callee=fm.getFunctionContaining(r.getToAddress());
                    edges.printf("%s\tout\t%s\t%s\t%s%n",root.getEntryPoint(),addr,callee==null?"":callee.getEntryPoint().toString(),callee==null?r.getToAddress().toString():callee.getName());
                    if(callee!=null) funcs.add(callee);
                }
            }
            // incoming calls/references to entry
            ReferenceIterator in=rm.getReferencesTo(root.getEntryPoint());
            while(in.hasNext()){
                Reference r=in.next();
                Function caller=fm.getFunctionContaining(r.getFromAddress());
                edges.printf("%s\tin\t%s\t%s\t%s%n",root.getEntryPoint(),r.getFromAddress(),caller==null?"":caller.getEntryPoint().toString(),caller==null?"":caller.getName());
                if(caller!=null) funcs.add(caller);
            }
        }
        edges.close();
        File decDir=new File(outDir,"neighborhood-decompiled"); decDir.mkdirs();
        DecompInterface ifc=new DecompInterface(); ifc.openProgram(currentProgram);
        int n=0;
        for(Function f:funcs){
            if(n++>120) break;
            DecompileResults res=ifc.decompileFunction(f,90,new ConsoleTaskMonitor());
            File out=new File(decDir,f.getEntryPoint()+"_"+safeName(f.getName())+".c");
            PrintWriter pw=new PrintWriter(new OutputStreamWriter(new FileOutputStream(out),"UTF-8"));
            pw.println("// Function: "+f.getName()+" @ "+f.getEntryPoint());
            pw.println("// Decompile completed: "+res.decompileCompleted());
            if(res.decompileCompleted() && res.getDecompiledFunction()!=null) pw.println(res.getDecompiledFunction().getC()); else pw.println("// "+res.getErrorMessage());
            pw.close();
        }
    }
}
