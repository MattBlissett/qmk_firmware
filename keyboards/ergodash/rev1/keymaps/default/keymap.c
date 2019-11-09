#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1

enum custom_keycodes {
  VOLUME = SAFE_RANGE,
  MEDIA
};

#define CTRL_ENT RCTL_T(KC_ENT)
#define SFT_CMPS RSFT_T(KC_APP)
#define ALT_PGDN LALT_T(KC_PGDN)
#define ALT_LEFT RALT_T(KC_LEFT)
#define LOW_CAPS LT(_LOWER, KC_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty for Dvorak
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |VOLUME|   1  |   2  |   3  |   4  |   5  |   `  |                    |   ]  |   6  |   7  |   8  |   9  |   0  |MEDIA |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   -  |                    |   =  |   Y  |   U  |   I  |   O  |   P  |  [   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  \   |   A  |   S  |   D  |   F  |   G  |  GUI |                    |  GUI |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |  ESC |                    |  Del |   N  |   M  |   ,  |   .  |   /  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |PageUp|PageDn|PageUp|AltPgD|||||||| Bksp | Ctrl |LowCap|||||||| Lower|^/Entr| Space||||||||Alt/← |   →  |  Up  | Down |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT(
        VOLUME,       KC_1,    KC_2,     KC_3,    KC_4,    KC_5,   KC_GRV,                          KC_RBRC,     KC_6,   KC_7,     KC_8,    KC_9,     KC_0,    MEDIA,
        KC_TAB,       KC_Q,    KC_W,     KC_E,    KC_R,    KC_T,  KC_MINS,                           KC_EQL,     KC_Y,   KC_U,     KC_I,    KC_O,     KC_P,  KC_LBRC,
       KC_BSLS,       KC_A,    KC_S,     KC_D,    KC_F,    KC_G,  KC_LGUI,                          KC_RGUI,     KC_H,   KC_J,     KC_K,    KC_L,  KC_SCLN,  KC_QUOT,
       KC_LSFT,       KC_Z,    KC_X,     KC_C,    KC_V,    KC_B,            KC_ESC,        KC_DEL,               KC_N,   KC_M,  KC_COMM,  KC_DOT,  KC_SLSH, SFT_CMPS,
    C(KC_PGUP), C(KC_PGDN), KC_PGUP, ALT_PGDN,          KC_BSPC, KC_LCTL, LOW_CAPS,    MO(_LOWER), CTRL_ENT, KC_SPC,           ALT_LEFT,   KC_UP,  KC_DOWN, KC_RIGHT
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | Mute |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |                    |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 | Stop |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |Pscree|      |      |                    |      |      |xNUM7 |xNUM8 |xNUM9 |      |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |Insert|      |                    |      |      |xNUM4 |xNUM5 |xNUM6 |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|      |      |      |      |      |      |      |      |      |      |      |xNUM1 |xNUM2 |xNUM3 |      | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      | Space|      ||||||||      | Space|      |||||||| Home |PageUp|PageDn| End  |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    KC_MUTE,  KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,  KC_F11,                         KC_F12, KC_F6,        KC_F7,      KC_F8,      KC_F9,  KC_F10, KC_MSTP,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, G(KC_KP_7), G(KC_KP_8), G(KC_KP_9), XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_INS, XXXXXXX,                        XXXXXXX, XXXXXXX, G(KC_KP_4), G(KC_KP_5), G(KC_KP_6), XXXXXXX, XXXXXXX,
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX,     XXXXXXX,          XXXXXXX, G(KC_KP_1), G(KC_KP_2), G(KC_KP_3), XXXXXXX, KC_RSFT,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,   KC_SPC ,XXXXXXX,     XXXXXXX, KC_SPC , XXXXXXX,                KC_HOME,    KC_PGUP, KC_PGDN,  KC_END
  )

};

static uint16_t key_timer;
static bool key_repeat;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case VOLUME:
            if (record->event.pressed) {
                if (timer_elapsed(key_timer) > 300) {
                    key_repeat = false;
                }
                key_timer = timer_read();  // start the timer
                return false;              // return false to keep the 1 from being sent
            } else {
                // If key was held
                if (key_repeat || timer_elapsed(key_timer) > 150) {
                    register_code(KC_AUDIO_VOL_UP);
                    unregister_code(KC_AUDIO_VOL_UP);
                    key_repeat = true;
                    key_timer = timer_read();
                    return false;
                } else {
                    // if key was tapped
                    register_code(KC_AUDIO_VOL_DOWN);
                    unregister_code(KC_AUDIO_VOL_DOWN);
                    key_repeat = false;
                    return false;
                }
            }
            break;
        case MEDIA:
            if (record->event.pressed) {
                key_timer = timer_read();  // start the timer
                return false;              // return false to keep the 1 from being sent
            } else {
                // If key was held a long time
                if (timer_elapsed(key_timer) > 500) {
                    register_code(KC_LGUI);
                    register_code(KC_MEDIA_STOP);
                    unregister_code(KC_MEDIA_STOP);
                    unregister_code(KC_LGUI);
                    return false;
                //} else if (timer_elapsed(key_timer) > 500) {
                //    register_code(KC_MEDIA_STOP);
                //    unregister_code(KC_MEDIA_STOP);
                //    return false;
                } else if (timer_elapsed(key_timer) > 150) {
                    register_code(KC_MEDIA_PLAY_PAUSE);
                    unregister_code(KC_MEDIA_PLAY_PAUSE);
                    return false;
                } else {
                    // if key was tapped
                    register_code(KC_MEDIA_NEXT_TRACK);
                    unregister_code(KC_MEDIA_NEXT_TRACK);
                    return false;
                }
            }
            break;
    }
    return true;
};

