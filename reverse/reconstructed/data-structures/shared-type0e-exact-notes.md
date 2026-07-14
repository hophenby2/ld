# Shared Enemy Type `0x0e` Exact-Port Notes

Status: the constructor, 20-frame entry, steering movement, both projectile
windows, nine-node multipart draw, gauge placement, death reward window, strict
bounds, and terminal collision behavior from `FUN_14007f2c0` are ported to
`StageRuntime`. Dispatch is global by spawn type.

Primary evidence:

- `reverse/ghidra-or-ida/exports/stage01-helper-decompiled/14007f2c0_FUN_14007f2c0.c`;
- original instructions `0x14007f2c0..0x1400800df` in `LikeDreamer.exe`;
- spawn case 7 in the stage spawn dispatcher;
- projectile constructors `FUN_14006c2f0` and `FUN_1400709b0`;
- common entity dispatcher collision/timer tail.

## Constructor and Entry

The constructor forces y to `-100` and supplies:

| Field | Value |
|---|---:|
| update type | `0x0e` |
| reward weight | `24` |
| collision radius | `80` |
| angle | `0x4000` |
| speed | `1.0` |
| targetability | invulnerable |

For helper timers `0..20`, the entity queues `Effect_m[4]` with scale
`3.0-timer*0.15`. Its marker point is clamped to
`[playerX/6-50,playerX/6+650] x [-50,770]`. At timer `20`, it enters state 1,
resets the helper timer, sets speed to `7.0`, becomes targetable, and continues
through active movement, firing, body drawing, and gauge drawing on the same
call. The transition frame therefore queues both the zero-scale marker and the
active body at timer zero.

## Movement

The helper captures the player aim at function entry, before movement. In
state 1 it applies these operations in order:

```text
if timer <= 120 and speed > 1.2: speed -= 0.1
angle = approach(angle, entryPlayerAim, 0x80)
if timer >= 300: speed -= 0.1
x += cos(angle*pi/32768) * speed
y += sin(angle*pi/32768) * speed
```

The post-movement position is used by all projectile sources and body nodes.

## Projectile Pattern

Firing is active for helper timers `24..299`. Let:

```text
cycle = (timer - 24) % 150
middleWave = 2*sin((timer-23)*2*pi/63)
sideY = y + 15 + middleWave
```

Difficulty tables are:

| Difficulty | Base speed | Side spread | Center interval | Center count |
|---:|---:|---:|---:|---:|
| 0 | `6.0` | `0` | `40` | `4` |
| 1 | `7.5` | `0` | `30` | `6` |
| 2 | `8.5` | `0x708` | `30` | `10` |
| 3 | `9.0` | `0xce4` | `15` | `12` |
| 4 | `11.0` | `0x9c4` | `15` | `13` |

The right source `(x+55,sideY)` captures its player aim at cycle `0` and
fires every five frames through cycle `29`. The left source `(x-55,sideY)`
captures separately at cycle `40` and fires every five frames through cycle
`69`. Each event creates visual selector `9`, movement ID `0`, initial travel
`10`, radius `1`, and base speed. Difficulty 2 and above add a two-projectile
spread at speed `base-1`; difficulty 4 adds another two-projectile spread at
speed `base-2` and twice the side spread.

For cycle `80..119`, the center source fires at the table interval from:

```text
(x, y - 24 + 2*sin(timer*2*pi/63))
```

It creates two visual-selector `0`, movement-ID `0` fans centered at player
aim `+200` and `-200`. Both use initial travel `0`, speed `base-2.5`, radius
`1`, the table count, and total spread `28000`.

## Multipart Draw

The original queues these `Enemy_m` frames in order:

1. Frame 21 mirrored pair on radius `70`, with an angle wave of period 36,
   amplitude `2000`, and bias `10000`.
2. Frame 20 mirrored pair on radius `85`, with the unshifted period-36 wave.
3. Frame 19 at the period-63 body wave shifted by 46 frames.
4. Frame 18 at the period-63 body wave shifted by 23 frames.
5. Frame 17 pair at x offsets `+45/-45`, y offset `frontWave-60`, and angles
   `bodyAngle-1000` / `1000-bodyAngle`.
6. Frame 16 at y offset `frontWave`, where
   `frontWave=2*sin(timer*2*pi/63)-24`.

The body-angle wave has period 63 and amplitude `2400`. The gauge uses mode 1
at x offset `0`, y offset `-120`.

## Death, Bounds, and Dispatcher Tail

After movement, firing, body, and gauge have been queued, HP below one calls
the reward helper with window `500` and reward weight `24`, then clears the
live flag. The lifetime rectangle is:

```text
x in [playerX / 6 - 128, playerX / 6 + 728]
y in [-128, 848]
```

The common dispatcher still performs terminal-frame player-shot collision and
then increments the helper timer. The runtime retains that terminal frame for
drawing before unlinking the inactive entity on the next update.

## Deferred Surface

- `FUN_140079e20(entity,1)` transient death visuals are represented by the
  runtime reward/death burst rather than the original global effect queue.
- Draw nodes are issued directly instead of reproducing the executable's
  global mode-7 render-node list and layer ordering.
