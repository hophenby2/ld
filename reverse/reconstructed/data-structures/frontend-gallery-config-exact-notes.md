# Frontend Gallery and Config Exact Notes

Evidence anchors:

- `FUN_1400b4c60`: state `0x06`, gallery list
- `FUN_1400b5c70`: state `0x07`, achievement grid
- `FUN_1400b8890`: state `0x08`, enemy encyclopedia
- `FUN_1400ffc00`: state `0x0a`, top-level options
- `FUN_140100e00`: state `0x0b`, control/help submenu
- `FUN_1401019e0`: state `0x0c`, game configuration
- `FUN_140102ae0`: state `0x0d`, key configuration
- `FUN_1400dacb0`: controller/keyboard prompt handle mapper

## State identity and resources

State `0x07` is the 50-entry achievement grid, not a gallery detail page. The
grid is 10 columns by 5 rows. `Achievement.png` has five `100x100` frames; the
fifth frame is the selection overlay. The executable's icon-frame table at
`0x140538a10` is transcribed in `frontend_runtime.cpp`.

Its input gate and lateral transition are both 60 frames. Moving left from a
column-zero cell maps row `r` back to Gallery cell `min(19, r*4+3)` and slides
the grid to the right before committing state `0x06`. Ordinary Confirm input
has no branch; only the separately gated final cell can enter the still
unreconstructed state `0x30`, so the reconstruction no longer emits synthetic
Enter/Error sounds on other achievement cells.

State `0x08` is the enemy encyclopedia. `EnemyList.png` is divided as 4 columns
by 104 rows (`416` frames of `320x40`). The four columns are Japanese, English,
Simplified Chinese, and Traditional Chinese. The selected page starts at
`selected - (selected - 1) % 10` and contains ten entries. `EnemyListPic.png`
is divided into 110 `600x600` frames; frame 0 is the locked/no-data image and
the enemy index directly selects the remaining frames.

Verified scalar layout values:

| Address | Value | Use |
| --- | ---: | --- |
| `0x14053ad2c` | `110.0f` | achievement row/column step |
| `0x14053ad50` | `130.0f` | achievement first-row y |
| `0x14053ad70` | `150.0f` | achievement odd-row x |
| `0x14053aca8` | `40.0f` | alternating-row x offset |
| `0x14053acbc` | `50.0f` | enemy-list row step |
| `0x14053ad10` | `90.0f` | enemy-list first-row y |
| `0x14053adb4` | `200.0f` | enemy-list x |
| `0x14053af50` | `815.0f` | enemy picture x |
| literal | `340.0f` | enemy picture y |
| `0x14053acac` | `42.0f` | key-config row step |
| `0x14053ad20` | `102.0f` | key-config first-row y |

## Save/config layout

Confirmed `save.dat` fields used by these states:

| Offset | Count | Meaning |
| --- | ---: | --- |
| `0x240c` | 20 ints | gallery unlocked |
| `0x2470` | 20 ints | gallery viewed |
| `0x24d4` | 50 ints | achievements unlocked |
| `0x259c` | 50 ints | achievements viewed |
| `0x267c` | 1 int | BGM volume, `0..10` |
| `0x2680` | 1 int | SE volume, `0..10` |
| `0x2684` | 1 int | control-mode enable |
| `0x2688` | 1 int | help-mode value, `0..6` |
| `0x26a4` | 1 int | language, `0..3` |
| `0x26a8` | 1 int | data-window enable |
| `0x26bc` | 1 int | detected control device, `0..5` |
| `0x26c0` | 11 ints | keyboard action bindings |
| `0x26f0` | 11 ints | controller action bindings |

`config.dat` is exactly seven little-endian `int32` values. State `0x0c`
edits them as: full screen toggle, frame-rate index `0..2`, VSync toggle,
visibility toggle, text-animation toggle, Like style toggle, and sound backend
index `0..3`. The Default row resets only entries 1 through 5, preserving full
screen and sound backend, exactly as the original handler does.

Startup consumes Full Screen and VSync before `DxLib_Init`. Sound modes `1..3`
map to `SetEnableWASAPIFlag(1,0,-1,44100)`,
`SetEnableWASAPIFlag(1,1,-1,44100)`, and
`SetEnableWASAPIFlag(0,1,-1,44100)`; mode `0` leaves backend selection to
DxLib. Frame-rate indices `0..2` advance game logic every one, two, or three
display loops, matching the 60/30/20 dispatcher branches. The reconstruction
now applies these paths. Text Animation still depends on the unported dialogue
runtime and remains an explicit configuration gap.

## Options and key-config input semantics

States `0x0a..0x0d` accept input after frame `0x1f`. A repeated direction is
accepted only while its opposite direction is completely released; testing
only the opposite repeat pulse is not equivalent. Vertical and horizontal
commands are evaluated independently, then the shared latch suppresses Confirm
and Cancel after either direction was accepted. Confirm therefore wins over
Cancel on command rows when no direction ran first. State `0x0d` is the
exception to the other submenu return animations: its Back-row Cancel starts
the same positive 50-frame wipe as Confirm. `Error.wav` is played at
`SE volume * 0x14`; the ordinary Select/Enter/Cancel sounds use `* 0x19`.

Keyboard capture scans only the 100 DirectInput codes in the local table used
by `FUN_1400dacb0`; unsupported keys remain ignored. Conflict replacement is
limited to the original three binding groups (`0..3`, `4..5`, and `6..10`).
Controller capture rejects the four direction bits, scans the 28 button masks
from `0x10` through `0x80000000`, and swaps conflicts within groups `4..5` or
`6..10`. Both scan loops continue after a match: when several supported inputs
are held, each assignment and conflict swap runs in table order, leaving the
last match as the selected binding. Capture is armed only after the bound menu
action used to enter it is released; unrelated unbound inputs do not hold the
latch. The eight-frame post-capture lock is keyboard-only. Generic controller
family `0` uses fixed prompt frames by action row; families `1..4` map the
current button mask into their 15-frame row. The reconstructed menu now follows
these boundaries and uses only the original prompt sheets, with no synthetic
text fallback.

At transition commit, states `0x0a`, `0x0b`, and `0x0d` write the `0x2730`-byte
`save.dat` block. State `0x0c` writes only the seven-int `config.dat` block.
Loading and saving the two files are independent; a bad save block must not
prevent the system configuration from being loaded or persisted. Both paths
write back to the same `<asset-root>/save` directory used during startup, even
when graphics are loaded from DXArchive logical paths.

The thirteen encyclopedia entries whose static picture is transparent are
composited from the original `Boss.png` frames at runtime. Their unlock bounds,
localized names, page behavior, and portrait animation are all evidence-backed.

## Gameplay configuration handoff

The frontend gameplay request now carries the EquipMenu Auto/Manual Fever
value, Data Window flag, SE volume, reward Visibility, Like Style, Help Mode,
and the current Help Auto progress record into `StageRuntimeConfig`. The Auto
record is the signed `int32` at
`0xac + ((stage * 3 + setupGroup) * 50 + difficulty) * 4` in `save.dat`. The Data
Window option gates only the left `FUN_1400c4bb0` panel and only when
`routeMode != -1`; it does not suppress the right gameplay HUD.  This matches
the call gate in `FUN_1400c2860` rather than the earlier whole-HUD
interpretation.
