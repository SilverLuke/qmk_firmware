#include "quantum.h"
#include "keycodes.h"

enum custom_keycodes {
    SEND_A = SAFE_RANGE,
    SEND_E,
    SEND_I,
    SEND_O,
    SEND_U,
};

void accented_letter(uint16_t key) {
    register_code(KC_RALT);
    register_code(KC_GRV);
    register_code(key);
    unregister_code(key);
    unregister_code(KC_GRV);
    unregister_code(KC_RALT);
}

void send_a(void) {
    accented_letter(KC_A);
}

void send_e(void) {
    accented_letter(KC_E);
}

void send_i(void) {
    accented_letter(KC_I);
}

void send_o(void) {
    accented_letter(KC_O);
}

void send_u(void) {
    accented_letter(KC_U);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SEND_A:
            if (record->event.pressed) {
                send_a();
            }
            break;
        case SEND_E:
            if (record->event.pressed) {
                send_e();
            }
            break;
        case SEND_I:
            if (record->event.pressed) {
                send_i();
            }
            break;
        case SEND_O:
            if (record->event.pressed) {
                send_o();
            }
            break;
        case SEND_U:
            if (record->event.pressed) {
                send_u();
            }
            break;
    }
    return true;
};
