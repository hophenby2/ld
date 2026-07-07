# Projectile Collision and Graze Notes

Status: first focused pass over the gameplay-loop functions that consume projectile node radius/enable fields. Names remain candidate-level, but the player collision/graze path is now much clearer than in earlier projectile notes.

## Key correction to `ProjectileNode` layout

The projectile constructor at `0x14006c2f0` shows that earlier notes placed the collision radius too late in the node:

| Offset | Decompiled access | Corrected field | Evidence |
|---:|---|---|---|
| `+0x38` | `piVar[0xe]` / `param_1[0xe]` | `collision_radius` | Constructor writes arg8 here (`puVar1 + 7`); collision code reads it as the radius. |
| `+0x3c` | `piVar[0xf]` | `graze_or_hit_processed` | Constructor initializes it to `0`; player collision code sets it to `1` after the near-miss/graze effect. |
| `+0x40` | `piVar[0x10]` | `collision_enabled` | Constructor initializes it to `1`; collision code requires it before graze handling. |
| `+0x44` | `piVar[0x11]` | `arg8_or_aux` | Constructor stores the final projectile constructor argument here. |
| `+0x48` | `*(... + 0x12)` | `next` | Main-loop cleanup unlinks through this field. |

Primary constructor evidence: `reverse/ghidra-or-ida/exports/stage-update-helper-priority/neighborhood-decompiled/14006c2f0_FUN_14006c2f0.c:21` through `:39`.

## `FUN_1400cbd30` — player projectile collision / graze candidate

Candidate name: `check_enemy_projectile_player_collision_and_graze_candidate`.

Call site: the main gameplay loop calls this after projectile update, stage/entity collision pass, and inactive-list cleanup. Its return value drives player-hit/route behavior in `state_14_replay_demo_gameplay_update_candidate`: `reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/1400bca30_state_14_replay_demo_gameplay_update_candidate.c:995` through `:1004`.

Behavior summary:

```c
bool check_enemy_projectile_player_collision_and_graze_candidate() {
    int hit_radius_bonus = (g_player_option_or_state + 2U > 4) ? 3 : 4;
    bool hit = false;

    for (ProjectileNode* p = projectile_head; p; p = p->next) {
        // Predict next frame's effective collision point, matching draw/update motion.
        float test_x = p->x + cos(p->angle) * p->speed_or_accel_hint;
        float test_y = p->y + sin(p->angle) * p->speed_or_accel_hint;
        float dist = hypot(test_x - player_x, test_y - player_y);

        if (p->collision_radius > 0) {
            if (dist <= p->collision_radius + hit_radius_bonus) {
                p->active = 0;
                hit = true;
            }

            if (!p->graze_or_hit_processed && p->active && g_main_state != 0x15 &&
                g_player_active_flag == 1 &&
                dist <= p->collision_radius + graze_margin) {
                spawn_graze_effects_near_projectile_and_player();
                play_graze_sound();
                increment_graze_counters();
                p->graze_or_hit_processed = 1;
            }
        }
    }

    return hit;
}
```

Important evidence:

- Iterates the enemy projectile list from `DAT_140e45260`: `reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/1400cbd30_FUN_1400cbd30.c:40` through `:44`.
- Predicts/test point from `x/y + cos/sin(angle) * speed_or_accel_hint`: same file `:45` through `:49`.
- Measures distance to player globals `DAT_140e445d8` / `DAT_140e445dc`: same file `:50` through `:57`.
- Reads `piVar11[0xe]` as the projectile radius and kills the projectile/returns hit when within `radius + 3/4`: same file `:58` through `:65`.
- Requires `piVar11[0xf] == 0`, `active == 1`, `collision_enabled == 1`, not state `0x15`, and player-active flag before graze handling: same file `:66` through `:67`.
- Spawns graze/near-miss effects, plays `DAT_140e472ac`, increments counters, and sets `piVar11[0xf] = 1`: same file `:68` through `:136`.

Interpretation:

- `+0x38` is a radius/collision-size field, not a generic flags field.
- `+0x3c` is a one-shot graze/near-miss processed flag.
- `+0x40` is the projectile collision/graze enable flag. Update helper IDs `0x13..0x15` explicitly toggle this field during short startup windows, matching “not immediately collidable” behavior.
- The return value is a player-hit flag. The projectile is deactivated on direct player collision, then the main-loop cleanup removes it.

## `FUN_1400cd750` — player-shot / cancel-object vs enemy projectile collision candidate

Candidate name: `check_player_side_object_vs_projectiles_candidate`. See `player-side-object-list.md` for the follow-up pass that identifies `DAT_140e46ea0` as a mixed player-side shot/special/cancel object list.

Call site: the main gameplay loop calls it immediately after projectile updates and before inactive-list cleanup: `reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/1400bca30_state_14_replay_demo_gameplay_update_candidate.c:853` through `:867`.

Behavior summary:

- Iterates another gameplay object list rooted at `DAT_140e46ea0`.
- Only selected object types are considered (`uVar19 < 0x1f` and bitmask `0x63737000`).
- For selected object types, it iterates the enemy projectile list `DAT_140e45260`.
- It predicts each projectile's next test point using the same `x/y + cos/sin(angle) * speed_or_accel_hint` formula.
- It compares squared distance to `(projectile.collision_radius + object_radius)^2`.
- When conditions match, it spawns impact/cancel effects and sets `projectile.active = 0`.

Important evidence:

- Traverses `DAT_140e46ea0` and filters by object type: `reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/1400cd750_FUN_1400cd750.c:40` through `:50`.
- For object type case 0, traverses `DAT_140e45260`: same file `:56` through `:61`.
- Predicts projectile test point and reads `piVar14[0xe]` as collision radius: same file `:62` through `:75`.
- Requires projectile active and `piVar14[0x10] == 1`, then emits effects and deactivates the projectile: same file `:75` through `:79`, `:93` through `:132`, and `:278`.
- A similar simpler collision/deactivate path exists in case 1: same file `:285` through `:336`.
- Case 2 repeats the richer effect/cancel branch: same file `:340` through `:558`.

Interpretation caveat:

`DAT_140e46ea0` is not yet fully typed. The object fields used here (`+0x0c`, `+0x10`, and `+0x2c`) look like `x`, `y`, and a collision/cancel radius. The function probably handles player shots, bombs, cancel fields, or other player-owned objects clearing enemy bullets. Do not rename it more specifically until the `DAT_140e46ea0` list allocator/update functions are reviewed.

## Main-loop ordering

Within `state_14_replay_demo_gameplay_update_candidate` the relevant sequence is:

1. Update stage entities (`FUN_140078b70`).
2. Run another gameplay helper (`FUN_1400ca7b0`).
3. Update effect nodes (`FUN_140070e40`).
4. Update each projectile by `projectile_id` through the six projectile update helpers.
5. Run `FUN_1400cd750`, which can deactivate projectiles through player-shot/cancel-object overlap.
6. Cleanup inactive lists, including enemy projectile nodes through `+0x48` and decrementing `DAT_140e451b4`.
7. Run `FUN_1400cbd30`, which checks player hit/graze against surviving projectiles and returns a hit flag.

Evidence anchors: projectile update switch at `reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/1400bca30_state_14_replay_demo_gameplay_update_candidate.c:751` through `:854`; `FUN_1400cd750` call at `:866`; projectile cleanup at `:963` through `:994`; player hit/graze call at `:995` through `:1004`.

## Current reconstruction status

`reverse/reconstructed/project/src/stage_runtime.cpp` now splits collision handling so enemy projectile player-hit/graze is separate from player offense:

- `handleEnemyProjectilePlayerHitAndGraze()` models direct player hits and graze/near-miss candidate handling from `FUN_1400cbd30`.
- `StageProjectile::grazeOrHitProcessed` is now consumed by runtime graze logic so each projectile only increments `player_.graze` once.
- Offensive player-shot/player-side-object hits no longer increment `player_.graze`; this keeps the runtime value aligned with the projectile near-miss evidence rather than using it as a generic activity counter.
- `handlePlayerSideObjectProjectileCancels()` models the `FUN_1400cd750` cancel path and emits reward item types `3/4` at cancelled projectile positions.

Caveats:

- Runtime graze margin/radii are first-pass approximations pending exact constants from `FUN_1400cbd30`.
- Original graze effects, sounds, and all auxiliary counters remain deferred.
- The user-facing term “buzz” remains unconfirmed; current docs/code should describe this as a graze/near-miss candidate.

## Rename candidates

| Address | Current | Candidate | Confidence |
|---|---|---|---|
| `0x1400cbd30` | `FUN_1400cbd30` | `check_enemy_projectile_player_collision_and_graze_candidate` | High |
| `0x1400cd750` | `FUN_1400cd750` | `check_player_side_object_vs_projectiles_candidate` | Medium-high |

## Next targets

1. Review the `DAT_140e46e90` secondary 0x30-byte list allocated by `FUN_1400ca6d0`; `DAT_140e46ea0` itself is now identified as the mixed player-side shot/special/cancel object list in `player-side-object-list.md`.
2. Find where projectile IDs `0x13`, `0x14`, and `0x15` are spawned; their special `collision_enabled` toggling suggests startup-safe or delayed-collision bullets.
3. Propagate the corrected projectile field names into any typed pseudo-C copies of projectile update helpers.
