# Bullet Frame Visual Map

Status: first-pass mapping from `media\\stage\\Bullet.png`, `dxlib_load_div_graph_candidate(..., 0x28, 10, 4, 0x3c, 0x3c, &DAT_140e451c0, ...)`, and the projectile draw helper `FUN_140070250 @ 0x140070250`. This is a local reverse-engineering aid; names are descriptive visual labels, not original asset names.

## Key distinction

`ProjectileNode::variant_or_owner` (`param_1[2]` in update helpers) is the primary selector passed to `FUN_140070250` and therefore selects the visible bullet frame family. `ProjectileNode::projectile_id` (`param_1[3]`) selects movement/update behavior. This means projectile IDs and visible bullet shapes are related by spawn-call arguments, not by a one-to-one ID-to-frame table.

Common call shape after each update helper computes position:

```c
FUN_140070250(
    node->variant_or_owner,   // visual selector / variant
    0x50 or 0x51 or 0x4f,      // draw frame/layer-ish argument
    node->age,                 // used for spin / scale animation
    draw_x,
    draw_y,
    node->angle,
    trail_or_effect_flag);
```

## Bullet.png sheet layout

- Backing file: `media\\stage\\Bullet.png`.
- Base global: `DAT_140e451c0`.
- Divided graph: `0x28` frames, 10 columns x 4 rows, 60x60 each.
- Global-to-frame formula: `DAT_140e451c0 + frame_index * 4`.

## Visual selector map from `FUN_140070250`

| Visual selector | Frame | Global | Visual label | Notes |
|---:|---:|---|---|---|
| `0x00` | 0 | `DAT_140e451c0` | magenta thin oval / small pellet | Age controls rotation (`age * 2000`) and scale pulse. |
| `0x01` | 1 | `DAT_140e451c4` | blue thin oval / small pellet | Case falls through to selector `0x00` animation behavior. |
| `0x02` | 2 | `DAT_140e451c8` | magenta large round / orb | Age controls rotation (`age * 999`) and scale pulse. |
| `0x03` | 3 | `DAT_140e451cc` | blue large round / orb | Age controls rotation (`age * 999`) and scale pulse. |
| `0x04` | 4 | `DAT_140e451d0` | magenta small round / bead | Age controls rotation (`age * 0x682`) and scale pulse. |
| `0x05` | 5 | `DAT_140e451d4` | blue small round / bead | Age controls rotation (`age * 0x682`) and scale pulse. |
| `0x06` | 6 | `DAT_140e451d8` | magenta horizontal capsule / bar | Fixed scale branch. |
| `0x07` | 7 | `DAT_140e451dc` | blue horizontal capsule / bar | Fixed scale branch. |
| `0x08` | 8 | `DAT_140e451e0` | magenta wide shard / rice | Fixed scale branch. |
| `0x09` | 9 | `DAT_140e451e4` | blue wide shard / rice | Fixed scale branch. |
| `0x0a` | 20 | `DAT_140e45210` | magenta long capsule / long oval | Uses default scale path. |
| `0x0b` | 21 | `DAT_140e45214` | blue long capsule / long oval | Uses default scale path. |
| `0x0c` | 22 | `DAT_140e45218` | magenta arrowhead / dart | Uses default scale path. |
| `0x0d` | 23 | `DAT_140e4521c` | blue arrowhead / dart | Uses default scale path. |
| `0x0e` | 24 | `DAT_140e45220` | magenta small diamond / shard | Age controls rotation (`age * 999`) and scale pulse. |
| `0x0f` | 25 | `DAT_140e45224` | blue small diamond / shard | Age controls rotation (`age * 999`) and scale pulse. |
| `0x10` | 26 | `DAT_140e45228` | magenta long horizontal bar / laser shard | Fixed scale branch. |
| `0x11` | 4 | `DAT_140e451d0` | magenta bead with white pulse overlay | Draws `DAT_140e4194c` pulse first, then frame 4. |
| `0x12` | 5 | `DAT_140e451d4` | blue bead with white pulse overlay | Draws `DAT_140e4194c` pulse first, then frame 5. |
| `0x13` | 5 | `DAT_140e451d4` | blue bead with Enemy_s overlay/effect | Draws `DAT_140e44834`, spawns effect type `5`, then frame 5. |
| `0x14` | 4 | `DAT_140e451d0` | magenta bead with Enemy_s overlay/effect | Draws `DAT_140e44838`, spawns effect type `7`, then frame 4. |

Frames 10-19 and 30-36 are white duplicates of the row 0/row 2 shapes, and frames 27-29 plus 37-39 are visually empty in the extracted PNG. No direct `FUN_140070250` selector currently maps to those white/empty frames, so they may be unused, reserve frames, or used by code paths not present in the current first-pass exports.

## Resource evidence from image analysis

A simple alpha/bounding-box pass over `Bullet.png` shows these shape clusters:

| Frames | Color | Shape cluster |
|---|---|---|
| `0,1,10,11` | magenta / blue / white duplicates | thin oval / small pellet |
| `2,3,12,13` | magenta / blue / white duplicates | large round / orb |
| `4,5,14,15` | magenta / blue / white duplicates | small round / bead |
| `6,7,16,17` | magenta / blue / white duplicates | horizontal capsule / bar |
| `8,9,18,19` | magenta / blue / white duplicates | wide shard / rice |
| `20,21,30,31` | magenta / blue / white duplicates | long capsule / long oval |
| `22,23,32,33` | magenta / blue / white duplicates | arrowhead / dart |
| `24,25,34,35` | magenta / blue / white duplicates | small diamond / shard |
| `26,36` | magenta / white duplicate | long horizontal bar / laser shard |
| `27-29,37-39` | empty | blank divided frames |

## Cross-reference files

- Machine-readable CSV: `bullet-frame-visual-map.csv`.
- Projectile node/update notes: `projectile-helper-notes.md`.
- Projectile ID pattern table: `projectile-pattern-parameter-table.csv`.
