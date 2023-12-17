// Copyright 2022 SilverLuke (@SilverLuke)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define EE_HANDS  // Software sinistra :avrdude-split-left  destra :avrdude-split-right

#define USE_I2C
#define DISPLAY_X (63)

#undef MATRIX_ROWS
#define MATRIX_ROWS 12

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    32


#define TAPPING_TERM 200

// #define TAPPING_TOGGLE 2

