#include QMK_KEYBOARD_H


enum layer_names {
    _QWERTY = 0,
    _NAV,
    _NUM,
    _LED,
};

// Tap Dance declarations
enum {
    TD_BSLS_NAV,
    TD_SPC_NAV,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_BSLS_NAV] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_BSLS,_NAV),
    [TD_SPC_NAV] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_SPC,_NAV),
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT_4key(
     KC_ESC,         KC_1,       KC_2,    KC_3,       KC_4,     KC_5,     KC_CAPS,                                 KC_PLUS,       KC_6,    KC_7,     KC_8,     KC_9,       KC_0,     KC_PSCR,
     C_S_T(KC_GRV),  KC_Q,       KC_W,    KC_E,       KC_R,     KC_T,     KC_EQL,                                  KC_MINS,       KC_Y,    KC_U,     KC_I,     KC_O,       KC_P,     CW_TOGG,
     KC_TAB,         KC_A,       KC_S,    KC_D,       KC_F,     KC_G,     KC_LBRC,                                 KC_RBRC,       KC_H,    KC_J,     KC_K,     KC_L,       KC_SCLN,  KC_QUOT,
     SC_LSPO,        KC_Z,       KC_X,    KC_C,       KC_V,     KC_B,     TD(TD_SPC_NAV),                                TG(_NUM),      KC_N,    KC_M,     KC_COMM,  KC_DOT,     KC_SLSH,  SC_RSPC,
     KC_LCTL,        KC_LGUI,    C(KC_SPC),     KC_LALT,   KC_BSPC,  LT(_NUM,KC_BSLS), LT(_NUM,KC_ENT), LT(_NUM,KC_ENT),  LT(_NAV,KC_SPC), KC_DEL,  KC_RALT,  KC_ESC,   C_S_T(KC_BSLS),KC_RCTL ),

	[_NAV] = LAYOUT_4key(
     _______,     KC_F1,      KC_F2,    KC_F3,        KC_F4,         KC_F5,    XXXXXXX,                      KC_VOLU,       KC_F6,   KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,
     _______,    XXXXXXX,    XXXXXXX,  KC_UP,        XXXXXXX,       KC_HOME,  XXXXXXX,                     KC_VOLD,       KC_HOME, XXXXXXX,  KC_UP,    XXXXXXX, XXXXXXX,   KC_F12,
     _______,    KC_PGUP,    KC_LEFT, KC_DOWN,      KC_RGHT,       KC_END,   KC_DEL,                       KC_MUTE,       KC_END,  KC_LEFT,  KC_DOWN,   KC_RGHT,  KC_PGUP, _______,
     _______,    KC_PGDN,    XXXXXXX,  XXXXXXX,      XXXXXXX,        XXXXXXX, TG(_NAV),                      TG(_LED),      XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, KC_PGDN,  _______,
     _______,    _______,    _______,          _______,               _______, KC_SPC, _______,     _______, _______, _______,            _______,       _______, _______, _______),

    [_NUM] = LAYOUT_4key(
     _______,  KC_F1,      KC_F2,    KC_F3,      KC_F4,    KC_F5,    KC_LCBR,                      KC_RCBR,        KC_F6,   KC_F7,     KC_F8,   KC_F9,    KC_F10,  KC_F11,
     _______,  KC_HASH,    KC_1,     KC_2,       KC_3,     KC_PLUS,  KC_LBRC,                      KC_RBRC,        KC_HOME, XXXXXXX,   KC_UP,   XXXXXXX,  XXXXXXX, KC_F12,
     _______,  KC_DOT,     KC_4,     KC_5,       KC_6,     KC_MINS,  KC_LT,                        KC_GT,          KC_END,  KC_LEFT,   KC_DOWN, KC_RGHT,  KC_PGUP, _______,
     _______,  KC_SLSH,    KC_7,     KC_8,       KC_9,     KC_0,     TG(_LED),                      TG(_NUM),        XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,  KC_PGDN, _______,
     _______,  _______,    _______,        _______,       _______,  KC_SPC,  _______,    _______,_______, _______,            _______,        _______,  _______, _______),

    [_LED] = LAYOUT_4key(
     QK_BOOT,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MODE_TWINKLE,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, RGB_SPI, RGB_SAI, RGB_HUI, RGB_VAI, XXXXXXX, RGB_MODE_SWIRL,               XXXXXXX, XXXXXXX, BL_UP,  BL_STEP, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, RGB_SPD, RGB_SAD, RGB_HUD, RGB_VAD, XXXXXXX, RGB_MODE_RAINBOW,             XXXXXXX, XXXXXXX, BL_DOWN,  BL_BRTG, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD,                      TG(_LED), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX,    XXXXXXX, RGB_RMOD, RGB_TOG,   BL_TOGG, XXXXXXX, TG(_LED),    XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX)
};

#define LAYER_VAL 150

// Define led segments for each layer

// Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {9, 6, HSV_RED}      // Light 6 LEDs, starting with LED 9
);


//const rgblight_segment_t PROGMEM base_segments[] = RGBLIGHT_LAYER_SEGMENTS(
//	{9, 6, 0, 255, LAYER_VAL}
//);
const rgblight_segment_t PROGMEM nav_col[] = RGBLIGHT_LAYER_SEGMENTS(
    {9, 6, 0, 255, LAYER_VAL}  // leds 9-15 red
);
const rgblight_segment_t PROGMEM num_col[] = RGBLIGHT_LAYER_SEGMENTS(
    {9, 6, 213, 255, LAYER_VAL} //leds 9-15 MAGENTA
);
const rgblight_segment_t PROGMEM led_col[] = RGBLIGHT_LAYER_SEGMENTS(
    {9, 6, 106, 255, LAYER_VAL} //leds 9-15 SPRINGGREEN
);
//const rgblight_segment_t PROGMEM adjust_segments[] = RGBLIGHT_LAYER_SEGMENTS(
	//{10, 4, 20, 255, LAYER_VAL}
//);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM mod_led_layers[] = RGBLIGHT_LAYERS_LIST(
	//base_segments,
    capslock_layer,
	nav_col,
	num_col,
	led_col
);

void keyboard_post_init_user(void) {
	// Enable the LED layers
	rgblight_layers = mod_led_layers;
}


bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}


//#define BIT_SET(intval, bitnum) ((intval & (1 << bitnum)) > 0)

// Use the RGBLight layers feature to indicate active layers
layer_state_t layer_state_set_user(layer_state_t state) {
	//uprintf("layer state: %d\n", state);
	rgblight_set_layer_state(1, layer_state_cmp(state, _NAV));
	rgblight_set_layer_state(2, layer_state_cmp(state, _NUM));
	rgblight_set_layer_state(3, layer_state_cmp(state, _LED));
//	rgblight_set_layer_state(4, BIT_SET(state, _ADJUST));
	// This isn't required but it improves the responsiveness
	rgblight_set();
  	return state;
}
