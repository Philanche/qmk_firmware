// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H

#include "print.h"
#include "unicode.h"
#include "transactions.h"

enum custom_keybinds {
  PHI_LATEX = SAFE_RANGE,
};

enum layers {
  BASE, // Valid layout
  GAMING, // Qwerty-like, used for gaming
  NAVIGATION, // Arrows and similar navigation
  NUMBERS, // Numbers and function keys
  SYMBOLS, // Additional symbols and accented letters
  GREEK, // Greek letters
  MATHS, // Maths symbols, will have LaTeX translation
  NUMPAD, // For fast number entry, for example OTP
  ARROWS, // Right hand arrows, for gaming
};

enum tap_dance {
  NUM,
  TD_GAMING,
  NAV,
};

enum unicode_names {
  // Maths symbols
  times,
  divide,
  sum,
  product,
  empty,
  implies,
  impliedby,
  iff,
  uni,
  inter,
  subseteq,
  infty,
  to,
  from,
  doublearrow,
  cdot,
  plusminus,
  coloneq,
  neq,
  cong,
  leq,
  geq,
  in,
  notin,
  lnot,
  lor,
  land,
  exists,
  forall,
  oplus,
  otimes,
  lefttriangle,
  langle,
  rangle,
  // Greek letters with LaTeX commands
  alpha,
  beta,
  gamma,
  Gamma,
  delta,
  Delta,
  epsilon,
  zeta,
  eta,
  theta,
  Theta,
  iota,
  kappa,
  lambda,
  Lambda,
  mu,
  nu,
  xi,
  Xi,
  pi,
  Pi,
  rho,
  sigma,
  Sigma,
  tau,
  upsilon,
  Upsilon,
  phi,
  Phi,
  chi,
  psi,
  Psi,
  omega,
  Omega,
  // Greek Letters without LaTeX commands
  Alpha,
  Beta,
  Epsilon,
  Zeta,
  Eta,
  Iota,
  Kappa,
  Mu,
  Nu,
  omicron,
  Omicron,
  Rho,
  Tau,
  Chi,
  // Extra symbols and letters
  ae,
  AE,
  oe,
  OE,
  dotdotdot,
  ccedilla,
  Ccedilla,
  eacute,
  Eacute,
  egrave,
  Egrave,
  ecirc,
  Ecirc,
  agrave,
  Agrave,
  ugrave,
  Ugrave,
  aring,
  Aring,
  euro,
  pound,
  tm,
  celsius,
};

const uint32_t PROGMEM unicode_map[] = {
  [times] = 0x00D7,
  [divide] = 0x00F7,
  [sum] = 0x2211,
  [product] = 0x220F,
  [empty] = 0x2205,
  [implies] = 0x21D2,
  [impliedby] = 0x21D0,
  [iff] = 0x21D4,
  [uni] = 0x222A,
  [inter] = 0x2229,
  [subseteq] = 0x2286,
  [infty] = 0x221E,
  [to] = 0x2192,
  [from] = 0x2190,
  [doublearrow] = 0x2194,
  [cdot] = 0x00B7,
  [plusminus] = 0x00B1,
  [coloneq] = 0x2254,
  [neq] = 0x2260,
  [cong] = 0x2245,
  [leq] = 0x2264,
  [geq] = 0x2265,
  [in] = 0x2208,
  [notin] = 0x2209,
  [lnot] = 0x00AC,
  [lor] = 0x2228,
  [land] = 0x2227,
  [exists] = 0x2203,
  [forall] = 0x2200,
  [oplus] = 0x2295,
  [otimes] = 0x2297,
  [lefttriangle] = 0x22B4,
  [langle] = 0x3008,
  [rangle] = 0x3009,
  [alpha] = 0x03B1,
  [Alpha] = 0x0391,
  [beta] = 0x03B2,
  [Beta] = 0x0392,
  [gamma] = 0x03B3,
  [Gamma] = 0x0393,
  [delta] = 0x03B4,
  [Delta] = 0x0394,
  [epsilon] = 0x03B5,
  [Epsilon] = 0x395,
  [zeta] = 0x03B6,
  [Zeta] = 0x0396,
  [eta] = 0x03B7,
  [Eta] = 0x0397,
  [theta] = 0x03B8,
  [Theta] = 0x0398,
  [iota] = 0x03B9,
  [Iota] = 0x0399,
  [kappa] = 0x03BA,
  [Kappa] = 0x039A,
  [lambda] = 0x03BB,
  [Lambda] = 0x039B,
  [mu] = 0x03BC,
  [Mu] = 0x039C,
  [nu] = 0x03BD,
  [Nu] = 0x039D,
  [xi] = 0x03BE,
  [Xi] = 0x039E,
  [omicron] = 0x03BF,
  [Omicron] = 0x039F,
  [pi] = 0x03C0,
  [Pi] = 0x03A0,
  [rho] = 0x03C1,
  [Rho] = 0x03A1,
  [sigma] = 0x03C3,
  [Sigma] = 0x03A3,
  [tau] = 0x03C4,
  [Tau] = 0x03A4,
  [upsilon] = 0x03C5,
  [Upsilon] = 0x03A5,
  [phi] = 0x03D5,
  [Phi] = 0x03A6,
  [chi] = 0x03C7,
  [Chi] = 0x03A7,
  [psi] = 0x03C8,
  [Psi] = 0x03A8,
  [omega] = 0x03C9,
  [Omega] = 0x03A9,
  [ae] = 0x00E6,
  [AE] = 0x00C6,
  [oe] = 0x0153,
  [OE] = 0x0152,
  [dotdotdot] = 0x2026,
  [ccedilla] = 0x00E7,
  [Ccedilla] = 0x00C7,
  [eacute] = 0x00E9,
  [Eacute] = 0x00C9,
  [egrave] = 0x00E8,
  [Egrave] = 0x00C8,
  [ecirc] = 0x00EA,
  [Ecirc] = 0x00CA,
  [agrave] = 0x00E0,
  [Agrave] = 0x00C0,
  [ugrave] = 0x00F9,
  [Ugrave] = 0x00D9,
  [aring] = 0x00E5,
  [Aring] = 0x00C5,
  [euro] = 0x20AC,
  [pound] = 0x00A3,
  [tm] = 0x2122,
  [celsius] = 0x2103,
};

const char PROGMEM *latex_name[] = {
  [times] = "times ",
  [divide] = "frac",
  [sum] = "sum ",
  [product] = "prod ",
  [empty] = "emptyset ",
  [implies] = "implies ",
  [impliedby] = "impliedby ",
  [iff] = "iff ",
  [uni] = "cup ",
  [inter] = "cap ",
  [subseteq] = "subseteq ",
  [infty] = "infty ",
  [to] = "to ",
  [from] = "leftarrow ",
  [doublearrow] = "leftrightarrow ",
  [cdot] = "cdot ",
  [plusminus] = "pm ",
  [coloneq] = "coloneq ",
  [neq] = "ne ",
  [cong] = "cong ",
  [leq] = "le ",
  [geq] = "ge ",
  [in] = "in ",
  [notin] = "notin ",
  [lnot] = "lnot ",
  [lor] = "lor ",
  [land] = "land ",
  [exists] = "exists ",
  [forall] = "forall ",
  [oplus] = "oplus ",
  [otimes] = "otimes ",
  [lefttriangle] = "triangleleft ",
  [langle] = "left< ",
  [rangle] = "right> ",
  [alpha] = "alpha ",
  [Alpha] = "A",
  [beta] = "beta ",
  [Beta] = "B",
  [gamma] = "gamma ",
  [Gamma] = "Gamma ",
  [delta] = "delta ",
  [Delta] = "Delta ",
  [epsilon] = "varepsilon ",
  [Epsilon] = "E",
  [zeta] = "zeta ",
  [Zeta] = "Z",
  [eta] = "eta ",
  [Eta] = "H",
  [theta] = "theta ",
  [Theta] = "Theta ",
  [iota] = "iota ",
  [Iota] = "I",
  [kappa] = "kappa ",
  [Kappa] = "K",
  [lambda] = "lamda ",
  [Lambda] = "Lamda ",
  [mu] = "mu ",
  [Mu] = "M",
  [nu] = "nu ",
  [Nu] = "N",
  [xi] = "xi ",
  [Xi] = "Xi ",
  [omicron] = "o",
  [Omicron] = "O",
  [pi] = "pi ",
  [Pi] = "Pi ",
  [rho] = "rho ",
  [Rho] = "R",
  [sigma] = "sigma ",
  [Sigma] = "Sigma ",
  [tau] = "tau ",
  [Tau] = "T",
  [upsilon] = "upsilon ",
  [Upsilon] = "Upsilon ",
  [phi] = "varphi ",
  [Phi] = "Phi ",
  [chi] = "Chi ",
  [Chi] = "X",
  [psi] = "psi ",
  [Psi] = "Psi ",
  [omega] = "omega ",
  [Omega] = "Omega ",
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │ ( │ V │ L │ D │ F │ X │       │ G │ P │ U │ O │ . │ ) │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │ - │ S │ R │ T │ N │ B │       │ W │ C │ E │ A │ I │ ? │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │ { │ J │ M │ K │ H │ Q │       │ ' │ Y │ Z │ / │ , │ } │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │ENT├───┐           ┌───┤LAY│
      *               └───┤SPC├───┐   ┌───┤BSP├───┘
      *                   └───┤LAY│   │LAY├───┘
      *                       └───┘   └───┘
      */
    [BASE] = LAYOUT_split_3x6_3(
        KC_LPRN , KC_V        , KC_L        , KC_D        , KC_F        , KC_X   ,                        KC_G   , KC_P        , KC_U        , KC_O        , KC_DOT      , KC_RPRN,
        KC_MINUS, LALT_T(KC_S), LCTL_T(KC_R), LGUI_T(KC_T), LSFT_T(KC_N), KC_B   ,                        KC_W   , RSFT_T(KC_C), RGUI_T(KC_E), RCTL_T(KC_A), RALT_T(KC_I), KC_QUES,
        KC_LCBR , KC_J        , KC_M        , KC_K        , KC_H        , KC_Q   ,                        KC_QUOT, KC_Y        , KC_Z        , KC_SLSH     , KC_COMM     , KC_RCBR,
	                                                         KC_ENT , KC_SPC , TD(NUM),  MO(SYMBOLS), KC_BSPC, TD(NAV)
				),
    [GAMING] = LAYOUT_split_3x6_3(
        KC_T    , KC_TAB      , KC_Q        , KC_W        , KC_E        , KC_R   ,                        KC_Y   , KC_U        , KC_I        , KC_O        , KC_P        , KC_LBRC,
        KC_G    , KC_LSFT     , KC_A        , KC_S        , KC_D        , KC_F   ,                        KC_H   , KC_J        , KC_K        , KC_L        , KC_SCLN     , KC_QUOT,
        KC_B    , KC_LCTL     , KC_Z        , KC_X        , KC_C        , KC_V   ,                        KC_N   , KC_M        , KC_COMM     , KC_DOT      , KC_SLSH     , KC_RBRC,
                                                                 _______, _______, _______,      _______, _______, _______
				  ),
    [NAVIGATION] = LAYOUT_split_3x6_3(
	KC_ESC  , KC_BRIU     , _______     , KC_UP       , _______     , _______,                        _______, _______     , KC_PGUP     , _______     , KC_VOLU     , KC_PWR ,
        KC_TAB  , KC_PAUS     , KC_LEFT     , KC_DOWN     , KC_RIGHT    , _______,                        _______, KC_HOME     , KC_PGDN     , KC_END      , KC_MUTE     , UG_TOGG,
        EE_CLR  , KC_BRID     , _______     , _______     , _______     , _______,                        _______, _______     , _______     , _______     , KC_VOLD     , _______,
                                                                 _______, _______, _______,      _______, _______, _______
				      ),
    [NUMBERS] = LAYOUT_split_3x6_3(
	KC_ESC  , KC_PPLS     , KC_PMNS     , UM(times)   , UM(divide)  , _______,                        KC_PERC, KC_PEQL     , KC_AT       , KC_HASH     , KC_TILDE    , _______,
        _______ , KC_1        , KC_2        , KC_3        , KC_4        , KC_5   ,                        KC_6   , KC_7        , KC_8        , KC_9        , KC_0        , _______,
        KC_F12  , KC_F1       , KC_F2       , KC_F3       , KC_F4       , KC_F5  ,                        KC_F6  , KC_F7       , KC_F8       , KC_F9       , KC_F10      , KC_F11 ,
                                                                 _______, _______, _______,      _______, _______, _______
				   ),
    [SYMBOLS] = LAYOUT_split_3x6_3(
	_______     , UM(pound)   , _______     , _______     , _______        , _______,                        _______, UP(ae,AE)            , UP(ugrave,Ugrave), UP(oe,OE)        , UM(dotdotdot), _______,
        UM(celsius) , UM(euro)    , KC_ASTR     , KC_CIRC     , LSFT_T(KC_AMPR), KC_GRV ,                        _______, UP(ccedilla,Ccedilla), UP(eacute,Eacute), UP(agrave,Agrave), _______      , _______,
        _______     , KC_DLR      , UM(tm)      , _______     , KC_PIPE        , _______,                        _______, UP(ecirc,Ecirc)      , UP(egrave,Egrave), UP(aring,Aring)  , _______      , _______,
                                                                 _______, _______, _______,      _______, _______, _______
								 ),
    [GREEK] = LAYOUT_split_3x6_3(
	_______ , UP(nu,Nu)      , UP(lambda,Lambda), UP(delta,Delta), UP(phi,Phi)    , UP(chi,Chi)  ,          UP(gamma,Gamma), UP(pi,Pi) , UP(upsilon,Upsilon), UP(omicron,Omicron), _______      , _______,
        OS_LSFT , UP(sigma,Sigma), UP(rho,Rho)      , UP(tau,Tau)    , UP(theta,Theta), UP(beta,Beta),          UP(omega,Omega), UP(xi,Xi) , UP(epsilon,Epsilon), UP(alpha,Alpha)    , UP(iota,Iota), OS_RSFT,
        _______ , _______        , UP(mu,Mu)        , UP(kappa,Kappa), UP(eta,Eta)    , _______      ,          _______        , UP(psi,Psi), UP(zeta,Zeta)     , _______            , _______      , _______,
                                                                              _______, _______, _______,      _______, _______, _______
								 ),
    [MATHS] = LAYOUT_split_3x6_3(
	UM(from)     , UM(lor)     , UM(oplus)   , UM(otimes)  , UM(cdot)        , PHI_LATEX,                        UC_NEXT, UM(product) , UM(uni)     , UM(empty)   , UM(cong)    , UM(to)     ,
        UM(impliedby), UM(sum)     , UM(infty)   , UM(in)      , UM(inter)       , UM(leq)  ,                        UM(geq), UM(subseteq), UM(exists)  , UM(forall)  , UM(coloneq) , UM(implies),
        UM(langle)   , UM(land)    , _______     , UM(notin)   , UM(lefttriangle), _______  ,                        _______, _______     , UM(lnot)    , _______     , UM(neq)     , UM(rangle) ,
                                                                 _______, _______, _______  ,               _______, _______, _______
								 ),
    [NUMPAD] = LAYOUT_split_3x6_3(
        _______ , _______     , KC_KP_7     , KC_KP_8     , KC_KP_9     , KC_PMNS,                        _______, KC_KP_7     , KC_KP_8     , KC_KP_9     , _______     , _______,
        _______ , _______     , KC_KP_4     , KC_KP_5     , KC_KP_6     , KC_PPLS,                        _______, KC_KP_4     , KC_KP_5     , KC_KP_6     , _______     , _______,
        _______ , _______     , KC_KP_1     , KC_KP_2     , KC_KP_3     , KC_PDOT,                        _______, KC_KP_1     , KC_KP_2     , KC_KP_3     , _______     , _______,
                                                                 _______, _______, _______,      _______, _______, _______
								 ),
    [ARROWS] = LAYOUT_split_3x6_3(
        _______ , _______     , _______     , _______     , _______     , _______,                        _______, _______     , KC_UP       , _______     , _______     , _______,
        _______ , _______     , _______     , _______     , _______     , _______,                        _______, KC_LEFT     , KC_DOWN     , KC_RIGHT    , _______     , _______,
        _______ , _______     , _______     , _______     , _______     , _______,                        _______, _______     , _______     , _______     , _______     , _______,
                                                                 _______, _______, _______,      _______, _______, _______
								 ),
    /*    [EMPTY] = LAYOUT_split_3x6_3(
        _______ , _______     , _______     , _______     , _______     , _______,                        _______, _______     , _______     , _______     , _______     , _______,
        _______ , _______     , _______     , _______     , _______     , _______,                        _______, _______     , _______     , _______     , _______     , _______,
        _______ , _______     , _______     , _______     , _______     , _______,                        _______, _______     , _______     , _______     , _______     , _______,
                                                                 _______, _______, _______,      _______, _______, _______
								 ),*/
};

// Tap Dances

void tap_num(tap_dance_state_t *state, void *user_data) {
  layer_on(NUMBERS);
}

void finished_num(tap_dance_state_t *state, void *user_data) {
  if(state->count == 2) {
    layer_invert(NUMPAD);
  }
}

void reset_num(tap_dance_state_t *state, void *user_data) {
  layer_off(NUMBERS);
}

void tap_nav(tap_dance_state_t *state, void *user_data) {
  layer_on(NAVIGATION);
}

void finished_nav(tap_dance_state_t *state, void *user_data) {
  if(state->count == 2) {
    layer_invert(ARROWS);
  }
}

void reset_nav(tap_dance_state_t *state, void *user_data) {
  layer_off(NAVIGATION);
}

tap_dance_action_t tap_dance_actions[] = {
  [NUM] = ACTION_TAP_DANCE_FN_ADVANCED(tap_num, finished_num, reset_num),
  [TD_GAMING] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_NO, GAMING),
  [NAV] = ACTION_TAP_DANCE_FN_ADVANCED(tap_nav, finished_nav, reset_nav),
};

// Combos

const uint16_t PROGMEM plusminus_combo[] = {KC_PPLS, KC_PMNS, COMBO_END};
const uint16_t PROGMEM iff_combo[] = {UM(implies), UM(impliedby), COMBO_END};
const uint16_t PROGMEM doublearrow_combo[] = {UM(to), UM(from), COMBO_END};
const uint16_t PROGMEM gaming_combo[] = {KC_LPRN, KC_RPRN, COMBO_END};
const uint16_t PROGMEM ungaming_combo[] = {KC_T, KC_LBRC, COMBO_END};

combo_t key_combos[] = {
  COMBO(plusminus_combo, UM(plusminus)),
  COMBO(iff_combo, UM(iff)),
  COMBO(doublearrow_combo, UM(doublearrow)),
  COMBO(gaming_combo, TD(TD_GAMING)),
  COMBO(ungaming_combo, TD(TD_GAMING)),
};

// Key overrides to make more custom keys.

const key_override_t left_bracket = ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_LBRC);
const key_override_t right_bracket = ko_make_basic(MOD_MASK_SHIFT, KC_RPRN, KC_RBRC);
const key_override_t exclamation_mark = ko_make_basic(MOD_MASK_SHIFT, KC_QUES, KC_EXLM);
const key_override_t less_than = ko_make_basic(MOD_MASK_SHIFT, KC_LCBR, KC_LT);
const key_override_t greater_than = ko_make_basic(MOD_MASK_SHIFT, KC_RCBR, KC_GT);
const key_override_t colon = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLN);
const key_override_t backslash = ko_make_basic(MOD_MASK_SHIFT, KC_SLSH, KC_BSLS);
const key_override_t semicolon = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_SCLN);

const key_override_t *key_overrides[] = {
  &left_bracket,
  &right_bracket,
  &exclamation_mark,
  &less_than,
  &greater_than,
  &colon,
  &backslash,
  &semicolon,
};

const rgblight_segment_t PROGMEM base_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, 0, 0, 255},
    {1, 4, 247, 255, 245},
    {2, 2, 139, 255, 250},
    {7, 4, 247, 255, 245},
    {8, 2, 139, 255, 250}
);

const rgblight_segment_t PROGMEM gaming_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_RED},
    {1, 1, HSV_ORANGE},
    {2, 1, HSV_YELLOW},
    {3, 1, HSV_GREEN},
    {4, 1, HSV_BLUE},
    {5, 1, HSV_PURPLE},
    {6, 1, HSV_RED},
    {7, 1, HSV_ORANGE},
    {8, 1, HSV_YELLOW},
    {9, 1, HSV_GREEN},
    {10, 1, HSV_BLUE},
    {11, 1, HSV_PURPLE}
);

const rgblight_segment_t PROGMEM navigation_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 12, HSV_CYAN});

const rgblight_segment_t PROGMEM numbers_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 12, HSV_GOLD});

const rgblight_segment_t PROGMEM symbols_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 12, HSV_PURPLE});

const rgblight_segment_t PROGMEM greek_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 12, HSV_GREEN});

const rgblight_segment_t PROGMEM maths_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 12, HSV_RED});

const rgblight_segment_t PROGMEM numpad_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 12, HSV_ORANGE});

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    base_layer,
    gaming_layer,
    navigation_layer,
    numbers_layer,
    symbols_layer,
    greek_layer,
    maths_layer,
    numpad_layer
);


// Runs every time a layer changes.
layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, NUMBERS, SYMBOLS, GREEK);
  state = update_tri_layer_state(state, NUMBERS, NAVIGATION, MATHS);
  rgblight_set_layer_state(0,layer_state_cmp(state,BASE));
  rgblight_set_layer_state(1,layer_state_cmp(state,GAMING));
  rgblight_set_layer_state(2,layer_state_cmp(state,NAVIGATION));
  rgblight_set_layer_state(3,layer_state_cmp(state,NUMBERS));
  rgblight_set_layer_state(4,layer_state_cmp(state,SYMBOLS));
  rgblight_set_layer_state(5,layer_state_cmp(state,GREEK));
  rgblight_set_layer_state(6,layer_state_cmp(state,MATHS));
  rgblight_set_layer_state(7,layer_state_cmp(state,NUMPAD));
  return state;
}

// Variables to dictate behaviour

bool return_to_gaming = false;
bool LaTeX_maths = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode){
  case LSFT_T(KC_AMPR):
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_AMPR);
      return false;
    }
    break;
  case KC_T:
    if (IS_LAYER_ON(GAMING)) {
      return_to_gaming = true;
      layer_off(GAMING);
    }
    break;
  case KC_ENT:
    if (return_to_gaming) {
      return_to_gaming = false;
      layer_on(GAMING);
    }
    break;
  case PHI_LATEX:
    if(record->event.pressed) {
      LaTeX_maths = !LaTeX_maths;
      uprintf("LaTeX status: %b", LaTeX_maths);
    }
    return false;
  case UM(times) ... UM(rangle):
    if(LaTeX_maths && record->event.pressed) {
      send_char('\\');
      send_string(latex_name[keycode&0x3FF]);
      send_char(' ');
      return false;
    }
    break;
  case UM(Alpha) ... UM(Chi):
    if(LaTeX_maths && record->event.pressed) {
      send_string(latex_name[keycode&0x3FF]);
      send_char(' ');
      return false;
    }
    break;

  }
  return true;
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  //debug_mouse=true;
  rgblight_layers = rgb_layers;
  layer_on(BASE);
}


// overwriting the default one to hopefully have electron not mess up
void unicode_input_start(void) {
    unicode_saved_led_state = host_keyboard_led_state();

    // Note the order matters here!
    // Need to do this before we mess around with the mods, or else
    // UNICODE_KEY_LNX (which is usually Ctrl-Shift-U) might not work
    // correctly in the shifted case.
    if (unicode_config.input_mode == UNICODE_MODE_LINUX && unicode_saved_led_state.caps_lock) {
        tap_code(KC_CAPS_LOCK);
    }

    unicode_saved_mods = get_mods(); // Save current mods
    clear_mods();                    // Unregister mods to start from a clean state
    clear_weak_mods();

    switch (unicode_config.input_mode) {
        case UNICODE_MODE_LINUX:
	    register_code(KC_LEFT_SHIFT);
	    wait_ms(TAP_CODE_DELAY);
	    register_code(KC_LEFT_CTRL);
	    wait_ms(TAP_CODE_DELAY);
	    tap_code(KC_U);
	    wait_ms(TAP_CODE_DELAY);
	    unregister_code(KC_LEFT_SHIFT);
	    wait_ms(TAP_CODE_DELAY);
	    unregister_code(KC_LEFT_CTRL);
            break;
        case UNICODE_MODE_EMACS:
            // The usual way to type unicode in emacs is C-x-8 <RET> then the unicode number in hex
            tap_code16(LCTL(KC_X));
            tap_code16(KC_8);
            tap_code16(KC_ENTER);
            break;
    }

    wait_ms(UNICODE_TYPE_DELAY);
}

void unicode_input_finish(void) {
    switch (unicode_config.input_mode) {
        case UNICODE_MODE_LINUX:
	    tap_code_delay(KC_SPACE, TAP_CODE_DELAY);
	    if (unicode_saved_led_state.caps_lock) {
	      tap_code(KC_CAPS_LOCK);
	    }
            break;
        case UNICODE_MODE_EMACS:
            tap_code16(KC_ENTER);
            break;
    }

    set_mods(unicode_saved_mods); // Reregister previously set mods

    wait_ms(UNICODE_TYPE_DELAY);
}
