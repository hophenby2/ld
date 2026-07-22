# Stage 1-4 敌人运动与发弹逻辑伪代码

本文总结重建工程中 Stage 1、2、3、4 实际能由关卡脚本或敌人辅助函数创建的全部敌人实体。重点是实体状态机、运动、发弹、部件联动和退出条件；敌弹生成后的运动见 `projectile-pseudocode.md`。这里的“中 Boss”也包括会锁住关卡时间线、具有长死亡演出的关卡内大型控制器。

## 记号

```text
D := 难度索引，0..4
DIFF[a,b,c,d,e] := 按 D 取表项
t := 当前实体 helperTimer；切换状态时通常清零
T := 父实体或 Boss 根的 helperTimer
F := 全局关卡帧 frame
AIM(x,y) := 从 (x,y) 指向自机的 16 位角
TURN(a,target,step) := 沿最短圆周方向、每帧最多 step 地转向
MOVE(a,speed) := (x,y) += (cos(a),sin(a))*speed
SHOT(v,b,pos,a,speed) := 创建外观 v、运动行为 b 的单颗敌弹
FAN(v,b,pos,a,speed,count,spread) := 以 a 为中心创建 count 发、总张角 spread 的扇形
RING(...) := FAN(..., spread=0x10000)
RAND(seed) := 原版脚本使用的确定性伪随机值
INSIDE(m) := 随自机横向偏移的 600x720 游戏区，四边外扩 m
```

角度 `0x0000/0x4000/0x8000/0xc000` 分别表示右、下、左、上。`v` 只选敌弹图像，`b` 才决定敌弹运动；例如 `SHOT(3,7,...)` 是“外观 3、运动 7”，不能合并成一种弹型。

除非另有说明，普通敌人 HP 归零会生成该类型的奖励/爆炸并停用；越过自身的外扩矩形则静默停用。难度 0 的创建 HP 通常另乘 `0.8`，不影响下面的状态逻辑。统一实体分派与更新顺序见 [`updateEnemies`](../src/stage_runtime.cpp#L4772)，难度常量表见 [`stage_runtime.cpp:76`](../src/stage_runtime.cpp#L76)。

## 完整类型覆盖表

| Stage | 分类 | 根/普通类型 | 子节点、临时实体 |
|---|---|---|---|
| 1 | 普通/复用敌人 | `0x06,0x08,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f` | `0x09`（`0x06` 的 Help 卫星，配置相关） |
| 1 | 关卡内大型控制器 | `0x10` | `0x11`（可破坏炮台），`0x153`（延迟转交伤害） |
| 1 | 关底 Boss | `0x138` | `0x12,0x13,0x14`（纯装饰），`0x15,0x16,0x17`（可破坏部件），`0x153` |
| 2 | 复用敌人 | `0x07,0x08,0x0a,0x0b,0x0d` | `0x09`（配置相关） |
| 2 | 专属普通敌人 | `0x19,0x1a,0x1b,0x1c,0x1d,0x1e` | 无 |
| 2 | 关卡内大型控制器 | `0x1f,0x20` | `0x21`（`0x20` 的五个炮台） |
| 2 | 关底 Boss | `0x139` | `0x22,0x23,0x24` |
| 3 | 复用敌人 | `0x07,0x08,0x0b` | `0x09`（配置相关） |
| 3 | 专属普通敌人 | `0x25,0x26,0x27,0x29,0x2c,0x2d` | `0x28`（`0x27` 卫星），`0x2a`（`0x29` 卫星） |
| 3 | 关卡内大型控制器 | `0x2b,0x2e` | `0x2f`（`0x2e` 共享 HP 部件） |
| 3 | 关底 Boss | `0x13a` | `0x30,0x31,0x32,0x33,0x34`，`0x153` |
| 4 | 复用敌人 | `0x07,0x08,0x0b` | `0x09`（配置相关） |
| 4 | 专属普通敌人 | `0x35,0x36,0x37,0x38,0x39,0x3a,0x3d` | `0x3b,0x3c`（运输体共享 HP 子体），`0x3e`（`0x3d` 炮台） |
| 4 | 关卡内大型控制器 | `0x3f` | 无 |
| 4 | 关底 Boss | `0x13b` | `0x40,0x41,0x42,0x43`，`0x153` |
| 1-4 | 公共死亡后实体 | 无 | `0x137`（Counter 模式死亡位置发射器） |
| 1、3、4 | 公共部件伤害实体 | 无 | `0x153`（30 帧延迟伤害转交） |

覆盖范围来自创建分支 [`spawnEnemy`](../src/stage_runtime.cpp#L3058)、子节点创建器 [`stage_runtime.cpp:3590`](../src/stage_runtime.cpp#L3590) 以及四关调度器 [`stage_runtime.cpp:1977`](../src/stage_runtime.cpp#L1977)。未列出 `0x18`：它是玩家侧清弹/反馈对象，不是敌人。

## 多关卡复用敌人

Stage 2-4 会复用早期关卡的若干辅助函数。其行为按“出生所在关卡”选择部分发弹表：

```text
0x06/0x07/0x08: Stage 1-4 使用同一根状态机；实际脚本分别选择其中部分类型
0x0a: Stage 1/2 使用 stage<=7 表
0x0b: Stage 1-3 使用早期表；Stage 4 使用 stage>3 表
0x0d: Stage 1/2 使用早期表
```

因此下文只完整定义一次，再在各 Stage 覆盖清单中指出复用关系。

## Stage 1

关卡调度见 [`spawnStage01OriginalSchedule`](../src/stage_runtime.cpp#L1977)，类型更新入口见 [`updateStage01Enemy`](../src/stage_runtime.cpp#L9127)。Stage 1 实际使用根类型 `0x06/0x08`；同族 `0x07` 出现在后续关卡。

### 普通敌人 `0x06/0x07/0x08 + 0x09`

三个根类型共享状态机；差别主要是贴图，以及哪些路线会按 `effectiveHelpLevel()` 生成 `0x09`。

```text
root state 0:
    显示 20 帧入场标记并把位置夹到 INSIDE(50)
    t == 20:
        speed=6
        允许的 type/route 组合生成若干 0x09
        state=1；可被攻击

root state 1:
    t<=120 且 speed>1: speed-=0.1
    secondaryAngle 以 0x14/帧追踪 AIM(x,y+75)
    MOVE(sourceAngle,speed)

    start=DIFF[40,30,30,30,30]
    period=DIFF[100,80,60,60,50]
    count=DIFF[1,3,5,5,7]
    若 start<=t<240 且 local=(t-start)%period<30 且 local%5==0:
        s=DIFF[4,6,8,9.5,11] + local*0.05
        FAN(0,0,(x,y+75),secondaryAngle,s,count,20000)
        D>2: 再发 speed=s-2 的一层

0x09 satellite:
    首帧随机内圈角；每帧 +0x200
    前 60 帧用 sin(t*pi/120) 把椭圆半径从 1 展开到 (160,60)
    在父实体局部坐标系内沿椭圆公转；不发弹、不可攻击
    父 HP<=0: 爆炸并掉落 Help；父仅失活: 静默退出
```

根 HP 清零时除普通奖励外掉落一个固定类型奖励；越过 `INSIDE(128)` 退出。源码：[`updateStage01Marker`](../src/stage_runtime.cpp#L9640)、[`updateStage01MarkerSatellite`](../src/stage_runtime.cpp#L9708)、[`emitStage01Projectiles`](../src/stage_runtime.cpp#L11566)。

### `0x0a`：曲线显现、追踪后上撤

```text
state 0 (120 帧):
    由出生点外 300 距离的位置沿正弦插值进入出生点
    t==120: angle=此帧移动前 AIM(x,y)，speed=0.8，state=1，可被攻击

state 1:
    t<300: angle=TURN(angle,AIM(x,y),0x100)
    t>=300: angle=TURN(angle,0xc000,0x100)，speed+=0.1
    MOVE(angle,speed)

    start=DIFF[20,10,0,0,0]
    period=DIFF[150,120,60,40,32]
    若 t<300 且 local=(t-start)%period <=19 且 local%3==0:
        周期首帧缓存 AIM(x,y-15)
        从左右枪口和中心各发 SHOT(4,0)，speed=DIFF[4,5,6.5,7,8]
        D>2: 中心追加 speed+2；D>3: 中心追加角度 +/-0x457
        缓存角再向实时瞄准角转 0x40
```

死亡奖励窗口 400，越过 `INSIDE(64)` 退出。源码：[`updateStage01Type0A`](../src/stage_runtime.cpp#L9179)、[`stage01Type0A` 发弹](../src/stage_runtime.cpp#L11124)。

### `0x0b`：高速侧入、减速追踪、上撤

```text
state 0: 显示 20 帧标记并夹到 INSIDE(20)
t==20:
    speed=RAND(F) in [7,9]
    左侧出生 angle=0；右侧出生 angle=0x8000
    state=1；可被攻击

state 1:
    保存移动前位置 old
    if t<200:
        speed=max(1,speed-0.1)
        angle=TURN(angle,AIM(x,y),0x80)
    else:
        angle=TURN(angle,0xc000,0x200)
        speed+=0.1
    MOVE(angle,speed)

    start=DIFF[30,16,12,8,6]
    period=Stage<=3 ? DIFF[32,27,20,15,6] : DIFF[24,20,16,12,6]
    local=(t-start)%(period*5)
    若 t<200 且 local 是前三个 period 的首帧，且 old 枪口位于安全区:
        a=AIM(old.x,old.y+25) 量化到 0x800
        SHOT(0,0,old+(0,25),a,DIFF[4.5,5.5,6.5,6.5,8.5])
        D>2: 追加 speed+1.6
```

死亡奖励窗口 300，越过 `INSIDE(180)` 退出。源码：[`updateStage01Type0B`](../src/stage_runtime.cpp#L9255)、[`0x0b` 发弹](../src/stage_runtime.cpp#L11168)。

### `0x0c`：双枪减速追踪

运动与 `0x0b` 相同，但入场初速为 `[5,7]`，200 帧后向上转向步长为 `0x100`。

```text
normalStart=DIFF[30,20,12,10,10]
normalPeriod=DIFF[140,100,80,80,60]
start=Stage<=3 ? DIFF[30,20,12,10,10] : DIFF[20,12,10,10,10]
period=Stage<=3 ? DIFF[140,100,80,80,60] : DIFF[120,80,60,60,50]

若 t<200:
    local=(t-start)%period
    local==0: 分别缓存左右枪口的 AIM
    local<40 且 local%5==0:
        s=DIFF[4.8,6.5,8,8,9.5] + ((t-normalStart)%normalPeriod)*0.02
        左右各 SHOT(7,0)，起始距离 10
        D>2: 左右各追加向外偏 +/-700、speed=s-0.8
```

死亡奖励窗口 360，越过 `INSIDE(180)` 退出。源码：[`updateStage01Type0C`](../src/stage_runtime.cpp#L9322)、[`0x0c` 发弹](../src/stage_runtime.cpp#L11202)。

### `0x0d`：横穿正弦波

```text
state 0: 20 帧标记
t==20:
    speed=3                         // Stage 1/2 的实际调度
    左侧出生 angle=0xf2fb；右侧出生 angle=0x8d05
    state=1；可被攻击

state 1:
    基准点按 angle 匀速移动
    y=baseY-sin((t%33)*pi/33)*10

    period=DIFF[60,44,24,15,7]
    每 F%period==0，且枪口在安全区、距自机>=50:
        从身体朝向对应的一侧枪口发同角两颗 SHOT(0,0)，起始距离分别 0/10
        角度=AIM(x,y+25) 量化到 0x800
        speed=DIFF[3,4,4.5,5.5,7.5]
```

死亡奖励窗口 480，越过 `INSIDE(180)` 退出。源码：[`updateStage01Type0D`](../src/stage_runtime.cpp#L9384)、[`0x0d` 发弹](../src/stage_runtime.cpp#L11245)。

### `0x0e`：双侧连射与中心大扇

```text
state 0: 20 帧标记；之后 speed=7、可被攻击
state 1:
    t<=120 且 speed>1.2: speed-=0.1
    angle=TURN(angle,AIM(x,y),0x80)
    t>=300: speed-=0.1
    MOVE(angle,speed)

    24<=t<300，cycle=(t-24)%150:
        cycle=0: 缓存右枪口瞄准角
        cycle 0..29 每 5 帧: 右枪口发 SHOT(9,0)
        cycle=40: 缓存左枪口瞄准角
        cycle 40..69 每 5 帧: 左枪口发 SHOT(9,0)
        speed=DIFF[6,7.5,8.5,9,11]
        D>1: 每次追加 2 发 spread=DIFF[0,0,1800,3300,2500]、speed-1
        D>3: 再追加 spread*2、speed-2

        cycle 80..119，按 DIFF[40,30,30,15,15] 间隔:
            从中心分别以 AIM+/-200 发 count=DIFF[4,6,10,12,13]
            visual=0，spread=28000，speed=上表-2.5
```

死亡奖励窗口 500，越过 `INSIDE(128)` 退出。源码：[`updateStage01Type0E`](../src/stage_runtime.cpp#L9441)、[`0x0e` 发弹](../src/stage_runtime.cpp#L11276)。

### `0x0f`：双侧随机流与中心多层扇形

```text
state 0: 20 帧标记；speed=9；按出生侧水平朝场内；可被攻击
state 1:
    t<=120 且 speed>1: speed-=0.1
    angle=TURN(angle,AIM(x,y),0x80)
    t>=300: speed-=0.1
    MOVE(angle,speed)

    40<=t<300:
        period=DIFF[200,120,100,90,90]
        active=DIFF[30,40,50,50,50]
        周期开始缓存左右移动枪口 AIM
        cycle<active: 每帧从两枪口发 visual 5/1 交替的 behavior 0 弹
                      角度在 +/-DIFF[800,1200,1800,2400,3000] 内随机
                      speed 随 cycle 每帧 +0.1
        cycle==65:
            中心发 count=DIFF[5,11,15,17,19] 的窄扇 visual=4
            D>0 增加中心角 +/-10000 的两扇；D>2 再加一层速度
```

死亡奖励窗口 500，越过 `INSIDE(360)` 退出。源码：[`updateStage01Type0F`](../src/stage_runtime.cpp#L9491)、[`0x0f` 发弹](../src/stage_runtime.cpp#L11352)。

### 关卡内大型控制器 `0x10 + 0x11`

`0x10` 出生时生成两个 `0x11`；在 Stage 1 额外生成两个，共四个。

```text
0x10 state 0:
    t==0: 生成 0x11，局部偏移 (+/-160,+40)，Stage1 再加 (+/-270,-20)
    t<90: 从出生点下方 1000 距离按 sin 入场
    每帧基准 y += 1
    t==120: state=1，speed=0.7，可被攻击

0x10 state 1:
    t<900:
        每 20 帧选目标 x in [200,520]、y in [180,220]
        angle=TURN(angle,target,0x200)
    else: angle=0xc000；speed=(t-900)*0.1
    MOVE(angle,speed)

    第一族，30<=t<300:
        period=DIFF[120,60,60,60,60]
        每周期前 20 帧、每 3 帧发一次 visual 0 半圆扇
        count=DIFF[1,3,5,5,7]，t>239 时 count+=2
        speed=DIFF[3,4,5,6,7]+t*0.01；D>2 增加较慢内层
    第二族，420<=t<900:
        每 DIFF[100,80,70,60,50] 帧发 visual 2 半圆扇
        count=DIFF[5,7,9,9,11] + volley*2，速度逐轮增加
        D>2 增加 speed+2 层

0x10 HP<=0:
    仍完成致命帧运动/发弹，然后 state=2，清弹反馈、关闭碰撞
state 2:
    60 帧连续爆炸并缓慢下沉；t==60 停用并解除关卡 gate
```

```text
0x11 state 0 (附着 120 帧):
    以每帧 1/20 的剩余距离追随父+逐渐展开的局部偏移
    t==120: state=1，speed=1，可被攻击

0x11 state 1:
    位置持续以 1/20 追随父+固定偏移
    age<300: 炮口从“父中心”瞄准自机，每帧转 0x20
    300<=age<900: 从自身瞄准，转速=角差/20+1

    age<300，每 DIFF[60,32,24,20,16] 帧:
        发两颗 visual 7（speed=DIFF[3.5,4.5,5,5,6.5] 与 +0.3）
        D>2 再发 +2 与 +2.3
    lateAge=age-390，0<=lateAge<510:
        每 DIFF[100,80,70,60,50] 周期前 25 帧、每 3 帧:
            发 visual 9 双发扇；层数=DIFF[1,1,2,3,3]

    自身死亡: 奖励/爆炸，创建 0x153，在 30 帧内把 maxHP/2 转交给父
    父死亡/失活: 爆炸或静默退出
```

源码：[`updateStage01Setpiece`](../src/stage_runtime.cpp#L9549)、[`updateStage01Child`](../src/stage_runtime.cpp#L9766)、[`0x10/0x11` 发弹](../src/stage_runtime.cpp#L11446)。

### 关底 Boss `0x138 + 0x12..0x17`

根 Boss 每 50 全局帧选 `(x in [210,510], y in [150,250])`，战斗状态以 `TURN(...,0x200)`、`sourceSpeed` 向目标漂移。每条血有 1800 帧倒计时；HP 清零或倒计时结束都在同帧进入下一过渡状态。倒计时结束额外清屏并给自机 100 帧无敌。

```text
root state 0:
    t==0: 生成装饰根 0x12；它再生成 0x13*2、0x14*2
    0..179: 大幅正弦轨迹入场；180..190 固定；之后微下沉
    t==240: state=1，HP=60000，保持出生 radius=160，开第 1 条血

state 1（第 1 条血）:
    漂移；执行 720 帧循环：
      - 多个 30 帧窗口：中心锁定连射 visual 0x0b；D>2 加左右偏角
      - 相邻窗口：visual 1 的双发扩张扇
      - tLocal 60..99/125..164：左右炮口随机偏角扇
      - 360..439/470..559：左右炮口正反旋转扇

血条结束 -> state 2:
    前 120 帧下沉；130 后恢复漂移
    t==130: 所有 0x12..0x14 装饰退出
    t==380: state=3，HP=55000，radius=80，开第 2 条血

state 3（第 2 条血）:
    t=1/11/21/31 依次生成四个 0x15（HP 6000）
    t>=180:
        每 DIFF[16,12,8,7,6] 帧发两组反向旋转扇
        count=DIFF[1,3,4,5,7]，speed=DIFF[3.5,4,4.5,5,7.2]
        若四部件全毁，速度*1.5 并增加另一组 visual 5

血条结束 -> state 4:
    缓慢下沉；t==180 -> state=5，HP=60000，开第 3 条血

state 5（第 3 条血）:
    t=1/11 生成两个 0x16（HP 12000）
    t=21/31 生成两个 0x17（HP 7000）
    t>=160，每 period=(5-liveChildren)*20:
        发 visual 2 半圆扇，count=DIFF[7,9,11,11,13]
        部件越少速度越快；全毁时追加每 20 帧 visual 3 扇

血条结束 -> state 6（结算）:
    t==1 开始结算并给 360 帧无敌；t==420 切换；t==480 停用
```

装饰 `0x12..0x14` 只以 1/5 剩余距离追随父，不发弹、不可攻击。

```text
0x15:
    60 帧从 3 倍局部偏移收拢到父旁，之后可攻击
    parentT >= (childIndex+9)*10:
        period=DIFF[150,100,80,80,60]
        周期前 12 帧每 4 帧锁定连射 visual 7
        D>2 追加 +/-700

0x16:
    parentT 90..209: 炮口按左右侧每帧 +/-200 旋转
    parentT>=210: 炮口追踪父中心到自机并限制到 [0x3060,0x4fa0]
    parentT>89 每 4 帧: visual 7 扇；D>=2 为双发小扇
    parentT>=380: 每 DIFF[24,11,9,9,5] 帧发三向旋转 visual 8；D>2 加速层

0x17:
    从 parentT=210+(childIndex-1)*period 开始
    period=DIFF[200,120,100,90,80]
    周期前 24 帧每 4 帧锁定连射 visual 0x0b；D>1 追加 +/-3000

任一战斗部件死亡:
    奖励/爆炸，生成 0x153 将 maxHP 在 30 帧内转交给根，liveChildCount--
父换相、死亡或倒计时结束: 部件退出
```

源码：[`updateStage01Boss`](../src/stage_runtime.cpp#L9866)、[`emitStage01BossProjectiles`](../src/stage_runtime.cpp#L10128)、[`updateStage01BossChild`](../src/stage_runtime.cpp#L10307)。

## Stage 2

调度见 [`spawnStage02OriginalSchedule`](../src/stage_runtime.cpp#L2089)。本关复用 `0x07/0x08/0x0a/0x0b/0x0d`，行为见 Stage 1；其中 `0x0b/0x0d` 使用 `Stage<=3` 的发弹表。

### `0x19`：横入追踪后上撤

```text
state 0: 20 帧标记；夹到 INSIDE(20)
t==20:
    speed=1.4；若在最左/最右边则初始 angle=右/左
    state=1；可被攻击

state 1:
    old=(x,y)
    t<150: angle=TURN(angle,进入本帧时的 AIM,0x80)，speed+=0.02
    else: angle=TURN(angle,0xc000,0x100)，speed+=0.1
    MOVE(angle,speed)

    t<150 且 old 枪口在安全区:
        start=DIFF[36,30,24,20,16]
        period=DIFF[150,48,32,32,20]
        每周期首帧:
            a=AIM(old.x,old.y+10) 量化到 0x800
            发 visual 5：一颗 speed*1.1，加一组双发 speed、spread=DIFF[900,2800,4000,2500,2500]
            D>=3: 再加双发 speed*0.9、spread*2
```

死亡窗口 300，越过 `INSIDE(180)` 退出。源码：[`updateStage02Type19`](../src/stage_runtime.cpp#L5562)。

### `0x1a`：急停后再次加速

```text
state 0: 20 帧标记；取随机 angle in [0x3b50,0x44b0]，speed=8.6
state 1:
    t<40: angle=TURN(angle,进入本帧时的 AIM,0x80)，speed=max(0.6,speed-0.2)
    else: speed+=0.16
    MOVE(angle,speed)；装饰角每帧 +0x378

    位于场内、距自机>100，且 t<90:
        start=DIFF[18,14,12,12,8]
        period=DIFF[32,24,16,16,8]
        每周期发 SHOT(0x0e,0)，speed=DIFF[5.5,6.5,7.5,8,9.6]
        D>=3: 追加 speed-2
```

死亡窗口 300，越过 `INSIDE(180)` 退出。源码：[`updateStage02Type1A`](../src/stage_runtime.cpp#L5670)。

### `0x1b`：追踪转向的双端重型敌人

```text
state 0: 20 帧标记；t==20 -> speed=7、state=1、可攻击
state 1:
    t<=120 且 speed>1.5: speed-=0.1
    angle=TURN(angle,AIM(x,y),0x80)
    t>=240: speed-=0.1
    MOVE(angle,speed)

    24<=t<=239:
        period=DIFF[120,80,70,70,60]
        phase=(t-24)%period
        phase==0:
            前端发 count=DIFF[3,5,7,7,9] 的 visual 5 窄扇
            speed=DIFF[4,5,5.5,6,7.2]；D>=3 加较慢宽层
        phase=30，及 30<phase<60 每 4 帧:
            后端在 phase=30 缓存瞄准角，随后缓慢追踪
            发 visual 0 单发；D>=1 加双发，D>=3 加高速层，D=4 再加三倍张角层
```

死亡窗口 500，越过 `INSIDE(128)` 退出。源码：[`updateStage02Type1B`](../src/stage_runtime.cpp#L5260)。

### `0x1c`：弧线穿场、锁定连射与大扇

```text
state 0: 20 帧标记
t==20:
    speed=2.5
    左半场初角=6000，右半场初角=0x6890
    state=1；可攻击

state 1:
    angle=TURN(angle,0xc000,0x14)；MOVE(angle,2.5)
    45<=t<300:
        period=DIFF[100,80,60,60,54]
        周期首帧缓存枪口 AIM
        前 DIFF[21,30,36,36,36] 帧每 3 帧:
            SHOT(9,0)，speed=DIFF[5.5,6.5,8,9,10.5]
            D>=3: 追加 +/-3500
        从 t=85 起每周期:
            FAN(4,0,实时AIM,speed=DIFF[3.5,4.5,5,5,6.5],
                count=DIFF[4,8,10,10,12],spread=27000)
            D>=3: 加 speed+1.2 层
```

死亡窗口 500，越过 `INSIDE(360)` 退出。源码：[`updateStage02Type1C`](../src/stage_runtime.cpp#L5375)。

### `0x1d/0x1e`：随背景下落的阵列炮

两者每帧 `y+=1`，进入画面后可被攻击，`y>=760` 退出。

```text
0x1d，y<400:
    period=DIFF[90,50,40,30,20]，用全局 F 取模
    phase=0: 缓存 AIM(x,y+30)+0x400
    phase=0,3,6: 将角度向下量化到 0xf800，发 SHOT(1,0)
                 speed=DIFF[4.5,5.5,6.5,7,8]
                 D>2 再发 speed+1.8

0x1e，t>=80 且 y<400:
    period=DIFF[140,100,80,80,50]
    phase=0: 缓存 AIM(x,y-60)
    phase=0,12,24,36: SHOT(0x0c,0)，speed=DIFF[5,6,7,8.5,9.5]
    D>2 且从 t=86 起: 在 phase=0,12,24 追加角度 +/-600
```

两者死亡时有专属小爆炸和奖励窗口 1000。源码：[`updateStage02Type1DOr1E`](../src/stage_runtime.cpp#L5477)。

### 大型控制器 `0x1f`

```text
每帧 y+=1；y>=-100 时 state 0->1
state 1:
    t==50: 可被攻击
    y<350 且 t>=50:
        每 DIFF[50,30,30,30,20] 帧:
            从 y+70 向自机发 visual 3、behavior 1 的大扇
            count=DIFF[1,3,5,5,5]，spread=18000，speed=DIFF[3,3,4,4,5]
            D>=3: 中心角 +/-800 再各发一扇
        从 t=60 起，每 DIFF[90,72,60,50,50] 周期前 32 帧、每 8 帧:
            从 y-55 发两层旋转圆环 visual 4
            count=DIFF[6,12,14,16,16]，speed=DIFF[4,4,4.5,5,7]

    HP<=0: state=2，奖励窗口 1800，关闭碰撞
state 2: 60 帧连续爆炸；t==60 大爆炸并停用
非死亡状态 y>=820: 静默退出
```

源码：[`updateStage02Type1F`](../src/stage_runtime.cpp#L5768)。

### 大型控制器 `0x20 + 0x21`

```text
0x20 每帧 y+=1
state 0:
    t==0: 生成五个 0x21，(x,局部y)=
          (420,+320),(235,+260),(570,+210),(125,+120),(620,+60)
    y>=-150: state=1，可被攻击
state 1，y<350 且 t>=50:
    每 120 帧仅前 60 帧为射击窗
    按 DIFF[45,30,20,15,15] 间隔重新 AIM，并加 [-1500,1500] 随机角
    发 visual 3、behavior 7 的半圆扇
    count=DIFF[7,11,15,19,21]，speed=DIFF[5,6,7,7.5,9.5]
HP<=0 -> state=2；60 帧连续爆炸，结束时停用并解除 gate

0x21:
    跟随背景每帧 y+=1；y>=-55 -> state=1；t==30 可攻击
    y<350、t>=60:
        period=DIFF[180,150,120,120,100]
        周期首帧缓存 AIM(x,y-20)
        前 48 帧每 DIFF[20,14,10,10,8] 帧:
            扇形发数从 1 逐次增长，spread 随之增长
        D>=3: 周期前 25 帧每 5 帧追加高速 visual 0x0d 小扇
    自身死亡: 奖励窗口 1000，父 liveChildCount--
    父死亡/失活: 爆炸或静默退出
```

源码：[`updateStage02Type20`](../src/stage_runtime.cpp#L5868)、[`updateStage02Type21`](../src/stage_runtime.cpp#L5944)。

### 关底 Boss `0x139 + 0x22..0x24`

根每 50 帧更新随机目标；通常为 `x=[210,510], y=[150,250]`，第 2 条血改为 `y=[220,320]`。战斗状态以 `TURN(...,0x200)` 漂移；四条血均为 1800 帧。

第一形态的六点装饰以 `(x,y-80)` 为中心，横半轴 140、纵半轴 90；13 节装饰环以 `(x,y+yShift+80)` 为中心，横半轴 215、纵半轴 120，并按前后半周分层绘制。

```text
state 0: 正弦从 y=900 入场；t==210 -> state=1，HP=60000，radius=180

state 1（第 1 条血，960 帧循环，从 t=30 起）:
    q 0..299:
        四枪口；内侧两枪口缓存追踪并作连射
        外侧两枪口交错发随机偏角扇；D>=3 加额外方向
    q 330..659:
        四枪口同步发正/反旋转 visual 9/8；D>=3 加速层
    q 690..929:
        四枪口发瞄准方向与反方向的 visual 2、behavior 0x17 连射
        D>=3 每方向追加 +/-2000

血条结束 -> state 2:
    前 90 帧爆炸/下沉；t=100 瞬移下移 160 后回场
    t=180 生成四个固定挂载 0x22：(+/-70,-50),(+/-140,-110)
    t=240 -> state=3，HP=75000，radius=220

state 3（第 2 条血）:
    根只漂移；主要弹幕全部由四个 0x22 发射

血条结束 -> state 4:
    前 120 帧爆炸；t=130 上移 160 后回场
    t=380 -> state=5，HP=40000，radius=80

state 5（第 3 条血）:
    t=10 生成 count=DIFF[3,5,7,7,9] 个 0x23
    根从 t>59 起，在 480 周期的 q=90..449 发 visual 16 半圆锁定连射

血条结束 -> state 6:
    180 帧过渡；t=180 -> state=7，HP=50000

state 7（第 4 条血）:
    根从 t>59 起发反复扫动的 visual 16/behavior 8 扇
    t=210 生成九个 0x24

血条结束 -> state 8:
    240 帧爆炸；t=420 结算切换；t=480 停用
```

```text
0x22（四固定挂载）:
    始终跟随父局部偏移；50 帧后 state=1
    从 t=20 起做 1200 帧循环，按 childIndex 分工：
      - 内侧/外侧交错执行追踪连射窗与旋转圆环窗
      - 650 后按 index 错开发 visual 3、behavior 0x18/0x19 圆环
      - D>=3 普遍增加偏角或高速层
    父离开 state 3 时退出

0x23:
    前 50 帧用 sin 展开到半径 140；随后变速公转
    每 DIFF[9,5,5,5,4] 帧发沿轨道反向旋转的 visual 1
    speed=DIFF[4,5,6,6.5,7.5]；D>=3 加 +0.6 层
    父离开 state 5 时退出

0x24:
    前 50 帧展开到半径 120；随后公转
    t>=30，period=DIFF[240,210,180,180,160]
    周期前 DIFF[16,25,32,32,32] 帧每 3 帧锁定连射 visual 11，速度递增
    父离开 state 7 时退出
```

源码：[`updateStage02Boss`](../src/stage_runtime.cpp#L10464)、[`emitStage02BossProjectiles`](../src/stage_runtime.cpp#L10688)、[`updateStage02BossChild`](../src/stage_runtime.cpp#L10889)。

## Stage 3

调度见 [`spawnStage03OriginalSchedule`](../src/stage_runtime.cpp#L2292)。本关复用 `0x07/0x08/0x0b`；`0x0b` 使用 Stage 1 的早期发弹表。

### `0x25`：横摆追踪小敌人

```text
state 0:
    20 帧标记；标记 x 在隐藏基准轨迹上叠加振幅 100 的全局正弦摆动
    t==20: speed=2，angle=0x4000，夹到 INSIDE(20)，state=1，可攻击

state 1:
    t<180:
        基准点 angle=TURN(angle,AIM(baseX,baseY),0x40)，MOVE(base,2)
        x=baseX+sin((F-entityId*55)*2pi/320)*100；y=baseY
    else:
        angle=TURN(angle,0xc000,0xa0)，speed+=0.1，MOVE(angle,speed)

    t<180 且在场内:
        start=DIFF[24,18,15,15,15]
        period=DIFF[120,80,70,60,50]
        周期首帧缓存 AIM；前 30 帧每 5 帧从左右枪口发 visual 7
        speed=DIFF[6,7,8,8.8,10.8]
        D>=3: 左右分别追加向外偏 +/-400
```

每 4 帧留一次尾迹；死亡窗口 300，越过 `INSIDE(180)` 退出。源码：[`updateStage03Type25`](../src/stage_runtime.cpp#L7395)。

### `0x26`：双炮大型追踪敌人

```text
state 0: 20 帧标记；之后 speed=6、state=1、可攻击
state 1:
    t<210:
        t<=120 且 speed>1.5: speed-=0.1
        angle=TURN(angle,AIM(x,y),0x40)
    else: angle=TURN(angle,0xc000,0xa0)，speed+=0.1
    MOVE(angle,speed)

    24<=t<210:
        period=DIFF[110,70,60,60,60]
        周期首帧分别缓存左右枪口 AIM
        周期前 24 帧每 4 帧: 左右各发 visual 7
        speed=DIFF[6,7,8,8,9.5]；D>=3 每枪口追加 +/-1000

        每两个周期：第一个周期 +32 帧从右枪口发 visual 4 大扇；
                    第二个周期 +32 帧从左枪口发
        count=DIFF[5,7,9,7,11]，speed=DIFF[4,5,6,6.5,8]
        D>=3: 增加少一发、speed-1.5 的内层
```

死亡窗口 500，越过 `INSIDE(128)` 退出。源码：[`updateStage03Type26`](../src/stage_runtime.cpp#L7499)。

### `0x27/0x29 + 0x28/0x2a`：高速本体与挂载炮

`0x27` 创建 `0x28`，`0x29` 创建 `0x2a`。难度 0 各两个卫星，其余难度各四个。

```text
root state 0:
    首帧先放到左上或右上画外 (-100,-100)/(820,-100)
    20 帧标记后生成卫星：
      0x27 -> 0x28 at (+/-50,-90)，D>0 再加 (+/-100,-50)
      0x29 -> 0x2a at (+/-30,+80)，D>0 再加 (+/-70,+40)
    angle 指向脚本出生点；speed=0x27?11.5:12；state=1，可攻击

root state 1:
    t<60: speed 每帧 -0.15，最低 0x27?2.5:3
    60<=t<240: 每 50 帧随机新目标 x=[120,600]、y=t+[0,100]
    t>=240: 目标 y=-500，speed+=0.1
    angle=TURN(angle,目标,0x200)；MOVE(angle,speed)

0x27 根额外发弹，60<=t<240:
    period=DIFF[160,120,90,90,90]
    每周期向自机发：
      FAN(3,0,speed=DIFF[4.5,6.5,7.5,8,9.5],count=DIFF[3,5,7,7,9],spread=20000)
      加一层少一发的 visual 2、behavior 9、speed+3
    D>=3: 在周期 +24 帧再发同组

satellite 0x28/0x2a:
    以 1/8 剩余距离追随父+固定局部偏移；不参与碰撞
    父 T<240 时发弹：
      0x28: t>=100，period 同 0x27，周期前 40 帧每 5 帧 visual 9
      0x2a: t>=75，period=DIFF[90,60,50,50,40]，前 30 帧每 5 帧 visual 7
      周期首帧从父中心缓存 AIM，再叠加卫星固有偏角
      speed=0x28?DIFF[5,6,6.5,6.5,8]:DIFF[5.6,6.5,7,6.5,8]，随 phase +0.08
      D>=3: 追加 speed +2 或 +2.5
```

根死亡窗口 500；父死亡时卫星爆炸退出，父静默失活时卫星静默退出。根仅在 `t>=240` 后检查 `INSIDE(128)`。源码：[`updateStage03Type27Or29`](../src/stage_runtime.cpp#L7601)、[`updateStage03Satellite`](../src/stage_runtime.cpp#L7717)。

### 大型控制器 `0x2b`

```text
state 0: 20 帧标记；之后 speed=7、state=1、可攻击
state 1:
    t<300:
        t<=120 且 speed>0.8: speed-=0.1
        angle=TURN(angle,AIM(x,y),0x40)
    else: angle=TURN(angle,0xc000,0xa0)，speed+=0.1
    MOVE(angle,speed)

    40<=t<300:
      A. 每 DIFF[18,14,12,12,10] 帧:
         从下枪口按 244 帧往返扫角发 visual 9
         count=DIFF[2,3,5,5,7]，spread=(count-1)*0xc80
         speed=DIFF[4.5,5.8,6.5,6.5,8]；D>=3 加 +1 层
      B. 从 t=50 起交错发奇偶半圆扇 visual 4：
         halfPeriod=DIFF[55,40,32,26,20]
         count=DIFF[7,13,15,15,17]，速度随 t 缓增

    HP<=0: state=2，奖励窗口 1000、清弹反馈、关闭碰撞
state 2: 60 帧连续爆炸/下沉，结束时停用
```

越过 `INSIDE(200)` 退出。源码：[`updateStage03Type2B`](../src/stage_runtime.cpp#L7784)。

### `0x2c/0x2d`：下落阵列炮

```text
共同运动:
    每帧 y+=1
    0x2c 在 y>=-40 进入 state 1；t==40 可攻击
    0x2d 在 y>=-100 进入 state 1；t==60 可攻击
    身体朝向持续追踪自机；0x2d 在射击窗口内暂停转向

0x2c，t>=40 且 y<350:
    每 DIFF[60,36,28,24,18] 帧
    从朝向前方 77 发两颗 visual 6，speed=DIFF[4.5,5.5,6,6.5,8.5] 与 +0.3
    D>=3 再发 +0.6/+0.9/+1.2

0x2d，t>=60 且 y<350:
    period=DIFF[120,80,70,60,45]
    window=DIFF[16,20,24,24,24]
    周期前 window 帧每 4 帧，从身体两侧 150 距离的枪口各发 visual 7 小扇
    count=DIFF[1,1,2,2,2]，spread=0x578，speed=DIFF[5.5,6.5,7.5,8,10]
    D>=3 每枪口追加 speed+2 单发
```

死亡时专属爆炸、奖励窗口 1000；`0x2c y>=800`、`0x2d y>=900` 退出。源码：[`updateStage03Type2C`](../src/stage_runtime.cpp#L7897)、[`updateStage03Type2D`](../src/stage_runtime.cpp#L7953)。

### 大型共享 HP 控制器 `0x2e + 0x2f`

```text
0x2e state 0:
    t==0: 生成局部偏移 (0,+240) 的 0x2f
    前 90 帧从左下画外按 sin 入场；每帧基准 y+=1
    t==120: state=1，speed=0.7，可攻击

0x2e state 1:
    t<1300:
        每 20 帧选目标 x=[240,480], y=[20,80]
        angle=TURN(angle,target,0x200)
        520<=t<620: speed+=0.01
    else: angle=0xc000；speed=(t-1300)*0.1
    MOVE(angle,speed)

    左枪口阶段，90<=t<250:
        缓存 AIM；每 DIFF[24,20,18,18,16] 帧发向一侧扫动的 visual 4 扇
        repeats=DIFF[3,3,4,6,6]，count=DIFF[1,3,4,4,5]
    右枪口阶段，320<=t<480: 镜像执行同一族
    双枪阶段，550<=t<1300:
        period=DIFF[70,48,38,32,28]
        周期首帧缓存两枪口 AIM；前 20 帧每 4 帧发 visual 9
        第 n 个周期 count=n+1，spread=n*DIFF[6000,4000,3200,2800,2600]

    HP<=0: state=2，奖励/清弹反馈
state 2: 60 帧连续爆炸；结束停用并解除 gate
```

```text
0x2f:
    以 1/7 剩余距离追随父+(0,240)
    t==120: 从父复制 HP/maxHP，state=1，可攻击
    检查八个候选窗口 [10,58,114,178,250,330,418,514]，但只允许 t<500，
    因而 514 窗实际不可达，418 窗在 t=500 前截断：
        每窗口每 4 帧，瞄准角以 400/帧追踪
        FAN(0x0d,0,count=DIFF[1,3,5,5,5],spread=27000,
            speed=DIFF[3.5,4.5,5,5,6.5]+local*0.12)
        D>=3: 追加角度 +/-800、speed+1 单发
    每帧把子体本帧受到的伤害同步扣到父；父更低时反向同步
    任一 HP<=0 都令父 HP=0；父死亡后关闭碰撞
```

源码：[`updateStage03Type2E`](../src/stage_runtime.cpp#L8013)、[`updateStage03Type2F`](../src/stage_runtime.cpp#L8164)。

### 关底 Boss `0x13a + 0x30..0x34`

根在普通阶段每 50 帧选目标，state 3 还每 25 帧刷新一次；使用 `TURN` 漂移。四条血均为 1800 帧。

```text
state 0:
    t==0: 生成可破坏下臂 0x30 at (+/-150,+120)，
          以及不可破坏上炮 0x31 at (+/-100,-100)
    先从 y=-200 下冲到 400，再回弹到 y=200
    t==180 -> state=1，HP=70000，radius=150

state 1（第 1 条血）:
    根漂移；1000 帧循环中 p=80..399 分四个 80 帧块
    每块前 DIFF[20,36,50,60,60] 帧、每 4 帧发逐渐增大的 visual 12 窄扇
    count=q/4+1，speed=DIFF[4,6,7.5,8,9]+block*0.5
    0x30/0x31 同时发各自弹幕

血条结束 -> state 2:
    前 90 帧爆炸/下沉；t=90 speed=3；之后快速回场
    t=200 -> state=3，HP=66000

state 3（第 2 条血）:
    根漂移；1200 帧循环：
      - p=30..279: visual 5 大扇，D>0 叠 visual 1 内层
      - 从 p=320 起八个逐渐变长的窗口：每 5 帧发加速 visual 3 大扇
        窗口内瞄准角以 0x78/次追踪；D>=3 加 +1.5 层
    0x31 切换到 state 3 的特殊 behavior 26/27 扇

血条结束 -> state 4:
    120 帧爆炸/下沉；t=120 speed=0.5；130 后回场
    t=380 -> state=5，HP=40000，radius=80

state 5（第 3 条血）:
    根漂移，不直接发弹
    从 t=10 起按 DIFF[150,120,100,100,100] 的左右半周期，
    每 DIFF[10,9,8,8,8] 帧创建横扫节点 0x32/0x33

血条结束 -> state 6:
    180 帧爆炸/下沉；t=180 -> state=7，HP=50000

state 7（第 4 条血）:
    根漂移；t=10 生成四个 0x34 at (+/-250,-20),(+/-120,-70)
    根自身不发弹；t>99 且四部件全毁时把 t 清零，等待血条伤害转交完成

血条结束 -> state 8:
    240 帧爆炸；t=420 结算切换；t=480 停用
```

```text
0x30（两个可破坏下臂）:
    以 1/5 剩余距离追随父局部偏移；父进入 state 1 时可攻击
    t>9，每 DIFF[100,60,40,36,30] 周期前 20 帧、每 4 帧向下发 visual 3 小扇
    自身死亡: 奖励/大爆炸，0x153 在 30 帧内把 maxHP 转交给根
    父离开过渡 state 2 后退出

0x31（两个不可破坏上炮）:
    固定在父局部偏移，炮口平滑追踪；不参与碰撞
    父 state 1 时执行 1000 帧循环：
      0..399: 双层 visual 7 锁定扇
      400..699: 炮口先转向侧面再正反旋转，密集 visual 13/behavior 1 扇
      700..999: 逐轮增大发数/速度的 visual 6 锁定扇
    父 state 3 时，p>=690 后左右交错发 visual 3/2、behavior 26/27 的大扇
    父进入后续阶段时退出

0x32/0x33（横扫节点）:
    40 帧从根位置正弦插值到脚本横向目标，随后可攻击
    基准点沿创建角加速，实体叠加 +/-sin(t*pi/75)*30 的横摆
    父 T>=60 后按 DIFF[80,60,50,50,50] 周期锁定：
        周期前 DIFF[24,32,36,36,40] 帧每 4 帧，
        同时向缓存角和反方向发 visual 7；D>=3 加速层
    死亡时可能发 behavior 3 的瞄准反击弹，并用 0x153 把 maxHP 转交根

0x34（最终四部件）:
    40 帧展开到父局部偏移，之后以 1/10 剩余距离追随
    父 T>=80，p=(T-80)%380：
      p<200: 四部件按 index*50 错开发旋转 visual 4 圆环
      p>=200: 四部件错开发随机角 visual 3 圆环；D>=3 加另一随机角高速层
    自身死亡: 奖励窗口 1800，0x153 将 maxHP/2 转交根，liveChildCount--
```

源码：[`updateStage03Boss`](../src/stage_runtime.cpp#L8250)、[`emitStage03BossProjectiles`](../src/stage_runtime.cpp#L8487)、[`Stage 3 Boss 子节点`](../src/stage_runtime.cpp#L8609)。

## Stage 4

调度见 [`spawnStage04OriginalSchedule`](../src/stage_runtime.cpp#L2563)。本关复用 `0x07/0x08/0x0b`；`0x0b` 使用 Stage 1 的 `Stage>3` 发弹表。

### `0x35`：高速回转小敌人

```text
state 0: 等待 20 帧；按出生侧令 angle=右/左，speed=12，state=1，可攻击
state 1:
    turn=通常 60；45<=t<=64 时 turn=1300
    根据出生侧和出生 y 象限决定 turn 正负
    angle+=turn；MOVE(angle,12)

    t<200，当前位置和下一位置都在安全发弹区，且 F%DIFF[42,16,10,10,8]==0:
        SHOT(6,0,(x,y+20),AIM,DIFF[5,6,7,7,9])
        D>2: 追加 speed+2.2
```

发弹使用移动前坐标；死亡窗口 200，下一位置越过 `INSIDE(180)` 退出。源码：[`0x35` 运动](../src/stage_runtime.cpp#L12896)、[`0x35` 发弹](../src/stage_runtime.cpp#L13275)。

### `0x36`：高速入场、急减速、再上撤

```text
state 0: 等待 20 帧；按左右出生侧选择随机入场角；speed=15
state 1:
    t<80:
        以 sin(t*pi/160)*700 的转速追踪 AIM
        speed=max(1,speed-0.18)
    80<=t<=200:
        t==80 开启碰撞；angle=TURN(angle,AIM,0x80)
    t>200:
        angle=TURN(angle,0xc000,200)；speed+=0.1
    MOVE(angle,speed)

    80<=t<200 且枪口在场内，每 DIFF[60,40,30,24,16] 帧:
        a=AIM 量化到 0x800
        发 visual 4：a+/-200 各一颗 speed=DIFF[4,5.2,6.5,7.5,9]，
                      中心一颗 speed+0.3
        D>2: 追加 a+/-750、speed-0.5
```

死亡窗口 300，下一位置越过 `INSIDE(180)` 退出。源码：[`0x36` 运动](../src/stage_runtime.cpp#L12932)、[`0x36` 发弹](../src/stage_runtime.cpp#L13300)。

### `0x37`：脉冲速度漂移敌人

```text
state 0:
    首帧确定随机 angle
    phaseScale=clamp(t/120,0,1)
    baseSpeed=8*phaseScale
    speed=baseSpeed-sin((t%30)*pi/60)*baseSpeed
    MOVE(angle,speed)
    t>=120: state=1，t=0，可攻击

state 1:
    保持同一方向；速度仍按 30 帧脉冲从 8 降到约 0 再恢复
    距自机>50，且 t>=10:
        period=DIFF[100,60,50,40,32]
        周期首帧缓存 AIM
        周期前 24 帧，每 DIFF[10,7,5,4,4] 帧:
            在缓存角 +/-DIFF[600,800,1000,1200,1400] 内随机发 visual 0
            speed=DIFF[4.2,5.2,6,6,7.5]；D>2 加 +1.2 层
            缓存角再向实时 AIM 转 0x80
```

死亡窗口 300，下一位置越过 `INSIDE(64)` 退出。源码：[`0x37` 运动](../src/stage_runtime.cpp#L12989)、[`0x37` 发弹](../src/stage_runtime.cpp#L13328)。

### `0x38`：双阶段扇形重型敌人

```text
state 0: 20 帧后 speed=7、state=1、可攻击
state 1:
    t<=120 且 speed>1.2: speed-=0.1
    angle=TURN(angle,AIM,0x80)
    t>=290: speed-=0.1
    MOVE(angle,speed)

    24<=t<=289，local=(t-24)%120:
        local=0/40: 缓存枪口 AIM
        local<DIFF[16,24,28,32,36] 且 local%4==0:
            visual 9 扇从 1 发逐步长大
            spreadStep=DIFF[320,320,350,450,600]
            speed=DIFF[6,7,7.5,10,11]
        40<=local<=69 且每 4 帧:
            visual 8 大扇，count=DIFF[3,5,7,7,9]，spread=20000
            speed=base+(local-40)*0.1+1；D>2 加 base+ramp-2 层
        缓存角每帧向实时 AIM 转 0x20
```

死亡窗口 500，越过 `INSIDE(128)` 退出。源码：[`0x38` 运动](../src/stage_runtime.cpp#L13021)、[`0x38` 发弹](../src/stage_runtime.cpp#L13364)。

### 运输体 `0x39/0x3a + 0x3b/0x3c`

根与所有子体共享 HP；击中任何活动子体都会把本帧伤害同步给根。

```text
root 0x39/0x3a state 0:
    20 帧后进入 state 1，speed=2，可攻击
    0x39 初角向下；0x3a 按出生侧斜向场内

root state 1:
    0x39: t<120 每帧弯 20；120..179 弯 100；之后弯 40
    0x3a: t<210 每帧弯 -80；之后弯 60
    左右出生侧镜像弯曲；MOVE(angle,2)

    每 DIFF[100,70,60,60,40] 帧:
        FAN(3,1,AIM,speed=1.2,count=DIFF[5,7,9,7,9],spread=22000)
        D>2: 增加少一发、speed=0.2 的内层

    t=40,80,...,320: 各生成一个 0x3b
    t=360: 生成终端 0x3c

0x3b/0x3c:
    首帧从根复制 HP/角度/出生基准，之后使用与根相同的弯曲规则 MOVE(angle,2)
    0x3b 按父 t 每 DIFF[88,55,47,41,31] 帧发 visual 8 瞄准弹
         speed=DIFF[4.5,5,5.5,6,7.7]；D>2 加 +1.8 层
    0x3c 不发弹，只是共享 HP 的终端子体

根 HP<=0: 奖励窗口 1000，state++，最终 t==1000 退出
子体发现根 HP<=0: 进入 state 2，并按出生时间差校准死亡计时；t==100 奖励后退出
根丢失/失活: 子体立即退出
```

源码：[`运输体运动`](../src/stage_runtime.cpp#L13051)、[`运输体发弹`](../src/stage_runtime.cpp#L13591)、[`finishStage04CarrierSharedHp`](../src/stage_runtime.cpp#L13639)。

### `0x3d + 0x3e`：三炮台锚点敌人

```text
0x3d state 0:
    t==0: 创建局部坐标 (-148,-80),(-95,-105),(113,-110) 的三个 0x3e
    20 帧标记后：speed=2.5；按出生侧取 angle=2000/0x7830
    state=1，可攻击
state 1:
    MOVE(angle,2.5)
    若侧枪口在场内:
        half=DIFF[100,80,50,60,50]
        t=32 mod 2*half: 在 AIM 的 0,+/-7000 发 visual 5 扇
        t=half+32 mod 2*half: 在 AIM 的 +/-3500 发扇
        D>2: 两个半周期补上彼此缺失的角度，speed-1.2
        count=DIFF[5,7,9,9,9]，speed=DIFF[3.2,3.6,4,5,6.5]

0x3e:
    固定在父局部偏移；左侧来源会镜像 x 偏移
    20 帧后 state=1；炮口按角差/10+0x30 追踪自机
    phase=30+(ownerId-selfId)*12
    t>=phase，每 DIFF[95,60,45,38,27] 帧:
        沿炮口发 visual 6，speed=DIFF[4.6,5.5,6,5.5,7] 与 +0.4
        D>2 再发 +2/+2.4
    父死亡/失活时退出
```

`0x3d` 死亡窗口 500，越过 `INSIDE(360)` 退出。源码：[`0x3d/0x3e` 运动](../src/stage_runtime.cpp#L13113)、[`0x3d/0x3e` 发弹](../src/stage_runtime.cpp#L13403)。

### 关卡内大型控制器 `0x3f`

```text
state 0:
    前 90 帧从斜下画外按 sin 入场；每帧基准 y+=1
    t==120: state=1，speed=0.3，可攻击

state 1:
    t<900:
        每 20 帧选目标 x=[240,480], y=[40,100]
        angle=TURN(angle,target,0x200)，MOVE(angle,0.3)
    else:
        angle=0x4000；speed=(t-900)*0.1；向下加速退出

    t<900 的弹幕：
      A. 四枪口交错窗口:
         half=DIFF[70,55,45,40,40]，window=DIFF[12,16,20,20,20]
         窗口内每 3 帧各发三方向 visual 7
         speed=DIFF[4.5,5.5,6,7.5,9.5]；D>2 加两组偏移层
      B. 60<=t<420，每 90 帧的前 50 帧:
         每 DIFF[16,10,8,7,5] 帧从中心发随机偏角 visual 4
         speed=t*0.005+DIFF[3,4,4.5,4.5,6]
         D=3 加高速层；D=4 加左右偏角
      C. 450<=t<900:
         每 DIFF[100,70,60,50,25] 帧发 visual 2 半圆扇
         count=DIFF[7,9,11,13,15]，速度随时间增加；D>2 加高速层

    HP<=0: 完成本帧运动/发弹后 state=2，奖励窗口 1800、清弹反馈
state 2:
    60 帧连续爆炸并下沉；t==60 停用并解除 gate
```

活动时越过 `INSIDE(400)` 会直接退出并解除 gate。源码：[`0x3f` 运动](../src/stage_runtime.cpp#L13198)、[`0x3f` 发弹](../src/stage_runtime.cpp#L13487)。

### 关底 Boss `0x13b + 0x40..0x43`

根 Boss 每 50 帧更新随机目标：第 1 条血为 `x=[260,460],y=[60,180]`，其余为 `x=[210,510],y=[150,250]`。每次阶段击破先清掉当前活动部件计数，并进入过渡状态。

```text
state 0:
    从 y=620 正弦入场到 y=120
    t=180 生成六个可破坏附肢 0x40：
          (+/-60,+260),(+/-150,+230),(+/-230,+170)
    t=240 -> state=1，HP=195000，倒计时=4500，radius=200

state 1（第 1 条血）:
    根漂移
    从 t=64 起，每 DIFF[200,160,160,160,120] 帧:
        以 AIM 为轴创建速度从快到慢、张角逐步覆盖整圆的 visual 10 双发扇列
        maximum=DIFF[11,17,20,20,20]
        D>=3: 插入第二套偏转 1500 的速度层
    六个 0x40 执行各自的长序列
    t==3420: t=0，整个根/附肢序列循环

血条结束 -> state 2:
    前 120 帧爆炸/下沉；130 后回场
    t=380 -> state=3，HP=45000，倒计时=1800，radius=80

state 3/4/5（第 2 条血）:
    state 3 漂移；t=10 生成 count=DIFF[7,9,11,11,13] 个 0x41，
    在横半径 100、纵半径 200 的椭圆上均分初角
    t=150 -> state 4
    state 4 用 60 帧正弦冲到随机邻近点 -> state 5
    state 5 漂移 90 帧 -> state 4；反复短距跳跃
    根不直接发弹，弹幕由 0x41 产生

血条结束 -> state 6:
    180 帧过渡；t=180 -> state=7，HP=58000，倒计时=1800

state 7（第 3 条血）:
    漂移；t=10 生成三个共享 HP 的 0x42
    根从 t=60 起，1200 帧循环中在 300/460/620 开始的三个 80 帧窗口发弹：
        按 DIFF[28,24,20,20,16] 交错发奇偶半圆扇 visual 4
        count=DIFF[4,7,7,7,7]，并围绕 AIM 加 +/-j*400 多层
        speed=DIFF[4.5,6,6.5,7,8.5]

血条结束 -> state 8:
    180 帧过渡；t=180 -> state=9，HP=70000，倒计时=2100

state 9/10（第 4 条血）:
    state 9 用 40 帧正弦移动到 (440,150)，并创建位移特效；随后 state=10
    state 10 在振幅逐渐增至 200 的横向正弦轨迹上移动，y 也上下摆动
    t=300 生成三个共享 HP 的 0x43
    根弹幕：
      - t<180 或 360<=t<660：三拍交错的 visual 4 多层半圆、visual 0 奇偶扇
      - 200<=t<350：逐发增长的 visual 12 瞄准扇；D>=3 加 +/-9000
      - t>=670 每 3 帧：三组 visual 8 双发，张角先从大收束，800 后中心角摆动

血条结束 -> state 11:
    240 帧连续爆炸；t=420 结算切换；t=480 停用
```

#### `0x40`：第 1 条血六附肢

```text
state 0: 60 帧后可攻击，并向父 liveChildCount 登记
state 1: 以自身 speed 追向父局部挂点；按父 T 进入下列子状态

state 2，父 T<600:
    六部件以不同相位摆动炮口
    从 T=32+pairIndex*DIFF[12,12,10,8,7] 起，
    每 DIFF[79,79,61,48,39] 帧发 visual 13 锁定弹
    D>0 追加 +/-4444

state 3，父 T=600..939:
    以 1/20 贴回挂点；660<=T<920:
    每 DIFF[65,44,38,44,38] 周期前 20 帧、每 4 帧发 visual 9 锁定连射
    D>=3 追加 +/-3888

state 4/7（分别在 T=960+index*150，及 T=2600/2870/3140 触发）:
    前 50 帧瞄准；t=90 后 speed=10 且每帧 +0.2，向自机冲刺
    在场内时每帧向后喷 visual 3/5、behavior 1 随机散弹
    state 4 还按 DIFF[4,1,1,1,1] 间隔发 visual 12、behavior 3 旋转圆环
    离开内框 -> state 5/8

state 5/8:
    90 帧后以 1/20 回挂点；state 8 的返回途中还沿连接链分段发 visual 4 双扇
    t=120 或父序列指定帧 -> state 1

state 6，父 T=1950..2550:
    贴回挂点，六炮口按不同正弦相位发正反方向 visual 13
    period=DIFF[72,44,32,32,28]，速度随 T 增长

自身 HP<=0:
    奖励/爆炸，0x153 将 maxHP 转交根，state=-1
state -1:
    沿附肢到根的连接链逐段爆炸
    若父仍在第 1 条血，t=200 时满 HP 复生并重新执行 state 0；否则退出
```

源码：[`updateStage04Type40`](../src/stage_runtime.cpp#L12113)。

#### `0x41`：第 2 条血椭圆轨道卫星

```text
state 0: 50 帧用 sin 展开椭圆轨道
state 1:
    轨道角速度：前 600 帧正弦增速，600..1199 恒速，1200..1799 正弦减速
    最大角步=D==0?333:555
    依次执行 25 个增长波次：
        wave i 起点=10+24*i+interval*i*(i-1)/2
        持续 i*interval，每 interval=DIFF[8,5,3,4,3] 帧发一颗 visual 3
        speed=DIFF[4.8,6,7,7,9]
        D>=3: 同角追加 visual 9、speed-2.4
    父 HP<=0 或倒计时结束: 爆炸退出
```

该节点不可攻击。源码：[`updateStage04Type41`](../src/stage_runtime.cpp#L12568)。

#### `0x42/0x43`：第 3/4 条血共享 HP 卫星

两者 50 帧展开后复制父 HP，随后任何一方 HP 更低都会同步给另一方；任一归零即把父置零。

```text
0x42:
    围绕父-(0,60) 公转；半径 180 加难度相关正弦收缩
    炮口平滑追踪自机
    1200 帧循环：
      0..279: visual 13 锁定连射，period=DIFF[90,44,33,50,44]
      从 410/570/730/800 起各 60 帧: visual 2 加速连射；D>=3 加 +/-0x34bc
      880..1149: 每 DIFF[48,30,18,14,12] 帧发 visual 13 三向弹（D>0）

0x43:
    半径 130 公转，角速度分 600 帧加速/恒速/减速
    period=DIFF[75,40,36,32,26]，按 childIndex 错开
    每三个 period 的前 24 帧、每 3 帧锁定连射 visual 13
    speed=DIFF[5.5,6.5,7,7.5,9.5] 加周期内增量；D>=3 加 +/-750
```

父 HP<=0 或倒计时结束时爆炸退出。源码：[`updateStage04Type42Or43`](../src/stage_runtime.cpp#L12656)。

## 公共死亡后实体

### `0x137`：Counter 模式死亡位置发射器

普通敌人发放死亡奖励时、以及 Boss 每次断血时都会在死亡位置创建不可见、不可攻击、完全静止的 `0x137`。

```text
if counterMode != 1:
    立即停用

period=DIFF[5,4,3,2,2]
每 period 帧，且自机 score!=0、发射器 y<600:
    在原敌人 radius 内随机取一点 P
    heading=AIM(P)+RAND[-1000,1000]
    threshold=RAND[180,480]
    if distance(P,player) < threshold:
        在 P 生成低级奖励和反馈效果
    else:
        SHOT(0x0f,0x16,P,heading,
             RAND[DIFF[3.5,4,4.5,5.5,6.5]+stage*0.1,
                  上式+2])

lifetime=创建者传入值；D==0 时减半
t==lifetime: 停用
```

源码：[`spawnPostDeathCounterEntity`](../src/stage_runtime.cpp#L15138)、[`updatePostDeathCounterEntity`](../src/stage_runtime.cpp#L15169)。behavior `0x16` 的 Counter 弹后续运动见 `projectile-pseudocode.md`。

### `0x153`：30 帧延迟伤害转交

该节点位于画外、不可见、不可攻击、完全静止。每帧从自身剩余 HP 取 `min(remaining,maxHP/30)`，同时扣除所有者相同 HP；30 帧左右耗尽后停用。它用于把可破坏部件的伤害平滑记入 Stage 1、3、4 的控制器或 Boss 根，避免部件击破只改变视觉而不推进共享血条。所有者缺失、类型不符或失活时立即退出。源码：[`spawnDelayedOwnerDamageNode`](../src/stage_runtime.cpp#L3970)、[`updateStage03DeathNode`](../src/stage_runtime.cpp#L9107)。
