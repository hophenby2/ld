# 敌弹创建与运动逻辑伪代码

本文总结当前重建运行时中全部敌弹行为。它描述的是
`src/stage_runtime.cpp` 已实现的逻辑，不把 `visualSelector`（贴图）误当成
`projectileId`（运动行为），也不把尚未恢复的原版逻辑写成既成事实。

## 1. 坐标、角度和字段

```text
坐标系:
    x 向右增加
    y 向下增加

16 位角度:
    0x0000 = 向右
    0x4000 = 向下
    0x8000 = 向左
    0xc000 = 向上
    ANGLE(a) = a & 0xffff

难度:
    D = clamp(difficulty, 0, 4)
    DIFF[a,b,c,d,e] = 按 D 选择一个值

伪代码函数:
    POLAR(angle, length) = (cos(angle)*length, sin(angle)*length)
    AIM(from, to) = 从 from 指向 to 的 16 位角
    TURN_TOWARD(current, target, maxStep) = 沿最短方向限速转向

主要字段:
    visualSelector     只决定 Bullet.png 帧、缩放、旋转和部分尾迹
    projectileId       决定运动和派生弹逻辑
    (x, y)             当前可见/碰撞位置
    (anchorX, anchorY) 直线/发射器族的线段起点，或特殊轨道中心
    (prevX, prevY)     上一位置、瞄准快照或特殊辅助量
    angle16            当前运动方向
    prevAngle16        瞄准快照或特殊辅助角
    speed              下一步使用的速度
    baseSpeed          创建时速度；部分行为会改作基准速度
    travel             speedOrAccelHint；沿 angle16 的累计径向距离
    age                已更新帧数，辅助函数执行完后才 age += 1
    arg                 arg8OrAux；通常保存父实体 ID
```

横向弹幕边界不是固定 `x=0..600`，而是：

```text
originX = player.x / 6
playfield = [originX, originX + 600] x [0, 720]
commonCull = playfield 向四周扩 30
```

## 2. 公共创建器

### 2.1 单发

```text
SPAWN_BULLET(visual, behavior, x, y, angle, initialTravel,
             speed, radius, arg):
    if bulletCount >= 0x800:
        return

    b.visualSelector = visual
    b.projectileId = behavior
    b.x = b.anchorX = b.prevX = x
    b.y = b.anchorY = b.prevY = y
    b.angle16 = b.prevAngle16 = angle
    b.travel = initialTravel
    b.speed = b.baseSpeed = speed
    b.radius = radius
    b.arg = arg
    b.collisionEnabled = true
    append b to liveBulletList
```

### 2.2 扇形和圆环

```text
SPAWN_SPREAD(..., center, count, spread):
    if count <= 0: return
    if count == 1: SPAWN_BULLET(..., center); return

    if spread == FULL_CIRCLE:
        step = FULL_CIRCLE / count
        for i in [0, count):
            SPAWN_BULLET(..., ANGLE(center + i * step))
    else:
        start = center - spread / 2
        step = (spread > 0) ? spread / (count - 1) : 0
        for i in [0, count):
            SPAWN_BULLET(..., ANGLE(start + i * step))
```

## 3. 每帧调度顺序

```text
UPDATE_ALL_BULLETS():
    # 使用可增长列表；本帧派生的新弹也可能在本帧稍后更新。
    for i = 0 while i < liveBulletList.size:
        b = liveBulletList[i]
        if not b.active: continue

        b.drawAge = b.age
        choose draw layer from b.projectileId

        dispatch b.projectileId to one of:
            COMMON_MOTION
            REFLECT_ON_BOUNDARY
            HOMING_STEERING
            SCRIPTED_EMITTER
            ORBIT_ARC_PAIR
            EXPANDING_SPIRAL_PAIR
            SHORT_LIVED_MARKER

        queue selector-owned afterimage/trail if required
        b.age += 1

    # 之后才进行玩家与敌弹的命中/擦弹检查。
```

行为族连续覆盖 `0x00..0x3c` 的全部 61 个编号：

| 运动族 | `projectileId` |
| --- | --- |
| 直线/变速 | `00,01,02,03,04,05,06,07,09,0a,0b,0d,0f,10,11,12,16` |
| 边界反射 | `08` |
| 直接积分追踪/曲线 | `0c,0e,23,24,25,26,27,2c,2d,35,36` |
| 移动发射器 | `17,18,19,1a,1b,1c,1d,1e,21,22,28,29,2a,2b,2e,2f,30,31,32,33,34,37,38,39,3c` |
| 椭圆轨道 | `1f,20` |
| 扩张螺旋 | `3a,3b` |
| 非碰撞短标记 | `13,14,15` |

## 4. 直线和变速族

这一族先用旧速度移动，再为下一帧修改速度：

```text
COMMON_PREMOVE(b):
    b.travel += b.speed
    p = b.anchor + POLAR(b.angle16, b.travel)

COMMON_FINISH(b, p):
    b.position = p
    if p outside commonCull:
        b.active = false
```

每个编号在 `COMMON_PREMOVE` 和 `COMMON_FINISH` 之间执行：

```text
id 00 or 16:                     # 匀速直线
    no speed change

id 01:                           # 持续加速
    speed += DIFF[0.06, 0.07, 0.08, 0.10, 0.10]

id 02:                           # 30 帧渐加速
    if age == 0: speed = 0.1 + baseSpeed / 30
    else if age <= 30: speed += baseSpeed / 30

id 03:                           # 停顿，30..90 帧恢复
    if age == 0: speed = 0.1
    else if 30 <= age <= 90: speed += baseSpeed / 60

id 04:                           # 停顿，12..72 帧恢复
    if age == 0: speed = 0.1
    else if 12 <= age <= 72: speed += baseSpeed / 60

id 05:                           # 半速起步，60..120 帧恢复
    if age == 0: speed = baseSpeed * 0.5
    else if 60 <= age <= 120: speed += baseSpeed / 120

id 06:                           # 快速减速
    if age == 0: baseSpeed = speed / 5
    if age <= 30 and baseSpeed < speed:
        speed -= baseSpeed / 6

id 07:                           # 先刹车再加速
    if age < 40: speed -= baseSpeed / 40
    else if age <= 99: speed += baseSpeed / 60

id 09:                           # 刹车 30 帧后重新瞄准
    if age < 30:
        speed -= baseSpeed / 30
    else:
        if age == 30:
            anchor = currentPoint
            angle = AIM(currentPoint, player)
            travel = 0
        speed += DIFF[0.13, 0.15, 0.175, 0.20, 0.20]

id 0a:                           # 40 帧减速后，从保存点重新瞄准
    if age < 40:
        speed = baseSpeed * 1.8 * (1 - age / 40)
    else if age == 40:
        anchor = currentPoint
        angle = AIM(savedSpawnPoint, player)
        travel = 0
        speed = baseSpeed / 60
    else if age <= 99:
        speed += baseSpeed / 60

id 0b:                           # 50 帧刹停后朝偏移目标加速
    if age < 50:
        speed -= baseSpeed / 50
    else:
        if age == 50:
            anchor = currentPoint
            angle = AIM((savedX, savedY - 200), player)
            travel = 0
            speed = 0
        speed += 0.07

id 0d:                           # 24 帧后持续加速，并留下短命轨迹弹
    if age > 23:
        speed += DIFF[0.15, 0.17, 0.18, 0.20, 0.20]
    if currentPoint inside commonCull:
        SPAWN_BULLET(visual=4, behavior=0x0f,
                     position=currentPoint, speed=0)

id 0f: if age == 20: active = false
id 10: if age == 40: active = false
id 11: if age == 10: active = false

id 12:
    if age == 60:
        spawn terminal effect
        active = false
```

## 5. 反射弹 `08`

```text
REFLECT_ON_BOUNDARY(b):
    b.travel += b.speed
    p = b.anchor + POLAR(b.angle, b.travel)

    if p crosses any playfield edge expanded by radius:
        replacementAngle = b.angle
        if p.x is left/right of the playfield:
            replacementAngle = ANGLE(0x8000 - b.angle)
        if p.y is above the playfield:
            replacementAngle = ANGLE(-b.angle)

        # 同时越过上侧角落时，纵向判断覆盖横向结果。
        # 只越过底边时不改角度；替换弹继续向外，稍后由 commonCull 回收。
        SPAWN_BULLET(same visual, behavior=00, p,
                     replacementAngle, speed=b.speed)
        b.active = false

    if p outside commonCull:
        b.active = false
```

## 6. 追踪和连续转向族

本族先按旧方向和旧速度直接更新 `(x,y)`，再修改下一帧的角度/速度。
统一在超出 `playfield + 250` 后删除。

```text
HOMING_PREMOVE(b):
    target = AIM(b.position, player)
    b.prevPosition = b.position
    b.position += POLAR(b.angle, b.speed)
```

```text
id 0c:                           # 两段式追踪
    if age < 60:
        if age == 0: speed = 8
        if speed > 1.4: speed -= 0.11
        angle = TURN_TOWARD(angle, target, maxStep=0x29a)
    else:
        if age == 60: speed = baseSpeed + 0.1
        else: speed += 0.1
        angle = TURN_TOWARD(angle, target,
                            DIFF[120,160,200,250,300])
    leave visual-4 / id-0f trail in commonCull

id 0e:                           # 波动速度追踪
    phase = (age + 30) * FULL_CIRCLE / 120
    if age < 240:
        speed = (baseSpeed + 3)/2 + sin(phase)*(baseSpeed - 3)/2
        step = if age < 30
                   then DIFF[200,240,270,300,300] + 500
                   else DIFF[200,240,270,300,300] + 300
                        - sin(phase)*300
    else:
        speed += 0.1
        step = 200
    angle = TURN_TOWARD(angle, target, step)
    leave visual-5 / id-0f trail in commonCull

id 23 or 24:                    # 加速移动发射器
    if id == 24 and age == 0:
        clamp position into commonCull
    if age % DIFF[15,11,9,9,8] == 0 and position inside playfield:
        spread = (id == 23) ? 0x7448 : 0x85dc
        fire two visual-8 / id-03 bullets over spread
        speed = DIFF[3.5,4.5,5.5,5.0,6.0]
        if D > 2: repeat at speed + 1.5
    leave visual-5 / id-0f trail
    speed += 0.1

id 25:                          # 高难度轻追踪加速弹
    leave visual-4 / id-0f trail
    if D > 2: angle = TURN_TOWARD(angle, target, 0xa0)
    speed += 0.1

id 26 or 27:                    # 左右弯曲、加速、有尾迹
    leave id-0f trail (26 用 visual 5；27 用 visual 4)
    sign = (id == 26) ? -1 : +1
    angle += sign * DIFF[150,170,180,195,211]
    speed += 0.05

id 2c or 2d:                    # 左右弯曲、加速、无额外尾迹
    sign = (id == 2c) ? -1 : +1
    angle += sign * DIFF[150,170,180,195,180]
    speed += 0.05

id 35 or 36:                    # 前 90 帧弯曲，之后直飞
    if age < 90:
        sign = (id == 35) ? +1 : -1
        angle += sign * 0x5a
        speed += 0.05
```

## 7. 脚本发射器族

本族默认也采用 `anchor + POLAR(angle, travel)`。除特别写明者外，母弹继续
沿原方向移动，离开 `commonCull` 时删除。

```text
id 17:
    at age 25:
        fire visual-3 / id-01 toward player at speed 2

id 18 or 19:
    end = 16 + DIFF[12,16,20,20,20]
    for even age in [16, end):
        clockwise = (id == 19)
        childVisual = clockwise ? 0x0d : 0x0c
        rotatingOffset = clockwise
                             ? age*200 + 0x36a0
                             : -age*200 - 0x36a0
        fire childVisual / id-01 at speed 1.5
    at age end: terminal effect; delete mother

id 1a or 1b:
    every DIFF[10,8,6,5,5] frames while inside playfield:
        choose visual 8/9 and mirrored rotating angle
        fire id-02 at DIFF[5,6,6.5,6,7]
        if D > 2: fire second layer at speed + 1.5

id 1c:
    halfPhase = (age + globalFrame) / 2
    if halfPhase % DIFF[18,18,15,16,14]
       < DIFF[6,7,8,10,10] and inside playfield:
        fire two visual-9 / id-02 bullets perpendicular to mother
        at DIFF[3.2,4,4.5,4.5,5.5]

id 1d or 1e:
    add a side-to-side sine offset whose amplitude grows with age
    halfPhase = (age + globalFrame) / 2
    interval = DIFF[4,3,3,3,2]
    at alternating interval boundaries while inside playfield:
        fire visual-0d / id-02 to one perpendicular side
        at DIFF[2.5,3.2,3.6,4,5]

id 21 or 22:
    at age 36:
        offset = (id == 21) ? +12000 : -12000
        fire visual-2 / id-04 at angle+offset, speed=baseSpeed+1.2

id 28:
    parent = FIND_ENEMY(arg)
    phase = (parent.timer - 60) % 1400
    if phase == 870 or phase == 1020:
        fire two visual-8 / id-04 at angle +/- 9000,
        speed=baseSpeed-1

id 29 or 2a:
    every DIFF[8,6,5,5,5] frames while inside playfield:
        emit visual 8/9 / id-04 on mirrored rotating angle
        at DIFF[3,3.5,3.5,4,5]

id 2b:
    if age == 0: savedTarget = player.position
    for age 0..35 every 3 frames while inside playfield:
        fire visual-0c / id-04 fan toward savedTarget
        count = DIFF[1,3,5,7,7]
        speed = DIFF[8,10,11,12,12]
        spread = 20000

id 2e:
    when mother leaves playfield:
        reflect its angle on crossed edge
        fire visual-0d / id-05 fan at reflected angle
        count = DIFF[3,5,6,7,7]
        speed = DIFF[4.5,5,5,5.5,5.5]
        spread = 32000
        delete mother

id 2f or 30:
    for even age in [4,36):
        emit visual 0c/0d / id-02 on mirrored rotating angle,
        speed 8.5
    at age 36: terminal effect; delete mother

id 31:
    when center crosses edge expanded by radius:
        reflect angle on left/right or top/bottom
        clamp the deleted mother's original anchor into the playfield
        # 这次 anchor 写回不改变下行创建的替换弹出生点。
        replace mother with visual-10 / id-00 at same speed

id 32:
    every 9 frames, only if mother visual is 2 or 3:
        childVisual = (visual == 2) ? 8 : 9
        fire two childVisual / id-04 at angle +/- 0x115c,
        speed 6.4

id 33:
    when center crosses edge expanded by radius:
        fire same visual / id-01 toward player at speed 4
        delete mother

id 34:
    at age 20:
        fire visual-5 / id-01 toward player at speed 3

id 37 or 38:
    during first 50 frames:
        speed approaches zero by subtracting baseSpeed/50
    at age 50:
        parent = FIND_ENEMY(arg)
        if parent exists:
            base = angle +/- low16(parent.timer)*0x14d
            fire three visual-8 / id-02 bullets 120 degrees apart,
            speed 4.8
        terminal effect; delete mother

id 39:
    for age < 30: speed -= baseSpeed/30
    at age 30:
        fire two visual-2 / id-02 at angle +/- 15000, speed 5.2
        delete mother

id 3c:
    speed += 0.15 every frame
    emit a zero-speed visual-4 / id-11 spark near current point
    emit one cosmetic particle with deterministic rainbow cycling
```

## 8. 椭圆轨道对 `1f/20`

```text
ORBIT_ARC_PAIR(b):
    if age < 40:
        ramp = sin(age * pi / 80)
        verticalRadius = trunc(ramp * 150)
        horizontalRadius = trunc(ramp * 320)
    else:
        verticalRadius = 150
        horizontalRadius = 320

    if age == 40:
        savedTravelAngle = AIM(savedCenter, player)

    if age > 40:
        speed = min(4, speed + 0.05)
        savedCenter += POLAR(savedTravelAngle, speed)

    turn = DIFF[0x46,0x78,0x8c,0xb4,0xdc]
    angle += (id == 1f) ? +turn : -turn

    position = savedCenter + (
        cos(angle) * horizontalRadius,
        sin(angle) * verticalRadius)

    delete outside playfield expanded by 256
```

## 9. 扩张螺旋对 `3a/3b`

```text
EXPANDING_SPIRAL_PAIR(b):
    if age == 0:
        baseRadius = initialTravel
        prevAngle16 = (anchorY > player.y) ? up : down
        # 当前恢复出的后续分支不再读取 prevAngle16；仍保留原结构写入。

    if age < 0: radius = 0
    else if age < 10: radius = sin(age*pi/20) * baseRadius
    else: radius = baseRadius

    centerSpeed = age * 0.35 - 2
    center += POLAR(angle, centerSpeed)
    angle += (id == 3a) ? +0x1bc : -0x1bc
    position = center + POLAR(angle, radius)

    delete when center leaves playfield expanded by baseRadius + 50
```

## 10. 短生命周期标记 `13/14/15`

```text
id 13 or 15:
    age 0: collisionEnabled=false; grazeOrHitProcessed=true
    age 1: delete

id 14:
    age 0: collisionEnabled=false; grazeOrHitProcessed=true
    age 3: delete
```

这些节点主要服务于效果/队列时序。`collisionEnabled=false` 会禁止擦弹；命中
分支本身只先检查 `radius`，因此只有 `radius<=0` 时才会无条件跳过命中计算。

## 11. 碰撞、擦弹和删除

```text
AFTER_BULLET_UPDATE:
    for each active bullet:
        directIntegration = projectileId in {
            0x0c, 0x0e, 0x23, 0x24, 0x25, 0x26, 0x27,
            0x2c, 0x2d, 0x35, 0x36
        }
        rawPoint = directIntegration ? (x,y) : (anchorX,anchorY)
        effectivePosition = rawPoint + POLAR(angle16, travel)

        if radius <= 0:
            continue

        if distance(effectivePosition, player) <= bullet.radius + hitRadius:
            bullet.active = false
            mark player hit

        else if collisionEnabled and not grazed and
                distance <= bullet.radius + grazeMargin:
            mark grazed
            add graze count and feedback

    inactive bullets are unlinked at the beginning of the next update
```

这里的 `travel` 就是结构字段 `speedOrAccelHint`。直接积分族通常以零径向量
创建，所以常见结果确实等于 `(x,y)`；但碰撞器仍执行上式，不能把它概括成
永远只检查绘制坐标。脚本族 `1d/1e` 的横向正弦绘制偏移也不会改写这个碰撞
基点。

## 12. 源码入口

- 公共构造器：`src/stage_runtime.cpp` 的 `spawnProjectileNode`、
  `spawnProjectileSpread`
- 总调度：`updateProjectiles`
- 直线族：`updateProjectileCommonMotion`
- 反射：`updateProjectileReflectOnBoundary`
- 追踪/曲线：`updateProjectileHomingSteering`
- 发射器：`updateProjectileScriptedEmitter`
- 椭圆轨道：`updateProjectileOrbitArcPair`
- 扩张螺旋：`updateProjectileExpandingSpiralPair`
- 玩家碰撞：`handleEnemyProjectilePlayerHitAndGraze`
