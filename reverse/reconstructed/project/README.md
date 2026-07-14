# LikeDreamerRe reconstruction scaffold

This directory contains a **local reconstruction scaffold**, not original Like Dreamer source code and not a complete game reimplementation.

The project began as a Windows x64 DxLib smoke test. It now contains a playable reconstruction runtime and evidence-backed frontend/gameplay slices; remaining approximations are kept explicit rather than presented as recovered source.

## Evidence used

- `../..//README.md` identifies DxLib + DXArchive and key `VanillaFever11`.
- `../../ghidra-or-ida/exports/renamed-decompiled/1400f4f70_game_startup_init_candidate.c` shows Steam init, save/config loading, `dxarchive_set_key_candidate("VanillaFever11")`, and initial `media\system\...` loads.
- `../data-structures/resource-handle-map.md` lists startup and primary graphics paths.
- `../headers/*.h` contains reconstructed identifier sketches.

## Build

Build from a Windows Developer PowerShell or Visual Studio command prompt. The target links the official Windows DxLib VC package, so native WSL Linux compilers are not expected to work.

```powershell
cd \\wsl.localhost\Ubuntu\mnt\e\fork\ld\reverse\reconstructed\project
cmake -S . -B build -G "Visual Studio 17 2022" -A x64
cmake --build build --config Release
```

The default `DXLIB_ROOT` points at the verified local VC package: `E:\fork\DxLibVCTest\DxLibVCTest`. Override it with `-DDXLIB_ROOT=...` only if that directory moves.

## Run smoke test

```powershell
.\build\Release\LikeDreamerRe.exe --asset-root "\\wsl.localhost\Ubuntu\mnt\e\fork\ld" --smoke-test
```

Default mode loads extracted files by mapping logical paths such as `media\system\TitleLogo.png` to `<asset-root>\re\system\TitleLogo.png`.

Experimental DXA mode keeps the original logical `media\...` paths and relies on `media.dxa` plus `SetDXArchiveKeyString("VanillaFever11")`:

```powershell
.\build\Release\LikeDreamerRe.exe --asset-root "\\wsl.localhost\Ubuntu\mnt\e\fork\ld" --use-dxa --smoke-test
```

For DXA mode, run from a directory where `media.dxa` is visible using the same layout as the original game.

## Current behavior

- Steam is stubbed out.
- `save\save.dat` and `save\config.dat` use the recovered fixed layouts (`0x2730` and `0x1c`) for frontend unlocks, setup, controls, language, volume, and display settings. Missing files are created from the original defaults; existing legacy/short files are normalized in memory without being overwritten during startup. Reads and menu writes consistently target `<asset-root>\save`, including DXA mode.
- Startup applies the saved Full Screen, VSync, and Auto/WASAPI/WASAPI Exclusive/DirectSound selection before `DxLib_Init`, then displays the reconstructed `starting.png` / `NowLoading.png` sequence. The 60/30/20 Frame Rate setting uses the original one-in-one, one-in-two, or one-in-three logic-update cadence.
- The frontend runtime implements title/setup/select/practice (`0x02..0x05`), gallery/achievements/enemy encyclopedia/manual (`0x06..0x09`), options/config/key config (`0x0a..0x0d`), replay selection (`0x0e/0x0f`), and ranking states (`0x11/0x12`). The post-game chain now routes the recovered Result, Trial Continue, ranking-submit, replay-prompt, and replay-save states (`0x10/0x20/0x22/0x23/0x24`) using the gameplay score/frame and the save-backed eligibility predicate. Options/Assist/Config/KeyConfig use the recovered repeat counters, release-gated capture, keyboard/controller scan rules, menu sound multipliers, and separate `save.dat`/`config.dat` persistence. Replay metadata is parsed, but recorded-input playback and a truthful input recording stream are still deferred.
- Gameplay receives the recovered loadout, Auto/Manual Fever, Data Window, control bindings, Help Mode plus its per-stage Auto record, SE volume, Visibility, and Like Style. The six equipment Bomb roots and PlayerSideObject chains `0x0b..0x1a` now use their recovered constructors, lifetimes, enemy damage, cancel groups/radii, deathbomb timing, effect frames, and sound multipliers. Enemy hits use the recovered distance-bucketed `Shothit` and additive spawn-type-gated `Shothit2` branches.
- With `--smoke-test`, use `Ctrl+F1` for the title smoke screen, `Ctrl+F2` for resource diagnostics, `Ctrl+F3` for text CSV diagnostics, `Ctrl+F4` for save/config diagnostics, `Ctrl+F5` for stage reconstruction probes, and `Ctrl+F6` for playable stage reconstruction slices. Requiring the diagnostic chord leaves `F1` through `F6` available to the original key-config capture. Menu Cancel follows the saved binding; closing the window exits.
- The `Ctrl+F5` stage probe includes a curated set of projectile visual annotations from the boss/final helper review, joining spawn type, projectile ID/selector pair, Bullet.png frame interpretation, and confidence.
- Enemy death now uses the shared reward-tier calculation, cleanup modes `0/1/2`, terminal-frame ordering, and the real invisible post-death counter entity `0x137` instead of immediate generic removal. Stage-specific helpers retain their recovered payout windows, feedback strengths, owner-death branches, and delayed `0x153` owner-damage nodes.
- The `Ctrl+F6` playable runtime covers Stage 1-4 schedules. Player movement, option formations, normal shots, projectile motion/collision, rewards, HUD panels, and the reviewed Stage 1-4 enemy families follow local Ghidra evidence. Shared enemy types `0x0a..0x0f` now use their recovered global constructors, entry states, movement/firing rules, multipart draws, gauges, death windows, bounds, and terminal-frame collision instead of falling back to generic behavior; this includes `0x0e`'s cached dual-mount windows and nine-node body plus `0x0f`'s seeded alternating mounts and layered center fans. Stage 2 scheduled enemies `0x19..0x21` use their recovered constructors, state timers, movement, firing, multipart draw, gauge, death, bounds, child, gate, and `0x2a/0x2b/0x2c/0x37` death-effect logic. Reward items use the original `Item.png` frame/style/visibility rules, collection gates, terminal-frame lifetime, and collection audio. Stage 1 Boss `0x138`, Stage 2 Boss `0x139`, and Stage 3 Boss `0x13a` now have dedicated state machines, live HP bars, phase breaks, child entities, recovered projectile patterns, multipart draws, Boss HUDs, and timed clear latches. Later bosses, exact render-layer ordering, and still-unported generic effect nodes remain explicit gaps.

- Stage Select now uses the recovered 15-node world map, per-stage RGB tint table, 30-frame camera interpolation, signed stage/difficulty layer timing, exact node transforms and horizontal culling, original menu/preview offsets, difficulty/Counter animations, fixed-angle arrows, and the special route stage-10 presentation. Detailed per-stage result/stat rows remain documented as deferred rather than provisional UI.

## Legal boundary

Keep reconstructed code and commercial assets local. Do not redistribute the original executable, assets, rebuilt archives, or proprietary reconstructed logic.

## Expanded diagnostics

Load the larger reconstructed graphics table and optional audio smoke-test handles:

```powershell
.\build\Release\LikeDreamerRe.exe --asset-root "E:\fork\ld" --smoke-test --load-all-graphics --load-audio
```

The expanded tables are hand-transcribed from `../data-structures/*.md` and the decompiled startup/resource-loader anchors. They are diagnostic coverage, not final gameplay behavior.

## Stage probe

`Ctrl+F5` shows the current stage-reconstruction evidence layer: stage/background/BGM hints, curated projectile visual annotations for representative boss/final helpers, parsed `LD_demo01..03.txt` header/input counts, replay stage-field offsets, entity model hypotheses, and the next reverse targets to locate (`stage_init`, `stage_update`, `spawn_enemy`, `spawn_bullet`, etc.). This page is intentionally diagnostic only.

## Playable stage reconstruction slices

`Ctrl+F6` enters the playable in-stage runtime when `--smoke-test` is enabled. Stage schedules and helpers combine exact decompiler ports with documented fallback boundaries from `../data-structures/stage-spawn-schedule.csv`, `projectile-runtime-exact-audit.md`, and the per-stage exact notes.

Controls come from the saved keyboard/controller binding tables; defaults remain arrows, `Shift`, `Z`/`X`/`C`, and `Escape`. `R` resets the active runtime during diagnostics. The implementation is still a reconstruction probe rather than recovered source: replay input playback, the dialogue path needed by Text Animation, several generic effect/render queue nodes, later-stage bosses, and unported helper families remain incomplete and are tracked in the adjacent exact-audit notes.
