#ifdef OLED_ENABLE
#include <stdio.h>
#include "layers_definition.h"

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    oled_set_cursor(0, 0);
    switch (get_highest_layer(layer_state)) {
        case L_WRITE:
            oled_write_ln_P(PSTR("WRITE"), false);
            break;
        case L_COLEMAK:
            oled_write_ln_P(PSTR("CO-DH"), false);
            break;
        case L_DVORAK:
            oled_write_ln_P(PSTR("DVORA"), false);
            break;
        case L_MOVE:
            oled_write_ln_P(PSTR("MOVE"), false);
            break;
        case L_NUMBER:
            oled_write_ln_P(PSTR("NUMB"), false);
            break;
        case L_GAME:
            oled_write_ln_P(PSTR("GAME"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    oled_set_cursor(0, 2);
    led_t led_state = host_keyboard_led_state();
    oled_write_ln_P(led_state.caps_lock ? PSTR("CAPS") : PSTR("    "), false);
    oled_write_ln_P(led_state.scroll_lock ? PSTR("SCRL") : PSTR("    "), false);


	for (uint8_t x = 0; x < DISPLAY_X; x++) {
		oled_write_pixel(x, 63, true);
	}
	oled_set_cursor(0, 9);
	char wpm_str[10];
	sprintf(wpm_str, "KPM:\n%03d\n", get_current_wpm());
	oled_write(wpm_str, false);

    return false;
}

#define NUM_LAYER_TIMEOUT 10000  //configure your timeout in milliseconds

void matrix_scan_user(void) {  // Go back to default layer after 10 second of inattivity
    int layer = get_highest_layer(layer_state);
    if ( layer == L_MOVE || layer == L_NUMBER ) {
        if (last_input_activity_elapsed() > NUM_LAYER_TIMEOUT) {
            layer_move(L_WRITE);
        }
    }
}

#endif