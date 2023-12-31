/**
 * keymap.c
 */

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_default(
        KC_ESC,     KC_1,     KC_2, KC_3, KC_4, KC_5, KC_6, KC_7,    KC_8,   KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSLS, KC_GRV, KC_HOME,
        KC_TAB,     KC_Q,     KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U,    KC_I,   KC_O,    KC_P, KC_LBRC, KC_RBRC, KC_BSPC, KC_END,
        KC_LCTRL,   KC_A,     KC_S, KC_D, KC_F, KC_G, KC_H, KC_J,    KC_K,   KC_L, KC_SCLN, KC_QUOT,  KC_ENT, KC_DEL,
        KC_LSFT,    KC_Z,     KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,   KC_UP,  MO(1),
        KC_CAPS, KC_LALT,  KC_LGUI,                 KC_SPC,                 KC_RGUI, KC_RALT, KC_LEFT, KC_DOWN, KC_RIGHT),
    [1] = LAYOUT_default(
        KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_INS, KC_DEL, _______,
          KC_CAPS, RGB_TOG, RGB_MOD, _______,  KC_F13,  KC_F14,  KC_F24, _______, KC_PSCR, KC_SCRL, KC_PAUSE, KC_UP, _______, _______, _______,
        _______, KC_VOLD, KC_VOLU, KC_MUTE, KC_EJCT, _______, KC_PAST, KC_PSLS,  KC_HOME,KC_PGUP, KC_LEFT, KC_RIGHT, _______, _______,
        _______, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, KC_PPLS, KC_PMNS, KC_END, KC_PGDN, KC_DOWN, _______, _______, _______,
        QK_BOOT, _______, _______,                   _______,                    _______,_______,          _______, _______, _______),
};