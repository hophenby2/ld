// Function: FUN_140275950 @ 140275950
// Decompile completed: true

undefined8 FUN_140275950(longlong param_1,undefined8 param_2,int param_3)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar2 = (longlong)param_3;
  if (param_3 == 0) {
    return 0;
  }
  *(int *)(param_1 + 0x10) = param_3;
  if (param_3 < 0x3f) {
    *(undefined8 *)(param_1 + 8) = 0;
    FUN_1401ae2f0(param_1 + 0x18,param_2,lVar2);
    *(undefined1 *)(lVar2 + 0x18 + param_1) = 0;
  }
  else {
    lVar1 = FUN_1401b6390((longlong)(param_3 + 1),
                          "..\\..\\..\\..\\..\\Source\\Library\\Main\\DxUseCLibLive2DCubism4.cpp",
                          0x54a);
    *(longlong *)(param_1 + 8) = lVar1;
    if (lVar1 == 0) {
      return 0xffffffff;
    }
    FUN_1401ae2f0(lVar1,param_2,lVar2);
    *(undefined1 *)(lVar2 + *(longlong *)(param_1 + 8)) = 0;
  }
  *(undefined1 *)(param_1 + 0xac) = 0;
  if (*(longlong *)(param_1 + 0xb0) != 0) {
    FUN_1401b6700();
    *(undefined8 *)(param_1 + 0xb0) = 0;
  }
  *(undefined4 *)(param_1 + 0xb8) = 0;
  *(undefined2 *)(param_1 + 0xbc) = 0;
  *(undefined1 *)(param_1 + 0x58) = 0;
  if (*(longlong *)(param_1 + 0x60) != 0) {
    FUN_1401b6700();
    *(undefined8 *)(param_1 + 0x60) = 0;
  }
  *(undefined8 *)(param_1 + 0x68) = 0;
  return 0;
}


