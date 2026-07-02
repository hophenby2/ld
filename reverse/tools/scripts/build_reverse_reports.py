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
    sections.append(f'''## {p.relative_to(BASE)}\n\n- Size: {len(b)} bytes\n- SHA256: `{sha256(p)}`\n- First 64 bytes: `{b[:64].hex(' ')}`\n- Entropy first 4096 bytes: {entropy(b[:4096]):.4f}\n- Entropy full file: {entropy(b):.4f}\n''')
(REV/'analysis/save-replay-format.md').write_text('# Save / Config / Replay Binary Format Notes\n\n'+ '\n'.join(sections), encoding='utf-8')

# scripts
(REV/'tools/scripts/parse_demo.py').write_text('''#!/usr/bin/env python3\nfrom pathlib import Path\nimport sys\nfor path in map(Path, sys.argv[1:]):\n    text=path.read_text(encoding='cp932', errors='replace')\n    print(path)\n    for i,line in enumerate(text.splitlines()[:20],1):\n        fields=line.split(',')\n        print(i, len(fields), fields[:16])\n''', encoding='utf-8')
(REV/'tools/scripts/inspect_save_replay.py').write_text('''#!/usr/bin/env python3\nfrom pathlib import Path\nimport sys, hashlib, math\ndef ent(b):\n    if not b: return 0\n    counts=[0]*256\n    for x in b: counts[x]+=1\n    n=len(b)\n    return -sum((c/n)*math.log2(c/n) for c in counts if c)\nfor path in map(Path, sys.argv[1:]):\n    b=path.read_bytes()\n    print(path)\n    print('size', len(b))\n    print('sha256', hashlib.sha256(b).hexdigest())\n    print('first64', b[:64].hex(' '))\n    print('entropy', ent(b))\n''', encoding='utf-8')
print('assets',len(rows),'reports written')
