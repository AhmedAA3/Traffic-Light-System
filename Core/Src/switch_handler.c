/*
 * switch_handler.c
 *
 *  Created on: Dec 8, 2025
 *      Author: lukasnoel
 */
#include <stdint.h>   // För int8_t
#include <stdbool.h>
#include "gpio.h"

/**
@brief TL1_CAR_HIT, checks if the car switch is hit
@param void
@return bool
*/
bool TL1_CAR_HIT(void)
{ if (HAL_GPIO_ReadPin(TL1_CAR_GPIO_Port, TL1_CAR_Pin) == 0) return true;
 else return false;
 }

/**
@brief TL2_CAR_HIT, checks if the car switch is hit
@param void
@return bool
*/
bool TL2_CAR_HIT(void)
{ if (HAL_GPIO_ReadPin(TL2_CAR_GPIO_Port, TL2_CAR_Pin) == 0) return true;
 else return false;
 }

/**
@brief TL3_CAR_HIT, checks if the car switch is hit
@param void
@return bool
*/
bool TL3_CAR_HIT(void)
{ if (HAL_GPIO_ReadPin(TL3_CAR_GPIO_Port, TL3_CAR_Pin) == 0) return true;
 else return false;
 }

/**
@brief TL4_CAR_HIT, checks if the car switch is hit
@param void
@return bool
*/
bool TL4_CAR_HIT(void)
{ if (HAL_GPIO_ReadPin(TL4_CAR_GPIO_Port, TL4_CAR_Pin) == 0) return true;
 else return false;
 }

