// Export references to selected addresses and decompile containing functions.
// @category LikeDreamer
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import ghidra.program.model.symbol.*;
import ghidra.util.task.ConsoleTaskMonitor;
import java.io.*;
import java.util.*;

public class ExportAddressRefs extends GhidraScript {
  private String safe(String s){ return s.replaceAll("[^A-Za-z0-9_.-]+","_"); }
  public void run() throws Exception {
    String[] args=getScriptArgs();
    File outDir=new File(args.length>0?args[0]:"."); outDir.mkdirs();
    String[] addrs=args.length>1?Arrays.copyOfRange(args,1,args.length):new String[]{"140976008","14097600c","14097604b"};
    ReferenceManager rm=currentProgram.getReferenceManager();
    FunctionManager fm=currentProgram.getFunctionManager();
    PrintWriter refs=new PrintWriter(new OutputStreamWriter(new FileOutputStream(new File(outDir,"global-key-refs.tsv")),"UTF-8"));
    refs.println("target\tref_from\tref_type\tfunction_entry\tfunction_name");
    Set<Function> funcs=new LinkedHashSet<>();
    for(String a:addrs){
      Address target=toAddr(a);
      ReferenceIterator it=rm.getReferencesTo(target);
      boolean any=false;
      while(it.hasNext()){
        any=true;
        Reference r=it.next();
        Function f=fm.getFunctionContaining(r.getFromAddress());
        refs.printf("%s\t%s\t%s\t%s\t%s%n", target, r.getFromAddress(), r.getReferenceType(), f==null?"":f.getEntryPoint().toString(), f==null?"":f.getName());
        if(f!=null) funcs.add(f);
      }
      if(!any) refs.printf("%s\t\tNO_REFS\t\t%n", target);
    }
    refs.close();
    File decDir=new File(outDir,"global-key-ref-decompiled"); decDir.mkdirs();
    DecompInterface ifc=new DecompInterface(); ifc.openProgram(currentProgram);
    for(Function f:funcs){
      DecompileResults res=ifc.decompileFunction(f,90,new ConsoleTaskMonitor());
      File out=new File(decDir,f.getEntryPoint()+"_"+safe(f.getName())+".c");
      PrintWriter pw=new PrintWriter(new OutputStreamWriter(new FileOutputStream(out),"UTF-8"));
      pw.println("// Function: "+f.getName()+" @ "+f.getEntryPoint());
      pw.println("// Decompile completed: "+res.decompileCompleted());
      if(res.decompileCompleted() && res.getDecompiledFunction()!=null) pw.println(res.getDecompiledFunction().getC()); else pw.println("// "+res.getErrorMessage());
      pw.close();
    }
  }
}
