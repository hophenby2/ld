// Function: FUN_1400ced90 @ 1400ced90
// Decompile completed: true

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1400ced90(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined8 *puVar7;
  longlong lVar8;
  undefined4 *puVar9;
  ulonglong uVar10;
  
  DAT_140e467f0 = FUN_140155c60("media\\system\\TitleBack.png",0);
  if (((((DAT_140e467f0 != -1) &&
        (DAT_140e46ec8 = FUN_140155c60("media\\system\\TitleLogo.png",0), DAT_140e46ec8 != -1)) &&
       (DAT_140e46a24 = FUN_140155c60("media\\player\\DataWindow.png",0), DAT_140e46a24 != -1)) &&
      (((DAT_140e46afc = FUN_140155c60("media\\player\\TimeWindow.png",0), DAT_140e46afc != -1 &&
        (DAT_140e45d8c = FUN_140155c60("media\\stage\\EnemyGauge2.png",0), DAT_140e45d8c != -1)) &&
       ((DAT_140e41b04 = FUN_140155c60("media\\stage\\BossApproach2.png",0), DAT_140e41b04 != -1 &&
        ((DAT_140e46874 = FUN_140155c60("media\\stage\\Stage2Back.png",0), DAT_140e46874 != -1 &&
         (DAT_140e46a0c = FUN_140155c60("media\\stage\\Stage3Back.png",0), DAT_140e46a0c != -1))))))
      )) && ((DAT_140e468c0 = FUN_140155c60("media\\stage\\Stage6Back.png",0), DAT_140e468c0 != -1
             && ((((DAT_140e46a18 = FUN_140155c60("media\\stage\\Stage8Back1.png",0),
                   DAT_140e46a18 != -1 &&
                   (DAT_140e46a3c = FUN_140155c60("media\\stage\\Stage8Back2.png",0),
                   DAT_140e46a3c != -1)) &&
                  (DAT_140e45f6c = FUN_140155c60("media\\gallery\\NoticeFrame.png",0),
                  DAT_140e45f6c != -1)) &&
                 ((DAT_140e46800 = FUN_140155c60("media\\gallery\\GalleryFrame.png",0),
                  DAT_140e46800 != -1 &&
                  (DAT_140e4604c = FUN_140155c60("media\\gallery\\EnemyListWindow.png",0),
                  DAT_140e4604c != -1)))))))) {
    if (DAT_140e467e8 != 0) {
      DAT_140e46ec8 = FUN_140155c60("media\\system\\DemoLogo.png",0);
    }
    if (DAT_140e46ec8 != -1) {
      if (DAT_140e473d8 == 1) {
        DAT_140e46ec8 = FUN_140155c60("media\\system\\BetaLogo.png",0);
      }
      if (((DAT_140e46ec8 != -1) &&
          (DAT_140e473a4 = FUN_140155c60("media\\system\\DemoEnd.png",0), DAT_140e473a4 != -1)) &&
         ((iVar4 = FUN_140155bf0("media\\system\\TitleMenu.png",9,1,9,0x21c,0x3c,&DAT_140e473b0,0,0,
                                 0), iVar4 != -1 &&
          (iVar4 = FUN_140155bf0("media\\system\\Stand.png",0x32,10,5,800,1000,&DAT_140e44240,0,0,0)
          , iVar4 != -1)))) {
        lVar8 = 2;
        iVar4 = FUN_140155bf0("media\\system\\TextBox.png",2,1,2,600,100,&DAT_140e47540,0,0,0);
        if ((((((((iVar4 != -1) &&
                 (iVar4 = FUN_140155bf0("media\\system\\TextIcon.png",0x14,10,2,0x50,0x50,
                                        &DAT_140e474f0,0,0,0), iVar4 != -1)) &&
                (iVar4 = FUN_140155bf0("media\\system\\StageFrame.png",2,2,1,600,0x2d0,
                                       &DAT_140e46910,0,0,0), iVar4 != -1)) &&
               ((iVar4 = FUN_140155bf0("media\\system\\StageFrame2.png",0xf,5,3,0x186,300,
                                       &DAT_140e46880,0,0,0), iVar4 != -1 &&
                (iVar4 = FUN_140155bf0("media\\system\\ConfigMenu.png",0x14,1,0x14,0xf0,0x28,
                                       &DAT_140e47340,0,0,0), iVar4 != -1)))) &&
              (iVar4 = FUN_140155bf0("media\\system\\ConfigMenu2.png",0xf,1,0xf,0xf0,0x28,
                                     &DAT_140e478c8,0,0,0), iVar4 != -1)) &&
             ((((iVar4 = FUN_140155bf0("media\\system\\KeyConfigMenu.png",0x15,1,0x15,0xf0,0x28,
                                       &DAT_140e473e0,0,0,0), iVar4 != -1 &&
                (iVar4 = FUN_140155bf0("media\\system\\ConfigNumber.png",0xb,1,0xb,0x1e,0x28,
                                       &DAT_140e46c30,0,0,0), iVar4 != -1)) &&
               ((iVar4 = FUN_140155bf0("media\\system\\PracticeMenu.png",0x14,1,0x14,0xf0,0x28,
                                       &DAT_140e477f0,0,0,0), iVar4 != -1 &&
                (((iVar4 = FUN_140155bf0("media\\system\\RankingNotice.png",0xe,1,0xe,0x280,0x3c,
                                         &DAT_140e47088,0,0,0), iVar4 != -1 &&
                  (iVar4 = FUN_140155bf0("media\\system\\KerPromotButton.png",0x4b,0xf,5,0x28,0x28,
                                         &DAT_140e470d0,0,0,0), iVar4 != -1)) &&
                 (iVar4 = FUN_140155bf0("media\\system\\KerboardPromot.png",0x6e,10,0xb,0x28,0x28,
                                        &DAT_140e46ed0,0,0,0), iVar4 != -1)))))) &&
              ((((iVar4 = FUN_140155bf0("media\\player\\Player.png",0x78,0xf,8,0x50,0x50,
                                        &DAT_140e44e70,0,0,0), iVar4 != -1 &&
                 (iVar4 = FUN_140155bf0("media\\player\\Item.png",0xf,0xf,1,100,100,&DAT_140e45d38,0
                                        ,0,0), iVar4 != -1)) &&
                ((iVar4 = FUN_140155bf0("media\\player\\PlayerFrame.png",0x1e,10,3,0x154,0x2d0,
                                        &DAT_140e419c0,0,0,0), iVar4 != -1 &&
                 ((iVar4 = FUN_140155bf0("media\\player\\State.png",0x20,1,0x20,200,0x28,
                                         &DAT_140e46b30,0,0,0), iVar4 != -1 &&
                  (iVar4 = FUN_140155bf0("media\\player\\PauseBack.png",10,5,2,600,0x2d0,
                                         &DAT_140e468c8,0,0,0), iVar4 != -1)))))) &&
               (iVar4 = FUN_140155bf0("media\\player\\PauseCount.png",4,4,1,0x140,0x140,
                                      &DAT_140e478b8,0,0,0), iVar4 != -1)))))) &&
            (((iVar4 = FUN_140155bf0("media\\player\\DataWindow2.png",10,10,1,0x3c,0x3c,
                                     &DAT_140e46bc0,0,0,0), iVar4 != -1 &&
              (iVar4 = FUN_140155bf0("media\\effect\\Effect_s.png",0x14,10,2,100,100,&DAT_140e41930,
                                     0,0,0), iVar4 != -1)) &&
             (iVar4 = FUN_140155bf0("media\\effect\\Effect_m.png",0x1e,10,3,200,200,&DAT_140e41a40,0
                                    ,0,0), iVar4 != -1)))) &&
           ((((iVar4 = FUN_140155bf0("media\\effect\\Effect_l.png",0x1e,10,3,600,600,&DAT_140e45060,
                                     0,0,0), iVar4 != -1 &&
              (iVar4 = FUN_140155bf0("media\\system\\Num_s.png",0xe,0xe,1,0x14,0x1e,&DAT_140e41980,0
                                     ,0,0), iVar4 != -1)) &&
             (((((iVar4 = FUN_140155bf0("media\\system\\Num_m.png",10,10,1,0x20,0x30,&DAT_140e47548,
                                        0,0,0), iVar4 != -1 &&
                 ((iVar4 = FUN_140155bf0("media\\system\\Num_l.png",0xe,0xe,1,0x30,0x48,
                                         &DAT_140e46bf8,0,0,0), iVar4 != -1 &&
                  (iVar4 = FUN_140155bf0("media\\player\\DreamGauge.png",2,2,1,0xa0,0xa0,
                                         &DAT_140e473a8,0,0,0), iVar4 != -1)))) &&
                (iVar4 = FUN_140155bf0("media\\stage\\TutorialButton.png",0x10,1,0x10,0xf0,0x50,
                                       &DAT_140e475a0,0,0,0), iVar4 != -1)) &&
               (((((((iVar4 = FUN_140155bf0("media\\stage\\StageBack1.png",10,10,1,0x2d0,0xa00,
                                            &DAT_140e469b0,0,0,0), iVar4 != -1 &&
                     (iVar4 = FUN_140155bf0("media\\stage\\StageBack1b.png",10,10,1,0x2d0,0xa00,
                                            &DAT_140e46ab8,0,0,0), iVar4 != -1)) &&
                    (iVar4 = FUN_140155bf0("media\\stage\\StageBack1c.png",0xc,0xc,1,0x2d0,0xa00,
                                           &DAT_140e469d8,0,0,0), iVar4 != -1)) &&
                   ((iVar4 = FUN_140155bf0("media\\stage\\StageBack1d.png",10,10,1,0x2d0,0xa00,
                                           &DAT_140e45178,0,0,0), iVar4 != -1 &&
                    (iVar4 = FUN_140155bf0("media\\stage\\StageBack2.png",10,10,1,0x2d0,0x2d0,
                                           &DAT_140e450d8,0,0,0), iVar4 != -1)))) &&
                  ((iVar4 = FUN_140155bf0("media\\stage\\Enemy_s.png",0xaa,10,0x11,100,100,
                                          &DAT_140e44660,0,0,0), iVar4 != -1 &&
                   ((iVar4 = FUN_140155bf0("media\\stage\\Enemy_m.png",0xe6,10,0x17,200,200,
                                           &DAT_140e44ad0,0,0,0), iVar4 != -1 &&
                    (iVar4 = FUN_140155bf0("media\\stage\\Enemy_l.png",0x6e,10,0xb,600,600,
                                           &DAT_140e44910,0,0,0), iVar4 != -1)))))) &&
                 (iVar4 = FUN_140155bf0("media\\stage\\Enemy_xl.png",8,4,2,800,800,&DAT_140e46ea8,0,
                                        0,0), iVar4 != -1)) &&
                ((((iVar4 = FUN_140155bf0("media\\stage\\EnemyGauge1.png",3,1,3,0xf6,0x10,
                                          &DAT_140e45d98,0,0,0), iVar4 != -1 &&
                   (iVar4 = FUN_140155bf0("media\\stage\\Boss.png",0xa0,10,0x10,200,200,
                                          &DAT_140e44310,0,0,0), iVar4 != -1)) &&
                  (iVar4 = FUN_140155bf0("media\\stage\\BossGauge.png",10,1,10,500,0x1e,
                                         &DAT_140e44598,0,0,0), iVar4 != -1)) &&
                 (((iVar4 = FUN_140155bf0("media\\stage\\BossName.png",0x16,1,0x16,400,0x1e,
                                          &DAT_140e418d0,0,0,0), iVar4 != -1 &&
                   (iVar4 = FUN_140155bf0("media\\stage\\Bullet.png",0x28,10,4,0x3c,0x3c,
                                          &DAT_140e451c0,0,0,0), iVar4 != -1)) &&
                  ((iVar4 = FUN_140155bf0("media\\system\\Opening.png",0x19,5,5,0x500,0x2d0,
                                          &DAT_140e47480,0,0,0), iVar4 != -1 &&
                   ((iVar4 = FUN_140155bf0("media\\player\\Result.png",0x14,1,0x14,0xf0,0x3c,
                                           &DAT_140e46960,0,0,0), iVar4 != -1 &&
                    (iVar4 = FUN_140155bf0("media\\player\\StageClear.png",5,5,1,0x500,0x2d0,
                                           &DAT_140e47390,0,0,0), iVar4 != -1)))))))))))) &&
              (iVar4 = FUN_140155bf0("media\\system\\Ending.png",0xf,5,3,0x500,0x2d0,&DAT_140e45f70,
                                     0,0,0), iVar4 != -1)))) &&
            ((((iVar4 = FUN_140155bf0("media\\system\\Credit.png",0x42,1,0x42,0x226,0x32,
                                      &DAT_140e476d0,0,0,0), iVar4 != -1 &&
               (iVar4 = FUN_140155bf0("media\\gallery\\NoticeText1.png",2,1,2,0x8c,0x28,
                                      &DAT_140e45da8,0,0,0), iVar4 != -1)) &&
              (iVar4 = FUN_140155bf0("media\\gallery\\Achievement.png",5,5,1,100,100,&DAT_140e46050,
                                     0,0,0), iVar4 != -1)) &&
             (iVar4 = FUN_140155bf0("media\\gallery\\EnemyList.png",0x1a0,4,0x68,0x140,0x28,
                                    &DAT_140e46070,0,0,0), iVar4 != -1)))))) {
          puVar9 = &DAT_140e45db0;
          iVar4 = FUN_140155bf0("media\\gallery\\EnemyListPic.png",0x6e,10,0xb,600,600,
                                &DAT_140e45db0,0,0,0);
          if (iVar4 != -1) {
            DAT_140e470cc = FUN_140155cc0(0x500,0x2d0,0);
            _DAT_140e45100 = _DAT_14053b630;
            _DAT_140e45108 = _UNK_14053b638;
            _DAT_140e45110 = _DAT_14053b630;
            _DAT_140e45118 = _UNK_14053b638;
            _DAT_140e45120 = _DAT_14053b630;
            _DAT_140e45128 = _UNK_14053b638;
            _DAT_140e45130 = _DAT_14053b630;
            _DAT_140e45138 = _UNK_14053b638;
            _DAT_140e45140 = _DAT_14053b630;
            _DAT_140e45148 = _UNK_14053b638;
            _DAT_140e45150 = _DAT_14053b630;
            _DAT_140e45158 = _UNK_14053b638;
            _DAT_140e45160 = _DAT_14053b630;
            uRam0000000140e45168 = _UNK_14053b638;
            _DAT_140e45170 = _DAT_14053b630;
            FUN_14018bc80(3);
            _DAT_140e45100 = CONCAT44(DAT_140e45104,1);
            uVar5 = FUN_1401885b0("media\\bgm\\Opening.ogg",3,0xffffffff);
            _DAT_140e45100 = CONCAT44(uVar5,DAT_140e45100);
            uVar5 = FUN_1401885b0("media\\bgm\\Title.ogg",3,0xffffffff);
            _DAT_140e45108 = CONCAT44(DAT_140e4510c,uVar5);
            uVar5 = FUN_1401885b0("media\\bgm\\Tutorial.ogg",3,0xffffffff);
            _DAT_140e45108 = CONCAT44(uVar5,DAT_140e45108);
            uVar5 = FUN_1401885b0("media\\bgm\\Gameover.ogg",3,0xffffffff);
            _DAT_140e45110 = CONCAT44(_DAT_140e45114,uVar5);
            uVar5 = FUN_1401885b0("media\\bgm\\Stage1.ogg",3,0xffffffff);
            _DAT_140e45110 = CONCAT44(uVar5,DAT_140e45110);
            uVar5 = FUN_1401885b0("media\\bgm\\Stage2.ogg",3,0xffffffff);
            _DAT_140e45118 = CONCAT44(_DAT_140e4511c,uVar5);
            uVar5 = FUN_1401885b0("media\\bgm\\Stage3.ogg",3,0xffffffff);
            _DAT_140e45118 = CONCAT44(uVar5,_DAT_140e45118);
            uVar5 = FUN_1401885b0("media\\bgm\\Stage4.ogg",3,0xffffffff);
            _DAT_140e45120 = CONCAT44(_DAT_140e45124,uVar5);
            uVar5 = FUN_1401885b0("media\\bgm\\Stage5.ogg",3,0xffffffff);
            _DAT_140e45120 = CONCAT44(uVar5,_DAT_140e45120);
            uVar5 = FUN_1401885b0("media\\bgm\\Stage6.ogg",3,0xffffffff);
            _DAT_140e45128 = CONCAT44(_DAT_140e4512c,uVar5);
            uVar5 = FUN_1401885b0("media\\bgm\\Stage7.ogg",3,0xffffffff);
            _DAT_140e45128 = CONCAT44(uVar5,_DAT_140e45128);
            uVar5 = FUN_1401885b0("media\\bgm\\Stage8.ogg",3,0xffffffff);
            _DAT_140e45130 = CONCAT44(_DAT_140e45134,uVar5);
            uVar5 = FUN_1401885b0("media\\bgm\\Stage9.ogg",3,0xffffffff);
            _DAT_140e45130 = CONCAT44(uVar5,_DAT_140e45130);
            uVar5 = FUN_1401885b0("media\\bgm\\Stage10.ogg",3,0xffffffff);
            _DAT_140e45138 = CONCAT44(DAT_140e4513c,uVar5);
            uVar5 = FUN_1401885b0("media\\bgm\\Boss1.ogg",3,0xffffffff);
            _DAT_140e45138 = CONCAT44(uVar5,DAT_140e45138);
            uVar5 = FUN_1401885b0("media\\bgm\\Boss2.ogg",3,0xffffffff);
            _DAT_140e45140 = CONCAT44(DAT_140e45144,uVar5);
            uVar5 = FUN_1401885b0("media\\bgm\\Boss3.ogg",3,0xffffffff);
            _DAT_140e45140 = CONCAT44(uVar5,DAT_140e45140);
            uVar5 = FUN_1401885b0("media\\bgm\\Boss4.ogg",3,0xffffffff);
            _DAT_140e45148 = CONCAT44(DAT_140e4514c,uVar5);
            uVar5 = FUN_1401885b0("media\\bgm\\Boss5.ogg",3,0xffffffff);
            _DAT_140e45148 = CONCAT44(uVar5,DAT_140e45148);
            uVar5 = FUN_1401885b0("media\\bgm\\StageClear.ogg",3,0xffffffff);
            _DAT_140e45158 = CONCAT44(DAT_140e4515c,uVar5);
            uVar5 = FUN_1401885b0("media\\bgm\\Ending.ogg",3,0xffffffff);
            _DAT_140e45158 = CONCAT44(uVar5,DAT_140e45158);
            uVar5 = FUN_1401885b0("media\\bgm\\Unlock.ogg",3,0xffffffff);
            uVar2 = _UNK_14053b638;
            uVar1 = _DAT_14053b630;
            _DAT_140e45160 = CONCAT44(DAT_140e45160_4,uVar5);
            piVar6 = &DAT_140e45100;
            do {
              if (*piVar6 == -1) {
                return 0xffffffff;
              }
              piVar6 = piVar6 + 1;
            } while ((longlong)piVar6 < 0x140e45178);
            piVar6 = &DAT_140e47200;
            puVar3 = (undefined8 *)&DAT_140e47200;
            do {
              puVar7 = puVar3;
              *puVar7 = uVar1;
              puVar7[1] = uVar2;
              puVar7[2] = uVar1;
              puVar7[3] = uVar2;
              puVar7[4] = uVar1;
              puVar7[5] = uVar2;
              puVar7[6] = uVar1;
              puVar7[7] = uVar2;
              puVar7[8] = uVar1;
              puVar7[9] = uVar2;
              puVar7[10] = uVar1;
              puVar7[0xb] = uVar2;
              puVar7[0xc] = uVar1;
              puVar7[0xd] = uVar2;
              puVar7[0xe] = uVar1;
              puVar7[0xf] = uVar2;
              lVar8 = lVar8 + -1;
              puVar3 = puVar7 + 0x10;
            } while (lVar8 != 0);
            puVar7[0x10] = uVar1;
            puVar7[0x11] = uVar2;
            puVar7[0x12] = uVar1;
            puVar7[0x13] = uVar2;
            puVar7[0x14] = uVar1;
            puVar7[0x15] = uVar2;
            puVar7[0x16] = uVar1;
            puVar7[0x17] = uVar2;
            FUN_14018bc80(0);
            DAT_140e47200 = FUN_1401885b0("media\\se\\Select.mp3",3,0xffffffff);
            DAT_140e47204 = FUN_1401885b0("media\\se\\Enter.wav",3,0xffffffff);
            DAT_140e47208 = FUN_1401885b0("media\\se\\Cancel.wav",3,0xffffffff);
            DAT_140e4720c = FUN_1401885b0("media\\se\\Error.wav",3,0xffffffff);
            DAT_140e47210 = FUN_1401885b0("media\\se\\Switch.wav",3,0xffffffff);
            _DAT_140e47214 = FUN_1401885b0("media\\se\\Text.wav",3,0xffffffff);
            _DAT_140e47218 = FUN_1401885b0("media\\se\\Text2.wav",3,0xffffffff);
            DAT_140e4721c = FUN_1401885b0("media\\se\\Pose.wav",3,0xffffffff);
            DAT_140e47220 = FUN_1401885b0("media\\se\\Miss.wav",3,0xffffffff);
            DAT_140e47224 = FUN_1401885b0("media\\se\\Miss2.wav",3,0xffffffff);
            DAT_140e47228 = FUN_1401885b0("media\\se\\Extend.wav",3,0xffffffff);
            DAT_140e4722c = FUN_1401885b0("media\\se\\Shot1.wav",3,0xffffffff);
            _DAT_140e47230 = FUN_1401885b0("media\\se\\Shot2.wav",3,0xffffffff);
            _DAT_140e47234 = FUN_1401885b0("media\\se\\BossSE2.wav",3,0xffffffff);
            _DAT_140e47238 = FUN_1401885b0("media\\se\\Shot4.wav",3,0xffffffff);
            _DAT_140e4723c = FUN_1401885b0("media\\se\\Shot5.wav",3,0xffffffff);
            DAT_140e47240 = FUN_1401885b0("media\\se\\BossSE4.wav",3,0xffffffff);
            DAT_140e47244 = FUN_1401885b0("media\\se\\Shothit.wav",3,0xffffffff);
            DAT_140e47248 = FUN_1401885b0("media\\se\\Shothit2.wav",3,0xffffffff);
            DAT_140e4724c = FUN_1401885b0("media\\se\\Bomb1.wav",3,0xffffffff);
            DAT_140e47250 = FUN_1401885b0("media\\se\\Bomb2.wav",3,0xffffffff);
            DAT_140e47254 = FUN_1401885b0("media\\se\\Bomb3.wav",3,0xffffffff);
            DAT_140e47258 = FUN_1401885b0("media\\se\\Bomb4.wav",3,0xffffffff);
            DAT_140e4725c = FUN_1401885b0("media\\se\\Bomb5.wav",3,0xffffffff);
            DAT_140e47260 = FUN_1401885b0("media\\se\\Bomb6.wav",3,0xffffffff);
            DAT_140e47264 = FUN_1401885b0("media\\se\\Bomb7.wav",3,0xffffffff);
            DAT_140e47268 = FUN_1401885b0("media\\se\\Bomb8.wav",3,0xffffffff);
            DAT_140e4726c = FUN_1401885b0("media\\se\\Item1.wav",3,0xffffffff);
            DAT_140e47270 = FUN_1401885b0("media\\se\\Item2.wav",3,0xffffffff);
            DAT_140e47274 = FUN_1401885b0("media\\se\\Item3.wav",3,0xffffffff);
            DAT_140e4727c = FUN_1401885b0("media\\se\\Guard.wav",3,0xffffffff);
            DAT_140e47278 = FUN_1401885b0("media\\se\\DreamPower.wav",3,0xffffffff);
            DAT_140e47280 = FUN_1401885b0("media\\se\\Fever1.wav",3,0xffffffff);
            DAT_140e47284 = FUN_1401885b0("media\\se\\Fever2.mp3",3,0xffffffff);
            DAT_140e47288 = FUN_1401885b0("media\\se\\Fever3.wav",3,0xffffffff);
            DAT_140e4728c = FUN_1401885b0("media\\se\\Fever4.wav",3,0xffffffff);
            DAT_140e47290 = FUN_1401885b0("media\\se\\EnemyDown1.wav",3,0xffffffff);
            DAT_140e47294 = FUN_1401885b0("media\\se\\EnemyDown2.wav",3,0xffffffff);
            DAT_140e47298 = FUN_1401885b0("media\\se\\EnemyDown3.wav",3,0xffffffff);
            DAT_140e4729c = FUN_1401885b0("media\\se\\Blast1.wav",3,0xffffffff);
            DAT_140e472a0 = FUN_1401885b0("media\\se\\Blast2.wav",3,0xffffffff);
            DAT_140e472a4 = FUN_1401885b0("media\\se\\Bullet1.wav",3,0xffffffff);
            DAT_140e472a8 = FUN_1401885b0("media\\se\\Bullet2.wav",3,0xffffffff);
            DAT_140e472ac = FUN_1401885b0("media\\se\\Graze.wav",3,0xffffffff);
            DAT_140e472b0 = FUN_1401885b0("media\\se\\Alert.wav",3,0xffffffff);
            DAT_140e472b4 = FUN_1401885b0("media\\se\\BossLife.wav",3,0xffffffff);
            DAT_140e472b8 = FUN_1401885b0("media\\se\\BossApproach.wav",3,0xffffffff);
            DAT_140e472bc = FUN_1401885b0("media\\se\\BossSE1.wav",3,0xffffffff);
            DAT_140e472c0 = FUN_1401885b0("media\\se\\BossSE2.wav",3,0xffffffff);
            DAT_140e472c4 = FUN_1401885b0("media\\se\\BossSE3.wav",3,0xffffffff);
            DAT_140e472c8 = FUN_1401885b0("media\\se\\BossSE4.wav",3,0xffffffff);
            DAT_140e472cc = FUN_1401885b0("media\\se\\BossSE5.wav",3,0xffffffff);
            DAT_140e472d0 = FUN_1401885b0("media\\se\\BossSE6.wav",3,0xffffffff);
            DAT_140e472d4 = FUN_1401885b0("media\\se\\BossSE7.wav",3,0xffffffff);
            DAT_140e472d8 = FUN_1401885b0("media\\se\\BossSE8.wav",3,0xffffffff);
            DAT_140e472dc = FUN_1401885b0("media\\se\\BossSE9.wav",3,0xffffffff);
            _DAT_140e472e0 = FUN_1401885b0("media\\se\\BossSE10.wav",3,0xffffffff);
            _DAT_140e472e4 = FUN_1401885b0("media\\se\\BossSE11.wav",3,0xffffffff);
            DAT_140e472e8 = FUN_1401885b0("media\\se\\BossSE12.wav",3,0xffffffff);
            DAT_140e472ec = FUN_1401885b0("media\\se\\BossSE13.wav",3,0xffffffff);
            DAT_140e472f0 = FUN_1401885b0("media\\se\\BossSE14.wav",3,0xffffffff);
            DAT_140e472f4 = FUN_1401885b0("media\\se\\BossSE15.wav",3,0xffffffff);
            DAT_140e472f8 = FUN_1401885b0("media\\se\\BossSE16.wav",3,0xffffffff);
            DAT_140e472fc = FUN_1401885b0("media\\se\\BossSE17.wav",3,0xffffffff);
            DAT_140e47300 = FUN_1401885b0("media\\se\\BossSE18.wav",3,0xffffffff);
            DAT_140e47304 = FUN_1401885b0("media\\se\\BossSE19.wav",3,0xffffffff);
            DAT_140e47308 = FUN_1401885b0("media\\se\\BossSE20.wav",3,0xffffffff);
            DAT_140e4730c = FUN_1401885b0("media\\se\\BossWeaken.wav",3,0xffffffff);
            DAT_140e47310 = FUN_1401885b0("media\\se\\Timer.wav",3,0xffffffff);
            DAT_140e47314 = FUN_1401885b0("media\\se\\Bonus.wav",3,0xffffffff);
            DAT_140e47318 = FUN_1401885b0("media\\se\\Notice.wav",3,0xffffffff);
            DAT_140e4731c = FUN_1401885b0("media\\se\\Opening1.wav",3,0xffffffff);
            DAT_140e47320 = FUN_1401885b0("media\\se\\Opening2.wav",3,0xffffffff);
            while (*piVar6 != -1) {
              piVar6 = piVar6 + 1;
              if (0x140e4733f < (longlong)piVar6) {
                uVar10 = (ulonglong)puVar9 & 0xffffffff00000000;
                DAT_140e470c0 = "Nyashi.ttf";
                DAT_140e47640 = &DAT_140538128;
                DAT_140e46c74 =
                     FUN_14015a5f0(&DAT_140538128,0x14,9,0x13,0,0xffffffff,uVar10,0xffffffff);
                DAT_140e46c78 =
                     FUN_14015a5f0(DAT_140e47640,0x18,9,0x13,0,0xffffffff,
                                   uVar10 & 0xffffffff00000000,0xffffffff);
                iVar4 = FUN_1400d0e50();
                if (iVar4 == -1) {
                  return 0xffffffff;
                }
                return 1;
              }
            }
          }
        }
      }
    }
  }
  return 0xffffffff;
}


