# DXArchive Key Function Analysis

## Confirmed candidate

Two addresses are associated with the same decompiled key-setting logic because of thunking/wrapping:

- `0x1401b23b0` — named `dxarchive_set_key_candidate`
- `0x1401399a0` — same decompiled body appears in exported neighborhood

Call site from startup:

```c
dxarchive_set_key_candidate("VanillaFever11");
```

This strongly matches DxLib's `SetDXArchiveKeyString("VanillaFever11")` behavior.

## Decompiled behavior

```c
undefined8 dxarchive_set_key_candidate(longlong key_string)
{
  ulonglong len;

  if (key_string == 0) {
    DAT_140976008 = 0;
    return 0;
  }

  DAT_140976008 = 1;
  len = strlen_like(key_string);

  if (0x3f < len) {
    memcpy_like(&DAT_14097600c, key_string, 0x3f);
    DAT_14097604b = 0;
    return 0;
  }

  strcpy_like(&DAT_14097600c, key_string);
  return 0;
}
```

## Global state

Likely global DXArchive key state:

| Address | Meaning |
|---|---|
| `DAT_140976008` | key-enabled flag; set to `1` when key string is non-null, `0` when null |
| `DAT_14097600c` | key string buffer |
| `DAT_14097604b` | terminator byte for max-length truncated key |

The copied maximum is `0x3f` bytes, plus terminator at `DAT_14097604b`, matching a 63-byte key string limit.

## Helper functions

| Address | Current interpretation | Evidence |
|---|---|---|
| `0x1401ae820` | `strlen_like` | Counts bytes/chars until null; supports character width modes 1/2/4. |
| `0x1401ae2f0` | `memcpy_like` | Copies `param_3` bytes from source to destination. |
| `0x1401ae790` | `strcpy_like` | Wrapper around string copy helper. |
| `0x1401ba9b0` | low-level length helper | Counts null-terminated string length depending on char width. |

## Confidence

High. The behavior exactly matches a public API like:

```c
SetDXArchiveKeyString(const char* KeyString)
```

with global state:

```c
bool g_DXArchiveKeyEnabled;
char g_DXArchiveKeyString[64];
```

and startup passes the known working key `VanillaFever11` before loading resources from `media.dxa`.

## Next references to trace

Find reads of:

- `DAT_140976008`
- `DAT_14097600c`
- `DAT_14097604b`

Those should lead to DXArchive open/decode functions that use the stored key string for archive decryption.
