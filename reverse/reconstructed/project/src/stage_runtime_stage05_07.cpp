#include "stage_runtime.h"

#include <array>
#include <cmath>
#include <cstdint>

namespace reconstructed {
namespace {

struct SchedulePoint {
    int x;
    int y;
};

std::uint32_t stageScheduleRandFromFrame(int frame) {
    const auto seed = static_cast<std::uint32_t>(frame);
    const std::uint32_t u = ((seed >> 30) ^ seed) * 0x6c078965u + 1u;
    const std::uint32_t a = ((u >> 30) ^ u) * 0x6c078965u + 2u;
    const std::uint32_t b = ((a >> 30) ^ a) * 0x6c078965u + 3u;
    const std::uint32_t c = ((b >> 30) ^ b) * 0x6c078965u + 4u;
    const std::uint32_t mixed = u * 0x800u ^ u;
    return (((c >> 11) ^ mixed) >> 8) ^ c ^ mixed;
}

bool isScheduleFrame(int frame, int start, int duration, int interval) {
    const int local = frame - start;
    return local >= 0 && local < duration && local % interval == 0;
}

// The Stage 6 formations are copied from the float pairs at
// 0x14053c030..0x14053c558. The original truncates each float to int.
constexpr std::array<SchedulePoint, 21> kStage06Formation1Small{{
    {305, -185}, {545, -195}, {210, -300}, {395, -290}, {515, -340},
    {650, -315}, {430, -470}, {80, -945}, {200, -935}, {333, -935},
    {470, -950}, {650, -1035}, {55, -1080}, {395, -1085}, {540, -1120},
    {120, -4520}, {600, -4520}, {80, -4670}, {395, -4715}, {505, -4660},
    {640, -4675},
}};

constexpr std::array<SchedulePoint, 12> kStage06Formation1Medium{{
    {300, -430}, {560, -465}, {615, -1240}, {465, -1285},
    {120, -3030}, {285, -3165}, {435, -3285}, {590, -3390},
    {100, -4350}, {265, -4315}, {455, -4315}, {620, -4350},
}};

constexpr std::array<SchedulePoint, 5> kStage06Formation1Large{{
    {235, -1100}, {550, -1470}, {465, -3845}, {230, -4005}, {240, -4735},
}};

constexpr std::array<SchedulePoint, 25> kStage06Formation2Small{{
    {100, -220}, {215, -225}, {660, -220}, {60, -360}, {175, -360},
    {375, -370}, {505, -370}, {620, -355}, {290, -465}, {410, -520},
    {285, -740}, {395, -810}, {290, -900}, {430, -930}, {500, -1255},
    {630, -1230}, {75, -3020}, {514, -3010}, {634, -2990}, {128, -3175},
    {260, -3160}, {80, -3310}, {385, -3360}, {515, -3380}, {645, -3370},
}};

constexpr std::array<SchedulePoint, 5> kStage06Formation2Medium{{
    {350, -235}, {520, -235}, {380, -660}, {215, -3000}, {375, -3000},
}};

constexpr std::array<SchedulePoint, 3> kStage06Formation2Large{{
    {605, -770}, {520, -2745}, {230, -3350},
}};

} // namespace

void StageRuntime::spawnStage05OriginalSchedule() {
    const int f = frame_;
    const std::uint32_t random = stageScheduleRandFromFrame(f);
    const auto randCoord = [&](int modulus, int base) {
        return static_cast<int>(random % static_cast<std::uint32_t>(modulus)) + base;
    };
    const auto spawn = [this](int type, int hitPoints, int x, int y, const char* note) {
        spawnEnemy({frame_, type, hitPoints, x, y, note});
    };

    if (isScheduleFrame(f, 0xfa, 100, 0xf))
        spawn(0x44, 0xfa, randCoord(0x15f, 0x168), -20, "S05 original line 31");
    if (f == 0x15e) spawn(0x46, 3000, 0x42e, 0x32, "S05 original line 35");
    if (f == 0x17c) spawn(0x46, 3000, 0x366, 0, "S05 original line 39");
    if (isScheduleFrame(f, 0x1c2, 100, 0xf))
        spawn(0x44, 0xfa, randCoord(0x15f, 10), -20, "S05 original line 50");
    if (f == 0x226) spawn(0x46, 3000, -350, 0x32, "S05 original line 54");
    if (f == 0x244) spawn(0x46, 3000, -150, 0, "S05 original line 58");
    if (isScheduleFrame(f, 0x294, 100, 0x13))
        spawn(0x45, 500, 0x2e4, randCoord(0x97, 0x78), "S05 original line 69");
    if (f == 800) spawn(7, 5000, 0x1cc, 0, "S05 original line 73");
    if (f == 900) spawn(0x47, 3000, 0x104, 0x96, "S05 original line 77");
    if (isScheduleFrame(f, 0x410, 0x50, 0x1f))
        spawn(0x45, 400, randCoord(0x97, 0x19a), -20, "S05 original line 88");
    if (isScheduleFrame(f, 0x492, 100, 0x18))
        spawn(0x45, 400, -20, randCoord(0x97, 0x96), "S05 original line 99");
    if (f == 0x4f6) spawn(0x46, 3000, 0x3fc, 0x32, "S05 original line 103");
    if (f == 0x51e) spawn(0x46, 3000, -300, 0x32, "S05 original line 107");
    if (isScheduleFrame(f, 0x564, 200, 0xe))
        spawn(0x44, 0xfa, randCoord(0x191, 0xa0), -20, "S05 original line 118");
    if (f == 0x640) spawn(0x46, 0x960, -400, 0x32, "S05 original line 122");
    if (f == 0x65e) spawn(0x46, 0x960, -250, 0x4b, "S05 original line 126");
    if (f == 0x67c) spawn(0x46, 0x960, -100, 100, "S05 original line 130");
    if (f == 0x6b8) spawn(0x46, 0x960, 0x398, 0x1e, "S05 original line 134");
    if (f == 0x708) spawn(0x4a, 11000, 0x1cc, 0, "S05 original line 138");
    if (f == 0x7f8) spawn(0x4a, 9000, 0x104, 0, "S05 original line 142");
    if (isScheduleFrame(f, 0x884, 100, 0x14))
        spawn(0x0b, 300, randCoord(0x12d, 0x104), -20, "S05 original line 153");
    if (f == 0x8e8) spawn(0x4a, 9000, 0x19a, 0, "S05 original line 157");
    if (isScheduleFrame(f, 0x974, 0x50, 0xf))
        spawn(0x45, 300, randCoord(0x12d, 0xa0), -20, "S05 original line 168");
    if (f == 0x9c4) spawn(0x4a, 9000, 0x136, 0, "S05 original line 172");
    if (f == 0xa8c) spawn(0x29, 7000, 0xf0, 300, "S05 original line 176");
    if (isScheduleFrame(f, 0xabe, 0x32, 10))
        spawn(0x44, 0xfa, randCoord(0x1c3, 0x104), -20, "S05 original line 187");
    if (isScheduleFrame(f, 0xb22, 0x32, 10))
        spawn(0x44, 0xfa, randCoord(0x1c3, 10), -20, "S05 original line 198");
    if (f == 0xb54) spawn(0x48, 0x960, 0x1cc, 0x96, "S05 original line 202");
    if (isScheduleFrame(f, 0xbea, 0x50, 0x14))
        spawn(0x0b, 300, -20, randCoord(0x97, 100), "S05 original line 213");
    if (f == 0xc6c) spawn(0x46, 0x960, 0x3fc, 100, "S05 original line 217");
    if (f == 0xc80) spawn(0x46, 0x960, -300, 100, "S05 original line 221");
    if (f == 0xcbc) spawn(0x46, 0x960, 0x42e, 0x14, "S05 original line 225");
    if (f == 0xcd0) spawn(0x46, 0x960, -350, 0x14, "S05 original line 229");
    if (isScheduleFrame(f, 0xd7a, 100, 10))
        spawn(0x44, 0xfa, randCoord(0x2bd, 10), -20, "S05 original line 240");
    if (f == 0xe10) spawn(0x4d, 6000, -150, 0, "S05 original line 244");
    if (f == 0xf6e) spawn(0x29, 7000, 0x1e0, 0xfa, "S05 original line 248");
    if (isScheduleFrame(f, 0xfd2, 0x50, 0x3c)) {
        spawn(0x45, 300, 0xb4, -20, "S05 original line 253");
        spawn(0x45, 300, 0x168, -20, "S05 original line 254");
        spawn(0x45, 300, 0x21c, -20, "S05 original line 255");
    }
    if (f == 0x1068) spawn(0x4d, 6000, 0x366, 0, "S05 original line 259");
    if (isScheduleFrame(f, 0x1162, 0x82, 10))
        spawn(0x44, 0xfa, randCoord(0x2bd, 10), -20, "S05 original line 270");
    if (isScheduleFrame(f, 0x1220, 0x32a, 0x60))
        spawn(0x45, 300, 0x2e4, randCoord(0xc9, 0x32), "S05 original line 281");
    if (isScheduleFrame(f, 0x1250, 0x2fa, 0x60))
        spawn(0x45, 300, -20, randCoord(0xc9, 0x32), "S05 original line 292");
    if (f == 0x12c0) spawn(0x4a, 7000, 0x104, 0, "S05 original line 296");
    if (f == 5000) spawn(0x4a, 7000, 0x1cc, 0, "S05 original line 300");
    if (f == 0x14c8) spawn(0x46, 0x960, -100, 0x32, "S05 original line 304");
    if (f == 0x14e6) spawn(0x46, 0x960, -250, 0x4b, "S05 original line 308");
    if (f == 0x1504) spawn(0x46, 0x960, -400, 100, "S05 original line 312");
    if (f == 0x157c) spawn(0x47, 0x960, 0xf0, 0x96, "S05 original line 316");
    if (isScheduleFrame(f, 0x1608, 0x82, 0x20))
        spawn(0x0b, 300, randCoord(0xf1, 0x168), -20, "S05 original line 332");
    if (f == 0x16a8) spawn(0x48, 0x960, 0x1e0, 0x96, "S05 original line 337");
    if (isScheduleFrame(f, 0x1734, 0x82, 0x20))
        spawn(0x0b, 300, randCoord(0xf1, 0x78), -20, "S05 original line 353");
    if (f == 0x17d4) spawn(0x47, 0x960, 0xf0, 0x96, "S05 original line 358");

    if (f == 0x18ce) {
        spawn(0x4f, 60000, 0x168, 200, "S05 original line 363: midboss");
        stage05GateFlag_ = true;
    }
    if (!stage05GateFlag_) {
        if (isScheduleFrame(f, 0x1900, 0x4e2, 0x96))
            spawn(0x46, 2000, randCoord(0x65, -350), randCoord(0x65, 0), "S05 original line 376");
        if (isScheduleFrame(f, 0x194b, 0x497, 0x96))
            spawn(0x46, 2000, randCoord(0x65, 0x3ca), randCoord(0x65, 0), "S05 original line 389");
        if (isScheduleFrame(f, 0x1900, 0x514, 0x11))
            spawn(0x45, 300, randCoord(0x259, 0x3c), -20, "S05 original line 401");
    }

    if (f == 0x1e3c) spawn(0x46, 0x898, -100, 100, "S05 original line 406");
    if (f == 0x1e50) spawn(0x46, 0x898, -250, 0x4b, "S05 original line 410");
    if (f == 0x1e64) spawn(0x46, 0x898, -400, 0x32, "S05 original line 414");
    if (f == 0x1eaa) spawn(0x46, 0x898, 0x334, 0x4b, "S05 original line 418");
    if (f == 0x1ebe) spawn(0x46, 0x898, 0x3ca, 0x32, "S05 original line 422");
    if (f == 0x1ed2) spawn(0x46, 0x898, 0x460, 0x19, "S05 original line 426");
    if (f == 8000) {
        spawn(0x46, 0x640, -400, 100, "S05 original line 430");
        spawn(0x46, 0x640, 0x460, 0x78, "S05 original line 431");
    }
    if (f == 0x1f72) {
        spawn(0x46, 0x640, -250, 100, "S05 original line 435");
        spawn(0x46, 0x640, 0x3ca, 0x3c, "S05 original line 436");
    }
    if (f == 0x1fa4) {
        spawn(0x46, 0x640, -100, 100, "S05 original line 440");
        spawn(0x46, 0x640, 0x334, 0, "S05 original line 441");
    }
    if (f == 0x203a) spawn(0x47, 0x960, 0xf0, 200, "S05 original line 445");
    if (f == 0x20d0) spawn(0x48, 0x960, 0x1e0, 0x96, "S05 original line 449");
    if (isScheduleFrame(f, 0x2166, 100, 10))
        spawn(0x44, 0xfa, randCoord(0xfb, 0xa0), -20, "S05 original line 460");
    if (isScheduleFrame(f, 0x21fc, 100, 10))
        spawn(0x44, 0xfa, randCoord(0x15f, 0x136), -20, "S05 original line 471");
    if (f == 0x2260) spawn(0x4a, 8000, 0x136, 0, "S05 original line 475");
    if (isScheduleFrame(f, 9000, 0x8c, 8))
        spawn(0x44, 0xfa, randCoord(0x259, 0x3c), -20, "S05 original line 491");
    if (f == 0x23f0) spawn(0x4d, 6000, 0x366, 0, "S05 original line 496");
    if (f == 0x24ea) spawn(0x46, 0x898, -250, 100, "S05 original line 500");
    if (f == 0x2508) spawn(0x46, 0x898, -400, 0x32, "S05 original line 504");
    if (f == 0x254e) spawn(0x46, 0x898, 0x3ca, 100, "S05 original line 508");
    if (f == 0x256c) spawn(0x46, 0x898, 0x460, 0x32, "S05 original line 512");
    if (isScheduleFrame(f, 0x25d0, 100, 0x11))
        spawn(0x45, 300, -20, randCoord(0x97, 100), "S05 original line 523");
    if (isScheduleFrame(f, 0x2648, 0x78, 0x13))
        spawn(0x45, 300, randCoord(0x12d, 0x104), -20, "S05 original line 534");
    if (f == 0x26ac) spawn(0x4a, 10000, 0x136, 0, "S05 original line 538");
    if (f == 0x27a6) spawn(0x4d, 6000, -150, 0, "S05 original line 542");
    if (isScheduleFrame(f, 0x28a0, 0x96, 0x13))
        spawn(0x45, 300, 0x2e4, randCoord(0x97, 100), "S05 original line 553");
    if (isScheduleFrame(f, 0x2954, 0xa0, 10))
        spawn(0x44, 0xfa, randCoord(0x259, 0x3c), -20, "S05 original line 564");
    if (f == 0x29fe) spawn(0x46, 0x898, -400, 100, "S05 original line 568");
    if (f == 0x2a1c) spawn(0x46, 0x898, -250, 0x32, "S05 original line 572");
    if (f == 0x2a3a) spawn(0x46, 0x898, -100, 0, "S05 original line 576");
    if (isScheduleFrame(f, 0x2a94, 200, 0x11))
        spawn(0x45, 300, randCoord(0x1e1, 0x78), -20, "S05 original line 588");
    if (f == 0x2b5c) spawn(8, 5000, 0x104, 0, "S05 original line 592");
}

void StageRuntime::spawnStage06OriginalSchedule() {
    const int f = frame_;
    const std::uint32_t random = stageScheduleRandFromFrame(f);
    const auto randCoord = [&](int modulus, int base) {
        return static_cast<int>(random % static_cast<std::uint32_t>(modulus)) + base;
    };
    const auto spawn = [this](int type, int hitPoints, int x, int y, const char* note) {
        spawnEnemy({frame_, type, hitPoints, x, y, note});
    };

    if (f == 0xfa) spawn(0x57, 0x960, 0x230, -150, "S06 original line 79");
    if (f == 0x118) spawn(0x57, 0x960, 0x2f8, -150, "S06 original line 82");
    if (isScheduleFrame(f, 0x15e, 0x50, 0xe))
        spawn(0x1a, 300, randCoord(0x1c3, 0x6e), -20, "S06 original line 93");
    if (isScheduleFrame(f, 0x1e0, 0x46, 0xc))
        spawn(0x0b, 300, -20, randCoord(0xc9, 100), "S06 original line 104");
    if (f == 0x24e) spawn(0x58, 0x960, 0xa0, -150, "S06 original line 108");
    if (f == 0x262) spawn(0x58, 0x960, -40, -150, "S06 original line 112");
    if (isScheduleFrame(f, 0x294, 0x8c, 0x14))
        spawn(0x0d, 300, 0x2e4, randCoord(0x65, 0xfa), "S06 original line 123");
    if (isScheduleFrame(f, 800, 0x8c, 0x14))
        spawn(0x0d, 300, -20, randCoord(0x65, 300), "S06 original line 134");
    if (f == 900) spawn(7, 5000, 0x104, 0, "S06 original line 138");
    if (f == 1000) spawn(0x57, 0x960, 0x294, -150, "S06 original line 142");
    if (f == 0x3fc) spawn(0x57, 0x960, 0x348, -180, "S06 original line 146");

    if (f == 0x44c) {
        for (const auto& point : kStage06Formation1Small)
            spawn(0x5a, 0x44c, point.x, point.y, "S06 original lines 151-196: formation 1 small");
        for (const auto& point : kStage06Formation1Medium)
            spawn(0x5d, 0xc80, point.x, point.y, "S06 original lines 171-202: formation 1 medium");
        for (const auto& point : kStage06Formation1Large)
            spawn(0x5e, 0x15e0, point.x, point.y, "S06 original lines 183-207: formation 1 large");
        spawn(0x5f, 0x2b5c, 0x168, -4490, "S06 original line 208: formation 1 core");
    }
    if (isScheduleFrame(f, 0x4b0, 800, 0x50))
        spawn(0x5c, 800, 0x302, f - 0x64a, "S06 original line 213");
    if (isScheduleFrame(f, 0x4d8, 0x2f8, 0x50))
        spawn(0x5c, 800, 0x302, f - 0x6b8, "S06 original line 218");
    if (isScheduleFrame(f, 0x898, 800, 0x50))
        spawn(0x5c, 800, -50, f - 0xa3c, "S06 original line 223");
    if (isScheduleFrame(f, 0x8c0, 0x2f8, 0x50))
        spawn(0x5c, 800, -50, f - 0xaa5, "S06 original line 228");
    if (isScheduleFrame(f, 0xd48, 800, 0x50))
        spawn(0x5b, 800, 0x302, f - 0xeec, "S06 original line 233");
    if (isScheduleFrame(f, 0xd70, 0x2f8, 0x50))
        spawn(0x5b, 800, -50, f - 0xf5a, "S06 original line 238");
    if (isScheduleFrame(f, 0x10cc, 800, 0x50))
        spawn(0x5b, 800, -50, f - 0x1252, "S06 original line 243");
    if (isScheduleFrame(f, 0x10f4, 0x2f8, 0x50))
        spawn(0x5b, 800, 0x302, f - 0x12c0, "S06 original line 248");
    if (isScheduleFrame(f, 0x488, 0xf0, 0x14))
        spawn(0x0b, 300, randCoord(0x1f5, 0x6e), -20, "S06 original line 259");
    if (f == 0x6a4) {
        spawn(0x57, 0x898, 0x1ae, -120, "S06 original line 263");
        spawn(0x57, 0x898, 0x244, -160, "S06 original line 264");
    }
    if (isScheduleFrame(f, 0xa28, 0x78, 0xf))
        spawn(0x0b, 300, -20, randCoord(0xc9, 100), "S06 original line 275");
    if (isScheduleFrame(f, 0xabe, 100, 0xf))
        spawn(0x1a, 300, randCoord(0x15f, 0x136), -20, "S06 original line 286");
    if (f == 0xc80) spawn(0x59, 0x22b8, -100, 200, "S06 original line 290");
    if (isScheduleFrame(f, 0xc80, 300, 0x2c))
        spawn(0x0c, 300, randCoord(0x191, 0xd2), -20, "S06 original line 301");
    if (f == 0xd70) spawn(0x59, 0x22b8, 0x334, 200, "S06 original line 305");
    if (isScheduleFrame(f, 0xdac, 200, 0x14))
        spawn(0x0d, 300, 0x2e4, randCoord(0x65, 300), "S06 original line 316");
    if (isScheduleFrame(f, 0xe42, 0x96, 0x14))
        spawn(0x0d, 300, -20, randCoord(0x65, 300), "S06 original line 327");
    if (f == 0x10cc) spawn(0x58, 0x960, 0x168, -120, "S06 original line 331");
    if (f == 0x10fe) spawn(0x58, 0x960, 0xd2, -150, "S06 original line 335");
    if (f == 0x1130) spawn(0x58, 0x960, 0x3c, -180, "S06 original line 339");
    if (isScheduleFrame(f, 0x11f8, 100, 0x14))
        spawn(0x0b, 300, -20, randCoord(0xc9, 100), "S06 original line 350");
    if (isScheduleFrame(f, 0x1482, 100, 10))
        spawn(0x0b, 300, randCoord(0x1f5, 0x6e), -20, "S06 original line 361");
    if (isScheduleFrame(f, 0x17ac, 0xf0, 0xf))
        spawn(0x1a, 300, randCoord(0x1f5, 0x6e), -20, "S06 original line 372");

    if (f == 0x189c) {
        spawn(0x143, 100000, 400, 240, "S06 original line 380: midboss");
        stage06GateFlag_ = true;
    }
    if (!stage06GateFlag_) {
        if (isScheduleFrame(f, 0x1900, 0x76c, 0x27))
            spawn(0x0b, 400, randCoord(0x259, 0x3c), -20, "S06 original line 396");
        if (isScheduleFrame(f, 0x1964, 0x6a4, 400)) {
            spawn(0x57, 2000, 0x1a4, -180, "S06 original line 401");
            spawn(0x57, 2000, 0x262, -150, "S06 original line 402");
            spawn(0x57, 2000, 800, -120, "S06 original line 403");
        }
        if (isScheduleFrame(f, 0x1a2c, 0x5dc, 400)) {
            spawn(0x58, 2000, 300, -120, "S06 original line 408");
            spawn(0x58, 2000, 0x6e, -150, "S06 original line 409");
            spawn(0x58, 2000, -80, -180, "S06 original line 410");
        }
    }

    if (f == 0x2008) {
        for (const auto& point : kStage06Formation2Small)
            spawn(0x5a, 0x44c, point.x, point.y, "S06 original lines 415-456: formation 2 small");
        for (const auto& point : kStage06Formation2Medium)
            spawn(0x5d, 0xc80, point.x, point.y, "S06 original lines 437-461: formation 2 medium");
        for (const auto& point : kStage06Formation2Large)
            spawn(0x5e, 0x15e0, point.x, point.y, "S06 original lines 442-466: formation 2 large");
        spawn(0x5f, 13000, 0xf0, -1250, "S06 original line 467: formation 2 core");
        spawn(0x5f, 0x30d4, 500, -3175, "S06 original line 468: formation 2 core");
    }
    if (isScheduleFrame(f, 0x22c4, 800, 0x50))
        spawn(0x5b, 800, 0x302, f - 0x245e, "S06 original line 473");
    if (isScheduleFrame(f, 0x23f0, 800, 0x50))
        spawn(0x5b, 800, -50, f - 0x25da, "S06 original line 478");
    if (f == 0x2260) spawn(0x59, 8000, 0x334, 200, "S06 original line 482");
    if (f == 0x23f0) spawn(0x0f, 5000, -120, 0x78, "S06 original line 486");
    if (isScheduleFrame(f, 0x26ca, 0x32, 0xd))
        spawn(0x0b, 300, 0x2e4, randCoord(0xc9, 0x96), "S06 original line 497");
    if (isScheduleFrame(f, 10000, 0x32, 0xd))
        spawn(0x0b, 300, -20, randCoord(0xc9, 100), "S06 original line 508");
    if (f == 0x2774) {
        spawn(0x57, 0x640, 0x168, -100, "S06 original line 512");
        spawn(0x57, 0x640, 0x230, -100, "S06 original line 513");
        spawn(0x57, 0x640, 0x2f8, -100, "S06 original line 514");
        spawn(0x57, 0x640, 0x1cc, -220, "S06 original line 515");
        spawn(0x57, 0x640, 0x294, -220, "S06 original line 516");
    }
    if (f == 0x283c || f == 0x288c || f == 0x28dc) {
        spawn(0x0c, 300, 0x3c, -20, "S06 original line 521");
        spawn(0x0c, 300, 0xb4, -20, "S06 original line 522");
        spawn(0x0c, 300, 300, -20, "S06 original line 523");
        spawn(0x0c, 300, 0x1a4, -20, "S06 original line 524");
        spawn(0x0c, 300, 0x21c, -20, "S06 original line 525");
        spawn(0x0c, 300, 0x294, -20, "S06 original line 526");
    }
    if (f == 0x2936) spawn(0x59, 7000, -100, 200, "S06 original line 530");
    if (f == 0x2968) spawn(0x59, 7000, 0x334, 200, "S06 original line 534");
    if (isScheduleFrame(f, 0x2a94, 0xdc, 0x1e))
        spawn(0x0c, 300, randCoord(0x191, 0x50), -20, "S06 original line 546");
    if (f == 0x2e18) spawn(8, 5000, 0x1cc, 0, "S06 original line 550");
}

void StageRuntime::spawnStage07OriginalSchedule() {
    const int f = frame_;
    const std::uint32_t random = stageScheduleRandFromFrame(f);
    const auto randCoord = [&](int modulus, int base) {
        return static_cast<int>(random % static_cast<std::uint32_t>(modulus)) + base;
    };
    const auto spawn = [this](int type, int hitPoints, int x, int y, const char* note) {
        spawnEnemy({frame_, type, hitPoints, x, y, note});
    };

    if (isScheduleFrame(f, 0x10e, 0x82, 0x13)) {
        const int local = f - 0x10e;
        spawn(0x74, 0x4b0, (local * 6) % 0x168 + 0xb4, 0x334, "S07 original line 27");
    }
    if (f == 500) spawn(0x71, 0x1130, 0x1e0, 200, "S07 original line 31");
    if (f == 0x244) spawn(0x71, 0x1130, 0xd2, 0x10e, "S07 original line 35");
    if (isScheduleFrame(f, 0x2ee, 100, 0x23))
        spawn(0x70, 700, 0x2e4, randCoord(0xc9, 100), "S07 original line 46");
    if (isScheduleFrame(f, 0x366, 100, 0x23))
        spawn(0x70, 700, -20, randCoord(0xc9, 100), "S07 original line 57");
    if (isScheduleFrame(f, 0x3ac, 0x82, 0x13)) {
        const int local = f - 0x3ac;
        spawn(0x74, 0x4b0, (local * 6) % 0x168 + 0xb4, 0x334, "S07 original line 62");
    }
    if (isScheduleFrame(f, 0x49c, 0x5a, 0x19))
        spawn(0x70, 0x4b0, randCoord(0x259, 0x3c), 0x30c, "S07 original line 73");
    if (f == 0x514) spawn(7, 5000, 0x168, 0, "S07 original line 77");
    if (f == 0x5b4) spawn(0x73, 7000, 0xf0, 0, "S07 original line 81");
    if (f == 0x6a4) spawn(0x73, 6000, 0x1e0, 0, "S07 original line 85");
    if (isScheduleFrame(f, 0x60e, 200, 0x2b)) {
        const int local = f - 0x60e;
        spawn(0x74, 0x4b0, 0x21c - (local * 3) % 0x168, 0x334, "S07 original line 90");
    }
    if (f == 0x758) spawn(0x72, 0xce4, 0x1fe, 0xfa, "S07 original line 94");
    if (f == 0x794) spawn(0x72, 0xce4, 0x168, 200, "S07 original line 98");
    if (f == 2000) spawn(0x72, 0xce4, 0xd2, 0x96, "S07 original line 102");
    if (isScheduleFrame(f, 0x834, 0x8c, 0x13))
        spawn(0x74, 1000, 0x21c - ((f - 0x60e) * 6) % 0x168, 0x334, "S07 original line 107");
    if (f == 0x960) spawn(0x26, 5000, 0x208, -20, "S07 original line 111");
    if (f == 0x9c4) spawn(0x26, 5000, 200, -20, "S07 original line 115");
    if (isScheduleFrame(f, 0xa14, 0x3c, 0xc))
        spawn(0x70, 0x4b0, randCoord(0x259, 0x3c), 0x30c, "S07 original line 126");
    if (f == 0xaf0) spawn(0x76, 18000, 0x1ea, 0x348, "S07 original line 130");
    if (isScheduleFrame(f, 0xb86, 100, 0x14))
        spawn(0x0b, 500, -20, randCoord(0xc9, 100), "S07 original line 141");
    if (isScheduleFrame(f, 0xc80, 0xa0, 0x28))
        spawn(0x70, 0x4b0, randCoord(0xfb, 0xa0), 0x30c, "S07 original line 152");
    if (isScheduleFrame(f, 0xd0c, 100, 0x14))
        spawn(0x0b, 500, 0x2e4, randCoord(0xc9, 100), "S07 original line 163");
    if (f == 0xd5c) spawn(0x76, 15000, 0xe6, 0x348, "S07 original line 167");
    if (f == 0xd84) spawn(0x75, 0x960, 0x1ae, 0x302, "S07 original line 171");
    if (f == 0xdfc) spawn(0x75, 0x960, 0x212, 0x366, "S07 original line 175");
    if (isScheduleFrame(f, 0xeec, 0xaa, 10))
        spawn(0x0b, 300, randCoord(0x259, 0x3c), -20, "S07 original line 186");

    if (f == 0xfb4) {
        spawn(0x144, 100000, 360, 900, "S07 original line 195: first midboss");
        stage07GateFlag_ = true;
    }
    if (!stage07GateFlag_ && f >= 0x1068 && f < 0x1900) {
        if (isScheduleFrame(f, 0x1068, 0x76c, 400))
            spawn(0x72, 0xaf0, 0xe6, 0xfa, "S07 original line 210");
        if (isScheduleFrame(f, 0x10a4, 0x730, 400))
            spawn(0x72, 0xaf0, 0x1ea, 200, "S07 original line 215");
        if (isScheduleFrame(f, 0x1130, 0x6a4, 400))
            spawn(0x71, 0xaf0, 0x1ea, 0xfa, "S07 original line 220");
        if (isScheduleFrame(f, 0x116c, 0x668, 400))
            spawn(0x71, 0xaf0, 0xe6, 200, "S07 original line 225");
        if (isScheduleFrame(f, 0x1068, 0x76c, 0x32))
            spawn(0x0b, 500, randCoord(0x1f5, 0x6e), -20, "S07 original line 236");
        if (f == 0x184c) spawn(0x73, 9000, 0x19a, 0, "S07 original line 240");
    }
    if (isScheduleFrame(f, 0x1900, 0x96, 0x13)) {
        const int local = f - 0x1900;
        spawn(0x74, 1000, (local * 5) % 0x168 + 0xb4, 0x334, "S07 original line 248");
    }
    if (isScheduleFrame(f, 0x1a04, 0x50, 0x14))
        spawn(0x70, 0x4b0, randCoord(0x17d, 0xaa), -60, "S07 original line 260");
    if (f == 0x1a5e) {
        spawn(0x77, 18000, 0xf0, 0x398, "S07 original line 264: gate owner");
        stage07GateFlag_ = true;
    }
    if (isScheduleFrame(f, 0x1bbc, 0xfa, 0x48))
        spawn(0x25, 700, randCoord(0xb5, 0x1a4), -20, "S07 original line 276");
    if (isScheduleFrame(f, 0x1cfc, 0xb4, 0x27)) {
        const int local = f - 0x1cfc;
        spawn(0x74, 1000, (local * 2) % 200 + 0x186, 0x334, "S07 original line 281");
    }
    if (!stage07GateFlag_ && isScheduleFrame(f, 0x1c20, 600, 0x78))
        spawn(0x72, 0xaf0, 0xf0, 0xf0, "S07 original line 286");
    if (isScheduleFrame(f, 0x1eaa, 100, 0x15))
        spawn(0x70, 1000, randCoord(0x191, 0xa0), 0x30c, "S07 original line 297");

    if (f == 8000) {
        spawn(0x145, 100000, 360, 900, "S07 original line 304: second midboss");
        stage07GateFlag_ = true;
    }
    if (!stage07GateFlag_ && f >= 0x2008 && f < 0x28a0) {
        if (isScheduleFrame(f, 0x2008, 0x5dc, 0x96)) {
            const double phase = (static_cast<double>(f) - 8200.0) *
                                 0x1.b4e81b4e81b4fp+6 *
                                 0x1.921fb54442d11p+1 *
                                 0x1p-15;
            const int x = 0x168 - static_cast<int>(std::sin(phase) * 180.0);
            spawn(0x73, 6000, x, 0, "S07 original line 321: sine path");
        }
        if (isScheduleFrame(f, 0x2008, 0x60e, 0x2c))
            spawn(0x0b, 300, randCoord(0x1f5, 0x6e), -20, "S07 original line 332");
        if (f == 0x2648) spawn(0x76, 15000, 0x168, 0x348, "S07 original line 336");
        if (f == 0x2670) {
            spawn(0x75, 0x960, 0x1cc, 1000, "S07 original line 340");
            spawn(0x75, 0x960, 0x104, 1000, "S07 original line 341");
        }
        if (f == 10000) {
            spawn(0x75, 0x960, 0x21c, 0x366, "S07 original line 345");
            spawn(0x75, 0x960, 0xb4, 0x366, "S07 original line 346");
        }
        if (f == 0x2814) {
            spawn(0x70, 0x4b0, 0x1b8, 0x30c, "S07 original line 350");
            spawn(0x70, 0x4b0, 0x118, 0x30c, "S07 original line 351");
        }
        if (f == 0x283c) {
            spawn(0x70, 0x4b0, 0x208, 0x30c, "S07 original line 355");
            spawn(0x70, 0x4b0, 200, 0x30c, "S07 original line 356");
        }
    }
    if (isScheduleFrame(f, 0x28a0, 0xc8, 10))
        spawn(0x0b, 300, randCoord(0x259, 0x3c), -20, "S07 original line 370");
    if (f == 0x2968) {
        spawn(0x77, 18000, 0x1e0, 0x398, "S07 original line 375: gate owner");
        stage07GateFlag_ = true;
    }
    if (f >= 0x29fe && f < 0x29fe + 0x1c2) {
        const int local = f - 0x29fe;
        const int burstFrame = local % 0x10e;
        if (burstFrame < 0x3c && burstFrame % 0x1e == 0)
            spawn(0x70, 700, -20, randCoord(0xc9, 100), "S07 original line 388");
    }
    if (f == 0x2c24) spawn(0x76, 15000, 0xe6, 0x348, "S07 original line 392");
    if (!stage07GateFlag_ && isScheduleFrame(f, 0x2cba, 0x78, 0x1e))
        spawn(0x70, 700, 0x2e4, randCoord(0xc9, 100), "S07 original line 404");
    if (isScheduleFrame(f, 0x2db4, 100, 10))
        spawn(0x0b, 300, randCoord(0x1f5, 0x6e), -20, "S07 original line 417");
    if (f == 0x2e18) spawn(8, 5000, 0x1cc, 0, "S07 original line 421");
}

} // namespace reconstructed
