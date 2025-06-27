#include QMK_KEYBOARD_H
// Atreus

// Adaptation sentence_case
char sentence_case_press_user(uint16_t keycode,
                              keyrecord_t* record,
                              uint8_t mods) {
  if ((mods & ~(MOD_MASK_SHIFT | MOD_BIT(KC_RALT))) == 0) {
    const bool shifted = mods & MOD_MASK_SHIFT;
    switch (keycode) {
      case KC_A:
      case KC_N:
      case KC_O:
      case KC_M:
      case KC_D:
      case KC_R:
      case KC_H:
      case KC_V:
      case KC_S:
      case KC_Y:
      case KC_T:
      case KC_I:
      case KC_COMMA:
      case KC_K:
      case KC_E:
      case KC_U:
      case KC_P:
      case KC_SEMICOLON:
      case KC_L:
      case KC_J:
      case KC_F:
      case KC_DOT:
      case KC_SLASH:
      case KC_Z:
      case KC_X:
      case KC_B:
      case KC_1 ... KC_0:  // 1 2 3 4 5 6 7 8 9 0, même si pose un problème dans les cas où la phrase commencerait par un chiffre – mais il est plus fréquent qu’elle se termine par un chiffre.
        return 'a';  // Letter key.

      case KC_Q:  // . is punctuation, Shift . is a symbol (>)
        return !shifted ? '.' : '#';
      case KC_W:
      case KC_C:
        return shifted ? '.' : '#';
      case S(KC_W):
      case S(KC_C):
        return '.';
      case KC_AT ... KC_RPRN:  // @ # $ % ^ & * ( )
      case KC_MINS ... KC_RIGHT_BRACKET:  // - = [ ]
      case KC_UNDS ... KC_COLN:  // _ + { } | :
      case KC_GRV:
        return '#';  // Symbol key.
      case KC_SPC:
	    case KC_F10:
	    case KC_F9:
	    case KC_F8:
        return ' ';  // Space key.
      case KC_QUOT:
        return '\'';  // Quote key.
    }
  }

  // Otherwise clear Sentence Case to initial state.
  sentence_case_clear();
  return '\0';
}

// Layers definitions
enum layer_names {
    _ER,
    _NVN,
    _SP,
    _COD,
    _CNVN
};

// Aliases
#define SC_ON SENTENCE_CASE_ON
#define SC_OFF SENTENCE_CASE_OFF
#define SC_TOGG SENTENCE_CASE_TOGGLE
#define NVN_SPC LT(_NVN, KC_SPC)
#define SP_ENT LT(_SP, KC_ENT)
#define HRM_J RSFT_T(KC_J)
#define HRM_F LSFT_T(KC_F)
#define HRM_K RALT_T(KC_K)
#define HRM_D RALT_T(KC_D)
#define HRM_F4 LCTL_T(KC_F4)
#define HRM_S LCTL_T(KC_S)
#define HRM_L RCTL_T(KC_L)
#define SAVE LCTL(KC_L)
#define UNDO LCTL(KC_B)
#define SRCH LCTL(KC_R)
#define SELA LCTL(KC_A)
#define CUT LCTL(KC_Z)
#define COPY LCTL(KC_O)
#define PASTE LCTL(KC_DOT)
#define INDI LCTL(KC_EQUAL)
#define PERC RALT(KC_T)
#define AMD RCS(KC_A)
#define EXP RCS(KC_EQUAL)
#define RAR RCS(KC_SEMICOLON)
#define MULA RCS(KC_S)
#define AJOU RCS(KC_F5)
#define RETI RCS(KC_Z)
#define ADOP RCS(KC_X)
#define REJT RCS(KC_K)
#define QOSD RCS(KC_P)
#define QAG RCS(KC_H)
#define CNVN_SPC LT(_CNVN, KC_SPC)
#define NVN_F9 LT(_NVN, KC_F9)
#define HRM_4S RSFT_T(KC_4)

// Macros declarations
enum custom_keycodes {
  MAIL = SAFE_RANGE,
  ASSS,
};

// Macros definitions
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MAIL:
      if (record->event.pressed) {
        SEND_STRING("idekqiesldaf@u;ejek,asiqoe,");
      } else {
      }
      break;
	case ASSS:
      if (record->event.pressed) {
        SEND_STRING("Ns;75mx1QQQQ");
      } else {
      }
      break;
  }
  return true;
};

// Tap Dance declarations
enum {
    F98, // actuellement inutilisé
    F6T,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [F98] = ACTION_TAP_DANCE_DOUBLE(KC_F9, KC_F8), // actuellement inutilisé
    [F6T] = ACTION_TAP_DANCE_DOUBLE(KC_F6, KC_TAB),
};

// Combo declarations
enum combos {
  WE_NBS,
  ER_QUOT,
  N56_NBS,
  XC_LP,
  CV_RP,
  UO_CTB,
  MCOM_2P,
  COMMDOT_EX,
  MDOT_QM,
  YP_TOCOD,
  QT_TOER,
  KL_F10,
  SD_F10,
  SHF_ENT,
  HSF_ENT,
  QR_SPO,
  PU_SPO,
  SX_F4,
  DC_F6,
  HFV_DEL,
  AHF_TAB,


  //LHJ_ENT,
 // HJL_ENT,


};

// Combo definitions
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM n56_combo[] = {KC_5, KC_6, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM uo_combo[] = {KC_U, KC_O, COMBO_END};
const uint16_t PROGMEM mcom_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM commdot_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM mdot_combo[] = {KC_M, KC_DOT, COMBO_END};
const uint16_t PROGMEM yp_combo[] = {KC_Y, KC_P, COMBO_END};
const uint16_t PROGMEM qt_combo[] = {KC_Q, KC_T, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM shf_combo[] = {KC_S, HRM_F, COMBO_END};
const uint16_t PROGMEM hsf_combo[] = {HRM_S, HRM_F, COMBO_END};
//const uint16_t PROGMEM lhj_combo[] = {KC_L, HRM_J, COMBO_END};
//const uint16_t PROGMEM hjl_combo[] = {HRM_L, HRM_J, COMBO_END};
const uint16_t PROGMEM qr_combo[] = {KC_Q, KC_R, COMBO_END};
const uint16_t PROGMEM pu_combo[] = {KC_P, KC_U, COMBO_END};
const uint16_t PROGMEM sx_combo[] = {KC_S, KC_X, COMBO_END};
const uint16_t PROGMEM dc_combo[] = {KC_D, KC_C, COMBO_END};
const uint16_t PROGMEM hfv_combo[] = {HRM_F, KC_V, COMBO_END};
const uint16_t PROGMEM ahf_combo[] = {HRM_F, KC_A, COMBO_END};



combo_t key_combos[] = {
  [WE_NBS] = COMBO(we_combo, RCS(KC_SPC)),
  [ER_QUOT] = COMBO(er_combo, RALT(KC_SCLN)),
  [N56_NBS] = COMBO(n56_combo, RCS(KC_SPC)),
  [XC_LP] = COMBO(xc_combo, RALT(KC_S)),
  [CV_RP] = COMBO(cv_combo, RALT(KC_D)),
  [UO_CTB] = COMBO(uo_combo, C(KC_BSPC)),
  [MCOM_2P] = COMBO(mcom_combo, S(KC_Q)),
  [COMMDOT_EX] = COMBO(commdot_combo, S(KC_W)),
  [MDOT_QM] = COMBO(mdot_combo, S(KC_C)),
  [YP_TOCOD] = COMBO(yp_combo, TO(_COD)),
  [QT_TOER] = COMBO(qt_combo, TO(_ER)),
  [KL_F10] = COMBO(kl_combo, KC_F10),
  [SD_F10] = COMBO(sd_combo, KC_F10),
  [SHF_ENT] = COMBO(shf_combo, KC_ENT),
  [HSF_ENT] = COMBO(hsf_combo, KC_ENT),
  //[LHJ_ENT] = COMBO(lhj_combo, KC_ENT),
 // [HJL_ENT] = COMBO(hjl_combo, KC_ENT),
  [QR_SPO] = COMBO(qr_combo, OSL(_SP)),
  [PU_SPO] = COMBO(pu_combo, OSL(_SP)),
  [SX_F4] = COMBO(sx_combo, KC_F4),
  [DC_F6] = COMBO(dc_combo, KC_F6),
  [HFV_DEL] = COMBO(hfv_combo, KC_DEL),
  [AHF_TAB] = COMBO(ahf_combo, KC_TAB),
};
// Custom combo times

#ifdef COMBO_TERM_PER_COMBO
uint16_t get_combo_term(uint16_t combo_index, combo_t *combo) {
    switch (combo_index) {
        case UI_CTB:
            return 0;
        case KL_F10:
        case SD_F10:
        case SHF_ENT:
        case HSF_ENT:
        case DC_F6:
        case SX_F4:
        case HFV_DEL:
        case AHF_TAB:
            return 0;
    }
    return COMBO_TERM;
}
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_ER] = LAYOUT( // pour la rédaction au compte rendu
    KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,     KC_U,    KC_I,    KC_O,    KC_P    ,
    KC_A,     KC_S,    KC_D,    HRM_F,   KC_G,                     KC_H,     HRM_J,   KC_K,    KC_L,    KC_SCLN ,
    KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,   KC_DEL,  OSL(_SP),KC_N,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH ,
    XXXXXXX,  HRM_F4,  TD(F6T), KC_ENT,  NVN_SPC,KC_BSPC, KC_F8,   NVN_F9,   KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX),


  [_NVN] = LAYOUT(
    UNDO,    KC_LBRC, KC_UP,   KC_RBRC, KC_PPLS,                  KC_F5,  KC_7,    KC_8,   KC_9,    SAVE,
    SRCH,    KC_LEFT, KC_DOWN, KC_RGHT, S(KC_3),                  XXXXXXX,HRM_4S,  KC_5,   KC_6,    KC_F2,
    SELA,    CUT,     COPY,    PASTE,   S(KC_7), KC_DEL,  XXXXXXX,KC_F3,  KC_1,    KC_2,   KC_3,    PERC,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,  KC_BSPC, XXXXXXX,KC_BSPC, KC_0,    KC_G,  KC_LCTL, XXXXXXX),


  [_SP] = LAYOUT(
    RAR,    EXP,     INDI,    XXXXXXX, QAG,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  ,
    AMD,    MULA,    AJOU,    ADOP,    QOSD,                      XXXXXXX, SC_TOGG, MAIL,    ASSS,    KC_F2  ,
    XXXXXXX,XXXXXXX, RETI,    REJT,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  ,
    XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ),


  [_COD] = LAYOUT( // code et vie de tous les jours
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,     KC_U,    KC_I,    KC_O,    KC_P    ,
    KC_A,    HRM_S,   HRM_D,   HRM_F,   KC_G,                         KC_H,     HRM_J,   HRM_K,   HRM_L,   KC_SCLN ,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_DEL,  LGUI(KC_1),KC_N,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH ,
    XXXXXXX, XXXXXXX, KC_TAB,  KC_ENT,  CNVN_SPC, KC_BSPC, KC_ESC,    MO(_CNVN),KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX),


  [_CNVN] = LAYOUT( // à remplir selon les besoins constatés
    UNDO,    XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX,                  XXXXXXX,  KC_7,    KC_8,   KC_9,    SAVE,
    SRCH,    KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,                  XXXXXXX,  HRM_4S,  KC_5,   KC_6,    MAIL,
    SELA,    CUT,     COPY,    PASTE,   XXXXXXX, KC_DEL,  XXXXXXX,XXXXXXX,  KC_1,    KC_2,   KC_3,    PERC,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,  KC_BSPC, XXXXXXX,KC_BSPC,   KC_0,    KC_DOT, XXXXXXX, XXXXXXX ),



};
