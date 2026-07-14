# Shared Enemy Type `0x0f` Exact-Port Notes

Status: the constructor, 20-frame entry, steering movement, alternating dual
mount pattern, center fans, five-node multipart draw, gauge placement, death
reward window, strict bounds, and terminal collision behavior from
`FUN_140080170` are ported to `StageRuntime`. Dispatch is global by spawn type.

Primary evidence:

- `reverse/ghidra-or-ida/exports/stage01-helper-decompiled/140080170_FUN_140080170.c`;
- original instructions `0x140080170..0x140080f57` in `LikeDreamer.exe`;
- spawn-dispatch case 8 at `0x14007b829` and common tail
  `0x14007bf81..0x14007bfc4`;
- integer random helper `FUN_140134d00`;
- projectile constructors `FUN_14006c2f0` and `FUN_1400709b0`.

## Constructor and Entry

Spawn-dispatch case 8 preserves scheduled HP and x/y, and supplies:

| Field | Value |
|---|---:|
| update type | `0x0f` |
| reward weight / kind | `30` |
| collision radius | `90` |
| angle | `0x4000` |
| speed | `1.0` |
| targetability | invulnerable |

For helper timers `0..20`, the entity queues `Effect_m[4]` with scale
`3.0-timer*0.15`. The marker point is clamped to
`[playerX/6-50,playerX/6+650] x [-50,770]`.

At timer `20`, speed becomes `9.0`. The angle becomes `0` when x is at most
`360`, or `0x8000` when x is at least `720`; an x between those tests retains
the constructor angle. The helper enters state 1, resets its timer, becomes
targetable, and continues through active movement, firing, body drawing, and
gauge drawing on the same call.

## Movement

The player aim is captured at function entry. In state 1:

```text
if timer <= 120 and speed > 1.0: speed -= 0.1
angle = approach(angle, entryPlayerAim, 0x80)
if timer >= 300: speed -= 0.1
x += cos(angle*pi/32768) * speed
y += sin(angle*pi/32768) * speed
```

Projectile and body coordinates use the post-movement point.

## Alternating Mount Pattern

Firing is evaluated for helper timers `40..299`. Difficulty tables are:

| Diff | Period | Active frames | Jitter | Speed, stage `<=4` | Speed, stage `>4` |
|---:|---:|---:|---:|---:|---:|
| 0 | `200` | `30` | `800` | `4.0` | `5.5` |
| 1 | `120` | `40` | `1200` | `5.5` | `6.5` |
| 2 | `100` | `50` | `1800` | `6.0` | `7.0` |
| 3 | `90` | `50` | `2400` | `7.0` | `7.0` |
| 4 | `90` | `50` | `3000` | `8.5` | `8.5` |

Let `cycle=(timer-40)%period`. The mount geometry is:

```text
mountAngle = trunc(sin(timer*pi/50)*2000)
mountX = cos(mountAngle*pi/32768)*95
mountY = sin(mountAngle*pi/32768)*95
sideY = y + sin((timer-17)*pi/36) + mountY - 15
rightX = x + mountX + 10
leftX  = x - mountX - 10
```

Cycle zero caches separate player aims for the two sources. For every active
cycle frame, `FUN_140134d00(globalFrame*111+timer,-jitter,+jitter)` supplies one
shared fixed-angle offset. Even cycles create visual selector `5`, movement ID
`0`; odd cycles create selector `1`, ID `0`. Both mounts use initial travel
`0`, radius `1`, and speed `base+cycle*0.1`.

## Cycle-65 Fans

At cycle `65`, the source is:

```text
(x, y + sin(timer*pi/36) - 30)
```

The fan tables are:

| Diff | Count | Speed, stage `<=4` | Speed, stage `>4` |
|---:|---:|---:|---:|
| 0 | `5` | `3.5` | `4.5` |
| 1 | `11` | `4.5` | `5.5` |
| 2 | `15` | `5.5` | `6.0` |
| 3 | `17` | `6.0` | `6.0` |
| 4 | `19` | `7.5` | `7.5` |

All use visual selector `4`, movement ID `0`, initial travel `0`, radius `1`,
and total spread `(count-1)*240`. Difficulty 0 creates one player-aimed fan.
Difficulty 1 and above add centers at aim `+10000` and `-10000`. Difficulty 3
and above repeat all three at speed `+1.2`.

## Multipart Draw

The original queues these `Enemy_m` nodes in order:

1. Frame 25 at the right mount, angle `mountAngle`.
2. Mirrored frame 25 at the left mount, angle `-mountAngle`.
3. Frame 24 at `y+sin((timer-34)*pi/36)`.
4. Frame 23 at `y+sin((timer-17)*pi/36)`.
5. Frame 22 at `y+sin(timer*pi/36)`.

All use scale `1`. The gauge uses mode 1 at x offset `0`, y offset `-120`.

## Death, Bounds, and Dispatcher Tail

HP below one calls the reward helper with window `500` and reward weight `30`,
then clears the live flag. The lifetime rectangle is:

```text
x in [playerX / 6 - 360, playerX / 6 + 960]
y in [-360, 1080]
```

The common dispatcher still performs terminal-frame player-shot collision and
then increments the helper timer. The reconstruction preserves the queued
terminal draw before unlinking the inactive entity on the next update.

## Deferred Surface

- The shared `FUN_14007b010`/`FUN_140079e20` death-effect chain is represented
  by the runtime reward/death burst rather than the original effect-node list.
- Draw nodes are issued directly rather than through the original global
  mode-7 render queue.
