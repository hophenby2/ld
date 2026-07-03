# Stage Spawn Type Family Notes

Status: aggregate notes from `stage-spawn-schedule.csv` and `stage-spawn-type-matrix.csv`. These are numeric spawn/entity type families, not confirmed enemy or object names.

## Core observations

`stage_spawn_dispatch_candidate(type, duration_or_lifetime, x, y, ...)` is called by the per-stage update handlers. The first argument clusters strongly by stage, suggesting the type id space is grouped by stage/theme or entity family.

Supporting files:

- `stage-spawn-schedule.csv` — raw extracted call rows, including nearby decompiler frame conditions.
- `stage-spawn-schedule.md` — readable raw schedule by stage.
- `stage-spawn-type-matrix.csv` — count matrix of spawn type by stage.
- `stage-spawn-type-summary.md` — matrix plus first/last examples for each type.
- `stage-spawn-dispatch-map.csv` — full `type -> case index -> case block -> default fields` reconstruction from the `stage_spawn_dispatch_candidate` jump table.
- `stage-spawn-dispatch-used-types.csv` / `.md` — dispatch map restricted to spawn types seen in stage schedules.

## Stage-to-type family map

| Stage | Dominant spawn type families | Notes |
|---:|---|---|
| `00` | `0x00..0x05` plus many non-spawn helper calls | Special tutorial/intro-like handler; also uses many prompt/HUD helpers and direct object allocation. |
| `01` | `0x0a..0x10`, with common `0x0b` projectile-like repeats | First regular dense schedule; type `0x0b` appears repeatedly with random x/y edges. |
| `02` | `0x19..0x20`, plus common `0x0b`, `0x0d` | Strong type block `0x19..0x20`; later reused by stage `09` and stage `08`. |
| `03` | `0x25..0x2e`, plus common `0x07`, `0x08`, `0x0b` | Strong type block `0x25..0x2e`; reused by stage `08` and lightly by stage `09`. |
| `04` | `0x35..0x3f` | Strong self-contained type block; heavily uses `0x35`/`0x38`. |
| `05` | `0x44..0x4f` | Strong self-contained type block; type `0x46` dominates this stage. |
| `06` | `0x57..0x5f`, plus common `0x0b..0x0f`, `0x1a` | Strong type block `0x57..0x5f`; type `0x57` and `0x58` dominate. |
| `07` | `0x70..0x77`, plus common `0x07`, `0x08`, `0x25`, `0x26` | Strong type block `0x70..0x77`; type `0x70` dominates. |
| `08` | Broad composite: `0x0a..0x10`, `0x19..0x20`, `0x25..0x2e`, `0x35..0x3f`, `0x44..0x4a`, `0x57..0x5f`, `0x70..0x73`, `0x95..0xa4` | Longest handler; appears to remix many earlier stage families plus its own `0x95..0xa4` block. Candidate for boss/rush/final composite stage, pending resource/text evidence. |
| `09` | Reuses many previous families: `0x0b..0x0f`, `0x19..0x1b`, `0x25..0x2b`, `0x35..0x3a`, `0x44..0x48`, `0x57..0x58`, `0x74`, `0x9b..0xa4` | Composite/reuse-heavy schedule; likely late-stage or challenge remix. |
| `10` | `0xfa..0x104`, plus common `0x06..0x08` | Distinct high-numbered type block; special/final-stage-like handler with no intro banner extraction in the raw schedule. |

## Dispatch map findings

`stage_spawn_dispatch_candidate @ 0x14007b710` uses a two-level table:

1. A byte index table at `0x14007c098`, indexed directly by spawn type `0..0x104`.
2. A case offset table at `0x14007bfcc`, indexed by that byte case id.

This means many numeric spawn types intentionally share the same case block/default behavior. For example:

- Types `0` and `1` both map to case `0` / target `0x14007b741`.
- Types `2`, `3`, and `4` all map to case `1` / target `0x14007b771`.
- Common type `0x0b` and type `0x0d` both map to case `5` / target `0x14007bb1f`.
- Several late composite/final types (`0xfe`, `0x100`, etc.) reuse earlier case `18` / target `0x14007bf24`.

The reconstructed fields currently extracted from objdump are provisional:

| Extracted field | Likely meaning |
|---|---|
| `entity_kind/r8d` | Internal behavior/render kind passed onward to `stage_entity_spawn_candidate`. |
| `field_38` | Default lifetime/timing/size-like field placed on the stack before the spawn call. |
| `const` | Float/double constants selected by a case block, likely scale/speed/alpha presets. |
| `tail` | Shared tail block used to finish argument setup before `stage_entity_spawn_candidate`. |

The next step is to align `entity_kind/r8d` and `field_38` with the `stage_entity_spawn_candidate` node layout and downstream entity update switch.

## Cross-stage common types

| Type family | Evidence |
|---|---|
| `0x07`, `0x08` | Appears once or twice in many stages, likely common large/background or stage-control entities. |
| `0x0b` | Most common spawn type overall: 74 calls across stages `01..09`, often with random edge/position arguments. Candidate common small enemy/projectile family. |
| `0x0c..0x0f` | Common early type family reused across several stages. |
| Stage-local blocks | Most stage families are contiguous blocks: `0x19..0x20`, `0x25..0x2e`, `0x35..0x3f`, `0x44..0x4f`, `0x57..0x5f`, `0x70..0x77`, `0x95..0xa4`, `0xfa..0x104`. This suggests `stage_spawn_dispatch_candidate` maps type ids to specialized enemy/object constructors or behavior initializers. |

## Next evidence needed

1. Review `stage_spawn_dispatch_candidate` switch and downstream case functions to map each type id to actual constructor/update logic.
2. Cross-reference graphics/resource ids touched by those constructors against `graphics-table.csv` / resource filenames.
3. Only after resources confirm the stage themes, rename `stage_XX_gameplay_update_candidate` and type families away from numeric names.
