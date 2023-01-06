#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    switch (get_highest_layer(layer_state)) {
        case _LAYER0:
            oled_write_P(PSTR("WRITE\n"), false);
            break;
        case _LAYER1:
            oled_write_P(PSTR("NUMBE\n"), false);
            break;
        case _LAYER2:
            oled_write_P(PSTR("MOVME\n"), false);
            break;
        case _LAYER3:
            oled_write_P(PSTR("3\n"), false);
            break;
        case _LAYER4:
            oled_write_P(PSTR("4\n"), false);
            break;
        case _LAYER5:
            oled_write_P(PSTR("5\n"), false);
            break;
        case _LAYER6:
            oled_write_P(PSTR("6\n"), false);
            break;
        case _LAYER7:
            oled_write_P(PSTR("7\n"), false);
            break;
        case _LAYER8:
            oled_write_P(PSTR("GAME\n"), false);
            break;
        case _LAYER9:
            oled_write_P(PSTR("Dvorak\n"), false);
            break;
        case _LAYER10:
            oled_write_P(PSTR("Colemak\n"), false);
            break;
        case _LAYER11:
            oled_write_P(PSTR("11\n"), false);
            break;
        case _LAYER12:
            oled_write_P(PSTR("12\n"), false);
            break;
        case _LAYER13:
            oled_write_P(PSTR("13\n"), false);
            break;
        case _LAYER14:
            oled_write_P(PSTR("14\n"), false);
            break;
        case _LAYER15:
            oled_write_P(PSTR("15\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    return false;
}
#endif

#define NUM_LAYER_TIMEOUT 10000  //configure your timeout in milliseconds

void matrix_scan_user(void) {
    int layer = get_highest_layer(layer_state);
    if ( layer == _LAYER1 || layer == _LAYER2 ) {
        if (last_input_activity_elapsed() > NUM_LAYER_TIMEOUT) {
            layer_move(_LAYER0);
        }
    }
}
