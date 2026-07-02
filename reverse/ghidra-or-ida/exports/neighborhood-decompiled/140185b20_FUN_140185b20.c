// Function: FUN_140185b20 @ 140185b20
// Decompile completed: true

undefined8 FUN_140185b20(uint param_1,uint param_2)

{
  int *piVar1;
  int *piVar2;
  
  if ((((DAT_140988920 != 0) && (-1 < (int)param_1)) && ((param_1 & 0x7c000000) == DAT_140988970))
     && ((int)(param_1 & 0x3ffff) < DAT_140988978)) {
    piVar1 = *(int **)(DAT_140988928 + (ulonglong)(param_1 & 0x3ffff) * 8);
    if ((((piVar1 != (int *)0x0) && (*piVar1 << 0x12 == (param_1 & 0x3fc0000))) &&
        ((piVar1[0x20] != 1 && ((-1 < (int)param_2 && ((param_2 & 0x7c000000) == DAT_140988970))))))
       && (((int)(param_2 & 0x3ffff) < DAT_140988978 &&
           (((((piVar2 = *(int **)(DAT_140988928 + (ulonglong)(param_2 & 0x3ffff) * 8),
               piVar2 != (int *)0x0 && (*piVar2 << 0x12 == (param_2 & 0x3fc0000))) &&
              (piVar2[0x20] != 1)) &&
             ((*(longlong *)(piVar1 + 0x26) == *(longlong *)(piVar2 + 0x26) &&
              (*(short *)((longlong)piVar1 + 0x86) == *(short *)((longlong)piVar2 + 0x86))))) &&
            ((*(short *)((longlong)piVar1 + 0x92) == *(short *)((longlong)piVar2 + 0x92) &&
             ((short)piVar1[0x21] == (short)piVar2[0x21])))))))) {
      FUN_1401ae2f0(*(undefined8 *)(piVar2 + 0x28),*(undefined8 *)(piVar1 + 0x28),
                    (ulonglong)*(ushort *)(piVar1 + 0x24) * *(longlong *)(piVar1 + 0x26));
      return 0;
    }
  }
  return 0xffffffff;
}


