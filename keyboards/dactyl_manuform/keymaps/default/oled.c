#ifdef OLED_ENABLE
#include <stdio.h>


oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    oled_set_cursor(0, 0);
    switch (get_highest_layer(layer_state)) {
        case _LAYER0:
            oled_write_ln_P(PSTR("WRITE"), false);
            break;
        case _LAYER1:
            oled_write_ln_P(PSTR("CO-DH"), false);
            break;
        case _LAYER2:
            oled_write_ln_P(PSTR("DVORA"), false);
            break;
        case _LAYER6:
            oled_write_ln_P(PSTR("MOVE"), false);
            break;
        case _LAYER7:
            oled_write_ln_P(PSTR("NUMB"), false);
            break;
        case _LAYER8:
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
	sprintf(wpm_str, "WPM:\n%03d\n", get_current_wpm());
	oled_write(wpm_str, false);

    return false;
}

#endif

#define NUM_LAYER_TIMEOUT 10000  //configure your timeout in milliseconds

void matrix_scan_user(void) {  // Go back to default layer after 10 second of inattivity
    int layer = get_highest_layer(layer_state);
    if ( layer == _LAYER1 || layer == _LAYER2 ) {
        if (last_input_activity_elapsed() > NUM_LAYER_TIMEOUT) {
            layer_move(_LAYER0);
        }
    }
}
