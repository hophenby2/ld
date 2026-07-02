// Rename audio/font resource candidates.
// @category LikeDreamer
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;
import ghidra.util.task.ConsoleTaskMonitor;
import java.io.*;

public class RenameResourceAudioCandidates extends GhidraScript {
  static class Item { String a,n; Item(String a,String n){this.a=a;this.n=n;} }
  private String safe(String s){ return s.replaceAll("[^A-Za-z0-9_.-]+","_"); }
  public void run() throws Exception {
    String[] args=getScriptArgs(); File outDir=new File(args.length>0?args[0]:"."); outDir.mkdirs();
    FunctionManager fm=currentProgram.getFunctionManager();
    Item[] items=new Item[]{
      new Item("1401885b0","dxlib_load_sound_candidate"),
      new Item("14018bc80","dxlib_set_sound_mode_candidate"),
      new Item("14015a5f0","dxlib_create_font_candidate"),
      new Item("140155cc0","dxlib_make_screen_candidate"),
      new Item("140155560","dxlib_load_graph_impl_candidate"),
      new Item("140155800","dxlib_load_div_graph_impl_candidate")
    };
    PrintWriter log=new PrintWriter(new OutputStreamWriter(new FileOutputStream(new File(outDir,"resource-audio-rename-log.tsv")),"UTF-8"));
    log.println("address\told_name\tnew_name\tstatus");
    DecompInterface ifc=new DecompInterface(); ifc.openProgram(currentProgram);
    File decDir=new File(outDir,"resource-audio-decompiled"); decDir.mkdirs();
    for(Item it:items){
      Function f=fm.getFunctionAt(toAddr(it.a)); if(f==null) f=fm.getFunctionContaining(toAddr(it.a));
      if(f==null){log.printf("%s\t\t%s\tNO_FUNCTION%n",it.a,it.n); continue;}
      String old=f.getName();
      try{f.setName(it.n,SourceType.USER_DEFINED); log.printf("%s\t%s\t%s\tOK%n",it.a,old,it.n);}catch(Exception e){log.printf("%s\t%s\t%s\tERR:%s%n",it.a,old,it.n,e.getMessage());}
      DecompileResults res=ifc.decompileFunction(f,90,new ConsoleTaskMonitor());
      PrintWriter pw=new PrintWriter(new OutputStreamWriter(new FileOutputStream(new File(decDir,it.a+"_"+safe(f.getName())+".c")),"UTF-8"));
      pw.println("// Function: "+f.getName()+" @ "+f.getEntryPoint()); pw.println("// Decompile completed: "+res.decompileCompleted());
      if(res.decompileCompleted() && res.getDecompiledFunction()!=null) pw.println(res.getDecompiledFunction().getC()); else pw.println("// "+res.getErrorMessage());
      pw.close();
    }
    log.close();
  }
}
