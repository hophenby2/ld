// Function: stage_entity_flush_effects_candidate @ 140079b00
// Decompile completed: true

void stage_entity_flush_effects_candidate(void)

{
  longlong lVar1;
  longlong lVar2;
  double dVar3;
  double dVar4;
  
  dVar3 = DAT_140539e38;
  lVar2 = DAT_140e45d80;
  while (lVar2 != 0) {
    dVar4 = (double)*(int *)(lVar2 + 0x50) * dVar3;
    FUN_140070d00(0xc,DAT_140e41a50,0x3d,*(undefined4 *)(lVar2 + 0x28),*(undefined4 *)(lVar2 + 0x2c)
                  ,0,0,dVar4,dVar4,0x10,0xff,0xff,0xff,0xff,0);
    lVar1 = *(longlong *)(lVar2 + 0x60);
    FUN_140323ce8(lVar2);
    lVar2 = lVar1;
  }
  DAT_140e45d80 = 0;
  DAT_140e45d90 = 0;
  DAT_140e44e6c = 0;
  return;
}


