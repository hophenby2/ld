# Stage 04 Type `0x3f` Exact-Port Notes

Status: the entity constructor, movement states, all three active projectile
families, multipart body, gauge, schedule gate, reward/death timing, bounds,
and the death-entry type-`0x16` portrait are ported to `StageRuntime`. The
remaining transient effect-list calls made during the 60-frame death animation
are still outside the runtime's current effect-node subsystem.

Primary evidence:

- `FUN_140095130` at `0x140095130..0x140096884`, exported as
  `missing-helper-priority/neighborhood-decompiled/140095130_FUN_140095130.c`.
- Type constructor branch `0x14007baf7..0x14007bfc3` in
  `stage_spawn_dispatch_candidate`.
- Raw constants exported by Homebrew Ghidra 12.1.2 to
  `reverse/ghidra-or-ida/exports/stage04-type3f-scalars.tsv`.
- Resource bases in `load_primary_resources_candidate`: `Enemy_s` begins at
  `DAT_140e44660`, `Enemy_m` at `DAT_140e44ad0`, and `Enemy_l` at
  `DAT_140e44910`.

## Constructor

The dispatch branch passes reward weight `120`, collision radius `240`, angle
`0x4000`, speed `1.0`, targetability flag `1` (invulnerable), and owner id `0`.
The common constructor copies scheduled HP to current/max HP and applies the
existing Easy `0.8` scale.

Both Stage 04 schedule sites are preserved: frame `0xe10`, HP `48000`, x `0x167`;
and frame `0x2648`, HP `44000`, x `0x169`. Their x values straddle the state-0
mirror test at `360`.

Both sites set `DAT_140e418cc = 1`. While it remains set, the paired type-`0x35`
windows after the first controller and the random type-`0x38` window after the
second controller are suppressed. The helper clears the flag only when type
`0x3f` completes its death state or exits its targetable bounds.

## State 0: mirrored entrance

For helper timers `0..89`, with `s=sin(timer*pi/180)`, the EXE truncates both
products to integers before adding them to the float coordinates:

```text
dx = 700 - trunc(s * 700)
dy = 400 - trunc(s * 400)
left  (sourceX < 360): x = sourceX + dx
right (sourceX >=360): x = sourceX - dx
y = savedY + dy
savedY += 1
```

For timers `90..120`, x is the source x, y is the saved y, and saved y still
increments by one. At timer `120`, speed becomes `0.3`, state becomes `1`, the
helper timer resets to zero, and the entity becomes targetable. The active-state
logic also runs on this transition frame.

## State 1: movement

While timer `<900`, every 20 frames the helper chooses a deterministic target
using the same frame-seeded MT expression visible in the EXE:

```text
targetX = rng(globalFrame) % 241 + 240
targetY = rng(globalFrame + 0x115c) % 61 + 40
```

The current fixed angle approaches the target angle by at most `0x200` per
frame, then moves at speed `0.3`. At timer `>=900`, the angle is fixed to
`0x4000`, speed is `(timer - 900) * 0.1`, and the entity accelerates downward.

## Projectile family A: four alternating mounts

Mount offsets are `(90,170)`, `(-90,170)`, `(160,117)`, and `(-160,117)`.
The first pair uses `timer % (2*halfCycle)`; the second pair uses
`(timer-halfCycle) % (2*halfCycle)` and starts at `halfCycle`. Shots occur in
the opening `window` frames when the phase is divisible by 3.

| Difficulty | Half-cycle | Window | Speed |
|---:|---:|---:|---:|
| 0 | 70 | 12 | 4.5 |
| 1 | 55 | 16 | 5.5 |
| 2 | 45 | 20 | 6.0 |
| 3 | 40 | 20 | 7.5 |
| 4 | 40 | 20 | 9.5 |

Each mount emits visual selector `7`, movement id `0`, initial travel `10`, and
angles `base-9000`, `base`, `base+9000`. Difficulties 3/4 add two three-shot
sets at speed `base-0.5`, using offsets `[-8500,500,9500]` and
`[-9500,-500,8500]`. The shared mount angle approaches player aim from
`(x,y+150)` by `0x10` after firing.

## Projectile family B: aimed jitter windows

Timers `60..419` are divided into 90-frame windows. The aim from `(x,y+220)` is
saved at each window start; shots occur during remainders `0..49` at the tabled
interval. Speed is `timer*0.005 + base`.

| Difficulty | Interval | Base speed | Extra shots |
|---:|---:|---:|---|
| 0 | 16 | 3.0 | none |
| 1 | 10 | 4.0 | none |
| 2 | 8 | 4.5 | none |
| 3 | 7 | 4.5 | duplicate at `speed+1.2` |
| 4 | 5 | 6.0 | offsets `-2777,+2778` |

The base angle adds `rng(globalFrame)%6001-3000`. All shots use visual selector
`4`, movement id `0`, and initial travel `10`.

## Projectile family C: half-circle fans

Timers `450..899` emit when `(timer-450) % interval == 0`. Speed is
`(timer-450)*0.01 + base`; the centered spread is `0x8000` fixed-angle units.

| Difficulty | Interval | Count | Base speed |
|---:|---:|---:|---:|
| 0 | 100 | 7 | 3.5 |
| 1 | 70 | 9 | 4.5 |
| 2 | 60 | 11 | 5.0 |
| 3 | 50 | 13 | 5.0 |
| 4 | 25 | 15 | 6.0 |

Difficulties 3/4 emit a second fan at `speed+1.2`. These shots use visual
selector `2`, movement id `0`, and initial travel `10`.

## Drawing

The helper appends the following body nodes every frame, in order:

1. Eleven `Enemy_s` frame 42 nodes, spaced 25 pixels along a ray rotating with
   a 136-frame period. Their scales descend from `1.0` to `0.5`.
2. Two `Enemy_m` frame 74 side nodes at `x +/- pulse*60, y+230`; the second is
   horizontally reversed. Pulse period is 120 frames and angle period 66.
3. `Enemy_l` frame 18 at `(x,y+70)` with the same `0.95..1.05` pulse scale.
4. Gauge type 0 at y offset `-40`; its fill begins at `(x-120,y-45)`.

## Death and bounds order

State 1 still moves and fires on the first frame whose HP is non-positive. It
then calls the reward helper with window `0x708` and effect parameter `0x1e`,
creates player-side object `0x18`, and allocates effect-list type `0x16` with
`PlayerFrame[1 + setupGroup*10]`, layer `0x6f`, and lifetime `0x78`. It enters
state 2, becomes untargetable, and resets the helper timer. State 2 adds
`timer*0.06` to y each frame and clears both the entity and schedule gate at
timer `60`.

While targetable, the final bounds test is x in
`[playerX/6-400, playerX/6+1000]` and y in `[-400,1120]`. It runs after body and
gauge nodes are queued in the original; an out-of-bounds exit also clears the
schedule gate. The reconstruction retains the terminal frame for drawing before
unlinking the inactive entity on the next update.
