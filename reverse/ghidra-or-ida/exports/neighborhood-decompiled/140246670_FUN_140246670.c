// Function: FUN_140246670 @ 140246670
// Decompile completed: true

undefined8 FUN_140246670(longlong param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)(param_1 + 0x8a);
  if (*(uint *)(param_1 + 0x86) == uVar1) {
    return 0xffffffff;
  }
  iVar2 = *(uint *)(param_1 + 0x86) - uVar1;
  if (*(longlong *)(param_1 + 0x488) < (longlong)iVar2) {
    iVar2 = *(int *)(param_1 + 0x488);
  }
  FUN_1401ae2f0(*(undefined8 *)(param_1 + 0x480),(ulonglong)uVar1 + *(longlong *)(param_1 + 0x7a),
                (longlong)iVar2);
  *(longlong *)(param_1 + 0x490) = (longlong)iVar2;
  *(int *)(param_1 + 0x8a) = *(int *)(param_1 + 0x8a) + iVar2;
  return 0;
}


