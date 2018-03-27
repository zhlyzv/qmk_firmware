// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include "chimera_ortho.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum chimera_ortho_layers {
  _DVORAK = 0,
  _SYMBOLS,
  _NAV,
  _BRACKETS
};

//Tap Dance Declarations
enum {
  TD_SHIFT_CAPS = 0,
  TD_COLON,
  TD_LBRACE,
  TD_RBRACE
};

// Layer toggles
#define KC_SPNV LT(_NAV,KC_SPC)
#define KC_SPSM LT(_SYMBOLS, KC_SPC)
#define KC_ENTBR LT(_BRACKETS, KC_ENT)

// Mod toggles
#define KC_ALDL MT(MOD_RALT, KC_DEL)
#define KC_ALTM MT(MOD_LALT, KC_MINS)
#define KC_TBCL MT(MOD_LCTL, KC_TAB)
#define KC_SLCL MT(MOD_RCTL, KC_SLSH)
#define KC_GUIDEL MT(MOD_LGUI, KC_DEL)
#define KC_SFENT MT(MOD_RSFT, KC_ENT)

// Navigation
#define KC_CPY LCTL(KC_C)
#define KC_PTE LCTL(KC_V)
#define KC_CTE LCTL(KC_X)
#define KC_UNDO LCTL(KC_Z)
#define KC_FNDE LCTL(KC_F)

// Tap dance
#define KC_SHCPS TD(TD_SHIFT_CAPS)
#define KC_CLNS TD(TD_COLON)
#define KC_LBRA TD(TD_LBRACE)
#define KC_RBRA TD(TD_RBRACE)

#define LONGPRESS_DELAY 150

// Fillers to make layering more clear
#define _______ KC_TRNS
#define KC_XXXX KC_NO
#define KC_ KC_TRNS

// Tap Dance actions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_SHIFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSHIFT, KC_CAPS),
  [TD_LBRACE] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),
  [TD_RBRACE] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR),
  [TD_COLON] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, LSFT(KC_SCLN))
};

// Layer definitions
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DVORAK] = KC_KEYMAP(
  //,----+----+----+----+----+----+----.     ,----+----+----+----+----+----+----.
    GESC,QUOT, COMM, DOT, P , Y   ,ALTM,      ALDL, F  , G  , C  , R  , L  ,BSPC,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
    TBCL, A  , O  , E  , U  , I   ,LBRA,      RBRA, D  , H  , T  , N  , S  ,SLCL,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
   SHCPS, SCLN, Q , J  , K  , X   ,LPRN,      RPRN, B  , M  , W  , V  , Z  ,RSFT,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
                      GUIDEL,SPNV,                SPSM, ENTBR
  // \------------------+----+----+---/       \---+----+----+-------------------/
  ),

  [_NAV] = KC_KEYMAP(
  //,----+----+----+----+----+----+----.     ,----+----+----+----+----+----+----.
        ,XXXX,XXXX, UP ,XXXX,XXXX,XXXX,       PSCR,XXXX,XXXX,PGUP,XXXX,FNDE,INS ,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
        ,XXXX,LEFT,DOWN,RGHT,XXXX,XXXX,       XXXX,XXXX,HOME,PGDN,END, CTE ,UNDO,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
        ,XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,       XXXX,XXXX,XXXX,XXXX,XXXX,CPY ,PTE ,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
                             XXXX,XXXX,             LALT,LCTL
  // \------------------+----+----+---/       \---+----+----+-------------------/
  ),

  [_SYMBOLS] = KC_KEYMAP(
  //,----+----+----+----+----+----+----.     ,----+----+----+----+----+----+----.
    GRV , QUOT,COMM,DOT , F4 , F5 , F11,        F12 , F6 , F7 , F8 , F9,F10,QUES,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
        ,   1 ,  2 ,  3 ,  4 ,  5 ,BSLS,      SLSH,  6 ,  7 ,  8 ,  9 ,  0 ,MINS,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
        ,EXLM,  AT ,HASH, DLR,PERC,MINS,      PLUS,CIRC,AMPR,ASTR,LPRN,RPRN,EQL,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
                            ,LALT ,                    ,SPC
  // \------------------+----+----+---/       \---+----+----+-------------------/
  ),

  [_BRACKETS] = KC_KEYMAP(
  //,----+----+----+----+----+----+----.     ,----+----+----+----+----+----+----.
        ,QUOT, DOT,LPRN,RPRN,AMPR,PIPE,      XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
        ,GRV , DLR,LCBR,RCBR,EQL ,COLN,      XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
        ,BSLS,SLSH,LABK,RABK,EXLM,MINS,      PLUS,XXXX,XXXX,XXXX,XXXX,XXXX,    ,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
                            ,    ,                    ,
  // \------------------+----+----+---/       \---+----+----+-------------------/
  )
};

// Relay layer information through receiver LED
void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    switch (layer) {
      case _DVORAK:
        set_led_cyan;
        break;
      case _SYMBOLS:
        set_led_white;
        break;
      case _NAV:
        set_led_magenta;
        break;
      default:
        set_led_cyan;
        break;
    }
};
