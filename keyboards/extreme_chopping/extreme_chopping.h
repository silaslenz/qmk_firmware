#pragma once

#include "quantum.h"

#ifdef KEYBOARD_lets_split_rev1
    #include "rev1.h"
#elif KEYBOARD_lets_split_rev2
    #include "rev2.h"
#elif KEYBOARD_lets_split_sockets
    #include "sockets.h"
#endif
// Used to create a keymap using only KC_ prefixed keys
#define LAYOUT( \
	L00, L01, L02, L03, L04, L05, L06, R00, R01, R02, R03, R04, R05, R06,\
	L10, L11, L12, L13, L14, L15     , R10, R11, R12, R13, R14, R15, R16, R17,\
	L20, L21, L22, L23, L24, L25     , R20, R21, R22, R23, R24, R25, R26,\
	L30, L31, L32, L33, L34, L35, L36, R30, R31, R32, R33, R34, R35,\
	L40, L41, L42, L43, L44               , R41, R42, R43, R44, R45, R46  \
	) \
	{ \
		{ L00, L01, L02, L03, L04, L05, L06}, \
		{ L10, L11, L12, L13, L14, L15, KC_NO }, \
		{ L20, L21, L22, L23, L24, L25, KC_NO }, \
		{ L30, L31, L32, L33, L34, L35, L36 }, \
		{ L40, L41, L42, L43, L44, KC_NO, KC_NO }, \
		{ R00, R01, R02, R03, R04, R05, R06, KC_NO }, \
		{ R10, R11, R12, R13, R14, R15, R16, R17 }, \
		{ R20, R21, R22, R23, R24, R25, R26, KC_NO }, \
		{ R30, R31, R32, R33, R34, R35, KC_NO, KC_NO }, \
		{ KC_NO, R41, R42, R43, R44, R45, R46, KC_NO } \
	}

#define LAYOUT_ortho_5x16 LAYOUT