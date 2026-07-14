# Stage 03 types 0x25, 0x26, 0x27, and 0x29 exact audit

Status: read-only audit against the original `LikeDreamer.exe`. This document
does not claim that the reconstruction has ported these helpers yet.

## Dispatch proof

Do not infer the helper from adjacency or from projectile ids. The original
entity dispatcher reads `DAT_1400799a8[entity.type]`, then dispatches that byte
through its update switch.

| spawn type | update case | helper | original call |
|---:|---:|---|---:|
| `0x25` | `0x19` | `FUN_1400894a0` | `0x140078cd8` |
| `0x26` | `0x1a` | `FUN_140089e00` | `0x140078ce5` |
| `0x27` | `0x1b` | `FUN_14008a970` | `0x140078cf2` |
| `0x29` | `0x1d` | `FUN_14008b480` | `0x140078cff` |

The mapping is also visible in
`stage-spawn-used-update-map.md` and in
`stage-update-helper-priority/neighborhood-decompiled/140078b70_stage_entity_update_dispatch_candidate.c:100-112`.

## Constructor fields

`stage_spawn_dispatch_candidate @ 0x14007b710` uses the byte table at
`0x14007c098`. Its relevant entries and targets are:

| type | constructor case byte | constructor block |
|---:|---:|---:|
| `0x25` | `0x10` | `0x14007b941` |
| `0x26` | `0x11` | `0x14007b971` |
| `0x27` | `0x12` | `0x14007bf24` |
| `0x29` | `0x12` | `0x14007bf24` |

The blocks converge on the call to `stage_entity_spawn_candidate` at
`0x14007bfbf`. `+0x54` must be interpreted carefully: collision only accepts an
entity when this field is zero. Therefore constructor value `1` means
entry/invulnerability gate enabled, not targetable. Each of the four helpers
sets it to zero at the state-0 to state-1 transition.

| type | HP / max HP | `+0x24` entity/reward kind | initial position | angle | speed | radius `+0x50` | hit gate `+0x54` | owner `+0x08` |
|---:|---|---:|---|---:|---:|---:|---:|---:|
| `0x25` | schedule arg 2 | `8` | schedule x, forced y `-20` | `0x4000` | `1.0` | `40` | `1` (blocked) | `0` |
| `0x26` | schedule arg 2 | `20` | schedule x, forced y `-100` | `0x4000` | `1.0` | `90` | `1` (blocked) | `0` |
| `0x27` | schedule arg 2 | `24` | schedule x/y | `0x4000` | `1.0` | `70` | `1` (blocked) | `0` |
| `0x29` | schedule arg 2 | `24` | schedule x/y | `0x4000` | `1.0` | `70` | `1` (blocked) | `0` |

Difficulty zero applies the shared constructor HP multiplier `0.8`; other
difficulties keep schedule HP. The schedule values are not lifetimes.

## Type 0x25: `FUN_1400894a0 @ 0x1400894a0..0x140089dfb`

### Entry and movement

- State 0 lasts through helper timer `20`. It draws `Effect_m[4]`
  (`DAT_140e41a50`) with layer/field `50`, mode `8`, angle zero, white/opaque,
  and uniform scale `2.0 - age * 0.1`. Its x is the sinusoidal x described
  below; y is returned by `FUN_1401346a0(current,-20)`.
- At timer `20`, it enters state 1, resets the helper timer to zero, writes
  speed `2.0`, angle `0x4000`, clears `+0x54` to make the entity hittable, and
  replaces current x/y with `FUN_1401346a0(current, -20)`.
- For state timer `< 180`, hidden/source x/y (`+0x30/+0x34`) move at the current
  angle and speed. The angle tracks the player with a maximum step of `0x40`.
  Display y follows hidden y; display x is hidden x plus
  `100 * sin((globalFrame - entityId * 55) * 2*pi/320)`.
- At timer `>= 180`, current x/y move directly, angle turns toward `0xc000`
  with step `0xa0`, and speed increases by `0.1` per frame.

### Projectiles

Shots are emitted only while the entity is within the original visible firing
rectangle and state timer is below `180`.

| difficulty | burst start | cycle | speed |
|---:|---:|---:|---:|
| `0` | `24` | `120` | `6.0` |
| `1` | `18` | `80` | `7.0` |
| `2` | `15` | `70` | `8.0` |
| `3` | `15` | `60` | `8.8` |
| `4` | `15` | `50` | `10.8` |

At cycle local times `0,5,10,15,20,25`, emit visual selector `7`, behavior
`0`, initial travel `10`, collision radius `1`, aux `0` from `(x+16,y+40)` and
`(x-16,y+40)`. Local time zero captures the player aim into `+0x42`; the rest
of that burst reuses it. On difficulties `3/4`, add one shot at aim `-400`
from the positive-x source and one at aim `+400` from the negative-x source,
both at `speed - 0.2`. Original projectile calls are at
`0x1400899d8`, `0x140089a1a`, `0x140089a79`, and `0x140089abb`.

### Draw and removal

- Main body: `Enemy_s[24]` (`DAT_140e446c0`), layer/field `0x23`, mode `7`, at
  `(x,y)`, angle zero, scale `(1,1)`.
- Two `Effect_s[0]` nodes are drawn at `(x+12,y-32)` and `(x-12,y-32)`, scale
  `0.4`, alpha `192`. They are white for `age % 4 < 2`, otherwise
  `(255,128,0)`.
- Every fourth frame it appends a trail/effect node using `Enemy_s[24]`:
  effect type `5`, field `+0x10 = 0x22`, angle zero, scales `1/1`, lifetime-like
  field `0x18`, RGB `255`, alpha `64`.
- It calls the shared enemy gauge renderer as `FUN_140079c10(entity,2)` after
  the body/effect draw (`0x140089d1f`).
- HP `<= 0`: `FUN_14007b010(entity,300,4)`, then
  `FUN_140079e20(entity,0)`, then clear active. Calls are at
  `0x140089d87/0x140089d91`.
- Bounds are x below the field origin minus `180`, x above it plus `780`,
  y below `-180`, or y above `900`.

## Type 0x26: `FUN_140089e00 @ 0x140089e00..0x14008a96a`

### Entry and movement

- The constructor has already forced y to `-100`. State 0 draws `Effect_m[4]`
  with layer/field `50`, mode `8`, angle zero, white/opaque, and uniform scale
  `3.0 - age * 0.15`, at `FUN_1401346a0(current,-50)`.
- At timer `20`, enter state 1, reset the timer, set speed `6.0`, and clear the
  hit gate.
- Before timer `210`, angle tracks the player with step `0x40`. While timer is
  below `121`, speed decreases by `0.1` until it reaches `1.5`.
- From timer `210`, angle turns toward `0xc000` with step `0xa0` and speed
  increases by `0.1` per frame. Position advances from angle and speed every
  state-1 frame.

### Projectiles

The firing window is state timers `24..209`. Common bursts use
`phase=(age-24)%interval` and fire at phase `0,4,8,12,16,20`; phase zero stores
the aim from each source in `+0x42/+0x44`.

| difficulty | interval | common speed, stages `<=5` | common speed, stages `>5` | fan speed, stages `<=5` | fan speed, stages `>5` | fan count `<=5` | fan count `>5` |
|---:|---:|---:|---:|---:|---:|---:|---:|
| `0` | `110` | `6.0` | `7.0` | `4.0` | `5.0` | `5` | `7` |
| `1` | `70` | `7.0` | `8.0` | `5.0` | `6.0` | `7` | `9` |
| `2` | `60` | `8.0` | `9.0` | `6.0` | `7.0` | `9` | `11` |
| `3` | `60` | `8.0` | `9.0` | `6.5` | `7.5` | `7` | `9` |
| `4` | `60` | `9.5` | `9.5` | `8.0` | `8.0` | `11` | `11` |

Stage 3 takes the `<=5` columns. Common shots are selector `7`, behavior `0`,
initial travel `10`, radius `1`, aux `0`, from `(x+50,y+80)` and
`(x-50,y+80)`. Difficulties `3/4` add two shots per source at stored aim
`-1000` and `+1000`.

On the doubled cycle `(age-24)%(interval*2)`, the positive-x source emits a
selector `4`, behavior `0` fan at phase `32`; the negative-x source emits at
phase `interval+32`. The normal fan spans `20000` fixed-angle units. On
difficulties `3/4`, add a fan at `fanSpeed-1.5`, count `N-1`, with spread
`(20000/(N-1))*(N-2)`. Common-shot calls are at
`0x14008a3c9..0x14008a4ce`; fan calls are at
`0x14008a530..0x14008a651`.

### Draw and removal

- Main body: `Enemy_m[49]` (`DAT_140e44b94`) at `(x,y)`.
- Side bodies: `Enemy_m[50]` (`DAT_140e44b98`) at `(x+50,y+10)` normal and
  `(x-50,y+10)` horizontally mirrored.
- `Effect_s[0]` at `(x+50,y-55)` and `(x-50,y-55)`, scale `0.8`, alpha `192`,
  with the same white/orange two-frame pulse as type `0x25`.
- All direct body/effect draws use layer/field `0x20`, mode `7`, angle zero.
- It calls `FUN_140079c10(entity,1)` after drawing (`0x14008a890`).
- HP `<=0`: reward parameters `(500,8)` and cleanup flag `1`, at
  `0x14008a8fe/0x14008a90b`.
- It is removed immediately when outside x `[fieldOrigin-128,
  fieldOrigin+728]` or y `[-128,848]`.

## Type 0x27: `FUN_14008a970 @ 0x14008a970..0x14008b471`

### Entry, children, and movement

- At state-0 timer zero, choose current x `-100` when saved spawn x is below
  `360`, otherwise `820`; current y becomes `-100`. The original scheduled
  coordinates remain in `+0x30/+0x34` as the first target.
- State 0 draws `Effect_m[4]` with layer/field `50`, mode `8`, angle zero,
  white/opaque, and uniform scale `3.0 - age * 0.15`, at
  `FUN_1401346a0(current,-50)`.
- At timer `20`, spawn type-`0x28` children, then enter state 1, reset timer,
  set speed `11.5`, set angle toward the saved target, and clear the hit gate.
- Always spawn children `(offset x, offset y, angle)` =
  `(50,-90,-1000)` and `(-50,-90,+1000)`. On difficulty `>0`, also spawn
  `(100,-50,-3000)` and `(-100,-50,+3000)`. Each child requests HP
  `99999999` (the shared easy-mode multiplier still applies), reward kind `1`,
  radius `20`, initial hit gate `1`, speed `0`, and owner id equal to this
  parent's entity id. Constructor calls are at
  `0x14008ab73`, `0x14008abbf`, `0x14008ac16`, and `0x14008ac59`.
- In state 1, turn toward `+0x30/+0x34` with step `0x200` and move at current
  speed. At ages `60,110,160,210`, choose a deterministic random target x in
  `[120,600]` and target y in `[age,age+100]`.
- For ages below `61`, speed decreases by `0.15` until it reaches `2.5`. At age
  `240+`, target y becomes `-500` and speed increases by `0.1` per frame.

### Projectiles

The parent fires during ages `60..239`.

| difficulty | interval | fan count | base speed |
|---:|---:|---:|---:|
| `0` | `160` | `3` | `4.5` |
| `1` | `120` | `5` | `6.5` |
| `2` | `90` | `7` | `7.5` |
| `3` | `90` | `7` | `8.0` |
| `4` | `90` | `9` | `9.5` |

At `(age-60)%interval==0`, emit two player-aimed fans from current `(x,y)`:

- selector `2`, behavior `9`, initial travel `10`, speed `base+3`, radius `1`,
  count `N-1`, reduced spread `(20000/(N-1))*(N-2)`;
- selector `3`, behavior `0`, initial travel `10`, base speed, radius `1`,
  count `N`, spread `20000`.

On difficulties `3/4`, the same pair also fires when
`age>83 && (age-84)%interval==0`, adding a phase offset of `24`. Calls are at
`0x14008b0d5/0x14008b117`.

### Draw and removal

- `bob = 5*sin(age*2*pi/48)`.
- Main body: `Enemy_m[51]` (`DAT_140e44b9c`) at `(x,y)`.
- On even ages, side body `Enemy_m[52]` (`DAT_140e44ba0`) at
  `(x+70,y+bob-10)` normal and `(x-70,y+bob-10)` mirrored.
- All direct draws use layer/field `0x22`, mode `7`, angle zero, scale `(1,1)`.
- Every fourth frame append a body trail/effect node: effect type `5`, graph
  `Enemy_m[51]`, `+0x10=0x21`, scales `1/1`, field `0x18`, RGB `255`, alpha
  `64`.
- It calls `FUN_140079c10(entity,1)` after drawing (`0x14008b37e`).
- HP `<=0`: reward `(500,8)`, cleanup flag `1`, calls
  `0x14008b3f9/0x14008b406`.
- Offscreen removal is gated by age `>=240`; bounds then are the type-`0x26`
  bounds.

## Type 0x29: `FUN_14008b480 @ 0x14008b480..0x14008bd5e`

### Entry, children, and movement

This parent uses the same side-entry/random-target state machine as type
`0x27`, with these differences:

- state-1 initial speed is `12.0`, and its deceleration floor is `3.0`;
- at timer `20` it spawns type-`0x2a` children at
  `(30,80,+200)` and `(-30,80,-200)`; difficulty `>0` also adds
  `(70,40,0)` and `(-70,40,0)`;
- child HP, kind, radius, hit gate, speed, and owner linkage match the type
  `0x28` children described above. Calls are at
  `0x14008b64c`, `0x14008b693`, `0x14008b6ea`, and `0x14008b730`.

The type-`0x29` parent itself creates no projectile nodes. Its visible attack
logic therefore depends on implementing the spawned type-`0x2a` child. The
entity update table maps both child types `0x28` and `0x2a` through case `0x1c`
to `FUN_14008bd60`; `FUN_14008d230` belongs to schedule type `0x2b` instead.
Substituting generic parent fire changes the original pattern.

### Draw and removal

- It uses the same `5*sin(age*2*pi/48)` bob.
- Main body: `Enemy_m[53]` (`DAT_140e44ba4`) at `(x,y)`.
- On even ages, side body `Enemy_m[54]` (`DAT_140e44ba8`) at
  `(x+70,y+bob)` normal and `(x-70,y+bob)` mirrored.
- Direct draws use layer/field `0x22`, mode `7`; every fourth frame appends the
  same type-5/body-trail node as type `0x27`, using `Enemy_m[53]`.
- It calls `FUN_140079c10(entity,1)` after drawing (`0x14008bc7b`).
- HP `<=0`: reward `(500,8)`, cleanup flag `1`, calls
  `0x14008bce6/0x14008bcf3`.
- Offscreen removal is gated by age `>=240` and uses the same bounds as type
  `0x27`.

## Required child helper: `FUN_14008bd60`

Types `0x28` and `0x2a` both map to update case `0x1c` and share
`FUN_14008bd60 @ 0x14008bd60..0x14008d22b`. This is part of the observable
behavior of parents `0x27/0x29`.

The helper resolves the owner by matching child `+0x08` against entity
`+0x04`. The desired child point is `parent x/y + child +0x30/+0x34` (the
offsets passed above). Each frame it moves the child toward that point by
exactly one eighth of the remaining distance. On child age zero it snaps the
current position to the parent center after computing the first step, so the
first visible child frame is at the parent.

The child constructor requests HP `99999999`; difficulty zero still applies
the shared `0.8` constructor multiplier. More importantly, child `+0x54`
remains `1`, so the player cannot hit it. If owner HP is below one, the helper
calls `FUN_140079e20(child,0)` and clears the child; if the owner is absent or
inactive, it clears the child directly.

### Type 0x28 child

- Draw `Enemy_s[27]` (`DAT_140e446cc`), layer/field `0x22`, mode `7`, angle
  zero, scale x `1`, scale y `1 + 0.1*sin(childAge*pi/16)`.
- Fire only for child age `>=100` while owner state timer is below `240`.

| difficulty | cycle | base speed |
|---:|---:|---:|
| `0` | `160` | `5.0` |
| `1` | `120` | `6.0` |
| `2` | `90` | `6.5` |
| `3` | `90` | `6.5` |
| `4` | `90` | `8.0` |

With `local=(childAge-100)%cycle`, capture player aim from the owner center at
local zero, then fire at local `0,5,10,15,20,25,30,35`. Each shot is selector
`9`, behavior `0`, child position, angle `storedOwnerAim + child +0x40`, initial
travel `10`, speed `base + local*0.08`, radius `1`, aux `0`. Difficulties
`3/4` add a same-angle shot at speed `+2.0`. Calls are at
`0x14008c107/0x14008c151`.

### Type 0x2a child

- Draw `Enemy_s[28]` (`DAT_140e446d0`), layer/field `0x22`, mode `7`, angle
  `childAge*333`, scales `1/1`.
- Fire only for child age `>=75` while owner state timer is below `240`.

| difficulty | cycle | base speed |
|---:|---:|---:|
| `0` | `90` | `5.6` |
| `1` | `60` | `6.5` |
| `2` | `50` | `7.0` |
| `3` | `50` | `6.5` |
| `4` | `40` | `8.0` |

With `local=(childAge-75)%cycle`, capture player aim from the owner center at
local zero, then fire at local `0,5,10,15,20,25`. Shots use selector `7`,
behavior `0`, angle `storedOwnerAim + child +0x40`, initial travel `10`, speed
`base + local*0.08`, radius `1`, aux `0`. Difficulties `3/4` add a same-angle
shot at speed `+2.5`. Calls are at `0x14008c325/0x14008c373`.

## Reconstruction gap at audit time

At the time of this audit, `stage_runtime.cpp` has no constructor cases for
`0x25`, `0x26`, `0x27`, or `0x29`. They therefore receive the default radius
`28`, small-enemy frame `8`, generic speed, and are hittable immediately.
Their schedule HP happens to be restored after the switch, including the
difficulty-zero `0.8` scaling.

All four fall through `updateGenericEnemy()` and
`emitGenericProjectiles()`. This loses the 20-frame entry state, timer reset,
fixed-angle movement, type-specific children, every difficulty table above,
original rewards, exact bounds, and multipart drawing. `stageUsesMediumFrame()`
also omits types `0x26/0x27/0x29`, so even assigning the right frame number
without adding exact draw routing would select the wrong sprite sheet.

Implementing only these four parents is still insufficient for the two
setpieces: type `0x27` creates `0x28` children and type `0x29` creates `0x2a`
children. Both children use `FUN_14008bd60`; the latter parent has no
projectile calls at all.
