// Function: FUN_140133f30 @ 140133f30
// Decompile completed: true

undefined8
FUN_140133f30(float param_1,float param_2,ushort param_3,ushort param_4,float param_5,float param_6)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  
  dVar2 = (double)param_4 * DAT_14053a020 * DAT_140539d28;
  dVar1 = (double)FUN_1403307c0(dVar2);
  dVar6 = (double)param_3 * DAT_14053a020 * DAT_140539d28;
  dVar2 = (double)FUN_140332d90(dVar2);
  dVar3 = (double)FUN_1403307c0(dVar6);
  dVar4 = (double)FUN_140332d90(dVar6);
  dVar5 = (double)FUN_1403307c0(dVar6);
  dVar6 = (double)FUN_140332d90(dVar6);
  return CONCAT44((float)(dVar5 * dVar2 * (double)param_5 + dVar6 * dVar1 * (double)param_6) +
                  param_2,(float)(dVar3 * dVar1 * (double)param_6 - dVar4 * dVar2 * (double)param_5)
                          + param_1);
}


