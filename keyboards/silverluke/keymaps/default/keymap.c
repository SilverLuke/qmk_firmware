#include QMK_KEYBOARD_H

#include "quantum.h"
#include "layers_definition.h"
#include "macro.c"


#include "tap_functions.c"

// Tap Dance declarations
enum {
    TD_LSFT_CAPS, TD_RSFT_CAPS,
    TD_L_RB_SB_B, TD_R_RB_SB_B,
    TD_L_MOVE, TD_L_NUMBER,
    // Lettere accentate
    TD_AL_A,
    TD_AL_E,
    TD_AL_I,
    TD_AL_O,
    TD_AL_U,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Attiva il caps lock sul shift sinistro
    [TD_LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    // Attiva il caps lock sul shift destro
    [TD_RSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_RSFT, KC_CAPS),
    // Parentesi un tap ( doppio [ e doppio + shift {
    [TD_L_RB_SB_B] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_LBRC),
    // Parentesi un tap ) doppio ] e doppio + shift }
    [TD_R_RB_SB_B] = ACTION_TAP_DANCE_DOUBLE(KC_RPRN, KC_RBRC),
    // Layer di move se tenuto premuto e attivo al doppio tap
    [TD_L_MOVE]    = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_move_layer, dance_move_layer_reset),
    // Layer dei numeri se tengo premuto e attivo al doppio tap
    [TD_L_NUMBER]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_number_layer, dance_number_layer_reset),
    // Lettere accentate tap dance
//    [TD_AL_A] = ACCENTED_LETTER_TAP_HOLD(KC_A),
//    [TD_AL_E] = ACCENTED_LETTER_TAP_HOLD(KC_E),
//    [TD_AL_I] = ACCENTED_LETTER_TAP_HOLD(KC_I),
//    [TD_AL_O] = ACCENTED_LETTER_TAP_HOLD(KC_O),
//    [TD_AL_U] = ACCENTED_LETTER_TAP_HOLD(KC_U),
};

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &ko_make_basic(MOD_MASK_SHIFT, KC_LCBR, KC_RCBR),
    &ko_make_basic(MOD_MASK_SHIFT, KC_LBRC, KC_RBRC),
    &ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_RPRN),
    NULL // Null terminate the array of overrides!
};

/**
L00, L01, L02, L03, L04, L05,     R00, R01, R02, R03, R04, R05, \
L10, L11, L12, L13, L14, L15,     R10, R11, R12, R13, R14, R15, \
L20, L21, L22, L23, L24, L25,     R20, R21, R22, R23, R24, R25, \
L30, L31, L32, L33, L34, L35,     R30, R31, R32, R33, R34, R35, \
L40, L41, L42, L43,               R42, R43, R44, R45, \
L44, L45,                         R40, R41,  \
L54, L55,                         R50, R51, \
L52, L53,                         R52, R53  \
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [L_WRITE] = LAYOUT_5x6_2(
        TO(L_GAME),    KC_1,             KC_2,        KC_3,        KC_4,    KC_5,               KC_6, KC_7,        KC_8,        KC_9,        KC_0,             TO(L_GAME),
        KC_BSLS,       KC_QUOT,          KC_W,        KC_E,        KC_R,    KC_T,               KC_Y, KC_U,        KC_I,        KC_O,        KC_SCLN,          KC_SLSH,
        TD(TD_L_MOVE), KC_Q,             KC_A,        KC_S,        KC_D,    KC_F,               KC_G, KC_H,        KC_J,        KC_K,        KC_L,             TD(TD_L_NUMBER),
        KC_PSCR,       TD(TD_L_RB_SB_B), KC_Z,        KC_X,        KC_C,    KC_V,               KC_B, KC_N,        KC_M,        KC_P,        TD(TD_R_RB_SB_B), KC_GRAVE,
        KC_INS,        KC_LCTL,          KC_MINS,     KC_EQL,                                                      KC_COMMA,    KC_DOT,      KC_RALT,          KC_SCROLL_LOCK,
        KC_LSFT,       KC_SPC,                                                                                                               KC_ENTER,         KC_BACKSPACE,  // Alias KC_BSPC
        KC_TAB,        KC_ESC,                                                                                                               TD(TD_RSFT_CAPS), KC_DELETE,  // Alias KC_DEL
        KC_LGUI,       KC_LALT,                                                                                                              KC_RCTL,          KC_RGUI),
/*
 [L_COLEMAK] = LAYOUT_5x6_2(
        TO(L_DVORAK), KC_7, KC_5, KC_3, KC_1, KC_9,            KC_0, KC_2, KC_4, KC_6, KC_8, TO(L_GAME),
        KC_NO, KC_SCLN, KC_COMM, KC_DOT, KC_P, KC_Y,           KC_F, KC_G, KC_C, KC_R, KC_L, KC_NO,
        KC_TRNS, KC_A, KC_O, KC_E, KC_U, KC_I,                 KC_D, KC_H, KC_T, KC_N, KC_S, KC_TRNS,
        KC_NO, KC_NO, KC_Q, KC_J, KC_K, KC_X,   000               KC_B, KC_M, KC_W, KC_V, KC_Z, KC_NO,
        KC_NO, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
        KC_TRNS, KC_TRNS,                                      KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,                                      KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,                                      KC_TRNS, KC_TRNS),

 [L_DVORAK] = LAYOUT_5x6_2(
        TO(L_WRITE), KC_1, KC_2, KC_3, KC_4, KC_5,             KC_6, KC_7, KC_8, KC_9, KC_0, TO(L_COLEMAK),
        KC_NO, KC_Q, KC_W, KC_F, KC_P, KC_B,                   KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_NO,
        KC_TRNS, KC_A, KC_R, KC_S, KC_T, KC_G, KC_M,           KC_N, KC_E, KC_I, KC_O, KC_TRNS,
        KC_NO, KC_Z, KC_X, KC_C, KC_D, KC_V,                   KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_NO,
        KC_NO, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
        KC_TRNS, KC_TRNS,                                      KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,                                      KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,                                      KC_TRNS, KC_TRNS),
*/
 [L_MOVE] = LAYOUT_5x6_2(
        KC_NO,       KC_NO,   KC_NO,   KC_BTN2, KC_NO,   KC_NO,            KC_NO,   KC_INS,  KC_PSCR,     KC_SCRL, KC_PAUS, KC_NO,
        KC_NO,       KC_MUTE, KC_BTN1, KC_MS_U, KC_BTN3, KC_WH_U,          KC_PGUP, KC_NO,   TO(L_WRITE), KC_NO,   KC_NO,   KC_NO,
        TO(L_WRITE), KC_VOLU, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,          KC_PGDN, KC_LEFT, KC_DOWN,     KC_UP,   KC_RGHT, TO(L_WRITE),
        KC_NO,       KC_VOLD, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT,          KC_NO,   KC_HOME, KC_PGDN,     KC_PGUP, KC_END,  KC_NO,
        KC_NO,       KC_TRNS, KC_TRNS, KC_TRNS,                                              KC_TRNS,     KC_TRNS, KC_TRNS, KC_NO,
        KC_TRNS,     KC_TRNS,                                                                                      KC_TRNS, KC_TRNS,
        KC_TRNS,     KC_TRNS,                                                                                      KC_TRNS, KC_TRNS,
        KC_TRNS,     KC_TRNS,                                                                                      KC_TRNS, KC_TRNS),

 [L_NUMBER] = LAYOUT_5x6_2(
        KC_NO,       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_NO,
        KC_NO,       SEND_A,  SEND_E,  SEND_I,  SEND_O,  SEND_U,           KC_LPRN, KC_LBRC, KC_LCBR, KC_ASTR, KC_SLSH, KC_NO,
        TO(L_WRITE), KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_P4,            KC_P5,   KC_P6,   KC_P7,   KC_P8,   KC_P9,   TO(L_WRITE),
        KC_NO,       KC_NO,   KC_NO,   KC_F11,  KC_CIRC, KC_NO,            KC_NO,   KC_DLR,  KC_F12,  KC_NO,   KC_NO,   KC_NO,
        KC_NO,       KC_TRNS, KC_TRNS, KC_TRNS,                                              KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
        KC_TRNS,     KC_TRNS,                                                                                  KC_TRNS, KC_TRNS,
        KC_TRNS,     KC_TRNS,                                                                                  KC_TRNS, KC_TRNS,
        KC_TRNS,     KC_TRNS,                                                                                  KC_TRNS, KC_TRNS),

 [L_GAME] = LAYOUT_5x6_2(
        KC_0,    KC_1,    KC_2, KC_3, KC_4, KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TO(L_WRITE),
        KC_T,    KC_TAB,  KC_Q, KC_W, KC_E, KC_R,                   KC_Y,    KC_U,    KC_I,    KC_O,    KC_SCLN, KC_SLSH,
        KC_G,    KC_LSFT, KC_A, KC_S, KC_D, KC_F,                   KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_NO,
        KC_U,    KC_LCTL, KC_Z, KC_X, KC_C, KC_V,                   KC_B,    KC_N,    KC_M,    KC_P,    KC_RPRN, KC_GRV,
        KC_J,    KC_LALT, KC_6, KC_7,                                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
        KC_8,    KC_SPC,                                                                                KC_TRNS, KC_TRNS,
        KC_9,    KC_ESC,                                                                                KC_TRNS, KC_TRNS,
        KC_LGUI, TO(L_WRITE),                                                                           KC_TRNS, KC_TRNS)
};

#include "oled.c"