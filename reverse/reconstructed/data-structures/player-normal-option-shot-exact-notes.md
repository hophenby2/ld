# Player Normal / Option Shot Exact Port Notes

Status: exact constructor decision tree from `FUN_14010db70`, player input and
movement state from `FUN_140106be0`, the evidence-backed option-node formations
from `FUN_14010cc90`, and type `8..10` shot tracking from `FUN_140109780` /
`FUN_140134420`.

## Configuration mapping

The state-03 setup menu proves the following mapping:

| Original global | Reconstruction field | Meaning in these helpers |
|---|---|---|
| `DAT_140e445c0` | `StageRuntimeConfig::setupGroup` | Three-way player/setup group (`0..2`). |
| `DAT_140e445c4` | `optionSlots[0]` | Binary option 0. |
| `DAT_140e445c8` | `optionSlots[1]` | Binary option 1. |
| `DAT_140e445cc` | `optionSlots[2]` | Binary option 2; not read by `FUN_14010db70`. |
| `DAT_140e445d0` | `optionSlots[3]` | Four-way stance/style (`0..3`). |

Evidence: `1400d4610_state_03_stage_start_init_candidate.c:643-660` and
`:683-700`. `routeMode` corresponds to the separate `DAT_140e41928`; it must
not be used as `DAT_140e445c0`.

`setupGroup`, Control Mode (`save.dat +0x2684`), and Help Mode
(`save.dat +0x2688`) are carried through the frontend gameplay request and
`StageRuntimeConfig`. Help Mode does not alter `FUN_140106be0` movement or shot
cadence; its recovered `FUN_140135290` level resolution and common marker
satellite consumption are documented in `help-mode-exact-notes.md`.

## Input, focus, and movement

The runtime now preserves the original `DAT_140e44640/44/48/50` state as the
shot timer, focus flag, signed focus-transition counter, and focus-hold timer.
The transition counter starts at `0x20`, matching `FUN_1400f6c40`.

- Control Mode `1` uses action `9` directly for low speed. Holding action `6`
  or `8` advances the shot timer continuously; releasing finishes the current
  five-frame cadence before resetting.
- Other Control Mode values implement the Arcade input window. A press of
  action `6` or `8` starts a minimum `0x10`-frame shot sequence. Holding Shoot
  past 11 frames enables low speed. Rapid-Fire seeds the focus timer at `8`
  when held with Shoot on its first frame, exactly as `FUN_140106be0` does.
- Volleys occur when `shotTimer % 5 == 1`, matching the original call site for
  `FUN_14010db70`.

After all six constructors, a normal volley plays `Shot1.wav` at
`SE volume * 12`; an enhanced volley plays `Bomb6.wav` at `SE volume * 16`.

Movement uses the fixed eight direction angles written by `FUN_140106be0` and
the recovered high/low-speed pairs: group 0 `7.5/4.0`, group 1 `7.9/4.1`, and
group 2 `8.3/4.2`. Horizontal displacement retains the original `1.2` factor.
The `FUN_1401346a0(position, 4)` bounds are represented as
`x/6 + 4 .. x/6 + 596` and `4 .. 716` after each movement step.

## Main pair

`FUN_14010db70:41-55` creates two shots at player x `+/-20`, player y `-30`,
angle `0xc000`:

| State | Type | Speed | Damage | Radius |
|---|---:|---:|---:|---:|
| `DAT_140e44658 == 0 && DAT_140e45d18 >= 0` | `0` | `25` | `130` | `30` |
| otherwise | `1` | `40` | `150` | `60` |

A ready positive gauge is still the type-0 path. A negative gauge/cooldown or
the separate `DAT_140e44658` timer selects type 1.

## Option constructor tree

All four option nodes use the same constructor result for a volley. The shot
starts at `node_position + direction(node_angle) * muzzle_offset`, and its
movement angle is the node angle (`FUN_14010db70:60-71`, `:199`).

Unfocused (`DAT_140e44644 == 0`):

| Branch | Base stance | Powered stance | Enhanced |
|---|---|---|---|
| group `0`, slot 0 = `1` | type `8`, damage `25` | type `9`, damage `30` | type `10`, damage `35` |
| every other configuration | type `2`, damage `50` | type `3`, damage `60` | type `4`, damage `70` |

Base stance is style `0/2`; powered stance is style `1/3`.

Focused (`DAT_140e44644 != 0`):

| Branch | Base stance | Powered stance | Enhanced |
|---|---|---|---|
| group `1`, slot 1 = `1` | type `8`, damage `45` | type `9`, damage `54` | type `10`, damage `63` |
| every other configuration | type `5`, damage `50` | type `6`, damage `60` | type `7`, damage `70` |
| group `0`, slot 1 = `0` override | type `5`, damage `45` | type `6`, damage `54` | type `7`, damage `63` |

Base stance is style `0/1`; powered stance is style `2/3`.

The common motion parameters are:

| State | Speed | Muzzle offset | Radius |
|---|---:|---:|---:|
| Base | `25` | `40` | `30` |
| Powered | `30` | `50` | `45` |
| Enhanced | `40` | `60` | `60` |

The literals come from `player-shot-scalars.tsv`. Damage/type branches are at
`FUN_14010db70:73-197`.

## Option nodes

The runtime now stores four persistent option positions and angles rather than
inventing per-volley anchors. It ports these `FUN_14010cc90` rules:

- the static offset/angle tables loaded at lines `155-227`;
- the group-1 radial and group-2 wide unfocused formations at lines `228-350`;
- the evidence-backed focused no-target formations at lines `352-509`;
- position convergence by `0.25` and angle convergence by
  `abs(delta) / 10 + 0x80` at lines `510-555`.

## Type 8..10 tracking

During ages `0..59`, moving player-side shot types `8..10` select the nearest
active, targetable enemy accepted by the bounds and radius tests recovered from
`FUN_140134420`:

- group `0` approaches the target by `(age + 16) * 0x20` angle units;
- group `1` approaches it by `0x200` angle units;
- group `2` does not retarget.

Group-0 drawing adds `age * 0x400` to a separate draw angle. The movement angle
is left untouched, matching `FUN_140109780` rather than turning the visual spin
into additional homing rotation. Target angles use the original float-delta,
double-`atan2`, truncation-toward-zero conversion from `FUN_140134420`.

## Still-unrepresented original state

- `DAT_140e44658` has a runtime field (`shotVariant`) but its exact producer and
  countdown are not yet ported.
- `DAT_140e4462c[4]` stores per-option target entity IDs for focused group 0.
- `DAT_140e445e0/e4` store a shared moving target anchor for focused group 2.

For those dynamic targeting paths the port keeps the exact no-target formation;
it does not invent a replacement target-selection policy.
