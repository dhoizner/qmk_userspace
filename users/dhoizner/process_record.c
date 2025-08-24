#include "dhoizner.h"
#include "select_word.h"
#include "macros.h"
#include "sentence_case.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_macro_event(keycode, record)) {
        return false; // We handled this keypress in the macro processor
    }
    return true;
}

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    // This is taken from https://docs.qmk.fm/features/combo
    // If you want *all* combos that have Mod-Tap/Layer-Tap/Momentary keys in their chord to be tap-only, this is for you:
    uint16_t key;
    uint8_t  idx = 0;
    while ((key = pgm_read_word(&combo->keys[idx])) != COMBO_END) {
        switch (key) {
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            case QK_MOMENTARY ... QK_MOMENTARY_MAX:
                return true;
        }
        idx += 1;
    }
    return false;
}
