from pathlib import Path
import csv, json, hashlib, math, struct, subprocess, os, re
BASE=Path('/Users/happyelements/SteamLibrary/steamapps/common/Like Dreamer')
REV=BASE/'reverse'
RE=BASE/'re'

def sha256(p):
    h=hashlib.sha256()
    with open(p,'rb') as f:
        for chunk in iter(lambda:f.read(1024*1024), b''):
            h.update(chunk)
    return h.hexdigest()

def entropy(data):
    if not data: return 0.0
    counts=[0]*256
    for b in data: counts[b]+=1
    n=len(data)
    return -sum((c/n)*math.log2(c/n) for c in counts if c)

def png_size(p):
    b=p.read_bytes()[:32]
    if b.startswith(b'\x89PNG\r\n\x1a\n') and b[12:16]==b'IHDR':
        return struct.unpack('>II', b[16:24])
    return None,None

def ffprobe_duration(p):
    try:
        r=subprocess.run(['ffprobe','-v','error','-show_entries','format=duration','-of','default=nw=1:nk=1',str(p)], stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True, timeout=10)
        if r.returncode==0 and r.stdout.strip(): return float(r.stdout.strip())
    except Exception:
        pass
    return None

def detect_text(p):
    b=p.read_bytes()
    for enc in ['utf-8-sig','cp932','shift_jis','latin1']:
        try:
            s=b.decode(enc)
            return enc, s
        except Exception:
            continue
    return 'binary',''

# asset index
rows=[]
for p in sorted(RE.rglob('*')):
    if not p.is_file(): continue
    rel=str(p.relative_to(RE)).replace('\\','/')
    ext=p.suffix.lower()
    cat=rel.split('/')[0] if '/' in rel else '(root)'
    width=height=duration=lines=encoding=''
    if ext=='.png':
        w,h=png_size(p); width=w or ''; height=h or ''
    if ext in ['.ogg','.wav','.mp3']:
        d=ffprobe_duration(p); duration=f'{d:.3f}' if d is not None else ''
    if ext in ['.csv','.txt']:
        enc,s=detect_text(p); encoding=enc; lines=s.count('\n')+bool(s) if s else 0
    rows.append({'relative_path':rel,'category':cat,'extension':ext,'size_bytes':p.stat().st_size,'sha256':sha256(p),'width':width,'height':height,'duration_seconds':duration,'encoding':encoding,'line_count':lines})
for name, filter_exts in [('assets.csv',None),('image-index.csv',{'.png'}),('audio-index.csv',{'.ogg','.wav','.mp3'}),('text-index.csv',{'.csv','.txt'})]:
    out=REV/'symbols'/name
    rr=[r for r in rows if filter_exts is None or r['extension'] in filter_exts]
    with open(out,'w',newline='',encoding='utf-8') as f:
        w=csv.DictWriter(f,fieldnames=list(rows[0].keys())); w.writeheader(); w.writerows(rr)
with open(REV/'symbols/assets.json','w',encoding='utf-8') as f: json.dump(rows,f,ensure_ascii=False,indent=2)

# reports
bycat={}
byext={}
for r in rows:
    bycat[r['category']]=bycat.get(r['category'],0)+1
    byext[r['extension']]=byext.get(r['extension'],0)+1

(REV/'analysis/resource-loading.md').write_text(f'''# Resource Loading Reconstruction Notes\n\n## Evidence\n\n- Main executable: `inputs/LikeDreamer.exe`\n- Archive: `inputs/media.dxa`\n- Extracted resource symlink: `assets/re -> ../re`\n- DXA key confirmed by extraction test: `VanillaFever11`\n- Interesting strings: `symbols/resources.txt`\n- Executable-to-resource mapping: `symbols/resource-map.csv`\n\n## DXA Header\n\n`media.dxa` is DxLib DXArchive v8. Parsed header from prior inspection:\n\n```text\nHead: DX\nVersion: 8\nHeadSize: 25728\nDataStart: 64\nFileNameTableStart: 242952384\nFileTableStart: 8128\nDirectoryTableStart: 25408\nCharCodeFormat: 932\nFlags: 0\nHuffmanEncodeKB: 10\n```\n\n## Resource Path Mapping\n\nThe executable contains 227 `media\\...` string references. `symbols/resource-map.csv` maps 226 of them to extracted files under `re/`. The one unmapped pattern is expected to be a formatted path or case/path variant.\n\n## Resource Counts\n\nBy category:\n\n{chr(10).join(f'- `{k}`: {v}' for k,v in sorted(bycat.items()))}\n\nBy extension:\n\n{chr(10).join(f'- `{k}`: {v}' for k,v in sorted(byext.items()))}\n\n## Reconstructed Loading Model\n\nHypothesis based on strings and DxLib/DXArchive evidence:\n\n1. Program initializes Steam and DxLib.\n2. Program sets DXArchive key string to `VanillaFever11` or equivalent internal value.\n3. Program loads assets through DxLib path APIs using logical paths such as `media\\system\\TitleLogo.png`.\n4. DxLib resolves the `media` logical root to `media.dxa`.\n5. Fonts `Nyashi.ttf` and `ChillRoundM.ttf` appear to be loaded from real files in the run directory.\n6. Save/config/replay files are real filesystem files under `save/` and `replay/`.\n\n## Next Reverse Targets\n\n- Cross-reference `VanillaFever11` in a decompiler to locate DXA key setup.\n- Cross-reference `media\\text\\text01.csv` to locate text manager initialization.\n- Cross-reference `SteamAPI_Init` imports/strings to locate startup chain.\n- Cross-reference `replay\\LD_replay%02d.dat` to locate replay loader/writer.\n''', encoding='utf-8')

# text csv report
text_lines=[]
for p in sorted((RE/'text').glob('*')):
    enc,s=detect_text(p)
    sample='\n'.join(s.splitlines()[:5])
    # csv rough columns
    parsed=[]
    try:
        parsed=list(csv.reader(s.splitlines()))
    except Exception: parsed=[]
    cols=sorted(set(len(r) for r in parsed))[:20]
    text_lines.append(f'''## {p.name}\n\n- Encoding: `{enc}`\n- Lines: {len(s.splitlines())}\n- CSV column counts observed: {cols}\n\nSample:\n\n```text\n{sample[:1200]}\n```\n''')
(REV/'analysis/text-csv-format.md').write_text('# Text CSV Format Notes\n\n'+ '\n'.join(text_lines), encoding='utf-8')

# demo parser/report
for script in ['parse_demo.py','inspect_save_replay.py']:
    pass

demo_sections=[]
for p in sorted((RE/'demo').glob('*.txt')):
    enc,s=detect_text(p)
    lines=s.splitlines()
    parsed=[]
    for line in lines[:20]:
        try: parsed.append([int(x) for x in line.split(',') if x!=''])
        except Exception: parsed.append(line.split(','))
    widths=sorted(set(len(line.split(',')) for line in lines if line))[:20]
    demo_sections.append(f'''## {p.name}\n\n- Encoding: `{enc}`\n- Lines: {len(lines)}\n- Comma-field counts observed: {widths}\n- First parsed records: `{parsed[:5]}`\n''')
(REV/'analysis/demo-format.md').write_text('# Demo TXT Format Notes\n\nHypothesis: frame/input or demo playback records. More correlation with runtime behavior is needed.\n\n'+'\n'.join(demo_sections), encoding='utf-8')

# save/replay binary report
bin_paths=list((BASE/'save').glob('*.dat'))+list((BASE/'replay').glob('*.dat'))
sections=[]
for p in sorted(bin_paths):
    b=p.read_bytes()
    rel=p.relative_to(BASE)
    extra=[]
    if rel.as_posix() == 'save/save.dat':
        extra.extend([
            '- Confirmed runtime read/write size: `0x2730` / `10032` bytes at global save block `DAT_140e41b10`.',
            '- First little-endian `int32` is the save schema/version sentinel; current valid value is `200` (`0xc8`).',
        ])
    elif rel.as_posix() == 'save/config.dat':
        ints=struct.unpack('<'+'i'*(len(b)//4), b[:(len(b)//4)*4]) if len(b) >= 4 else ()
        extra.extend([
            '- Confirmed runtime read/write size: `0x1c` / `28` bytes at config block `DAT_140e468f0`.',
            f'- Seven little-endian `int32` fields: `{ints}`.',
        ])
    elif rel.as_posix().startswith('replay/'):
        header=b[:0xa98]
        payload=b[0xa98:]
        ints=struct.unpack('<'+'i'*(min(len(header),0x140)//4), header[:min(len(header),0x140)])
        record_count=len(payload)//8
        rem=len(payload)%8
        declared=ints[1] if len(ints) > 1 else None
        player_tag=header[8:11].decode('ascii', errors='replace')
        timestamp=ints[4] if len(ints) > 4 else 0
        timestamp_note=''
        if timestamp > 0:
            import datetime
            timestamp_note=' / UTC '+datetime.datetime.fromtimestamp(timestamp, datetime.UTC).strftime('%Y-%m-%d %H:%M:%S')
        layout_rows=[
            ('0x0000', 'int32', 'version_or_magic', ints[0] if len(ints) > 0 else None, 'valid/current value is 200'),
            ('0x0004', 'int32', 'input_record_count', declared, 'matches payload bytes / 8 in samples'),
            ('0x0008', 'char[3]+NUL', 'player_tag_or_initials', player_tag, 'written from three selected characters'),
            ('0x0010', 'int32', 'unix_timestamp_candidate', str(timestamp)+timestamp_note, 'sample values decode to plausible UTC save dates'),
            ('0x0018', 'int32', 'mode_or_route_candidate', ints[6] if len(ints) > 6 else None, 'demo header field #2 / loaded into DAT_140e41928'),
            ('0x001c', 'int32', 'mode_subfield_candidate', ints[7] if len(ints) > 7 else None, 'loaded into DAT_140e41abc'),
            ('0x0020', 'int32', 'play_setting_0', ints[8] if len(ints) > 8 else None, 'part of demo/replay 15-field header'),
            ('0x0024', 'int32', 'play_setting_1', ints[9] if len(ints) > 9 else None, 'part of demo/replay 15-field header'),
            ('0x0028', 'int32', 'play_setting_2', ints[10] if len(ints) > 10 else None, 'part of demo/replay 15-field header'),
            ('0x002c', 'int32', 'stage_or_section_candidate', ints[11] if len(ints) > 11 else None, 'loaded into DAT_140e445c0'),
            ('0x0030', 'int32', 'stage_progress_candidate', ints[12] if len(ints) > 12 else None, 'loaded into DAT_140e445c4'),
            ('0x0034', 'int32', 'stage_progress_candidate_2', ints[13] if len(ints) > 13 else None, 'loaded into DAT_140e445c8'),
            ('0x0038', 'int32', 'stage_progress_candidate_3', ints[14] if len(ints) > 14 else None, 'loaded into DAT_140e445cc'),
            ('0x003c', 'int32', 'stage_progress_candidate_4', ints[15] if len(ints) > 15 else None, 'loaded into DAT_140e445d0'),
            ('0x0040', 'int32', 'demo_checkpoint_or_stage', ints[16] if len(ints) > 16 else None, 'demo header field #15; replay load may copy it to DAT_1407c7798 in mode 0'),
            ('0x0044', 'int32', 'binary_current_stage', ints[17] if len(ints) > 17 else None, 'binary-only field written from DAT_1407c7798 before replay save'),
            ('0x0048', 'int32', 'stage_group_checkpoint_0', ints[18] if len(ints) > 18 else None, 'used by stage transition code for stage group 1'),
            ('0x004c', 'int32', 'stage_group_checkpoint_1', ints[19] if len(ints) > 19 else None, 'used by stage transition code for stage groups 2/3'),
            ('0x0050', 'int32', 'stage_group_checkpoint_2', ints[20] if len(ints) > 20 else None, 'used by stage transition code for stage groups 4/5'),
            ('0x0058', 'int64 low', 'score_or_counter_candidate', ints[22] if len(ints) > 22 else None, 'written from DAT_140e44590; high-variance low dword in samples'),
            ('0x0060', 'int64 low', 'secondary_score_or_counter_candidate', ints[24] if len(ints) > 24 else None, 'written from DAT_140e451b0; zero in current samples'),
            ('0x0064', 'int32', 'unknown_runtime_value_64', ints[25] if len(ints) > 25 else None, 'written from DAT_140e4680c; zero in current samples'),
            ('0x0068', 'int32', 'player_option_or_type_candidate', ints[26] if len(ints) > 26 else None, 'used instead of DAT_140e44194 during replay mode'),
            ('0x006c', 'int32', 'player_suboption_candidate', ints[27] if len(ints) > 27 else None, 'used instead of DAT_140e41b70 during replay mode'),
            ('0x0070', 'int32', 'demo_export_field_0x70', ints[28] if len(ints) > 28 else None, 'included in demo text export as one of the 15 header values'),
            ('0x00b4', 'int32', 'player_state_active_flag', ints[45] if len(ints) > 45 else None, 'start of repeated player/object state snapshot; observed 1'),
            ('0x00b8', 'float', 'player_pos_x_candidate', round(struct.unpack('<f', header[0xb8:0xbc])[0], 4), 'float 360.0 in samples; likely screen/player X'),
            ('0x00bc', 'float', 'player_pos_y_candidate', round(struct.unpack('<f', header[0xbc:0xc0])[0], 4), 'float 600.0 in samples; likely screen/player Y'),
            ('0x00c0', 'float', 'player_prev_or_target_x_candidate', round(struct.unpack('<f', header[0xc0:0xc4])[0], 4), 'float 360.0 in samples'),
            ('0x00c4', 'float', 'player_prev_or_target_y_candidate', round(struct.unpack('<f', header[0xc4:0xc8])[0], 4), 'float 600.0 in samples'),
            ('0x00c8', 'int32', 'player_angle_or_fixed_velocity_candidate', ints[50] if len(ints) > 50 else None, '0x0000c000 in samples; resembles fixed-point direction/speed'),
            ('0x00d8', 'int32', 'player_state_mode_candidate', ints[54] if len(ints) > 54 else None, 'observed 2'),
            ('0x00e4', 'float', 'subobject0_pos_x_candidate', round(struct.unpack('<f', header[0xe4:0xe8])[0], 4), 'float 360.0 in samples'),
            ('0x00e8', 'float', 'subobject0_pos_y_candidate', round(struct.unpack('<f', header[0xe8:0xec])[0], 4), 'float 600.0 in samples'),
            ('0x00ec', 'float', 'subobject1_pos_x_candidate', round(struct.unpack('<f', header[0xec:0xf0])[0], 4), 'float 360.0 in samples'),
            ('0x00f0', 'float', 'subobject1_pos_y_candidate', round(struct.unpack('<f', header[0xf0:0xf4])[0], 4), 'float 600.0 in samples'),
            ('0x0104', 'float', 'subobject_velocity_or_angle_x_candidate', round(struct.unpack('<f', header[0x104:0x108])[0], 4), 'float about -2.0117 in samples'),
            ('0x0108', 'float', 'subobject_velocity_or_angle_y_candidate', round(struct.unpack('<f', header[0x108:0x10c])[0], 4), 'float about -2.0117 in samples'),
            ('0x0128', 'int32', 'state_counter_128', ints[74] if len(ints) > 74 else None, 'observed 32'),
            ('0x0134', 'int32', 'state_counter_134', ints[77] if len(ints) > 77 else None, 'observed 60'),
        ]
        extra.extend([
            '- Confirmed replay header size: `0xa98` / `2712` bytes.',
            f'- Payload bytes after header: `{len(payload)}`; as 8-byte input records: `{record_count}` remainder `{rem}`.',
            f'- Header first `int32` is schema sentinel `{ints[0] if ints else None}`; second `int32` is declared input record count `{declared}`.',
            f'- Player tag/initials bytes at `0x0008`: `{header[8:12].hex(" ")}` -> `{player_tag}`.',
            f'- Timestamp candidate at `0x0010`: `{timestamp}`{timestamp_note}.',
            f'- First 32 header `int32` values: `{ints[:32]}`.',
            '',
            '| Offset | Type | Provisional name | Value | Evidence / note |',
            '|---:|---|---|---:|---|',
            *[f'| `{off}` | `{typ}` | `{name}` | `{val}` | {note} |' for off,typ,name,val,note in layout_rows],
        ])
        if payload:
            recs=[struct.unpack('<IhH', payload[off:off+8]) for off in range(0,min(len(payload),80),8)]
            extra.append(f'- First input records as `(uint32 frame_or_tick, int16 input_state, uint16 pad_or_flags)`: `{recs}`.')
    sections.append(f'''## {rel}\n\n- Size: {len(b)} bytes\n- SHA256: `{sha256(p)}`\n- First 64 bytes: `{b[:64].hex(' ')}`\n- Entropy first 4096 bytes: {entropy(b[:4096]):.4f}\n- Entropy full file: {entropy(b):.4f}\n{chr(10).join(extra)}\n''')
(REV/'analysis/save-replay-format.md').write_text('# Save / Config / Replay Binary Format Notes\n\nEvidence combines sample files with Ghidra decompilation of the save/config/replay handlers. All multi-byte numeric fields observed so far are little-endian.\n\n'+ '\n'.join(sections) + '''\n## Handler evidence\n\n- `game_startup_init_candidate` reads `save\\save.dat` into `DAT_140e41b10` with size `0x2730`, creates it via `FUN_1400d0aa0()` when missing, and accepts/migrates sentinel `200`.\n- `save_init_or_reset_candidate` writes `DAT_140e41b10` back to `save\\save.dat` with size `0x2730` and sets `DAT_140e471fc = 0xb4`.\n- `game_startup_init_candidate` reads `save\\config.dat` into `DAT_140e468f0` with size `0x1c`; on first run it writes seven default `int32` fields.\n- `config_handler_candidate` updates config menu fields `DAT_140e468f0` through `DAT_140e46908`, then startup consumes `DAT_140e46908` as an audio/sound mode selector.\n- `replay_handler_candidate_B` scans 24 replay slots, reads each `0xa98`-byte header into `DAT_140e8cf40 + slot * 0xa98`, and marks `DAT_140e9fd40[slot] = 1` when the header sentinel is `200`.\n- `replay_or_save_handler_candidate_A` loads the selected replay: first a `0xa98` header into `DAT_140e45280`, then a linked list of 8-byte input records until EOF.\n- `replay_or_save_handler_candidate_C` writes replay files: a `0xa98` header from `DAT_140e45280`, followed by linked-list input records serialized as 8 bytes each. In demo-export mode it writes text records to `media\\demo\\LD_demo%02d.txt` instead.\n

## Replay header layout notes

The binary replay header begins at `DAT_140e45280` and has the same logical field order as the first line of demo text files, except binary replays also carry a 3-character player tag at `0x0008` and timestamp-like metadata at `0x0010` before the gameplay fields used by demo import/export.

Known decompiler data flow:

- `DAT_140e45284` (`0x0004`) is exported as demo field #1 and bounds demo input-record import; in binary samples it equals payload byte count divided by 8.
- `DAT_140e45288..8a` (`0x0008`) are filled from three selected characters before binary replay save.
- `DAT_140e45298` (`0x0018`) through `DAT_140e452c0` (`0x0040`) correspond to demo text fields #2..#15.
- Binary replay save additionally writes `DAT_140e452c4` (`0x0044`) from `DAT_1407c7798`, `DAT_140e452d8` (`0x0058`) from `DAT_140e44590`, `DAT_140e452e0` (`0x0060`) from `DAT_140e451b0`, and `DAT_140e452e4` (`0x0064`) from `DAT_140e4680c`.
- Stage transition code uses `DAT_140e452c8`, `cc`, and `d0` (`0x0048..0x0050`) as stage-group checkpoint defaults.
- Replay-mode player update uses `DAT_140e452e8` and `DAT_140e452ec` (`0x0068..0x006c`) instead of the normal player option globals `DAT_140e44194` and `DAT_140e41b70`.
- `0x00b4..0x0134` decodes as a compact float-heavy state snapshot: repeated `360.0, 600.0` pairs, fixed-point-looking `0x0000c000`, and counters `32`/`60`. Nearby player update code initializes similar globals (`DAT_140e445d8`, `DAT_140e445dc`, `DAT_140e44654`, `DAT_140e44648`) to the same values, so this region is likely player/subobject initial runtime state rather than timestamps.
- Demo text import/export uses the 15-field format string `%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d`, then serializes the same 8-byte input stream as text `%d,%d` records.
''', encoding='utf-8')

# scripts
(REV/'tools/scripts/parse_demo.py').write_text('''#!/usr/bin/env python3\nfrom pathlib import Path\nimport sys\nfor path in map(Path, sys.argv[1:]):\n    text=path.read_text(encoding='cp932', errors='replace')\n    print(path)\n    for i,line in enumerate(text.splitlines()[:20],1):\n        fields=line.split(',')\n        print(i, len(fields), fields[:16])\n''', encoding='utf-8')
(REV/'tools/scripts/inspect_save_replay.py').write_text('''#!/usr/bin/env python3\nfrom pathlib import Path\nimport sys, hashlib, math\ndef ent(b):\n    if not b: return 0\n    counts=[0]*256\n    for x in b: counts[x]+=1\n    n=len(b)\n    return -sum((c/n)*math.log2(c/n) for c in counts if c)\nfor path in map(Path, sys.argv[1:]):\n    b=path.read_bytes()\n    print(path)\n    print('size', len(b))\n    print('sha256', hashlib.sha256(b).hexdigest())\n    print('first64', b[:64].hex(' '))\n    print('entropy', ent(b))\n''', encoding='utf-8')
print('assets',len(rows),'reports written')
