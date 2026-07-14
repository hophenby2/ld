# Projectile Helper Call-site Map

Status: representative call-site map for `FUN_14006c2f0`, `FUN_1400709b0`, and `FUN_140070d00`. This complements `projectile-helper-notes.md`; it is not exhaustive, but records high-signal stage/entity helpers and constants worth using for future names.

## Helper scale

| Helper | Approximate call-site coverage in current exports | Meaning |
|---|---:|---|
| `FUN_14006c2f0` | ~727 decompiled calls across ~142 files | Allocate/enqueue one projectile node. |
| `FUN_1400709b0` | ~599 decompiled calls across ~104 files | Wrapper that emits a projectile spread/fan/ring by repeatedly calling `FUN_14006c2f0`. |
| `FUN_140070d00` | ~146 decompiled calls across ~78 files | Allocate/enqueue one visual/effect node. |

Counts include duplicate export sets; use as a coverage estimate rather than a unique-site count.

## `FUN_14006c2f0` representative projectile call sites

| Stage/entity | Helper file | Representative pattern | Interpretation |
|---|---|---|---|
| Stage04 type `0x36` | `140091540_FUN_140091540.c` | `FUN_14006c2f0(4, 0, x, y, angle + offsets, 0, speed, flags, 0)` | Side-entry curving multipart emitter; centered 3/5-shot spread. |
| Stage04 type `0x37` | `140092230_FUN_140092230.c` | `FUN_14006c2f0(0, 0, x, y, aimed_angle + jitter, 0, speed, 1, 0)` | Random drifting aimed microburst emitter; high difficulty adds extra shot. |
| Stage04 type `0x3f` | `140095130_FUN_140095130.c` | Selectors `7` and `4` with id `0`, plus selector `2` / id `0` spreads | Boss-like multipart pattern controller; alternating mounts, jitter windows, and half-circle fans. |
| Stage04 types `0x39/0x3a` | `140093540_FUN_140093540.c` | `FUN_14006c2f0(8, variant_mod, x, y, angle, speed, ..., flags, 0)` | Directional child carrier pair; also uses id `3` spread wrapper. |
| Stage05 type `0x4f` | `14009b5f0_FUN_14009b5f0.c` | `FUN_14006c2f0(3, 0x1c, x, y, angle + phase terms, 0, ..., flags, 0)` | Boss-like multi-phase summoner; later direct volleys after spread phases. |
| Stage07 type `0x75` | `1400a4fe0_FUN_1400a4fe0.c` | `FUN_14006c2f0(5, 0, x, y, aim + fan_offsets, 0, speed, flags, extra)` | Lower anchor dense aimed/fan emitter. |
| Stage07 type `0x76` | `1400a5dd0_FUN_1400a5dd0.c` | `FUN_14006c2f0(10, 0, x, y, angle, speed, ...)` | Heavy multipart pattern source, mixed with ids `7`, `0xf`, `2` via spread wrapper. |
| Final type `0xfb` | `1400af900_FUN_1400af900.c` | `FUN_14006c2f0(8, 0, x, y, angle, 0, DAT_14053a160, flags, 0)` | Homing/chasing swarmer that fires forward shots. |
| Final type `0x100` | `1400b1db0_FUN_1400b1db0.c` | `FUN_14006c2f0(7, 0, paired_offset_x, paired_offset_y, angle, speed, ..., 1, 0)` | Dual child / paired aimed emitter. |
| Final type `0x102` | `1400b2760_FUN_1400b2760.c` | `FUN_14006c2f0(0xd, 0, offset_x, offset_y, angle, 0, speed, flags, 0)` and later id `0` bursts | Large multi-part carrier/emitter; repeated final-stage id `0xd` shots. |
| Final types `0x103/0x104` | `1400b3540_FUN_1400b3540.c` | `FUN_14006c2f0(4, 0x34, x, y, orbit_angle + base_angle, 0, speed, flags, 0)` | Four-offset rotating/orbit burst pair. |
| Stage01 type `0x0b` | `14007d4e0_FUN_14007d4e0.c` | `FUN_14006c2f0(0, phase_mod, x, y+offset, aimed_quantized_angle, 0, difficulty_speed, flags, 0)` | State-1 aimed id `0` microburst while helper age `< 200`; start frame and interval are difficulty-scaled, with a three-interval burst inside a five-interval cycle. |
| Stage01 type `0x0c` | `14007dfb0_FUN_14007dfb0.c` | `FUN_14006c2f0(7, 0, x±DAT_14053ac60, y, side_aim_angle, DAT_14053ac2c, speed + phase_delta, flags, 0)` | Paired left/right id `7` shots during state age `< 200`; high difficulty adds angled variants from both sides. |
| Stage01 type `0x0d` | `14007ea30_FUN_14007ea30.c` | `FUN_14006c2f0(0, global_frame_mod, side_offset_x, side_offset_y, aimed_quantized_angle, 0/DAT_14053ac2c, difficulty_speed, flags, 0)` | Side-entry source emits id `0` on global-frame modulo intervals; original also emits a paired accelerated shot. |

## `FUN_1400709b0` representative spread/ring call sites

| Stage/entity | Helper file | Representative pattern | Interpretation |
|---|---|---|---|
| Stage04 type `0x38` | `140092b20_FUN_140092b20.c` | `FUN_1400709b0(9, 0, ..., count, variable_spread, 0)` and `FUN_1400709b0(8, 0, ..., count, 20000, 0)` | Large sinusoidal multipart pattern emitter. |
| Stage04 types `0x39/0x3a` | `140093540_FUN_140093540.c` | `FUN_1400709b0(3, 1, ..., count, 22000, 0)` | Child-carrier pair; player-aimed/fan spreads. |
| Stage04 type `0x3d` | `1400941d0_FUN_1400941d0.c` | `FUN_1400709b0(5, 0, ..., base_angle ± constants, count, spread, 0)` | Three-anchor symmetric spread emitter. |
| Stage04 type `0x3f` | `140095130_FUN_140095130.c` | `FUN_1400709b0(2, 0, ..., count, 0x8000, 0)`; the guarded modulo value passed as arg2 is zero | Boss-like half-circle/fan spread using selector 2 and basic movement id 0. |
| Stage05 type `0x4f` | `14009b5f0_FUN_14009b5f0.c` | IDs `10` and `0xb`, count-dependent spreads `count*7000-7000` / `count*12000-12000` | Boss-like summoner multi-phase fan families. |
| Stage07 type `0x70` | `1400a2310_FUN_1400a2310.c` | `FUN_1400709b0(0xc, 0, ..., count, count*0x1c2-0x1c2, 0)` and spread `3000` | Dual-anchor aimed spread emitter. |
| Stage07 type `0x73` | `1400a3990_FUN_1400a3990.c` | `FUN_1400709b0(7, ...)` from four offsets and `FUN_1400709b0(0xc, 0, center_x, center_y, ...)` | Drifting multipart emitter; offset-point bursts plus center spreads. |
| Stage07 type `0x76` | `1400a5dd0_FUN_1400a5dd0.c` | IDs `7`, `0xf`, and `FUN_1400709b0(2, 7, ..., count, 27000, 0)` | Heavy multipart pattern emitter. |
| Stage07 type `0x77` | `1400a7760_FUN_1400a7760.c` | IDs `4` and `0xc` | Boss-like pattern controller. |
| Final type `0xfd` | `1400b0b70_FUN_1400b0b70.c` | `FUN_1400709b0(0xd, 0, ..., count, count*400-400, 0)` | Spinning fan-burster; ramping fan bursts in 60-frame cycle. |
| Dense scripted/boss helper | `14004a970_FUN_14004a970.c` | IDs `0xc`, `3`, `9`, `5`, `0xd`, including `spread=0x10000` | One of the densest general/boss pattern callers; full rings visible. |

## `FUN_140070d00` representative effect call sites

| Context | Helper file | Representative pattern | Interpretation |
|---|---|---|---|
| Opening/attract visuals | `1400f7570_state_01_opening_attract_candidate.c` | `FUN_140070d00(0, DAT_140e41a40, 1/10, x, y, 0xc000, ..., 0xff,0xff,0xff,0x80, 0)` | White translucent attract/opening effect. |
| Player movement | `140106be0_player_update_input_movement_candidate.c` | `FUN_140070d00(0x18, DAT_140e41a40, 0x16, ...)` | Short movement/trail effect. |
| Dense generic effects | `140079e20_FUN_140079e20.c` | Effect ids `0x2a`, `0x2c`, `0xc` with white `RGBA` constants | Useful for confirming color/alpha args. |
| Stage07 type `0x75` | `1400a4fe0_FUN_1400a4fe0.c` | `FUN_140070d00(0x38, DAT_140e41948, 0x15, ..., 0x78, 0xff,0xff,0xff,0x80, 0)` | Timeout/death-ish effect. |
| Stage07 type `0x76` | `1400a5dd0_FUN_1400a5dd0.c` | `FUN_140070d00(0x38, DAT_140e45090, 0x15, ..., 0x78, 0xff,0xff,0xff,0xc0, 0)` | Same effect type as `0x75`, different graph handle/alpha. |
| Stage07 type `0x77` | `1400a7760_FUN_1400a7760.c` | `FUN_140070d00(0x38, DAT_140e45090, 0x15, ...)` | Boss-like pattern effect. |
| Mixed gameplay/effect caller | `140066370_FUN_140066370.c` | `FUN_140070d00(10, DAT_140e44aa4, 0x1d)` and `FUN_140070d00(5, DAT_140e44aa0, 0x1c)` | Enemy-resource effect nodes. |

## Common effect constants

| Category | Observed constants |
|---|---|
| Effect IDs | `0`, `4`, `5`, `7`, `10`, `0xc`, `0x18`, `0x2a`, `0x2c`, `0x30`, `0x35`, `0x36`, `0x37`, `0x38`, `0x3c`, `0x41` |
| General/effect graph handles | `DAT_140e41a40`, `DAT_140e41a50`, `DAT_140e41a54`, `DAT_140e41a88`, `DAT_140e41a8c`, `DAT_140e41a90`, `DAT_140e41948`, `DAT_140e41974` |
| Enemy/resource graph handles | `DAT_140e44aa0`, `DAT_140e44aa4`, `DAT_140e44ea8`, `DAT_140e446d4`, `DAT_140e4487c`, `DAT_140e44880`, `DAT_140e45090` |
| Lifetime/frame arg | `1`, `5`, `6`, `10`, `0x15`, `0x16`, `0x1c`, `0x1d`, `0x22`, `0x23`, `0x28`, `0x2d`, `0x3c`, `0x3d`, `0x3e`, `0x48`, `0x50`, `0x7a` |
| Common colors | `0xff,0xff,0xff,0xff`; `0xff,0xff,0xff,0xc0`; `0xff,0xff,0xff,0x80`; `0xff,0xff,0xff,0x60` |

## Cross-reference

The best current semantic map tying projectile helper usage to scheduled stage entities remains `stage-spawn-semantic-name-candidates.md`. Use that file when deciding whether a projectile pattern belongs to an ordinary enemy, child carrier, boss-like controller, or final-stage setpiece.
