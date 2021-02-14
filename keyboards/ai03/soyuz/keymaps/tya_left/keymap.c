/*
 * ai03 Soyuz VIA Keymap
 *
 * Copyright (C) 2020 Sendy YK <https://mr.sendyyk.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum layer_names {
    _BASE   , // Default Layer
    _MSPROJ , // Layer for MS Project editing
    _VSDBG  , // Layer for debugging with Visual Studio
    _ADJUST   // layer for Keyboard adjusting
};

#define LA_BASE DF(_BASE)
#define LA_MSPR DF(_MSPROJ)
#define LA_VSDB DF(_VSDBG)

#define ADJUST  MO(_ADJUST)

#define TY_MUTE MEH(KC_M)

#define PJ_ODNT  MEH(KC_LEFT)   // Ctrl + Alt + Left  ... Outdent
#define PJ_IDNT  MEH(KC_RGHT)   // Ctrl + Alt + Right ... Indent
#define PJ_RGHT  LALT(KC_RIGHT)
#define PJ_LEFT  LALT(KC_LEFT)
#define PJ_HIDE  LSA(KC_MINS)   // Alt + Shift + (-) ... Hide Sub tasks
#define PJ_ALL   LSA(KC_PAST)   // Alt + Shift + (*) ... Show All Sub tasks
#define PJ_SHOW  LSA(KC_PLUS)   // Alt + Shift + (-) ... Show Sub tasks

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* Default Layer
     * ,----------------------------------.
     * |  ESC  |    /   |    *   |  MUTE  |
     * |-------+--------+--------+--------+
     * |   7   |    8   |    9   |    -   |
     * |-------+--------+--------+--------+
     * |   4   |    5   |    6   |    +   |
     * |-------+--------+--------+--------+
     * |   1   |    2   |    3   |  EQUAL |
     * |-------+--------+--------+--------+
     * | Adjust|    0   |    .   |  Enter |
     * `----------------------------------'
     */
    [_BASE] = LAYOUT_ortho_5x4(
        KC_ESC , KC_PSLS, KC_PAST, TY_MUTE,
        KC_7   , KC_8   , KC_9   , KC_PMNS,
        KC_4   , KC_5   , KC_6   , KC_PPLS,
        KC_1   , KC_2   , KC_3   , KC_PEQL,
        ADJUST , KC_0   , KC_DOT , KC_ENT 
    ),

	/* MS Project
     * ,----------------------------------.
     * |  CUT  |  COPY  |  PASTE |(______)|
     * |-------+--------+--------+--------+
     * |PJ_ODNT|   UP   | PJ_IDNT| PJ_HIDE|
     * |-------+--------+--------+--------+
     * |  LEFT |        |  RIGHT | PJ_SHOW|
     * |-------+--------+--------+--------+
     * |PJ_LEFT|  DOWN  | PJ_RGHT| PJ_ALL |
     * |-------+--------+--------+--------+
     * |(_____)|        |        |(______)|
     * `----------------------------------'
     */
    [_MSPROJ] = LAYOUT_ortho_5x4(
        KC_CUT , KC_COPY, KC_PSTE, _______,
        PJ_ODNT, KC_UP  , PJ_IDNT, PJ_HIDE,
        KC_LEFT, _______, KC_RGHT, PJ_SHOW,
        PJ_LEFT, KC_DOWN, PJ_RGHT, PJ_ALL ,
        _______, _______, _______, _______
    ),

	/* Layer : Debug with Visual Studio
     * ,----------------------------------.
     * |   F10 |   F11  |   F12  |(______)|
     * |-------+--------+--------+--------+
     * |   F7  |   F8   |   F9   |        |
     * |-------+--------+--------+--------+
     * |   F4  |   F5   |   F6   |        |
     * |-------+--------+--------+--------+
     * |   F1  |   F2   |   F3   |        |
     * |-------+--------+--------+--------+
     * |(_____)|        |        |(______)|
     * `----------------------------------'
     */
    [_VSDBG] = LAYOUT_ortho_5x4(
        KC_F10 , KC_F11 , KC_F12 , _______,
        KC_F7  , KC_F8  , KC_F9  , _______,
        KC_F4  , KC_F5  , KC_F6  , _______,
        KC_F1  , KC_F2  , KC_F3  , _______,
        _______, _______, _______, _______
    ),
	/* Adjust Layer
     * ,----------------------------------.
     * |       |        |        |        |
     * |-------+--------+--------+--------+
     * |       |        |        |        |
     * |-------+--------+--------+--------+
     * |       |        |        |        |
     * |-------+--------+--------+--------+
     * |       |        |        |        |
     * |-------+--------+--------+--------+
     * |       |  BASE  | MSPROJ |  VSDBG |
     * `----------------------------------'
     */
    [_ADJUST] = LAYOUT_ortho_5x4(
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, LA_BASE, LA_MSPR, LA_VSDB
    )
};
