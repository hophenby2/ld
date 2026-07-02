#!/usr/bin/env python3
from pathlib import Path
import sys, hashlib, math
def ent(b):
    if not b: return 0
    counts=[0]*256
    for x in b: counts[x]+=1
    n=len(b)
    return -sum((c/n)*math.log2(c/n) for c in counts if c)
for path in map(Path, sys.argv[1:]):
    b=path.read_bytes()
    print(path)
    print('size', len(b))
    print('sha256', hashlib.sha256(b).hexdigest())
    print('first64', b[:64].hex(' '))
    print('entropy', ent(b))
