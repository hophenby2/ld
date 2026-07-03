# Save / Config / Replay Manager Pseudocode Sketch

Status: evidence-backed pseudocode from Ghidra decompilation, not original source. Function and field names are provisional.

## Save startup/load path

Evidence: `game_startup_init_candidate @ 0x1400f4f70`, `save_init_or_reset_candidate @ 0x1400d0a30`.

```cpp
// Not original source.
struct SaveBlock {
    int32_t version_or_magic; // observed valid/current value: 200
    uint8_t body[0x2730 - 4];
};

SaveBlock g_save; // DAT_140e41b10

void load_or_create_save() {
    if (fopen("save\\save.dat", "rb")) {
        fread(&g_save, 0x2730, 1, file);
        fclose(file);

        if (g_save.version_or_magic != 200) {
            // Startup contains migration/defaulting logic for older sentinels.
            migrate_or_reset_save_to_200(&g_save);
        }
    } else {
        initialize_default_save(&g_save); // FUN_1400d0aa0
        fwrite(&g_save, 0x2730, 1, fopen("save\\save.dat", "wb"));
    }
}

void write_save_block() {
    fwrite(&g_save, 0x2730, 1, fopen("save\\save.dat", "wb"));
    save_write_cooldown_or_notice_timer = 0xb4; // DAT_140e471fc
}
```

## Config load/menu path

Evidence: `game_startup_init_candidate @ 0x1400f4f70`, `config_handler_candidate @ 0x1401019e0`.

```cpp
// Not original source.
struct ConfigBlock {
    int32_t field0; // observed sample: 1
    int32_t field1; // observed sample: 0
    int32_t field2; // observed sample: 0
    int32_t field3; // observed sample: 0
    int32_t field4; // observed sample: 1
    int32_t field5; // observed sample: 0
    int32_t sound_mode; // DAT_140e46908, consumed during audio setup
};

ConfigBlock g_config; // DAT_140e468f0, size 0x1c

void load_or_create_config() {
    if (fopen("save\\config.dat", "rb")) {
        fread(&g_config, 0x1c, 1, file);
    } else {
        g_config = default_config_constants;
        fwrite(&g_config, 0x1c, 1, fopen("save\\config.dat", "wb"));
    }

    apply_sound_mode(g_config.sound_mode);
}

void config_menu_update() {
    // Cursor rows 0..6 toggle/increment/decrement g_config fields.
    // Row 8 exits/cancels; row 7 resets several fields to defaults.
    // Exact UI labels still need mapping against config menu textures/text.
}
```

## Replay slot scan

Evidence: `replay_handler_candidate_B @ 0x1401171d0`.

```cpp
// Not original source.
struct ReplayHeader {
    int32_t version_or_magic;        // +0x0000, observed valid/current value: 200
    int32_t input_record_count;      // +0x0004, matches payload_size / 8 in samples
    char player_tag[4];              // +0x0008, three selected chars plus NUL/pad, e.g. "HT "
    int32_t reserved_0c;             // +0x000c, zero in current samples
    int32_t timestamp_unix;          // +0x0010, plausible UTC timestamp in current samples
    int32_t reserved_14;             // +0x0014, zero in current samples
    int32_t mode_or_route;           // +0x0018, demo header field #2; copied to DAT_140e41928
    int32_t mode_subfield;           // +0x001c, copied to DAT_140e41abc
    int32_t play_setting_0;          // +0x0020, part of demo/replay 15-field header
    int32_t play_setting_1;          // +0x0024, part of demo/replay 15-field header
    int32_t play_setting_2;          // +0x0028, part of demo/replay 15-field header
    int32_t stage_or_section;        // +0x002c, copied to DAT_140e445c0
    int32_t stage_progress_0;        // +0x0030, copied to DAT_140e445c4
    int32_t stage_progress_1;        // +0x0034, copied to DAT_140e445c8
    int32_t stage_progress_2;        // +0x0038, copied to DAT_140e445cc
    int32_t stage_progress_3;        // +0x003c, copied to DAT_140e445d0
    int32_t demo_checkpoint_or_stage; // +0x0040, demo field #15; copied to DAT_1407c7798 for one replay mode
    int32_t binary_current_stage;      // +0x0044, written from DAT_1407c7798 before binary save
    int32_t stage_group_checkpoint_0;  // +0x0048, used by stage transition code for stage group 1
    int32_t stage_group_checkpoint_1;  // +0x004c, used by stage transition code for groups 2/3
    int32_t stage_group_checkpoint_2;  // +0x0050, used by stage transition code for groups 4/5
    int32_t reserved_54;
    int64_t score_or_counter_candidate;           // +0x0058, written from DAT_140e44590
    int32_t secondary_score_or_counter_candidate; // +0x0060 low dword, written from DAT_140e451b0; zero in samples
    int32_t unknown_runtime_value_64;              // +0x0064, written from DAT_140e4680c
    int32_t player_option_or_type;     // +0x0068, replay mode uses this instead of DAT_140e44194
    int32_t player_suboption;          // +0x006c, replay mode uses this instead of DAT_140e41b70
    int32_t demo_export_field_70;      // +0x0070, included in demo text export
    uint8_t unknown_74_to_b3[0x00b4 - 0x0074];
    int32_t player_state_active_flag;  // +0x00b4, observed 1
    float player_pos_x_candidate;      // +0x00b8, observed 360.0
    float player_pos_y_candidate;      // +0x00bc, observed 600.0
    float player_prev_or_target_x;     // +0x00c0, observed 360.0
    float player_prev_or_target_y;     // +0x00c4, observed 600.0
    int32_t player_angle_or_fixed_velocity; // +0x00c8, observed 0x0000c000
    uint8_t unknown_cc_to_d7[0x00d8 - 0x00cc];
    int32_t player_state_mode;         // +0x00d8, observed 2
    uint8_t unknown_dc_to_e3[0x00e4 - 0x00dc];
    float subobject0_pos_x;            // +0x00e4, observed 360.0
    float subobject0_pos_y;            // +0x00e8, observed 600.0
    float subobject1_pos_x;            // +0x00ec, observed 360.0
    float subobject1_pos_y;            // +0x00f0, observed 600.0
    float subobject2_pos_x;            // +0x00f4, observed 360.0
    float subobject2_pos_y;            // +0x00f8, observed 600.0
    float subobject3_pos_x;            // +0x00fc, observed 360.0
    float subobject3_pos_y;            // +0x0100, observed 600.0
    float subobject_velocity_or_angle_x; // +0x0104, observed about -2.0117
    float subobject_velocity_or_angle_y; // +0x0108, observed about -2.0117
    uint8_t body[0xa98 - 0x010c];
};

ReplayHeader replay_slot_headers[24]; // DAT_140e8cf40, stride 0xa98
int replay_slot_present[24];          // DAT_140e9fd40

void scan_replay_slots() {
    for (int slot = 0; slot < 24; slot++) {
        char path[32];
        sprintf(path, "replay\\LD_replay%02d.dat", slot + 1);
        if (fopen(path, "rb")) {
            fread(&replay_slot_headers[slot], 0xa98, 1, file);
            replay_slot_present[slot] = (replay_slot_headers[slot].version_or_magic == 200);
            fclose(file);
        } else {
            replay_slot_present[slot] = 0;
        }
    }
}
```

## Replay load/save payload

Evidence: `replay_or_save_handler_candidate_A @ 0x140115880`, `replay_or_save_handler_candidate_C @ 0x140114580`.

```cpp
// Not original source.
struct ReplayInputRecord {
    uint32_t frame_or_tick;
    int16_t input_state;
    uint16_t pad_or_flags; // always zero in the first sample records inspected
};

ReplayHeader current_replay_header;       // DAT_140e45280
ReplayInputRecordList current_input_list; // linked list via DAT_140e45278 / DAT_140e9fd00

void load_selected_replay(int slot) {
    char path[32];
    sprintf(path, "replay\\LD_replay%02d.dat", slot + 1);
    if (!fopen(path, "rb")) {
        MessageBoxA(nullptr, "Replay data not found.", "error", 0);
        return;
    }

    fread(&current_replay_header, 0xa98, 1, file);
    while (fread(&raw_record, 8, 1, file) != 0) {
        append_input_record(raw_record.frame_or_tick, raw_record.input_state);
    }
    fclose(file);
}

void save_current_replay(int slot) {
    current_replay_header.player_tag[0] = replay_name_alphabet[name_index0];
    current_replay_header.player_tag[1] = replay_name_alphabet[name_index1];
    current_replay_header.player_tag[2] = replay_name_alphabet[name_index2];
    current_replay_header.binary_current_stage = current_stage;
    current_replay_header.score_or_counter_candidate = current_score_or_counter;
    current_replay_header.secondary_score_or_counter_candidate = current_secondary_counter;
    current_replay_header.unknown_runtime_value_64 = current_runtime_value_64;

    char path[32];
    sprintf(path, "replay\\LD_replay%02d.dat", slot + 1);

    fwrite(&current_replay_header, 0xa98, 1, fopen(path, "wb"));
    FILE *file = fopen(path, "ab");
    for (ReplayInputRecord *r = current_input_list.head; r; r = r->next) {
        fwrite(r, 8, 1, file);
    }
    fclose(file);

    scan_replay_slots();
    write_save_block();
}
```

Open questions:

- Map the remaining replay header fields after `0x010c`, especially whether the float-heavy state snapshot continues through the full `0xa98` header.
- Name the 8-byte input record bitfield; first samples show monotonically increasing `frame_or_tick` and stable input bitmasks (`0`, `80`, `90`, `602`).
- Confirm whether the second replay header `int32` is always the input record count or can diverge from payload length after abnormal exits.
