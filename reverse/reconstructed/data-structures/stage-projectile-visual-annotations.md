# Stage Projectile Visual Annotations

Status: first manual pass tying high-value stage/entity helpers to `(projectile_id, visual_selector_or_variant)` pairs and Bullet.png visuals. This builds on `projectile-visual-pair-coverage.md`; unlike the raw coverage table, rows here are stage-semantic annotations from representative boss/final/stage07 helper bodies.

Machine-readable version: `stage-projectile-visual-annotations.csv`.

## Interpretation model

- `projectile_id` selects movement/update behavior.
- Constructor arg2 becomes `ProjectileNode::visual_selector_or_variant`.
- If arg2 is handled by `FUN_140070250`, it maps directly to a `Bullet.png` frame.
- If arg2 is above `0x14`, current evidence suggests it often acts as subpattern/owner/phase while the draw helper falls back to default frame 0, unless a later path rewrites it.

## High-value stage/type annotations

| Spawn type | Semantic label | Helper | Projectile pair | Bullet visual | Pattern interpretation | Confidence |
|---|---|---|---|---|---|---|
| `0x3f` | `stage04_boss_like_multipart_pattern_controller` | `FUN_140095130` | `selector=0x07, id=0x00` | frame 7, blue horizontal capsule / bar | Alternating four-mount volleys use selector 7 with basic movement id 0. | High |
| `0x3f` | `stage04_boss_like_multipart_pattern_controller` | `FUN_140095130` | `selector=0x04, id=0x00` | frame 4, magenta small round / bead | Saved-aim jitter windows use selector 4 with basic movement id 0. | High |
| `0x3f` | `stage04_boss_like_multipart_pattern_controller` | `FUN_140095130` | `selector=0x02, id=0x00` | frame 2, magenta large round / orb | Half-circle fans use selector 2; the apparent dynamic second argument is the modulo remainder already proven zero at the guarded call. | High |
| `0x4f` | `stage05_boss_like_multi_phase_summoner` | `FUN_14009b5f0` | `id=0x0a, selector=0x02` | frame 2, magenta large orb | First active fan family uses heavy/common `id=0x0a` movement with large magenta orb visual. | High |
| `0x4f` | `stage05_boss_like_multi_phase_summoner` | `FUN_14009b5f0` | `id=0x0b, selector=0x02` | frame 2, magenta large orb | Second fan family changes to delayed-retarget `id=0x0b` while preserving large magenta orb visual. | High |
| `0x4f` | `stage05_boss_like_multi_phase_summoner` | `FUN_14009b5f0` | `id=0x03, selector=0x1c` | draw-helper default frame 0 unless rewritten | Late direct volleys use selector-overflow arg2; likely subpattern/phase rather than an explicit Bullet.png selector. | Medium |
| `0x76` | `stage07_heavy_multipart_pattern_emitter` | `FUN_1400a5dd0` | `id=0x0a, selector=0x00` | frame 0, magenta thin oval / small pellet | Opening/early direct heavy shots are default pellets. | High |
| `0x76` | `stage07_heavy_multipart_pattern_emitter` | `FUN_1400a5dd0` | `id=0x07, selector=0x00` | frame 0, magenta thin oval / small pellet | Offset-point spread families use fast/common `id=7` movement with default visuals. | High |
| `0x76` | `stage07_heavy_multipart_pattern_emitter` | `FUN_1400a5dd0` | `id=0x0f, selector=0x00 or dynamic` | frame 0 for fixed selector; dynamic unresolved | Secondary spread family is mostly default-pellet unless dynamic arg2 falls into visual-selector range. | Medium |
| `0x76` | `stage07_heavy_multipart_pattern_emitter` | `FUN_1400a5dd0` | `id=0x02, selector=0x07` | frame 7, blue horizontal capsule / bar | Distinct late/heavy spread uses blue capsule/bar visual, making it a strong visual anchor for this helper. | High |
| `0x77` | `stage07_boss_like_pattern_controller` | `FUN_1400a7760` | `id=0x04, selector=0x00 or cadence-derived dynamic` | frame 0 for fixed selector; dynamic unresolved | Boss controller emits `id=4` spread families; one fixed default and one cadence-derived visual/variant path. | Medium |
| `0x77` | `stage07_boss_like_pattern_controller` | `FUN_1400a7760` | `id=0x0c, selector=0x00 or dynamic` | frame 0 for fixed selector; dynamic unresolved | Center/aimed spread family uses homing `id=0x0c`; fixed path defaults to magenta pellet. | Medium |
| `0xfd` | `final_stage_spinning_fan_burster` | `FUN_1400b0b70` | `id=0x0d, selector=0x00` | frame 0, magenta thin oval / small pellet | Ramping 60-frame fan burst is visually simple default pellets; complexity comes from count/spread ramp. | High |
| `0x102` | `final_stage_large_multi_part_carrier_emitter` | `FUN_1400b2760` | `id=0x0d, selector=0x00` | frame 0, magenta thin oval / small pellet | Repeated aimed/random shots use default pellets. | High |
| `0x102` | `final_stage_large_multi_part_carrier_emitter` | `FUN_1400b2760` | `id=0x00, selector=0x00` | frame 0, magenta thin oval / small pellet | Later 15-shot burst windows also use default pellets. | High |
| `0x103/0x104` | `final_stage_large_rotating_orbit_burst_emitter_pair` | `FUN_1400b3540` | `id=0x04, selector=0x34` | draw-helper default frame 0 unless rewritten | Four-offset orbit burst likely uses arg2 `0x34` as subpattern/owner/phase and still draws default pellet. | Medium |

## Pattern-level conclusions

### Stage04 `0x3f` boss-like controller

The helper uses three distinct visual selectors with the basic movement id `0`:

- selector `7`: blue horizontal capsule/bar for alternating mount volleys;
- selector `4`: magenta bead for saved-aim jitter windows;
- selector `2`: magenta large orb for half-circle fans.

The older `id=7/4/2, selector=0` annotation had the constructor fields reversed;
`FUN_14006c2f0` stores its first argument at projectile `+0x08` and its second at
`+0x0c`, while the update dispatcher switches on `+0x0c`.

### Stage05 `0x4f` boss-like summoner

This is one of the clearest non-default visual anchors:

- `id=0x0a, selector=0x02` → magenta large orb.
- `id=0x0b, selector=0x02` → magenta large orb with different movement behavior.

So the phase transition changes projectile behavior while preserving visual family.

### Stage07 `0x76` heavy multipart emitter

This helper has a useful visual separation:

- Direct/offset volleys: default magenta pellets (`id=0x0a`, `id=0x07`).
- Distinct heavy spread: blue horizontal capsule/bar (`id=0x02, selector=0x07`).

That makes `id=0x02 + selector=0x07` a good candidate for a more specific local description such as “blue capsule spread” in notes, while keeping formal Ghidra names conservative.

### Stage07 `0x77` boss-like controller

The helper uses dynamic visual/variant arguments for `id=4` and `id=0xc` spread families. Fixed fallback paths are default pellets, but the dynamic values need a local symbolic/evaluation pass before assigning exact Bullet.png frames.

### Final-stage helpers

Final-stage visually complex enemies often still fire default pellets:

- `0xfd` ramping fan burst: `id=0x0d, selector=0x00`.
- `0x102` repeated aimed/random shots and 15-shot burst windows: `id=0x0d/0x00, selector=0x00`.
- `0x103/0x104` orbit burst uses selector-overflow `0x34`, likely subpattern/phase with draw-helper default frame 0.

This is useful for naming: final-stage helper names should emphasize emitter motion/body layout and pattern shape, not unique bullet sprite names.

## Conservative rename guidance from this pass

Good local wording:

- `stage05_type4f_large_orb_fan_phase_candidate`
- `stage07_type76_blue_capsule_spread_phase_candidate`
- `final_typefd_default_pellet_ramping_fan_candidate`

Avoid formal names like “orb boss” or “blue capsule enemy” until the enemy body resources and schedule semantics agree. Use visual labels for projectile phases, not whole enemy names.

## Next targets

1. Evaluate dynamic arg2 expressions in `FUN_1400a7760` and `FUN_140095130` to decide whether they can resolve to `0x00..0x14` visual selectors.
2. Annotate Stage04/Stage05 non-boss helpers where `projectile-visual-pair-coverage.csv` shows clear non-default visuals, especially `id=0x04 selector=0x0a/0x0f/0x10/0x11` and `id=0x11 selector=0x0c`.
3. Continue resource-frame mapping for enemy body sheets so projectile visual annotations can be paired with enemy visual identity.
