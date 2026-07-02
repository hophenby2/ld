// Function: FUN_1402239b0 @ 1402239b0
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_1402239b0(longlong param_1,undefined8 *param_2,int *param_3,int param_4,undefined8 param_5,
             int param_6,int param_7,char *param_8,ulonglong param_9,char *param_10,
             undefined4 param_11,int param_12,undefined4 param_13)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  int iVar8;
  ulonglong uVar9;
  int iVar10;
  longlong lVar11;
  ulonglong uVar12;
  byte bVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  undefined1 auStack_1a8 [32];
  undefined8 local_188;
  undefined8 local_180;
  ulonglong local_178;
  undefined4 local_170;
  ulonglong local_168;
  ulonglong local_160;
  undefined8 *local_158;
  undefined4 local_150;
  undefined4 local_148;
  undefined4 local_140;
  undefined4 local_138;
  undefined4 local_130;
  undefined4 local_128;
  undefined4 local_120;
  undefined4 local_118;
  int local_108;
  int local_104;
  int local_100;
  ulonglong local_f8;
  char *local_f0;
  undefined8 local_e8;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  char *local_c0;
  ulonglong local_b8;
  int local_b0;
  int local_ac;
  int *local_a8;
  undefined8 *local_a0;
  ulonglong local_98;
  ulonglong local_90;
  undefined8 local_88;
  undefined4 local_80 [2];
  undefined8 local_78;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  undefined8 local_58;
  int local_50;
  int local_4c;
  ulonglong local_48;
  
  local_48 = DAT_1407c6b00 ^ (ulonglong)auStack_1a8;
  iVar4 = -1;
  cVar1 = *param_8;
  local_f0 = param_8;
  uVar7 = 0;
  local_88 = 0;
  local_90 = 0;
  uVar12 = (ulonglong)((byte)(cVar1 - 1U) < 5);
  local_e8 = param_5;
  local_b8 = param_9;
  cVar2 = *(char *)(param_1 + 9);
  local_c0 = param_10;
  local_ac = 1;
  if (cVar2 != '\0') {
    local_ac = 6;
  }
  local_100 = param_4;
  local_f8 = uVar12;
  local_a8 = param_3;
  local_a0 = param_2;
  if (((((*param_3 == 0) && (param_3[2] == param_6)) && (param_3[1] == 0)) &&
      ((param_3[3] == param_7 &&
       (iVar8 = *(int *)(param_1 + 0x48), iVar8 <= *(int *)(param_8 + 0x440))))) &&
     ((((cVar1 == '\x01' &&
        (*(int *)(&DAT_140ca5bac + (longlong)*(int *)(param_1 + 4) * 4) == 0x31545844)) ||
       (((cVar1 == '\x02' &&
         (*(int *)(&DAT_140ca5bac + (longlong)*(int *)(param_1 + 4) * 4) == 0x32545844)) ||
        ((cVar1 == '\x03' &&
         (*(int *)(&DAT_140ca5bac + (longlong)*(int *)(param_1 + 4) * 4) == 0x33545844)))))) ||
      (((cVar1 == '\x04' &&
        (*(int *)(&DAT_140ca5bac + (longlong)*(int *)(param_1 + 4) * 4) == 0x34545844)) ||
       ((cVar1 == '\x05' &&
        (*(int *)(&DAT_140ca5bac + (longlong)*(int *)(param_1 + 4) * 4) == 0x35545844)))))))) {
    local_90 = *(ulonglong *)(param_8 + 0x438);
    if (cVar2 == '\0') {
      iVar15 = 0;
      if (0 < iVar8) {
        do {
          if (local_f8 == 0) {
            iVar8 = (uint)(byte)local_f0[4] * param_7 * param_6;
          }
          else {
            iVar8 = (uint)(byte)local_f0[5] * ((int)(param_7 + 3 + (param_7 + 3 >> 0x1f & 3U)) >> 2)
                    * ((int)(param_6 + 3 + (param_6 + 3 >> 0x1f & 3U)) >> 2) * 2;
          }
          if (local_100 == 0) {
            local_180 = (char *)CONCAT44(local_180._4_4_,param_13);
            local_188 = (int *)((ulonglong)local_188 & 0xffffffff00000000);
            iVar5 = FUN_1402230e0(param_5,iVar15,local_80,0);
          }
          else {
            iVar4 = FUN_14023ba80(param_6,param_7,
                                  *(undefined4 *)
                                   (&DAT_140ca5bac + (longlong)*(int *)(param_1 + 4) * 4),param_13);
            while (iVar4 == -1) {
              iVar4 = FUN_1401ad850();
              if (iVar4 != 0) {
                return 0xffffffff;
              }
              FUN_1401b7120(1);
              iVar4 = FUN_14023ba80(param_6,param_7,
                                    *(undefined4 *)
                                     (&DAT_140ca5bac + (longlong)*(int *)(param_1 + 4) * 4),param_13
                                   );
            }
            local_188._4_4_ = (undefined4)((ulonglong)local_188 >> 0x20);
            local_188 = (int *)CONCAT44(local_188._4_4_,param_13);
            uVar7 = (&DAT_140e0c2b8)[(longlong)iVar4 * 4];
            iVar5 = FUN_140222ed0(uVar7,local_80,0,0x2000);
          }
          if (iVar5 != 0) {
LAB_1402248ea:
            FUN_1401594b0(&DAT_1404e7f58);
            return 0xffffffff;
          }
          FUN_1401ae2f0(local_78,local_90,(longlong)iVar8);
          if (local_100 == 0) {
            FUN_1402231b0(param_5,iVar15,param_13);
          }
          else {
            FUN_140222fa0(uVar7,param_13);
            FUN_140223040(param_5,iVar15,&local_88);
            local_188 = (int *)CONCAT44(local_188._4_4_,param_13);
            FUN_140222ba0(uVar7,0,local_88);
            FUN_140220340(local_88,param_13);
            FUN_14023c5b0(iVar4,param_13);
            iVar4 = -1;
          }
          local_90 = local_90 + (longlong)iVar8;
          iVar15 = iVar15 + 1;
          iVar8 = param_6 >> 1;
          iVar5 = param_7 >> 1;
          param_6 = 1;
          if (0 < iVar8) {
            param_6 = iVar8;
          }
          param_7 = 1;
          if (0 < iVar5) {
            param_7 = iVar5;
          }
        } while (iVar15 < *(int *)(param_1 + 0x48));
      }
    }
    else {
      local_108 = 0;
      do {
        local_104 = 0;
        iVar5 = param_7;
        iVar15 = param_6;
        if (0 < iVar8) {
          do {
            if (uVar12 == 0) {
              iVar8 = (uint)(byte)param_8[4] * iVar5 * iVar15;
            }
            else {
              iVar8 = (uint)(byte)param_8[5] * ((int)(iVar5 + 3 + (iVar5 + 3 >> 0x1f & 3U)) >> 2) *
                      ((int)(iVar15 + 3 + (iVar15 + 3 >> 0x1f & 3U)) >> 2) * 2;
            }
            if (local_100 == 0) {
              local_178 = CONCAT44(local_178._4_4_,param_13);
              local_180 = (char *)((ulonglong)local_180 & 0xffffffff00000000);
              local_188 = (int *)0x0;
              iVar3 = FUN_1402204c0(local_e8,local_108,local_104,local_80);
            }
            else {
              iVar4 = FUN_14023ba80(iVar15,iVar5,
                                    *(undefined4 *)
                                     (&DAT_140ca5bac + (longlong)*(int *)(param_1 + 4) * 4),param_13
                                   );
              while (iVar4 == -1) {
                iVar4 = FUN_1401ad850();
                if (iVar4 != 0) {
                  return 0xffffffff;
                }
                FUN_1401b7120(1);
                iVar4 = FUN_14023ba80(iVar15,iVar5,
                                      *(undefined4 *)
                                       (&DAT_140ca5bac + (longlong)*(int *)(param_1 + 4) * 4),
                                      param_13);
              }
              local_188._4_4_ = (undefined4)((ulonglong)local_188 >> 0x20);
              local_188 = (int *)CONCAT44(local_188._4_4_,param_13);
              uVar7 = (&DAT_140e0c2b8)[(longlong)iVar4 * 4];
              iVar3 = FUN_140222ed0(uVar7,local_80,0,0x2000);
            }
            if (iVar3 != 0) {
LAB_140224637:
              FUN_1401594b0(&DAT_1404e7f18);
              return 0xffffffff;
            }
            FUN_1401ae2f0(local_78,local_90,(longlong)iVar8);
            if (local_100 == 0) {
              FUN_1402205c0(local_e8,local_108,local_104,param_13);
            }
            else {
              FUN_140222fa0(uVar7,param_13);
              local_188._0_4_ = param_13;
              FUN_140220400(local_e8,local_108,local_104,&local_88);
              local_188 = (int *)CONCAT44(local_188._4_4_,param_13);
              FUN_140222ba0(uVar7,0,local_88,0);
              FUN_140220340(local_88,param_13);
              FUN_14023c5b0(iVar4,param_13);
              iVar4 = -1;
            }
            local_90 = local_90 + (longlong)iVar8;
            iVar8 = *(int *)(param_1 + 0x48);
            local_104 = local_104 + 1;
            iVar3 = iVar15 >> 1;
            iVar14 = iVar5 >> 1;
            iVar15 = 1;
            if (0 < iVar3) {
              iVar15 = iVar3;
            }
            iVar5 = 1;
            if (0 < iVar14) {
              iVar5 = iVar14;
            }
            param_8 = local_f0;
            uVar12 = local_f8;
          } while (local_104 < iVar8);
        }
        local_108 = local_108 + 1;
      } while (local_108 < 6);
    }
  }
  else if ((*(int *)(&DAT_140ca5bac + (longlong)*(int *)(param_1 + 4) * 4) + 0xceaba7bcU < 0x4000001
           ) && ((*(int *)(&DAT_140ca5bac + (longlong)*(int *)(param_1 + 4) * 4) + 0xceaba7bcU &
                 0xffffff) == 0)) {
    FUN_1401594b0(&DAT_1404b30d0);
  }
  else {
    iVar8 = *(int *)(param_1 + 0x48);
    if (*(int *)(param_8 + 0x440) < iVar8) {
      iVar8 = 1;
      local_d0 = 1;
      iVar15 = param_3[2] - *param_3;
      if (1 < iVar15) {
        do {
          iVar8 = iVar8 * 2;
          local_d0 = iVar8;
        } while (iVar8 < iVar15);
      }
      iVar8 = 1;
      local_cc = 1;
      if (1 < param_3[3] - param_3[1]) {
        do {
          iVar8 = iVar8 * 2;
          local_cc = iVar8;
        } while (iVar8 < param_3[3] - param_3[1]);
      }
      local_e0 = (uint)(byte)param_10[4] * local_d0;
      iVar8 = local_e0 * local_cc;
      uVar6 = FUN_1401b6390((longlong)(iVar8 * 2),
                            "..\\..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxGraphicsD3D9.cpp"
                            ,0x6efb);
      uVar12 = local_90;
      local_98 = (longlong)iVar8 + uVar6;
      local_f8 = uVar6;
      if (uVar6 == 0) {
        FUN_1401594b0(&DAT_1404b3120);
        return 0xffffffff;
      }
      local_b0 = *(int *)(param_9 + 0x42c) * *(int *)(param_9 + 0x430);
      local_e8 = CONCAT44(local_e8._4_4_,*(int *)(local_f0 + 0x42c) * *(int *)(local_f0 + 0x430));
      local_108 = 0;
      local_c4 = 0;
      local_c8 = 0;
      iVar8 = local_d0;
      iVar15 = local_cc;
      do {
        local_104 = param_7;
        uVar16 = 0;
        iVar5 = iVar8;
        iVar3 = iVar15;
        local_d4 = param_6;
        iVar14 = iVar8;
        iVar10 = iVar15;
        if (0 < *(int *)(param_1 + 0x48)) {
          do {
            local_d8 = iVar3;
            local_dc = iVar5;
            bVar13 = (byte)uVar16;
            if (uVar16 == 0) {
              if (((param_12 == 0) || (local_c0[0xb] == '\0')) ||
                 (*(longlong *)(local_b8 + 0x438) != 0)) {
                local_148 = 0;
              }
              else {
                local_148 = 1;
              }
              local_178 = (longlong)local_c8 + *(longlong *)(local_b8 + 0x438);
              local_118 = 0;
              local_120 = 0;
              local_128 = param_11;
              local_130 = 0;
              local_138 = DAT_140824374;
              local_140 = *(undefined4 *)(param_1 + 0x1c);
              local_150 = 0;
              local_158 = local_a0;
              local_170 = *(undefined4 *)(local_b8 + 0x430);
              local_160 = uVar12;
              local_168 = local_b8;
              local_180 = local_f0;
              local_188 = (int *)CONCAT44(local_188._4_4_,*(undefined4 *)(local_f0 + 0x430));
              FUN_14017ae00(local_f8,local_e0,local_c0,
                            (longlong)local_c4 + *(longlong *)(local_f0 + 0x438));
              local_90 = local_f8;
            }
            else {
              local_158 = (undefined8 *)CONCAT44(local_158._4_4_,iVar10);
              local_160 = CONCAT44(local_160._4_4_,iVar14);
              uVar9 = uVar6;
              local_90 = local_98;
              if ((uVar16 & 1) == 0) {
                uVar9 = local_98;
                local_90 = uVar6;
              }
              local_168 = local_168 & 0xffffffff00000000;
              local_170 = 0;
              local_178 = local_178 & 0xffffffff00000000;
              local_180 = (char *)((ulonglong)local_180 & 0xffffffff00000000);
              local_188 = (int *)CONCAT44(local_188._4_4_,local_e0);
              FUN_140181550(local_c0,local_90,local_e0,uVar9);
            }
            iVar8 = local_d4;
            local_64 = local_a8[3] >> (bVar13 & 0x1f);
            local_70 = *local_a8 >> (bVar13 & 0x1f);
            local_68 = local_a8[2] >> (bVar13 & 0x1f);
            local_6c = local_a8[1] >> (bVar13 & 0x1f);
            if (local_68 == local_70) {
              local_68 = local_70 + 1;
            }
            if (local_64 == local_6c) {
              local_64 = local_6c + 1;
            }
            if (local_100 == 0) {
              if (*(char *)(param_1 + 9) == '\0') {
                local_180 = (char *)CONCAT44(local_180._4_4_,param_13);
                local_188 = (int *)((ulonglong)local_188 & 0xffffffff00000000);
                iVar8 = FUN_1402230e0(param_5,uVar16,local_80,&local_70);
                goto LAB_140224715;
              }
              local_188 = &local_70;
              local_178 = CONCAT44(local_178._4_4_,param_13);
              local_180 = (char *)((ulonglong)local_180._4_4_ << 0x20);
              iVar8 = FUN_1402204c0(param_5,local_108,uVar16,local_80);
              if (iVar8 != 0) {
                FUN_1401b6700(local_f8);
                goto LAB_140224637;
              }
            }
            else {
              iVar4 = FUN_14023ba80(local_d4,local_104,
                                    *(undefined4 *)
                                     (&DAT_140ca5bac + (longlong)*(int *)(param_1 + 4) * 4),param_13
                                   );
              while (iVar4 == -1) {
                iVar4 = FUN_1401ad850();
                if (iVar4 != 0) {
                  FUN_1401b6700(local_f8);
                  FUN_1401594b0(&DAT_1404e7f90);
                  return 0xffffffff;
                }
                FUN_1401b7120(1);
                iVar4 = FUN_14023ba80(iVar8,local_104,
                                      *(undefined4 *)
                                       (&DAT_140ca5bac + (longlong)*(int *)(param_1 + 4) * 4),
                                      param_13);
              }
              local_188._4_4_ = (undefined4)((ulonglong)local_188 >> 0x20);
              local_188 = (int *)CONCAT44(local_188._4_4_,param_13);
              uVar7 = (&DAT_140e0c2b8)[(longlong)iVar4 * 4];
              iVar8 = FUN_140222ed0(uVar7,local_80,&local_70,0x2000);
LAB_140224715:
              if (iVar8 != 0) {
                FUN_1401b6700(local_f8);
                goto LAB_1402248ea;
              }
            }
            local_118 = 0;
            local_120 = 0;
            local_128 = 0;
            local_130 = 0;
            local_138 = 0;
            local_140 = 0;
            local_148 = 0;
            local_150 = 0;
            local_50 = local_dc;
            local_4c = local_d8;
            local_158 = &local_58;
            local_160 = uVar12;
            local_168 = 0;
            local_170 = 0;
            local_178 = 0;
            local_58 = 0;
            local_180 = local_c0;
            local_188 = (int *)CONCAT44(local_188._4_4_,local_e0);
            FUN_14017ae00(local_78,local_80[0],local_c0,local_90);
            if (local_100 == 0) {
              if (*(char *)(param_1 + 9) == '\0') {
                FUN_1402231b0(param_5,uVar16,param_13);
              }
              else {
                FUN_1402205c0(param_5,local_108,uVar16,param_13);
              }
            }
            else {
              local_90 = 0;
              FUN_140222fa0(uVar7,param_13);
              if (*(char *)(param_1 + 9) == '\0') {
                FUN_140223040(param_5,uVar16,&local_90,param_13);
              }
              else {
                local_188 = (int *)CONCAT44(local_188._4_4_,param_13);
                FUN_140220400(param_5,local_108,uVar16,&local_90);
              }
              local_60 = local_70;
              local_5c = local_6c;
              local_188 = (int *)CONCAT44(local_188._4_4_,param_13);
              FUN_140222ba0(uVar7,&local_70,local_90,&local_60);
              FUN_140220340(local_90,param_13);
              FUN_14023c5b0(iVar4,param_13);
              iVar4 = -1;
            }
            uVar16 = uVar16 + 1;
            iVar8 = local_d4 >> 1;
            iVar15 = local_104 >> 1;
            iVar5 = 1;
            if (local_dc >> 1 != 0) {
              iVar5 = local_dc >> 1;
            }
            iVar3 = 1;
            if (local_d8 >> 1 != 0) {
              iVar3 = local_d8 >> 1;
            }
            local_d4 = 1;
            if (0 < iVar8) {
              local_d4 = iVar8;
            }
            local_104 = 1;
            if (0 < iVar15) {
              local_104 = iVar15;
            }
            uVar6 = local_f8;
            iVar14 = local_dc;
            iVar8 = local_d0;
            iVar10 = local_d8;
            iVar15 = local_cc;
          } while ((int)uVar16 < *(int *)(param_1 + 0x48));
        }
        local_d8 = iVar3;
        local_dc = iVar5;
        local_108 = local_108 + 1;
        local_c8 = local_c8 + local_b0;
        local_c4 = local_c4 + (int)local_e8;
      } while (local_108 < local_ac);
      FUN_1401b6700(uVar6);
    }
    else {
      uVar12 = *(ulonglong *)(param_8 + 0x438);
      local_90 = uVar12;
      if (cVar2 == '\0') {
        local_108 = 0;
        if (0 < iVar8) {
          do {
            bVar13 = local_f0[4];
            if (local_100 == 0) {
              local_180 = (char *)CONCAT44(local_180._4_4_,param_13);
              local_188 = (int *)((ulonglong)local_188 & 0xffffffff00000000);
              iVar8 = FUN_1402230e0(param_5,local_108,local_80,0);
            }
            else {
              iVar4 = FUN_14023ba80(param_6,param_7,
                                    *(undefined4 *)
                                     (&DAT_140ca5bac + (longlong)*(int *)(param_1 + 4) * 4),param_13
                                   );
              while (iVar4 == -1) {
                iVar4 = FUN_1401ad850();
                if (iVar4 != 0) {
                  return 0xffffffff;
                }
                FUN_1401b7120(1);
                iVar4 = FUN_14023ba80(param_6,param_7,
                                      *(undefined4 *)
                                       (&DAT_140ca5bac + (longlong)*(int *)(param_1 + 4) * 4),
                                      param_13);
              }
              local_188._4_4_ = (undefined4)((ulonglong)local_188 >> 0x20);
              local_188 = (int *)CONCAT44(local_188._4_4_,param_13);
              uVar7 = (&DAT_140e0c2b8)[(longlong)iVar4 * 4];
              iVar8 = FUN_140222ed0(uVar7,local_80,0,0x2000);
            }
            if (iVar8 != 0) goto LAB_1402248ea;
            lVar11 = (longlong)(int)((uint)bVar13 * param_7 * param_6);
            FUN_1401ae2f0(local_78,uVar12,lVar11);
            if (local_100 == 0) {
              FUN_1402231b0(param_5,local_108,param_13);
            }
            else {
              FUN_140222fa0(uVar7,param_13);
              FUN_140223040(param_5,local_108,&local_88);
              local_188 = (int *)CONCAT44(local_188._4_4_,param_13);
              FUN_140222ba0(uVar7,0,local_88);
              FUN_140220340(local_88,param_13);
              FUN_14023c5b0(iVar4,param_13);
              iVar4 = -1;
            }
            uVar12 = uVar12 + lVar11;
            iVar8 = param_6 >> 1;
            local_108 = local_108 + 1;
            iVar15 = param_7 >> 1;
            param_6 = 1;
            if (0 < iVar8) {
              param_6 = iVar8;
            }
            param_7 = 1;
            if (0 < iVar15) {
              param_7 = iVar15;
            }
          } while (local_108 < *(int *)(param_1 + 0x48));
        }
      }
      else {
        local_104 = 0;
        do {
          local_108 = 0;
          iVar5 = param_7;
          iVar15 = param_6;
          if (0 < iVar8) {
            do {
              bVar13 = param_8[4];
              if (local_100 == 0) {
                local_178 = CONCAT44(local_178._4_4_,param_13);
                local_180 = (char *)((ulonglong)local_180 & 0xffffffff00000000);
                local_188 = (int *)0x0;
                iVar8 = FUN_1402204c0(local_e8,local_104,local_108,local_80);
              }
              else {
                iVar4 = FUN_14023ba80(iVar15,iVar5,
                                      *(undefined4 *)
                                       (&DAT_140ca5bac + (longlong)*(int *)(param_1 + 4) * 4),
                                      param_13);
                while (iVar4 == -1) {
                  iVar4 = FUN_1401ad850();
                  if (iVar4 != 0) {
                    return 0xffffffff;
                  }
                  FUN_1401b7120(1);
                  iVar4 = FUN_14023ba80(iVar15,iVar5,
                                        *(undefined4 *)
                                         (&DAT_140ca5bac + (longlong)*(int *)(param_1 + 4) * 4),
                                        param_13);
                }
                local_188._4_4_ = (undefined4)((ulonglong)local_188 >> 0x20);
                local_188 = (int *)CONCAT44(local_188._4_4_,param_13);
                uVar7 = (&DAT_140e0c2b8)[(longlong)iVar4 * 4];
                iVar8 = FUN_140222ed0(uVar7,local_80,0,0x2000);
              }
              if (iVar8 != 0) goto LAB_1402248ea;
              lVar11 = (longlong)(int)((uint)bVar13 * iVar5 * iVar15);
              FUN_1401ae2f0(local_78,local_90,lVar11);
              if (local_100 == 0) {
                FUN_1402205c0(local_e8,local_104,local_108,param_13);
              }
              else {
                FUN_140222fa0(uVar7,param_13);
                local_188._0_4_ = param_13;
                FUN_140220400(local_e8,local_104,local_108,&local_88);
                local_188 = (int *)CONCAT44(local_188._4_4_,param_13);
                FUN_140222ba0(uVar7,0,local_88,0);
                FUN_140220340(local_88,param_13);
                FUN_14023c5b0(iVar4,param_13);
                iVar4 = -1;
              }
              local_90 = local_90 + lVar11;
              iVar8 = *(int *)(param_1 + 0x48);
              local_108 = local_108 + 1;
              iVar3 = iVar15 >> 1;
              iVar14 = iVar5 >> 1;
              iVar15 = 1;
              if (0 < iVar3) {
                iVar15 = iVar3;
              }
              iVar5 = 1;
              if (0 < iVar14) {
                iVar5 = iVar14;
              }
              param_8 = local_f0;
            } while (local_108 < iVar8);
          }
          local_104 = local_104 + 1;
        } while (local_104 < 6);
      }
    }
  }
  return 0;
}


