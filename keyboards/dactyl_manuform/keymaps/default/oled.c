

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    // Host Keyboard LED Status
    //if (is_keyboard_master()) {
    //    oled_write_P(PSTR("MASTE\n"), false);
    //} else {
    //    oled_write_P(PSTR("SLAVE\n"), false);
    //}
    return false;
}
#endif
