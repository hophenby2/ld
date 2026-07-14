# Help Mode Exact Notes

Status: exact value resolution and common marker satellite consumption are
implemented. Replay serialization and the original result-state routing are
documented but remain outside the current runtime surface.

## Saved value and automatic record

`DAT_140e44198` is `save.dat + 0x2688` and has seven menu values:

| Saved value | Runtime meaning |
|---:|---|
| `0` | Auto |
| `1..5` | Explicit Help level |
| `6` | Off |

For Auto, `FUN_140135290(stageIndex, setupGroup, difficulty)` reads:

```text
save.dat + 0x00ac + ((stageIndex * 3 + setupGroup) * 50 + difficulty) * 4
```

The signed record value maps to a level as follows:

| Record | Effective level |
|---:|---:|
| `< 3` | `0` |
| `3..5` | `1` |
| `6..7` | `2` |
| `8..9` | `3` |
| `10..11` | `4` |
| `>= 12` | `5` |

Explicit values `1..5` are returned unchanged and value `6` returns `0`.
Stage index `14` is a final override and always returns `0`.

Evidence: `140135290_FUN_140135290.c:11-49`. `DAT_140e41bbc` is
`0xac` bytes after the save block base `DAT_140e41b10`.

`StageRuntimeConfig::helpAutoProgress` carries the already-selected record from
the frontend. `StageRuntime::effectiveHelpLevel()` implements the exact
thresholds without conflating Auto (`0`) and Off (`6`).

## Gameplay initialization and replay

`FUN_1401121f0` initially copies the saved menu value into `DAT_140e452f0`.
When the saved value is Auto, route mode `0` resolves the current stage record
and route mode `1` resolves record index `DAT_140e41abc + 11`. Other route modes
leave the snapshot at zero.

`FUN_140135290` uses this snapshot instead of live save/menu state when
`DAT_140e41b00 == 1` (replay/demo mode). The snapshot is also written to replay
data by `FUN_140114580`. The reconstruction does not yet expose replay playback
or replay header serialization, so this snapshot boundary is not fabricated.

Evidence: `1401121f0_FUN_1401121f0.c:38-47`,
`140135290_FUN_140135290.c:12-43`, and
`140114580_replay_or_save_handler_candidate_C.c:299-313`.

## Common marker consumption

At marker timer `0x14`, `FUN_140082d90` creates type-`0x09` children with HP
`3000`; the number of children is the effective Help level:

| Marker type | Route `0` | Route `1` | Other routes |
|---:|---:|---:|---:|
| `0x06` | Help level | Help level | `0` |
| `0x07` | Help level | `0` | `0` |
| `0x08` | `0` | `0` | `0` |

The helper contains no type-`0x11` creation. The reconstruction therefore
removes the previous fixed pair of type-`0x09` satellites and the two temporary
type-`0x11` children. The common `0x06..0x09` update route now applies in every
implemented stage rather than only Stage 1.

`FUN_140083db0` resolves each type-`0x09` parent by entity id, seeds its orbit
angle from `entityId + 0x6f`, advances the angle by `0x200`, and removes the
child through the type-7 reward path once the parent expires. It does not emit
enemy bullets while the parent is alive, so the previous 90-frame generic shot
was removed.

Evidence: `140082d90_FUN_140082d90.c:68-141` and
`140083db0_FUN_140083db0.c:31-108`.

## Result route predicate

`FUN_140135330` only considers the special result route when route mode is `1`
and `DAT_140e4680c != 0`. For ordinary route stages it returns true only when
the effective Help level for record index `DAT_140e41abc + 11` is zero. Stage
`10` uses a separate record at `save.dat + 0x181c +
(setupGroup * 50 + difficulty) * 4`, but applies the same Auto thresholds and
explicit-value folding.

The caller routes a true result to main state `0x10`; false goes to `0x23`.
The reconstructed app currently exposes only a single `stageComplete()` boolean
and directly returns to the frontend. It has no equivalents for
`DAT_140e4680c`, result states `0x10/0x23`, or the stage-10 record, so no result
predicate is guessed into `StageRuntime` yet.

Evidence: `140135330_result_route_predicate_candidate.c:11-60` and
`1400fcd20_state_2c_auto_gameplay_branch_candidate.c:695-711`.
