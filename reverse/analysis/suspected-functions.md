# Suspected Functions / Cross-Reference Targets

This file starts as a target list for decompiler cross-references. Function addresses have not yet been assigned.

## High-value string anchors

| String | Offset in exe strings scan | Hypothesis |
|---|---:|---|
| `VanillaFever11` | `0x5379e8` | DXArchive key string. Cross-reference should lead to resource init or SetDXArchiveKeyString-equivalent call. |
| `media\\demo\\LD_demo%02d.txt` | `0x535f20` | Formatted demo script path. |
| `media\\system\\TitleLogo.png` | `0x536038` | Title/menu resource table. |
| `media\\bgm\\Stage1.ogg` | `0x5368b0` | BGM table. |
| `media\\text\\text01.csv` | `0x538c38` | Text CSV loading. |
| `save\\save.dat` | see `symbols/resources.txt` | Save serialization. |
| `save\\config.dat` | see `symbols/resources.txt` | Config serialization. |
| `replay\\LD_replay%02d.dat` | see `symbols/resources.txt` | Replay serialization. |
| `Failed to initialize SteamAPI.` | `0x537958` | Startup/Steam init error path. |

## Initial hypotheses

- Resource paths appear in dense contiguous tables around offsets `0x535f20` through `0x538c80`.
- BGM and SE resources are grouped, suggesting array-based loading by enum index.
- Language variants use filename suffixes (`_eng`, `_ch1`, `_ch2`) rather than separate text-only bundles.
- `LD_demo%02d.txt` is a template; extracted files are `LD_demo01.txt` to `LD_demo03.txt`.
