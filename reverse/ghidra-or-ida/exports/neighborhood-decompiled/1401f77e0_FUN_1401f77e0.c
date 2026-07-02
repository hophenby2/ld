// Function: FUN_1401f77e0 @ 1401f77e0
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_1401f77e0(undefined8 *param_1)

{
  longlong lVar1;
  int iVar2;
  float fVar3;
  
  if (DAT_140ca59d8 == 0) {
    return 0xffffffff;
  }
  iVar2 = FUN_1401ae2b0(&DAT_1407cea94,&DAT_140c595ec,0x10);
  if (((iVar2 == 0) && (iVar2 = FUN_1401ae2b0(param_1,&DAT_140c595a8,0x44), iVar2 == 0)) &&
     (DAT_140c49268 == 0)) {
    return 0;
  }
  lVar1 = *(longlong *)(DAT_140c3e320 + 0x10);
  FUN_1401ef160(0);
  if (DAT_140b27168 != 0) {
    FUN_1401df4f0();
  }
  _DAT_140c595a8 = *param_1;
  uRam0000000140c595b0 = param_1[1];
  _DAT_140c595b8 = param_1[2];
  _DAT_140c595c0 = param_1[3];
  _DAT_140c595c8 = *(undefined4 *)(param_1 + 4);
  uRam0000000140c595cc = *(undefined4 *)((longlong)param_1 + 0x24);
  uRam0000000140c595d0 = *(undefined4 *)(param_1 + 5);
  uRam0000000140c595d4 = *(undefined4 *)((longlong)param_1 + 0x2c);
  _DAT_140c595d8 = *(undefined4 *)(param_1 + 6);
  _DAT_140c595dc = *(undefined4 *)((longlong)param_1 + 0x34);
  _DAT_140c595e0 = *(undefined4 *)(param_1 + 7);
  _DAT_140c595e4 = *(undefined4 *)((longlong)param_1 + 0x3c);
  _DAT_140c595e8 = *(undefined4 *)(param_1 + 8);
  FUN_1401ae2f0(&DAT_140c595ec,&DAT_1407cea94,0x10);
  fVar3 = DAT_1404ad408;
  *(undefined4 *)(lVar1 + 0x2a0) = *(undefined4 *)param_1;
  *(undefined4 *)(lVar1 + 0x2a4) = *(undefined4 *)((longlong)param_1 + 4);
  *(undefined4 *)(lVar1 + 0x2a8) = *(undefined4 *)(param_1 + 1);
  *(undefined4 *)(lVar1 + 0x2ac) = *(undefined4 *)((longlong)param_1 + 0xc);
  *(undefined4 *)(lVar1 + 0x2b0) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(lVar1 + 0x2b4) = *(undefined4 *)((longlong)param_1 + 0x24);
  *(undefined4 *)(lVar1 + 0x2b8) = *(undefined4 *)(param_1 + 5);
  *(undefined4 *)(lVar1 + 700) = *(undefined4 *)((longlong)param_1 + 0x2c);
  if (fVar3 <= *(float *)(param_1 + 8)) {
    fVar3 = *(float *)(param_1 + 8);
  }
  *(float *)(lVar1 + 0x2d0) = fVar3;
  *(undefined4 *)(lVar1 + 0x2d4) = DAT_140c595ec;
  *(undefined4 *)(lVar1 + 0x2d8) = DAT_140c595f0;
  *(undefined4 *)(lVar1 + 0x2dc) = DAT_140c595f4;
  *(undefined4 *)(DAT_140c3e320 + 0x18) = 1;
  FUN_1401f6140();
  DAT_140c491d4 = 1;
  return 0;
}


