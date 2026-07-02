// Function: FUN_1401171d0 @ 1401171d0
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1401171d0(void)

{
  errno_t eVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *_DstBuf;
  int *piVar4;
  undefined1 auStack_58 [32];
  FILE *local_38;
  char local_30 [32];
  ulonglong local_10;
  
  local_10 = DAT_1407c6b00 ^ (ulonglong)auStack_58;
  piVar4 = &DAT_140e8cf40;
  iVar3 = 0;
  puVar2 = &DAT_140e9fd40;
  _DstBuf = &DAT_140e8cf40;
  do {
    iVar3 = iVar3 + 1;
    FUN_140070ca0(local_30,0x20,"replay\\LD_replay%02d.dat");
    eVar1 = fopen_s(&local_38,local_30,"rb");
    if (eVar1 == 0) {
      fread(_DstBuf,0xa98,1,local_38);
      if (*piVar4 == 200) {
        *puVar2 = 1;
      }
      FUN_140323e90(local_38);
    }
    else {
      *puVar2 = 0;
    }
    _DstBuf = _DstBuf + 0x2a6;
    piVar4 = piVar4 + 0x2a6;
    puVar2 = puVar2 + 1;
  } while (iVar3 < 0x18);
  return;
}


