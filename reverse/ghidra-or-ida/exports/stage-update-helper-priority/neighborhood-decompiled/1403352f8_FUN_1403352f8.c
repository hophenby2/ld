// Function: FUN_1403352f8 @ 1403352f8
// Decompile completed: true

float FUN_1403352f8(float param_1)

{
  float fVar1;
  
  if (((uint)param_1 & 0x7f800000) == 0x7f800000) {
    if (((uint)param_1 & 0x7fffff) != 0) {
      fVar1 = (float)FUN_14033fd44(param_1);
      return fVar1;
    }
    if ((int)param_1 < 0) goto LAB_140335330;
  }
  if (-1 < (int)param_1 || ABS(param_1) == 0.0) {
    return SQRT(param_1);
  }
LAB_140335330:
  fVar1 = (float)FUN_14033fbf4("sqrtf",5,0xffc00000,1,8,0x21,param_1,0,1);
  return fVar1;
}


