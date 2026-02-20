/*
 * shiftreg.h
 *
 *  Created on: Dec 2, 2025
 *      Author: lukasnoel
 */

#ifndef INC_SHIFTREG_H_
#define INC_SHIFTREG_H_

#include <stdint.h>
#include <stdbool.h>
#include "main.h" // For HAL types and GPIO pin defines

// --- Exported Variables (Defined in main.c) ---
// These declarations tell the compiler that these variables exist elsewhere.
extern SPI_HandleTypeDef hspi3;

// --- Exported Function Prototypes ---

/**
 * @brief Initializes the Shift Register pins.
 * Sets the Enable pin (OE#) to active (LOW) and the Reset pin (MR#) to inactive (HIGH).
 */
void ShiftRegInit(void); // Note: Corrected function name convention is ShiftRegInit

/**
 * @brief Updates the shift register outputs with the 24 bits provided.
 *
 * @param bits The 24-bit value (uint32_t) to send to the three shift registers.
 * @return 1 if SPI transmission was successful (HAL_OK), 0 otherwise.
 */
uint8_t ShiftRegUpdate(uint32_t bits);

// Note: The structure you provided does not contain a buffer.
// If you implement ShiftRegUpdate this way, you MUST call it every time a bit changes.
// The structure provided in previous answers (using a static buffer and separate SetOutput/Update)
// is required for the application's complexity.



#endif /* INC_SHIFTREG_H_ */
