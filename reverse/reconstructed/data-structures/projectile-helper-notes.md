# Projectile Helper Notes

Status: first-pass reconstruction from Ghidra exports. This is a local reverse-engineering aid, not original source. Names are intentionally descriptive and conservative until bullet resources/collision behavior are fully mapped.

Newer companion notes:

- `bullet-frame-visual-map.md` / `.csv` maps `Bullet.png` divided frames, globals, and visual selectors from `FUN_140070250`.
- `projectile-update-helper-semantics.md` records the first deeper pass over the six projectile update helpers using `ProjectileNode` field names.
- `projectile-visual-pair-coverage.md` / `.csv` joins literal projectile constructor calls to Bullet.png visual shapes, distinguishing movement IDs from visual selectors/subpattern values.

## Globals and lists

### Pending projectile list (`DAT_140e45260` / `DAT_140e451a8`)

`FUN_14006c2f0` appends a `0x50`-byte projectile node to a singly-linked list:

- Head: `DAT_140e45260`.
- Tail: `DAT_140e451a8`.
- Count: `DAT_140e451b4`, capped at `0x800`.
- Extra per-window spawn counter: `DAT_140e451a0`.
- Link offset: `+0x48`.

The main gameplay loop dispatches these nodes by `node->projectile_id` / decompiled `piVar17[3]` and later unlinks inactive nodes. `FUN_14006c420` flushes this list into visual effects and frees every node, so this list is probably the enemy/boss projectile list rather than a pure visual-effect list.

### Visual/effect list (`DAT_140e45d78` / `DAT_140e45d28`)

`FUN_140070d00` appends a `0x60`-byte effect/render node:

- Head: `DAT_140e45d78`.
- Tail: `DAT_140e45d28`.
- Count: `DAT_140e45d1c`, capped at `0x1000`.
- Link offset: `+0x58`.

`FUN_140070e40` updates this list by `effect_type` and calls lower-level draw helpers such as `FUN_1400c8410`. Many projectile update helpers also spawn these effect nodes for impacts, trails, clears, or special pulse graphics.

## Helper signatures

### `FUN_14006c2f0` — append one projectile

Candidate name: `spawn_projectile_node`.

Observed prototype:

```c
void spawn_projectile_node(
    int projectile_id,
    int variant_or_owner,
    float x,
    float y,
    uint16_t angle,
    float speed_or_accel_hint,
    double speed,
    int radius_or_flags,
    int arg8);
```

Field mapping for the allocated `0x50`-byte node:

| Offset | Field | Source | Evidence / notes |
|---:|---|---|---|
| `+0x00` | `active` | constant `1` | Main loop removes nodes with `active == 0`. |
| `+0x04` | `age` | zeroed by allocator / incremented externally | Main loop increments `piVar17[1]` each frame. |
| `+0x08` | `variant_or_owner` | arg2 | In draw/update helpers this is primarily the visible bullet selector passed to `FUN_140070250`; in scripted child helpers it can also encode subpattern/owner/variant. See `bullet-frame-visual-map.md`. |
| `+0x0c` | `projectile_id` | arg1 | Main loop dispatch switch key. |
| `+0x10` | `x` | arg3 | Position. |
| `+0x14` | `y` | arg4 | Position. |
| `+0x18` | `prev_x` | arg3 | Mirrored initial position. |
| `+0x1c` | `prev_y` | arg4 | Mirrored initial position. |
| `+0x20` | `speed_or_accel_hint` | arg6 | Some update IDs use it as acceleration / steering magnitude. |
| `+0x24` | `angle` | arg5 | 16-bit fixed angle; update helpers feed it through sin/cos. |
| `+0x26` | `prev_angle` | arg5 | Mirrored initial angle. |
| `+0x28` | `speed` | arg7 | Primary motion speed; update helpers add `cos/sin(angle) * speed`. |
| `+0x30` | `base_speed` | arg7 | Mirrored, used by acceleration/deceleration variants. |
| `+0x38` | `scratch_or_phase` | `0` | Update helpers reuse for timing/secondary speed. |
| `+0x3c` | `radius_or_flags` | arg8 | Passed to draw/collision/update helpers; common values `1`, `0x10`, `0x28`, etc. |
| `+0x40` | `draw_or_collision_enabled` | constant `1` | Looks like enable flag. |
| `+0x44` | `arg8` | arg9 | Often zero; sometimes color/resource/owner-like. |
| `+0x48` | `next` | `NULL` | List link. |

Important gate: no node is created unless `DAT_140e445fc - 0x79U > 0x8a`, so projectile creation is suppressed during an early gameplay/startup window, while the count is capped at `0x800`.

### `FUN_1400709b0` — spawn a projectile ring/fan

Candidate name: `spawn_projectile_spread`.

Observed prototype:

```c
void spawn_projectile_spread(
    int projectile_id,
    int variant_or_owner,
    float x,
    float y,
    uint16_t center_angle,
    float speed_or_accel_hint,
    double speed,
    int radius_or_flags,
    uint32_t count,
    int spread_angle,
    int arg8);
```

Behavior:

- If `count == 1`, delegates to `FUN_14006c2f0` for a single shot.
- If `spread_angle == 0x10000`, emits a full ring of `count` shots at `center_angle + i * (0x10000 / count)`.
- Otherwise, emits a centered fan of `count` shots spanning approximately `spread_angle`, with step `spread_angle / (count - 1)` and first angle `center_angle - spread_angle / 2`.

This helper does not allocate its own type; it is only a convenience wrapper around `spawn_projectile_node`.

### `FUN_140070d00` — append one visual/effect node

Candidate name: `spawn_effect_node`.

Observed prototype:

```c
void spawn_effect_node(
    int effect_type,
    int graph_handle,
    int frame_or_lifetime,
    float x,
    float y,
    uint16_t angle,
    double scale0,
    double scale1,
    double scale2,
    int arg9,
    int color_r,
    int color_g,
    int color_b,
    int alpha,
    int arg14);
```

Field mapping for the allocated `0x60`-byte node:

| Offset | Field | Source | Evidence / notes |
|---:|---|---|---|
| `+0x00` | `active` | constant `1` | Visual list cleanup removes inactive nodes. |
| `+0x04` | `age` | zeroed by allocator / incremented externally | Effect update loop branches on age. |
| `+0x08` | `effect_type` | arg1 | `FUN_140070e40` switch key. |
| `+0x0c` | `graph_handle` | arg2 | Passed to draw helpers as graph/resource handle. |
| `+0x10` | `frame_or_lifetime` | arg3 | Draw/update subtype dependent. |
| `+0x14` | `x` | arg4 | Position. |
| `+0x18` | `scale_or_x2` | arg5 | Mirrored to `+0x20`; often y/secondary x depending decompiler typing. |
| `+0x1c` | `prev_x` | arg4 | Mirrored initial coordinate. |
| `+0x20` | `y_or_aux` | arg5 | Mirrored initial coordinate/aux. |
| `+0x24` | `angle` | arg6 | 16-bit fixed angle. |
| `+0x28` | `scale0` | arg7 | Passed to effect draw/update code. |
| `+0x30` | `scale1` | arg8 | Passed to effect draw/update code. |
| `+0x38` | `scale2` | arg9 | Passed to effect draw/update code. |
| `+0x40` | `arg9` | arg10 | Type-specific lifetime/size/phase. |
| `+0x44` | `color_r` | arg11 | Color channel. |
| `+0x48` | `color_g` | arg12 | Color channel. |
| `+0x4c` | `color_b` | arg13 | Color channel. |
| `+0x50` | `alpha` | arg14 | Alpha / opacity; common `0xff`, `0x80`, `0x60`. |
| `+0x54` | `arg14` | arg15 | Type-specific flag or owner. |
| `+0x58` | `next` | `NULL` | List link. |

## Angle and pattern conventions

- Angles are 16-bit fixed point. `0x10000` is a full circle, `0x8000` half circle, `0x4000` quarter circle.
- Calls to `FUN_1403307c0` and `FUN_140332d90` consume angle converted through `angle * DAT_14053a020 * DAT_140539d28`, consistent with sin/cos conversion.
- Many call sites compute player aim via `FUN_1403300b4(target_y - y, target_x - x) * DAT_14053aba0` and cast to `short`.
- `FUN_1400709b0(..., count, 0x10000, ...)` is a ring.
- `FUN_1400709b0(..., count, spread, ...)` where `spread < 0x10000` is a centered fan/spread.
- `FUN_14006c2f0` repeated in loops with angle increments is equivalent to hand-authored fan/ring logic.

## Dispatcher groups for projectile IDs

The gameplay update loop dispatches projectile IDs as follows:

| Projectile IDs | Update helper | Working behavior |
|---|---|---|
| `0,1,2,3,4,5,6,7,9,10,0x0b,0x0d,0x0f,0x10,0x11,0x12,0x16` | `FUN_14006c620` | Common straight/accelerating/retargeting projectiles. IDs `9`, `10`, `0x0b` retarget after a delay; ID `0x0d` accelerates and emits child `id=4, variant=0x0f`; IDs `0x0f..0x12` are timed self-expiring/effect variants. |
| `8` | `FUN_14006faa0` | Boundary-reflecting projectile. On boundary crossing it computes a reflected angle, clamps/repositions, spawns a replacement projectile, and kills the original. |
| `0x0c,0x0e,0x23..0x27,0x2c,0x2d,0x35,0x36` | `FUN_14006ecf0` | Homing/steering projectile family; moves each frame and adjusts angle toward player, sometimes spawning child projectiles. |
| `0x17..0x1e,0x21,0x22,0x28..0x2b,0x2e..0x34,0x37,0x38,0x39,0x3c` | `FUN_14006ce40` | Complex scripted projectile family; includes sub-emission, deceleration, fan children, and visual effects. |
| `0x1f,0x20` | `FUN_14006fcd0` | Mirrored orbit/arc pair. Computes position through `FUN_140133f30` around an anchor, rotates opposite directions, then after ~40 frames moves the anchor toward the player. |
| `0x3a,0x3b` | `FUN_14006ffc0` | Mirrored expanding spiral/whip pair. Eases in a radius, moves a central point, rotates heading by `±0x1bc` per frame, and draws at an offset from the center. |

## Near-term rename candidates

Keep these local until the resource/frame map and collision code confirm semantics:

| Address | Current | Candidate |
|---|---|---|
| `0x14006c2f0` | `FUN_14006c2f0` | `spawn_projectile_node_candidate` |
| `0x1400709b0` | `FUN_1400709b0` | `spawn_projectile_spread_candidate` |
| `0x140070d00` | `FUN_140070d00` | `spawn_effect_node_candidate` |
| `0x14006c420` | `FUN_14006c420` | `flush_projectile_nodes_to_effects_candidate` |
| `0x140070250` | `FUN_140070250` | `draw_projectile_visual_candidate` |
| `0x14006c620` | `FUN_14006c620` | `update_projectile_common_motion_candidate` |
| `0x14006faa0` | `FUN_14006faa0` | `update_projectile_reflect_on_boundary_candidate` |
| `0x14006ecf0` | `FUN_14006ecf0` | `update_projectile_homing_steering_candidate` |
| `0x14006ce40` | `FUN_14006ce40` | `update_projectile_scripted_emitter_candidate` |
| `0x14006fcd0` | `FUN_14006fcd0` | `update_projectile_orbit_arc_pair_candidate` |
| `0x140070e40` | `FUN_140070e40` | `update_effect_nodes_candidate` |
| `0x140070250` | `FUN_140070250` | `draw_projectile_visual_candidate` |
| `0x14006c620` | `FUN_14006c620` | `update_projectile_common_motion_candidate` |
| `0x14006faa0` | `FUN_14006faa0` | `update_projectile_reflect_on_boundary_candidate` |
| `0x14006ecf0` | `FUN_14006ecf0` | `update_projectile_homing_steering_candidate` |
| `0x14006ce40` | `FUN_14006ce40` | `update_projectile_scripted_emitter_candidate` |
| `0x14006fcd0` | `FUN_14006fcd0` | `update_projectile_orbit_arc_pair_candidate` |
| `0x14006ffc0` | `FUN_14006ffc0` | `update_projectile_expanding_spiral_pair_candidate` |
