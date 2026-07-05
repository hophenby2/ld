#pragma once

#include <cstdint>

// Pseudo-C layouts reconstructed from Ghidra exports.
// These are not original source; sizes/field names are working hypotheses used
// to make decompiled gameplay helpers readable.

namespace reconstructed {

using GraphHandle = int32_t;
using FixedAngle16 = uint16_t; // 0x10000 units per full turn.

struct StageEntity {
    int32_t active;                 // +0x00: live flag; inactive nodes are unlinked/freed.
    int32_t age;                    // +0x04: total frame age, incremented by update dispatcher.
    int32_t active_age;             // +0x08: active-state timer / secondary timer.
    int32_t field_0c;               // +0x0c: helper-specific timer/state.
    int32_t field_10;               // +0x10: helper-specific timer/state.
    int32_t owner_or_parent_id;     // +0x14: aux link id; child helpers match this against parent ids.
    int32_t spawn_type;             // +0x18: primary behavior discriminator / update switch input.
    int32_t lifetime;               // +0x1c: current/remaining or scheduled duration.
    int32_t lifetime_max;           // +0x20: mirrored lifetime / max duration.
    int32_t entity_kind;            // +0x24: render/collision/payout category, not update type.
    float x;                        // +0x28: current x.
    float y;                        // +0x2c: current y.
    float prev_or_origin_x;         // +0x30: previous/origin x.
    float prev_or_origin_y;         // +0x34: previous/origin y.
    float anchor_or_target_x;       // +0x38: anchor/target x.
    float anchor_or_target_y;       // +0x3c: anchor/target y.
    FixedAngle16 angle;             // +0x40: current heading/angle.
    FixedAngle16 prev_angle;        // +0x42: previous/secondary heading.
    FixedAngle16 target_angle;      // +0x44: target/aim angle.
    uint16_t field_46;              // +0x46: padding or helper-specific short.
    double speed_or_scale;          // +0x48: movement magnitude / scale / scripted constant.
    float collision_radius;         // +0x50: radius or clear-effect size.
    int32_t targetable_or_active;   // +0x54: flag used by targeting and cleanup helpers.
    int32_t field_58;               // +0x58: helper-specific scratch.
    int32_t field_5c;               // +0x5c: helper-specific scratch.
    StageEntity* next;              // +0x60: linked-list next (`DAT_140e45d80` list).
};
static_assert(sizeof(StageEntity) == 0x68, "StageEntity layout size must match allocation");

struct ProjectileNode {
    int32_t active;                 // +0x00
    int32_t age;                    // +0x04
    int32_t visual_selector_or_variant; // +0x08: Bullet.png visual selector in draw helper; sometimes owner/subpattern.
    int32_t projectile_id;              // +0x0c: update dispatcher key.
    float x;                        // +0x10
    float y;                        // +0x14
    float prev_x;                   // +0x18
    float prev_y;                   // +0x1c
    float speed_or_accel_hint;      // +0x20
    FixedAngle16 angle;             // +0x24
    FixedAngle16 prev_angle;        // +0x26
    double speed;                   // +0x28
    double base_speed;              // +0x30
    int32_t collision_radius;       // +0x38: consumed by player/cancel collision walkers.
    int32_t graze_or_hit_processed; // +0x3c: one-shot graze/near-miss flag.
    int32_t collision_enabled;      // +0x40: gates graze/cancel collision handling.
    int32_t arg8_or_aux;            // +0x44: final constructor arg, helper-specific.
    ProjectileNode* next;           // +0x48
};
static_assert(sizeof(ProjectileNode) == 0x50, "ProjectileNode layout size must match allocation");

struct EffectNode {
    int32_t active;                 // +0x00
    int32_t age;                    // +0x04
    int32_t effect_type;            // +0x08: update dispatcher key.
    GraphHandle graph_handle;       // +0x0c
    int32_t frame_or_lifetime;      // +0x10
    float x;                        // +0x14
    float y_or_aux0;                // +0x18
    float prev_x;                   // +0x1c
    float y_or_aux1;                // +0x20
    FixedAngle16 angle;             // +0x24
    uint16_t field_26;              // +0x26
    double scale0;                  // +0x28
    double scale1;                  // +0x30
    double scale2;                  // +0x38
    int32_t arg9;                   // +0x40
    int32_t color_r;                // +0x44
    int32_t color_g;                // +0x48
    int32_t color_b;                // +0x4c
    int32_t alpha;                  // +0x50
    int32_t arg14;                  // +0x54
    EffectNode* next;               // +0x58
};
static_assert(sizeof(EffectNode) == 0x60, "EffectNode layout size must match allocation");

// Helper prototypes in readable form.
void spawn_projectile_node_candidate(int projectile_id, int variant_or_owner,
                                     float x, float y, FixedAngle16 angle,
                                     float speed_or_accel_hint, double speed,
                                     int collision_radius, int arg8_or_aux);

void spawn_projectile_spread_candidate(int projectile_id, int variant_or_owner,
                                       float x, float y, FixedAngle16 center_angle,
                                       float speed_or_accel_hint, double speed,
                                       int collision_radius, uint32_t count,
                                       int spread_angle, int arg8_or_aux);

void spawn_effect_node_candidate(int effect_type, GraphHandle graph_handle,
                                 int frame_or_lifetime, float x, float y,
                                 FixedAngle16 angle, double scale0,
                                 double scale1, double scale2, int arg9,
                                 int color_r, int color_g, int color_b,
                                 int alpha, int arg14);

void draw_projectile_visual_candidate(int visual_selector, int frame_or_layer,
                                      int age, float x, float y,
                                      FixedAngle16 angle,
                                      int spawn_trail_effect_flag);

} // namespace reconstructed
