# Projectile Update Helper Semantics

Status: first-pass semantic pass over the six projectile update helpers using the `ProjectileNode` layout. Names remain conservative until collision/lifetime and more runtime traces confirm behavior.

## Shared node field interpretation used here

Raw decompiler form is `undefined4 *param_1`; important field aliases:

| Decompiled access | `ProjectileNode` field | Meaning in update helpers |
|---|---|---|
| `param_1[0]` | `active` | Set to `0` when the projectile expires or transforms into a child projectile. |
| `param_1[1]` | `age` | Frame age; dispatcher increments it once per frame. |
| `param_1[2]` | `variant_or_owner` | Mostly the visible bullet selector passed to `FUN_140070250`; sometimes also subpattern/owner in child-script helpers. |
| `param_1[3]` | `projectile_id` | Movement/update behavior switch. |
| `param_1[4]`, `param_1[5]` | `x`, `y` | Current position. |
| `param_1[6]`, `param_1[7]` | `prev_x`, `prev_y` | Previous/origin/anchor scratch, helper-dependent. |
| `param_1[8]` | `speed_or_accel_hint` | Float acceleration/additive speed term; several helpers add it to `speed` for movement distance. |
| `*(short *)(param_1 + 9)` | `angle` | Current 16-bit fixed angle. |
| `*(short *)((char*)param_1 + 0x26)` | `prev_angle` | Secondary/target angle in specialized helpers. |
| `*(double *)(param_1 + 10)` | `speed` | Current speed. |
| `*(double *)(param_1 + 0xc)` | `base_speed` | Baseline speed or acceleration divisor. |
| `param_1[0xe]` | `radius_or_flags` | Boundary margin / radius / draw flag, depending helper. |

All helpers eventually draw through:

```c
FUN_140070250(node->variant_or_owner, frame_or_layer, node->age,
              draw_x, draw_y, node->angle, trail_or_effect_flag);
```

`FUN_140070250` is the bullet visual selector bridge; see `bullet-frame-visual-map.md`.

## `FUN_140070250` — draw projectile visual candidate

Candidate name: `draw_projectile_visual_candidate`.

Observed prototype:

```c
void draw_projectile_visual_candidate(
    int visual_selector,
    int frame_or_layer,
    int age,
    float x,
    float y,
    FixedAngle16 angle,
    int spawn_trail_effect_flag);
```

Evidence:

- Selects `Bullet.png` handles `DAT_140e451c0..DAT_140e45228` by `visual_selector`.
- Draws via `FUN_1400c8410(graph, frame_or_layer, 7, x, y, angle, scale_x, scale_y, 0xff, 0xff, 0xff, 0xff, 1, 0)`.
- Selectors `0x11..0x14` add overlays/effect nodes before drawing the base bead frame.
- If final flag is `1`, it spawns an effect node type `5` with low alpha, likely a short trail/afterimage.

## `FUN_14006c620` — common straight / acceleration / delayed-retarget family

Candidate name: `update_projectile_common_motion_candidate`.

Dispatcher IDs: `0,1,2,3,4,5,6,7,9,10,0x0b,0x0d,0x0f,0x10,0x11,0x12,0x16`.

Behavior summary:

- Computes prospective position using `(speed + speed_or_accel_hint)` along `angle`.
- `projectile_id` then mutates `speed`, `angle`, or active state before drawing.
- Draw call uses `variant_or_owner` as visual selector and `age` as animation frame input.
- Out-of-bounds cleanup uses a common playfield margin and sets `active = 0`.

High-signal per-ID notes:

| ID | Behavior notes |
|---:|---|
| `0x00` | Basic straight shot: no special switch case beyond shared motion/draw. |
| `0x01` | Difficulty-dependent acceleration: `speed += small_delta`, with larger deltas at higher difficulty/rank. |
| `0x02` | Starts with a small speed on age 0, then accelerates from `base_speed / 90-ish` for about 30 frames. |
| `0x03` | Starts at speed `0.1`, then after ~30 frames accelerates toward `base_speed`. Draw layer/frame argument changes to `0x4f`. |
| `0x04` | Like ID `0x03` but delay window is shorter (~12 frames). |
| `0x05` | Starts at a fraction of `base_speed`, then accelerates after ~60 frames. |
| `0x06` | Decelerating shot: stores a derived decel amount in `base_speed`; subtracts from `speed` for ~30 frames. |
| `0x07` | Decelerates for ~40 frames, then accelerates again until about frame 99. |
| `0x09` | Delayed retarget: decelerates for ~30 frames, snaps current position, aims at the player, resets speed hint, then accelerates. |
| `0x0a` | Retarget after ~40 frames using original/anchor fields, then accelerates for about 60 frames. |
| `0x0b` | Decelerates for ~50 frames, then aims near the player with a vertical offset and accelerates from zero. |
| `0x0d` | Accelerates after ~24 frames and, while onscreen, emits a stationary/special child `projectile_id=4`, `variant=0x0f`. |
| `0x0f`, `0x10`, `0x11` | Timed self-expiring variants at ages 20, 40, and 10 respectively. |
| `0x12` | At age 60 spawns a type `0x0c` white effect node at the projectile position and expires. |
| `0x16` | No explicit case observed in this helper excerpt; currently behaves like shared straight motion unless another path mutates it. |

## `FUN_14006faa0` — boundary-reflecting projectile

Candidate name: `update_projectile_reflect_on_boundary_candidate`.

Dispatcher ID: `0x08`.

Behavior summary:

- Moves like a common projectile using `speed + speed_or_accel_hint`.
- Checks a wider boundary rectangle based on `radius_or_flags`.
- On boundary crossing, computes a reflected angle:
  - left/right reflections use `-0x8000 - angle` style transformation;
  - top/bottom reflections use `-angle` style transformation.
- Clamps/repositions via `FUN_1401346a0(position, 0)`.
- Spawns a replacement projectile with same `projectile_id`, reflected angle, same `speed`, same boundary/radius flag, and then kills the original.
- Draws through `FUN_140070250(variant_or_owner, 0x50, age, x, y, angle, ...)`.

This is stronger than merely “bounce-like”: the original node is not reused after reflection; it is transformed by spawning a replacement and setting `active = 0`.

## `FUN_14006ecf0` — homing / steering / child-emitting family

Candidate name: `update_projectile_homing_steering_candidate`.

Dispatcher IDs: `0x0c,0x0e,0x23..0x27,0x2c,0x2d,0x35,0x36`.

Behavior summary:

- Moves first using current `angle` and `speed`.
- Computes player aim angle every frame.
- Many IDs clamp heading change per frame toward the player, using difficulty-scaled turn-rate constants.
- Several IDs emit child projectiles (`id 4`, `5`, `8`, `0xd`) while continuing to steer.
- Cleanup uses a larger boundary than `FUN_14006c620`, fitting homing/special bullets that may roam farther outside the playfield.

High-signal per-ID notes:

| ID | Behavior notes |
|---:|---|
| `0x0c` | Strong homing/steering missile. First 60 frames decelerate from high speed while slowly turning; at frame 60 plays sound and then accelerates while turning more strongly. Emits child `projectile_id=4`, `variant=0x0f` while onscreen. |
| `0x0e` | Oscillating speed homing variant. For ~240 frames blends speed using sine and clamps turn rate toward the player; after that accelerates and continues turn-clamped homing. Emits child `projectile_id=5`, `variant=0x0f`; can spawn grey/white visual effects when leaving a tighter region. |
| `0x23`, `0x24` | Periodic paired spread emitters. Difficulty controls interval and speed; `0x24` offsets/clamps initial position. Emits two-shot spreads of `projectile_id=8`, `variant=3`, plus faster duplicates on high difficulty. Also emits child `id=5, variant=0x0f`. |
| `0x25` | Continues forward, emits `projectile_id=4`, `variant=0x0f`; on high difficulty it slowly turns toward the player. |
| `0x26`, `0x27` | Curving pair with opposite angular drift. `0x26` emits child `id=5`; `0x27` emits child `id=4`; both accelerate and rotate by difficulty-scaled angle increments. |
| `0x2c`, `0x2d` | Curving accelerating pair; mostly angle drift plus speed acceleration, without the child emission seen in `0x26/0x27`. |
| `0x35`, `0x36` | Short-lived steering/curving specials for ~90 frames, rotating in opposite directions while accelerating. |

## `FUN_14006ce40` — scripted projectile emitter family

Candidate name: `update_projectile_scripted_emitter_candidate`.

Dispatcher IDs: `0x17..0x1e,0x21,0x22,0x28..0x2b,0x2e..0x34,0x37..0x39,0x3c`.

Behavior summary:

- Shared first step is common forward motion using `speed + speed_or_accel_hint`.
- Then ID-specific scripts emit children, spawn visual effects, or self-expire.
- Draw call normally uses `frame_or_layer=0x50`, but many “scripted emitter” IDs use `0x51`; some timed self-expiring variants use `0x4f`/effect bursts.
- The helper is best understood as projectile-as-emitter, not just projectile-as-bullet.

High-signal groups:

| ID(s) | Behavior notes |
|---|---|
| `0x17` | At age 25 emits one aimed child `projectile_id=3`, `variant=1`. |
| `0x18`, `0x19` | Alternating timed volleys. Difficulty controls burst count/window. `0x18` emits child `id=0x0c`; `0x19` emits child `id=0x0d`; final age spawns a white effect node and kills the parent. |
| `0x1a`, `0x1b` | Periodic fan-like emitters. `0x1a` emits reflected/bounce `id=8`; `0x1b` emits delayed-retarget `id=9`; high difficulty adds a second faster child. |
| `0x1c` | Periodic two-way emitter of `id=9`, two opposite directions around parent heading. |
| `0x1d`, `0x1e` | Offset/orbiting two-phase emitters that periodically fire `id=0x0d` at `angle ± 0x4000`; play shot sound. |
| `0x21`, `0x22` | At age 36 emit `projectile_id=2`, `variant=4` with opposite angle offsets. |
| `0x28` | Synchronizes with a parent `StageEntity` by `owner_or_parent_id`-like field and emits two `id=8`, `variant=4` shots at specific parent phase windows. |
| `0x29`, `0x2a` | Mirrored timed emitters: `0x29` emits `id=8`, `variant=4`; `0x2a` emits `id=9`, `variant=4`. |
| `0x2b` | Aims at a stored anchor/player-like coordinate and emits `id=0x0c`, `variant=4` spread using `spawn_projectile_spread`. |
| `0x2e` | On leaving a tighter rectangle, reflects angle and spawns a fan/ring-ish spread of `id=0x0d` before killing itself. |
| `0x2f`, `0x30` | Timed volley pair: `0x2f` emits `id=0x0c`; `0x30` emits `id=0x0d`; then self-expire with a white effect at age 36. |
| `0x31` | Boundary-triggered transform; decompilation truncates a call as `FUN_14006c2f0(10)`, so arguments need a cleaner export/trace before naming. |
| `0x32` | Every 9 frames emits two `id=8` children if visual selector is 2, or two `id=9` children if selector is 3. |
| `0x33` | Boundary-triggered respawn of same visual selector with `projectile_id=1`, then expires. |
| `0x34` | At age 20 emits aimed child `projectile_id=5`, `variant=1`. |
| `0x37`, `0x38` | Decelerate for ~50 frames, then parent-phase synchronized three-way `id=8` bursts in mirrored rotation directions, followed by a white effect/self-expire. |
| `0x39` | Decelerates for ~30 frames, then emits two `projectile_id=2`, `variant=2` children and expires. |
| `0x3c` | Randomized sparkle/emitter projectile: every frame spawns a `projectile_id=4`, `variant=0x11` child at a small random offset and effect type `4` with randomized color/scale; accelerates slightly. |

## `FUN_14006fcd0` — orbit/arc special pair

Candidate name: `update_projectile_orbit_arc_pair_candidate`.

Dispatcher IDs: `0x1f`, `0x20`.

Behavior summary:

- Does not use ordinary straight integration for final position. Instead it computes `(x,y)` via `FUN_140133f30(projectile_id, anchor_y, 0, angle, radius_x, radius_y)` and stores the returned position into `x/y`.
- Age 0-39 use sinusoidal radius growth; after that radius defaults to larger fixed values.
- At age 40 it aims `prev_angle`/secondary heading toward the player from the anchor fields (`prev_x/prev_y`), then after age 40 moves the anchor along that heading with gradually increasing speed.
- `0x1f` rotates angle positively; `0x20` rotates negatively. Turn rate is difficulty-scaled (`0x46`..`0xdc`).
- Draws the orbiting bullet at computed position with visual selector `variant_or_owner`.
- Expires when the computed position leaves an expanded rectangle.

This looks like a pair of mirrored spiral/orbit bullets whose center/anchor later starts chasing or drifting toward the player.

## `FUN_14006ffc0` — expanding spiral/whip special pair

Candidate name: `update_projectile_expanding_spiral_pair_candidate`.

Dispatcher IDs: `0x3a`, `0x3b`.

Behavior summary:

- At age 0, copies `speed_or_accel_hint` into `prev_x` and uses it as an orbit radius/amplitude.
- Sets `prev_angle` to `0xc000` or `0x4000` depending whether the projectile starts above/below the player-like y global; this is a secondary direction marker.
- For the first 10 frames, eases radius/amplitude in with a sine ramp; after that radius remains at the stored value.
- Sets `speed = age * small_delta - base_offset`, so the central point starts moving backward/negative then changes over time.
- Moves the central point by current `angle`, then rotates the heading by `+0x1bc` for ID `0x3a` or `-0x1bc` for ID `0x3b` each frame.
- Draw position is offset from the central point by `(cos(angle), sin(angle)) * radius`, producing an expanding curved/spiral trail-like motion.
- Expires using a radius-expanded boundary.

## Next verification targets

1. Cleanly type `FUN_140070250` and all six update helpers in a local pseudo-C copy using `ProjectileNode` fields.
2. Collect spawn-call evidence that maps `(projectile_id, variant_or_owner)` pairs to the visual selectors in `bullet-frame-visual-map.md`.
3. Deepen collision/lifetime semantics by locating the projectile collision walker that reads `radius_or_flags` and `draw/collision_enabled` fields.
