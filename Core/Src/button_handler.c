/*
 * button_handler.c
 *
 *  Created on: Dec 4, 2025
 *      Author: lukasnoel
 */
#include <stdint.h>   // För int8_t
#include <stdbool.h>
#include "gpio.h"

/**
@brief PL_LEFT_HIT, checks if the left button is hit
@param void
@return bool, true if the button is hit, false if not
*/
bool PL_LEFT_HIT(void)
{ if (HAL_GPIO_ReadPin(PL1_Switch_GPIO_Port, PL1_Switch_Pin) == 0) return true;
 else return false;
 }

/**
@brief PL_TOP_HIT, checks if the top button is hit
@param void
@return bool, true if the button is hit, false if not
*/
bool PL_TOP_HIT(void)
{ if (HAL_GPIO_ReadPin(PL2_Switch_GPIO_Port, PL2_Switch_Pin) == 0) return true;
 else return false;
 }
