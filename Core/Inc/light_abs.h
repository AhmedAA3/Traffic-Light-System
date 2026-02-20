/*
 * light_abs.h
 *
 *  Created on: Dec 8, 2025
 *      Author: lukasnoel
 */

#ifndef INC_LIGHT_ABS_H_
#define INC_LIGHT_ABS_H_

#include <stdint.h>
#define TL3_RED (1 << 0)
#define TL3_YELLOW (1 << 1)
#define TL3_GREEN (1 << 2)
#define TL4_RED (1 << 3)
#define TL4_YELLOW (1 << 4)
#define TL4_GREEN (1 << 5)
#define TL2_RED (1 << 8)
#define TL2_YELLOW (1 << 9)
#define TL2_GREEN (1 << 10)
#define PL2_RED (1 << 11)
#define PL2_GREEN (1 << 12)
#define PL2_BLUE (1 << 13)
#define TL1_RED (1 << 16)
#define TL1_YELLOW (1 << 17)
#define TL1_GREEN (1 << 18)
#define PL1_RED (1 << 19)
#define PL1_GREEN (1 << 20)
#define PL1_BLUE (1 << 21)


void Light_Set(uint32_t light_mask, uint32_t *state_ptr);
//clears a specific light
void Light_Clear(uint32_t light_mask, uint32_t *state);
//flips lights (useful for blue PL)
void Light_Toggle(uint32_t light_mask, uint32_t *state);

// Forces an update (useful for initialization)
void Light_ForceUpdate(uint32_t state);
#endif /* INC_LIGHT_ABS_H_ */
