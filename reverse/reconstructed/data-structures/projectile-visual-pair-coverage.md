# Projectile Visual Pair Coverage

Status: first-pass spawn-call coverage that joins literal projectile constructor calls with the `Bullet.png` visual selector map. Counts are raw decompiled-export counts and include duplicated export sets, so use them as signal strength rather than exact unique call-site totals.

## Method

Scanned decompiled exports under `reverse/ghidra-or-ida/exports/**/*.c` for calls with literal first two arguments:

```c
FUN_14006c2f0(visual_selector_or_variant, projectile_id, ...)
FUN_1400709b0(visual_selector_or_variant, projectile_id, ...)
```

Then joined the raw argument pair to `bullet-frame-visual-map.csv` via `FUN_140070250` selector behavior. The generated CSV headers predate the constructor correction below and must be read with their first two semantic labels swapped.

Generated machine-readable files:

- `projectile-visual-pair-calls.csv` — raw literal call records.
- `projectile-visual-pair-coverage.csv` — aggregated `(projectile_id, visual_selector)` coverage with representative helper files and joined Bullet.png frame labels.

## Important interpretation caveat

The first projectile constructor argument is stored at `ProjectileNode +0x08`. In most update helpers it is passed directly to `FUN_140070250` as the bullet visual selector, while the second argument at `+0x0c` is the movement/update ID. Some scripted helpers also inspect the first value as a subpattern/owner/phase variant. See `projectile-runtime-exact-audit.md` for the direct constructor and dispatcher evidence.

`FUN_140070250` explicitly handles visual selectors `0x00..0x14`. For observed selector values above `0x14`, the current decompilation leaves the draw helper's default graph as `DAT_140e451c0`, so those projectiles likely render as the default magenta small pellet unless another not-yet-seen path rewrites `node->variant_or_owner` before drawing.

This makes high selector values such as `0x1f`, `0x20`, `0x21`, etc. strong candidates for “variant/subpattern values that still draw with default frame 0.”

## Coverage summary

- Literal constructor calls found: `1195` raw export occurrences.
- Distinct `(projectile_id, visual_selector)` pairs: `109`.
- Observed selector values: `0x0,0x1,0x2,0x3,0x4,0x7,0x8,0x9,0xa,0xb,0xc,0xd,0xe,0xf,0x10,0x11,0x12,0x17,0x18,0x19,0x1c,0x1f,0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x28,0x29,0x2a,0x2b,0x2c,0x2d,0x2e,0x2f,0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x39,0x3a,0x3b,0x3c`.

## Most common visual pairings

| Projectile ID | Visual selector | Raw count | Bullet.png visual | Representative interpretation |
|---:|---:|---:|---|---|
| `0x04` | `0x00` | 119 | frame 0, magenta thin oval / small pellet | Very common child/fan projectile in default visual. |
| `0x07` | `0x00` | 75 | frame 0, magenta thin oval / small pellet | Common fast aimed/paired shot in default visual. |
| `0x09` | `0x00` | 72 | frame 0, magenta thin oval / small pellet | Delayed-retarget projectile commonly appears as default pellet. |
| `0x0c` | `0x00` | 72 | frame 0, magenta thin oval / small pellet | Homing/steering projectile commonly appears as default pellet. |
| `0x03` | `0x00` | 70 | frame 0, magenta thin oval / small pellet | High-use aimed/alternating projectile in default visual. |
| `0x05` | `0x00` | 68 | frame 0, magenta thin oval / small pellet | Common aimed/fan projectile in default visual. |
| `0x02` | `0x00` | 55 | frame 0, magenta thin oval / small pellet | Common scripted spread/ring projectile in default visual. |
| `0x0b` | `0x00` | 55 | frame 0, magenta thin oval / small pellet | Paired/retargeting shots, usually default visual. |
| `0x0d` | `0x00` | 52 | frame 0, magenta thin oval / small pellet | Frequent final/boss fan projectile, often default visual. |
| `0x08` | `0x00` | 38 | frame 0, magenta thin oval / small pellet | Reflecting/bounce projectile often default visual. |
| `0x0a` | `0x00` | 31 | frame 0, magenta thin oval / small pellet | Heavy pattern shots often default visual. |
| `0x00` | `0x00` | 24 | frame 0, magenta thin oval / small pellet | Basic aimed shot. |

Dominant pattern: the gameplay code frequently varies `projectile_id` while keeping `visual_selector=0`, so many mechanically different bullets render with the same default small magenta pellet.

## High-signal non-default visual pairings

| Projectile ID | Visual selector | Raw count | Bullet.png visual | Notes |
|---:|---:|---:|---|---|
| `0x0d` | `0x02` | 23 | frame 2, magenta large orb | Scripted emitter helper and several stage helpers use `id=0x0d` as a larger orb-like fan/child. |
| `0x0d` | `0x01` | 16 | frame 1, blue thin oval / small pellet | Blue/default-shape variant of common final/boss fan projectile. |
| `0x0d` | `0x04` | 14 | frame 4, magenta small bead | Smaller bead version of `id=0x0d`; seen in `FUN_14006ce40` emissions and stage helpers. |
| `0x03` | `0x01` | 13 | frame 1, blue thin oval / small pellet | Blue small-pellet version of common `id=3`. |
| `0x03` | `0x07` | 13 | frame 7, blue horizontal capsule / bar | `id=3` can render as a blue bar/capsule in some patterns. |
| `0x09` | `0x02` | 13 | frame 2, magenta large orb | Delayed-retarget behavior with large orb visual. |
| `0x04` | `0x0a` | 12 | frame 20, magenta long capsule / long oval | `id=4` as long capsule in spread wrapper calls. |
| `0x0c` | `0x01` | 12 | frame 1, blue thin oval / small pellet | Homing/steering with blue small-pellet visual. |
| `0x08` | `0x02` | 12 | frame 2, magenta large orb | Reflecting/bounce behavior with large orb visual. |
| `0x04` | `0x0f` | 10 | frame 25, blue small diamond / shard | Common child emission from homing/common helpers; visually a blue small diamond. |
| `0x08` | `0x04` | 9 | frame 4, magenta small bead | Reflecting/bounce behavior with small bead visual. |
| `0x0d` | `0x03` | 9 | frame 3, blue large orb | Blue large-orb version of `id=0x0d`. |
| `0x11` | `0x0c` | 9 | frame 22, magenta arrowhead / dart | Rare timed/special projectile rendered as magenta arrowhead. |
| `0x0d` | `0x0b` | 8 | frame 21, blue long capsule / long oval | Blue long-capsule final/boss-style projectile. |
| `0x05` | `0x0f` | 7 | frame 25, blue small diamond / shard | Homing helper child path emits `id=5, variant=0x0f`. |
| `0x02` | `0x09` | 5 | frame 9, blue wide shard / rice | Scripted spread/ring behavior with wide blue shard visual. |
| `0x04` | `0x10` | 4 | frame 26, magenta long horizontal bar / laser shard | Special `id=4` visual using laser-like shard. |
| `0x04` | `0x11` | 3 | frame 4 plus white pulse overlay | `FUN_14006ce40 id=0x3c` random sparkle/emitter child. |
| `0x02` | `0x12` | 2 | frame 5 plus white pulse overlay | Rare special bead-with-pulse visual. |

## Selector-overflow / likely subpattern values

These values are observed as constructor arg2 but are not explicitly handled by `FUN_140070250`:

- Frequent examples: `(id=0x02, selector=0x1f)`, `(id=0x03, selector=0x20)`, `(id=0x03, selector=0x21)`, `(id=0x03, selector=0x22)`.
- Current draw-helper behavior implies they render with the default frame 0 unless changed before drawing.
- This supports treating `ProjectileNode +0x08` as `visual_selector_or_variant`, not just `visual_selector`.

High-value overflow pairs from raw coverage:

| Projectile ID | Arg2 value | Raw count | Current draw implication | Likely meaning |
|---:|---:|---:|---|---|
| `0x02` | `0x1f` | 18 | default frame 0 | subpattern/owner/phase value |
| `0x03` | `0x20` | 18 | default frame 0 | subpattern/owner/phase value |
| `0x03` | `0x21` | 8 | default frame 0 | subpattern/owner/phase value |
| `0x03` | `0x22` | 8 | default frame 0 | subpattern/owner/phase value |
| `0x02` | `0x17` | 6 | default frame 0 | subpattern/owner/phase value |
| `0x02` | `0x37` | 4 | default frame 0 | subpattern/owner/phase value |

## Per-projectile visual diversity notes

| Projectile ID | Observed useful visuals | Working interpretation |
|---:|---|---|
| `0x02` | default pellet, blue pellet, blue orb, bead, wide shard, pulse bead, many overflow variants | Scripted spread/ring behavior reused with both real visuals and subpattern IDs. |
| `0x03` | default pellet, blue pellet, magenta orb, blue bar, wide shards, overflow variants | Very reusable movement family; visual varies heavily by stage/pattern. |
| `0x04` | default pellet, blue orb, blue bar, long capsule, blue diamond, laser shard, pulse bead | Common child/fan projectile whose visible form depends strongly on caller. |
| `0x05` | default pellet, blue pellet, large orb, blue diamond | Aimed/fan projectile plus homing-helper child path. |
| `0x08` | default pellet, large orbs, small bead | Reflecting/bounce behavior has multiple visible forms. |
| `0x09` | default pellet, blue pellet, large orb, bead | Delayed-retarget behavior appears with both default and orb/bead visuals. |
| `0x0c` | default pellet, blue pellet, orb/bead variants | Homing behavior is not visually fixed. |
| `0x0d` | default pellet, blue pellet, large orbs, beads, long capsules | Final/boss fan projectile is visually polymorphic. |
| `0x11` | magenta arrowhead | Rare special/timed projectile with a clear visual selector. |

## Recommended next pass

1. Re-run this extraction with a de-duplication key based on function entry + line + argument tuple if exact unique call-site counts become important.
2. For high-value boss/final helper files, manually review the representative functions from `projectile-visual-pair-coverage.csv` to attach stage/type semantic names to these pairs.
3. Investigate whether any update helper rewrites `visual_selector_or_variant` before drawing; current evidence mostly passes it directly to `FUN_140070250`.
4. Use this table to support conservative Ghidra renames: name projectile IDs by movement behavior, and name arg2 values separately as visual selectors or variants.
