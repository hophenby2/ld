# Shared Enemy Type `0x0a` Exact-Port Notes

Status: the constructor surface, both movement states, projectile cadence and
sources, multipart drawing, gauge placement, death window, and strict bounds
from `FUN_14007c9c0` are ported to `StageRuntime`. Type `0x0a` is a global
entity-dispatch type, so the exact helper is now used outside Stage 1 as well;
in particular, the Stage 2 schedule no longer sends it through generic enemy
movement and firing.

Primary evidence:

- `reverse/ghidra-or-ida/exports/stage01-helper-decompiled/14007c9c0_FUN_14007c9c0.c`;
- original instructions `0x14007c9c0..0x14007d4d3` in `LikeDreamer.exe`;
- spawn dispatch instructions `0x14007b7a1..0x14007bfc3`;
- `reverse/ghidra-or-ida/exports/stage-update-helper-sample/neighborhood-decompiled/1400c9580_FUN_1400c9580.c`;
- dispatcher ordering in
  `reverse/ghidra-or-ida/exports/stage-entity-list-refs/global-key-ref-decompiled/140078b70_FUN_140078b70.c`.

## Constructor

Spawn dispatch case 4 passes the scheduled HP and x/y through the common
constructor with these type-specific values:

| Field | Value |
|---|---:|
| type | `0x0a` |
| reward weight | `10` |
| collision radius | `50` |
| current/saved angles | `0x4000` |
| speed | `1.0` |
| targetability flag | `1` (invulnerable) |
| owner | `0` |

The previous reconstruction used radius `34`, vertical speed `0.65`, and made
the entity targetable immediately. The common Easy-difficulty `HP * 0.8`
truncation remains applied after the type branch.

## State 0 Entry

The helper timer runs from `0` through `120`, inclusive. The entry direction is
derived once from the entity ID by the same four-word MT seed expression used
elsewhere in the executable:

```text
random = stageScriptRandFromFrame(entityId)
entryAngle16 = random % 4001 + 0x3830
entryX = originX + cos(angle16 * pi / 32768) * 300
entryY = originY + sin(angle16 * pi / 32768) * 300
t = sin(timer * pi / 240)
x = entryX + t * (originX - entryX)
y = entryY + t * (originY - entryY)
```

At timer `120`, the position reaches the scheduled origin. The helper sets
speed `0.8`, copies the player aim computed before that frame's interpolation
into the current angle, resets the timer to zero, enters state 1, and becomes
targetable. It then falls through: active movement, possible firing, body draw,
and the type-2 gauge all occur on the transition call.

`StageRuntime` increments `StageEnemy::age` before dispatch. State 0 therefore
uses `age-1` as the original helper timer; after the transition reset, state 1
uses `age` directly. This preserves the original `0..120`, then `0..` sequence.

## State 1 Movement

For timers below `300`, the current angle approaches the pre-movement player
aim by at most `0x100` fixed-angle units. At timer `300` and later, it approaches
`0xc000` by the same step and adds exact scalar `0.1` to speed each call. The old
runtime used `1/60` for this acceleration.

Movement is integrated before the projectile block. Strict terminal bounds are:

```text
x in [playerX / 6 - 64, playerX / 6 + 664]
y in [-64, 784]
```

The original queues movement, shots, body, and gauge before the HP and bounds
tail. The reconstruction likewise keeps an inactive node until the next update,
so the terminal frame remains visible. HP death calls the existing reward bridge
with window `400`; the original mode-0 death effect remains outside this port.

## Projectile Pattern

Only state-1 timers below `300` can fire. Difficulty tables are:

| Difficulty | First frame | Interval | Speed |
|---:|---:|---:|---:|
| 0 | `20` | `150` | `4.0` |
| 1 | `10` | `120` | `5.0` |
| 2 | `0` | `60` | `6.5` |
| 3 | `0` | `40` | `7.0` |
| 4 | `0` | `32` | `8.0` |

The later-stage table selected when the executable's stage index is greater
than 7 is also retained (`120/90/50/40/32` and `5.0/6.0/6.5/7.0/8.0`). Each
interval opens a 20-frame window and fires when the local timer is divisible by
3. At local timer zero, the helper captures aim from `(x, y-15)` into the saved
angle. Each firing event creates visual selector `4`, movement ID `0` bullets:

```text
(x+5, y-20), savedAngle, speed
(x-5, y-20), savedAngle, speed
(x,   y-15), savedAngle, speed
```

Difficulty 3 and 4 add a center bullet at `speed+2`. Difficulty 4 also adds
center bullets at `savedAngle-0x457` and `savedAngle+0x457`. After emission, the
saved angle approaches the current post-movement aim by `0x40`; it is not
advanced before the bullets use it.

## Drawing

`FUN_1400c9580(frame + entityId*5, 0, 6, 3, 12, 13, 14)` selects the body frame,
so frames `12`, `13`, and `14` each last six gameplay frames. The draw order is:

1. `Enemy_m` frame `15` at `(x,y-15)`, angle `wing`, normal orientation.
2. Frame `15` again at the same point, angle `-wing`, horizontally reversed.
3. The selected frame `12..14` at `(x,y)`, angle zero.

The wing angle is the signed truncation of:

```text
sin((globalFrame + entityId*5) * pi/4) * 3000
```

All three nodes use the state-0 interpolation factor as both x/y scale; state 1
uses scale `1`. Once targetable, gauge type `2` is drawn with x offset `0` and y
offset `-80`. The runtime snapshots HP when the helper queues this draw, so a
player-shot collision later in the dispatcher cannot retroactively alter the
same frame's gauge.

## Deferred Surface

- `FUN_140079e20(entity, 0)` transient death visuals are not represented here.
- Reward-item allocation and exact payout scatter belong to the separate reward
  runtime and were not changed by this port.
- The reconstruction draws the three body components in original order, but it
  does not yet expose the executable's global mode-7 layer queue (`7` during the
  entry transition and `0x23` during ordinary active frames).
