# Player Bomb / Fever Exact Reconstruction Notes

Status: read-only audit of `FUN_140106be0`, `FUN_140109660`, and
`FUN_140109780` against the original `LikeDreamer.exe`.  This resolves the two
Fever modes, all six equipment-dependent Bomb roots, the two six-entry timing
tables, and the player-side object chain from type `0x0b` through `0x1a`.

## Evidence and terminology

Primary code evidence:

- `reverse/ghidra-or-ida/exports/gameplay-spawn-helpers-renamed/neighborhood-decompiled/140106be0_player_update_input_movement_candidate.c`
- `reverse/ghidra-or-ida/exports/gameplay-helpers-renamed/neighborhood-decompiled/140109660_FUN_140109660.c`
- `reverse/ghidra-or-ida/exports/main-gameplay/neighborhood-decompiled/140109780_FUN_140109780.c`
- original instructions at `0x140107350..0x140107a7d` and
  `0x140109780..0x14010cc17`

The names are not guesses.  `re/system/EquipMenu.png` labels the two mode
frames `Auto Fever` and `Manual Fever`, and labels the six Bomb choices:

| `setupGroup` | `optionSlots[2]` | Menu label | Root type |
|---:|---:|---|---:|
| `0` (Vanilla Alice) | `0` | Carrot Blaster | `0x0b` |
| `0` | `1` | Vivid Grenade | `0x0e` |
| `1` (Yuri Cocoa) | `0` | Stinging Words | `0x0f` |
| `1` | `1` | Dark Rampage | `0x11` |
| `2` (URAKO) | `0` | Flaming Hack | `0x12` |
| `2` | `1` | Cheat Barrier | `0x15` |

The setup menu selects EquipMenu frame `0x60` when `DAT_140e41b70 == 0` and
frame `0x61` otherwise (`1400d4610...c:608-613`).  Therefore:

| Original | Exact meaning |
|---|---|
| `DAT_140e41b70 == 0` | Auto Fever |
| `DAT_140e41b70 == 1` | Manual Fever |
| replay `DAT_140e452ec` | recorded Auto/Manual Fever value |

Most importantly, gauge values `-600..-1` are the **active Fever duration**,
not a cooldown.  During this interval normal shots use their enhanced branch
and enemy payout is doubled.  The value counts upward toward zero.

## Player-side object ABI

`FUN_140109660` has this recovered signature:

```cpp
spawnPlayerObject(type, x, y, speed, angle16, value, radius);
```

It allocates at most 256 nodes and initializes the following fields:

| Offset | Field | Constructor source |
|---:|---|---|
| `+0x00` | `active` | `1` |
| `+0x04` | `age` | `0` |
| `+0x08` | `type` | argument 1 |
| `+0x0c/+0x10` | `x/y` | arguments 2/3 |
| `+0x14/+0x18` | `originX/originY` | copies of x/y |
| `+0x1c` | `angle16` | argument 5 |
| `+0x20` | `double speed` | argument 4 |
| `+0x28` | `value` | argument 6; multiplied by 100 in debug mode |
| `+0x2c` | `radius` | argument 7 |
| `+0x30` | `targetRadius` | second copy of argument 7 |
| `+0x34` | `scratch` | `0` |
| `+0x38` | `next` | list link |

Every `FUN_140109780` case runs with the current age and then increments age,
even if that case set `active = 0`.  Equality-based terminal frames therefore
still run their draw/effect work unless the pseudocode below explicitly says
otherwise.

For pseudocode below, `cs(a)` and `sn(a)` are the fixed-angle cosine and sine
helpers `FUN_1403307c0` and `FUN_140332d90`.  `fadeIn(t,n,max)` and
`fadeOut(t,n,max)` denote the exact sine-eased envelopes used by the original;
the frame ranges and maxima are given explicitly.

## Bomb / Fever input state machine

### Literal trigger gate

The Bomb action is `DAT_140e467d4 == 1`.  `FUN_140106be0` accepts it only when:

```cpp
bombLock == 0 &&
(bombStock != 0 || (feverGauge > 49999 && feverMode == Manual)) &&
DAT_140e41a3c == 0 &&
uint32_t(playerStateTimer - 120) > 139 &&
(feverGauge >= 0 || uint32_t(invulnerabilityTimer - 1) > 278)
```

This is a level check rather than a separate edge detector.  The nonzero
`bombLock` prevents immediate retriggering.

### Directly implementable mode logic

```cpp
if (BombDown && triggerGate()) {
    if (feverMode == Auto ||
        (feverMode == Manual && feverGauge < 50000)) {
        startEquippedBomb();       // spends one bomb/guard stock band
    } else {
        startFever();              // Manual Fever was armed/full
    }
}

if (feverGauge < 50000) {
    if (feverGauge < 0) {
        if (DAT_140e46b2c == 0)
            ++feverGauge;

        if ((globalFrame % 16) == 0 && feverGauge < -60)
            emitFeverTrailEffect();

        if (feverGauge == 0) {
            play(Fever3);
            spawnPlayerObject(0x18, playerX, playerY, 0.0, 0, 0, 0.0f);
        }
    }
} else if (feverMode == Auto) {
    startFever();
} else if (feverGauge <= 9999998) {
    armManualFever();
}
```

Both Fever-start paths perform these original operations:

```cpp
feverGauge = -600;
spawnPlayerObject(0x18, playerX, playerY, 0.0, 0, 0, 0.0f);
emitFeverStartEffects();
play(Fever1);
play(Fever2);
invulnerabilityTimer = max(invulnerabilityTimer, 150);
incrementFeverUseCountersUnlessReplay();
```

The Manual-Bomb path additionally sets `playerStateTimer = 0` and clamps an
already very large `invulnerabilityTimer` to `280` (`>279 -> 280`).  The Auto
full-gauge path does not reset `playerStateTimer` and only applies the minimum
of 150.

`armManualFever()` emits the ready effects, plays `Fever4.wav`, and assigns
`feverGauge = 9999999`.  It does **not** start the `-600` timer and does not
spawn type `0x18`.  The sentinel prevents the ready effect from replaying each
frame.  A later Bomb press enters `startFever()` without spending Bomb stock.

Audio globals confirm the terminology:

| Handle | Resource |
|---|---|
| `DAT_140e47280` | `media\se\Fever1.wav` |
| `DAT_140e47284` | `media\se\Fever2.mp3` |
| `DAT_140e47288` | `media\se\Fever3.wav` |
| `DAT_140e4728c` | `media\se\Fever4.wav` |

### Equipped Bomb constructors and timing tables

All root calls use current player `x/y` and angle `0xc000`:

| Group/slot | Root constructor `(type,x,y,speed,angle,value,radius)` | Bomb lock | Invulnerability/cancel timer |
|---|---|---:|---:|
| `0/0` | `(0x0b, px, py, 0, 0xc000, 0, 0)` | `-210` | `300` |
| `0/1` | `(0x0e, px, py, 18, 0xc000, 0, 45)` | `-210` | `300` |
| `1/0` | `(0x0f, px, py, 0, 0xc000, 0, 0)` | `1` | `300` |
| `1/1` | `(0x11, px, py, 0, 0xc000, 0, 0)` | `-180` | `150` |
| `2/0` | `(0x12, px, py, 0, 0xc000, 0, 0)` | `-210` | `300` |
| `2/1` | `(0x15, px, py, 0, 0xc000, 15, 0)` | `-270` | `360` |

The raw arrays loaded in `FUN_140106be0` are therefore:

```cpp
constexpr int bombLock[3][2] = {
    {-210, -210},
    {   1, -180},
    {-210, -270},
};

constexpr int bombInvulnerability[3][2] = {
    {300, 300},
    {300, 150},
    {300, 360},
};
```

The lock updater is exact and sign-sensitive:

```cpp
if (bombLock != 0)
    ++bombLock;
if (bombLock >= 180)
    bombLock = -30;
```

Thus the positive `1` used by Stinging Words counts through 180, changes to
`-30`, then returns to zero.  It is not equivalent to merely assigning `-210`
if intermediate positive state is observed elsewhere.

Starting any equipped Bomb also plays `Bomb1.wav`, decrements the stock level,
subtracts one difficulty-dependent stock threshold from stock progress, resets
the player state timer, and assigns the two table values.  Vivid Grenade also
plays `Bomb4.wav` immediately.

## Exact `0x0b..0x1a` update chains

### Type `0x0b` - Carrot Blaster root

```cpp
a = age;
alpha = (a < 32) ? fadeIn(a, 32, 192)
      : (a >= 164 && a < 180) ? fadeOut(a - 164, 16, 192)
      : (a < 180) ? 192 : 0;

if (a == 0)
    spawn(0x1a, playerX, playerY, 0, 0, 0, 300);

if (a == 0 || a == 8 || a == 16 || a == 24) {
    i = a / 8;
    ang = optionAngle[i];
    spawn(0x0c,
          optionX[i] + cs(ang) * 40,
          optionY[i] + sn(ang) * 40,
          20, ang, 0, 45);
    play(Bomb2);
}

emitAmbientNode(selector = 0x17, alpha);
if (a == 180) active = false;
```

### Type `0x0c` - Carrot projectile / cancel body

```cpp
a = age;
visualScale = (a < 8) ? fadeIn(a, 8, 1.0) : 1.0;
x += cs(angle16) * speed;
y += sn(angle16) * speed;

if (a < 20) {
    reflect angle at [playfieldLeft + radius, playfieldLeft + 600 - radius]
                     and [radius, 720 - radius];
    clamp position with FUN_1401346a0(position, int(radius));
}

terminate = (y < 50);
if (a >= 20) {
    terminate |= x < playfieldLeft - radius ||
                 x > playfieldLeft + 600 + radius ||
                 y < -radius || y > 720 + radius;
}
terminate |= (a == 148);

if (terminate) {
    spawn(0x0d, x, y, 0, 0, 16, 0);
    play(Bomb3);
    active = false;
}

draw(DAT_140e41a58, scale = visualScale, angle = globalFrame * 999);
emit one randomized effect node around x/y each frame;
```

The per-frame effect offset radius is `random % 51`, and its scale is `0.8`,
lifetime is `20`, and selector is `0x3b`.

### Type `0x0d` - Carrot impact visual

It stays at its constructor position.  Scale/radius sine-eases in over ages
`0..9`, remains at its maximum through age 119, fades over `120..129`, draws
`DAT_140e45064`, and sets `active = false` at age `130`.

### Type `0x0e` - Vivid Grenade root

```cpp
a = age;
rootAlpha = the same 32-in / 16-out / 180-frame envelope as type 0x0b;
if (a == 0)
    spawn(0x19, playerX, playerY, 0, 0, 0, 0);

if (a < 30) {
    speed = max(0.0, speed - 0.6);       // constructor speed is 18
    x += cs(angle16) * speed;
    y += sn(angle16) * speed;
    reflect and clamp inside the playfield using radius;
    draw DAT_140e41a58 with a 20-in / 10-out scale envelope;
    emit one randomized selector-0x3b effect per frame;
} else {
    if (a == 30) {
        play(Bomb5);
        speed = 1.0;
        value = 32;
    }
    x += cs(angle16) * speed;
    y += sn(angle16) * speed;
    radius = (a < 40) ? fadeIn(a - 30, 10, 250) : 250;
    if ((a % 8) == 0)
        emit selector `0x20`, alternating the two handles at
        `DAT_140e45068`, scaled from radius;
}

emitAmbientNode(selector = 0x17, alpha = rootAlpha);
if (a == 180) active = false;
```

### Type `0x0f` - Stinging Words root

```cpp
a = age;
x = playerX;
y = playerY;
alpha = the 32-in / 16-out / 180-frame envelope;

if ((a % 3) == 0) {
    for (i = 0; i < 4; ++i)
        spawn(0x10, optionX[i], optionY[i], 50,
              optionAngle[i], 90, 60);
    play(Bomb6);
}

if ((a % 30) == 0)
    emit the original selector-0x5b generator at playerX/playerY;
emitAmbientNode(selector = 0x17, alpha);
if (a == 180) active = false;
```

### Type `0x10` - Stinging Words child

```cpp
x += cs(angle16) * speed;
y += sn(angle16) * speed;
draw(DAT_140e41a5c, angle16, scale = 1);
emit selector-0x3b effect at x/y, angle16, lifetime 12;
if (y < -500) active = false;
```

There is no fixed age expiry.  Constructor `value = 90` is not used as this
object's lifetime by `FUN_140109780`.

### Type `0x11` - Dark Rampage root

```cpp
a = age;
alpha = (a < 32) ? fadeIn(a, 32, 192)
      : (a >= 584 && a < 600) ? fadeOut(a - 584, 16, 192)
      : (a < 600) ? 192 : 0;

if (a == 0) {
    spawn(0x18, playerX, playerY, 0, 0, 0, 0);
    DAT_140e44658 = 600;                 // enhanced-shot timer
}

emitAmbientNode(selector = 0x17, alpha);
if (a == 600 || (a > 59 && bombLock == -179))
    active = false;
```

### Type `0x12` - Flaming Hack root

```cpp
a = age;
alpha = the 32-in / 16-out / 180-frame envelope;

if ((a % 40) == 0 && a < 151) {         // ages 0, 40, 80, 120
    emit selector-0x5b generator at playerX/playerY;
    spawn(0x13, playerX, playerY, 0, randomAngle16(), 0, 0);
}

emitAmbientNode(selector = 0x17, alpha);
if (a == 180) active = false;
```

### Type `0x13` - Flaming Hack timed generator

At every age divisible by five, including terminal age 90, it emits exactly
three children and plays `Bomb7.wav` once:

```cpp
if ((age % 5) == 0) {
    distance = 80 + age * 8;
    for (i = 0; i < 3; ++i) {
        radialAngle = angle16 + age * 999 + i * 0x5555;
        spawn(0x14,
              x + cs(radialAngle) * distance,
              y + sn(radialAngle) * distance,
              0, randomAngle16(), 5, 120);
    }
    play(Bomb7);
}
if (age == 90) active = false;
```

### Type `0x14` - Flaming Hack cancel child

```cpp
alpha = (age < 24) ? 192 : fadeOut(age - 24, 6, 192);
radius = sn(quarterTurn * age / 30) * targetRadius; // targetRadius = 120
draw(DAT_140e41a70, angle16, scale = radius / 75, alpha);
if (age == 30) active = false;
```

The update writes the computed radius back to `+0x2c`, so projectile-cancel
collision sees the same expanding radius as drawing.

### Type `0x15` - Cheat Barrier root

```cpp
a = age;
x = playerX;
y = playerY;

fieldAlpha = (a < 32) ? fadeIn(a, 32, 48)
           : (a >= 224 && a < 240) ? fadeOut(a - 224, 16, 48)
           : (a < 240) ? 48 : 0;
ambientAlpha = same envelope with maximum 192;

radius = (a < 32) ? fadeIn(a, 32, 200)
       : (a >= 230 && a < 240) ? fadeOut(a - 230, 10, 200)
       : (a < 240) ? 200 : 0;

draw the four mirrored DAT_140e45074 edge groups;
draw two counter-rotating DAT_140e45070 center groups;
draw six randomized DAT_140e41938 particles;
if ((a % 20) == 0) play(Bomb8);
emitAmbientNode(selector = 0x17, alpha = ambientAlpha);
if (a == 240) active = false;
```

The computed `radius` is written to `+0x2c`; type `0x15` is therefore itself
the large projectile-cancel field.

### Type `0x16` - shield/guard ring

This type is created by the player hit/stock paths, not by the six root Bomb
constructors:

```cpp
if (age == 0) {
    for (seed = 0; seed < 0x420; seed += 0x21)
        emit one selector-0x48 effect;    // 32 effects
}

alpha = (age < 80) ? 255 : fadeOut(age - 80, 16, 255);
radius = (age < 0) ? 20
       : (age < 32) ? 20 + fadeIn(age, 32, targetRadius - 20)
       : targetRadius;
draw two counter-rotating DAT_140e45078 rings, scale = radius / 200;
if (age == 96) active = false;
```

### Types `0x17` and `0x18` - expanding Fever/stock rings

The two IDs share one update case:

```cpp
if (age == 0)
    invulnerabilityTimer = max(invulnerabilityTimer, 100);
alpha = (age < 32) ? 255 : fadeOut(age - 32, 16, 255);
radius += 25;
draw(DAT_140e45060, scale = radius / 250, alpha);
if (age == 48) active = false;
```

Type `0x18` is created at both Fever start and Fever end, and by Dark Rampage.

### Type `0x19` - Vivid Grenade opening ring

```cpp
if (age == 0)
    invulnerabilityTimer = max(invulnerabilityTimer, 100);
alpha = (age < 16) ? 255 : fadeOut(age - 16, 8, 255);
radius += 50;
draw(DAT_140e45060, scale = radius / 250, alpha);
if (age == 24) active = false;
```

### Type `0x1a` - Carrot Blaster opening cancel ring

```cpp
alpha = (age < 16) ? 96 : fadeOut(age - 16, 8, 96);
radius = sn(quarterTurn * age / 24) * targetRadius; // targetRadius = 300
draw(DAT_140e41a54, scale = radius / 75, alpha);
if (age == 24) active = false;
```

Unlike `0x17..0x19`, type `0x1a` does not raise the invulnerability timer.

## Projectile-cancel participation

`FUN_1400cd750` does not treat every player-side object as a cancel field.  Its
exact filter is:

```cpp
bool cancelCandidate(int type) {
    return (type < 0x1f && ((0x63737000u >> type) & 1u)) || type == 0x1a;
}
```

Decoded IDs are:

```text
0x0c, 0x0d, 0x0e, 0x10, 0x11, 0x14,
0x15, 0x16, 0x18, 0x19, 0x1d, 0x1e, and explicit 0x1a
```

Collision uses the enemy projectile's current visible `x/y` position and the current
object `+0x2c` radius.  This is why the per-frame writes to radius for types
`0x0e`, `0x14`, `0x15`, `0x16`, and `0x17..0x1a` must happen before the later
projectile-cancel pass.

## Reconstruction corrections implemented

The current temporary `updateSpecialGaugeAction()` behavior differs in four
material ways that should be corrected by the eventual port:

1. `-600..0` is Fever-active time, not cooldown.
2. Auto Fever starts immediately on reaching 50000; Manual Fever arms at
   `9999999` and waits for Bomb input.
3. A non-full Manual Fever Bomb press still spends stock and creates the
   equipment-selected root object; it is not always a generic type `0x18`.
4. The original does not perform a hand-written radial bullet wipe at input
   time.  Cancellation comes from the exact player-object type mask and each
   object's evolving `+0x2c` radius in the subsequent collision pass.

## Runtime port status - 2026-07-13

`StageRuntime` now carries `feverMode_` through `GameplayRequest` as the
explicit Auto/Manual Fever mode and implements the recovered mode split.  Auto
starts at 50000, Manual arms at 9999999, negative gauge values are treated as
the 600-frame enhanced-shot Fever interval, and a non-full Manual Bomb creates
the selected equipment root while consuming stock.

The six root constructors, signed Bomb-lock updater, invulnerability table,
types `0x0b..0x1a`, dynamic cancel radii, current-projectile collision point,
`Effect_m`/`Effect_l` core frames, and Bomb/Fever sounds are ported.  Inactive
objects are retained through their terminal draw frame and removed at the next
update, matching the original update/draw/unlink order.

`FUN_1400cc2f0` is also ported with enemy-outer/object-inner traversal and no
object-active filter. Normal shots and type `0x10` are consumed on hit, type
`0x0c` converts to a value-10 `0x0d`, and `0x0d/0x0e/0x14/0x15` apply their
original persistent damage/progress behavior. `FUN_1400cd750` now preserves
its three cancel groups, including the no-reward `0x16/0x1e` group and the
flag-ignoring `0x18/0x19/0x1a` group. Its type-3/type-4 drops use the original
frame-and-projectile-index seeded angle, speed `2.0`, and radii `30/45`. Bomb
input uses the original unsigned
timer gates, delayed hit settlement at player-state timer 260, table-assigned
invulnerability, and per-sound SE multipliers.

Damaging `FUN_1400cc2f0` overlaps also play `Shothit.wav` with the original
distance bucket `((140 - max(0,int(distance)-enemyRadius-60)/10)/10)` applied
to the configured SE volume. The later `Shothit2.wav` branch is additive rather
than a replacement: any overlap against enemy spawn type `0xc3`, `0x127`,
`0x136`, `0x14e`, or `0x150` plays it at SE multiplier `9` unless the
PlayerSideObject type is `0x1e`. This branch is outside the positive-damage
test, matching the original collision ordering. Generic hit-effect nodes remain
pending.

Remaining visual-only gaps are the separate generic effect-list nodes emitted
by Fever start/ready/trail, the randomized `0x0c` and `0x10` trails, and the
selector-`0x5b` overlays.  Core PlayerSideObject creation and collision no
longer use the former hand-written radius-150 wipe.
