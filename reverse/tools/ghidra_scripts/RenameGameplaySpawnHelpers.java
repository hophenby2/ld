// Apply conservative names for common gameplay spawn/event helpers used by per-stage handlers.
// @category LikeDreamer
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.SourceType;

public class RenameGameplaySpawnHelpers extends GhidraScript {
    private static class RenameEntry {
        String address;
        String name;
        RenameEntry(String address, String name) {
            this.address = address;
            this.name = name;
        }
    }

    private final RenameEntry[] entries = new RenameEntry[] {
        new RenameEntry("14007b710", "stage_spawn_dispatch_candidate"),
        new RenameEntry("140078a00", "stage_entity_spawn_candidate"),
        new RenameEntry("140078b70", "stage_entity_update_dispatch_candidate"),
        new RenameEntry("140079b00", "stage_entity_flush_effects_candidate"),
        new RenameEntry("14006c420", "stage_pending_effect_flush_candidate"),
        new RenameEntry("14012e8e0", "stage_intro_banner_event_candidate"),
        new RenameEntry("1401307e0", "stage_intro_skip_prompt_candidate"),
        new RenameEntry("1401309b0", "stage_continue_prompt_candidate"),
        new RenameEntry("140130be0", "stage_hud_or_option_panel_candidate"),
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
