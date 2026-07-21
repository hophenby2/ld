# 敌人、发弹与敌弹逻辑伪代码索引

这组文档把当前重建运行时中的敌人运动、敌人发弹和敌弹运动整理为面向
人类的伪代码。目标是便于继续逆向、比较原版录像和定位行为偏差，而不是把
重建代码宣称为泄露或恢复出的原始源码。

## 阅读顺序

1. [Stage 1-4 敌人逻辑](enemy-pseudocode-stage01-04.md)
2. [Stage 5-7 敌人逻辑](enemy-pseudocode-stage05-07.md)
3. [Stage 8-10 敌人逻辑](enemy-pseudocode-stage08-10.md)
4. [敌弹创建与运动逻辑](projectile-pseudocode.md)

前三份文档回答“谁在何时移动和发什么”；最后一份回答“创建出的
`projectileId` 如何继续运动、转向、派生和消失”。

## 范围边界

包含：

- Stage 1-10 实际构造的普通敌人、中 Boss、关底 Boss；
- Boss 挂载节点、共享碰撞代理、延迟伤害节点和会实际发弹的死亡计数实体；
- 敌人状态机、移动、瞄准、发弹、共享 HP、死亡和离场；
- `projectileId 0x00..0x3c` 的全部 61 种敌弹行为；
- 难度表、固定角、关键帧、周期和派生弹关系。

不包含：

- 玩家、子机、Bomb 和玩家弹；
- 奖励道具运动、背景滚动、HUD 和纯绘制动画；
- 从未被关卡日程或子节点构造器使用的保留分发槽；
- 仅存在于逆向产物、尚未进入当前重建运行时的推测逻辑。

## 统一伪代码记号

```text
D = clamp(difficulty, 0, 4)
DIFF[a,b,c,d,e] = 按 D 选择值

ANGLE(a) = a & 0xffff
0x0000 = 右, 0x4000 = 下, 0x8000 = 左, 0xc000 = 上

POLAR(angle, distance) =
    (cos(angle) * distance, sin(angle) * distance)

AIM(from, to) = 从 from 指向 to 的 16 位角
TURN_TOWARD(now, target, step) = 沿最短方向每帧最多转 step

FIRE(v, id, p, a, s, r=1, arg=0) =
    创建 visualSelector=v、projectileId=id 的单发

FAN(v, id, p, center, s, count, spread) =
    以 center 为中线、含首尾的等角扇形

RING(v, id, p, start, s, count) =
    以 start 为第一发的 360 度等分圆环
```

文档中的 `timer` 通常指 `helperTimer`，`state` 指 `helperState`。固定角常数
保留十六进制或原十进制值，以便直接搜索源码和反编译结果。

## 公共敌人更新顺序

```text
UPDATE_ENEMIES():
    append pending enemies

    # 使用可增长列表；本帧创建的子节点可能在本帧稍后更新。
    for each enemy in live list by insertion order:
        if HP <= 0 and this type does not own an exact death branch:
            create rewards/effects
            enemy.active = false
            continue

        enemy.age += 1
        if enemy.age <= activationDelay:
            damp generic velocity
            continue

        dispatch by spawnType / parentSpawnType:
            exact movement/state helper
            exact firing helper, or firing inside the state helper
            exact death/bounds tail

        if this family uses generic velocity integration:
            position += velocity

        snapshot draw state/timer when required
        helperTimer += 1 unless the exact helper owns that clock
        if targetable: targetableTimer += 1

        append newly pending children

    apply player-shot damage after all enemy helpers
```

由此产生几个重要时序结论：

```text
1. 玩家弹通常在本帧末写 HP，敌人的 HP<1 分支通常在下一帧 helper 中执行。
2. helper 在本帧把 timer 设为 0 后，分发器尾部可能立即把它加到 1。
3. 父节点先创建、子节点后创建时，父节点通常先更新；子节点能看到父节点
   刚切换的新 state/timer。
4. active=false 的终止帧仍可能已经排入绘制；实体在下一次 update 开头解绑。
5. Boss 根经常只是控制器，真正承受碰撞或发弹的是子节点。
```

## 公共运动和发弹原则

```text
MOVE_POLAR(enemy):
    enemy.position += POLAR(enemy.angle16, enemy.speed)

STEER_TO(enemy, target, maxTurn):
    desired = AIM(enemy.position, target)
    enemy.angle16 = TURN_TOWARD(enemy.angle16, desired, maxTurn)
    MOVE_POLAR(enemy)

REFRESH_RANDOM_TARGET(period, xRange, yRange):
    if globalFrame % period == 0:
        target = deterministicFrameSeededRandom(xRange, yRange)

FIRE_IF_VISIBLE(action):
    if source point lies inside the helper's recovered firing rectangle:
        action
```

所有随机数均来自帧号和固定 salt 的确定性序列。相同关卡帧、难度和配置应
得到相同坐标、角度与发弹选择，而不是使用运行时真随机数。

## HP、目标和退出

```text
targetable == false:
    玩家弹碰撞遍历跳过该实体

shared HP owner/child:
    子节点把本帧伤害差额写回根节点
    或根节点取各子节点 HP 的 sum/min
    非参战节点可能保留在远场哨兵坐标，不能按普通离屏对象删除

timeout phase break:
    flush bullets or create cancel field
    保护玩家若干帧
    进入 transition state
    transition timer 到达阈值后装入下一条 HP

ordinary exit:
    helper 自己检查恢复出的矩形/计时器并 active=false

boss handoff:
    清除当前敌弹和关卡敌人
    切换 BGM/演出
    在恢复出的延迟后创建 Boss 根
```

## 跨关卡不可见实体

敌人死亡奖励函数与若干 Boss 阶段击破分支都会在击破位置创建 `0x137`。
它不是纯计数标记，而是 Counter 模式的实际发射器：

```text
UPDATE_POST_DEATH_COUNTER(0x137):
    velocity = 0
    drawBody = drawMarker = false
    targetable = false

    if counterMode != 1:
        active = false
        return

    interval = DIFF[5,4,3,2,2]
    if player.score != 0 and timer % interval == 0 and deathY < 600:
        p = 在原敌人半径内选一个确定性随机点
        heading = AIM(p, player) + RAND[-1000,+1000]
        threshold = RAND[180,480]

        if distance(p, player) <= 480 and distance(p, player) < threshold:
            在 p 创建低阶奖励和反馈效果
        else:
            minSpeed = DIFF[3.5,4.0,4.5,5.5,6.5] + stage*0.1
            FIRE(visual=0x0f, id=0x16, p, heading,
                 speed=RAND[minSpeed,minSpeed+2], radius=1)

    lifetime = 创建参数；Easy 时减半
    if timer == lifetime: active = false
```

普通死亡把 `enemy.radius*0.6` 作为寿命；Boss 阶段分支可传入独立寿命。
`0x153` 则是不可见的延迟伤害节点：每帧最多把自身 `maxHp/30` 的剩余伤害
转交 owner，约 30 帧耗尽；owner 已不存在时立即退出。

## 文件与主分发对应

| 内容 | 主要实现 |
| --- | --- |
| Stage 1-4 普通敌人与早期 Boss | `src/stage_runtime.cpp` |
| Stage 5 通用晚期敌人、晚期 Boss 总入口 | `src/stage_runtime_late.cpp` |
| Stage 6 普通敌人/中 Boss | `stage_runtime_enemy06.cpp`, `stage_runtime_midboss06.cpp` |
| Stage 7 普通敌人/中 Boss/双 Boss | `stage_runtime_enemy07.cpp`, `stage_runtime_midboss07.cpp`, `stage_runtime_boss07.cpp` |
| Stage 8 普通敌人/Boss | `stage_runtime_enemy08.cpp`, `stage_runtime_boss08.cpp` |
| Stage 9 中 Boss/Boss | `stage_runtime_midboss09*.cpp`, `stage_runtime_boss09.cpp` |
| Stage 10 场景/普通敌人/最终 Boss | `stage_runtime_scene10.cpp`, `stage_runtime_enemy10.cpp`, `stage_runtime_late.cpp`, `stage_runtime_boss10_aux.cpp` |
| 敌弹公共运行时 | `src/stage_runtime.cpp` |

## 完整性判定

敌人文档以“当前代码可达构造路径”为边界：关卡 schedule、Boss/中 Boss
子节点构造器、敌弹发射器构造器和共享代理构造器中出现的每个 `spawnType`
都必须进入对应阶段文档的覆盖表。一个编号在多个关卡复用时，只完整描述一次，
其他关卡明确链接到复用族。

敌弹文档以 `updateProjectiles()` 的连续分发区间 `0x00..0x3c` 为边界。
七个运动族的编号并集必须等于该完整区间，不能只记录当前探针页面展示的代表弹。
