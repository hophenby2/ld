# Stage Spawn Semantic Name Candidates

Status: first-pass semantic labels for scheduled spawn types. These are conservative descriptive names based on update helper behavior, call schedules, and helper side effects. Do not apply as Ghidra/user-facing renames until each row's confidence is promoted by deeper resource/render evidence.

## Naming rules

- Prefer behavior/shape labels over enemy names until sprite/resource IDs are confirmed.
- Use `emitter`, `spinner`, `carrier`, `burst`, `sweeper`, `boss_part`, or `wave` style labels when the helper clearly emits bullets/effects or drives child entities.
- Keep numeric family prefixes in notes to preserve traceability.

## High-confidence anchors

| Spawn type(s) | Update helper | Candidate semantic label | Confidence | Evidence |
|---|---|---|---|---|
| `0x0b` | `FUN_14007d4e0` | `common_homing_burst_emitter` | Medium | Most frequent scheduled type. Initializes from offscreen/top-edge coordinates, steers angle toward player, emits `FUN_14006c2f0(0, ...)` bursts while alive, renders a core object, and on expiry creates a 4-way visual/effect ring before cleanup. |
| `0x2, 0x3, 0x4, 0x5` | `FUN_1401331c0` | `stage00_orbiting_core_variants` | Medium | Shared helper for early type set. Uses sinusoidal orbit around origin, renders body plus 5 satellite visuals; `0x3` emits a 40-shot radial ring, `0x5` emits repeated 30-shot spreads, and `0x2..0x5` select distinct visual resources. |
| `0x6, 0x7, 0x8` | `FUN_140082d90` | `common_spawn_marker_to_emitter` | Medium | Waits through a marker phase, then for type `0x6`/`0x7` spawns child type `9` entities based on stage route count. Then moves/aims and emits periodic player-aimed shots. |
| `0x57, 0x58` | `FUN_14009d610` | `stage06_diving_aimed_emitter_pair` | Medium | Pair differs by initial angle (`0x58f0` vs `10000`). Starts with randomized offset, homes/steers toward player, emits repeated `FUN_1400709b0`/`FUN_14006c2f0` bullet patterns, then cleans up on bounds/lifetime. |
| `0x9b, 0x9c, 0x9e, 0x9f, 0xa1, 0xa2` | `FUN_1400abc50` | `composite_child_spawner_triplets` | Medium | At activation, each subtype spawns four child entities: `0x9b/0x9c -> 0x9d`, `0x9e/0x9f -> 0xa0`, `0xa1/0xa2 -> 0xa3`; then moves with per-subtype speed and periodic retargeting. Strong child-carrier behavior. |
| `0x103, 0x104` | `FUN_1400b3540` | `final_pair_aimed_emitter` | Low-Medium | Shared high-numbered final-stage helper; subtypes only differ by initial direction branch. Needs deeper projectile/resource review before applying. |

## Reviewed frequency-driven candidates

| Spawn type(s) | Update helper | Candidate label | Confidence | Evidence |
|---|---|---|---|---|
| `0x46` | `FUN_140097d30` | `stage05_medium_multi_part_aimed_burst_emitter` | Medium | Marker phase, then multi-phase motion: initially turns slowly toward the player, accelerates/retargets, then decelerates. Emits difficulty-scaled type `7` bursts from about frame `0x40`, including extra offset/spread shots on higher difficulty; renders a medium multi-part body from `DAT_140e44c08..c10` (`Enemy_m.png` frames 78-80). |
| `0x35` | `FUN_140090c30` | `stage04_triple_afterimage_aimed_emitter` | Medium | Marker phase followed by edge-aware turning and player-aimed type `6` shots at difficulty-dependent cadence. Renders the main body plus three manually allocated visual clones with rotations separated by roughly thirds (`0`, `+0x5555`, `-0x5556`), suggesting a tri-blade/afterimage visual. |
| `0x45` | `FUN_140097270` | `stage05_small_swooping_aimed_spread_emitter` | Medium | Re-randomizes its position after the marker phase, steers toward the player for the first `0x96` frames, then turns toward `0xc000` while speed rises. Emits type `8` shots with extra paired/offset volleys on higher difficulty and renders a six-call small multipart body from `DAT_140e44720..72c` (`Enemy_s.png` frames 48-51). |
| `0x70` | `FUN_1400a2310` | `stage07_dual_anchor_aimed_spread_emitter` | Medium | Tracks both an anchor position (`param[0xc/0xd]`) and a displayed offset position (`param[10/0xb]`). It retargets toward the player with clamped angles, emits difficulty-scaled `FUN_1400709b0(0xc, ...)` spreads after a delay, and renders anchor/body/offset effects from `DAT_140e44798..7a4` (`Enemy_s.png` frames 78-81; `447a4` also appears as a translucent effect in sibling helpers). |
| `0xfa` | `FUN_1400af090` | `final_stage_curving_single_shot_emitter` | Medium | Initializes heading from entry side, curves using edge-aware steering while maintaining a separate aimed angle field, and periodically emits type `9` shots when on-screen and sufficiently far from the player. Renders a compact three-part body from `DAT_140e448c0/c4` (`Enemy_s.png` frames 152-153). |
| `0xfc` | `FUN_1400b0120` | `final_stage_swaying_triple_shot_sweeper` | Medium | Marker phase resets to a new position and speed, then sways horizontally while moving for roughly `0xb4` frames before turning downward. Fires periodic volleys: a central type `0xc` shot plus paired type `4` shots offset left/right; renders a multi-part body from `DAT_140e448d0..8dc` (`Enemy_s.png` frames 156-159). |

## Adjacent helper candidates

These are conservative per-type labels from neighboring families. Low-confidence rows are mostly schedule/dispatch based because the helper body is not yet exported.

| Spawn type(s) | Update helper | Candidate label | Confidence | Evidence |
|---|---|---|---|---|
| `0x36` | `FUN_140091540` | `stage04_side_entry_curving_multipart_spread_emitter` | Medium | Newly exported helper confirms side-entry/offscreen behavior matching schedule: marker phase, edge-dependent randomized heading, active turn toward player, then downward/exit turn after ~`0xc9` frames. Fires difficulty-scaled `FUN_14006c2f0(4, 0, ...)` centered 3-shot spread, with high-difficulty wider 5-shot variant. Renders small multipart body using `DAT_140e446fc`, `DAT_140e446f8`, and `Enemy_s.png` frames roughly `0x22..0x25`. |
| `0x37` | `FUN_140092230` | `stage04_random_drifting_aimed_microburst_emitter` | Medium | Newly exported helper confirms random in-screen materialization/drifter rather than side-entry: long marker phase to frame `0x78`, randomized initial heading, sinusoidal active speed modulation, smoothed aim toward player, and difficulty-scaled `FUN_14006c2f0(0, 0, ...)` aimed microbursts with high-difficulty extra shot. Renders `DAT_140e44704` and `DAT_140e44700`. |
| `0x38` | `FUN_140092b20` | `stage04_large_multipart_sinusoidal_pattern_emitter` | Medium-High | Long-lived Stage04-heavy fixed-slot enemy. Marker/arrival phase transitions to active sinusoidal movement with gradual player-angle tracking, six-part body render (`DAT_140e44bd8`, `DAT_140e44bd4`, `DAT_140e44bd0`, `DAT_140e44bcc`), and difficulty-scaled `FUN_1400709b0(9, ...)` / `FUN_1400709b0(8, ...)` volleys. No clear gameplay child spawn. |
| `0x39, 0x3a` | `FUN_140093540` | `stage04_directional_child_carrier_pair` | Medium | Shared helper branches on `param[6] == 0x39/0x3a`, uses distinct turn behavior, periodically spawns child `0x3b`, and eventually spawns `0x3c`. Uses projectile/effect helpers `FUN_1400709b0(3, ...)` and `FUN_14006c2f0(8, ...)`; resource globals include `DAT_140e44be0..bec`. |
| `0x3d` | `FUN_1400941d0` | `stage04_three_anchor_spread_emitter` | Medium-High | On frame 0 spawns three persistent child/anchor entities of type `0x3e`, then repositions after activation and emits repeated symmetric `FUN_1400709b0(5, ...)` spreads. Strong child-anchor evidence. |
| `0x3f` | `FUN_140095130` | `stage04_boss_like_multipart_pattern_controller` | High | Only two long-lived S04 entries. Large multi-phase setpiece: sound/effect setup, random target movement for early active phase, later deterministic/vertical phase, extensive difficulty-scaled projectile scripts using `FUN_14006c2f0(7, ...)`, `FUN_14006c2f0(4, ...)`, and `FUN_1400709b0(2, ...)`, special death/effect handling, and `DAT_140e418cc = 0` cleanup. Resources include `DAT_140e44708`, `DAT_140e44bf8`, `DAT_140e44958`. |
| `0x44` | `FUN_140096890` | `stage05_fast_curving_suicide_burst_emitter` | Medium | Marker phase then active-position reselection, fast player-steering motion, paired translucent/rotating render parts (`DAT_140e44718/71c`), and on death/expiry emits type `9` bursts with extra side shots at high difficulty. |
| `0x47, 0x48` | `FUN_140098700` | `stage05_orbiting_child_ring_emitter_pair` | Medium | Shared helper; around frame `0x3c` spawns a difficulty-scaled ring of child `0x49` entities, then steers toward the player and emits `FUN_1400709b0(0xb, ...)` volleys. `0x48` has an extra initial-orbit branch. |
| `0x4a` | `FUN_140099570` | `stage05_four_anchor_chaser_spread_emitter` | Medium-High | Spawns four persistent child anchors of type `0x4b`, maintains body plus secondary target/offset state, and emits repeated `FUN_1400709b0(4, ...)` spreads. Schedule uses long-lived fixed central entries, matching scripted anchor/chaser behavior. |
| `0x4d` | `FUN_14009a4a0` | `stage05_three_satellite_charge_emitter` | Medium | On activation plays sound, spawns three child `0x4e` satellites, turns/charges toward the player, decelerates, then emits dense alternating `FUN_1400709b0(3, 7, ...)` volleys. |
| `0x4f` | `FUN_14009b5f0` | `stage05_boss_like_multi_phase_summoner` | Medium | Single long-lived S05 schedule entry. Helper seeds random targets, spawns child `0x50`, emits `FUN_1400709b0(10, ...)` then `FUN_1400709b0(0xb, ...)`, later spawns repeated child `0x53` plus `FUN_14006c2f0(3, 0x1c, ...)` volleys. |
| `0x71, 0x72` | `FUN_1400a2ca0` | `stage07_mirrored_medium_emitter_pair` | Medium-High | Shared helper branches by type for mirrored left/right placement, drifts/retargets toward the player, fires paired `FUN_14006c2f0(9, ...)` and later `FUN_1400709b0(4, ...)` projectiles. Renders from `Enemy_m.png`-adjacent handles including `DAT_140e44c94/498`. |
| `0x73` | `FUN_1400a3990` | `stage07_08_drifting_multi_part_emitter` | Medium-High | Newly exported helper confirms long-lived stage07/08 mobile multipart emitter: 20-frame intro, active decaying/random-walk drift, smooth player aiming, `FUN_1400709b0(7, ...)` bursts from four body offset points, and `FUN_1400709b0(0xc, ...)` aimed center spreads. Renders `DAT_140e44ca0`, `DAT_140e44c9c`, and `DAT_140e44ca4`. |
| `0x74` | `FUN_1400a4440` | `stage07_lane_sweeper_aimed_burst_emitter` | Medium | Newly exported helper confirms marker-to-active transition, lower-lane/sweeping movement matching schedule y `0x334`, player-aimed jittered `FUN_14006c2f0(1, 0, ...)` bursts with difficulty-dependent extra shot, and body frames `Enemy_s.png` approximately 82-89 via `(&DAT_140e44660)[0x52..0x59]`. No gameplay child spawns observed. |
| `0x75` | `FUN_1400a4fe0` | `stage07_lower_anchor_bullet_emitter` | Medium | Newly exported helper confirms lower-screen anchored hazard/emitter: short intro, scroll-coupled/oscillating active body, dense difficulty-scaled `FUN_14006c2f0(5, ...)` aimed/fan bursts, layered render parts `DAT_140e447c8/7cc` plus indexed `Enemy_s` body, symmetric manual side nodes using `DAT_140e41958`, periodic pulse nodes using `DAT_140e41a50`, and timeout effect via `FUN_140070d00(0x38, DAT_140e41948, 0x15, ...)`. |
| `0x76` | `FUN_1400a5dd0` | `stage07_heavy_multipart_pattern_emitter` | Medium-High | Newly exported helper confirms a long-lived low-screen heavy pattern source: marker-to-active transition, multipart oscillating body with `Enemy_s.png` frames 94-95 plus `Enemy_m.png` frames 118-122 (`DAT_140e44ca8..cb8`), projectile families `FUN_14006c2f0(10, ...)`, `FUN_1400709b0(7, ...)`, `FUN_1400709b0(0xf, ...)`, and `FUN_1400709b0(2, 7, ...)`, plus repeated SFX. No gameplay child spawns observed. |
| `0x77` | `FUN_1400a7760` | `stage07_boss_like_pattern_controller` | High | Only two S07 long-lived entries. Helper spawns child `0x78`, plays boss SFX (`BossSE8`, `BossSE15`), emits `FUN_1400709b0(4, ...)`, `FUN_1400709b0(0xc, ...)`, and `FUN_140070d00(0x38, DAT_140e45090, ...)`, and draws layered enemy sprites. |
| `0xfb` | `FUN_1400af900` | `final_stage_homing_swarmer_with_forward_shots` | Medium | Newly exported helper confirms short materialization phase followed by homing/chasing movement toward player, speed growth, and periodic forward `FUN_14006c2f0(8, 0, ...)` shots when in-bounds and sufficiently far from target. Renders compact body/wing sprites `DAT_140e448c8` and `DAT_140e448cc`. No gameplay child spawns observed. |
| `0xfd` | `FUN_1400b0b70` | `final_stage_spinning_fan_burster` | Medium-High | Newly exported helper confirms a spinning visual and fan-burst pattern: first 0x5a frames slowly turn toward target, then turn downward/away while accelerating. Emits ramping `FUN_1400709b0(0xd, ...)` fan bursts in a 60-frame cycle, with count increasing across the burst window. Renders main `DAT_140e44df8` plus four rotating `DAT_140e44dfc` blade/trail visuals. |
| `0xfe` | `FUN_1400b14d0` | `final_stage_four_satellite_child_carrier` | Medium | At activation spawns four child `0xff` entities, retargets destination fields periodically, and renders `Enemy_m.png` frames 204-205 (`DAT_140e44e00/e04`). No direct bullet emission visible in exported body. |
| `0x100` | `FUN_1400b1db0` | `final_stage_dual_child_paired_aimed_emitter` | Medium | At activation spawns two child `0x101` entities, retargets/steers, then fires paired aimed `FUN_14006c2f0(7, ...)` shots. Renders `Enemy_m.png` frames 206-207 (`DAT_140e44e08/e0c`). |
| `0x102` | `FUN_1400b2760` | `final_stage_large_multi_part_carrier_emitter` | High | Newly exported helper confirms a large composite final-stage emitter: marker phase, active player-tracking movement, multiple sinusoidal body offsets, repeated projectile id `0xd` aimed/random shots, later 15-shot id `0` burst windows, and multipart render resources `DAT_140e44e14`, `DAT_140e448f0`, `DAT_140e44e10`, `DAT_140e448ec`, `DAT_140e44e18`. No clear gameplay child spawn, but strong large setpiece/emitter evidence. |
| `0x103, 0x104` | `FUN_1400b3540` | `final_stage_large_rotating_orbit_burst_emitter_pair` | Medium | Refinement of earlier low-medium label. Pair differs mostly by initial direction. Helper fires four-offset `FUN_14006c2f0(4, 0x34, ...)` shots and renders a complex multipart/orbit visual using `Enemy_m.png` frames 211-213 plus `Enemy_s.png` frame 165. |

All scheduled helper bodies from the current high-value adjacent list have now been exported and reviewed. Remaining work shifts from missing body export to projectile-helper semantics, resource-frame naming, and optional formal Ghidra renames.

## Resource cross-reference notes

The reviewed helper resource globals are divided graph handles inside the primary stage enemy sheets loaded by `load_primary_resources_candidate`:

| Globals | Backing sheet | Frame indexes | Primary use |
|---|---|---:|---|
| `DAT_140e44720..72c` | `media\\stage\\Enemy_s.png` | 48-51 | `0x45` / `FUN_140097270`, small symmetric multipart body. |
| `DAT_140e44c08..c10` | `media\\stage\\Enemy_m.png` | 78-80 | `0x46` / `FUN_140097d30`, medium symmetric multipart body. |
| `DAT_140e44798..7a4` | `media\\stage\\Enemy_s.png` | 78-81 | `0x70` / `FUN_1400a2310`, dual-anchor body plus translucent offset/effect frame. |
| `DAT_140e448c0/c4` | `media\\stage\\Enemy_s.png` | 152-153 | `0xfa` / `FUN_1400af090`, compact final/special body. |
| `DAT_140e448d0..8dc` | `media\\stage\\Enemy_s.png` | 156-159 | `0xfc` / `FUN_1400b0120`, final/special multipart sweeper body. |

Loader anchors: `Enemy_s.png` starts at `DAT_140e44660` with `0xaa` 100x100 frames, `Enemy_m.png` starts at `DAT_140e44ad0` with `0xe6` 200x200 frames, and `Enemy_l.png` starts at `DAT_140e44910` with `0x6e` 600x600 frames. Frame indexes above assume 4-byte graph-handle slots.

## Schedule cross-reference notes

The schedule rows mostly agree with the helper-body interpretation, but they also separate true edge-entry types from helpers that reselect position after the marker phase:

| Spawn type(s) | Schedule pattern | Helper interpretation |
|---|---|---|
| `0x35` | 31 calls across S04/S08/S09. Mostly side-edge/offscreen x lanes (`0x2e4` or `0xffffffec`) with fixed y lanes such as `0x78`, `0x96`, `0xb4`, `0x15e`, and `400`. | True side-edge entry. The helper uses scheduled position through marker-to-active transition; no obvious post-marker coordinate randomization. |
| `0x45` | 23 calls across S05/S08/S09. Mixed side edges, top-edge random x, and fixed top x slot waves (`0x50`, `0xdc`, `0x168`, `500`, `0x26c`). | Marker/entry coordinates are hints only: helper calls `FUN_1401346a0` again at activation and assigns new `param[10]/param[0xb]`, so active position is reselected after marker. |
| `0x46` | 50 calls across S05/S08/S09. Highly scripted offscreen lanes: far-right (`0x42e`, `0x3fc`, `0x398`, `0x460`) and far-left/negative (`0xfffffea2`, `0xfffffed4`, `0xfffffe70`, `0xffffff06`, `0xffffff9c`) x values with small y lanes. | True scripted edge/offscreen entry. Scheduled coordinates remain meaningful and seed the active multi-phase tracking movement. |
| `0x70` | 22 calls across S07/S08. Mix of side-edge random y, bottom entries at `0x30c`, fixed x lanes, and mirrored/patterned x formulas such as `0x136 - (uVar * 6) % 0xf0` and `... % 0xf0 + 0x19a`. | Hybrid dual-anchor/offset mover. Scheduled coordinates seed anchor/display state, not just a simple edge-entry point. |
| `0xfa` | 18 calls in S10. Mostly top entries (`y=0xffffffec`) with fixed x lanes plus side-edge entries (`0x2e4` or `0xffffffec`) with y lanes such as `0x96`, `0xf0`, `0x140`, `0x168`, and `300`. | True edge/top entry. Helper derives initial heading from entry side and then applies edge-aware curve steering. |
| `0xfc` | 11 calls in S10. Early patterned top sweep (`iVar5 * 10`, `y=0xffffffec`), random x top/center rows, and final fixed x slots at `y=0` (`0x3c`, `0xb4`, `300`, `0x1a4`, `0x21c`, `0x294`). | Patterned x-position sweeper with marker reset. Schedule expresses wave layout, but helper resets position/speed and then runs swaying movement before downward turn. |

Overall: `0x35`, `0x46`, and `0xfa` are the clearest true edge-entry types; `0x45` is the clearest random-reposition-after-marker type; `0x70` and `0xfc` are hybrid pattern/anchor cases.

## Helper-group interpretation

| Spawn family | Working interpretation |
|---|---|
| `0x00..0x10` | Common/early families. Contains tutorial/intro-like core variants and common emitters reused across many stages. |
| `0x19..0x2e` | Stage02/03 family block; mostly one helper per scheduled type, likely a themed enemy set. |
| `0x35..0x4f` | Stage04/05 family block; includes several high-frequency edge-entry emitters. Use family prefixes (`stage04_`, `stage05_`) but keep labels per-type because `0x35`, `0x45`, and `0x46` have distinct update helpers, projectile IDs, and resource groups. |
| `0x57..0x77` | Stage06/07 family block; includes paired diving/aimed emitters and several long-lived pattern emitters. `0x70` has a strong dual-anchor identity and should not be treated as a family-wide label for all `0x70..0x77`. |
| `0x95..0xa4` | Composite/late-stage family; multiple scheduled types spawn internal child entities (`0x9d`, `0xa0`, `0xa3`). |
| `0xfa..0x104` | Final/special high-numbered family; mostly one helper per type. Keep `final_` as a family prefix, but keep `0xfa` and `0xfc` labels separate because their projectile IDs, motion, and multipart resources differ. |

## Next review targets

1. Analyze projectile helpers now exported in `missing-helper-priority` and `remaining-helper-priority`: `FUN_14006c2f0`, `FUN_1400709b0`, and `FUN_140070d00`, then build a projectile ID / pattern parameter table.
2. Expand resource-frame naming for `Enemy_s/m/l`, `Boss`, and `Bullet` sheets using the reviewed helper resource clusters.
3. If applying formal Ghidra renames later, prefer conservative per-type names such as `stage05_type46_tracking_shooter_candidate` before using descriptive enemy names.
4. For spawn types whose schedule coordinates disagree with helper movement, classify the scheduled coordinates as marker/entry hints unless the helper preserves them through activation.
