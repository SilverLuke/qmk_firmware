#include QMK_KEYBOARD_H
#include "layers_definition.h"

void dance_move_layer(qk_tap_dance_state_t *state, void *user_data) {
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

void dance_move_layer_reset(qk_tap_dance_state_t *state, void *user_data) {
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

void dance_number_layer(qk_tap_dance_state_t *state, void *user_data) {
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

void dance_number_layer_reset(qk_tap_dance_state_t *state, void *user_data) {
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

void accent_letter(qk_tap_dance_state_t *state, void *user_data) {
    tap_data *key = (tap_data *) user_data;
    switch (state->count) {
        case 1:
            // Single tap: Send just 'e'
            register_code(key->keycode);
            unregister_code(key->keycode);
            break;
        case 2:
            // Double tap: Send ALT_R+`+e
            register_code(KC_RALT);
            register_code(KC_GRV);
            register_code(key->keycode);
            unregister_code(key->keycode);
            unregister_code(KC_GRV);
            unregister_code(KC_RALT);
            break;
    }
}