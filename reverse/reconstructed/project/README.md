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
- Startup applies the saved Full Screen, VSync, and Auto/WASAPI/WASAPI Exclusive/DirectSound selection before `DxLib_Init`, then displays the reconstructed `starting.png` / `NowLoading.png` sequence. The main loop follows the recovered accumulated `16.66` ms deadline even when VSync is disabled. The 60/30/20 Frame Rate setting updates logic and input every tick while refreshing a persistent presentation screen every one, two, or three ticks.
- The frontend runtime implements title/setup/select/practice (`0x02..0x05`), gallery/achievements/enemy encyclopedia/manual (`0x06..0x09`), options/config/key config (`0x0a..0x0d`), replay selection (`0x0e/0x0f`), and ranking states (`0x11/0x12`). The post-game chain now routes the recovered Result, Trial Continue, ranking-submit, replay-prompt, replay-slot, and three-character replay-name states (`0x10/0x20/0x22/0x23/0x24/0x25`). Live gameplay records the original ten-bit input mask and writes the recovered `0xa98` header plus 8-byte frame records to `replay/LD_replayXX.dat`; recorded-input playback is still deferred. Options/Assist/Config/KeyConfig use the recovered repeat counters, release-gated capture, keyboard/controller scan rules, menu sound multipliers, and separate `save.dat`/`config.dat` persistence.
- Gameplay receives the recovered loadout, Auto/Manual Fever, Data Window, control bindings, Help Mode plus its per-stage Auto record, SE volume, Visibility, and Like Style. The six equipment Bomb roots and PlayerSideObject chains `0x0b..0x1a` now use their recovered constructors, lifetimes, enemy damage, cancel groups/radii, deathbomb timing, effect frames, and sound multipliers. Enemy hits use the recovered distance-bucketed `Shothit` and additive spawn-type-gated `Shothit2` branches.
- With `--smoke-test`, use `Ctrl+F1` for the title smoke screen, `Ctrl+F2` for resource diagnostics, `Ctrl+F3` for text CSV diagnostics, `Ctrl+F4` for save/config diagnostics, `Ctrl+F5` for stage reconstruction probes, and `Ctrl+F6` for playable stage reconstruction slices. Requiring the diagnostic chord leaves `F1` through `F6` available to the original key-config capture. Menu Cancel follows the saved binding; closing the window exits.
- The `Ctrl+F5` stage probe includes a curated set of projectile visual annotations from the boss/final helper review, joining spawn type, projectile ID/selector pair, Bullet.png frame interpretation, and confidence.
- Enemy death now uses the shared reward-tier calculation, cleanup modes `0/1/2`, terminal-frame ordering, and the real invisible post-death counter entity `0x137` instead of immediate generic removal. Stage-specific helpers retain their recovered payout windows, feedback strengths, owner-death branches, and delayed `0x153` owner-damage nodes.
- The `Ctrl+F6` playable runtime accepts Stage 1-10 (`1`..`9`, `0` for Stage 10). Stage 5-10 use direct transcriptions of their original frame/modulo/gate schedules, the recovered `UNK_140538ad8` lengths, deterministic frame-seeded random coordinates, dedicated background resources, per-stage BGM, and the original Boss handoff families. Stage 9 includes its six mid-stage roots; Stage 10 keeps the `0x14c -> 0x141` transition, its foreground fleet tree, and the final Boss controller/emitter hierarchy. Player movement, option formations, normal shots, projectile motion/collision, rewards, and HUD panels remain shared across all stages. Scheduled and internally-created Stage 1-10 entity types now route through dedicated recovered update, projectile, and draw helpers; uncreated dispatcher slots remain inert instead of receiving generic movement or bullets. A small number of pure visual effect-queue calls still use the nearest represented effect node where decompilation lost call arguments.

- Stage Select now uses the recovered 15-node world map, per-stage RGB tint table, 30-frame camera interpolation, signed stage/difficulty layer timing, exact node transforms and horizontal culling, original menu/preview offsets, difficulty/Counter animations, fixed-angle arrows, and the special route stage-10 presentation. Detailed per-stage result/stat rows remain documented as deferred rather than provisional UI.

## Gameplay behavior pseudocode

The reconstructed enemy movement, firing, and enemy-projectile state machines are
summarized in human-readable pseudocode under
[`docs/enemy-projectile-pseudocode.md`](docs/enemy-projectile-pseudocode.md). The
index links separate Stage 1-4, Stage 5-7, Stage 8-10, and shared projectile
documents, with explicit `spawnType` and `projectileId` coverage tables.

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

`Ctrl+F6` enters the playable in-stage runtime when `--smoke-test` is enabled. Stage schedules and entity helpers are transcribed from the dispatcher maps, Ghidra exports, PE constants, `../data-structures/stage-spawn-schedule.csv`, `projectile-runtime-exact-audit.md`, and the per-stage exact notes.

Controls come from the saved keyboard/controller binding tables; defaults remain arrows, `Shift`, `Z`/`X`/`C`, and `Escape`. `R` resets the active runtime during diagnostics. The implementation is still a reconstruction rather than recovered source: replay input playback, the dialogue path needed by Text Animation, and some effect/render queue calls remain incomplete and are tracked in the adjacent exact-audit notes.
