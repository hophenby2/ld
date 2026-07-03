// Function: fopen_s @ 1403278b0
// Decompile completed: true

/* Library Function - Single Match
    fopen_s
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

errno_t __cdecl fopen_s(FILE **_File,char *_Filename,char *_Mode)

{
  ulong *puVar1;
  _iobuf *p_Var2;
  ulong uVar3;
  
  uVar3 = 0;
  if (_File == (FILE **)0x0) {
    puVar1 = __doserrno();
    uVar3 = 0x16;
    *puVar1 = 0x16;
    FUN_140339f94();
  }
  else {
    p_Var2 = common_fsopen<char>(_Filename,_Mode,0x80);
    *_File = p_Var2;
    if (p_Var2 == (_iobuf *)0x0) {
      puVar1 = __doserrno();
      uVar3 = *puVar1;
    }
  }
  return uVar3;
}


