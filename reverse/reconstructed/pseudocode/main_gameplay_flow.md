# Main Gameplay Flow Pseudocode Sketch

Status: evidence-backed pseudocode from renamed Ghidra exports. This is not original source; function/global names remain provisional.

Primary evidence:

- `reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/1400d4610_state_03_stage_start_init_candidate.c`
- `reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/1400d5d50_state_04_gameplay_update_candidate.c`
- `reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/14010e9b0_state_05_gameplay_boss_or_result_candidate.c`
- `reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/1400bca30_state_14_replay_demo_gameplay_update_candidate.c`
- `reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/1400fcd20_state_2c_auto_gameplay_branch_candidate.c`

## Cross-state globals

```cpp
int g_main_state;              // DAT_140e45270
int g_scene_cursor;            // DAT_140e45274
int g_scene_frame;             // DAT_140e418c8
int g_transition_timer;        // DAT_140e45fac, positive = confirm/start fade, negative = cancel/back fade
int g_selection_anim_timer;    // DAT_140e46bb4
int g_selection_anim_timer_2;  // DAT_140e46bb0
int g_selection_dirty;         // DAT_140e46014
int g_input_consumed;          // DAT_140e467fc
int g_route_or_mode;           // DAT_140e41928
int g_stage_group;             // DAT_140e445c0
int g_current_stage;           // DAT_1407c7798
int g_replay_mode;             // DAT_140e41b00
```

Common evidence patterns:

- Most handlers draw or update fade panels for the first ~60 frames via `FUN_1400d4310`.
- Sound effects use `FUN_140184700(..., DAT_140e47200/204/208/20c/21c)` followed by `FUN_14018a340(...)`.
- Save writes use `fopen_s(..., "save\\save.dat", "wb")`, `FUN_140327c78(&DAT_140e41b10, 0x2730, 1, file)`, and `FUN_140323e90(file)`, then set `DAT_140e471fc = 0xb4`.
- Resource handles in `DAT_140e45100..140e45178` are explicitly stopped/freed with `FUN_14018f230(handle, 0)` during state changes.

## State `0x03`: stage start / run setup menu

`state_03_stage_start_init_candidate` is not a direct gameplay simulation loop. It is the pre-run setup screen that selects route/stage/player options and then commits into active gameplay.

Observed behavior:

```cpp
void state_03_stage_start_init_candidate() {
    draw_entry_fade_until_60_frames();
    draw_route_stage_option_menu();

    if (ready_for_input()) {
        // Horizontal input adjusts the selected row.
        if (cursor == 0) {
            cycle_stage_group();
            copy_group_defaults_to_working_selection();
        } else if (cursor >= 1 && cursor < 5) {
            increment_or_decrement_stage_option(cursor - 1);
        } else if (cursor == 5) {
            toggle_player_suboption_or_flag();
        }

        // Confirm moves deeper through rows; on final row it starts positive fade.
        if (confirm_pressed()) {
            if (cursor < 6) {
                previous_cursor = cursor;
                cursor++;
                selection_anim_timer = +1;
            } else {
                g_transition_timer = +1;
            }
        }

        // Cancel backs out; on first row it starts negative fade toward title/menu.
        if (cancel_pressed()) {
            if (cursor == 0) {
                g_transition_timer = -1;
            } else {
                previous_cursor = cursor;
                cursor--;
                selection_anim_timer = -1;
            }
        }
    }

    if (g_transition_timer == 0x50) {
        reset_scene_locals();
        if (g_route_or_mode == 2) {
            g_main_state = 0x05;     // alternate/boss-like route
        } else {
            g_main_state = 0x04;     // normal active gameplay setup/update
            g_stage_variant_flag = 0;
            g_current_stage = saved_route_stage_for_mode(g_route_or_mode);
            g_stage_subselection = selected_substage;
            g_player_option = selected_player_option;
        }
        write_save_block();
    }

    if (g_transition_timer == -0x32) {
        cursor = g_route_or_mode;
        reset_scene_locals();
        g_main_state = 0x02;         // return to title/main menu
        write_save_block();
    }

    tick_timers();
}
```

Evidence anchors:

- Row/stage option edits and `DAT_140e445c0` cycling: `.../1400d4610_state_03_stage_start_init_candidate.c:643` through `:664`, and reverse direction at `:683` through `:703`.
- Confirm/cancel cursor movement: same file `:734` through `:762`.
- Commit transition to states `0x05` or `0x04`: same file `:784` through `:803`.
- Cancel transition to title state `0x02`: same file `:812` through `:823`.

## State `0x04`: active gameplay pre-start / stage selection overlay

`state_04_gameplay_update_candidate` appears to be the normal route's active gameplay setup/update screen. It renders the stage/run presentation, lets the player adjust stage and substage selection after an intro delay, and starts the actual run through a long positive fade. It can also cancel back to state `0x03`.

```cpp
void state_04_gameplay_update_candidate() {
    draw_intro_fade_and_stage_ui();
    draw_stage_objects_and_overlay();

    if (g_scene_frame > 0x3b && g_transition_timer == 0 && g_stage_variant_flag == 0) {
        if (left_or_right_pressed_on_stage_row()) {
            adjust_current_stage_within_allowed_bounds();
            g_selection_dirty = signed_animation_direction;
        }

        if (left_or_right_pressed_on_substage_row()) {
            adjust_substage_selection();
            g_selection_anim_timer = +/-4;
        }

        if (confirm_pressed() && g_selection_dirty == 0) {
            if (selection_is_playable()) {
                cursor++;
                g_transition_timer = +1;
            } else {
                play_error_sound();
            }
        }

        if (cancel_pressed() && g_selection_dirty == 0) {
            cursor--;
            g_transition_timer = -1;
        }
    }

    if (cursor == 2 && g_transition_timer == 1) {
        persist_selected_route_stage_and_player_option();
        stop_scene_audio_handles();
        write_save_block();
    }

    if (cursor == -1 && g_transition_timer == -0x32) {
        persist_selected_route_stage_and_player_option();
        reset_scene_locals();
        g_main_state = 0x03;         // back to run setup menu
        write_save_block();
    }

    tick_timers();
}
```

Evidence anchors:

- Input gate after frame `0x3b`, while not transitioning: `.../1400d5d50_state_04_gameplay_update_candidate.c:1731`.
- Stage/substage adjustment: same file `:1744` through `:1795`.
- Confirm/cancel set `DAT_140e45fac` to `+1`/`-1`: same file `:1824` through `:1844`.
- Commit selection and save at cursor `2`, transition start: same file `:1876` through `:1897`.
- Back transition to state `0x03`: same file `:1910` through `:1938`.

Resolved helper note: the final transition after cursor `2` calls `FUN_1400f7150()` at timer `100` and decrements `g_scene_frame`. The focused helper export shows `FUN_1400f7150()` computes the selected run/replay context, resets gameplay timing fields, and then sets `DAT_140e45270 = (DAT_140e41928 == -1) + 0x14` unless currently in demo state `0x2a`. In normal cases this means it enters state `0x14`; when `DAT_140e41928 == -1`, it enters state `0x15`. Evidence: `reverse/ghidra-or-ida/exports/gameplay-helpers/neighborhood-decompiled/1400f7150_FUN_1400f7150.c:62` through `:157`.

## State `0x05`: alternate/boss route setup or result-adjacent selection

`state_05_gameplay_boss_or_result_candidate` is structurally another menu/update state, but with 10 cursor positions and a different option table. It likely covers an alternate route, boss challenge, or result-adjacent branch rather than a raw simulation loop.

```cpp
void state_05_gameplay_boss_or_result_candidate() {
    draw_intro_fade_and_option_ui();

    if (frame >= 0x20 && g_transition_timer == 0 && !selection_dirty) {
        up_down_wrap_cursor_0_to_9();
        left_right_adjust_option_values_for_rows_0_to_7();

        if (confirm_pressed()) {
            if (cursor == 8 && selection_is_allowed) {
                g_transition_timer = +1;
            } else if (cursor == 9) {
                g_transition_timer = -1;
            } else {
                cursor = 8;          // force confirm row after editing options
            }
        }
    }

    if (g_transition_timer == 0x32) {
        if (cursor == 8) {
            finish_confirm_path();    // calls FUN_1400f7150, save remains in same state/frame
        }
        if (cursor == 9) {
            reset_scene_locals();
            g_main_state = 0x03;     // return to setup menu
        }
        write_save_block();
    }

    if (g_transition_timer == -0x32) {
        reset_scene_locals();
        write_save_block();
        g_main_state = 0x03;
    }

    tick_timers();
}
```

Evidence anchors:

- Cursor wraps over `0..9`: `.../14010e9b0_state_05_gameplay_boss_or_result_candidate.c:175` through `:206`.
- Confirm/back rows and transition timer setup: same file `:456` through `:478`.
- Positive transition at `0x32` returns to setup for row `9`: same file `:969` through `:984`.
- Negative transition returns to setup: same file `:993` through `:1007`.

## States `0x14`, `0x15`, `0x2a`: replay/demo gameplay update

`state_14_replay_demo_gameplay_update_candidate` is the clearest real gameplay-loop handler in this export set. It records live input to a linked list when not in replay mode, or replays stored input records when `DAT_140e41b00 == 1`. It also manages demo text playback (`state 0x2a`) and replay-save/menu exits.

```cpp
void state_14_replay_demo_gameplay_update_candidate() {
    maybe_start_or_crossfade_stage_bgm();

    if (!g_replay_mode) {
        append_input_record(frame_counter, packed_input_flags);
        if (g_main_state == 0x2a) {
            drive_demo_text_timing();
            if (demo_finished) {
                cleanup_replay_demo_state();
                g_main_state = 0x02;
            }
        }
    } else {
        apply_input_record_for_replay_frame();
        if (replay_payload_finished) {
            cleanup_audio_and_transition_to_replay_followup();
            g_main_state = 0x27;
            cursor = 0;
        }
    }

    run_gameplay_simulation_and_render();

    if (special_exit_pressed_or_stage_flag_set && g_main_state != 0x2a) {
        stop_scene_audio_handles();
        cursor = 0;
        g_transition_timer = 0;
        g_input_consumed = 1;
        if (g_main_state == 0x15) {
            g_main_state = 0x16;
        } else if (!g_replay_mode) {
            g_main_state = 0x17;
        } else {
            g_main_state = 0x26;
        }
    }

    g_scene_frame++;
}
```

Evidence anchors:

- Live input recording packs `DAT_140e467b8..467dc` into a record: `.../1400bca30_state_14_replay_demo_gameplay_update_candidate.c:105` through `:163`.
- Demo playback can return to title state `0x02`: same file `:164` through `:192`.
- Replay playback applies stored input and exits to state `0x27`: same file `:196` through `:236`.
- Exit/save-menu transition to states `0x16`, `0x17`, or `0x26`: same file `:1099` through `:1119`.

Per-stage gameplay dispatcher evidence: within this state, a switch on `DAT_1407c7798` calls eleven stage-specific update functions. These have now been renamed in Ghidra with generic stage-index names, pending resource/text confirmation of real stage titles. Evidence: `reverse/ghidra-or-ida/exports/per-stage-gameplay-renamed/neighborhood-decompiled/1400bca30_state_14_replay_demo_gameplay_update_candidate.c:644` through `:679`.

| `DAT_1407c7798` | Address | Applied name | Notes |
|---:|---|---|---|
| `0` | `0x14012eba0` | `stage_00_gameplay_update_candidate` | Special first-stage handler; larger setup/intro logic. |
| `1` / default | `0x140118420` | `stage_01_gameplay_update_candidate` | Default branch for non-enumerated stage ids. |
| `2` | `0x140119640` | `stage_02_gameplay_update_candidate` | Uses dense spawn/event schedule. |
| `3` | `0x14011b3d0` | `stage_03_gameplay_update_candidate` | Uses dense spawn/event schedule. |
| `4` | `0x14011cdd0` | `stage_04_gameplay_update_candidate` | Uses dense spawn/event schedule. |
| `5` | `0x14011eef0` | `stage_05_gameplay_update_candidate` | Uses dense spawn/event schedule. |
| `6` | `0x140121660` | `stage_06_gameplay_update_candidate` | Uses dense spawn/event schedule. |
| `7` | `0x140123620` | `stage_07_gameplay_update_candidate` | Uses dense spawn/event schedule. |
| `8` | `0x1401253e0` | `stage_08_gameplay_update_candidate` | Longest exported stage handler in this set. |
| `9` | `0x140128940` | `stage_09_gameplay_update_candidate` | Uses dense spawn/event schedule. |
| `10` | `0x14012b260` | `stage_10_gameplay_update_candidate` | Special/final-stage-like handler; distinct early timing/audio setup. |

Focused helper names now applied in Ghidra:

| Address | Applied name | Evidence summary |
|---|---|---|
| `0x1400f7150` | `gameplay_context_init_candidate` | Computes selected run context, clears scene audio, initializes gameplay frame fields, and enters `0x14`/`0x15`. |
| `0x1400d3a60` | `ambient_effect_update_and_render_candidate` | Periodically spawns ambient particles/effects and calls common effect update/render helpers. |
| `0x1400d3fd0` | `transition_tile_wipe_out_candidate` | Creates a checker/tile wipe with positive transition timing and frees scene objects near completion. |
| `0x1400d4310` | `transition_tile_wipe_in_candidate` | Creates the inverse/entry checker/tile wipe during initial frames. |
| `0x140106be0` | `player_update_input_movement_candidate` | Converts input/replay fields into player orientation, movement/shot state, and downstream player effects. |
| `0x140135330` | `result_route_predicate_candidate` | Checks current mode/stage completion conditions for result routing. |

Common stage spawn/event helper names now applied in Ghidra:

| Address | Applied name | Evidence summary |
|---|---|---|
| `0x14007b710` | `stage_spawn_dispatch_candidate` | Thin dispatch wrapper keyed by spawn/type id; decompiler signature is incomplete at this wrapper, but call sites pass spawn id plus timing/position fields. |
| `0x140078a00` | `stage_entity_spawn_candidate` | Allocates a `0x68`-byte node in the `DAT_140e45d80` list. Confirmed node anchors: `+0x18` primary behavior/type, `+0x1c/+0x20` lifetime, `+0x28/+0x2c` x/y, `+0x24` render/collision category, `+0x50` radius/clear-effect size, `+0x60` next link. |
| `0x140078b70` | `stage_entity_update_dispatch_candidate` | Iterates `DAT_140e45d80`, uses node `+0x18` to index byte table `DAT_1400799a8`, dispatches to per-type update helpers, then runs inactive cleanup/timer increments. |
| `0x140079b00` | `stage_entity_flush_effects_candidate` | Iterates `DAT_140e45d80`, emits effect sprites via `FUN_140070d00`, frees nodes, and clears the stage entity list/count. |
| `0x14006c420` | `stage_pending_effect_flush_candidate` | Converts pending entries in `DAT_140e45260` into visual effects, frees them, and clears pending-effect counters. |
| `0x14012e8e0` | `stage_intro_banner_event_candidate` | Renders intro/banner panels between a start/end frame, optionally spawns a marker with `FUN_14012e070`, and clears banner objects near the end. |
| `0x1401307e0` | `stage_intro_skip_prompt_candidate` | Draws a prompt after frame `0x8b`; confirm rewinds `DAT_140e418c8` to `99` and records `DAT_140e46804`. |
| `0x1401309b0` | `stage_continue_prompt_candidate` | Draws a centered continue/prompt object and allows confirm after frame `0xdb` to rewind/branch. |
| `0x140130be0` | `stage_hud_or_option_panel_candidate` | Draws a mode-dependent HUD/option panel with alpha fade-in; exact UI meaning needs text/resource cross-reference. |

## State `0x2c`: auto/extra stage unlock or ending branch

`state_2c_auto_gameplay_branch_candidate` is an accelerated auto branch. The outer loop already special-cases state `0x2c` for multiple updates per display frame when the current stage flag is set. The handler draws an automated stage presentation, unlocks a per-stage flag in save data, and eventually routes to extra/system/result states.

```cpp
void state_2c_auto_gameplay_branch_candidate() {
    append_visual_object_for_this_frame();

    if (g_scene_frame == 1) {
        stop_scene_audio_handles();
        start_stage_bgm_or_background();
        if (!g_replay_mode && !debug_or_skip_flag && stage_group < 0x14 && !stage_seen_flag[stage_group]) {
            stage_seen_flag[stage_group] = 1;
            update_unlock_or_achievement_state();
            write_save_block();
        }
    }

    draw_auto_stage_sequence();
    run_effect_update_helpers();

    if (g_transition_timer == 0) {
        if (scene_not_complete_yet && !stage_fast_flag[current_stage]) {
            g_scene_frame++;
            return;
        }

        if (confirm_pressed_after_intro()) {
            g_transition_timer++;
            if (!stage_fast_flag[current_stage]) {
                stage_fast_flag[current_stage] = 1;
                write_save_block();
            }
        }
    }

    if (g_transition_timer > 0) {
        fade_out_bgm_and_screen();
        if (g_transition_timer >= 0x78) {
            cleanup_scene_lists_and_audio();
            if (any_extra_flags_pending()) {
                g_main_state = 0x2d;
            } else if (FUN_140135330() != 0) {
                g_main_state = 0x10;
            } else {
                g_main_state = 0x23;
            }
        }
    }

    g_scene_frame++;
}
```

Evidence anchors:

- First-frame setup and save flag update: `.../1400fcd20_state_2c_auto_gameplay_branch_candidate.c:126` through `:140`.
- Completion gate at frame `0x1c20` or per-stage flag: same file `:607` through `:644`.
- Confirm starts fade and writes save flag: same file `:645` through `:655`.
- Fade completion routes to states `0x2d`, `0x23`, or `0x10`: same file `:658` through `:710`.

## Near-term focused exports

The next useful Ghidra pass should target helper functions now proven central:

| Address | Current name | Why |
|---|---|---|
| `0x1400f7150` | `FUN_1400f7150` | Resolved: selected-run/replay initializer that computes selected stage context, clears scene audio, initializes gameplay timing, calls a gameplay setup helper, then enters state `0x14` or `0x15`. |
| `0x1400d3a60` | `FUN_1400d3a60` | Common UI/render tail for states `0x03`, `0x04`, `0x05`; exported for follow-up naming. |
| `0x1400d3fd0` | `FUN_1400d3fd0` | Resolved: tile/screen fade transition helper; creates a 12x6 checker/tile wipe and plays periodic transition ticks. |
| `0x1400d4310` | `FUN_1400d4310` | Entry fade/draw helper for gameplay-adjacent screens; exported for follow-up naming. |
| `0x140106be0` | `FUN_140106be0` | Dense player update / input-to-movement logic; replay mode substitutes player option globals at function entry. |
| `0x140135330` | `FUN_140135330` | Resolved: result-route predicate used by state `0x2c`; checks mode/stage completion conditions to route to `0x10` versus `0x23`. |
