// Function: FUN_1401346a0 @ 1401346a0
// Decompile completed: true

undefined8 FUN_1401346a0(undefined8 param_1,int param_2)

{
  float fVar1;
  float fVar2;
  undefined4 local_res18;
  undefined4 local_res20;
  undefined4 uStackX_24;
  
  uStackX_24 = (float)((ulonglong)param_1 >> 0x20);
  fVar2 = (float)param_2;
  local_res20 = (float)param_1;
  fVar1 = fVar2 + DAT_140e445d8 / DAT_14053ab70;
  local_res18 = local_res20;
  if (local_res20 < fVar1) {
    local_res18 = fVar1;
  }
  fVar1 = (DAT_14053aec0 - fVar2) + DAT_140e445d8 / DAT_14053ab70;
  if (fVar1 < local_res20) {
    local_res18 = fVar1;
  }
  fVar1 = uStackX_24;
  if (uStackX_24 < fVar2) {
    fVar1 = fVar2;
  }
  if (DAT_14053af14 - fVar2 < uStackX_24) {
    return CONCAT44(DAT_14053af14 - fVar2,local_res18);
  }
  return CONCAT44(fVar1,local_res18);
}


