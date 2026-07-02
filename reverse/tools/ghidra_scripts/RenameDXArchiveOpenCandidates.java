// Rename DXArchive open/decode candidate functions.
// @category LikeDreamer
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import ghidra.program.model.symbol.SourceType;
import ghidra.util.task.ConsoleTaskMonitor;
import java.io.*;

public class RenameDXArchiveOpenCandidates extends GhidraScript {
  static class Item { String a,n; Item(String a,String n){this.a=a;this.n=n;} }
  private String safe(String s){ return s.replaceAll("[^A-Za-z0-9_.-]+","_"); }
  public void run() throws Exception {
    String[] args=getScriptArgs(); File outDir=new File(args.length>0?args[0]:"."); outDir.mkdirs();
    FunctionManager fm=currentProgram.getFunctionManager();
    Item[] items=new Item[]{
      new Item("1401b17e0","dxarchive_open_archive_dispatch_candidate"),
      new Item("1401b3410","dxarchive_open_from_file_candidate"),
      new Item("1401b3750","dxarchive_open_from_file_wait_candidate"),
      new Item("1401b3b60","dxarchive_open_from_memory_candidate"),
      new Item("1401b3280","dxarchive_key_create_candidate"),
      new Item("1401b3000","dxarchive_xor_keyconv_candidate"),
      new Item("1401b31d0","dxarchive_keyconv_file_read_candidate"),
      new Item("1401b5b00","dxarchive_huffman_decode_candidate"),
      new Item("1401b2550","dxarchive_lz_decode_candidate")
    };
    PrintWriter log=new PrintWriter(new OutputStreamWriter(new FileOutputStream(new File(outDir,"dxarchive-rename-log.tsv")),"UTF-8"));
    log.println("address\told_name\tnew_name\tstatus");
    DecompInterface ifc=new DecompInterface(); ifc.openProgram(currentProgram);
    File decDir=new File(outDir,"dxarchive-open-decompiled"); decDir.mkdirs();
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
