// Copyright 2022 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        LCTL_T(KC_A),    LSFT_T(KC_S),    LALT_T(KC_D),    LGUI_T(KC_F),    KC_G,                               KC_H,    LGUI_T(KC_J),    LALT_T(KC_K),    LSFT_T(KC_L),    LCTL_T(KC_SCLN),
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                                    KC_TAB, MO(1), MO(1),           KC_SPC,  KC_SPC,  MO(2)
    ),
    [1] = LAYOUT_split_3x5_3(
        KC_1, KC_2, KC_3, KC_4, KC_5,                            KC_6, KC_7, KC_8, KC_9, KC_0,
        KC_TRNS, KC_TRNS, KC_ESC, KC_BSPC, KC_LBRC,                            KC_RBRC, KC_BSLS, KC_QUOT, KC_TRNS, KC_TRNS,
        KC_MINS, KC_EQL, KC_GRV, KC_DEL, S(KC_9),                            S(KC_0), _______, _______, _______, KC_ENT,
                                    _______, _______, _______,          _______, _______, _______                                          
    ),
    [2] = LAYOUT_split_3x5_3(
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                            _______, KC_VOLU, KC_VOLD, KC_MUTE, _______,
        _______, _______, _______, _______, _______,                            _______, KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT,
        _______, _______, _______, _______, _______,                            _______, KC_MPRV, KC_MPLY, KC_MNXT, _______,
                                   _______, _______, _______,          _______, _______, _______
    ),
    [3] = LAYOUT_split_3x5_3(
        _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______,
                                   _______, _______, _______,          _______, _______, _______
    )
};
