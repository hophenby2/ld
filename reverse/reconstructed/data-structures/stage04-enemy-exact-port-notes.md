# Stage 04 Enemy Exact-Port Notes

Status: reviewed against the original `LikeDreamer.exe` and the exported Ghidra
decompilations. Types `0x3d`/`0x3e` and `0x3f` now have dedicated exact-port
notes in `stage04-type3d-exact-notes.md` and `stage04-type3f-exact-notes.md`.

## Critical correction: schedule argument 2 is HP

The second argument of the stage spawn schedule is initial HP, not lifetime.
This supersedes the older `duration_or_lifetime` / `schedule duration` wording in
`stage-spawn-family-notes.md`.

Evidence:

- `stage_entity_spawn_candidate` stores `param_2` in node `+0x1c` and `+0x20` at
  `gameplay-spawn-helpers-renamed/neighborhood-decompiled/140078a00_stage_entity_spawn_candidate.c:28-33`.
- `FUN_140079c10` computes the displayed gauge as signed current HP at `+0x1c`
  divided by max HP at `+0x20` at
  `remaining-helper-priority/neighborhood-decompiled/140079c10_FUN_140079c10.c:20-25`.
- The original hit routine loads the player-side object's damage from object
  `+0x28`, then executes `sub dword ptr [rdi+0x1c], ebx` at original VA
  `0x1400cd0f6`. Here `rdi` is the stage entity and `ebx` is the hit object's
  damage. The call is gated by entity `+0x54 == 0` in
  `stage-entity-list-refs/global-key-ref-decompiled/140078b70_FUN_140078b70.c:650-655`.
- Difficulty index `0` scales both HP fields by `DAT_140539f28 == 0.8`, except
  type `0x153`; difficulty indices `1..4` keep the scheduled value unchanged.
  See `140078a00_stage_entity_spawn_candidate.c:21,28-34`.
- List cleanup only unlinks nodes whose `+0x00` active field was cleared. It
  does not compare the helper timer with the scheduled HP value. See
  `main-gameplay/neighborhood-decompiled/1400bca30_state_14_replay_demo_gameplay_update_candidate.c:932-959`.

Consequences for the reconstruction:

- Rename `StageSpawnEvent::lifetime` to `hitPoints` or `initialHp` throughout the
  schedule API.
- Initialize `enemy.hp` and `enemy.maxHp` from the schedule value, applying the
  `0.8` multiplier only on difficulty `0` and excluding type `0x153`.
- Remove any global `enemy.age > scheduledValue` deletion rule. Bounds, owner
  loss, explicit helper timers, and helper-owned death logic decide removal.
- Keep a helper-local timer separate from total targetable time. Do not reuse HP
  as a timer or use one `age` value for both original counters.

## Original `0x68`-byte stage entity layout

| Offset | Width | Meaning | Initialization / use |
|---:|---:|---|---|
| `+0x00` | 4 | exists / active | Initialized to `1`; cleanup frees only when it becomes `0`. |
| `+0x04` | 4 | unique entity id | Incrementing global id. |
| `+0x08` | 4 | owner / parent id | Spawn argument 10; child helpers find the owner by this id. |
| `+0x0c` | 4 | helper state timer | Incremented after every helper call. Helpers reset it at state transitions. |
| `+0x10` | 4 | targetable-active timer | Incremented only while `+0x54 == 0`. |
| `+0x14` | 4 | helper state | Initialized to `0`. |
| `+0x18` | 4 | entity type | Dispatch discriminator. |
| `+0x1c` | 4 | current HP | Spawn arg 2, then reduced by player-side object damage. |
| `+0x20` | 4 | max HP | Spawn arg 2 after difficulty scaling. |
| `+0x24` | 4 | reward / death-weight parameter | Constructor-specific spawn-dispatch value. |
| `+0x28` | 4 | current x | `float`. |
| `+0x2c` | 4 | current y | `float`. |
| `+0x30` | 4 | source / origin x | Initial x retained separately from current position. |
| `+0x34` | 4 | source / origin y | Initial y retained separately from current position. |
| `+0x38` | 4 | secondary saved x | Initialized from spawn x. |
| `+0x3c` | 4 | secondary saved y | Initialized from spawn y. |
| `+0x40` | 2 | current fixed angle | 16-bit turn space. |
| `+0x42` | 2 | secondary / stored angle | Used by multipart visuals, burst aim, and children. |
| `+0x44` | 2 | target / auxiliary angle | Initialized from the spawn angle. |
| `+0x48` | 8 | speed | `double`. |
| `+0x50` | 4 | collision / threat radius | Integer radius. |
| `+0x54` | 4 | targetability state | `1` during marker/invulnerable states; `0` when hittable. |
| `+0x60` | 8 | next node | Singly linked stage-entity list. |

Constructor evidence is in
`gameplay-spawn-helpers-renamed/neighborhood-decompiled/140078a00_stage_entity_spawn_candidate.c:15-60`.
The dispatcher calls the type helper first, then collision/damage, then increments
`+0x0c` and conditionally `+0x10`; see
`stage-entity-list-refs/global-key-ref-decompiled/140078b70_FUN_140078b70.c:650-655`.
That ordering means a hit which makes HP non-positive is normally processed by
the entity helper on the following update, not deleted directly by the collision
loop.

## Player-side hit damage

The current reconstruction's fixed damage `1` / `2` is two orders of magnitude
too small for original schedule HP such as `500`, `5000`, or `10000`.

`FUN_140109660` is the constructor for the original player-side object list:

- parameter 6 is stored at object `+0x28` at
  `gameplay-helpers-renamed/neighborhood-decompiled/140109660_FUN_140109660.c:20-28`;
- when `DAT_140e9fd20 == 1`, the constructor multiplies it by `100` at lines
  `33-35` (likely a special/debug mode; it is not the normal damage path);
- `FUN_1400cc2f0` later reads this exact field and subtracts it from entity HP at
  VA `0x1400cd09e..0x1400cd0f9`.

Normal-shot creation is explicit in
`gameplay-helpers-renamed/neighborhood-decompiled/14010db70_FUN_14010db70.c`:

| Player object | Damage (`+0x28`) | Evidence |
|---|---:|---|
| type `0`, two main shots | `0x82` = `130` each | lines `41-44` |
| type `1`, two enhanced main shots | `0x96` = `150` each | lines `48-52` |
| option shot families | `25, 30, 35, 45, 50, 54, 60, 63, 70` depending on loadout/state | initialization and branches at lines `36,73-199` |

The option values correspond to literals `0x19`, `0x1e`, `0x23`, `0x2d`,
`0x32`, `0x36`, `0x3c`, `0x3f`, and `0x46`. They are parameter 6 in the call at
line `199`; parameter 7 is collision radius/scale, not damage.

Porting rule: store damage on each `PlayerSideObject` when it is created and
subtract that value on collision. Avoid a later `type <= 1 ? 2 : 1` lookup.
The separate reconstruction `playerShots_` path must not inflict another fixed
`2` damage for the same normal volley; either merge it into this object model or
make it purely visual.

## Stage 04 update dispatch

The raw entity type first indexes `DAT_1400799a8`, so Ghidra's recovered switch
case is not the raw type. The generated map gives these exact associations:

| Entity type | Update case | Helper |
|---:|---:|---|
| `0x35` | `0x27` | `FUN_140090c30` |
| `0x36` | `0x28` | `FUN_140091540` |
| `0x37` | `0x29` | `FUN_140092230` |
| `0x38` | `0x2a` | `FUN_140092b20` |
| `0x39..0x3c` | `0x2b` | `FUN_140093540` |
| `0x3d` | `0x2c` | `FUN_1400941d0` |
| `0x3e` | `0x2d` | `FUN_140094bc0` |
| `0x3f` | `0x2e` | `FUN_140095130` |

Map evidence: `stage-entity-update-dispatch-map.csv:55-65`; dispatch helper calls
are visible at
`remaining-helper-priority/neighborhood-decompiled/140078b70_stage_entity_update_dispatch_candidate.c:141-164`.

## Type `0x35`: `FUN_140090c30`

Constructor defaults from `stage-spawn-dispatch-map.csv:55`: reward/weight `5`,
radius `30`, targetability flag `1`.

State and motion:

- State 0 is a 20-frame marker. Its scale is `2.0 - timer * 0.1`.
- At timer `20`, speed becomes `12.0`; a left entry (`originX <= 0`) gets angle
  `0`, and a right entry (`originX >= 720`) gets angle `0x8000`. The helper
  changes to state 1, resets its timer, and sets targetability to `0`.
- In state 1, add `60` to the angle each frame, except timers `45..64`, where the
  delta is `1300`.
- Negate the turn delta for a left entry whose origin y is at least `300`, or a
  right entry whose origin y is below `300`.
- Move by `x += cos16(angle) * 12`, `y += sin16(angle) * 12`. There is no
  homing or deceleration.

Evidence: `140090c30_FUN_140090c30.c:41-92`.

Firing:

- Fire only while the state-1 helper timer is below `200` and the old position
  is inside the firing window.
- Emission uses the global stage frame modulo the interval, not the entity timer.
- For stage index `<= 7`, intervals by difficulty are `[42,16,10,10,8]` and
  speeds are `[5.0,6.0,7.0,7.0,9.0]`.
- For stage index `> 7`, intervals are `[24,12,8,8,8]` and speeds are
  `[5.5,6.6,7.5,7.5,9.0]`.
- Emit projectile id `6`, selector `globalFrame % interval` (therefore `0` on
  the emission frame), from the pre-movement `(x, y + 20)`, aimed at the player.
- Difficulty `> 2` emits a second id `6` at the same angle and speed `base+2.2`.

Evidence: `140090c30_FUN_140090c30.c:93-189`. Constant values were decoded from
the original PE `.rdata` (`DAT_140539fd8 == 2.2`).

Visuals and removal:

- Draw `Enemy_s` frame `32` (`DAT_140e446e0`) as the body.
- Draw three `Enemy_s` frame `33` parts (`DAT_140e446e4`) at `(x,y-35)` with
  angles `timer*2000`, `timer*2000+0x5555`, and `timer*2000-0x5556`.
- On `currentHp < 1`, call `FUN_14007b010(entity,200,2)`, call
  `FUN_140079e20(entity,0)`, and clear `+0x00`.
- Also clear `+0x00` outside x `[left-180,left+780]` or y `[-180,900]`.

Evidence: `140090c30_FUN_140090c30.c:191-295`. Frame indices follow
`Enemy_s` base `DAT_140e44660`, four bytes per handle.

## Type `0x36`: `FUN_140091540`

Constructor defaults from `stage-spawn-dispatch-map.csv:56`: reward/weight `5`,
radius `40`, targetability flag `1`.

State and motion:

- State 0 is a 20-frame marker.
- At timer `20`, speed becomes `15.0`. A left entry uses the exact 16-bit MT
  expression equivalent to `-(rng % 5001)-9000`; a right entry uses the exact
  expression equivalent to `(rng % 5001)-23768`.
- Clamp the transitioned position to the playfield using the helper's `-20`
  margin, enter state 1, and reset the helper timer.
- Timers `<80`: turn toward the player with maximum step
  `sin(timer * 204.8 * pi/32768) * 700`; reduce speed by `0.18` while above `1`.
- Timers `80..200`: turn toward the player by at most `0x80` per frame. At timer
  `80`, set targetability to `0`.
- Timers `>=201`: approach angle `0xc000` by `200` per frame and add `0.1` to
  speed each frame.
- Movement is fixed-angle cosine/sine multiplied by current speed.

Evidence: `140091540_FUN_140091540.c:61-209`.

Firing:

- Fire only at timers `80..199` and while the firing point is in bounds.
- Intervals are `[60,40,30,24,16]`; speeds are `[4.0,5.2,6.5,7.5,9.0]`.
- Quantize player aim to `0x800` angle steps.
- Every volley emits id `4` at center angles `-200` and `+200`, speed `base`,
  plus id `4` at center, speed `base+0.3`.
- Difficulty `>2` also emits id `4` at center angles `-750` and `+750`, speed
  `base-0.5`.

Evidence: `140091540_FUN_140091540.c:210-290`.

Visuals and removal:

- Body starts at `Enemy_s` frame `34`, transitions through frames `35/36` at
  timers `70..79`, and uses frame `37` after timer `79`.
- Multipart overlays use frames `38` (`DAT_140e446f8`) and `39`
  (`DAT_140e446fc`).
- On `currentHp < 1`, call `FUN_14007b010(entity,300,3)`, call
  `FUN_140079e20(entity,0)`, then clear `+0x00`.
- Bounds are the same broad `[-180,780]` relative-x and `[-180,900]` y window as
  type `0x35`.

Evidence: `140091540_FUN_140091540.c:293-346`.

## Type `0x37`: `FUN_140092230`

Constructor defaults from `stage-spawn-dispatch-map.csv:57`: reward/weight `5`,
radius `40`, targetability flag `1`.

State and motion:

- At state-0 timer `0`, derive the heading with the exact signed-16-bit
  expression `(short)rng + (short)(rng/4001)*-4001 - 0x47d0`.
- State 0 lasts 120 frames and already moves. Its marker scale is `timer/120`;
  state 1 uses scale `1.0`.
- Let `base = 8 * (state0 ? timer/120 : 1)`. Each frame uses
  `speed = base - sin((timer % 30)*pi/60) * base`.
- The secondary visual angle alternates `angle+0xd05` and `angle-0xd05` every
  30 frames.
- At timer `120`, enter state 1, reset the helper timer, and set targetability
  to `0`.

Evidence: `140092230_FUN_140092230.c:43-93,212-216`.

Firing:

- Fire only in state 1 and only when player distance is greater than `50`.
- Burst intervals are `[100,60,50,40,32]`; burst substeps are `[10,7,5,4,4]`;
  jitter ranges are `[600,800,1000,1200,1400]`; projectile speeds are
  `[4.2,5.2,6.0,6.0,7.5]`.
- A burst starts when `(timer-10) % interval == 0` and stores current player aim.
  During burst phase `0..23`, every `substep` frames emit id `0`, selector `0`,
  at stored aim plus deterministic jitter.
- Difficulty `>2` adds a same-angle id `0` at `speed+1.2`.
- After each emitted substep, stored aim approaches exact player aim by at most
  `0x80`.

Evidence: `140092230_FUN_140092230.c:96-203`.

Visuals and removal:

- Draw `Enemy_s` frames `40` (`DAT_140e44700`) and `41`
  (`DAT_140e44704`).
- On `currentHp < 1`, call `FUN_14007b010(entity,300,3)`, call
  `FUN_140079e20(entity,0)`, then clear `+0x00`.
- Clear outside x `[left-64,left+664]` or y `[-64,784]`.

Evidence: `140092230_FUN_140092230.c:218-245`.

## Types `0x39/0x3a` and children `0x3b/0x3c`: `FUN_140093540`

Types `0x39`, `0x3a`, `0x3b`, and `0x3c` all dispatch to this helper. Scheduled
parents `0x39/0x3a` have constructor defaults reward/weight `50`, radius `60`,
and targetability flag `1` (`stage-spawn-dispatch-map.csv:59-62`).

Parent transition and children:

- At marker timer `20`, speed becomes `2.0`.
- Type `0x39` gets angle `0x4000`.
- Type `0x3a` gets angle `0xe4a8` when its origin is in the left half and
  `0x9b58` in the right half.
- Copy current angle to secondary angle, enter state 1, reset the timer, and set
  targetability to `0`.
- At parent timers `40,80,...,320`, spawn eight type `0x3b` children.
- At parent timer `360`, spawn one type `0x3c` child.
- Each child gets HP equal to the parent's max HP, position equal to the parent's
  source/origin `(x,y)`, the parent's secondary angle, speed `2.0`, radius `40`,
  targetability flag `0`, and owner id equal to the parent's entity id.

Transition evidence: `140093540_FUN_140093540.c:67-123`. Spawn evidence:
`140093540_FUN_140093540.c:251-268`.

HP ownership and death:

- On construction, a child copies owner max HP to its max field and owner current
  HP to its current field.
- If child HP drops below owner HP, propagate the difference back to owner HP.
  If owner HP is lower, clamp child HP down to owner HP. A child reaching zero
  therefore kills the shared parent pool.
- Parent `currentHp < 1` sets targetability to `1`, calls
  `FUN_14007b010(entity,1000,10)` and `FUN_140079e20(entity,1)`, and advances its
  helper state. Unlike simple types, it is not immediately unlinked by this
  branch; the helper clears it at timer `1000`.
- Children enter their death state when owner HP is non-positive, run their own
  effect at death-state timer `100`, and clear `+0x00`.
- Any child also clears immediately when its owner node no longer exists.
- Parent and children clear at helper timer `1000` even when still alive.

Evidence: `140093540_FUN_140093540.c:53-66,270-309,337-360`.

Visuals:

- Parent body: `Enemy_m` frame `68` (`DAT_140e44be0`).
- Parent side parts: `Enemy_m` frame `69` (`DAT_140e44be4`).
- Type `0x3b`: `Enemy_m` frame `70` (`DAT_140e44be8`).
- Type `0x3c`: `Enemy_m` frame `71` (`DAT_140e44bec`).

Evidence: `140093540_FUN_140093540.c:310-357`. Frame indices follow `Enemy_m`
base `DAT_140e44ad0`, four bytes per handle.

Implementation status: ported into `stage_runtime.cpp`. The runtime now uses the
original `0x200` entity cap and processes children appended during an entity
walk later in the same frame. Parent timers `40..320` create the eight `0x3b`
nodes and timer `360` creates `0x3c`; all children inherit the owner id, source
position, secondary angle, and shared HP pool. Damage propagation, the child
death-timer rewrite, parent/child delayed cleanup, difficulty firing tables,
and `Enemy_m` frames `68..71` are implemented. Marker rendering now uses
`Effect_m` frame `4` (`DAT_140e41a50`) instead of a scaled enemy-body stand-in.

The scalar values used by this port were exported read-only from the original
PE to `reverse/ghidra-or-ida/exports/stage04-carrier-scalars.tsv`. The remaining
known approximation in this family is the spatial distribution of reward items:
the payout decomposition and timing follow `FUN_14007b010`, while its exact RNG
coordinate helper and transient death-effect nodes are not yet represented.

## Recommended integration order

1. Preserve the HP correction and delete every remaining generic scheduled-age
   expiry path.
2. Add `damage` to `PlayerSideObject`; use `130/150` for the main pair and the
   recovered per-option values. Remove or neutralize the duplicate fixed-damage
   `playerShots_` collision route.
3. Split helper timer, targetable timer, helper state, current/max HP,
   targetability, origin position, and secondary angle in `StageEnemy`.
4. Move death ownership out of the generic collision loop. Collision subtracts
   damage; the next helper update performs helper-specific rewards, effects,
   parent propagation, and removal.
5. Port `0x35`, `0x36`, and `0x37` exactly, including global-frame versus
   entity-timer firing distinctions and the original sprite frames.
6. ~~Add generic owner-id lookup and child creation, then port the shared
   `0x39..0x3c` HP pool and delayed cleanup.~~ Ported; retain the exact effect
   node/RNG follow-up described above.
7. Audit and port the remaining Stage 04 helpers `0x3d`, `0x3e`, and `0x3f`
   before claiming Stage 04 parity. Type `0x38` is now ported from
   `stage04-type38-exact-notes.md`.
