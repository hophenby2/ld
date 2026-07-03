# Save / Config / Replay Binary Format Notes

Evidence combines sample files with Ghidra decompilation of the save/config/replay handlers. All multi-byte numeric fields observed so far are little-endian.

## replay/LD_replay22.dat

- Size: 110992 bytes
- SHA256: `a78bcc080b953cc444cb294a7adc6b16d53b30eaf436e5191d75560f9c44c7b5`
- First 64 bytes: `c8 00 00 00 df 34 00 00 48 54 20 00 00 00 00 00 c1 47 4c 66 00 00 00 00 00 00 00 00 00 00 00 00 04 00 00 00 01 00 00 00 00 00 00 00 02 00 00 00 01 00 00 00 00 00 00 00 01 00 00 00 03 00 00 00`
- Entropy first 4096 bytes: 1.6416
- Entropy full file: 3.7476
- Confirmed replay header size: `0xa98` / `2712` bytes.
- Payload bytes after header: `108280`; as 8-byte input records: `13535` remainder `0`.
- Header first `int32` is schema sentinel `200`; second `int32` is declared input record count `13535`.
- Player tag/initials bytes at `0x0008`: `48 54 20 00` -> `HT `.
- Timestamp candidate at `0x0010`: `1716275137` / UTC 2024-05-21 07:05:37.
- First 32 header `int32` values: `(200, 13535, 2118728, 0, 1716275137, 0, 0, 0, 4, 1, 0, 2, 1, 0, 1, 3, 3, 3, 2, 4, 6, 0, 102885950, 0, 0, 0, 1, 1, 6, 1, 0, 0)`.

| Offset | Type | Provisional name | Value | Evidence / note |
|---:|---|---|---:|---|
| `0x0000` | `int32` | `version_or_magic` | `200` | valid/current value is 200 |
| `0x0004` | `int32` | `input_record_count` | `13535` | matches payload bytes / 8 in samples |
| `0x0008` | `char[3]+NUL` | `player_tag_or_initials` | `HT ` | written from three selected characters |
| `0x0010` | `int32` | `unix_timestamp_candidate` | `1716275137 / UTC 2024-05-21 07:05:37` | sample values decode to plausible UTC save dates |
| `0x0018` | `int32` | `mode_or_route_candidate` | `0` | demo header field #2 / loaded into DAT_140e41928 |
| `0x001c` | `int32` | `mode_subfield_candidate` | `0` | loaded into DAT_140e41abc |
| `0x0020` | `int32` | `play_setting_0` | `4` | part of demo/replay 15-field header |
| `0x0024` | `int32` | `play_setting_1` | `1` | part of demo/replay 15-field header |
| `0x0028` | `int32` | `play_setting_2` | `0` | part of demo/replay 15-field header |
| `0x002c` | `int32` | `stage_or_section_candidate` | `2` | loaded into DAT_140e445c0 |
| `0x0030` | `int32` | `stage_progress_candidate` | `1` | loaded into DAT_140e445c4 |
| `0x0034` | `int32` | `stage_progress_candidate_2` | `0` | loaded into DAT_140e445c8 |
| `0x0038` | `int32` | `stage_progress_candidate_3` | `1` | loaded into DAT_140e445cc |
| `0x003c` | `int32` | `stage_progress_candidate_4` | `3` | loaded into DAT_140e445d0 |
| `0x0040` | `int32` | `demo_checkpoint_or_stage` | `3` | demo header field #15; replay load may copy it to DAT_1407c7798 in mode 0 |
| `0x0044` | `int32` | `binary_current_stage` | `3` | binary-only field written from DAT_1407c7798 before replay save |
| `0x0048` | `int32` | `stage_group_checkpoint_0` | `2` | used by stage transition code for stage group 1 |
| `0x004c` | `int32` | `stage_group_checkpoint_1` | `4` | used by stage transition code for stage groups 2/3 |
| `0x0050` | `int32` | `stage_group_checkpoint_2` | `6` | used by stage transition code for stage groups 4/5 |
| `0x0058` | `int64 low` | `score_or_counter_candidate` | `102885950` | written from DAT_140e44590; high-variance low dword in samples |
| `0x0060` | `int64 low` | `secondary_score_or_counter_candidate` | `0` | written from DAT_140e451b0; zero in current samples |
| `0x0064` | `int32` | `unknown_runtime_value_64` | `0` | written from DAT_140e4680c; zero in current samples |
| `0x0068` | `int32` | `player_option_or_type_candidate` | `1` | used instead of DAT_140e44194 during replay mode |
| `0x006c` | `int32` | `player_suboption_candidate` | `1` | used instead of DAT_140e41b70 during replay mode |
| `0x0070` | `int32` | `demo_export_field_0x70` | `6` | included in demo text export as one of the 15 header values |
| `0x00b4` | `int32` | `player_state_active_flag` | `1` | start of repeated player/object state snapshot; observed 1 |
| `0x00b8` | `float` | `player_pos_x_candidate` | `360.0` | float 360.0 in samples; likely screen/player X |
| `0x00bc` | `float` | `player_pos_y_candidate` | `600.0` | float 600.0 in samples; likely screen/player Y |
| `0x00c0` | `float` | `player_prev_or_target_x_candidate` | `360.0` | float 360.0 in samples |
| `0x00c4` | `float` | `player_prev_or_target_y_candidate` | `600.0` | float 600.0 in samples |
| `0x00c8` | `int32` | `player_angle_or_fixed_velocity_candidate` | `49152` | 0x0000c000 in samples; resembles fixed-point direction/speed |
| `0x00d8` | `int32` | `player_state_mode_candidate` | `2` | observed 2 |
| `0x00e4` | `float` | `subobject0_pos_x_candidate` | `360.0` | float 360.0 in samples |
| `0x00e8` | `float` | `subobject0_pos_y_candidate` | `600.0` | float 600.0 in samples |
| `0x00ec` | `float` | `subobject1_pos_x_candidate` | `360.0` | float 360.0 in samples |
| `0x00f0` | `float` | `subobject1_pos_y_candidate` | `600.0` | float 600.0 in samples |
| `0x0104` | `float` | `subobject_velocity_or_angle_x_candidate` | `-2.0117` | float about -2.0117 in samples |
| `0x0108` | `float` | `subobject_velocity_or_angle_y_candidate` | `-2.0117` | float about -2.0117 in samples |
| `0x0128` | `int32` | `state_counter_128` | `32` | observed 32 |
| `0x0134` | `int32` | `state_counter_134` | `60` | observed 60 |
- First input records as `(uint32 frame_or_tick, int16 input_state, uint16 pad_or_flags)`: `[(0, 80, 0), (1, 80, 0), (2, 80, 0), (3, 80, 0), (4, 80, 0), (5, 80, 0), (6, 80, 0), (7, 80, 0), (8, 80, 0), (9, 80, 0)]`.

## replay/LD_replay23.dat

- Size: 282560 bytes
- SHA256: `847359f65f9a740bcfdaac4543eb5425836afd7190fcc02f41ce118a7ec7eb30`
- First 64 bytes: `c8 00 00 00 a5 88 00 00 48 54 20 00 00 00 00 00 ef f4 81 67 00 00 00 00 00 00 00 00 00 00 00 00 04 00 00 00 01 00 00 00 00 00 00 00 02 00 00 00 01 00 00 00 00 00 00 00 01 00 00 00 03 00 00 00`
- Entropy first 4096 bytes: 1.5369
- Entropy full file: 3.8516
- Confirmed replay header size: `0xa98` / `2712` bytes.
- Payload bytes after header: `279848`; as 8-byte input records: `34981` remainder `0`.
- Header first `int32` is schema sentinel `200`; second `int32` is declared input record count `34981`.
- Player tag/initials bytes at `0x0008`: `48 54 20 00` -> `HT `.
- Timestamp candidate at `0x0010`: `1736570095` / UTC 2025-01-11 04:34:55.
- First 32 header `int32` values: `(200, 34981, 2118728, 0, 1736570095, 0, 0, 0, 4, 1, 0, 2, 1, 0, 1, 3, 8, 8, 2, 4, 6, 0, 1312412685, 0, 0, 0, 1, 1, 6, 1, 0, 0)`.

| Offset | Type | Provisional name | Value | Evidence / note |
|---:|---|---|---:|---|
| `0x0000` | `int32` | `version_or_magic` | `200` | valid/current value is 200 |
| `0x0004` | `int32` | `input_record_count` | `34981` | matches payload bytes / 8 in samples |
| `0x0008` | `char[3]+NUL` | `player_tag_or_initials` | `HT ` | written from three selected characters |
| `0x0010` | `int32` | `unix_timestamp_candidate` | `1736570095 / UTC 2025-01-11 04:34:55` | sample values decode to plausible UTC save dates |
| `0x0018` | `int32` | `mode_or_route_candidate` | `0` | demo header field #2 / loaded into DAT_140e41928 |
| `0x001c` | `int32` | `mode_subfield_candidate` | `0` | loaded into DAT_140e41abc |
| `0x0020` | `int32` | `play_setting_0` | `4` | part of demo/replay 15-field header |
| `0x0024` | `int32` | `play_setting_1` | `1` | part of demo/replay 15-field header |
| `0x0028` | `int32` | `play_setting_2` | `0` | part of demo/replay 15-field header |
| `0x002c` | `int32` | `stage_or_section_candidate` | `2` | loaded into DAT_140e445c0 |
| `0x0030` | `int32` | `stage_progress_candidate` | `1` | loaded into DAT_140e445c4 |
| `0x0034` | `int32` | `stage_progress_candidate_2` | `0` | loaded into DAT_140e445c8 |
| `0x0038` | `int32` | `stage_progress_candidate_3` | `1` | loaded into DAT_140e445cc |
| `0x003c` | `int32` | `stage_progress_candidate_4` | `3` | loaded into DAT_140e445d0 |
| `0x0040` | `int32` | `demo_checkpoint_or_stage` | `8` | demo header field #15; replay load may copy it to DAT_1407c7798 in mode 0 |
| `0x0044` | `int32` | `binary_current_stage` | `8` | binary-only field written from DAT_1407c7798 before replay save |
| `0x0048` | `int32` | `stage_group_checkpoint_0` | `2` | used by stage transition code for stage group 1 |
| `0x004c` | `int32` | `stage_group_checkpoint_1` | `4` | used by stage transition code for stage groups 2/3 |
| `0x0050` | `int32` | `stage_group_checkpoint_2` | `6` | used by stage transition code for stage groups 4/5 |
| `0x0058` | `int64 low` | `score_or_counter_candidate` | `1312412685` | written from DAT_140e44590; high-variance low dword in samples |
| `0x0060` | `int64 low` | `secondary_score_or_counter_candidate` | `0` | written from DAT_140e451b0; zero in current samples |
| `0x0064` | `int32` | `unknown_runtime_value_64` | `0` | written from DAT_140e4680c; zero in current samples |
| `0x0068` | `int32` | `player_option_or_type_candidate` | `1` | used instead of DAT_140e44194 during replay mode |
| `0x006c` | `int32` | `player_suboption_candidate` | `1` | used instead of DAT_140e41b70 during replay mode |
| `0x0070` | `int32` | `demo_export_field_0x70` | `6` | included in demo text export as one of the 15 header values |
| `0x00b4` | `int32` | `player_state_active_flag` | `1` | start of repeated player/object state snapshot; observed 1 |
| `0x00b8` | `float` | `player_pos_x_candidate` | `360.0` | float 360.0 in samples; likely screen/player X |
| `0x00bc` | `float` | `player_pos_y_candidate` | `600.0` | float 600.0 in samples; likely screen/player Y |
| `0x00c0` | `float` | `player_prev_or_target_x_candidate` | `360.0` | float 360.0 in samples |
| `0x00c4` | `float` | `player_prev_or_target_y_candidate` | `600.0` | float 600.0 in samples |
| `0x00c8` | `int32` | `player_angle_or_fixed_velocity_candidate` | `49152` | 0x0000c000 in samples; resembles fixed-point direction/speed |
| `0x00d8` | `int32` | `player_state_mode_candidate` | `2` | observed 2 |
| `0x00e4` | `float` | `subobject0_pos_x_candidate` | `360.0` | float 360.0 in samples |
| `0x00e8` | `float` | `subobject0_pos_y_candidate` | `600.0` | float 600.0 in samples |
| `0x00ec` | `float` | `subobject1_pos_x_candidate` | `360.0` | float 360.0 in samples |
| `0x00f0` | `float` | `subobject1_pos_y_candidate` | `600.0` | float 600.0 in samples |
| `0x0104` | `float` | `subobject_velocity_or_angle_x_candidate` | `-2.0117` | float about -2.0117 in samples |
| `0x0108` | `float` | `subobject_velocity_or_angle_y_candidate` | `-2.0117` | float about -2.0117 in samples |
| `0x0128` | `int32` | `state_counter_128` | `32` | observed 32 |
| `0x0134` | `int32` | `state_counter_134` | `60` | observed 60 |
- First input records as `(uint32 frame_or_tick, int16 input_state, uint16 pad_or_flags)`: `[(0, 0, 0), (1, 0, 0), (2, 0, 0), (3, 0, 0), (4, 0, 0), (5, 0, 0), (6, 0, 0), (7, 0, 0), (8, 0, 0), (9, 0, 0)]`.

## replay/LD_replay24.dat

- Size: 163392 bytes
- SHA256: `83b87ed4195475f5f971d94dcab7840a23e0da5b5c0c6ed7fc071984911a3ffe`
- First 64 bytes: `c8 00 00 00 75 4e 00 00 48 54 20 00 00 00 00 00 f6 1c 81 67 00 00 00 00 00 00 00 00 00 00 00 00 04 00 00 00 01 00 00 00 00 00 00 00 02 00 00 00 01 00 00 00 00 00 00 00 01 00 00 00 03 00 00 00`
- Entropy first 4096 bytes: 1.6301
- Entropy full file: 3.8346
- Confirmed replay header size: `0xa98` / `2712` bytes.
- Payload bytes after header: `160680`; as 8-byte input records: `20085` remainder `0`.
- Header first `int32` is schema sentinel `200`; second `int32` is declared input record count `20085`.
- Player tag/initials bytes at `0x0008`: `48 54 20 00` -> `HT `.
- Timestamp candidate at `0x0010`: `1736514806` / UTC 2025-01-10 13:13:26.
- First 32 header `int32` values: `(200, 20085, 2118728, 0, 1736514806, 0, 0, 0, 4, 1, 0, 2, 1, 0, 1, 3, 7, 7, 2, 4, 6, 0, 240152166, 0, 0, 0, 1, 1, 6, 1, 0, 0)`.

| Offset | Type | Provisional name | Value | Evidence / note |
|---:|---|---|---:|---|
| `0x0000` | `int32` | `version_or_magic` | `200` | valid/current value is 200 |
| `0x0004` | `int32` | `input_record_count` | `20085` | matches payload bytes / 8 in samples |
| `0x0008` | `char[3]+NUL` | `player_tag_or_initials` | `HT ` | written from three selected characters |
| `0x0010` | `int32` | `unix_timestamp_candidate` | `1736514806 / UTC 2025-01-10 13:13:26` | sample values decode to plausible UTC save dates |
| `0x0018` | `int32` | `mode_or_route_candidate` | `0` | demo header field #2 / loaded into DAT_140e41928 |
| `0x001c` | `int32` | `mode_subfield_candidate` | `0` | loaded into DAT_140e41abc |
| `0x0020` | `int32` | `play_setting_0` | `4` | part of demo/replay 15-field header |
| `0x0024` | `int32` | `play_setting_1` | `1` | part of demo/replay 15-field header |
| `0x0028` | `int32` | `play_setting_2` | `0` | part of demo/replay 15-field header |
| `0x002c` | `int32` | `stage_or_section_candidate` | `2` | loaded into DAT_140e445c0 |
| `0x0030` | `int32` | `stage_progress_candidate` | `1` | loaded into DAT_140e445c4 |
| `0x0034` | `int32` | `stage_progress_candidate_2` | `0` | loaded into DAT_140e445c8 |
| `0x0038` | `int32` | `stage_progress_candidate_3` | `1` | loaded into DAT_140e445cc |
| `0x003c` | `int32` | `stage_progress_candidate_4` | `3` | loaded into DAT_140e445d0 |
| `0x0040` | `int32` | `demo_checkpoint_or_stage` | `7` | demo header field #15; replay load may copy it to DAT_1407c7798 in mode 0 |
| `0x0044` | `int32` | `binary_current_stage` | `7` | binary-only field written from DAT_1407c7798 before replay save |
| `0x0048` | `int32` | `stage_group_checkpoint_0` | `2` | used by stage transition code for stage group 1 |
| `0x004c` | `int32` | `stage_group_checkpoint_1` | `4` | used by stage transition code for stage groups 2/3 |
| `0x0050` | `int32` | `stage_group_checkpoint_2` | `6` | used by stage transition code for stage groups 4/5 |
| `0x0058` | `int64 low` | `score_or_counter_candidate` | `240152166` | written from DAT_140e44590; high-variance low dword in samples |
| `0x0060` | `int64 low` | `secondary_score_or_counter_candidate` | `0` | written from DAT_140e451b0; zero in current samples |
| `0x0064` | `int32` | `unknown_runtime_value_64` | `0` | written from DAT_140e4680c; zero in current samples |
| `0x0068` | `int32` | `player_option_or_type_candidate` | `1` | used instead of DAT_140e44194 during replay mode |
| `0x006c` | `int32` | `player_suboption_candidate` | `1` | used instead of DAT_140e41b70 during replay mode |
| `0x0070` | `int32` | `demo_export_field_0x70` | `6` | included in demo text export as one of the 15 header values |
| `0x00b4` | `int32` | `player_state_active_flag` | `1` | start of repeated player/object state snapshot; observed 1 |
| `0x00b8` | `float` | `player_pos_x_candidate` | `360.0` | float 360.0 in samples; likely screen/player X |
| `0x00bc` | `float` | `player_pos_y_candidate` | `600.0` | float 600.0 in samples; likely screen/player Y |
| `0x00c0` | `float` | `player_prev_or_target_x_candidate` | `360.0` | float 360.0 in samples |
| `0x00c4` | `float` | `player_prev_or_target_y_candidate` | `600.0` | float 600.0 in samples |
| `0x00c8` | `int32` | `player_angle_or_fixed_velocity_candidate` | `49152` | 0x0000c000 in samples; resembles fixed-point direction/speed |
| `0x00d8` | `int32` | `player_state_mode_candidate` | `2` | observed 2 |
| `0x00e4` | `float` | `subobject0_pos_x_candidate` | `360.0` | float 360.0 in samples |
| `0x00e8` | `float` | `subobject0_pos_y_candidate` | `600.0` | float 600.0 in samples |
| `0x00ec` | `float` | `subobject1_pos_x_candidate` | `360.0` | float 360.0 in samples |
| `0x00f0` | `float` | `subobject1_pos_y_candidate` | `600.0` | float 600.0 in samples |
| `0x0104` | `float` | `subobject_velocity_or_angle_x_candidate` | `-2.0117` | float about -2.0117 in samples |
| `0x0108` | `float` | `subobject_velocity_or_angle_y_candidate` | `-2.0117` | float about -2.0117 in samples |
| `0x0128` | `int32` | `state_counter_128` | `32` | observed 32 |
| `0x0134` | `int32` | `state_counter_134` | `60` | observed 60 |
- First input records as `(uint32 frame_or_tick, int16 input_state, uint16 pad_or_flags)`: `[(0, 602, 0), (1, 602, 0), (2, 602, 0), (3, 602, 0), (4, 602, 0), (5, 90, 0), (6, 90, 0), (7, 90, 0), (8, 90, 0), (9, 90, 0)]`.

## save/config.dat

- Size: 28 bytes
- SHA256: `e6b10ff8681fb7461557e6227d036617c7ecfc6e31a35412f8a5f72c217f318b`
- First 64 bytes: `01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00`
- Entropy first 4096 bytes: 0.3712
- Entropy full file: 0.3712
- Confirmed runtime read/write size: `0x1c` / `28` bytes at config block `DAT_140e468f0`.
- Seven little-endian `int32` fields: `(1, 0, 0, 0, 1, 0, 0)`.

## save/save.dat

- Size: 10032 bytes
- SHA256: `3bbde7413ca83ca63b54c07b2da2ecd5f804f33e7712d91c641c27b872543407`
- First 64 bytes: `c8 00 00 00 01 00 00 00 01 00 00 00 01 00 00 00 01 00 00 00 02 00 00 00 00 00 00 00 01 00 00 00 00 00 00 00 03 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 03 00 00 00 01 00 00 00 01 00 00 00`
- Entropy first 4096 bytes: 1.1408
- Entropy full file: 1.2340
- Confirmed runtime read/write size: `0x2730` / `10032` bytes at global save block `DAT_140e41b10`.
- First little-endian `int32` is the save schema/version sentinel; current valid value is `200` (`0xc8`).

## Handler evidence

- `game_startup_init_candidate` reads `save\save.dat` into `DAT_140e41b10` with size `0x2730`, creates it via `FUN_1400d0aa0()` when missing, and accepts/migrates sentinel `200`.
- `save_init_or_reset_candidate` writes `DAT_140e41b10` back to `save\save.dat` with size `0x2730` and sets `DAT_140e471fc = 0xb4`.
- `game_startup_init_candidate` reads `save\config.dat` into `DAT_140e468f0` with size `0x1c`; on first run it writes seven default `int32` fields.
- `config_handler_candidate` updates config menu fields `DAT_140e468f0` through `DAT_140e46908`, then startup consumes `DAT_140e46908` as an audio/sound mode selector.
- `replay_handler_candidate_B` scans 24 replay slots, reads each `0xa98`-byte header into `DAT_140e8cf40 + slot * 0xa98`, and marks `DAT_140e9fd40[slot] = 1` when the header sentinel is `200`.
- `replay_or_save_handler_candidate_A` loads the selected replay: first a `0xa98` header into `DAT_140e45280`, then a linked list of 8-byte input records until EOF.
- `replay_or_save_handler_candidate_C` writes replay files: a `0xa98` header from `DAT_140e45280`, followed by linked-list input records serialized as 8 bytes each. In demo-export mode it writes text records to `media\demo\LD_demo%02d.txt` instead.


## Replay header layout notes

The binary replay header begins at `DAT_140e45280` and has the same logical field order as the first line of demo text files, except binary replays also carry a 3-character player tag at `0x0008` and timestamp-like metadata at `0x0010` before the gameplay fields used by demo import/export.

Known decompiler data flow:

- `DAT_140e45284` (`0x0004`) is exported as demo field #1 and bounds demo input-record import; in binary samples it equals payload byte count divided by 8.
- `DAT_140e45288..8a` (`0x0008`) are filled from three selected characters before binary replay save.
- `DAT_140e45298` (`0x0018`) through `DAT_140e452c0` (`0x0040`) correspond to demo text fields #2..#15.
- Binary replay save additionally writes `DAT_140e452c4` (`0x0044`) from `DAT_1407c7798`, `DAT_140e452d8` (`0x0058`) from `DAT_140e44590`, `DAT_140e452e0` (`0x0060`) from `DAT_140e451b0`, and `DAT_140e452e4` (`0x0064`) from `DAT_140e4680c`.
- Stage transition code uses `DAT_140e452c8`, `cc`, and `d0` (`0x0048..0x0050`) as stage-group checkpoint defaults.
- Replay-mode player update uses `DAT_140e452e8` and `DAT_140e452ec` (`0x0068..0x006c`) instead of the normal player option globals `DAT_140e44194` and `DAT_140e41b70`.
- `0x00b4..0x0134` decodes as a compact float-heavy state snapshot: repeated `360.0, 600.0` pairs, fixed-point-looking `0x0000c000`, and counters `32`/`60`. Nearby player update code initializes similar globals (`DAT_140e445d8`, `DAT_140e445dc`, `DAT_140e44654`, `DAT_140e44648`) to the same values, so this region is likely player/subobject initial runtime state rather than timestamps.
- Demo text import/export uses the 15-field format string `%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d`, then serializes the same 8-byte input stream as text `%d,%d` records.
