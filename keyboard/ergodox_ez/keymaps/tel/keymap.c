#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // norman-esque layer
#define QWER 1 // qwerty-like layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Norman layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | `      |   1  |   2  |   3  |   4  |   5  |      |           |  6   |   7  |   8  |   9  |   0  |   -  |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   D  |   F  |   K  | QWER |           |      |   J  |   U  |   R  |   O  |   :  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Ctrl*  |   A  |   S  |   E  |   T  |   G  |------|           |------|   Y  |   N  |   I  |   O  |   H  |   '    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift*|   Z  |   X  |   C  |   V  |   B  |      |           |      |   P  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
*   |       |      |      | OPT  | LGUI |                                       | RGUI |   (  |   )  |  {   |  }   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 | SPC  | ENT  |------|       |------|  ENT   | BSPC |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */


[BASE] = KEYMAP(
        // left hand
        KC_TILD,       KC_1, KC_2, KC_3, KC_4, KC_5, KC_NO,
        KC_TAB,        KC_Q, KC_W, KC_D, KC_F, KC_K, KC_FN1,
        CTL_T(KC_ESC), KC_A, KC_S, KC_E, KC_T, KC_G,
        KC_LSFT,       KC_Z, KC_X, KC_C, KC_V, KC_B, KC_NO,

        KC_NO, KC_NO, KC_NO, KC_LALT, KC_LGUI,

                       KC_NO, KC_NO,
                              KC_NO,
              KC_SPC, KC_ENT, KC_NO,

        // right hand
        KC_6,    KC_7, KC_8, KC_9,    KC_0,   KC_MINS, KC_EQL,
        KC_NO,   KC_J, KC_U, KC_R,    KC_L,   KC_SCLN, KC_BSLS,
                 KC_Y, KC_N, KC_I,    KC_O,   KC_H,    KC_QUOT,
        KC_NO,   KC_P, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,

        KC_RGUI, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC,

             KC_NO, KC_NO,
             KC_NO,
             KC_NO, KC_ENT, KC_BSPC
    ),


/* Keymap 0: Qwerty Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | <>     |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  | <>     |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | <>     |   Q  |   W  |   E  |   R  |   T  |  <>  |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | <>     |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|  <>  |           |      |------+------+------+------+------+--------|
 * | <>     |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | <>     |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
*   |       |      |      |      | <>   |                                       | <>   |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 | <>   |      |------|       |------|  <>    | <>   |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */

[QWER] = KEYMAP(
        // left hand
        KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_TRNS,
        KC_TRNS, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_TRNS,
        KC_TRNS, KC_A, KC_S, KC_D, KC_F, KC_G,
        KC_TRNS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_TRNS,

        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                       KC_TRNS, KC_TRNS,
                                KC_TRNS,
              KC_TRNS, KC_TRNS, KC_TRNS,

        // right hand
        KC_TRNS, KC_6, KC_7, KC_8,    KC_9,   KC_0,    KC_TRNS,
        KC_TRNS, KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_BSLS,
                 KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,
        KC_TRNS, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_TRNS,

        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

             KC_TRNS, KC_TRNS,
             KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS
    ),
};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(QWER)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop, mainType, subType, (/?), (/.).
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case QWER:
            ergodox_right_led_1_on();
            break;
        case BASE:
            break;
        default:
            // none
            break;
    }

};
