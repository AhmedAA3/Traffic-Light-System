/*
 * shiftreg.c
 *
 *  Created on: Dec 2, 2025
 *     
 */

#include <stdint.h>
#include <stdbool.h>
#include "main.h"
#include "shiftreg.h"

extern SPI_HandleTypeDef hspi3;

/**
@brief ShiftRegInit, initialize the shift register
@param void
@return void
*/

void ShiftRegInit (void){
	HAL_GPIO_WritePin(_595_Enable_GPIO_Port,_595_Enable_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(_595_Reset_GPIO_Port,_595_Reset_Pin, GPIO_PIN_SET);
}

/**
@brief ShiftRegUpdate, update the shift register
@param uint32_t bits, bits to be sent to the shift register
@return uint8_t, 1 if successful, 0 if not
*/
uint8_t ShiftRegUpdate(uint32_t bits){
	uint32_t byteToReg;
	byteToReg = 0;
	byteToReg = bits;


	HAL_StatusTypeDef spiTransmitStatus = HAL_SPI_Transmit(&hspi3, &byteToReg, 3, HAL_MAX_DELAY);
	HAL_GPIO_WritePin(_595_STCP_GPIO_Port, _595_STCP_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(_595_STCP_GPIO_Port, _595_STCP_Pin, GPIO_PIN_RESET);

	if(spiTransmitStatus == HAL_OK)
		return 1;
	else
		return 0;



}
static uint32_t shiftRegState = 0;

