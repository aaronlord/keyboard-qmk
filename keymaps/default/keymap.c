// Copyright 2022 mjohns
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    BASE,
    SYMBOLS,
    NAV,
};

// MACROS
enum custom_keycodes {
    M_ARW = SAFE_RANGE,
    M_DARW,
    M_SPSH,
    M_EQ2X,
    M_DEQ2X,
    M_EQ3X,
    M_DEQ3X,
    M_CUT,
    M_COPY,
    M_PASTE,
    M_UNDO
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case M_CUT:
            if (record->event.pressed) {
                tap_code16(LGUI(KC_X));
            }
            return false;

        case M_COPY:
            if (record->event.pressed) {
                tap_code16(LGUI(KC_C));
            }
            return false;

        case M_PASTE:
            if (record->event.pressed) {
                tap_code16(LGUI(KC_V));
            }
            return false;

        case M_UNDO:
            if (record->event.pressed) {
                tap_code16(LGUI(KC_Z));
            }
            return false;

        case M_ARW:
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            return false;

        case M_DARW:
            if (record->event.pressed) {
                SEND_STRING("=>");
            }
            return false;

        case M_SPSH:
            if (record->event.pressed) {
                SEND_STRING("<=>");
            }
            return false;

        case M_EQ2X:
            if (record->event.pressed) {
                SEND_STRING("==");
            }
            return false;

        case M_DEQ2X:
            if (record->event.pressed) {
                SEND_STRING("!==");
            }
            return false;

        case M_EQ3X:
            if (record->event.pressed) {
                SEND_STRING("===");
            }
            return false;

        case M_DEQ3X:
            if (record->event.pressed) {
                SEND_STRING("!==");
            }
            return false;
    }
    return true;
}

#define NAV_DEL LT(NAV, KC_DEL)
#define CTL_ESC LCTL_T(KC_ESC)

// Home row mods
#define GUI_A    LGUI_T(KC_A)
#define ALT_S    LALT_T(KC_S)
#define CTL_D    LCTL_T(KC_D)
#define SFT_F    LSFT_T(KC_F)
#define SFT_J    RSFT_T(KC_J)
#define CTL_K    RCTL_T(KC_K)
#define ALT_L    LALT_T(KC_L)
#define GUI_SCLN RGUI_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                      KC_6,    KC_7,    KC_8,    KC_9,   KC_0,     KC_HOME,
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                      KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,     KC_END,
        KC_ESC,    GUI_A,   ALT_S,   CTL_D,   SFT_F,   KC_G,                                      KC_H,    SFT_J,   CTL_K,   ALT_L,  GUI_SCLN, KC_QUOT,
        KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                      KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH,  KC_RSFT,
                   M_UNDO,  M_CUT,   M_COPY,  M_PASTE,                                                   KC_MINS, KC_EQL,  KC_GRV, S(KC_NUHS),
                                                               KC_CAPS, KC_PSCR,       KC_LGUI, CW_TOGG,
                                                                        KC_LCTL,       KC_LALT,
                                                 KC_BSPC, OSL(SYMBOLS), NAV_DEL,       OSL(NAV), KC_ENT, KC_SPC
    ),

    [SYMBOLS] = LAYOUT(
        KC_GRV,   S(KC_1),    S(KC_2),   S(KC_3),    S(KC_4),  S(KC_5),                                S(KC_6),   S(KC_7),  S(KC_8),    S(KC_9),   S(KC_0),    XXXXXXX,
        XXXXXXX,  KC_QUOT,    XXXXXXX,   KC_EQL,     XXXXXXX,  S(KC_NUHS),                             XXXXXXX,   KC_UNDS,  KC_TILD,    XXXXXXX,   S(KC_EQL),  XXXXXXX,
        XXXXXXX,  S(KC_QUOT), KC_LBRC,   S(KC_LBRC), S(KC_9),  KC_NUBS,                                KC_BSLS,   S(KC_0),  S(KC_RBRC), KC_RBRC,   S(KC_SCLN), S(KC_2),
        XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,    XXXXXXX,  KC_GRV,                                 S(KC_NUBS), KC_MINS, S(KC_COMM), S(KC_DOT), S(KC_SLSH), XXXXXXX,
                  M_DEQ3X,    M_EQ3X,    M_DEQ2X,    M_EQ2X,                                                     XXXXXXX,   M_ARW,      M_DARW,    M_SPSH,
                                                               XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX,
                                                                        XXXXXXX,     XXXXXXX,
                                                      XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [NAV] = LAYOUT(
        // XXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_END,  XXXXXXX,                                       XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, KC_HOME,      XXXXXXX,
        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                         KC_F6,   KC_F7,         KC_F8,   KC_F9,   KC_F10,       KC_F11,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, KC_PGUP,       XXXXXXX, XXXXXXX, S(C(KC_EQL)), XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN, XXXXXXX, XXXXXXX,                                       KC_LEFT, KC_DOWN,       KC_UP,   KC_RGHT, XXXXXXX,      XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, S(C(KC_MINS)), XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                                         XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX,
                                                               XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,
                                                                        XXXXXXX,   XXXXXXX,
                                                      XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX
    )
};
