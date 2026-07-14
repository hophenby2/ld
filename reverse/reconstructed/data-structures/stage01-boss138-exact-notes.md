# Stage 1 boss `0x138` exact audit

Status: audited and ported into `StageRuntime`; no build was run. The main body
is `FUN_140004660 @ 0x140004660` (1,468 Ghidra decompile lines). The runtime now
uses the recovered seven-state boss loop described below.

## Evidence set

- Exact main body: `reverse/ghidra-or-ida/exports/stage01-boss138-exact/140004660_FUN_140004660.c`.
- Phase-break helper: `.../1400031d0_FUN_1400031d0.c`.
- stage-clear/final-transition helper: `.../140003ad0_FUN_140003ad0.c`.
- per-frame boss HUD helper: `.../140002260_FUN_140002260.c`.
- common Boss ambient-effect helper: `.../140004140_FUN_140004140.c`.
- common entity constructor and ambient helper: `.../140078a00_stage_entity_spawn_candidate.c` and
  `.../14007ac00_FUN_14007ac00.c`.
- Constants: `reverse/ghidra-or-ida/exports/stage01-boss138-scalars.tsv` and
  `stage01-boss138-spawn-scalars.tsv`.
- Dispatch proof: `0x138 -> case 0x9f -> FUN_140004660` at
  `reverse/ghidra-or-ida/exports/stage-entity-list-refs/global-key-ref-decompiled/140078b70_FUN_140078b70.c:501`.
- Original handoff: `reverse/ghidra-or-ida/exports/per-stage-gameplay-renamed/neighborhood-decompiled/140118420_stage_01_gameplay_update_candidate.c:307`.

`DAT_140e44910` is **not** `Boss.png`: it is `Enemy_l.png[0]`.  `Boss.png`
is the 160-handle table beginning at `DAT_140e44310`; see
`1400ced90_load_primary_resources_candidate.c:161-178`.

## Constructor and field contract

At `endFrame + 0x3c` the original performs:

```text
stage_entity_spawn_candidate(
    type=0x138, hp=100000, kind=0,
    x=360.0f, y=200.0f, angle=0,
    speed=0.3, radius=160, untargetable=1, owner=0)

DAT_140e44308 = allocated entity id
DAT_140e418cc = 1
DAT_140e419bc = 0
DAT_140e41b0c = 100000
DAT_140e4192c = 0
DAT_140e41af8 = 3
```

Difficulty 0 applies the constructor's common `0.8` HP scale to the otherwise
unused intro HP.  The three actual attack HP values are assigned directly by
the boss state transitions.

The existing `StageEntity` working names are misleading for the first fields.
For this helper the confirmed layout is:

| Offset | Boss meaning |
| --- | --- |
| `+0x00` | active flag |
| `+0x04` | unique entity id |
| `+0x08` | owner id |
| `+0x0c` | state-local timer; dispatcher increments it after the helper every frame |
| `+0x10` | targetable-age timer; increments only while `+0x54 == 0` |
| `+0x14` | boss substate (`0..6`) |
| `+0x18` | spawn type `0x138` |
| `+0x1c/+0x20` | current/original HP |
| `+0x24` | entity kind (`0`, not `120`) |
| `+0x28/+0x2c` | x/y |
| `+0x30/+0x34` | constructor origin x/y |
| `+0x40/+0x42/+0x44` | current, previous and target fixed angles |
| `+0x48` | movement speed (`0.3`) |
| `+0x50` | collision radius |
| `+0x54` | inverse targetability: `1` is invulnerable, `0` is targetable |
| `+0x5c` | number of live phase children |

The common dispatcher increments `+0x0c` unconditionally and `+0x10` only
when `+0x54 == 0` (`FUN_140078b70:650-656`).  A reconstruction should not add
an independent 60-frame activation delay.

## Global phase loop

The important globals are:

| Global | Meaning in this helper |
| --- | --- |
| `DAT_140e419bc` | phase mode: `0` intro, `1` live attack, `2` transition, `-1` final clear |
| `DAT_140e41b0c` | current attack's maximum HP |
| `DAT_140e4430c` | attack countdown, set to `0x708` (1800) |
| `DAT_140e4192c` | phase/reward index, reset to zero for each live attack |
| `DAT_140e41af8` | remaining phase breaks, initially `3` |
| `DAT_140e44908/0c` | random movement target x/y |
| `DAT_140e44308` | root boss entity id used by child and HUD helpers |

At the top of every update, if mode is `1` and either HP or the `1800`-frame
countdown is exhausted, `FUN_1400031d0` runs, a `0x137` phase-break entity is
spawned at the boss, the boss becomes invulnerable, its timer is reset, and:

| Remaining before decrement | Next state | Other change |
| --- | --- | --- |
| `3` | `2` | mode `2`; radius becomes `240` |
| `2` | `4` | mode `2` |
| `1` | `6` | mode `-1` |

The remaining count is then decremented and live-child count is reset.  This
branch is the boss's death logic.  It must run before generic enemy death; the
root entity is deliberately kept alive across all three HP bars.

## State machine

| State | Local duration | Core behavior and exit |
| --- | --- | --- |
| `0` | `0xf0` | Intro. At timer 0 spawn decorative root child `0x12`. For `t<180`, use the scripted origin trajectory below; from `t>=191`, add `0.1` to y per frame. Draw `Enemy_l[0]`. At `240`: state `1`, HP/max-global `60000`, countdown `1800`, radius remains `160`, targetable, mode `1`. |
| `1` | until HP/time break | Turn heading toward the random target by at most `0x200`, move at `0.3`, run all first-pattern bullets, draw `Enemy_l[0]`. Break goes to state `2`. |
| `2` | `0x17c` | First transition. Timer `<120`: ambient helper and cumulative `y += t*0.02`; effects at `1` and `120`; phase-title helper after `220`. Draw `Enemy_l[0]` through timer `129`, then cycle Boss frames `0,1,2` every 7 frames. At `380`: radius `80`, targetable, state `3`, HP/max-global `55000`, countdown `1800`, mode `1`. |
| `3` | until HP/time break | Moving live phase. Spawn four type `0x15` children at timers `1,11,21,31`; attack starts at `180`. Draw Boss entry frames `3/4`, then `5/6/7`, back through `4/3`, then idle `0/1/2`. Break goes to state `4`. |
| `4` | `0xb4` | Second transition. Scale is `1 - 0.3*sin(t*pi/180)` and y increases by `0.1`. Run ambient helper for `t<90`; cycle Boss frames `8,9` every 5 frames. At `180`: targetable, state `5`, HP/max-global `60000`, countdown `1800`, mode `1`. |
| `5` | until HP/time break | Same `0x200` heading steering and `0.3` movement. Spawn type `0x16` children at `1,11`, type `0x17` at `21,31`, plus linked effect at `120`; attack starts after `159`. Draw `0/1/2` for `t<80`, `3/4` for `80..89`, then `5/6/7`. Break goes to state `6`. |
| `6` | `0x1e0` | Calls final-clear helper every frame. For `t<240`, run ambient effects, add `0.2` to y and cycle Boss frames `8,9`; route/result panels are shown for `60..239`. At `240` create final disappearance effect; at `480` deactivate root. `FUN_140003ad0` sets clear/transition globals at timers `1`, `420`, and `480`. |

The state-0 trajectory can be transcribed without approximation.  With
`origin=(360,200)` and `t<180`:

```text
a = (t + 60) * pi / 120
amp = -600 + 600 * sin(t * pi / 360)
x = originX + sin(a) * amp
y = 600 + sin(a) * (originY - 600)
```

Timers `180..239` additionally drive the original fade/effect alpha.  The
integer truncations visible in `FUN_140004660:118-195` should be retained for
pixel/timing parity.

Every 50 global frames the movement target is regenerated deterministically:
`x = rng(frame) % 301 + 210`, `y = rng(stage*111 + frame) % 101 + 150`.

## Root bullet patterns

`FUN_14006c2f0` creates a single projectile and `FUN_1400709b0` creates a
spread.  All angles below use the original 16-bit turn domain.

### State 1

After timer 40, `local=(timer-40)%720` selects a repeating script:

| Local window | Pattern |
| --- | --- |
| `0..29`, `240..269`, `300..329`, `600..629`, `660..689` | Every 4 frames, fire visual `0x0b`, projectile id `0` from `(x,y+70)` toward the aim cached every 60 frames. Difficulty `3+` adds the `-1500/+1500` pair at speed minus `1`. |
| `10..29`, `250..279`, `310..339`, `610..639`, `670..699` | Fire visual `1`, id `0` spreads. Cadence by difficulty is `20,14,10,10,10`; count is `3,5,7,7,8`; speed is `3.5,4.5,6.5,7,9`. |
| `60..99` and `125..164` | Alternating right/left sources `(x+95,y-5)` and `(x-95,y-5)`, visual `4`, id `0`, randomized `+/-3000` aim. Cadence/count/speed use the preceding table; difficulty `3+` adds visual `0` at speed minus `2`. |
| `360..439` and `470..559` | Rotating streams from the same right/left sources. Cadence `6,4,3,3,2`; count `3,5,7,9,11`; angle step `1000,1400,2060,2060,2900`; base speed `3.5,5.5,6,6,7.5`, increased by `0.01` per window frame. Difficulty `3+` adds a stream at speed plus `1.2`. |

The exact source, random modulo and spread arguments are at
`FUN_140004660:269-573`.

### State 3

For `t>=180`, difficulty tables are:

```text
cadence       = 16,12,8,7,6
spread count  = 1,3,4,5,7
spread arg    = 0,7000,10000,12000,16000
angle step    = 180,240,300,300,350
speed         = 3.5,4.0,4.5,5.0,7.2
```

The first visual-`4`/id-`0` stream uses
`(t-180)*step-0x2000`.  From `t>=280`, a second uses
`(280-t)*step-0x6000`.  Once all four children are destroyed, speed is
multiplied by `1.5` and each stream gains a visual-`5` counterpart with the
opposite `+0x2000/+0x6000` offset and speed plus `1.0`.

### State 5

After timer `159`, let `destroyed=4-liveChildren`:

```text
spread count = 7,9,11,11,13
base speed   = 4.5,5.5,6.5,6.5,7.5
speed       += destroyed * 0.5
period       = (5 - destroyed) * 20   // 100,80,60,40,20
```

At every period boundary from timer `160`, fire visual `2`, id `0`, spread
angle `0x8000`; difficulty `3+` adds speed `+1.8`.  If all children are gone,
also fire visual `3`, id `0` every 20 frames from timer `170`, with a
deterministic random `+/-3000` adjustment to the player aim.  The one-shot
achievement/save cue in this all-children-dead branch is also original logic.

## Child/helper contract

- Intro type `0x12` dispatches to `FUN_140007960`; it attaches to the boss and
  creates decorative `0x13/0x14` nodes.  It uses `Enemy_l` frames, not Boss
  frames.
- Types `0x15/0x16/0x17` all dispatch to `FUN_140007fc0`.  Their constructor
  x/y values are relative offsets from the root boss, despite looking like
  off-screen absolute coordinates.
- State 3 spawns four `0x15` nodes (HP `6000`) at relative offsets
  `(-30,200)`, `(-30,-200)`, `(-140,110)`, `(-140,-110)`.
- State 5 spawns two `0x16` nodes (HP `12000`) at `(200,-30)` and `(-200,-30)`,
  and two `0x17` nodes (HP `7000`) at `(100,-160)` and `(-100,-160)`.
- Each child spends 60 frames invulnerable, then becomes targetable. On death
  it calls the original `FUN_14007b010(child,1000,8)`, decrements the root's
  `+0x5c`, creates a type `0x153` death node, and deactivates. Children also
  vanish when the root leaves its live phase or the phase timer expires.
- `0x15` fires aimed visual `7` singles, `0x16` fires visual `7` spreads and
  later three-way visual `8` volleys, and `0x17` fires aimed visual `0x0b`
  bursts. Exact tables remain in `FUN_140007fc0:176-509`; these helpers cannot
  be routed through generic enemy movement without changing the phase.

## Drawing and common effects

All root draws use layer `0x1e`, mode `7`, angle `0`, and normally scale
`1.0`; state 4 supplies its animated scale. Frame selection is:

```text
state 0/1: Enemy_l[0]
state 2:  Enemy_l[0] until t=129, then Boss[0,1,2] at 7-frame steps
state 3:  t 0..9   Boss[3,4]       (5-frame steps)
          t 10..59 Boss[5,6,7]     (5-frame steps)
          t 60..69 Boss[4,3]       (5-frame steps)
          t >=70   Boss[0,1,2]     (7-frame steps)
state 4:  Boss[8,9]                (5-frame steps)
state 5:  t 0..79  Boss[0,1,2]     (7-frame steps)
          t 80..89 Boss[3,4]       (5-frame steps)
          t >=90   Boss[5,6,7]     (5-frame steps)
state 6:  Boss[8,9] through t=239  (5-frame steps)
```

`FUN_140004140` is called after every state and creates ambient boss particles
only during the player's special/cancel window. `FUN_140002260` is then called
every frame to draw the boss HP/name HUD. Those effect/HUD queues are separable
from the minimum movement-and-bullet port, but must not be replaced with root
projectiles.

## Pre-port reconstruction mismatches

At the time of this audit, `stage_runtime.cpp` differs materially:

1. Spawn is `(300,180)` instead of `(360,200)`, radius is `72` instead of
   `160`, kind/reward weight is `120` instead of original kind `0`, and a fake
   60-frame activation delay replaces inverse targetability.
2. The generic HP `<1` branch executes before `FUN_140004660` routing, so it
   deactivates the root and emits a generic reward instead of performing a
   phase break.
3. Update is only a small sine jitter and aim-at-player assignment; emission is
   an unrelated 90-frame radial spread.
4. Drawing fixes frame `0`, rotates it toward the player and uses the generic
   medium scale (`0.42`). The original uses the table above, angle zero and
   scale `1.0`.
5. No boss phase globals/countdown, `0x137` break entity, `0x12..0x17`
   children, child-count escalation, spell effects, or final state transition
   are represented.

## Minimum direct-port boundary

A coherent first exact port should include, as one change:

1. Exact constructor and handoff globals.
2. A dedicated boss update path that bypasses generic death and owns its
   state timer, targetability, countdown and three HP bars.
3. States `0..6`, including the phase-break preamble and exact transitions.
4. Root bullet scripts for states `1`, `3`, and `5`.
5. Exact root frame selection and unrotated scale-1 drawing.
6. Dedicated `0x15..0x17` children (or an equivalent child component) because
   their live count directly changes state-3/state-5 bullet logic.
7. Final state-6 deactivation and stage-clear flags.

The `0x60` effect queue, `0x48` render queue, boss HUD, sounds, `0x137`
visual, and route-result panels can be layered on after this boundary without
altering the core state/bullet simulation. Omitting the child contract or
generic-death bypass, however, does alter gameplay and is not a safe temporary
approximation.

## Runtime port status - 2026-07-13

The minimum direct-port boundary above is implemented. The constructor uses
`(360,200)`, speed `0.3`, radius `160`, and inverse targetability; the root
bypasses generic death/movement/emission and owns all seven states, three HP
bars, 1800-frame timers, and phase breaks. State 1/3/5 projectile scripts and
dedicated `0x15..0x17` children include their spawn phases, attachment,
targetability, death-count contract, escalation, and multipart drawing.

State 6 exposes a clear latch at timer 480. `App` consumes it and restores the
stage-selection frontend; starting the same configuration again explicitly
resets the runtime. Remaining gaps are the separable `0x12`, `0x137`, and
`0x153` effect nodes, the original Boss HUD/effect queues, and the full route
result presentation.
