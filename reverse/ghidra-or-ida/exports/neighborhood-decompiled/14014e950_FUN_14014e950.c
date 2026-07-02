// Function: FUN_14014e950 @ 14014e950
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_14014e950(undefined4 *param_1)

{
  longlong lVar1;
  bool bVar2;
  
  *param_1 = _DAT_1407cdae8;
  param_1[1] = DAT_1407cda80;
  *(undefined8 *)(param_1 + 2) = 0;
  param_1[4] = DAT_1407cda84;
  param_1[5] = DAT_1407cda8c;
  param_1[6] = DAT_1407cda88;
  param_1[7] = DAT_1407cda90;
  param_1[8] = DAT_1407cda94;
  bVar2 = DAT_1407cda98 == 0;
  param_1[10] = 0;
  param_1[9] = (uint)bVar2;
  param_1[0xb] = DAT_1407cdab4;
  param_1[0xc] = DAT_1407cdab8;
  param_1[0xd] = DAT_1407cdabc;
  param_1[0xe] = DAT_1407cdac0;
  param_1[0xf] = (uint)(DAT_1407cdac4 == 0);
  param_1[0x12] = DAT_1407cdad0;
  param_1[0x10] = DAT_1407cdac8;
  param_1[0x11] = DAT_1407cdacc;
  param_1[0x13] = DAT_1407cdad4;
  param_1[0x14] = DAT_1407cdad8;
  param_1[0x15] = DAT_1407cdaf4;
  param_1[0x16] = DAT_1407cdaf8;
  param_1[0x17] = DAT_1407cdaf0;
  param_1[0x18] = DAT_1407cdafc;
  param_1[0x19] = DAT_1407cdb00;
  param_1[0x1a] = 0;
  param_1[0x1b] = DAT_1407cda9c;
  param_1[0x1c] = DAT_1407cdaa0;
  if ((DAT_1407cdaa8 != 0) && (0 < DAT_1407cdab0)) {
    lVar1 = FUN_1401b6390((longlong)DAT_1407cdab0 << 2,
                          "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxGraphics.cpp",0x84bf);
    *(longlong *)(param_1 + 0x1e) = lVar1;
    if (lVar1 == 0) {
      FUN_140159b70(&DAT_1404a7d80,(longlong)DAT_1407cdab0 << 2);
      param_1[0x20] = 0;
      *(undefined8 *)(param_1 + 0x22) = 0;
      return;
    }
    FUN_1401ae2f0(lVar1,DAT_1407cdaa8,(longlong)DAT_1407cdab0 << 2);
    param_1[0x20] = DAT_1407cdab0;
    *(undefined8 *)(param_1 + 0x22) = 0;
    return;
  }
  *(undefined8 *)(param_1 + 0x1e) = 0;
  param_1[0x20] = 0;
  *(undefined8 *)(param_1 + 0x22) = 0;
  return;
}


