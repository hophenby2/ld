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
| `0x46` | `FUN_140097d30` | `stage05_multi_part_aimed_burst_emitter` | Medium | Marker phase, then multi-phase motion: initially turns slowly toward the player, accelerates/retargets, then decelerates. Emits difficulty-scaled type `7` bursts from about frame `0x40`, including extra offset/spread shots on higher difficulty; renders a multi-part body from `DAT_140e44720..72c`. |
| `0x35` | `FUN_140090c30` | `stage04_triple_afterimage_aimed_emitter` | Medium | Marker phase followed by edge-aware turning and player-aimed type `6` shots at difficulty-dependent cadence. Renders the main body plus three manually allocated visual clones with rotations separated by roughly thirds (`0`, `+0x5555`, `-0x5556`), suggesting a tri-blade/afterimage visual. |
| `0x45` | `FUN_140097270` | `stage05_swooping_aimed_spread_emitter` | Medium | Re-randomizes its position after the marker phase, steers toward the player for the first `0x96` frames, then turns toward `0xc000` while speed rises. Emits type `8` shots with extra paired/offset volleys on higher difficulty and renders a five-part body from `DAT_140e44c08..c10`. |
| `0x70` | `FUN_1400a2310` | `stage07_dual_anchor_aimed_spread_emitter` | Medium | Tracks both an anchor position (`param[0xc/0xd]`) and a displayed offset position (`param[10/0xb]`). It retargets toward the player with clamped angles, emits difficulty-scaled `FUN_1400709b0(0xc, ...)` spreads after a delay, and renders anchor/body/offset effects from `DAT_140e44798..7a4`. |
| `0xfa` | `FUN_1400af090` | `final_stage_curving_single_shot_emitter` | Medium | Initializes heading from entry side, curves using edge-aware steering while maintaining a separate aimed angle field, and periodically emits type `9` shots when on-screen and sufficiently far from the player. Renders a compact three-part body from `DAT_140e448c0/c4`. |
| `0xfc` | `FUN_1400b0120` | `final_stage_swaying_triple_shot_sweeper` | Medium | Marker phase resets to a new position and speed, then sways horizontally while moving for roughly `0xb4` frames before turning downward. Fires periodic volleys: a central type `0xc` shot plus paired type `4` shots offset left/right; renders a multi-part body from `DAT_140e448d0..8dc`. |

## Helper-group interpretation

| Spawn family | Working interpretation |
|---|---|
| `0x00..0x10` | Common/early families. Contains tutorial/intro-like core variants and common emitters reused across many stages. |
| `0x19..0x2e` | Stage02/03 family block; mostly one helper per scheduled type, likely a themed enemy set. |
| `0x35..0x4f` | Stage04/05 family block; includes several high-frequency edge-entry emitters. |
| `0x57..0x77` | Stage06/07 family block; includes paired diving/aimed emitters and several long-lived pattern emitters. |
| `0x95..0xa4` | Composite/late-stage family; multiple scheduled types spawn internal child entities (`0x9d`, `0xa0`, `0xa3`). |
| `0xfa..0x104` | Final/special high-numbered family; mostly one helper per type, likely final-stage-specific behaviors. |

## Next review targets

1. Cross-reference resource globals used by the reviewed helpers (`DAT_140e44720..72c`, `DAT_140e44c08..c10`, `DAT_140e44798..7a4`, `DAT_140e448c0..c4`, `DAT_140e448d0..8dc`) before applying permanent names.
2. Review neighboring same-stage helpers around `0x36..0x4f`, `0x71..0x77`, and `0xfb/0xfd/0xfe/0x100/0x102` to see whether the new labels should be family-wide or only per-type.
3. Cross-reference scheduled spawn coordinates/counts against each helper's entry-side and retargeting behavior to separate true edge-entry enemies from random repositioning after marker phase.
