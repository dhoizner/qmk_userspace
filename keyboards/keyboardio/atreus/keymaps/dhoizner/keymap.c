// Copyright (C) 2019, 2020  Keyboard.io, Inc
//
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include "dhoizner.h"
#include "mykeys.h"
#include "layout.h"
#include "keymap_combo.h"
#include "custom_shifts.c" // This has to be here due to https://github.com/qmk/qmk_firmware/blob/master/docs/ChangeLog/20240825.md#key-override-keymapc-signature-change-24120

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [PRIMARY] = LAYOUT_LR(
    L_4_T_BASE, L_3_T_BASE, L_2_T_BASE, L_1_T_BASE, L_I_T_BASE,
    L_4_H_BASE, L_3_H_BASE, L_2_H_BASE, L_1_H_BASE, L_I_H_BASE,
    L_4_B_BASE, L_3_B_BASE, L_2_B_BASE, L_1_B_BASE, L_I_B_BASE, XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    L_T_3_BASE, L_T_1_BASE, L_T_2_BASE,

                            R_I_T_BASE, R_1_T_BASE, R_2_T_BASE, R_3_T_BASE, R_4_T_BASE,
                            R_I_H_BASE, R_1_H_BASE, R_2_H_BASE, R_3_H_BASE, R_4_H_BASE,
                XXXXXXX,    R_I_B_BASE, R_1_B_BASE, R_2_B_BASE, R_3_B_BASE, R_4_B_BASE,
                R_T_2_BASE, R_T_1_BASE, R_T_3_BASE, XXXXXXX,    XXXXXXX,    XXXXXXX
    ),
  [NUMBER_AND_SYMBOL] = LAYOUT_LR(
    L_4_T_NAS, L_3_T_NAS, L_2_T_NAS, L_1_T_NAS, L_I_T_NAS,
    L_4_H_NAS, L_3_H_NAS, L_2_H_NAS, L_1_H_NAS, L_I_H_NAS,
    L_4_B_NAS, L_3_B_NAS, L_2_B_NAS, L_1_B_NAS, L_I_B_NAS, XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   L_T_3_NAS, L_T_1_NAS, L_T_2_NAS,

                          R_I_T_NAS, R_1_T_NAS, R_2_T_NAS, R_3_T_NAS, R_4_T_NAS,
                          R_I_H_NAS, R_1_H_NAS, R_2_H_NAS, R_3_H_NAS, R_4_H_NAS,
               XXXXXXX,   R_I_B_NAS, R_1_B_NAS, R_2_B_NAS, R_3_B_NAS, R_4_B_NAS,
               R_T_2_NAS, R_T_1_NAS, R_T_3_NAS, XXXXXXX,   XXXXXXX,   XXXXXXX
    ),
  [NAVIGATION] = LAYOUT_LR(
    L_4_T_NAV, L_3_T_NAV, L_2_T_NAV, L_1_T_NAV, L_I_T_NAV,
    L_4_H_NAV, L_3_H_NAV, L_2_H_NAV, L_1_H_NAV, L_I_H_NAV,
    L_4_B_NAV, L_3_B_NAV, L_2_B_NAV, L_1_B_NAV, L_I_B_NAV, XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   L_T_3_NAV, L_T_1_NAV, L_T_2_NAV,

                          R_I_T_NAV, R_1_T_NAV, R_2_T_NAV, R_3_T_NAV, R_4_T_NAV,
                          R_I_H_NAV, R_1_H_NAV, R_2_H_NAV, R_3_H_NAV, R_4_H_NAV,
               XXXXXXX,   R_I_B_NAV, R_1_B_NAV, R_2_B_NAV, R_3_B_NAV, R_4_B_NAV,
               R_T_2_NAV, R_T_1_NAV, R_T_3_NAV, XXXXXXX,   XXXXXXX,   XXXXXXX
    ),
  [FUNCTION_AND_MEDIA] = LAYOUT_LR(
    L_4_T_FAM, L_3_T_FAM, L_2_T_FAM, L_1_T_FAM, L_I_T_FAM,
    L_4_H_FAM, L_3_H_FAM, L_2_H_FAM, L_1_H_FAM, L_I_H_FAM,
    L_4_B_FAM, L_3_B_FAM, L_2_B_FAM, L_1_B_FAM, L_I_B_FAM, XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   L_T_3_FAM, L_T_1_FAM, L_T_2_FAM,

                          R_I_T_FAM, R_1_T_FAM, R_2_T_FAM, R_3_T_FAM, R_4_T_FAM,
                          R_I_H_FAM, R_1_H_FAM, R_2_H_FAM, R_3_H_FAM, R_4_H_FAM,
               XXXXXXX,   R_I_B_FAM, R_1_B_FAM, R_2_B_FAM, R_3_B_FAM, R_4_B_FAM,
               R_T_2_FAM, R_T_1_FAM, R_T_3_FAM, XXXXXXX,   XXXXXXX,   XXXXXXX
    ),
  [MOUSE] = LAYOUT_LR(
    L_4_T_MOUSE, L_3_T_MOUSE, L_2_T_MOUSE, L_1_T_MOUSE, L_I_T_MOUSE,
    L_4_H_MOUSE, L_3_H_MOUSE, L_2_H_MOUSE, L_1_H_MOUSE, L_I_H_MOUSE,
    L_4_B_MOUSE, L_3_B_MOUSE, L_2_B_MOUSE, L_1_B_MOUSE, L_I_B_MOUSE, XXXXXXX,
    XXXXXXX,     XXXXXXX,     XXXXXXX,     L_T_3_MOUSE, L_T_1_MOUSE, L_T_2_MOUSE,

                              R_I_T_MOUSE, R_1_T_MOUSE, R_2_T_MOUSE, R_3_T_MOUSE, R_4_T_MOUSE,
                              R_I_H_MOUSE, R_1_H_MOUSE, R_2_H_MOUSE, R_3_H_MOUSE, R_4_H_MOUSE,
                 XXXXXXX,     R_I_B_MOUSE, R_1_B_MOUSE, R_2_B_MOUSE, R_3_B_MOUSE, R_4_B_MOUSE,
                 R_T_2_MOUSE, R_T_1_MOUSE, R_T_3_MOUSE, XXXXXXX,     XXXXXXX,     XXXXXXX
    ),
  [BUTTON] = LAYOUT_LR(
    L_4_T_BUT, L_3_T_BUT, L_2_T_BUT, L_1_T_BUT, L_I_T_BUT,
    L_4_H_BUT, L_3_H_BUT, L_2_H_BUT, L_1_H_BUT, L_I_H_BUT,
    L_4_B_BUT, L_3_B_BUT, L_2_B_BUT, L_1_B_BUT, L_I_B_BUT, XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   L_T_3_BUT, L_T_1_BUT, L_T_2_BUT,

                          R_I_T_BUT, R_1_T_BUT, R_2_T_BUT, R_3_T_BUT, R_4_T_BUT,
                          R_I_H_BUT, R_1_H_BUT, R_2_H_BUT, R_3_H_BUT, R_4_H_BUT,
               XXXXXXX,   R_I_B_BUT, R_1_B_BUT, R_2_B_BUT, R_3_B_BUT, R_4_B_BUT,
               R_T_2_BUT, R_T_1_BUT, R_T_3_BUT, XXXXXXX,   XXXXXXX,   XXXXXXX
    ),
};

#ifndef CHORDAL_HOLD
// Handedness for Chordal Hold
const char chordal_hold_layout[MAX_LAYERS][MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_LR(
    k00, k01, k02, k03, k04,
    k10, k11, k12, k13, k14,
    k20, k21, k22, k23, k24, k25,
    k30, k31, k32, k33, k34, k35,

                         k40, k41, k42, k43, k44,
                         k50, k51, k52, k53, k54,
                    k60, k61, k62, k63, k64, k65,
                    k70, k71, k72, k73, k74, k75
    );
#endif // CHORDAL_HOLD
