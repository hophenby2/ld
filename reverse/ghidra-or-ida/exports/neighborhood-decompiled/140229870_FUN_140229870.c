// Function: FUN_140229870 @ 140229870
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_140229870(int *param_1)

{
  int iVar1;
  ulonglong uVar2;
  uint uVar3;
  undefined1 auStack_88 [32];
  undefined8 *local_68;
  undefined4 local_60;
  undefined4 local_58;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  ulonglong uVar4;
  
  local_18 = DAT_1407c6b00 ^ (ulonglong)auStack_88;
  if (DAT_140ca5960 == 0) {
    return 0;
  }
  uVar2 = 0;
  uVar4 = uVar2;
  do {
    uVar3 = (uint)uVar4;
    if (*(int *)((longlong)&DAT_140d81970 + uVar2) != *(int *)((longlong)&DAT_1407cea94 + uVar2))
    break;
    uVar3 = uVar3 + 1;
    uVar4 = (ulonglong)uVar3;
    uVar2 = uVar2 + 4;
  } while ((longlong)uVar2 < 0x10);
  if (uVar3 == 4) {
    if (DAT_140d3ae18 != 0) goto LAB_1402299e2;
    if (((((((DAT_140d81948 == param_1[7]) && (DAT_140d8193c == param_1[4])) &&
           (DAT_140d81940 == param_1[5])) &&
          ((DAT_140d81944 == param_1[6] && (DAT_140d81938 == param_1[3])))) &&
         ((DAT_140d8192c == *param_1 &&
          ((DAT_140d81930 == param_1[1] && (DAT_140d81934 == param_1[2])))))) &&
        (DAT_140d81968 == param_1[0xf])) &&
       ((((DAT_140d8195c == param_1[0xc] && (DAT_140d81960 == param_1[0xd])) &&
         (DAT_140d81964 == param_1[0xe])) &&
        (((DAT_140d81958 == param_1[0xb] && (DAT_140d8194c == param_1[8])) &&
         ((DAT_140d81950 == param_1[9] &&
          ((DAT_140d81954 == param_1[10] && (DAT_140d8196c == param_1[0x10])))))))))) {
      return 0;
    }
  }
  else if (DAT_140d3ae18 != 0) goto LAB_1402299e2;
  FUN_1401ef160(0);
  if (DAT_140b27168 != 0) {
    FUN_1401df4f0();
  }
LAB_1402299e2:
  _DAT_140d8192c = *(undefined8 *)param_1;
  _DAT_140d81934 = *(undefined8 *)(param_1 + 2);
  _DAT_140d8193c = *(undefined8 *)(param_1 + 4);
  _DAT_140d81944 = *(undefined8 *)(param_1 + 6);
  DAT_140d8194c = param_1[8];
  DAT_140d81950 = param_1[9];
  DAT_140d81954 = param_1[10];
  DAT_140d81958 = param_1[0xb];
  DAT_140d8195c = param_1[0xc];
  DAT_140d81960 = param_1[0xd];
  DAT_140d81964 = param_1[0xe];
  DAT_140d81968 = param_1[0xf];
  DAT_140d8196c = param_1[0x10];
  FUN_1401ae2f0(&DAT_140d81970,&DAT_1407cea94,0x10);
  local_48 = *(undefined8 *)param_1;
  uStack_40 = *(undefined8 *)(param_1 + 2);
  local_68 = &local_48;
  local_58 = 1;
  local_60 = 3;
  local_38 = *(undefined8 *)(param_1 + 8);
  uStack_30 = *(undefined8 *)(param_1 + 10);
  local_24 = DAT_140d81970;
  local_28 = param_1[0x10];
  local_20 = DAT_140d81974;
  local_1c = DAT_140d81978;
  FUN_14023dd40(&DAT_140ca5d24,0,0,0xb);
  local_58 = 1;
  local_68 = &local_48;
  local_60 = 3;
  FUN_14023dd40(&DAT_140ca5d24,3,0);
  FUN_1402259a0();
  iVar1 = FUN_140222890(param_1);
  return -(uint)(iVar1 != 0);
}


