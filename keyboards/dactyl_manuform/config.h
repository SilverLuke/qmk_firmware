// Copyright 2022 SilverLuke (@SilverLuke)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define EE_HANDS  // Software sinistra :avrdude-split-left  destra :avrdude-split-right
#undef MASTER_LEFT
#undef MASTER_RIGHT
#define MASTER_LEFT

#define USE_I2C


#undef MATRIX_ROWS
#define MATRIX_ROWS 12



/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
