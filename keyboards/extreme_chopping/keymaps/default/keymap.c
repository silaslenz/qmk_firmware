#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_5x16(
   KC_GRV,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,    KC_7, KC_8,  KC_9,  KC_0,    KC_MINS,  KC_EQL,  KC_BSPC,
   KC_TAB,  KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,           KC_Y, KC_U,  KC_I,  KC_O,    KC_P,     KC_LBRC, KC_RBRC,KC_ENT,
   KC_ESC,  KC_A,  KC_S,  KC_D,  KC_F,  KC_G,           KC_H, KC_J,  KC_K,  KC_L,    KC_SCLN,  KC_QUOT, KC_SLSH,
   KC_LSFT, KC_NUBS,KC_Z, KC_X,  KC_C,  KC_V,  KC_B,    KC_N, KC_M,  KC_COMM,KC_DOT, KC_SLSH,  KC_RSFT,
   KC_LCTL, KC_LGUI, KC_LALT,  MO(_RAISE), KC_SPC,          KC_SPC,MO(_LOWER),KC_ALGR ,KC_RGUI,KC_APP, KC_RCTL
),

[_RAISE] = LAYOUT_ortho_5x16(
   RESET,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,    KC_F7, KC_F8,  KC_F9,  KC_F10,    KC_F11,  KC_F12,  KC_DEL,
   KC_NO,  KC_MS_BTN1,  KC_MS_U,  KC_MS_BTN3,  KC_NO,  KC_NO,           KC_NO, KC_NO,  KC_NO,  KC_NO,    KC_NO,     KC_NO, KC_NO,KC_NO,
   KC_NO,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_NO,  KC_NO,           KC_HOME, KC_PGDN,  KC_PGUP,  KC_END,    KC_NO,  KC_NO, KC_NO,
   KC_NO, KC_NO, KC_WH_U,KC_WH_D,  KC_NO,  KC_NO,  KC_NO,    KC_NO, KC_NO,  KC_NO,KC_NO, KC_NO,  KC_NO,
   KC_LCTL, KC_LGUI, KC_LALT,  _RAISE, KC_SPC,          KC_SPC,_LOWER,KC_ALGR ,KC_RGUI,KC_APP, KC_RCTL
),
[_LOWER] = LAYOUT_ortho_5x16(
   KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO, KC_NO,  KC_NO,  KC_NO,    KC_NO,  KC_NO,  KC_NO,
   KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,           KC_NO, KC_NO,  KC_NO,  KC_NO,    KC_NO,     KC_NO, KC_NO,KC_NO,
   KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,           KC_LEFT, KC_DOWN,  KC_UP,  KC_RIGHT,    KC_NO,  KC_NO, KC_NO,
   KC_NO, KC_NO,KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO, KC_NO,  KC_NO,KC_NO, KC_NO,  KC_NO,
   KC_LCTL, KC_LGUI, KC_LALT,  _RAISE, KC_SPC,          KC_SPC,_LOWER,KC_ALGR ,KC_RGUI,KC_APP, KC_RCTL
   ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
  }
  return true;
}
