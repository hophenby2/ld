// Apply proposed names for gameplay helper functions discovered from the main gameplay branch.
// @category LikeDreamer
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.SourceType;

public class RenameGameplayHelpers extends GhidraScript {
    private static class RenameEntry {
        String address;
        String name;
        RenameEntry(String address, String name) {
            this.address = address;
            this.name = name;
        }
    }

    private final RenameEntry[] entries = new RenameEntry[] {
        new RenameEntry("1400f7150", "gameplay_context_init_candidate"),
        new RenameEntry("1400d3a60", "ambient_effect_update_and_render_candidate"),
        new RenameEntry("1400d3fd0", "transition_tile_wipe_out_candidate"),
        new RenameEntry("1400d4310", "transition_tile_wipe_in_candidate"),
        new RenameEntry("140106be0", "player_update_input_movement_candidate"),
        new RenameEntry("140135330", "result_route_predicate_candidate"),
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
