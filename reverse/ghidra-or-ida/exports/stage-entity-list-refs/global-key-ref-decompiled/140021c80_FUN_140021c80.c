// Function: FUN_140021c80 @ 140021c80
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140021c80(undefined4 *param_1)

{
  int iVar1;
  undefined1 auVar2 [16];
  double dVar3;
  float fVar4;
  longlong lVar5;
  short sVar6;
  float fVar7;
  float fVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  float fVar12;
  undefined4 uVar13;
  undefined2 uVar14;
  undefined4 in_stack_fffffffffffffee0;
  undefined4 uVar15;
  undefined2 uVar16;
  undefined1 in_stack_fffffffffffffee8 [16];
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  undefined8 uStack_c0;
  
  uVar16 = (undefined2)((uint)in_stack_fffffffffffffee0 >> 0x10);
  uStack_c0 = 0;
  uStack_c0._4_4_ = 0;
  if ((0 < DAT_140e44e6c) && (lVar5 = DAT_140e45d80, uStack_c0._4_4_ = 0, DAT_140e45d80 != 0)) {
    do {
      if (*(int *)(lVar5 + 4) == DAT_140e44308) {
        uStack_c0 = *(undefined8 *)(lVar5 + 0x18);
      }
      lVar5 = *(longlong *)(lVar5 + 0x60);
    } while (lVar5 != 0);
  }
  dVar9 = (double)FUN_1403300b4((double)(DAT_140e445dc - (float)param_1[0xb]),
                                (double)(DAT_140e445d8 - (float)param_1[10]));
  dVar3 = DAT_140539f40;
  dVar9 = dVar9 * DAT_14053aba0;
  dVar10 = DAT_140539f40;
  if (param_1[5] == 0) {
    iVar1 = param_1[3];
    if (iVar1 < 0) {
      dVar10 = 0.0;
    }
    else if (iVar1 < 0x32) {
      dVar10 = (double)FUN_140332d90(((double)iVar1 - 0.0) * DAT_14053a670 * DAT_14053a020 *
                                     DAT_140539d28);
      dVar10 = dVar10 + 0.0;
    }
    else {
      dVar10 = dVar3;
      if (iVar1 == 0x32) {
        param_1[0x15] = 0;
      }
    }
    dVar11 = (double)FUN_1403307c0();
    param_1[10] = (float)(dVar11 * *(double *)(param_1 + 0x12)) + (float)param_1[10];
    dVar11 = (double)FUN_140332d90();
    fVar12 = (float)(dVar11 * *(double *)(param_1 + 0x12)) + (float)param_1[0xb] +
             (float)iVar1 * _DAT_140539ce8;
    param_1[0xb] = fVar12;
    if (param_1[0x15] == 0) {
      uVar13 = DAT_14053b33c;
      FUN_140079c10(param_1,2,fVar12,0,DAT_14053b33c);
      uVar14 = (undefined2)((uint)uVar13 >> 0x10);
      if ((int)param_1[7] < 1) {
        fVar12 = (float)param_1[0xb];
        fVar7 = (float)FUN_140334430((float)param_1[10] - DAT_140e445d8);
        fVar4 = DAT_140e445dc;
        fVar8 = (float)FUN_140334430(fVar12 - DAT_140e445dc);
        if (fVar7 + fVar8 < 0.0) {
          fVar7 = (float)FUN_1403352f8();
        }
        else {
          fVar7 = SQRT(fVar7 + fVar8);
        }
        uVar13 = DAT_14053ac2c;
        if ((((float)(param_1[0x14] + 0x1e) <= fVar7) && (fVar12 < DAT_14053ae90)) &&
           (fVar12 < fVar4)) {
          dVar11 = DAT_14053a048;
          if (((DAT_140e419b8 != 0) && (dVar11 = DAT_14053a088, DAT_140e419b8 != 1)) &&
             ((dVar11 = DAT_14053a0b0, DAT_140e419b8 != 2 &&
              ((DAT_140e419b8 != 3 && (dVar11 = dVar3, DAT_140e419b8 == 4)))))) {
            dVar11 = DAT_14053a110;
          }
          auVar17._12_4_ = in_stack_fffffffffffffee8._12_4_;
          auVar17._0_8_ = in_stack_fffffffffffffee8._0_8_;
          auVar17._8_4_ = 1;
          auVar18._8_8_ = auVar17._8_8_;
          auVar18._0_8_ = dVar11;
          sVar6 = (short)(((int)dVar9 & 0xffffU) + 0x400 >> 0xb) * 0x800;
          uVar15 = DAT_14053ac2c;
          FUN_14006c2f0(0,0,param_1[10],fVar12,CONCAT22(uVar14,sVar6),DAT_14053ac2c,dVar11,
                        auVar18._8_8_,0);
          uVar16 = (undefined2)((uint)uVar15 >> 0x10);
          if (2 < DAT_140e419b8) {
            auVar19._12_4_ = auVar18._12_4_;
            auVar19._0_8_ = auVar18._0_8_;
            auVar19._8_4_ = 1;
            FUN_14006c2f0(0,0,param_1[10],param_1[0xb],sVar6,uVar13,dVar11 + DAT_140539f90,
                          auVar19._8_8_,0);
            uVar16 = (undefined2)((uint)uVar13 >> 0x10);
          }
        }
        FUN_14007b010(param_1,200,1);
        FUN_140079e20(param_1,0);
        *param_1 = 0;
      }
    }
  }
  auVar2._8_4_ = SUB84(dVar10,0);
  auVar2._0_8_ = dVar10;
  auVar2._12_4_ = (int)((ulonglong)dVar10 >> 0x20);
  FUN_1400c8410(DAT_140e44744,0x23,7,param_1[10],param_1[0xb],
                CONCAT22(uVar16,*(short *)(param_1 + 3) * 0x29a),auVar2,0xff,0xff,0xff,0xff,1,0);
  if ((uStack_c0._4_4_ < 1) || (DAT_140e4430c < 1)) {
    FUN_140079e20(param_1,0);
    *param_1 = 0;
  }
  if (((((float)param_1[10] < DAT_140e445d8 / DAT_14053ab70 - DAT_14053ad9c) ||
       (DAT_140e445d8 / DAT_14053ab70 + DAT_14053af38 < (float)param_1[10])) ||
      ((float)param_1[0xb] < DAT_14053b3bc)) || (DAT_14053af80 < (float)param_1[0xb])) {
    *param_1 = 0;
  }
  return;
}


