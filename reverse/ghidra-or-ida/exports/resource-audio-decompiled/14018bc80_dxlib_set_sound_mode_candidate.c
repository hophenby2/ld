// Function: dxlib_set_sound_mode_candidate @ 14018bc80
// Decompile completed: true

undefined8 dxlib_set_sound_mode_candidate(uint param_1)

{
  if (param_1 < 4) {
    if (param_1 == 1) {
      param_1 = 0;
    }
    DAT_140845118 = param_1;
    return 0;
  }
  return 0xffffffff;
}


