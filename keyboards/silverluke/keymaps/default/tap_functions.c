#include QMK_KEYBOARD_H
#include "layers_definition.h"

void dance_move_layer(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1: // Enable write layer
            if (state->pressed) {
                layer_on(L_MOVE);
                layer_off(L_WRITE);
            }
            break;
        case 2: // Enable MOVE
            layer_on(L_MOVE);
            layer_off(L_WRITE);
            break;
    }
}

void dance_move_layer_reset(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1: // Enable write layer
            layer_on(L_WRITE);
            layer_off(L_MOVE);
            break;
        case 2: // Enable MOVE
            layer_on(L_MOVE);
            layer_off(L_WRITE);
            break;
    }
}

void dance_number_layer(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1: // Enable write layer
            if (state->pressed) {
                layer_on(L_NUMBER);
                layer_off(L_WRITE);
            }
            break;
        case 2: // Enable MOVE
            layer_on(L_NUMBER);
            layer_off(L_WRITE);
            break;
    }
}

void dance_number_layer_reset(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1: // Enable write layer
            layer_on(L_WRITE);
            layer_off(L_NUMBER);
            break;
        case 2: // Enable MOVE
            layer_on(L_NUMBER);
            layer_off(L_WRITE);
            break;
    }
}

// Experimental
#define ACCENTED_LETTER_TAP_DANCE(key) { .fn = {NULL, accent_letter, NULL}, .user_data = (void *)&((tap_data){.keycode = key}) }
#define ACCENTED_LETTER_TAP_HOLD(key) { .fn = {NULL, x_finished, x_reset}, .user_data = (void *)&((tap_data){.keycode = key}) }

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Tap dance enums
enum {
    X_CTL,
    SOME_OTHER_DANCE
};

td_state_t cur_dance(tap_dance_state_t *state);

// For the x tap dance. Put it here, so it can be used in any keymap
void x_finished(tap_dance_state_t *state, void *user_data);
void x_reset(tap_dance_state_t *state, void *user_data);

typedef struct {
    uint16_t keycode;
} tap_data;

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) {
            return TD_SINGLE_TAP;
        }
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else {
            return TD_SINGLE_HOLD;
        }
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted)
            return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return TD_DOUBLE_HOLD;
        else
            return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed)
            return TD_TRIPLE_TAP;
        else
            return TD_TRIPLE_HOLD;
    } else
        return TD_UNKNOWN;
}

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t xtap_state = {.is_press_action = true, .state = TD_NONE};

void x_finished(tap_dance_state_t *state, void *user_data) {
    tap_data *key    = (tap_data *)user_data;
    xtap_state.state = cur_dance(state);

    switch (xtap_state.state) {
        case TD_SINGLE_TAP:
            register_code(key->keycode);
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_RALT);
            register_code(KC_GRV);
            register_code(key->keycode);
            break;
        case TD_DOUBLE_TAP:
            register_code(key->keycode);
            unregister_code(key->keycode);
            register_code(key->keycode);
            unregister_code(key->keycode);
            break;
        case TD_DOUBLE_HOLD:
            register_code(KC_RALT);
            register_code(KC_GRV);
            register_code(key->keycode);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            register_code(key->keycode);
            unregister_code(key->keycode);
            register_code(key->keycode);
            unregister_code(key->keycode);
            break;
        default:
            break;
    }
}

void x_reset(tap_dance_state_t *state, void *user_data) {
    tap_data *key    = (tap_data *)user_data;
    switch (xtap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_X);
            unregister_code(key->keycode);
            break;
        case TD_SINGLE_HOLD:
            unregister_code(key->keycode);
            unregister_code(KC_GRV);
            unregister_code(KC_RALT);
            break;
        case TD_DOUBLE_TAP:
            break;
        case TD_DOUBLE_HOLD:
            unregister_code(key->keycode);
            unregister_code(KC_GRV);
            unregister_code(KC_RALT);
            break;
        case TD_DOUBLE_SINGLE_TAP:
        default:
            break;
    }
    xtap_state.state = TD_NONE;
}
