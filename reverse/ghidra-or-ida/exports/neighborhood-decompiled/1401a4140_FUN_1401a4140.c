// Function: FUN_1401a4140 @ 1401a4140
// Decompile completed: true

void FUN_1401a4140(void)

{
  uint uVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  
  if ((DAT_140c2b470 == 0) && (FUN_1401e6080(), DAT_140c2c018 != (code *)0x0)) {
    (*DAT_140c2c018)(1);
  }
  if (DAT_1408aadf8 == 0) {
    DAT_1408aadf8 = 1;
    puVar4 = &DAT_14089ae00;
    do {
      uVar2 = (*DAT_140c2b650)(0,1,0);
      *puVar4 = uVar2;
      puVar4 = puVar4 + 2;
    } while ((longlong)puVar4 < 0x1408aae00);
    FUN_1401b6d40(&DAT_1408aae00);
  }
  uVar1 = (*DAT_140c2b698)();
  do {
    FUN_1401b6dc0(&DAT_1408aae00,"..\\..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxWindow.cpp",
                  0x68a);
    uVar2 = DAT_14089ae00;
    if (DAT_14089adec == 0) {
      if ((DAT_1408aadfc == 0) || (DAT_14089adf0 == uVar1)) goto LAB_1401a4301;
      if (DAT_14089adf8 == uVar1) {
        if (DAT_1408aadfc != 1) {
          FUN_1401ae2f0(&DAT_14089adf8,&DAT_14089ae08,(longlong)(DAT_1408aadfc + -1) << 4);
          (&DAT_14089ae00)[(longlong)(DAT_1408aadfc + -1) * 2] = uVar2;
          (&DAT_14089adf8)[(longlong)(DAT_1408aadfc + -1) * 2] = 0;
        }
        DAT_1408aadfc = DAT_1408aadfc + -1;
LAB_1401a4301:
        DAT_14089ade8 = DAT_14089ade8 + 1;
        DAT_14089adec = 1;
        DAT_14089adf0 = uVar1;
        FUN_1401b6e70(&DAT_1408aae00);
        return;
      }
    }
    else if (DAT_14089adf0 == uVar1) goto LAB_1401a4301;
    if (DAT_1408aadfc == 0x1000) {
      FUN_1401b6e70(&DAT_1408aae00);
      (*DAT_140c2b848)(1);
    }
    else {
      (&DAT_14089adf8)[(longlong)DAT_1408aadfc * 2] = (ulonglong)uVar1;
      lVar3 = (longlong)DAT_1408aadfc;
      DAT_1408aadfc = DAT_1408aadfc + 1;
      uVar2 = (&DAT_14089ae00)[lVar3 * 2];
      FUN_1401b6e70(&DAT_1408aae00);
      (*DAT_140c2b6b0)(uVar2,0xffffffff);
      (*DAT_140c2b660)(uVar2);
    }
  } while( true );
}


