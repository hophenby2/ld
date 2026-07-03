// Apply generic names for per-stage gameplay update functions dispatched by state_14_replay_demo_gameplay_update_candidate.
// @category LikeDreamer
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.SourceType;

public class RenamePerStageGameplayHandlers extends GhidraScript {
    private static class RenameEntry {
        String address;
        String name;
        RenameEntry(String address, String name) {
            this.address = address;
            this.name = name;
        }
    }

    private final RenameEntry[] entries = new RenameEntry[] {
        new RenameEntry("14012eba0", "stage_00_gameplay_update_candidate"),
        new RenameEntry("140118420", "stage_01_gameplay_update_candidate"),
        new RenameEntry("140119640", "stage_02_gameplay_update_candidate"),
        new RenameEntry("14011b3d0", "stage_03_gameplay_update_candidate"),
        new RenameEntry("14011cdd0", "stage_04_gameplay_update_candidate"),
        new RenameEntry("14011eef0", "stage_05_gameplay_update_candidate"),
        new RenameEntry("140121660", "stage_06_gameplay_update_candidate"),
        new RenameEntry("140123620", "stage_07_gameplay_update_candidate"),
        new RenameEntry("1401253e0", "stage_08_gameplay_update_candidate"),
        new RenameEntry("140128940", "stage_09_gameplay_update_candidate"),
        new RenameEntry("14012b260", "stage_10_gameplay_update_candidate"),
    };

    @Override
    public void run() throws Exception {
        int ok = 0;
        int missing = 0;
        for (RenameEntry entry : entries) {
            Function function = getFunctionAt(toAddr(entry.address));
            if (function == null) {
                function = getFunctionContaining(toAddr(entry.address));
            }
            if (function == null) {
                println("MISSING\t" + entry.address + "\t" + entry.name);
                missing++;
                continue;
            }
            String oldName = function.getName();
            function.setName(entry.name, SourceType.USER_DEFINED);
            println("RENAMED\t" + entry.address + "\t" + oldName + "\t" + entry.name);
            ok++;
        }
        println("SUMMARY\tok=" + ok + "\tmissing=" + missing);
    }
}
