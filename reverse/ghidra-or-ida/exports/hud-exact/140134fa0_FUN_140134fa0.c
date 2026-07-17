// Function: FUN_140134fa0 @ 140134fa0
// Decompile completed: true

undefined4 * FUN_140134fa0(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = 0xff;
  param_1[1] = 0xff;
  param_1[2] = 0xff;
  switch(param_2) {
  default:
    return param_1;
  case 1:
    param_1[2] = 0x78;
    param_1[1] = 0x78;
    return param_1;
  case 2:
    param_1[1] = 200;
    param_1[2] = 0x6e;
    return param_1;
  case 3:
    goto switchD_140134fd0_caseD_3;
  case 4:
    *param_1 = 0x78;
switchD_140134fd0_caseD_3:
    param_1[2] = 0x78;
    return param_1;
  case 5:
    *param_1 = 0x78;
    return param_1;
  case 6:
    *param_1 = 0x78;
    param_1[1] = 0x78;
    return param_1;
  case 7:
    *param_1 = 0xdc;
    param_1[1] = 0x78;
    return param_1;
  }
}
