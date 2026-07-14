# Frontend state 0x08 enemy encyclopedia audit

Status: evidence-backed reconstruction of `FUN_1400b8890` at
`0x1400b8890`. The old generated name
`state_08_gallery_unlock_or_achievement_candidate` is misleading: this is the
enemy encyclopedia shown to the left of the gallery.

Primary evidence:

- `reverse/ghidra-or-ida/exports/decompiled-anchors/1400b8890_FUN_1400b8890.c`
- `reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/1401351a0_FUN_1401351a0.c`
- `reverse/ghidra-or-ida/exports/renamed-decompiled/1400ced90_load_primary_resources_candidate.c`
- `reverse/ghidra-or-ida/exports/renamed-decompiled/1400d0e50_load_secondary_localized_resources_candidate.c`
- `reverse/ghidra-or-ida/exports/frontend-state08-scalars.tsv`
- the extracted `re/gallery/EnemyList*.png` files

## High-level corrections

- The valid cursor range is one-based: enemy IDs `1..maximum`. Index `0` is a
  locked/unknown placeholder, not a selectable enemy. There are 103 selectable
  records even though both runtime arrays are naturally indexed as 104 slots.
- There is no persistent 104-element enemy unlock array and no enemy-viewed
  array in `save.dat`. `FUN_1400b8890` rebuilds a temporary 104-entry mask from
  stage records every frame.
- The four `EnemyList.png` frames per row are the four languages. They are not
  locked, unlocked, selected, and viewed variants.
- Confirm has no branch in state `0x08`. It must not play an enter/error sound
  or mutate a viewed bit.
- Right returns to gallery state `0x06` at gallery cursor `0`. It does not map
  the encyclopedia page to a gallery row.

## Save-backed availability

`FUN_1401351a0(stage, 0xffffffff)` returns a three-state stage status. Ghidra
gave it a `void` return type, but the value retained in `iVar1` is returned in
`EAX` and is consumed by `FUN_1400b8890`.

For stage `s > 0` and player/character slot `c = 0..2`, define:

```text
record = 0x84 + s * 0x258 + c * 0xc8
```

All offsets are relative to the start of the `0x2730`-byte `save.dat` block.
The helper scans four little-endian `int32` fields at `record + 0x00..0x0c`
and four at `record + 0x14..0x20`:

```cpp
int stageStatus(int stage) {
    int result = 0;
    if (stage <= 0) return result;
    for (int character = 0; character < 3; ++character) {
        const size_t record = 0x84 + stage * 0x258 + character * 0xc8;
        for (int difficulty = 0; difficulty < 4; ++difficulty) {
            if (readI32(record + 0x14 + difficulty * 4) > 0 && result == 0)
                result = 1;
            if (readI32(record + difficulty * 4) > 0)
                result = 2;
        }
    }
    return result;
}
```

State `0x08` only tests this result for `> 0`. Its temporary mask is equivalent
to the following (the original is unrolled in groups of 13):

```cpp
int maximum = 10;
constexpr int capAfterStage[11] = {
    10, 11, 22, 32, 41, 51, 61, 73, 82, 84, 103
};

for (int stage = 1; stage <= 10; ++stage)
    if (stageStatus(stage) > 0)
        maximum = capAfterStage[stage];

const bool firstStageGate = stageStatus(1) > 0;
for (int id = 0; id < 104; ++id)
    unlocked[id] = firstStageGate && id <= maximum;

// DAT_140e41b68 is save.dat + 0x58.
if (readI32(0x58) >= 9) {
    unlocked[83] = true;
    unlocked[84] = true;
    maximum = std::max(maximum, 84);
}
```

The resulting natural progression is:

| Evidence gate | Maximum cursor | Newly available IDs |
|---|---:|---:|
| no stage 1 status | 10 | none; IDs 1..10 are shown locked |
| stage 1 | 11 | 1..11 |
| stage 2 | 22 | 12..22 |
| stage 3 | 32 | 23..32 |
| stage 4 | 41 | 33..41 |
| stage 5 | 51 | 42..51 |
| stage 6 | 61 | 52..61 |
| stage 7 | 73 | 62..73 |
| stage 8 | 82 | 74..82 |
| `save.dat+0x58 >= 9` | at least 84 | 83, 84 only |
| stage 9 | 84 | all through 84 |
| stage 10 | 103 | 85..103 |

The `+0x58` field is the main sequential progression value used elsewhere to
unlock later title modes; it is not itself the complete encyclopedia cap.

Do not confuse the generic gallery notice arrays referenced near the end of
this function with enemy unlock state:

| Save offset | Count | Actual use in this function |
|---:|---:|---|
| `0x240c` (`DAT_140e43f1c`) | 20 `int32` | gallery picture/notice unlock overlay |
| `0x2470` (`DAT_140e43f80`) | 20 `int32` | gallery picture/notice viewed overlay |
| `0x24d4` | 50 `int32` | achievement unlocks; not read by state `0x08` |
| `0x259c` | 50 `int32` | achievement viewed bits; not read by state `0x08` |

Language is `DAT_140e441b4`, which is directly `save.dat + 0x26a4`: `0` is
Japanese, `1` English, `2` Simplified Chinese, and `3` Traditional Chinese.

## Input and state transitions

Input is disabled while `frame < 60` or while the signed transition counter is
nonzero. The directional repeat rule is: trigger at held count `1`, then at
counts `20, 28, 36, ...`. Up is accepted only while Down is not held, and vice
versa.

```cpp
if (upRepeat && !downHeld)
    cursor = cursor > 1 ? cursor - 1 : maximum;
if (downRepeat && !upHeld)
    cursor = cursor < maximum ? cursor + 1 : 1;
```

Every accepted move sets the selection-dirty flag, plays the ordinary select
SE, and therefore changes page automatically when a decade boundary is
crossed. There is no separate page-up/page-down input.

The visible page starts at:

```cpp
pageStart = cursor - (cursor - 1) % 10; // 1, 11, 21, ... 101
```

Ten candidate rows are visited, but rows with `id > maximum` are omitted. Thus
the final page at full completion contains only IDs `101..103`.

On stable entry (`frame == 60`) and after each cursor change, the original
clears the existing queued cue list and calls `FUN_14012e070` with sound/event
ID `0x1c2 + cursor` for an unlocked enemy, or fallback ID `0x1c2` for a locked
one. This is in addition to the ordinary select SE.

The lateral and cancel paths are exact:

- Entering from the left edge of Gallery sets state `0x08`, cursor `1`, frame
  `0`, and uses the 60-frame slide-in.
- Right (`DAT_140e467c0`) clears the queued cue list, sets cursor `0`, starts a
  positive slide counter at `1`, and at counter `60` switches to state `0x06`
  with gallery cursor `0` and frame `60`.
- Cancel (`DAT_140e467cc`) sets the transition counter to `-1`, writes the full
  `save.dat` block immediately, begins the tile wipe once the counter is below
  `-19`, and at `-50` switches to title state `0x02`, cursor `5`, frame `0`.
- Left and Confirm have no state-specific action.

## Resource frame semantics

Original load calls:

```text
EnemyList.png    : 416 frames, 4 x 104, each 320 x 40
EnemyListPic.png : 110 frames, 10 x 11, each 600 x 600
```

Both are split in row-major order.

For a list row with enemy ID `id`:

```cpp
const int frame = unlocked[id] ? 4 * id + language : language;
```

Frames `0..3` are four localized copies of the `????????` row. Frames `4..7`
are enemy ID 1, and so on through frames `412..415` for ID 103. Asset inspection
matches the language order above.

For the large picture:

```cpp
const int frame = unlocked[cursor] ? cursor : 0;
```

Frames `104..109` are unused transparent grid padding. Frame `0` is the locked
placeholder. Direct picture frames `11, 22, 32, 41, 50, 51, 59, 61, 72, 73,
82, 84, 103` are transparent; the original deliberately reconstructs those
enemies from animated gameplay sprite components after drawing the transparent
tile.

## Exact base layout

Coordinates are for the original 1280 x 720 surface. `xOffset` is added to all
state-specific content:

```cpp
if (frame < 60)
    xOffset = 1280.0f * sin(frame * pi / 120.0f) - 1280.0f;
else if (transition > 0)
    xOffset = -1280.0f * sin(transition * pi / 120.0f);
else
    xOffset = 0.0f;
```

| Element | Anchor | Position | Scale | RGB | Alpha |
|---|---|---|---:|---:|---:|
| `EnemyListWindow.png` | top-left | `(xOffset, 0)` | `1,1` | `255` | `255` |
| list row `j=0..9` | top-left | `(xOffset + 200, 90 + 50*j)` | `1,1` | selected `255`, otherwise `128` | `255` |
| `EnemyListPic[frame]` | centered | `(xOffset + 815, 340)` | `1,1` | `255` | `255` |
| right-return arrow | centered | `(1200 + 8*sin(blink*pi/40), 360)` | `1,1` | `255` | `255` |

The unselected rows are darkened through RGB modulation; they are not made
half-transparent. Locked rows still use full row modulation according to
selection and simply substitute the localized `????????` frame.

## Transparent-picture composite IDs

All component positions below also receive `xOffset`. Unless stated otherwise,
the nodes are centered, scale `1,1`, RGB `255`, alpha `255`, and use frames from
the gameplay medium-enemy graph bank. `anim(step, [frames...])` means the exact
`FUN_1400c9580(frame, 0, step, count, frames...)` selection.

| ID | Animated components `(x,y): animation` |
|---:|---|
| 11 | `(715,240): anim(7,[0,1,2])`; `(915,240): anim(5,[5,6,7])`; `(815,440): anim(5,[8,9])` |
| 22 | `(715,240): anim(5,[10,11,12])`; `(915,240): anim(5,[15,16,17])`; `(815,440): anim(5,[18,19])` |
| 32 | `(715,340): anim(7,[20,21,22])`; `(915,340): anim(5,[23,24])` |
| 41 | `(715,240): anim(7,[25,26,27])`; `(915,240): anim(5,[30,31,32])`; `(715,440): anim(5,[35,36,37])`; `(915,440): anim(5,[38,39])` |
| 50 | `(715,240): anim(7,[40,41,42,41])`; `(915,240): anim(5,[45,46,47,46])`; `(815,440): anim(5,[48,49])` |
| 51 | `(715,340): anim(7,[50,51,52])`; `(915,340): anim(5,[55,56,57])` |
| 59 | `(715,240): anim(5,[60,61,62])`; `(915,240): anim(7,[65,66,67])`; `(815,440): anim(5,[68,69])` |
| 61 | `(715,240): anim(6,[70,71,72,71])`; `(915,240): anim(5,[75,76,77])`; `(815,440): anim(5,[78,79])` |
| 72 | `(715,340): anim(5,[80,81,82,83,84,85,87,86,87,86,85,84,83,82,80,81])`; `(915,340): anim(5,[88,89])` |
| 73 | `(715,340): anim(5,[96,95,94,93,92,90,91,90,91,92,93,94,95,97,96,97])`; `(915,340): anim(5,[98,99])` |
| 103 | `(715,240): anim(5,[145,146,147,146])`; `(915,240): anim(5,[150,151,152,153,152,151])`; `(715,440): anim(5,[154,155,156,157])`; `(915,440): anim(5,[158,159])` |

IDs 82 and 84 also use non-contiguous component graph handles:

- ID 82 uses top groups centered around `x=685` and `x=945`. Each group has
  paired components at `center +/- 10, y=145`, a static component at
  `(center,160)`, and an animated component at `(685,160):
  anim(6,[110,111,112,111])` or `(945,160): anim(5,[113,114])`. The paired
  rotations are `+/- 2000*sin(frame*pi/60)` fixed-angle units. Its lower group
  is `(715,340): anim(6,[100,101,102,101])`, `(915,340):
  anim(5,[105,106,107])`, and `(815,520): anim(5,[108,109])`.
- ID 84 has four paired groups centered at `x=685/945`, with pair positions
  `center +/- 24` at `y=220` and `y=420`. Their rotations are
  `+/- 3000*sin(frame*pi/24)` and their horizontal scale is
  `0.7 + 0.3*sin(frame*pi/24)`. Center animations are `(685,240):
  anim(5,[115,116,117,116])`, `(945,240): anim(5,[120,121,122])`,
  `(685,440): anim(5,[123,124])`, and `(945,440): anim(5,[127,128])`.

The paired negative-rotation component also sets the render-node mirror flag.
Keeping these composites is necessary: using only `EnemyListPic.png` produces
an empty right panel for all 13 IDs listed above.
