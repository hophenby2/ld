# Shared enemy types `0x0b` and `0x0c`: exact runtime notes

This note records the recovered semantics of the two early enemy helpers that
are reused outside Stage 1:

- `0x0b -> FUN_14007d4e0 @ 0x14007d4e0`
- `0x0c -> FUN_14007dfb0 @ 0x14007dfb0`

Primary evidence is
`reverse/ghidra-or-ida/exports/stage01-helper-decompiled/14007d4e0_FUN_14007d4e0.c`,
`14007dfb0_FUN_14007dfb0.c`, and direct `LikeDreamer.exe` disassembly over
`0x14007d4e0..0x14007ea2a`. Both helpers are selected by the common entity
dispatcher, so their behavior is independent of the stage that scheduled them.

## Shared dispatcher and constructor contract

The entity layout used here is the established `0x68`-byte stage node:

| Offset | Meaning used by these helpers |
| --- | --- |
| `+0x00` | active/link flag |
| `+0x0c` | helper-local timer; incremented by the dispatcher after the helper |
| `+0x10` | targetable-age timer; conditionally incremented after collision |
| `+0x14` | helper state |
| `+0x1c/+0x20` | current/max HP |
| `+0x28/+0x2c` | x/y |
| `+0x40` | movement angle16 |
| `+0x42/+0x44` | cached right/left firing angles (`0x0c`) |
| `+0x48` | double movement speed |
| `+0x54` | inverse targetability flag (`0` means targetable) |

After a helper returns, the dispatcher still performs target collision and
timer increments even when the helper cleared `+0x00`. This is why a body can
draw and collide on its death/bounds terminal frame, then be unlinked at the
start of the next update.

Constructor values recovered from `stage_spawn_dispatch_candidate` are:

| Type | case | kind/reward weight | radius | position | angle | speed | initial targetability |
| --- | ---: | ---: | ---: | --- | ---: | ---: | --- |
| `0x0b` | `5` | `5` | `30` | scheduled x/y | `0x4000` | `1.0` | false |
| `0x0c` | `6` | `7` | `30` | scheduled x, forced y `-20` | `0x4000` | `1.0` | false |

Scheduled HP is retained (and the common difficulty-0 `0.8` HP scaling remains
in the node constructor).

## Shared state 0 and movement

Both helpers draw `Effect_m` frame 4 (`DAT_140e41a50`) on layer `0x32`, mode
`8`, at a clamped copy of the current point:

```text
x in [playerX / 6 - 20, playerX / 6 + 620]
y in [-20, 740]
scale = 2.0 - helperTimer * 0.1
```

The node itself stays at the scheduled point until timer `20`. On that call the
helper chooses its random speed with `FUN_140134db0`, selects angle `0` when
`x <= 0` or `0x8000` when `x >= 720` (otherwise retaining `0x4000`), commits
the clamped point, changes to state 1, resets the timer to zero, and becomes
targetable. Execution falls through, so timer-0 state-1 movement, firing,
body, and gauge all occur on the same call as the final marker.

The random helper is frame-seeded and quantized to hundredths:

- `0x0b`: `[7.00, 9.00]`
- `0x0c`: `[5.00, 7.00]`

In state 1, both helpers capture the player aim from the pre-movement entity
point. For timer `< 200`, speed is reduced by `0.1` only while it is above
`1.0`, and angle approaches that aim by `0x80`. From timer `200`, angle
approaches `0xc000`; speed increases by `0.1` every frame. The exit turn step is
`0x200` for `0x0b` and `0x100` for `0x0c`. Position integration uses double
cosine/sine before conversion back to the node's float coordinates.

## Type `0x0b` firing and drawing

Firing is limited to timer `< 200` and a pre-movement source `(x, y + 25)`
inside:

```text
x in [playerX / 6 + 40, playerX / 6 + 560]
y in [40, 680]
```

The source aim is truncated to angle16 and then quantized to 32 directions:

```text
angle = ((((trunc(aim * 65536 / (2*pi)) & 0xffff) + 0x400) >> 11) * 0x800) & 0xffff
```

Difficulty tables are:

| difficulty | 0 | 1 | 2 | 3 | 4 |
| --- | ---: | ---: | ---: | ---: | ---: |
| start | 30 | 16 | 12 | 8 | 6 |
| interval, stages 1..3 | 32 | 27 | 20 | 15 | 6 |
| interval, stage 4+ | 24 | 20 | 16 | 12 | 6 |
| speed | 4.5 | 5.5 | 6.5 | 6.5 | 8.5 |

Five intervals form one cycle and only the first three interval boundaries
emit. The call is visual `0`, projectile id `0`, initial travel `0`; difficulty
3/4 adds a same-angle projectile at `speed + 1.6`.

Drawing uses the post-movement point and helper timer:

- frame 4 body: scaleX `1 + 0.1*sin(timer * 0.12319971190548208)`, scaleY `1`;
- four frame 5 nodes at `y - 45`, angles
  `timer*2000 + {0, 0x4000, -0x8000, -0x4000}`;
- gauge mode 2 at y offset `-50`, using the HP captured before collision.

Death uses payout window `300` and effect mode `0` in the original.

## Type `0x0c` firing and drawing

Firing uses the post-movement right/left sources `(x + 25, y)` and
`(x - 25, y)`. At each interval boundary the helper independently captures
their truncated player aims into `+0x42/+0x44`. It then fires every five frames
for the first 40 frames of that interval, with initial travel `10`.

| difficulty | 0 | 1 | 2 | 3 | 4 |
| --- | ---: | ---: | ---: | ---: | ---: |
| normal start | 30 | 20 | 12 | 10 | 10 |
| stage-4+ start | 20 | 12 | 10 | 10 | 10 |
| normal interval | 140 | 100 | 80 | 80 | 60 |
| stage-4+ interval | 120 | 80 | 60 | 60 | 50 |
| normal base speed | 4.8 | 6.5 | 8.0 | 8.0 | 9.5 |
| stage-4+ base speed | 6.0 | 7.0 | 8.0 | 8.0 | 9.5 |

The speed is `base + normalPhase * 0.02`. `normalPhase` is deliberately
computed with the normal start/interval before the stage-4+ table override;
this preserves the original helper's ordering quirk. Calls use visual `7`,
projectile id `0`. Difficulty 3/4 adds a right angle `-700` and left angle
`+700` pair at `speed - 0.8`.

Drawing uses these literal sine waves (the old reconstruction's cosine was not
supported by the disassembly):

- mirrored frame 8 pair at `y + sin((timer - 17) * 0.1698158191129618)`, angles
  `+/-sin(timer * 1.2566370614359172) * 2400`;
- frame 7 at that same wave y minus `7`;
- frame 6 at `y + sin(timer * 0.1698158191129618) - 14`;
- gauge mode 2 at y offset `-50`, using pre-collision HP.

Death uses payout window `0x168` and effect mode `0`. Both types clear their
active flag outside `x = playerX/6 + [-180, 780]` or `y = [-180, 900]`.

## Runtime port status

`StageRuntime` now routes types `0x0b/0x0c` through these helpers on every
stage, owns the dispatcher timer separately from generic age, preserves the
transition fallthrough and pre/post-movement projectile origins, queues exact
multipart bodies and gauges, applies the helper-local death/bounds tail, and
keeps terminal-frame collision behavior. The runtime's generic death-burst
representation remains in place for the original mode-0 death effect node.
