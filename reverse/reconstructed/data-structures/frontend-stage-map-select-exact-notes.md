# Frontend Stage / Map Select Exact Notes

This note records the state `0x04` facts used by `FrontendRuntime`. The primary
evidence is
`reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/1400d5d50_state_04_gameplay_update_candidate.c`,
with resource identities cross-checked against `resource-handle-map.md` and the
primary resource loader.

## State and timers

- `DAT_140e45274`: `0` stage selection, `1` difficulty/counter selection,
  `2` gameplay launch, `-1` return to setup.
- Input is enabled only when the state frame is greater than `0x3b`, the signed
  layer/launch timer is zero, and the state04 intro flag is zero.
- Stage movement uses signed `DAT_140e46014` and lasts 30 frames. The camera
  interpolation factor is `sin(counter * pi / 60)`.
- Stage-to-difficulty starts the signed layer timer at `+1`; difficulty-to-stage
  starts it at `-1`. Input remains blocked through the `+/-10` frame commit.
- Difficulty movement starts its animation counter at `+4` for right and `-4`
  for left. The counter-mode toggle starts its animation counter at `4`.
- Gameplay launch commits at `100` frames. Return to setup commits at `-50`.

The original input path also blocks confirm and cancel while the 30-frame
camera movement counter is nonzero. The special route stage id `10` does not
accept difficulty left/right input and bypasses the ordinary difficulty unlock
check on confirm.

## World nodes

The screen transform is:

```text
screen_x = 640 + node_x - camera_x
screen_y = 320 + node_y - camera_y
```

Only `screen_x` is culled, using the inclusive range `[-640, 1920]`.

| Stage id | X | Y |
|---:|---:|---:|
| 1 | 0 | 0 |
| 2 | 750 | -320 |
| 3 | 1500 | -320 |
| 4 | 2250 | -640 |
| 5 | 3000 | -640 |
| 6 | 3750 | -960 |
| 7 | 4500 | -960 |
| 8 | 5250 | -1280 |
| 9 | 6000 | 320 |
| 10 | 6750 | -320 |
| 11 | 7500 | 0 |
| 12 | 8250 | -320 |
| 13 | 9000 | -640 |
| 14 | 9750 | -640 |

The node Y position adds
`5 * sin((frame - stage_id * 40) * pi / 90)`. `StageFrame[0]` and
`StageFrame[1]` use `sin(frame * pi / 60)` as their scale for frames `0..29`,
then scale `1`. `MapMenu` begins its 12-frame sine scale-in at frame `30` and
`StageFrame2` at frame `35`.

## Node resource composition

Each visible stage is composed in this order:

1. `StageFrame[0]` at `(screen_x, screen_y)`, RGB `(128,128,128)`, alpha `255`.
2. `StageFrame[1]` at the same point, using the stage RGB table below and alpha
   `int(255 * 0.75)`, or `191`.
3. `MapMenu[stage_id - 1]` at `(screen_x, screen_y - 240)`.
4. `StageFrame2[stage_id - 1]` at `(screen_x, screen_y - 50)`.

The RGB table is indexed by the original stage id. Slot `0` is real data even
though the normal route starts at stage id `1`.

| Stage id | R | G | B |
|---:|---:|---:|---:|
| 0 | 255 | 255 | 255 |
| 1 | 128 | 255 | 255 |
| 2 | 255 | 255 | 128 |
| 3 | 255 | 128 | 192 |
| 4 | 128 | 128 | 255 |
| 5 | 128 | 128 | 128 |
| 6 | 192 | 128 | 255 |
| 7 | 128 | 255 | 255 |
| 8 | 255 | 128 | 128 |
| 9 | 64 | 64 | 64 |
| 10 | 128 | 128 | 255 |
| 11 | 128 | 255 | 255 |
| 12 | 255 | 128 | 128 |
| 13 | 255 | 128 | 255 |
| 14 | 255 | 255 | 128 |

The table is reconstructed in decompiled lines 136-168 and 179-183. The draw
path reads three 32-bit components at `stage_id * 0x0c` in lines 617-625.
The corresponding `.rdata` blocks occupy `0x14053b820..0x14053b928`.

## Stable overlay layout

| Element | Resource/frame | Position | Other |
|---|---|---:|---|
| Menu base | `MapMenu2[4]` | `(590,460)` | layer `0x50` |
| Difficulty | `MapMenu2[6+difficulty]` | `(640,530)` | layer `0x54` |
| Locked mark | `MapMenu2[12]` | `(640,530)` | fixed angle `0xf000` |
| Counter row | `MapMenu2[5]` | `(640,580)` | alpha `128` off, `255` on |
| Tips | `DifficultyTips[difficulty]` | `(850,450+wave)` | `wave=3*sin(frame*pi/90)` |
| Right difficulty arrow | `Effect_s[1]` | `(780-wave,530)` | scale `0.8`, angle `0` |
| Left difficulty arrow | `Effect_s[1]` | `(500+wave,530)` | scale `0.8`, angle `0x8000` |
| Counter arrow | `Effect_s[1]` | `(730,580+/-wave)` | scale `0.5` |
| Stage right arrow | `Effect_s[1]` | `(880+wave,320)` | angle `0` |
| Stage left arrow | `Effect_s[1]` | `(400-wave,320)` | angle `0x8000` |

For the last four rows, `wave=3*sin(frame*pi/30)`. The counter arrow uses fixed
angle `0xc000` while off and `0x4000` while on. Difficulty changes add a
four-frame sine pulse with amplitude `0.4`. The Counter timer normally leaves
its arrow at scale `0.5`, but rapid sequential input can overlap both timers:
positive difficulty motion adds `0.25*sin(counterTimer*pi/4)` while Counter is
off, and negative difficulty motion subtracts it while Counter is on. The
player stand is centered at `(200,480+6*sin(frame*pi/90))`, with alpha `128`.

Special route stage id `10` uses `MapMenu2[11]` and `DifficultyTips[5]` rather
than the ordinary difficulty-indexed frames.

## Deferred exact work

The following state04 behavior remains intentionally unimplemented rather than
filled with provisional content:

- Cases `2..7` of the per-stage eight-case draw loop: detailed stage result,
  score, rank, and value rows.
- Exact digit/help-level content and its save-backed availability checks.
- The precise result predicate and placement for special `MapMenu2[13]`.
- The long `DAT_140e46958` intro/highlight sequence and its selected-node alpha
  flashes after frame `120`.
- The launch/back overlay and prompt-helper effects beyond the shared frontend
  transition renderer.

The world coordinates, stage tint table, stable menu geometry, fixed rotations,
input gates, and primary signed timers above are resolved and should no longer
be treated as provisional.
