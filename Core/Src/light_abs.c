/*
 * light_abs.c
 *
 *  Created on: Dec 8, 2025
 *      Author: lukasnoel
 */

#include "light_abs.h"
#include "shiftreg.h"




void Light_Set(uint32_t light_mask, uint32_t *state_ptr) {
    *state_ptr |= light_mask;     // Modify the variable in main directly
    ShiftRegUpdate(*state_ptr);   // Update hardware
}

void Light_Clear(uint32_t light_mask, uint32_t *state) {
    *state &= ~light_mask;
    ShiftRegUpdate(*state);
}

void Light_Toggle(uint32_t light_mask, uint32_t *state) {
    // XOR (^) flips bits
    *state ^= light_mask;

    ShiftRegUpdate(*state);
}

void Light_ForceUpdate(uint32_t state) {
    ShiftRegUpdate(state);
}
