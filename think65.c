/* Copyright 2019 MechMerlin
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#define LAYER_LED_RANGE              0, 2
#define BADGE_LED_OFF                0, 0, 0

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t h = rgblight_get_hue();
    uint8_t s = rgblight_get_sat();
    uint8_t v = rgblight_get_val();

    if(IS_LAYER_ON_STATE(state, 1)) { 
        rgblight_sethsv_range(1, s, v, LAYER_LED_RANGE);
    } 
    else { 
        rgblight_sethsv_range(h, s, v, LAYER_LED_RANGE);
    }
    return state; 
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_CAPS:
            if (!record->event.pressed) {
                uint8_t h = rgblight_get_hue();
                uint8_t s = rgblight_get_sat();
                uint8_t v = rgblight_get_val();
                host_keyboard_led_state().caps_lock ? rgblight_sethsv_range(0, s, v, LAYER_LED_RANGE) : rgblight_sethsv_range(h, s, v, LAYER_LED_RANGE);
            }
            break;
        default:
            break;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_all(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV, KC_HOME,
        KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC, KC_END,
        KC_LCTRL,         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,           _______,
        KC_LSFT, KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   _______,
        KC_CAPS, KC_LALT, KC_LGUI,                      KC_SPC,                          KC_RGUI, MO(1),                     KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT_all(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,   KC_INS,  KC_DEL,  _______,
        KC_CAPS,          RGB_TOG, RGB_MOD, _______, KC_F13,  KC_F14,  KC_F24,  _______, KC_PSCR, KC_SCRL, KC_PAUSE, KC_UP,    _______, _______, _______,
        _______,          KC_VOLD, KC_VOLU, KC_MUTE, KC_EJCT, _______, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT,  KC_RIGHT, _______,          _______,
        _______, _______, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, KC_PPLS, KC_PMNS, KC_END,  KC_PGDN, KC_DOWN,  _______,          _______, _______,
        QK_BOOT, _______, _______,                      _______,                         _______, _______,                     _______, _______, _______
    ),
};
