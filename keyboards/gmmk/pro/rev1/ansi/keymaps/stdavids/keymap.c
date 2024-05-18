#include QMK_KEYBOARD_H

bool g_dbg_state = false;

extern void rgb_matrix_update_pwm_buffers(void);


// This code should only work on devices that use the aw20216s LED driver. This code is based on the
// rgb_matrix_set_color function found in qmk_firmware/drivers/led/aw20216s.c.
uint8_t g_pwm_buffer[AW20216S_DRIVER_COUNT][216]; // AW20216S_PWM_REGISTER_COUNT = 216
RGB rgb_matrix_get_color(int index)
{
    RGB rgb;
    aw20216s_led_t led;
    memcpy_P(&led, (&g_aw20216s_leds[index]), sizeof(led));
    rgb.r = g_pwm_buffer[led.driver][led.r];
    rgb.g = g_pwm_buffer[led.driver][led.g];
    rgb.b = g_pwm_buffer[led.driver][led.b];
    return rgb;
}


void rgb_matrix_invert_color(int index)
{
    RGB current, inverse;
    current = rgb_matrix_get_color(index);
    inverse.r = UINT8_MAX - current.r;
    inverse.g = UINT8_MAX - current.g;
    inverse.b = UINT8_MAX - current.b;
    rgb_matrix_set_color(index, inverse.r, inverse.g, inverse.b);
}


enum custom_keycodes {
    STD_DBG = SAFE_RANGE,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // BASE LAYER
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    // FUNCTION LAYER
    [1] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  EE_CLR,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, STD_DBG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX,
        XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, NK_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                            XXXXXXX, _______,   MO(2), XXXXXXX, XXXXXXX, XXXXXXX
    ),

    // RGB LAYER
    [2] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          RGB_TOG,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, RGB_SPD, RGB_SAI, RGB_SPI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, RGB_HUD, RGB_SAD, RGB_HUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX,
        XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                            XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
    ),

};


const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW( KC_VOLD, KC_VOLU ) }, // BASE LAYER
    [1] = { ENCODER_CCW_CW( XXXXXXX, XXXXXXX ) }, // FUNCTION LAYER
    [2] = { ENCODER_CCW_CW( RGB_VAD, RGB_VAI ) }  // RGB LAYER
};


bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode) {
        case STD_DBG:
            if (record->event.pressed) {
                // on pressed
                g_dbg_state = !g_dbg_state;
            } else {
                // on released
            }
            break;
    }
    return true;
}


bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max)
{
    uint8_t layer = get_highest_layer(layer_state);

    if (g_dbg_state) {
        rgb_matrix_set_color(RGB_IDX_LSIDE_0, RGB_RED);
        rgb_matrix_set_color(RGB_IDX_LSIDE_1, RGB_RED);
        rgb_matrix_set_color(RGB_IDX_LSIDE_2, RGB_YELLOW);
        rgb_matrix_set_color(RGB_IDX_LSIDE_3, RGB_YELLOW);
        rgb_matrix_set_color(RGB_IDX_LSIDE_4, RGB_RED);
        rgb_matrix_set_color(RGB_IDX_LSIDE_5, RGB_RED);
        rgb_matrix_set_color(RGB_IDX_LSIDE_6, RGB_YELLOW);
        rgb_matrix_set_color(RGB_IDX_LSIDE_7, RGB_YELLOW);

        rgb_matrix_set_color(RGB_IDX_RSIDE_0, RGB_RED);
        rgb_matrix_set_color(RGB_IDX_RSIDE_1, RGB_RED);
        rgb_matrix_set_color(RGB_IDX_RSIDE_2, RGB_YELLOW);
        rgb_matrix_set_color(RGB_IDX_RSIDE_3, RGB_YELLOW);
        rgb_matrix_set_color(RGB_IDX_RSIDE_4, RGB_RED);
        rgb_matrix_set_color(RGB_IDX_RSIDE_5, RGB_RED);
        rgb_matrix_set_color(RGB_IDX_RSIDE_6, RGB_YELLOW);
        rgb_matrix_set_color(RGB_IDX_RSIDE_7, RGB_YELLOW);

        rgb_matrix_set_color(RGB_IDX_F5,  255,0,255);
        rgb_matrix_set_color(RGB_IDX_F6,  255,0,255);
        rgb_matrix_set_color(RGB_IDX_F7,  255,0,255);
        rgb_matrix_set_color(RGB_IDX_F8,  255,0,255);
        rgb_matrix_set_color(RGB_IDX_F9,  255,0,255);
        rgb_matrix_set_color(RGB_IDX_F10, 255,0,255);
        rgb_matrix_set_color(RGB_IDX_F11, 255,0,255);
        rgb_matrix_set_color(RGB_IDX_F12, 255,0,255);

        uint8_t val = 0;
        if (layer == 0) {
            val = rgb_matrix_get_hue();
        } else if (layer == 1) {
            val = rgb_matrix_get_sat();
        } else if (layer == 2) {
            val = rgb_matrix_get_speed();
        }

        if ((val >> 0) & 0x1) { rgb_matrix_invert_color(RGB_IDX_F5); }
        if ((val >> 1) & 0x1) { rgb_matrix_invert_color(RGB_IDX_F6); }
        if ((val >> 2) & 0x1) { rgb_matrix_invert_color(RGB_IDX_F7); }
        if ((val >> 3) & 0x1) { rgb_matrix_invert_color(RGB_IDX_F8); }
        if ((val >> 4) & 0x1) { rgb_matrix_invert_color(RGB_IDX_F9); }
        if ((val >> 5) & 0x1) { rgb_matrix_invert_color(RGB_IDX_F10); }
        if ((val >> 6) & 0x1) { rgb_matrix_invert_color(RGB_IDX_F11); }
        if ((val >> 7) & 0x1) { rgb_matrix_invert_color(RGB_IDX_F12); }
    }

    // Invert the capslock key when capslock is enabled
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color_all(RGB_RED);
    }

    // When off of the base layer, highlight all bound keys
    if (layer > 0) {
        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index = g_led_config.matrix_co[row][col];
            if (index >= led_min && index < led_max && index != NO_LED) {
                if (keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                    rgb_matrix_invert_color(index);
                }
            }
        }}
    }

    return false;
}


bool shutdown_user(bool jump_to_bootloader)
{
    rgb_matrix_set_color_all(RGB_OFF);
    if (jump_to_bootloader) {
        rgb_matrix_set_color(RGB_IDX_LSIDE_0, RGB_RED);
        rgb_matrix_set_color(RGB_IDX_LSIDE_1, RGB_RED);
        rgb_matrix_set_color(RGB_IDX_LSIDE_2, RGB_YELLOW);
        rgb_matrix_set_color(RGB_IDX_LSIDE_3, RGB_YELLOW);
        rgb_matrix_set_color(RGB_IDX_LSIDE_4, RGB_RED);
        rgb_matrix_set_color(RGB_IDX_LSIDE_5, RGB_RED);
        rgb_matrix_set_color(RGB_IDX_LSIDE_6, RGB_YELLOW);
        rgb_matrix_set_color(RGB_IDX_LSIDE_7, RGB_YELLOW);

        rgb_matrix_set_color(RGB_IDX_RSIDE_0, RGB_RED);
        rgb_matrix_set_color(RGB_IDX_RSIDE_1, RGB_RED);
        rgb_matrix_set_color(RGB_IDX_RSIDE_2, RGB_YELLOW);
        rgb_matrix_set_color(RGB_IDX_RSIDE_3, RGB_YELLOW);
        rgb_matrix_set_color(RGB_IDX_RSIDE_4, RGB_RED);
        rgb_matrix_set_color(RGB_IDX_RSIDE_5, RGB_RED);
        rgb_matrix_set_color(RGB_IDX_RSIDE_6, RGB_YELLOW);
        rgb_matrix_set_color(RGB_IDX_RSIDE_7, RGB_YELLOW);
    }
    rgb_matrix_update_pwm_buffers();
    return false;
}
