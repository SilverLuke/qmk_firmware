#include QMK_KEYBOARD_H

#include "quantum.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_5x6_2(
		KC_P7, KC_P7, KC_P7, KC_P7, KC_P7, KC_P7,                          KC_P7, KC_P7, KC_P7, KC_P7, KC_P7, KC_P7, \
    	KC_P7, KC_P7, KC_P7, KC_P7, KC_P7, KC_P7,                          KC_P7, KC_P7, KC_P7, KC_P7, KC_P7, KC_P7, \
    	KC_P7, KC_P7, KC_P7, KC_P7, KC_P7, KC_P7,                          KC_P7, KC_P7, KC_P7, KC_P7, KC_P7, KC_P7, \
    	KC_P7, KC_P7, KC_P7, KC_P7, KC_P7, KC_P7,                          KC_P7, KC_P7, KC_P7, KC_P7, KC_P7, KC_P7, \
    	KC_P7, KC_P7, KC_P7, KC_P7, 													 KC_P7, KC_P7, KC_P7, KC_P7, \
									KC_P7, KC_P7,                          KC_P7, KC_P7,
        			                			KC_P7, KC_P7, KC_P7, KC_P7, \
                    			    			KC_P7, KC_P7, KC_P7, KC_P7  \
    )
};

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_270;
}



bool oled_task_user(void) {

	// Host Keyboard Layer Status
    oled_write_P(PSTR("PORCO\n"), false);
    oled_write_P(PSTR("DIO\n"), false);
    oled_write_P(PSTR("v2\n"), false);

        // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM\n") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP\n") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR\n") : PSTR("    "), false);

    return false;
}
#endif
