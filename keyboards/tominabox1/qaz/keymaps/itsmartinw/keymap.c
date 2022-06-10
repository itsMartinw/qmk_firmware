#include QMK_KEYBOARD_H
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM  150

enum layers{
  _BASE,
  _NUM_SYM,
  _NAV
};

enum combo_events {
  COMBO_BSPC,
  COMBO_NUMBAK,
  COMBO_TAB,
  COMBO_ESC,
  COMBO_DEL,
};

#define KC_NUM_SPC LT(_NUM_SYM, KC_SPC)
#define KC_GA LGUI_T(KC_A)
#define KC_AS LALT_T(KC_S)
#define KC_CD LCTL_T(KC_D)
#define KC_SF LSFT_T(KC_F)
#define KC_SJ RSFT_T(KC_J)
#define KC_CK RCTL_T(KC_K)
#define KC_AL RALT_T(KC_L)
#define KC_GSCLN RGUI_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_space(
    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,    KC_I,   KC_O,     KC_P,
    KC_A,  KC_S,  KC_D,  KC_F,   KC_G,   KC_H,  KC_J,  KC_K,  KC_L, RCTL_T(KC_ENT),
    LSFT_T(KC_Z),   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M, KC_COMM, RSFT_T(KC_DOT),
    KC_LCTL, KC_LGUI, KC_LALT, LT(2,KC_BSPC), LT(1,KC_SPACE), KC_RALT, KC_RGUI, MO(3)
  ),

  /* Keymap Default Layer
   * ,--------------------------------------------------------------------------------.
   * |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |    P    |
   * |---------------------------------------------------------------------------------|
   * |     A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   | Enter |
   * |---------------------------------------------------------------------------------|
   * |       Z     |   X   |   C   |   V   |   B   |   N   |   M   |   <   |     >     |
   * |---------------------------------------------------------------------------------|
   * | Ctrl  |  Win  |  Alt  | Backspace L(2) |  Space L(1)   |  Alt  |  Win  |  Fn(3) |
   * `---------------------------------------------------------------------------------'
   */

  [1] = LAYOUT_split_space(
    KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
    KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    LSFT_T(KC_BSLS), KC_MINS, KC_EQL, KC_LBRC, KC_GRV, KC_RBRC, KC_SCLN, KC_QUOT, RSFT_T(KC_SLSH),
    KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  /* Keymap L1 - Needs updating once I'm happy with the firmware
   * ,--------------------------------------------------------------------------------.
   * |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |    0    |
   * |---------------------------------------------------------------------------------|
   * |     ~   |   \   |   -   |   =   |   [   |   ]   |   ;   |   '   |bspace | Enter |
   * |---------------------------------------------------------------------------------|
   * |             |       |       |       |       |       |       |       |           |
   * |---------------------------------------------------------------------------------|
   * |       |       |       |     Delete     |               |       |       |        |
   * `---------------------------------------------------------------------------------'
   */

  [2] = LAYOUT_split_space(
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_HOME, KC_UP, KC_END, KC_PGUP,
    KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PSCR,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
  ),

   /* Keymap L2 - TODO
   * ,--------------------------------------------------------------------------------.
   * |  F1   |  F2   |  F3   |  F4   |  F5   |  F6   |   7   |   8   |   9   |    0    |
   * |---------------------------------------------------------------------------------|
   * |    F7   |  F8   |  F9   |  F10  |  F11  |  F12  |       |       |       |       |
   * |---------------------------------------------------------------------------------|
   * |             |       |       |       |       |       |       |       |           |
   * |---------------------------------------------------------------------------------|
   * |       |       |       |                |               |       |       |        |
   * `---------------------------------------------------------------------------------'
   */

  [3] = LAYOUT_split_space(
    KC_ESC, KC_NO, KC_MPLY, KC_MFFD, KC_NO, KC_NO, KC_HOME, KC_UP, KC_END, KC_PGUP,
    KC_TAB, KC_VOLD, KC_VOLU, KC_MUTE, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS
  ),

    /* Keymap L2 - TODO
   * ,--------------------------------------------------------------------------------.
   * |  F1   |  F2   |  F3   |  F4   |  F5   |  F6   |   7   |   8   |   9   |    0    |
   * |---------------------------------------------------------------------------------|
   * |    F7   |  F8   |  F9   |  F10  |  F11  |  F12  |       |       |       |       |
   * |---------------------------------------------------------------------------------|
   * |             |       |       |       |       |       |       |       |           |
   * |---------------------------------------------------------------------------------|
   * |       |       |       |                |               |       |       |        |
   * `---------------------------------------------------------------------------------'
   */
};


#ifdef COMBO_ENABLE
//const uint16_t PROGMEM combo_bspc[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_numbak[] = {KC_0, KC_9, COMBO_END};
//const uint16_t PROGMEM combo_tab[] = {KC_Q, KC_W, COMBO_END};
//const uint16_t PROGMEM combo_esc[] = {KC_E, KC_W, COMBO_END};
const uint16_t PROGMEM combo_del[] = {KC_MINS, KC_EQL, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
//  [COMBO_BSPC] = COMBO(combo_bspc,KC_BSPC),
  [COMBO_NUMBAK] = COMBO(combo_numbak,KC_BSPC),
//  [COMBO_TAB] = COMBO(combo_tab,KC_TAB),
//  [COMBO_ESC] = COMBO(combo_esc,KC_ESC),
  [COMBO_DEL] = COMBO(combo_del,KC_DEL),

};
#endif
