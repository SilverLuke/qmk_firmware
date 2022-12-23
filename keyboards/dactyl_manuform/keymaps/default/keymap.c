#include QMK_KEYBOARD_H

#include "quantum.h"

#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2
#define _LAYER3 3
#define _LAYER4 4
#define _LAYER5 5
#define _LAYER6 6
#define _LAYER7 7
#define _LAYER8 8
#define _LAYER9 9
#define _LAYER10 10
#define _LAYER11 11
#define _LAYER12 12
#define _LAYER13 13
#define _LAYER14 14
#define _LAYER15 15

enum custom_keycodes {
    LAYER0 = SAFE_RANGE,
    LAYER1,
    LAYER2,
    LAYER3,
    LAYER4,
    LAYER5,
    LAYER6,
    LAYER7,
    LAYER8,
    LAYER9,
    LAYER10,
    LAYER11,
    LAYER12,
    LAYER13,
    LAYER14,
    LAYER15,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_LAYER0] = LAYOUT_5x6_2(TG(8), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, TG(0), KC_BSLS, KC_QUOT, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_SCLN, KC_SLSH, TO(2), KC_Q, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, TO(1), KC_LBRC, KC_LPRN, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_P, KC_RPRN, KC_RBRC, KC_NO, KC_LCTL, KC_MINS, KC_EQL, KC_COMM, KC_DOT, KC_RALT, KC_NO, KC_TAB, KC_SPC, KC_ENT, KC_BSPC, KC_ESC, KC_LSFT, KC_RSFT, KC_DEL, KC_LGUI, KC_LALT, KC_RCTL, KC_NO),
    [_LAYER1] = LAYOUT_5x6_2(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_PLUS, KC_MINS, KC_LPRN, KC_LBRC, KC_LCBR, KC_RCBR, KC_RBRC, KC_RPRN, KC_ASTR, KC_SLSH, KC_NO, TO(2), KC_P0, KC_P1, KC_P2, KC_P3, KC_P4, KC_P5, KC_P6, KC_P7, KC_P8, KC_P9, TO(0), KC_NO, UC(0x00E0), UC(0x00E8), UC(0x00EC), UC(0x00F2), UC(0x00F9), KC_CIRC, KC_DLR, KC_P4, KC_P5, KC_P6, KC_PDOT, KC_NO, KC_NO, UC(0x00E9), KC_NO, KC_P1, KC_P2, KC_P3, KC_P0, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [_LAYER2] = LAYOUT_5x6_2(KC_NO, KC_NO, KC_ACL0, KC_ACL1, KC_ACL2, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MUTE, KC_WH_U, KC_MS_U, KC_BTN3, KC_NO, KC_NO, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_NO, TO(0), KC_VOLD, KC_MS_L, KC_BTN1, KC_MS_R, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, TO(1), KC_NO, KC_VOLU, KC_WH_D, KC_MS_D, KC_BTN2, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [_LAYER8] = LAYOUT_5x6_2(KC_NO, KC_7, KC_5, KC_3, KC_1, KC_9, KC_0, KC_2, KC_4, KC_6, KC_8, TO(0), KC_NO, KC_SCLN, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_NO, KC_NO, KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, KC_NO, QK_BOOT, KC_NO, KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, KC_NO, EE_CLR, DB_TOGG, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO, KC_TAB, KC_SPC, KC_ENT, KC_BSPC, KC_LSFT, KC_LCTL, KC_DEL, KC_RCTL, KC_LGUI, KC_LALT, KC_RALT, KC_ESC)

};
#include "oled.c"
