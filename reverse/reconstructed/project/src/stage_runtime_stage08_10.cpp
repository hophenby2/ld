#include "stage_runtime.h"

#include <cmath>
#include <cstdint>

namespace reconstructed {
namespace {

std::uint32_t lateStageRand(int frame) {
    const auto seed = static_cast<std::uint32_t>(frame);
    const std::uint32_t u = ((seed >> 30) ^ seed) * 0x6c078965u + 1u;
    const std::uint32_t a = ((u >> 30) ^ u) * 0x6c078965u + 2u;
    const std::uint32_t b = ((a >> 30) ^ a) * 0x6c078965u + 3u;
    const std::uint32_t c = ((b >> 30) ^ b) * 0x6c078965u + 4u;
    const std::uint32_t mixed = u * 0x800u ^ u;
    return (((c >> 11) ^ mixed) >> 8) ^ c ^ mixed;
}

int lateStageRandCoord(int frame, std::uint32_t modulus, int base) {
    return static_cast<int>(lateStageRand(frame) % modulus) + base;
}

bool lateStageWindow(int frame, int start, int duration, int step) {
    const int local = frame - start;
    return local >= 0 && local < duration && local % step == 0;
}

} // namespace

void StageRuntime::spawnStage08OriginalSchedule() {
    const int f = frame_;
    const std::uint32_t random = lateStageRand(f);
    auto spawn = [this](int type, int hitPoints, int x, int y, const char* note) {
        spawnEnemy({frame_, type, hitPoints, x, y, note});
    };
    auto randomCoord = [random](std::uint32_t modulus, int base) {
        return static_cast<int>(random % modulus) + base;
    };
    auto reverseRandomCoord = [random](std::uint32_t modulus, int base) {
        return base - static_cast<int>(random % modulus);
    };

    // Literal stack paths assembled by stage_08_gameplay_update_candidate.
    static constexpr std::array<std::array<int, 2>, 6> kOpening97Path{{
        {{160, -1810}}, {{360, -1810}}, {{560, -1810}},
        {{90, -4570}}, {{530, -4570}}, {{640, -4570}},
    }};
    static constexpr std::array<std::array<int, 2>, 6> kEarly99Path{{
        {{-180, 240}}, {{-250, 120}}, {{-180, 0}},
        {{900, 240}}, {{970, 120}}, {{900, 0}},
    }};
    static constexpr std::array<std::array<int, 2>, 26> kEarly96Path{{
        {{125, 40}}, {{140, 140}}, {{205, 20}}, {{220, 120}},
        {{300, 0}}, {{300, 140}}, {{360, 70}}, {{595, 40}},
        {{580, 140}}, {{515, 20}}, {{500, 120}}, {{420, 0}},
        {{420, 140}}, {{360, 190}}, {{180, 240}}, {{540, 240}},
        {{270, 445}}, {{450, 445}}, {{200, 465}}, {{520, 465}},
        {{130, 480}}, {{590, 480}}, {{180, 570}}, {{540, 570}},
        {{110, 595}}, {{610, 595}},
    }};
    static constexpr std::array<std::array<int, 2>, 10> kLate96Path{{
        {{360, 40}}, {{275, 70}}, {{445, 70}}, {{120, 335}},
        {{205, 290}}, {{310, 300}}, {{590, 350}}, {{550, 450}},
        {{440, 470}}, {{145, 450}},
    }};

    // Direct transcription of stage_08_gameplay_update_candidate @ 0x1401253e0.
    if (f == 400) {
        for (const auto& point : kOpening97Path) {
            spawn(0x97, 0x5dc, point[0], point[1], "S08 original lines 90-101: opening 0x97 path");
        }
        spawn(0x9a, 15000, 0x200, -0xc82, "S08 original line 102: opening controller");
        spawn(0x9a, 15000, 0x138, -0x1167, "S08 original line 103: opening controller");
    }
    if (lateStageWindow(f, 400, 800, 0x5a)) {
        spawn(0x98, 1000, 0x302, f - 0x352, "S08 original line 108: right descending route");
    }
    if (lateStageWindow(f, 700, 800, 0x5a)) {
        spawn(0x98, 1000, -50, f - 0x460, "S08 original line 113: left descending route");
    }
    if (lateStageWindow(f, 2000, 800, 0x5a)) {
        spawn(0x98, 1000, 0x302, f - 0x992, "S08 original line 118: right descending route");
    }
    if (lateStageWindow(f, 4000, 800, 0x5a)) {
        spawn(0x98, 1000, -50, f - 0x1158, "S08 original line 123: left descending route");
    }
    if (lateStageWindow(f, 0x546, 0x226, 0x5a)) {
        for (int x : {0x10e, 0x168, 0x1c2}) {
            spawn(0x95, 1000, x, -50, "S08 original lines 128-130: early 0x95 wall");
        }
    }
    if (lateStageWindow(f, 0xa8c, 500, 0x5a)) {
        spawn(0x95, 0x4b0, 0x1d6, -50, "S08 original lines 135-136: early 0x95 pair");
        spawn(0x95, 0x4b0, 0x249, -50, "S08 original lines 135-136: early 0x95 pair");
    }
    if (lateStageWindow(f, 0xf3c, 400, 0x5a)) {
        spawn(0x95, 0x4b0, 0xe6, -50, "S08 original lines 141-142: early 0x95 pair");
        spawn(0x95, 0x4b0, 0x1ea, -50, "S08 original lines 141-142: early 0x95 pair");
    }
    for (std::size_t i = 0; i < kEarly99Path.size(); ++i) {
        const int spawnFrame = 0x672 + static_cast<int>(i) * 0x0f;
        if (f == spawnFrame) {
            spawn(0x99, 0x4b0, kEarly99Path[i][0],
                  kEarly99Path[i][1] + f - 0x672,
                  "S08 original lines 145-161: routed 0x99 path");
        }
    }
    if (f == 0xce4) spawn(0x99, 0x5dc, -50, 0x50, "S08 original line 164: fixed 0x99");
    if (f == 0xd02) spawn(0x99, 0x5dc, -180, 0x50, "S08 original line 168: fixed 0x99");
    for (std::size_t i = 0; i < kEarly96Path.size(); ++i) {
        const int baseFrame = 0x15b8 + static_cast<int>(i) * 0x0c;
        const int spawnFrame = i < 7 ? baseFrame - 0x3c
                              : (i > 15 ? baseFrame + 0xbe : baseFrame);
        if (f == spawnFrame) {
            spawn(0x96, 700, kEarly96Path[i][0],
                  100 - kEarly96Path[i][1] + f - 0x157c,
                  "S08 original lines 172-219: routed 0x96 formation");
        }
    }

    if (lateStageWindow(f, 0x186, 0xb4, 0x10)) {
        spawn(0x0b, 0xfa, randomCoord(0x259, 0x3c), -20, "S08 original line 234: top wave");
    }
    if (lateStageWindow(f, 0x18e, 0xac, 0x10)) {
        spawn(0x44, 0xfa, randomCoord(0x259, 0x3c), -20, "S08 original line 251: top wave");
    }
    if (f == 0x26c) spawn(0x0e, 5000, 500, 0, "S08 original line 256: fixed setpiece");
    if (f == 0x28a) spawn(0x0e, 5000, 0xdc, 0, "S08 original line 260: fixed setpiece");
    if (f == 1000) spawn(0x07, 5000, 0x1cc, 0, "S08 original line 264: common marker");
    if (lateStageWindow(f, 0x802, 0x96, 0x0c)) {
        spawn(0x0b, 0xfa, randomCoord(0x259, 0x3c), -20, "S08 original line 275: top wave");
    }
    if (lateStageWindow(f, 0x92e, 100, 0x0c)) {
        spawn(0x0b, 0xfa, randomCoord(0x259, 0x3c), -20, "S08 original line 286: top wave");
    }
    if (lateStageWindow(f, 0xa64, 100, 0x0f)) {
        spawn(0x45, 400, -20, randomCoord(0x79, 0x96), "S08 original line 297: left wave");
    }
    if (f == 0xb54) spawn(0x10, 14000, 0x10e, 0x50, "S08 original line 301: fixed controller");
    if (lateStageWindow(f, 0xe56, 0x50, 8)) {
        spawn(0x44, 0xfa, randomCoord(0x155, 0x3c), -20, "S08 original line 317: narrow top wave");
    }
    if (lateStageWindow(f, 0xece, 0x50, 8)) {
        spawn(0x44, 0xfa, randomCoord(0x155, 0x140), -20, "S08 original line 334: narrow top wave");
    }
    if (f == 0x1004) spawn(0x46, 0x960, -300, 0x32, "S08 original line 339: left sweep");
    if (f == 0x1022) spawn(0x46, 0x960, 0x3fc, 0x32, "S08 original line 343: right sweep");
    if (f == 0x109a) spawn(0x46, 0x960, -300, 100, "S08 original line 347: left sweep");
    if (f == 0x10b8) spawn(0x46, 0x960, 0x3fc, 100, "S08 original line 351: right sweep");
    if (lateStageWindow(f, 0x11f8, 100, 0x0f)) {
        spawn(0x45, 400, 0x2e4, randomCoord(0x83, 0x78), "S08 original line 362: right wave");
    }
    if (lateStageWindow(f, 0x1432, 0xa0, 5)) {
        spawn(0x44, 200, randomCoord(0x281, 0x28), -20, "S08 original line 373: dense top wave");
    }
    if (lateStageWindow(f, 0x1518, 0x32, 0x1e)) {
        for (int x : {0x50, 0xdc, 0x168, 500, 0x26c}) {
            spawn(0x45, 400, x, -20, "S08 original lines 378-382: five-lane wall");
        }
    }
    if (f == 0x16a8) {
        spawn(0x46, 0x960, -300, 100, "S08 original lines 386-387: sweep pair");
        spawn(0x46, 0x960, 0x3fc, 100, "S08 original lines 386-387: sweep pair");
    }
    if (f == 0x186a) {
        if (config_.setupGroup == 0) spawn(0x9c, 9000, 0x21c, 200, "S08 original line 392: route controller");
        if (config_.setupGroup == 1) spawn(0x9f, 7000, 0x21c, 200, "S08 original line 396: route controller");
        if (config_.setupGroup == 2) spawn(0xa2, 7000, 0x21c, 200, "S08 original line 400: route controller");
    }
    if (lateStageWindow(f, 0x18d8, 0x8c, 0x3c)) {
        for (int x : {0x50, 0xdc, 0x168, 500, 0x26c}) {
            spawn(0x0b, 300, x, -20, "S08 original lines 406-410: five-lane wall");
        }
    }
    if (f == 0x19fa) spawn(0x08, 5000, 0x136, 0, "S08 original line 414: common marker");

    if (lateStageWindow(f, 0x1af4, 0x3c, 10)) {
        spawn(0x70, 0x15e, 0x2e4, randomCoord(0xc9, 100), "S08 original line 425: right wave");
    }
    if (lateStageWindow(f, 7000, 0x3c, 10)) {
        spawn(0x70, 0x15e, -20, randomCoord(0xc9, 100), "S08 original line 436: left wave");
    }
    if (lateStageWindow(f, 0x1bbc, 0x3c, 0x10)) {
        spawn(0x70, 0x15e, reverseRandomCoord(0xc9, 0x136), -20,
              "S08 original line 452: mirrored top pair");
        spawn(0x70, 0x15e, randomCoord(0xc9, 0x19a), -20,
              "S08 original line 459: mirrored top pair");
    }
    if (lateStageWindow(f, 0x1c52, 0x96, 0x14)) {
        spawn(0x37, 300, randomCoord(0x1e1, 0x78), randomCoord(0x97, 400),
              "S08 original lines 464-473: random drifter");
    }
    if (f == 0x1c20) spawn(0x71, 5000, 0x1b8, 200, "S08 original line 477: fixed setpiece");
    if (f == 0x1cac) spawn(0x72, 5000, 0x118, 200, "S08 original line 481: fixed setpiece");
    if (f == 0x1d38) spawn(0x71, 5000, 0x1e0, 0xfa, "S08 original line 485: fixed setpiece");
    {
        const int local = f - 0x1dec;
        if (local >= 0 && local < 0x1cc && local % 0x82 < 0x3c &&
            (local % 0x82) % 8 == 0) {
            spawn(0x44, 0xfa, randomCoord(0x259, 0x3c), -20,
                  "S08 original lines 488-501: cyclic top wave");
        }
    }
    if (f == 0x1db0) spawn(0x1c, 0x1130, -120, 0, "S08 original line 506: fixed setpiece");
    if (f == 0x1e32) spawn(0x1c, 0x1130, 0x348, 0x1e, "S08 original line 510: fixed setpiece");
    if (f == 0x1eb4) spawn(0x1c, 0x1130, -120, 0x3c, "S08 original line 514: fixed setpiece");
    if (f == 0x1f36) spawn(0x1c, 0x1130, 0x348, 0x5a, "S08 original line 518: fixed setpiece");
    if (lateStageWindow(f, 0x2008, 100, 0x10)) {
        spawn(0x0b, 300, reverseRandomCoord(0xc9, 0x136), -20,
              "S08 original line 534: mirrored top pair");
        spawn(0x0b, 300, randomCoord(0xc9, 0x19a), -20,
              "S08 original line 541: mirrored top pair");
    }

    if (f == 0x20a8) {
        spawn(0xa4, 75000, 0x334, 0xb4, "S08 original line 547: first gate controller");
        stage08GateFlag_ = true;
    }
    else if (!stage08GateFlag_ && f >= 0x20d0 && f < 0x20d0 + 0x898) {
        if (lateStageWindow(f, 0x2260, 0x44c, 0x1e)) {
            spawn(0x70, 0x15e, reverseRandomCoord(0x1f5, 0x262), -20,
                  "S08 original line 561: first gate top wave");
        }
        if (lateStageWindow(f, 0x2260, 0x44c, 0x10)) {
            spawn(0x0b, 300, reverseRandomCoord(0x1f5, 0x262), -20,
                  "S08 original line 578: first gate dense top wave");
        }
        if (lateStageWindow(f, 10000, 300, 0x16)) {
            spawn(0x1a, 300, reverseRandomCoord(0x1b9, 0x244), -20,
                  "S08 original line 590: first gate top wave");
        }
        if (lateStageWindow(f, 0x2738, 0x104, 100)) {
            spawn(0x38, 0xe10, reverseRandomCoord(0x1b9, 0x244), -20,
                  "S08 original line 601: first gate heavy wave");
        }
    }
    if (f == 0x28a0) spawn(0x26, 3000, 0x168, -20, "S08 original line 607: fixed top anchor");
    if (f == 0x28d2) {
        spawn(0x26, 3000, 0x21c, -20, "S08 original lines 611-612: fixed top pair");
        spawn(0x26, 3000, 0xb4, -20, "S08 original lines 611-612: fixed top pair");
    }

    if (f == 0x2a30) {
        static constexpr std::array<std::array<int, 2>, 6> kType1dPath{{
            {{310, -430}}, {{415, -470}}, {{512, -430}},
            {{600, -4520}}, {{660, -4600}}, {{80, -4640}},
        }};
        static constexpr std::array<std::array<int, 2>, 6> kType2cPath{{
            {{60, -1790}}, {{265, -1790}}, {{465, -1790}},
            {{660, -1790}}, {{85, -4030}}, {{635, -4030}},
        }};
        static constexpr std::array<std::array<int, 2>, 6> kType5aPath{{
            {{108, -470}}, {{215, -500}}, {{610, -500}},
            {{110, -4540}}, {{495, -4540}}, {{565, -4650}},
        }};
        static constexpr std::array<std::array<int, 2>, 2> kType1ePath{{
            {{400, -2795}}, {{640, -2795}},
        }};
        static constexpr std::array<std::array<int, 2>, 2> kType2dPath{{
            {{230, -4065}}, {{490, -4065}},
        }};
        static constexpr std::array<std::array<int, 2>, 8> kType5dPath{{
            {{160, -1850}}, {{360, -1850}}, {{560, -1850}}, {{245, -2280}},
            {{140, -2440}}, {{240, -2600}}, {{225, -4580}}, {{380, -4580}},
        }};
        static constexpr std::array<std::array<int, 2>, 4> kType97Path{{
            {{120, -5480}}, {{600, -5480}}, {{185, -5590}}, {{535, -5590}},
        }};
        for (std::size_t i = 0; i < kType1dPath.size(); ++i) {
            spawn(0x1d, 0x640, kType1dPath[i][0], kType1dPath[i][1],
                  "S08 original lines 651-652: 0x1d path");
            spawn(0x2c, 0x640, kType2cPath[i][0], kType2cPath[i][1],
                  "S08 original lines 653-654: 0x2c path");
            spawn(0x5a, 0x640, kType5aPath[i][0], kType5aPath[i][1],
                  "S08 original lines 655-656: 0x5a path");
        }
        for (std::size_t i = 0; i < kType1ePath.size(); ++i) {
            spawn(0x1e, 0x708, kType1ePath[i][0], kType1ePath[i][1],
                  "S08 original lines 661-662: 0x1e path");
            spawn(0x2d, 0x1194, kType2dPath[i][0], kType2dPath[i][1],
                  "S08 original lines 663-664: 0x2d path");
        }
        for (const auto& point : kType5dPath) spawn(0x5d, 0xc80, point[0], point[1], "S08 original lines 669-670: 0x5d path");
        for (const auto& point : kType97Path) spawn(0x97, 0x708, point[0], point[1], "S08 original lines 675-676: 0x97 path");
        spawn(0x20, 14000, 200, -0xb22, "S08 original line 679: path controller");
        spawn(0x5e, 0x157c, 0x208, -0xb54, "S08 original line 680: path controller");
        spawn(0x1f, 8000, 0x1c2, -0x139c, "S08 original line 681: path controller");
        spawn(0x1f, 8000, 0x127, -0x143c, "S08 original line 682: path controller");
        spawn(0x5f, 0x34bc, 0x168, -0x157c, "S08 original line 683: path controller");
    }
    if (lateStageWindow(f, 0x2de6, 0x226, 0x5a)) {
        for (int x : {0x10e, 0x168, 0x1c2}) spawn(0x95, 1000, x, -50, "S08 original lines 688-690: 0x95 wall");
    }
    if (lateStageWindow(f, 0x37dc, 400, 0x5a)) {
        spawn(0x95, 0x4b0, 0xe6, -50, "S08 original lines 695-696: 0x95 pair");
        spawn(0x95, 0x4b0, 0x1ea, -50, "S08 original lines 695-696: 0x95 pair");
    }
    if (lateStageWindow(f, 0x2b5c, 800, 0x5a)) {
        spawn(0x5b, 800, 0x302, f - 0x2d14, "S08 original line 701: routed 0x5b");
        spawn(0x5b, 800, -50, f - 0x2d82, "S08 original line 702: routed 0x5b");
    }
    if (lateStageWindow(f, 0x30d4, 900, 0x5a)) {
        spawn(0x5b, 1000, -50, f - 0x3264, "S08 original line 707: routed 0x5b");
    }
    if (lateStageWindow(f, 0x3520, 800, 0x5a)) {
        spawn(0x98, 1000, 0x302, f - 0x3714, "S08 original line 712: routed 0x98");
    }
    for (std::size_t i = 0; i < kLate96Path.size(); ++i) {
        const int baseFrame = 0x3e08 + static_cast<int>(i) * 0x0f;
        const int spawnFrame = i < 3 ? baseFrame - 0x118 : baseFrame;
        if (f == spawnFrame) {
            spawn(0x96, 700, kLate96Path[i][0],
                  100 - kLate96Path[i][1] + f - 0x3cf0,
                  "S08 original lines 715-739: late routed 0x96 formation");
        }
    }

    if (lateStageWindow(f, 0x2a62, 100, 8)) spawn(0x35, 0xfa, -20, 0x96, "S08 original line 748: left wave");
    if (f == 0x2ac6) spawn(0x1b, 3000, 0xf0, 0, "S08 original line 753: fixed anchor");
    if (lateStageWindow(f, 11000, 100, 8)) spawn(0x35, 0xfa, 0x2e4, 0x96, "S08 original line 763: right wave");
    if (f == 0x2b5c) spawn(0x1b, 3000, 0x1e0, 0, "S08 original line 768: fixed anchor");
    if (f == 0x2c56) spawn(0x4a, 9000, 0x168, 0, "S08 original line 772: fixed controller");
    if (lateStageWindow(f, 12000, 0x3c, 8)) spawn(0x35, 200, 0x2e4, 0x96, "S08 original line 782: right wave");
    if (lateStageWindow(f, 0x2f58, 0x32, 8)) spawn(0x35, 200, -20, 0xb4, "S08 original line 793: left wave");
    if (lateStageWindow(f, 0x3002, 0x32, 8)) spawn(0x35, 200, 0x2e4, 0x15e, "S08 original line 804: right wave");
    if (lateStageWindow(f, 0x30ac, 0x32, 8)) spawn(0x35, 200, -20, 0x15e, "S08 original line 815: left wave");
    if (lateStageWindow(f, 13000, 100, 8)) spawn(0x35, 0xfa, 0x2e4, 0x78, "S08 original line 826: right wave");
    if (f == 0x3390) spawn(0x9b, 6000, 0x230, 0xb4, "S08 original line 831: fixed setpiece");
    if (f == 0x367e) spawn(0x9e, 5000, 0xdc, 0x96, "S08 original line 835: fixed setpiece");
    if (f == 0x3840) spawn(0x3a, 10000, 800, 200, "S08 original line 839: fixed carrier");
    if (f == 0x3afc) spawn(0xa1, 9000, 0x21c, 0x96, "S08 original line 843: fixed setpiece");
    if (lateStageWindow(f, 0x3b60, 100, 0x14)) {
        spawn(0x0b, 0xfa, randomCoord(0x259, 0x3c), -20, "S08 original line 854: top wave");
    }
    if (!stage08GateFlag_ && lateStageWindow(f, 0x4010, 300, 0x0d)) {
        spawn(0x0b, 300, randomCoord(0x259, 0x3c), -20, "S08 original line 866: gate-open top wave");
    }
    if (lateStageWindow(f, 0x413c, 200, 0x10)) {
        const int local = f - 0x413c;
        spawn(0x0a, 1000, (local * 7) % 0x1e0 + 0x78, 0x4236 - f,
              "S08 original line 877: rising route");
    }
    if (lateStageWindow(f, 0x4290, 0x6e, 0x0f)) {
        spawn(0x0c, 400, randomCoord(0x259, 0x3c), -20, "S08 original line 889: top wave");
    }
    if (lateStageWindow(f, 0x43a8, 0x28, 0x0f)) {
        const int local = f - 0x43a8;
        spawn(0x70, 500, 0x136 - (local * 6) % 0xf0, 0x30c, "S08 original lines 894-895: bottom pair");
        spawn(0x70, 500, (local * 6) % 0xf0 + 0x19a, 0x30c, "S08 original lines 894-895: bottom pair");
    }
    if (lateStageWindow(f, 0x440c, 0x28, 0x0f)) {
        const int local = f - 0x440c;
        spawn(0x70, 500, 0x136 - (local * 6) % 0xf0, 0x30c, "S08 original lines 900-901: bottom pair");
        spawn(0x70, 500, (local * 6) % 0xf0 + 0x19a, 0x30c, "S08 original lines 900-901: bottom pair");
    }
    if (f == 0x44c0) spawn(0x0f, 0x1194, -120, 0xfa, "S08 original line 905: fixed setpiece");
    if (f == 0x44f2) spawn(0x0f, 0x1194, 0x348, 200, "S08 original line 909: fixed setpiece");
    if (f == 0x4524) spawn(0x0f, 0x1194, -120, 0x96, "S08 original line 913: fixed setpiece");
    if (f == 0x4556) spawn(0x0f, 0x1194, 0x348, 100, "S08 original line 917: fixed setpiece");
    if (f == 18000) spawn(0x3d, 10000, 0x398, 0x96, "S08 original line 921: fixed anchor");
    if (lateStageWindow(f, 0x4696, 0x50, 8)) spawn(0x35, 0xfa, 0x2e4, 0x78, "S08 original line 931: right wave");
    if (f == 0x474a) spawn(0x73, 7000, 0x1cc, 0, "S08 original line 936: fixed setpiece");
    if (lateStageWindow(f, 0x475e, 0x50, 8)) spawn(0x35, 0xfa, -20, 0xa0, "S08 original line 946: left wave");
    if (f == 0x4812) spawn(0x73, 7000, 0x104, 0, "S08 original line 951: fixed setpiece");
    if (f == 0x4876) {
        for (int x : {0xd2, 300, 0x186, 0x1e0}) spawn(0x25, 700, x, -20, "S08 original lines 955-958: four-lane wall");
    }
    if (f == 0x48a8) {
        for (int x : {0xf0, 0x14a, 0x1a4, 0x1fe}) spawn(0x25, 700, x, -20, "S08 original lines 962-965: four-lane wall");
    }

    if (f == 0x490c) {
        spawn(0x2e, 60000, 0x168, -120, "S08 original line 970: second gate controller");
        stage08GateFlag_ = true;
    }
    else if (!stage08GateFlag_ && f > 0x490c && f <= 0x490c + 0x577) {
        if (lateStageWindow(f, 0x4970, 0x47e, 5)) {
            spawn(0x44, 0xfa, randomCoord(0x259, 0x3c), -20,
                  "S08 original line 983: second gate dense top wave");
        }
        if (f == 20000) spawn(0x27, 4000, 0x1e0, 300, "S08 original line 987: second gate setpiece");
        if (f == 0x4e48) spawn(0x27, 4000, 0xf0, 200, "S08 original line 991: second gate setpiece");
    }
    if (f == 0x4e70) spawn(0x27, 4000, 0x1b8, 100, "S08 original line 996: fixed setpiece");
    if (f == 0x4f4c) spawn(0x29, 4000, 0xf0, 300, "S08 original line 1000: fixed setpiece");
    if (f == 0x4fb0) spawn(0x29, 4000, 0x1e0, 0xfa, "S08 original line 1004: fixed setpiece");
    if (f == 0x5014) spawn(0x29, 4000, 0xf0, 200, "S08 original line 1008: fixed setpiece");
    if (!stage08GateFlag_ && lateStageWindow(f, 0x4fb0, 400, 0x18)) {
        spawn(0x0b, 300, randomCoord(0x259, 0x3c), -20, "S08 original line 1020: gate-open top wave");
    }
    if (f == 0x50aa) spawn(0x59, 5000, -100, 200, "S08 original line 1025: fixed setpiece");
    if (f == 0x50dc) spawn(0x59, 5000, 0x334, 200, "S08 original line 1029: fixed setpiece");
    if (!stage08GateFlag_ && lateStageWindow(f, 0x50dc, 100, 0x18)) {
        spawn(0x45, 300, randomCoord(0x259, 0x3c), -20, "S08 original line 1041: gate-open top wave");
    }
    if (f == 0x51a4) spawn(0x08, 5000, 0x104, 0, "S08 original line 1045: ending marker");
}

void StageRuntime::spawnStage09OriginalSchedule() {
    const int f = frame_;
    const std::uint32_t random = lateStageRand(f);
    auto spawn = [this](int type, int hitPoints, int x, int y, const char* note) {
        spawnEnemy({frame_, type, hitPoints, x, y, note});
    };
    auto randomCoord = [f](std::uint32_t modulus, int base) {
        return lateStageRandCoord(f, modulus, base);
    };

    // Direct transcription of stage_09_gameplay_update_candidate @ 0x140128940.
    if (lateStageWindow(f, 0x10e, 0x10e, 0x3c)) {
        constexpr double kPi = 3.14159265358979323846;
        const int offset =
            -static_cast<int>(std::sin((f - 250) * kPi / 40.0) * -50.0);
        spawn(0x74, 700, offset + 0x82, 0x334, "S09 original line 31: opening formation");
        spawn(0x74, 700, offset + 0x104, 0x334, "S09 original line 32: opening formation");
        spawn(0x74, 700, offset + 0x186, 0x334, "S09 original line 33: opening formation");
        spawn(0x74, 700, offset + 0x208, 0x334, "S09 original line 34: opening formation");
        spawn(0x74, 700, offset + 0x28a, 0x334, "S09 original line 35: opening formation");
    }
    if (f == 700) {
        spawn(0x26, 3000, 0x230, -20, "S09 original line 39: fixed top anchor");
        spawn(0x26, 3000, 0xa0, -20, "S09 original line 40: fixed top anchor");
    }
    if (f == 800) {
        spawn(0x26, 3000, 0x168, -20, "S09 original line 44: fixed top anchor");
    }
    if (lateStageWindow(f, 0x398, 0x78, 0x14)) {
        spawn(0x19, 700, f * 4 - 0xdc0, -20, "S09 original line 49: linear top wave");
    }
    if (lateStageWindow(f, 0x438, 0x78, 10)) {
        spawn(0x0d, 400, -20, randomCoord(0x12d, 0x96),
              "S09 original line 60: random left wave");
    }
    if (lateStageWindow(f, 0x43d, 0x73, 10)) {
        spawn(0x0d, 400, 0x2e4, randomCoord(0x12d, 0x96),
              "S09 original line 71: random right wave");
    }
    if (f == 0x4b0) {
        spawn(0x07, 5000, 0x104, 0, "S09 original line 75: common marker");
    }

    if (f == 0x546) {
        spawn(0x146, 100000, 360, 200, "S09 original line 85: first mid-stage boss root");
        stage09GateFlag_ = true;
    }
    else if (!stage09GateFlag_ && f >= 0x640 && f < 0x640 + 2000) {
        const int localCycle = (f - 0x640) % 0x78;
        if (localCycle < 0x60 && localCycle % 0x18 == 0) {
            spawn(0x0b, 400, randomCoord(0x259, 0x3c), -20,
                  "S09 original line 103: first gate top wave");
        }
        if (lateStageWindow(f, 0x668, 0x6e0, 100)) {
            spawn(0x0e, 3000, randomCoord(0x1b9, 0x8c), 0,
                  "S09 original line 114: first gate setpiece wave");
        }
        if (f == 0xdac) {
            spawn(0x38, 3000, 0x208, 0, "S09 original line 118: first gate fixed pair");
            spawn(0x38, 3000, 0xb4, 0, "S09 original line 119: first gate fixed pair");
        }
    }

    if (f == 0xe4c) spawn(0x46, 2000, 0x460, 100, "S09 original line 124: right sweep");
    if (f == 0xe74) spawn(0x46, 2000, 0x3ca, 0x4b, "S09 original line 128: right sweep");
    if (f == 0xe92) spawn(0x46, 2000, 0x334, 0x32, "S09 original line 132: right sweep");
    if (f == 0xec4) spawn(0x46, 2000, -400, 0x50, "S09 original line 136: left sweep");
    if (f == 0xee2) spawn(0x46, 2000, -250, 0x37, "S09 original line 140: left sweep");
    if (f == 0xf00) spawn(0x46, 2000, -100, 0x1e, "S09 original line 144: left sweep");
    if (lateStageWindow(f, 0xf8c, 0x78, 0x28)) {
        for (int x = 0x6e; x <= 0x262; x += 100) {
            spawn(0x19, 500, x, -20, "S09 original lines 149-154: six-lane wall");
        }
    }

    if (f == 0x1004) {
        spawn(0x147, 100000, 360, 270, "S09 original line 162: second mid-stage boss root");
        stage09GateFlag_ = true;
    }
    else if (!stage09GateFlag_ && f >= 0x10cc && f < 0x10cc + 0x6a4) {
        if (f < 0x15e0 && lateStageWindow(f, 0x10cc, 0x514, 0x50)) {
            spawn(0x57, 0x708, static_cast<int>(random % 0x97u) + 0x262,
                  static_cast<int>(random % 0x65u) - 200,
                  "S09 original lines 180-181: second gate right wave");
        }
        if (lateStageWindow(f, 0x10ea, 0x4f6, 0x50)) {
            spawn(0x58, 0x708, static_cast<int>(random % 0x97u) - 0x28,
                  static_cast<int>(random % 0x65u) - 200,
                  "S09 original lines 193-194: second gate left wave");
        }
        if (f == 0x1644) {
            spawn(0x2b, 12000, 0x168, 0, "S09 original line 198: second gate anchor");
        }
        if (lateStageWindow(f, 0x16a8, 0x96, 0x32)) {
            spawn(0x0b, 400, 0x6e, -20, "S09 original line 203: second gate paired lanes");
            spawn(0x0b, 400, 0x262, -20, "S09 original line 204: second gate paired lanes");
        }
    }

    if (f >= 0x1798 && f < 0x1798 + 0xa0) {
        const int localCycle = (f - 0x1798) % 0x78;
        if (localCycle < 0x60 && localCycle % 0x0f == 0) {
            spawn(0x0b, 0x168, randomCoord(0x259, 0x3c), -20,
                  "S09 original line 217: staggered top wave");
        }
    }
    if (f >= 0x179d && f < 0x179d + 0x9b) {
        const int localCycle = (f - 0x179d) % 0x78;
        if (localCycle < 0x60 && localCycle % 0x0f == 0) {
            spawn(0x0b, 0x168, 0x2e4, randomCoord(0xfb, 100),
                  "S09 original line 229: staggered right wave");
        }
    }
    if (f >= 0x17a2 && f < 0x17a2 + 0x96) {
        const int localCycle = (f - 0x17a2) % 0x78;
        if (localCycle < 0x60 && localCycle % 0x0f == 0) {
            spawn(0x0b, 0x168, -20, randomCoord(0xfb, 100),
                  "S09 original line 241: staggered left wave");
        }
    }

    if (f == 0x1838) {
        spawn(0x148, 100000, 360, 200, "S09 original line 249: third mid-stage boss root");
        stage09GateFlag_ = true;
    }
    else if (!stage09GateFlag_ && f >= 0x1900 && f < 0x1900 + 2000) {
        const bool firstWall = f < 0x1bee && (f - 0x1900) % 8 == 0;
        const bool secondWall = lateStageWindow(f, 0x1c52, 200, 8);
        const bool thirdWall = lateStageWindow(f, 0x1d7e, 200, 8);
        if (firstWall || secondWall || thirdWall) {
            spawn(0x35, 0x96, 0x2e4, 100, "S09 original lines 266-269: alternating side wall");
            spawn(0x35, 0x96, -20, 0xa0, "S09 original lines 266-269: alternating side wall");
            spawn(0x35, 0x96, 0x2e4, 0xdc, "S09 original lines 266-269: alternating side wall");
            spawn(0x35, 0x96, -20, 0x118, "S09 original lines 266-269: alternating side wall");
        }
        if (f == 0x1e78) spawn(0x47, 2000, 0x1fe, 0xfa, "S09 original line 290: third gate fixed enemy");
        if (f == 0x1ec8) spawn(0x48, 2000, 0xd2, 0x96, "S09 original line 294: third gate fixed enemy");
        if (f == 0x1fd6) {
            spawn(0x58, 0x640, 0x104, -100, "S09 original lines 298-300: third gate left trio");
            spawn(0x58, 0x640, 0x6e, -150, "S09 original lines 298-300: third gate left trio");
            spawn(0x58, 0x640, -40, -200, "S09 original lines 298-300: third gate left trio");
        }
        if (f == 0x203a) {
            spawn(0x57, 0x640, 0x1cc, -200, "S09 original lines 304-306: third gate right trio");
            spawn(0x57, 0x640, 0x262, -150, "S09 original lines 304-306: third gate right trio");
            spawn(0x57, 0x640, 0x2f8, -100, "S09 original lines 304-306: third gate right trio");
        }
    }

    if (f == 0x20d0) spawn(0x08, 5000, 0x1cc, 0, "S09 original line 311: common marker");
    if (f == 0x2166) spawn(0x4d, 6000, -150, 0, "S09 original line 315: fixed left entry");
    if (lateStageWindow(f, 0x2210, 0xe6, 0x14)) {
        spawn(0x36, 0x15e, 0x2e4, randomCoord(0xc9, 300),
              "S09 original line 326: random right wave");
    }
    if (lateStageWindow(f, 0x221a, 0xdc, 0x14)) {
        spawn(0x36, 0x15e, -20, randomCoord(0xc9, 300),
              "S09 original line 337: random left wave");
    }

    if (f == 9000) {
        spawn(0x149, 100000, 360, 200, "S09 original line 345: fourth mid-stage boss root");
        stage09GateFlag_ = true;
    }
    else if (!stage09GateFlag_ && f >= 0x23f0 && f < 0x23f0 + 2000) {
        if (f < 0x27c4 && lateStageWindow(f, 0x23f0, 0x3d4, 0x18)) {
            spawn(0x0b, 400, randomCoord(0x259, 0x3c), -20,
                  "S09 original line 362: fourth gate top wave");
        }
        if (lateStageWindow(f, 0x2800, 0xf0, 10)) {
            spawn(0x0d, 400, -20, randomCoord(0x12d, 0x96),
                  "S09 original line 373: fourth gate left wave");
        }
        if (lateStageWindow(f, 0x2805, 0xeb, 10)) {
            spawn(0x0d, 400, 0x2e4, randomCoord(0x12d, 0x96),
                  "S09 original line 384: fourth gate right wave");
        }
        if (f == 0x2968) spawn(0x39, 7000, 0x262, -80, "S09 original line 388: fourth gate setpiece");
        if (lateStageWindow(f, 0x2990, 0x6e, 0x10)) {
            spawn(0x0b, 300, randomCoord(0xf1, 0x50), -20,
                  "S09 original line 404: fourth gate top burst");
        }
        if (f == 0x29cc) spawn(0x3a, 7000, -80, 200, "S09 original line 409: fourth gate setpiece");
        if (f == 0x2a30) spawn(0x39, 7000, 0x6e, -80, "S09 original line 413: fourth gate setpiece");
        if (lateStageWindow(f, 0x2a58, 0x6e, 0x10)) {
            spawn(0x0b, 300, randomCoord(0xf1, 400), -20,
                  "S09 original line 429: fourth gate top burst");
        }
        if (f == 0x2a94) spawn(0x3a, 7000, 800, 200, "S09 original line 434: fourth gate setpiece");
    }

    if (f == 0x2bf2) spawn(0x76, 12000, 0xe6, 0x348, "S09 original line 439: fixed rising entry");
    if (f == 0x2c1a) spawn(0x76, 12000, 0x1ea, 0x348, "S09 original line 443: fixed rising entry");
    if (lateStageWindow(f, 0x2da0, 0xb4, 5)) {
        spawn(0x44, 0xfa, randomCoord(0x259, 0x3c), -20,
              "S09 original line 454: dense top wave");
    }

    if (f == 0x2e54) {
        spawn(0x14a, 100000, 360, 200, "S09 original line 461: fifth mid-stage boss root");
        stage09GateFlag_ = true;
    }
    else if (!stage09GateFlag_ && f >= 12000 && f < 12000 + 0x6a4) {
        if (f < 0x3340 && lateStageWindow(f, 12000, 0x460, 0x12)) {
            spawn(0x0b, 300, randomCoord(0x1f5, 0x6e), -20,
                  "S09 original line 480: fifth gate common top wave");
        }
        if (lateStageWindow(f, 12000, 0x460, 0x18)) {
            spawn(0x19, 500, randomCoord(0x1f5, 0x6e), -20,
                  "S09 original line 492: fifth gate type 0x19 wave");
        }
        if (lateStageWindow(f, 0x3390, 300, 100)) {
            spawn(0x9b, 5000, static_cast<int>(random % 0x65u) + 0x1cc,
                  static_cast<int>(random % 0x65u) + 0x96,
                  "S09 original lines 504-505: fifth gate random setpiece");
        }
        if (f >= 0x33e0 && f < 0x33e0 + 0x168) {
            const int localCycle = (f - 0x33e0) % 0x96;
            if (localCycle < 0x3c && localCycle % 0x0f == 0) {
                spawn(0x45, 400, randomCoord(0x1e1, 0x78), -20,
                      "S09 original line 517: fifth gate clustered top wave");
            }
        }
    }

    if (f == 0x3584) spawn(0x1b, 0x1130, 0x168, 0, "S09 original line 523: fixed anchor");
    if (f == 0x35b6) spawn(0x1b, 0x1130, 0x1fe, 0, "S09 original line 527: fixed anchor");
    if (f == 0x35e8) spawn(0x1b, 0x1130, 0xd2, 0, "S09 original line 531: fixed anchor");

    if (f == 0x364c) {
        spawn(0x14b, 100000, 360, 240, "S09 original line 539: sixth mid-stage boss root");
        stage09GateFlag_ = true;
    }
    else if (!stage09GateFlag_ && f >= 0x3714 && f < 0x3714 + 2000) {
        if (f < 0x3bc4 && lateStageWindow(f, 0x3714, 1200, 0x13)) {
            spawn(0x1a, 400, randomCoord(0x231, 0x50), -20,
                  "S09 original line 555: sixth gate type 0x1a wave");
        }
        if (lateStageWindow(f, 0x3714, 0x4b0, 0x1e)) {
            spawn(0x25, 600, randomCoord(0x1f5, 0x6e), -20,
                  "S09 original line 566: sixth gate type 0x25 wave");
        }
        if (lateStageWindow(f, 0x3c28, 400, 100)) {
            spawn(0xa1, 5000, static_cast<int>(random % 0x65u) + 0xa0,
                  static_cast<int>(random % 0x65u) + 0x96,
                  "S09 original lines 578-579: sixth gate random setpiece");
        }
        if (f == 0x3e1c) {
            for (int x = 0x3c; x < 0x2d0; x += 0x3c) {
                spawn(0x44, 0xfa, x, -20, "S09 original line 585: eleven-lane wall");
            }
        }
        if (f == 0x3e44) {
            spawn(0x0f, 5000, -120, 0x96, "S09 original line 591: paired side setpiece");
            spawn(0x0f, 5000, 0x348, 0x96, "S09 original line 592: paired side setpiece");
        }
    }

    if (f == 0x3ee4) {
        spawn(0xa4, 50000, -100, 0xb4, "S09 original line 598: final gated controller");
        stage09GateFlag_ = true;
    }
    else if (!stage09GateFlag_ && f >= 0x3f48 && f < 0x3f48 + 0x44c) {
        if (f < 0x4290 && lateStageWindow(f, 0x3f48, 0x348, 10)) {
            spawn(0xad, 300, randomCoord(0x259, 0x3c), -10,
                  "S09 original lines 611-612: final gate specialized wave");
        }
        if (f == 0x42cc) spawn(0x9e, 5000, 0x1cc, 0xfa, "S09 original line 616: final gate setpiece");
        if (f == 0x42fe) spawn(0x9e, 5000, 0x104, 0xb4, "S09 original line 620: final gate setpiece");
    }
    if (f == 0x4394) {
        spawn(0x08, 5000, 0x1cc, 0, "S09 original line 625: ending marker");
    }
}

void StageRuntime::spawnStage10OriginalSchedule() {
    const int f = frame_;
    auto spawn = [this](int type, int hitPoints, int x, int y, const char* note) {
        spawnEnemy({frame_, type, hitPoints, x, y, note});
    };
    auto randomCoord = [f](std::uint32_t modulus, int base) {
        return lateStageRandCoord(f, modulus, base);
    };

    // Direct transcription of stage_10_gameplay_update_candidate @ 0x14012b260.
    if (f == 1) stage10GateFlag_ = true;
    if (f == 350) stage10GateFlag_ = false;
    if (f == 0x4c4 ||
        (config_.rawStartFrame > 0x4c4 && f == config_.rawStartFrame + 1)) {
        spawn(0x14c, 100000, 360, -2400,
              f == 0x4c4 ? "S10 original line 68: scene boss root"
                          : "S10 original line 70: late-start scene boss root");
        stage10GateFlag_ = false;
    }

    if (lateStageWindow(f, 400, 0x78, 0x0c)) {
        spawn(0xfa, 300, 0x1e0, -20, "S10 original line 82: opening top wave");
    }
    if (lateStageWindow(f, 0x196, 0x72, 0x0c)) {
        spawn(0xfa, 300, 0xf0, -20, "S10 original line 87: opening top wave");
    }
    if (lateStageWindow(f, 0x21c, 100, 0x0d)) {
        const int local = f - 0x21c;
        const int x = (local < 0x32 ? 0x3d - local : local - 0x27) * 10;
        spawn(0xfc, 800, x, -20, "S10 original line 99: folding top wave");
    }
    if (lateStageWindow(f, 700, 0x3c, 0x0c)) {
        spawn(0xfa, 300, 0x2e4, 0x96, "S10 original line 104: right wave");
    }
    if (lateStageWindow(f, 0x316, 0x3c, 0x0c)) {
        spawn(0xfa, 300, -20, 0xf0, "S10 original line 109: left wave");
    }
    if (lateStageWindow(f, 0x370, 0x3c, 0x0c)) {
        spawn(0xfa, 300, 0x2e4, 0x140, "S10 original line 114: right wave");
    }
    if (lateStageWindow(f, 0x3d4, 0x78, 10)) {
        spawn(0xfb, 400, randomCoord(0x231, 0x50), 0,
              "S10 original line 125: random field wave");
    }
    if (f == 0x44c) spawn(0x06, 5000, 0x1cc, 0, "S10 original line 129: common marker");
    if (lateStageWindow(f, 0x4e2, 0x1c2, 0x1e)) {
        spawn(0xfc, 800, randomCoord(0x1f5, 0x6e), -20,
              "S10 original line 140: random top wave");
    }
    if (lateStageWindow(f, 0x578, 0x3c, 0x0c)) {
        spawn(0xfa, 300, 0xb4, -20, "S10 original line 145: top wave");
    }
    if (lateStageWindow(f, 0x5dc, 0x3c, 0x0c)) {
        spawn(0xfa, 300, 0x2e4, 200, "S10 original line 150: right wave");
    }
    if (lateStageWindow(f, 0x640, 0x3c, 0x0c)) {
        spawn(0xfa, 300, -20, 0x168, "S10 original line 155: left wave");
    }
    if (lateStageWindow(f, 0x6a4, 0x3c, 0x0c)) {
        spawn(0xfa, 300, 0x21c, -20, "S10 original line 160: top wave");
    }
    if (lateStageWindow(f, 2000, 1000, 0x1e)) {
        spawn(0xfb, 300, randomCoord(0x231, 0x50), 0,
              "S10 original line 171: long random field wave");
    }
    if (f == 0xbea) spawn(0x103, 4000, 0x2c6, -200, "S10 original line 175: fixed entry");
    if (f == 0xc30) spawn(0x103, 4000, 0x35c, -150, "S10 original line 179: fixed entry");
    if (lateStageWindow(f, 0xcb2, 0x3c, 0x0c)) {
        spawn(0xfa, 300, 0x2e4, 0x96, "S10 original line 184: right wave");
    }
    if (lateStageWindow(f, 0xd02, 0x3c, 0x0c)) {
        spawn(0xfa, 300, -20, 0xf0, "S10 original line 189: left wave");
    }
    if (f == 0xd7a) spawn(0x104, 4000, -40, -200, "S10 original line 193: fixed entry");
    if (f == 0xdd4) spawn(0xfe, 7000, 0x21c, 200, "S10 original line 197: fixed setpiece");
    if (lateStageWindow(f, 0x10fe, 100, 0x1e)) {
        spawn(0xfc, 800, randomCoord(0x1f5, 0x6e), 0,
              "S10 original line 208: random field wave");
    }
    if (lateStageWindow(f, 0x11e4, 100, 8)) {
        spawn(0xfb, 300, randomCoord(0x231, 0x50), 0,
              "S10 original line 224: rapid random field wave");
    }
    if (f == 0x12c0) spawn(0x102, 7000, 0x1e0, 0, "S10 original line 229: fixed anchor");
    if (lateStageWindow(f, 0x1324, 0x3c, 0x0c)) {
        spawn(0xfa, 300, 0x1cc, -20, "S10 original line 234: top wave");
    }
    if (lateStageWindow(f, 5000, 0x78, 0x14)) {
        spawn(0xfd, 1000, randomCoord(0x191, 0xd2), 0,
              "S10 original line 245: random field wave");
    }
    if (lateStageWindow(f, 0x1400, 0x50, 10)) {
        spawn(0xfb, 300, randomCoord(0xc9, 0x6e), 0,
              "S10 original line 256: narrow random wave");
    }
    if (f == 0x146e) spawn(0x100, 6000, 0xb4, 300, "S10 original line 260: fixed setpiece");
    if (f == 0x14c8) spawn(0x100, 6000, 0x21c, 200, "S10 original line 264: fixed setpiece");
    if (f == 0x159a) {
        spawn(0xfd, 1000, 0x78, 0, "S10 original lines 268-271: four-lane group");
        spawn(0xfd, 1000, 0x10e, 0, "S10 original lines 268-271: four-lane group");
        spawn(0xfd, 1000, 0x1c2, 0, "S10 original lines 268-271: four-lane group");
        spawn(0xfd, 1000, 600, 0, "S10 original lines 268-271: four-lane group");
    }

    if (!stage10GateFlag_) {
        if (lateStageWindow(f, 0x16a8, 700, 0x12)) {
            spawn(0xfb, 300, randomCoord(0x17d, 0x50), 0,
                  "S10 original line 283: scene-boss gate wave");
        }
        if (lateStageWindow(f, 0x16a8, 700, 0x1e)) {
            spawn(0xfc, 800, randomCoord(0x191, 0xd2), 0,
                  "S10 original line 294: scene-boss gate wave");
        }
    }
    if (lateStageWindow(f, 0x19dc, 0x3c, 0x0c)) {
        spawn(0xfa, 300, 0x1a4, -20, "S10 original line 300: top wave");
    }
    if (f == 0x1a18) spawn(0x102, 7000, 0x168, 0, "S10 original line 304: fixed anchor");
    if (lateStageWindow(f, 0x1a7c, 0x3c, 0x0c)) {
        spawn(0xfa, 300, 300, -20, "S10 original line 309: top wave");
    }
    if (lateStageWindow(f, 0x1af4, 800, 0x1e)) {
        spawn(0xfb, 300, randomCoord(0x231, 0x50), -20,
              "S10 original line 320: long random top wave");
    }
    if (f == 7000) spawn(0xfe, 0x157c, 0xb4, 0xfa, "S10 original line 324: fixed setpiece");
    if (f == 0x1bbc) spawn(0xfe, 0x157c, 0xb4, 200, "S10 original line 328: fixed setpiece");
    if (f == 0x1c20) spawn(0xfe, 0x157c, 0xb4, 0x96, "S10 original line 332: fixed setpiece");
    if (f == 0x1d1a) spawn(0x102, 5000, 0x208, 0, "S10 original line 336: fixed anchor");
    if (f == 0x1d7e) spawn(0x102, 5000, 200, 0, "S10 original line 340: fixed anchor");
    if (f == 0x1de2) spawn(0x102, 5000, 0x168, 0, "S10 original line 344: fixed anchor");

    if (stage10GateFlag_ && lateStageWindow(f, 8000, 700, 0x1e)) {
        spawn(0xfb, 300, randomCoord(0x17d, 0x104), 0,
              "S10 original line 356: gate-closed random wave");
    }
    if (!stage10GateFlag_) {
        if (lateStageWindow(f, 8000, 700, 0x12)) {
            spawn(0xfb, 300, randomCoord(0x17d, 0x104), 0,
                  "S10 original line 368: gate-open random wave");
        }
        if (lateStageWindow(f, 8000, 700, 0x28)) {
            spawn(0xfd, 1000, randomCoord(0x191, 0x6e), 0,
                  "S10 original line 379: gate-open support wave");
        }
    }
    if (lateStageWindow(f, 0x2292, 100, 0x0f)) {
        spawn(0xfc, 800, randomCoord(0x1f5, 0x6e), 0,
              "S10 original line 392: random field wave");
    }
    if (f == 9000) spawn(0x104, 4000, 0x3c, -100, "S10 original line 396: fixed entry");
    if (f == 0x235a) spawn(0x104, 4000, -90, -150, "S10 original line 400: fixed entry");
    if (f == 0x238c) spawn(0x104, 4000, -240, -200, "S10 original line 404: fixed entry");
    if (lateStageWindow(f, 0x2454, 0x3c, 0x0c)) {
        spawn(0xfa, 300, 0x2e4, 0x168, "S10 original line 409: right wave");
    }
    if (lateStageWindow(f, 0x2490, 0x3c, 0x0c)) {
        spawn(0xfa, 300, -20, 0xf0, "S10 original line 414: left wave");
    }
    if (lateStageWindow(f, 0x24cc, 0x3c, 0x0c)) {
        spawn(0xfa, 300, 0x2e4, 0xa0, "S10 original line 419: right wave");
    }
    if (lateStageWindow(f, 0x2508, 0x3c, 0x0c)) {
        spawn(0xfa, 300, -20, 300, "S10 original line 424: left wave");
    }
    if (f == 0x2544) spawn(0x100, 6000, 0xb4, 0xfa, "S10 original line 428: fixed setpiece");
    if (f == 0x26ac) spawn(0x100, 6000, 0x21c, 0x96, "S10 original line 432: fixed setpiece");
    if (lateStageWindow(f, 0x25bc, 0x348, 0x1c)) {
        spawn(0xfb, 300, randomCoord(0x17d, 0x104), 0,
              "S10 original line 443: long random field wave");
    }
    if (f == 0x28a0) spawn(0x103, 4000, 0x35c, -120, "S10 original line 447: fixed entry");

    if (!stage10GateFlag_) {
        if (lateStageWindow(f, 0x2a30, 200, 7)) {
            spawn(0xfb, 300, randomCoord(0x231, 0x50), 0,
                  "S10 original line 460: final rapid random wave");
        }
        if (lateStageWindow(f, 11000, 400, 0x0f)) {
            spawn(0xfb, 300, randomCoord(0x231, 0x50), 0,
                  "S10 original line 472: final random wave");
        }
        if (f == 0x2b5c) spawn(0x102, 5000, 0xf0, 0, "S10 original line 476: final anchor");
        if (f == 0x2c24) spawn(0x102, 5000, 0x1e0, 0, "S10 original line 480: final anchor");
    }
    if (f == 0x2cd8 || f == 0x2d14 || f == 0x2d50) {
        for (int x = 0x3c; x <= 0x294; x += 0x78) {
            spawn(0xfc, 800, x, 0, "S10 original lines 485-490: six-lane closing wall");
        }
    }
    if (f == 0x2db4) {
        spawn(0x07, 5000, 0x104, 0, "S10 original line 494: ending marker");
    }
}

} // namespace reconstructed
