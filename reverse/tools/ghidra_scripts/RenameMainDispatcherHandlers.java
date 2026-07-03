// Apply proposed names for the FUN_1400f5ef0 state-dispatcher jump table handlers.
// @category LikeDreamer
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.SourceType;

public class RenameMainDispatcherHandlers extends GhidraScript {
    private static class RenameEntry {
        String address;
        String name;
        RenameEntry(String address, String name) {
            this.address = address;
            this.name = name;
        }
    }

    private final RenameEntry[] entries = new RenameEntry[] {
        new RenameEntry("1400f5ef0", "main_state_dispatcher_candidate"),
        new RenameEntry("1400d21e0", "state_02_title_main_menu_candidate"),
        new RenameEntry("1400d4610", "state_03_stage_start_init_candidate"),
        new RenameEntry("1400d5d50", "state_04_gameplay_update_candidate"),
        new RenameEntry("14010e9b0", "state_05_gameplay_boss_or_result_candidate"),
        new RenameEntry("1400bca30", "state_14_replay_demo_gameplay_update_candidate"),
        new RenameEntry("1400fcd20", "state_2c_auto_gameplay_branch_candidate"),
        new RenameEntry("1400ffc00", "state_0a_options_menu_candidate"),
        new RenameEntry("140100e00", "state_0b_options_submenu_a_candidate"),
        new RenameEntry("1401019e0", "state_0c_config_menu_candidate"),
        new RenameEntry("140102ae0", "state_0d_key_config_menu_candidate"),
        new RenameEntry("1400b4c60", "state_06_gallery_list_candidate"),
        new RenameEntry("1400b5c70", "state_07_gallery_detail_candidate"),
        new RenameEntry("1400b8890", "state_08_gallery_unlock_or_achievement_candidate"),
        new RenameEntry("140104d80", "state_1b_stage_result_transition_panel_candidate"),
        new RenameEntry("1401124b0", "state_10_23_result_continue_candidate"),
        new RenameEntry("140113ef0", "state_24_result_continue_submenu_candidate"),
        new RenameEntry("1400d9110", "state_28_29_ending_result_candidate"),
        new RenameEntry("1400b7f10", "state_30_gameplay_clear_fail_transition_candidate"),
        new RenameEntry("140115190", "state_0e_replay_list_menu_candidate"),
        new RenameEntry("140115880", "state_0f_replay_load_select_candidate"),
        new RenameEntry("140114580", "state_25_replay_save_name_entry_candidate"),
        new RenameEntry("1400ceb40", "state_00_pre_title_init_candidate"),
        new RenameEntry("1400f7570", "state_01_opening_attract_candidate"),
        new RenameEntry("1400ff570", "state_09_menu_branch_candidate"),
        new RenameEntry("1401108b0", "state_11_menu_branch_part1_candidate"),
        new RenameEntry("1401115f0", "state_11_13_menu_branch_shared_candidate"),
        new RenameEntry("1401110b0", "state_13_menu_branch_part1_candidate"),
        new RenameEntry("140104200", "state_16_17_save_select_candidate"),
        new RenameEntry("140105910", "state_18_save_select_candidate"),
        new RenameEntry("1400c5d70", "state_22_gameplay_result_branch_candidate"),
        new RenameEntry("1400c7df0", "state_1f_gameplay_result_branch_candidate"),
        new RenameEntry("1400fac60", "state_20_gameplay_result_branch_candidate"),
        new RenameEntry("1401172c0", "state_26_save_replay_adjacent_menu_candidate"),
        new RenameEntry("140117b00", "state_27_save_replay_adjacent_menu_candidate"),
        new RenameEntry("1400feaa0", "state_2d_2e_system_menu_branch_candidate"),
        new RenameEntry("1400ff2d0", "state_2f_system_menu_branch_candidate"),
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
