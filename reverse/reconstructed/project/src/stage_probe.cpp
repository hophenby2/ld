#include "stage_probe.h"

#include <fstream>
#include <sstream>

namespace reconstructed {
namespace {

std::vector<std::string> splitComma(const std::string& line) {
    std::vector<std::string> fields;
    std::string field;
    for (char ch : line) {
        if (ch == ',') {
            fields.push_back(field);
            field.clear();
        }
        else if (ch != '\r') {
            field.push_back(ch);
        }
    }
    fields.push_back(field);
    return fields;
}

DemoProbeSummary loadDemo(const std::filesystem::path& assetRoot, int index) {
    DemoProbeSummary summary;
    char name[32] = {};
    std::snprintf(name, sizeof(name), "LD_demo%02d.txt", index);
    summary.id = name;
    summary.logicalPath = std::string("media\\demo\\") + name;

    const auto path = assetRoot / "re" / "demo" / name;
    std::ifstream in(path, std::ios::binary);
    if (!in) {
        summary.error = "open failed";
        return summary;
    }

    std::string line;
    if (!std::getline(in, line)) {
        summary.error = "empty file";
        return summary;
    }
    if (line.size() >= 3 && static_cast<unsigned char>(line[0]) == 0xef &&
        static_cast<unsigned char>(line[1]) == 0xbb && static_cast<unsigned char>(line[2]) == 0xbf) {
        line.erase(0, 3);
    }

    summary.firstHeader = line;
    summary.headerFieldCount = static_cast<int>(splitComma(line).size());

    while (std::getline(in, line)) {
        if (splitComma(line).size() == 2) {
            ++summary.inputRecordCount;
        }
    }
    summary.loaded = summary.headerFieldCount == 15;
    if (!summary.loaded) {
        summary.error = "unexpected header field count";
    }
    return summary;
}

} // namespace

bool StageProbe::loadDemoSummaries(const std::filesystem::path& assetRoot) {
    demos_.clear();
    bool ok = true;
    for (int i = 1; i <= 3; ++i) {
        auto summary = loadDemo(assetRoot, i);
        ok = summary.loaded && ok;
        demos_.push_back(std::move(summary));
    }
    return ok;
}

const std::vector<StageResourceHint>& stageResourceHints() {
    static const std::vector<StageResourceHint> hints = {
        {1, "Stage group 1", "StageBack1/1b/1c/1d + StageBack2", "Stage1.ogg", "Boss1.ogg", "1400ced90 resource table + replay checkpoint defaults"},
        {2, "Stage 2", "Stage2Back", "Stage2.ogg", "Boss2.ogg", "1400ced90 single graph and BGM table"},
        {3, "Stage 3", "Stage3Back", "Stage3.ogg", "Boss3.ogg", "1400ced90 single graph and BGM table"},
        {4, "Stage 4", "background unknown from current string evidence", "Stage4.ogg", "Boss2.ogg", "FUN_14011cdd0 selects the shared Boss2 handle"},
        {5, "Stage 5", "background unknown from current string evidence", "Stage5.ogg", "Boss5.ogg", "BGM table only so far"},
        {6, "Stage 6", "Stage6Back", "Stage6.ogg", "unknown", "1400ced90 single graph and BGM table"},
        {8, "Stage 8", "Stage8Back1 + Stage8Back2", "Stage8.ogg", "unknown", "1400ced90 single graph and BGM table"},
        {10, "Stage 10", "background unknown from current string evidence", "Stage10.ogg", "unknown", "BGM table only so far"},
    };
    return hints;
}

const std::vector<ReplayStageFieldHint>& replayStageFieldHints() {
    static const std::vector<ReplayStageFieldHint> hints = {
        {"0x002c", "stage_or_section_candidate", "loaded into DAT_140e445c0; value 2 in current samples"},
        {"0x0030..0x003c", "stage_progress_candidate_*", "four progress/checkpoint-like integers"},
        {"0x0040", "demo_checkpoint_or_stage", "demo header field #15; sample values 3,7,8"},
        {"0x0044", "binary_current_stage", "written from DAT_1407c7798 before replay save"},
        {"0x0048..0x0050", "stage_group_checkpoint_0..2", "used by stage transition code for stage groups"},
        {"0x00b8..0x00c4", "player initial x/y pairs", "float-heavy snapshot around 360,600"},
    };
    return hints;
}

const std::vector<EntityModelHypothesis>& entityModelHypotheses() {
    static const std::vector<EntityModelHypothesis> hints = {
        {"player", "Player.png, PlayerFrame.png, DreamGauge.png", "active, x/y, prev/target x/y, speed/angle, state, option/subobject positions"},
        {"enemy", "Enemy_s/m/l/xl.png, EnemyGauge1/2.png", "active, type, x/y, velocity, hp, timer, sprite index, behavior id, drop id"},
        {"bullet", "Bullet.png split 0x28,10,4,0x3c,0x3c", "active, x/y, angle, speed, radius, sprite/color index, timer, owner"},
        {"boss", "Boss.png, BossGauge.png, BossName.png, BossApproach*.png", "active, boss id, hp, phase, phase timer, movement target, pattern id"},
    };
    return hints;
}

const std::vector<ProjectileVisualAnnotation>& projectileVisualAnnotations() {
    static const std::vector<ProjectileVisualAnnotation> annotations = {
        {"0x3f", "stage04_boss_like_multipart_pattern_controller", "FUN_140095130", "id=0x07 selector=0x00", "frame 0 magenta thin oval / small pellet", "common fast aimed/paired shot", "early/medium active boss-like volleys use default magenta pellet despite varied speeds/offsets", "High"},
        {"0x3f", "stage04_boss_like_multipart_pattern_controller", "FUN_140095130", "id=0x04 selector=0x00", "frame 0 magenta thin oval / small pellet", "common straight/fan child projectile", "later phase/fan child shots remain default magenta pellet", "High"},
        {"0x4f", "stage05_boss_like_multi_phase_summoner", "FUN_14009b5f0", "id=0x0a selector=0x02", "frame 2 magenta large orb", "common/heavy pattern shot", "first active fan family uses large magenta orbs; high difficulty adds faster duplicate fans", "High"},
        {"0x4f", "stage05_boss_like_multi_phase_summoner", "FUN_14009b5f0", "id=0x0b selector=0x02", "frame 2 magenta large orb", "delayed-retarget paired shot", "second fan family switches movement behavior while keeping large magenta orb visual", "High"},
        {"0x76", "stage07_heavy_multipart_pattern_emitter", "FUN_1400a5dd0", "id=0x02 selector=0x07", "frame 7 blue horizontal capsule / bar", "scripted spread/ring projectile", "distinct late/heavy spread uses blue capsule/bar visual, separating it from default-pellet volleys", "High"},
        {"0xfd", "final_stage_spinning_fan_burster", "FUN_1400b0b70", "id=0x0d selector=0x00", "frame 0 magenta thin oval / small pellet", "common delayed/accelerating fan projectile", "ramping 60-frame fan burst is visually default magenta pellets; complexity comes from count/spread ramp", "High"},
        {"0x103/0x104", "final_stage_large_rotating_orbit_burst_emitter_pair", "FUN_1400b3540", "id=0x04 selector=0x34", "draw-helper default frame 0 unless arg2 is rewritten", "common straight/fan child projectile with selector-overflow arg2", "four-offset orbit burst likely uses arg2 as subpattern/owner/phase and still draws default pellet", "Medium"},
    };
    return annotations;
}

const std::vector<ReverseTargetFunction>& reverseTargetFunctions() {
    static const std::vector<ReverseTargetFunction> targets = {
        {"main_loop_candidate", "DxLib ProcessMessage/ScreenFlip/ClearDrawScreen call cluster", "xref static-linked DxLib frame calls and identify scene dispatch"},
        {"scene_update_candidate", "small global scene id switch expected", "trace writes to current scene/state globals"},
        {"stage_init_candidate", "BGM Stage*.ogg usage and player initial 360,600 values", "xref PlaySound/BGM handles and stage id globals"},
        {"stage_update_candidate", "stage timer and enemy/bullet array traversal expected", "look for frame counter modulo checks and spawn calls"},
        {"stage_draw_candidate", "StageBack*, Enemy*, Bullet*, Boss* handles", "xref resource handle globals into draw functions"},
        {"spawn_enemy_candidate", "Enemy_s/m/l/xl resources and enemy arrays", "find function that writes empty enemy slot fields"},
        {"spawn_bullet_candidate", "Bullet.png split table and trigonometric patterns", "find function that writes bullet x/y/vx/vy/type"},
        {"boss_phase_candidate", "BossGauge/BossName/BossLife/BossSE resources", "trace boss hp/phase/timer updates"},
        {"demo_loader_candidate", "media\\demo\\LD_demo%02d.txt", "xref string 140536f20 and correlate with text demo parser"},
        {"replay_input_reader_candidate", "0xa98 replay header and 8-byte input records", "continue from replay handler candidates A/B/C"},
    };
    return targets;
}

} // namespace reconstructed
