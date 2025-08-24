#include "action.h"
#include "modifiers.h"
#include "quantum.h"
#include QMK_KEYBOARD_H
#include "dhoizner.h"
#include "macros.h"

// Helper for digraph combos.
static bool digraph_combo(keyrecord_t *record, uint16_t first_letter, uint16_t second_letter) {
    if (record->event.pressed) {
        // Fire digraph combos only on base layer
        if (layer_state_cmp(layer_state, PRIMARY)) {
            if (is_caps_word_on()) {
                add_weak_mods(MOD_BIT(KC_LSFT));
            }

            tap_code16(first_letter);
            unregister_mods(MOD_MASK_SHIFT);
            tap_code16(second_letter);
        }
    }
    return false; // We handled this keypress
}

// Helper for combos that type something different when shifted.
static bool shift_override_combo(keyrecord_t *record, uint16_t key, uint16_t shifted_key, int first_hold, int second_hold) {
    if (record->event.pressed) {
        // Key overrides don't work for macros, so we have to do this manually
        if (get_mods() & MOD_MASK_SHIFT) {
            uint8_t temp_mods = get_mods();
            unregister_mods(MOD_MASK_SHIFT); // sometimes we want an unshifted key, turn off shift
            tap_code16(shifted_key);
            set_mods(temp_mods);
        } else {
            // No shift, resolve combo normally
            tap_code16(key);
        }
    }
    return false;
}

bool process_macro_event(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case COMBO_Z:
            if (record->event.pressed) {
                if (is_caps_word_on()) {
                    add_weak_mods(MOD_BIT(KC_LSFT));
                }
                tap_code16(KC_Z);
            }
        case COMBO_WH:
            return digraph_combo(record, KC_W, KC_H); // wh
        case COMBO_GH:
            return digraph_combo(record, KC_G, KC_H); // gh
        case COMBO_CH:
            return digraph_combo(record, KC_C, KC_H); // ch
        case COMBO_SH:
            return digraph_combo(record, KC_S, KC_H); // sh
        case COMBO_TH:
            return digraph_combo(record, KC_T, KC_H); // th
        case COMBO_PH:
            return digraph_combo(record, KC_P, KC_H); // ph
        case COMBO_QU:
            if (record->event.pressed) {
                if (is_caps_word_on()) {
                    add_weak_mods(MOD_BIT(KC_LSFT));
                }
                if (record->tap.count == 0) {
                    tap_code16(KC_Q);
                } else {
                    tap_code16(KC_Q);
                    unregister_mods(MOD_MASK_SHIFT);
                    tap_code16(KC_U);
                }
            }
            return false;
        case COMBO_PAREN:
            return shift_override_combo(record, KC_LPRN, KC_RPRN, KC_RSFT, KC_RCTL); // ( or )
        case COMBO_BRACE:
            return shift_override_combo(record, KC_LCBR, KC_RCBR, KC_RCTL, KC_RALT); // { or }
        case COMBO_BRACK:
            return shift_override_combo(record, KC_LBRC, KC_RBRC, KC_RSFT, KC_RALT); // [ or ]
        default:
            return true; // We did not handle this keypress
    }
}
