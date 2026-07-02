#!/usr/bin/env python3
from pathlib import Path
import sys
for path in map(Path, sys.argv[1:]):
    text=path.read_text(encoding='cp932', errors='replace')
    print(path)
    for i,line in enumerate(text.splitlines()[:20],1):
        fields=line.split(',')
        print(i, len(fields), fields[:16])
