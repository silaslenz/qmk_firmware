#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
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
[_QWERTY] = LAYOUT_ortho_7x14(
   KC_NO,   KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,\
   KC_NO,   KC_GRAVE,KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINUS, KC_EQUAL,\
   KC_NO,   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRACKET,KC_RBRACKET,\
   KC_NO,   KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCOLON,KC_QUOTE, KC_BSLASH,\
   KC_NO,   KC_LCTRL,KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMMA,KC_DOT,  KC_SLASH, KC_NO,    KC_RSHIFT,\
   KC_NO,   RAISE,   KC_LGUI, KC_LALT, KC_RALT,KC_HOME,KC_PSCREEN,KC_PAUSE,KC_PGUP ,KC_RGUI,KC_APP,  KC_RALT,  KC_UP, KC_RCTRL,\
   KC_NO,   KC_NO,   KC_NO,   KC_SPACE,KC_DEL,  KC_END,  KC_NO,   KC_NO,   KC_PGDOWN,KC_BSPACE,KC_ENTER,KC_LEFT,KC_DOWN, KC_RIGHT\
),

[_RAISE] = LAYOUT_ortho_7x14(\
   KC_NO,   KC_ESC,  KC_AUDIO_VOL_DOWN,   KC_AUDIO_VOL_UP,   KC_F3,   KC_F4,   KC_MEDIA_PLAY_PAUSE,   KC_MEDIA_PREV_TRACK,   KC_MEDIA_NEXT_TRACK,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,\
   KC_NO,   KC_GRAVE,KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINUS, KC_EQUAL,\
   KC_NO,   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRACKET,KC_RBRACKET,\
   KC_NO,   KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCOLON,KC_QUOTE, KC_BSLASH,\
   KC_NO,   KC_LCTRL,KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMMA,KC_DOT,  KC_SLASH, KC_NO,    KC_RSHIFT,\
   KC_NO,   RAISE,   RESET,  KC_LALT, KC_RALT, KC_PSCREEN,KC_HOME,KC_PGUP,KC_PAUSE,KC_APP,  KC_MENU, KC_RALT,  KC_UP, KC_RCTRL,\
   KC_NO,   KC_NO,   KC_NO,   KC_SPACE,KC_DEL,  KC_END,  KC_NO,   KC_NO,   KC_PGDOWN,KC_BSPACE,KC_ENTER,KC_LEFT,KC_DOWN, KC_RIGHT\
)
};


uint32_t layer_state_set_user(uint32_t state) {
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
