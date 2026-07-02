// Function: FUN_140135430 @ 140135430
// Decompile completed: true

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140135430(int param_1)

{
  undefined4 *puVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  longlong lVar5;
  undefined8 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  longlong lVar9;
  undefined1 auStack_58 [32];
  FILE *local_38;
  ulonglong local_30;
  
  local_30 = DAT_1407c6b00 ^ (ulonglong)auStack_58;
  if (param_1 == 1) {
    DAT_140e41b6c = 0xe;
    _DAT_140e41b1c = 0x100000001;
    DAT_140e41b68 = DAT_140e467e8;
    if (DAT_140e467e8 == 0) {
      DAT_140e41b68 = 9;
    }
    DAT_140e43ea8 = 4;
    DAT_140e41b94 = 1;
    DAT_140e43eac = 4;
    DAT_140e41dec = 1;
    DAT_140e43eb0 = 4;
    _DAT_140e42044 = 1;
    _DAT_140e43eb4 = 4;
    _DAT_140e4229c = 1;
    _DAT_140e43eb8 = 4;
    _DAT_140e424f4 = 1;
    _DAT_140e43ebc = 4;
    DAT_140e4274c = 1;
    _DAT_140e43ec0 = 4;
    _DAT_140e429a4 = 1;
    _DAT_140e43ec4 = 4;
    _DAT_140e42bfc = 1;
    DAT_140e43ec8 = 4;
    _DAT_140e42e54 = 1;
    DAT_140e43ecc = 4;
    _DAT_140e430ac = 1;
    _DAT_140e43ed0 = 4;
    _DAT_140e43304 = 1;
    DAT_140e43ed4 = 4;
    _DAT_140e4355c = 1;
    _DAT_140e43ed8 = 4;
    DAT_140e437b4 = 1;
    _DAT_140e43edc = 4;
    DAT_140e43a0c = 1;
    _DAT_140e43ee0 = 4;
    _DAT_140e43c64 = 1;
    DAT_140e441bc = 1;
    DAT_140e441c0 = 1;
    _DAT_140e441c4 = 1;
    _DAT_140e441c8 = 1;
    DAT_140e43f18 = 1;
    _DAT_140e41b74 = 0x100000001;
    uRam0000000140e4409c = _UNK_14053b638;
    DAT_140e440a4 = _DAT_14053b630;
  }
  else {
    lVar5 = 0;
    DAT_140e41b64 = 0;
    _DAT_140e41b1c = 0;
    _DAT_140e41b74 = 0;
    DAT_140e43f18 = 0;
    DAT_140e41b18 = 0;
    _DAT_140e43f00 = 0;
    DAT_140e41b58 = 1;
    _DAT_140e41b5c = 0xb;
    DAT_140e41b68 = 1;
    DAT_140e41b6c = 0xb;
    DAT_140e44198 = 6;
    do {
      puVar8 = &DAT_140e43ea8;
      puVar4 = (undefined8 *)((longlong)&DAT_140e41bd8 + lVar5);
      puVar6 = puVar4;
      lVar9 = lVar5;
      do {
        *puVar8 = 2;
        puVar1 = (undefined4 *)((longlong)&DAT_140e41b94 + lVar9);
        lVar2 = 5;
        puVar3 = puVar4;
        puVar7 = (undefined4 *)((longlong)puVar6 + 0x4c);
        do {
          puVar1[-5] = 0;
          *puVar1 = 0;
          puVar1[5] = 0;
          puVar1[10] = 0;
          puVar1 = puVar1 + 1;
          puVar3[-1] = 0;
          *puVar3 = 0;
          puVar7[-1] = 0x57030;
          *puVar7 = 0x57030;
          lVar2 = lVar2 + -1;
          puVar3 = puVar3 + 2;
          puVar7 = puVar7 + 2;
        } while (lVar2 != 0);
        puVar8 = puVar8 + 1;
        lVar9 = lVar9 + 600;
        puVar4 = puVar4 + 0x4b;
        puVar6 = puVar6 + 0x4b;
      } while ((longlong)puVar8 < 0x140e43ee4);
      lVar5 = lVar5 + 200;
    } while (lVar5 < 600);
    DAT_140e43ee8 = 0;
    DAT_140e43ef0 = 0;
    _DAT_140e43f80 = 0;
    _DAT_140e43f88 = 0;
    _DAT_140e43f90 = 0;
    _DAT_140e43f98 = 0;
    _DAT_140e43fa0 = 0;
    _DAT_140e43fa8 = 0;
    _DAT_140e43fb0 = 0;
    _DAT_140e43fb8 = 0;
    _DAT_140e43fc0 = 0;
    uRam0000000140e43fc8 = 0;
    uRam0000000140e4409c = 0;
    _DAT_140e440ac = 0;
    uRam0000000140e440b4 = 0;
    _DAT_140e440bc = 0;
    uRam0000000140e440c4 = 0;
    _DAT_140e440cc = 0;
    uRam0000000140e440d4 = 0;
    _DAT_140e440dc = 0;
    uRam0000000140e440e4 = 0;
    _DAT_140e440ec = 0;
    uRam0000000140e440f4 = 0;
    _DAT_140e440fc = 0;
    uRam0000000140e44104 = 0;
    _DAT_140e4410c = 0;
    uRam0000000140e44114 = 0;
    _DAT_140e4411c = 0;
    uRam0000000140e44124 = 0;
    _DAT_140e4412c = 0;
    uRam0000000140e44134 = 0;
    _DAT_140e4413c = 0;
    uRam0000000140e44144 = 0;
    _DAT_140e4414c = 0;
    uRam0000000140e44154 = 0;
    _DAT_140e4415c = 0;
    uRam0000000140e44164 = 0;
    _DAT_140e44174 = 0;
    _DAT_140e4417c = 0;
    _DAT_140e44184 = 0;
    DAT_140e441bc = 0;
    DAT_140e440a4 = 0;
    DAT_140e4416c = 0;
  }
  _DAT_140e43f1c = DAT_140e440a4;
  _DAT_140e43f24 = uRam0000000140e4409c;
  _DAT_140e43f2c = DAT_140e440a4;
  _DAT_140e43f34 = uRam0000000140e4409c;
  _DAT_140e43f3c = DAT_140e440a4;
  _DAT_140e43f44 = uRam0000000140e4409c;
  _DAT_140e43f4c = DAT_140e440a4;
  _DAT_140e43f54 = uRam0000000140e4409c;
  _DAT_140e43f5c = DAT_140e440a4;
  _DAT_140e43f64 = uRam0000000140e4409c;
  _DAT_140e43fe4 = DAT_140e440a4;
  _DAT_140e43fec = uRam0000000140e4409c;
  _DAT_140e43ff4 = DAT_140e440a4;
  uRam0000000140e43ffc = uRam0000000140e4409c;
  _DAT_140e44004 = DAT_140e440a4;
  uRam0000000140e4400c = uRam0000000140e4409c;
  _DAT_140e44014 = DAT_140e440a4;
  uRam0000000140e4401c = uRam0000000140e4409c;
  _DAT_140e44024 = DAT_140e440a4;
  uRam0000000140e4402c = uRam0000000140e4409c;
  _DAT_140e44034 = DAT_140e440a4;
  _DAT_140e4403c = uRam0000000140e4409c;
  _DAT_140e44044 = DAT_140e440a4;
  _DAT_140e4404c = uRam0000000140e4409c;
  _DAT_140e44054 = DAT_140e440a4;
  uRam0000000140e4405c = uRam0000000140e4409c;
  _DAT_140e44064 = DAT_140e440a4;
  uRam0000000140e4406c = uRam0000000140e4409c;
  _DAT_140e44074 = DAT_140e440a4;
  uRam0000000140e4407c = uRam0000000140e4409c;
  _DAT_140e44084 = DAT_140e440a4;
  uRam0000000140e4408c = uRam0000000140e4409c;
  _DAT_140e44094 = DAT_140e440a4;
  fopen_s(&local_38,"save\\save.dat","wb");
  FUN_140327c78(&DAT_140e41b10,0x2730,1,local_38);
  FUN_140323e90(local_38);
  DAT_140e471fc = 0xb4;
  return;
}


