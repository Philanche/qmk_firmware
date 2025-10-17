// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H

#define NB_OF_KEYCODES 8 // for our implementation of custom keycodes. Might get removed

enum phi_keycodes {
  // keycodes for punctuation combos that are not in qwerty
  PHI_LPRN = SAFE_RANGE,
  PHI_RPRN,
  PHI_QUES,
  PHI_LCBR,
  PHI_RCBR,
  PHI_DOT,
  PHI_SLSH,
  PHI_COMM
};

enum layers {
  BASE, // Valid layout
  GAMING, // Qwerty-like, used for gaming
  NAVIGATION, // Arrows and similar navigation
  NUMBERS, // Numbers and function keys
  GREEK, // Greek letters
  SYMBOLS, // Additional symbols and accented letters
  MATHS, // Maths symbols, will have LaTeX translation
  NUMPAD // For fast number entry, for example OTP
};

enum unicode_names {
  // Greek letters
  alpha,
  Alpha,
  beta,
  Beta,
  gamma,
  Gamma,
  delta,
  Delta,
  epsilon,
  Epsilon,
  zeta,
  Zeta,
  eta,
  Eta,
  theta,
  Theta,
  iota,
  Iota,
  kappa,
  Kappa,
  lambda,
  Lambda,
  mu,
  Mu,
  nu,
  Nu,
  xi,
  Xi,
  omicron,
  Omicron,
  pi,
  Pi,
  rho,
  Rho,
  sigma,
  Sigma,
  tau,
  Tau,
  upsilon,
  Upsilon,
  phi,
  Phi,
  chi,
  Chi,
  psi,
  Psi,
  omega,
  Omega,
  // Maths on the number layer
  times,
  divide,
  // Extra symbols and letters
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
  // Maths symbols
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
};

const uint32_t PROGMEM unicode_map[] = {
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
  [times] = 0x00D7,
  [divide] = 0x00F7,
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
  [sum] = 0x2211,
  [product] = 0x220F,
  [empty] = 0x2205,
  [implies] = 0x21D2,
  [impliedby] = 0x21D0,
  [iff] = 0x2D4,
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
        PHI_LPRN, KC_V        , KC_L        , KC_D        , KC_F        , KC_X   ,                        KC_G   , KC_P        , KC_U        , KC_O        , KC_DOT      , PHI_RPRN,
        KC_MINUS, LALT_T(KC_S), LCTL_T(KC_R), LGUI_T(KC_T), LSFT_T(KC_N), KC_B   ,                        KC_W   , RSFT_T(KC_C), RGUI_T(KC_E), RCTL_T(KC_A), RALT_T(KC_I), PHI_QUES,
        PHI_LCBR, KC_J        , KC_M        , KC_K        , KC_H        , KC_Q   ,                        KC_QUOT, KC_Y        , KC_Z        , PHI_SLSH    , PHI_COMM    , PHI_RCBR,
                                                                 KC_ENT , KC_SPC , KC_NO,          KC_NO, KC_BSPC, KC_NO
				),
    [GAMING] = LAYOUT_split_3x6_3(
        KC_T    , KC_TAB      , KC_Q        , KC_W        , KC_E        , KC_R   ,                        KC_Y   , KC_U        , KC_I        , KC_O        , KC_P        , KC_LBRC,
        KC_G    , KC_LSFT     , KC_A        , KC_S        , KC_D        , KC_F   ,                        KC_H   , KC_J        , KC_K        , KC_L        , KC_SCLN     , KC_QUOT,
        KC_B    , KC_LCTL     , KC_Z        , KC_X        , KC_C        , KC_V   ,                        KC_N   , KC_M        , KC_COMM     , KC_DOT      , KC_SLSH     , KC_RBRC,
                                                                 _______, _______, _______,      _______, _______, _______
				  ),
    [NAVIGATION] = LAYOUT_split_3x6_3(
	_______ , KC_BRIU     , _______     , KC_UP       , _______     , _______,                        _______, _______     , KC_PGUP     , _______     , KC_VOLU     , KC_PWR ,
        _______ , KC_PAUS     , KC_LEFT     , KC_DOWN     , KC_RIGHT    , _______,                        _______, KC_HOME     , KC_PGDN     , KC_END      , KC_MUTE     , _______,
        _______ , KC_BRID     , _______     , _______     , _______     , _______,                        _______, _______     , _______     , _______     , KC_VOLD     , _______,
                                                                 _______, _______, _______,      _______, _______, _______
				      ),
    [NUMBERS] = LAYOUT_split_3x6_3(
	_______ , KC_PPLS     , KC_PMNS     , UM(times)   , UM(divide)  , _______,                        KC_PERC, KC_PEQL     , KC_AT       , KC_HASH     , KC_TILDE    , _______,
        _______ , KC_1        , KC_2        , KC_3        , KC_4        , KC_5   ,                        KC_6   , KC_7        , KC_8        , KC_9        , KC_0        , _______,
        KC_F12  , KC_F1       , KC_F2       , KC_F3       , KC_F4       , KC_F5  ,                        KC_F6  , KC_F7       , KC_F8       , KC_F9       , KC_F10      , KC_F11 ,
                                                                 _______, _______, _______,      _______, _______, _______
				   ),
    [GREEK] = LAYOUT_split_3x6_3(
	_______ , UP(nu,Nu)      , UP(lambda,Lambda), UP(delta,Delta), UP(phi,Phi)    , UP(chi,Chi)  ,          UP(gamma,Gamma), UP(pi,Pi) , UP(upsilon,Upsilon), UP(omicron,Omicron), _______      , _______,
        _______ , UP(sigma,Sigma), UP(rho,Rho)      , UP(tau,Tau)    , UP(theta,Theta), UP(beta,Beta),          UP(omega,Omega), UP(xi,Xi) , UP(epsilon,Epsilon), UP(alpha,Alpha)    , UP(iota,Iota), _______,
        _______ , _______        , UP(mu,Mu)        , UP(kappa,Kappa), UP(eta,Eta)    , _______      ,          _______        , UP(psi,Psi), UP(zeta,Zeta)     , _______            , _______      , _______,
                                                                              _______, _______, _______,      _______, _______, _______
								 ),
    [SYMBOLS] = LAYOUT_split_3x6_3(
        _______ , UM(pound)   , _______     , _______     , _______     , _______,                        _______, _______              , UP(ugrave,Ugrave), _______          , UM(dotdotdot), _______,
        _______ , UM(euro)    , KC_ASTR     , KC_CIRC     , KC_AMPR     , _______,                        _______, UP(ccedilla,Ccedilla), UP(eacute,Eacute), UP(agrave,Agrave), _______      , _______,
        _______ , KC_DLR      , _______     , _______     , KC_PIPE     , _______,                        _______, UP(ecirc,Ecirc)      , UP(egrave,Egrave), UP(aring,Aring)  , _______      , _______,
                                                                 _______, _______, _______,      _______, _______, _______
								 ),
    [MATHS] = LAYOUT_split_3x6_3(
	UM(from)     , UM(lor)     , UM(oplus)   , UM(otimes)  , UM(cdot)        , _______,                        _______, UM(product) , UM(uni)     , UM(empty)   , UM(cong)    , UM(to)     ,
        UM(impliedby), UM(sum)     , UM(infty)   , UM(in)      , UM(inter)       , UM(leq),                        UM(geq), UM(subseteq), UM(exists)  , UM(forall)  , UM(coloneq) , UM(implies),
        UM(langle)   , UM(land)    , _______     , UM(notin)   , UM(lefttriangle), _______,                        _______, _______     , UM(lnot)    , _______     , UM(neq)     , UM(rangle) ,
                                                                 _______, _______, _______,      _______, _______, _______
								 ),
    [NUMPAD] = LAYOUT_split_3x6_3(
        _______ , _______     , KC_KP_7     , KC_KP_8     , KC_KP_9     , _______,                        _______, KC_KP_7     , KC_KP_8     , KC_KP_9     , _______     , _______,
        _______ , _______     , KC_KP_4     , KC_KP_5     , KC_KP_6     , _______,                        _______, KC_KP_4     , KC_KP_5     , KC_KP_6     , _______     , _______,
        _______ , _______     , KC_KP_1     , KC_KP_2     , KC_KP_3     , _______,                        _______, KC_KP_1     , KC_KP_2     , KC_KP_3     , _______     , _______,
                                                                 _______, _______, _______,      _______, _______, _______
								 ),
    /*    [EMPTY] = LAYOUT_split_3x6_3(
        _______ , _______     , _______     , _______     , _______     , _______,                        _______, _______     , _______     , _______     , _______     , _______,
        _______ , _______     , _______     , _______     , _______     , _______,                        _______, _______     , _______     , _______     , _______     , _______,
        _______ , _______     , _______     , _______     , _______     , _______,                        _______, _______     , _______     , _______     , _______     , _______,
                                                                 _______, _______, _______,      _______, _______, _______
								 ),*/
};

// TODO: Make layers. Combos (A + E = Æ; T + M = ™; O + E = Œ; + + - = ±; => + <= = <=>; -> + <- = <->; Tap Dance combo to go to GAMING. ) Layer movement in general. (Numpad layer = double tap number layer key)
// Layers to make: Gaming typing;
// TODO: LaTeX toggle/handling.

// Use KC_PAUS for wifi.

// Custom keycode implementation. Might be changed for qmk's key override

bool shifted[NB_OF_KEYCODES];

void custom_keycode(uint16_t regular_keycode, uint16_t shifted_keycode, uint16_t custom_index, keyrecord_t *record) {
  if(record->event.pressed) {
    if(get_mods() & MOD_MASK_SHIFT) {
      shifted[custom_index] = true;
      uint8_t cur_mods = get_mods();
      del_mods(MOD_MASK_SHIFT);
      register_code(shifted_keycode);
      set_mods(cur_mods);
    } else {
      shifted[custom_index] = false;
      register_code(regular_keycode);
    }
  } else {
    if(shifted[custom_index]) {
      unregister_code(shifted_keycode);
    } else {
      unregister_code(regular_keycode);
    }
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case PHI_LPRN:
    custom_keycode(KC_LPRN, KC_LBRC, 0, record);
    return false;
  case PHI_RPRN:
    custom_keycode(KC_RPRN, KC_RBRC, 1, record);
    return false;
  case PHI_QUES:
    custom_keycode(KC_QUES, KC_EXLM, 2, record);
    return false;
  case PHI_LCBR:
    custom_keycode(KC_LCBR, KC_LT, 3, record);
    return false;
  case PHI_RCBR:
    custom_keycode(KC_RCBR, KC_GT, 4, record);
    return false;
  case PHI_DOT:
    custom_keycode(KC_DOT, KC_COLN, 5, record);
    return false;
  case PHI_SLSH:
    custom_keycode(KC_SLSH, KC_BSLS, 6, record);
    return false;
  case PHI_COMM:
    custom_keycode(KC_COMM, KC_SCLN, 7, record);
    return false;
  }
  return true;
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  //debug_mouse=true;
}
