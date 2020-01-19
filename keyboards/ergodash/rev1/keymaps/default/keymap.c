#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1

enum custom_keycodes {
  VOLUME = SAFE_RANGE,
  MEDIA1,
  MEDIA2,
  OS_TAB
};

// Mod-Tap shortcuts
#define CTRL_ENT RCTL_T(KC_ENT)
#define ALT_PGDN LALT_T(KC_PGDN)
#define ALT_LEFT RALT_T(KC_LEFT)
#define OS_CMPSE LGUI_T(KC_APP)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty for Dvorak
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |VOLUME|   1  |   2  |   3  |   4  |   5  |   6  |                    |MEDIA1|   7  |   8  |   9  |   0  |   -  |  =   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   `  |                    |   ]  |   Y  |   U  |   I  |   O  |   P  |  [   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  \   |   A  |   S  |   D  |   F  |   G  |OS-Tab|                    |OS-Cps|   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |  ESC |                    |  Del |   N  |   M  |   ,  |   .  |   /  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |PageUp|PageDn|PageUp|AltPgD|||||||| Bksp | Ctrl |Lower |||||||| Lower|^/Entr| Space||||||||Alt/← |  Up  | Down | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT(
        VOLUME,       KC_1,    KC_2,     KC_3,    KC_4,    KC_5,     KC_6,                             MEDIA1,     KC_7,   KC_8,     KC_9,    KC_0,  KC_MINS,   KC_EQL,
        KC_TAB,       KC_Q,    KC_W,     KC_E,    KC_R,    KC_T,   KC_GRV,                            KC_RBRC,     KC_Y,   KC_U,     KC_I,    KC_O,     KC_P,  KC_LBRC,
       KC_BSLS,       KC_A,    KC_S,     KC_D,    KC_F,    KC_G,   OS_TAB,                           OS_CMPSE,     KC_H,   KC_J,     KC_K,    KC_L,  KC_SCLN,  KC_QUOT,
       KC_LSFT,       KC_Z,    KC_X,     KC_C,    KC_V,    KC_B,              KC_ESC,        KC_DEL,               KC_N,   KC_M,  KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT,
    C(KC_PGUP), C(KC_PGDN), KC_PGUP, ALT_PGDN,          KC_BSPC,  KC_LCTL,MO(_LOWER),    MO(_LOWER), CTRL_ENT,   KC_SPC,         ALT_LEFT,   KC_UP,  KC_DOWN, KC_RIGHT
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | Mute |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |MEDIA2|  F7  |  F8  |  F9  | F10  | F11  | F12  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |Pscree|      |      |                    |      |      |xNUM7 |xNUM8 |xNUM9 |      |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Left |  Up  | Down |Right |      |Insert|      |                    |CapsLk|      |xNUM4 |xNUM5 |xNUM6 |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|      |      |      |CapsLk|      |      |      |      |      |      |      |xNUM1 |xNUM2 |xNUM3 |      | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      |||||||| Home |PageUp|PageDn| End  |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    KC_MUTE,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                         MEDIA2, KC_F7,        KC_F8,      KC_F9,     KC_F10,  KC_F11,  KC_F12,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, DM_REC2, XXXXXXX,                        XXXXXXX, DM_REC1, G(KC_KP_7), G(KC_KP_8), G(KC_KP_9), XXXXXXX, XXXXXXX,
    XXXXXXX, KC_LEFT,   KC_UP, KC_DOWN,KC_RIGHT,  KC_INS, XXXXXXX,                        KC_CAPS, DM_RSTP, G(KC_KP_4), G(KC_KP_5), G(KC_KP_6), XXXXXXX, XXXXXXX,
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS, DM_PLY2,           XXXXXXX,     XXXXXXX,          DM_PLY1, G(KC_KP_1), G(KC_KP_2), G(KC_KP_3), XXXXXXX, KC_RSFT,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX,  XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX,                KC_HOME,    KC_PGUP, KC_PGDN,  KC_END
  )

};

// Add function keys F1-F12 as combinations of the number and the key below.
const uint16_t PROGMEM  c_f1[] = {KC_Q,       KC_1, COMBO_END};
const uint16_t PROGMEM  c_f2[] = {KC_W,       KC_2, COMBO_END};
const uint16_t PROGMEM  c_f3[] = {KC_E,       KC_3, COMBO_END};
const uint16_t PROGMEM  c_f4[] = {KC_R,       KC_4, COMBO_END};
const uint16_t PROGMEM  c_f5[] = {KC_T,       KC_5, COMBO_END};
const uint16_t PROGMEM  c_f6[] = {KC_GRV,     KC_6, COMBO_END};

const uint16_t PROGMEM  c_f7[] = {KC_Y,       KC_7, COMBO_END};
const uint16_t PROGMEM  c_f8[] = {KC_U,       KC_8, COMBO_END};
const uint16_t PROGMEM  c_f9[] = {KC_I,       KC_9, COMBO_END};
const uint16_t PROGMEM c_f10[] = {KC_O,       KC_0, COMBO_END};
const uint16_t PROGMEM c_f11[] = {KC_P,    KC_MINS, COMBO_END};
const uint16_t PROGMEM c_f12[] = {KC_LBRC,  KC_EQL, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO( c_f1,  KC_F1),
    COMBO( c_f2,  KC_F2),
    COMBO( c_f3,  KC_F3),
    COMBO( c_f4,  KC_F4),
    COMBO( c_f5,  KC_F5),
    COMBO( c_f6,  KC_F6),
    COMBO( c_f7,  KC_F7),
    COMBO( c_f8,  KC_F8),
    COMBO( c_f9,  KC_F9),
    COMBO(c_f10, KC_F10),
    COMBO(c_f11, KC_F11),
    COMBO(c_f12, KC_F12)
};

static uint16_t key_timer;
static bool key_repeat;
static bool window_switching;
static bool other_key_pressed = true;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case VOLUME:
            other_key_pressed = true;

            if (record->event.pressed) {
                if (timer_elapsed(key_timer) > 300) {
                    key_repeat = false;
                }
                key_timer = timer_read();
                return false;
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

        case MEDIA1:
            other_key_pressed = true;

            if (record->event.pressed) {
                key_timer = timer_read();
                return false;
            } else {
                if (timer_elapsed(key_timer) > 500) {
                    // if key was long-pressed
                    register_code(KC_LGUI);
                    register_code(KC_MEDIA_STOP);
                    unregister_code(KC_MEDIA_STOP);
                    unregister_code(KC_LGUI);
                    return false;
                } else if (timer_elapsed(key_timer) > 150) {
                    // if key was pressed "firmly"
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

         case MEDIA2:
            other_key_pressed = true;

            if (record->event.pressed) {
                key_timer = timer_read();
                return false;
            } else {
                if (timer_elapsed(key_timer) > 500) {
                    // if key was long-pressed
                    register_code(KC_LGUI);
                    register_code(KC_DEL);
                    unregister_code(KC_DEL);
                    unregister_code(KC_LGUI);
                    return false;
                } else if (timer_elapsed(key_timer) > 150) {
                    // if key was pressed "firmly"
                    register_code(KC_MEDIA_STOP);
                    unregister_code(KC_MEDIA_STOP);
                    return false;
                } else {
                    // if key was tapped
                    register_code(KC_MEDIA_PREV_TRACK);
                    unregister_code(KC_MEDIA_PREV_TRACK);
                    return false;
                }
            }
            break;

        case OS_TAB:
            // On the first tap, hold down LEFT_GUI.
            // If other keys are pressed, then when released, release LEFT_GUI.
            // If the key was held down (to OS + mouse drag), release LEFT_GUI.
            // Otherwise, press TAB on each successive release.
            if (record->event.pressed) {
                key_timer = timer_read();
                if (!window_switching) {
                    register_code(KC_LGUI);
                    other_key_pressed = false;
                }
            } else {
                if (timer_elapsed(key_timer) > 250) {
                    window_switching = false;
                    unregister_code(KC_LGUI);
                } else {
                    register_code(KC_TAB);
                    unregister_code(KC_TAB);
                    window_switching = true;
                }
            }
            return false;
            break;

        case KC_G:
            // If window switching, hold shift to switch in the opposite direction.
            if (window_switching) {
                if (record->event.pressed) {
                    register_code(KC_LSFT);
                } else {
                    register_code(KC_TAB);
                    unregister_code(KC_TAB);
                    unregister_code(KC_LSFT);
                }
                return false;
            }
            break;

        default:
            other_key_pressed = true;
            if (window_switching) {
                window_switching = false;
                unregister_code(KC_LGUI);
            }
            break;
    }
    return true;
};

// Release L_GUI if window-switching has finished.
void matrix_scan_user(void) {
    if (window_switching) {
        if (timer_elapsed(key_timer) > 1250) {
            window_switching = false;
            unregister_code(KC_LGUI);
        }
    }
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch(biton32(layer_state)) {
            case _LOWER:
                clockwise ? tap_code(KC_MS_WH_DOWN) : tap_code(KC_MS_WH_UP);
                break;
            default:
                clockwise ? tap_code(KC_PGDN) : tap_code(KC_PGUP);
                break;
        }
    } else if (index == 1) {
        switch(biton32(layer_state)) {
            case _LOWER:
                clockwise ? tap_code(KC_RIGHT) : tap_code(KC_LEFT);
                break;
            default:
                clockwise ? tap_code(KC_DOWN) : tap_code(KC_UP);
                break;
        }
    }
}
