/*
 * Traffic_functions.c
 *
 *  Created on: Dec 9, 2025
 *      Author: lukasnoel
 */

#include "test.h"
#include "shiftreg.h"
#include "main.h"
#include <string.h>
#include "button_handler.h"
#include "gpio.h"
#include "light_abs.h"
#include <stdbool.h>
#include "switch_handler.h"

/**
@brief Start_Sequence, starts the traffic sequence
@param uint32_t *system_lights, pointer to the system lights
@return void
*/
void Start_Sequence(uint32_t *system_lights){
	ShiftRegInit();
	Light_ForceUpdate(0);
	Light_Set(PL2_RED, system_lights);
	Light_Set(TL4_GREEN, system_lights);
	Light_Set(TL2_GREEN, system_lights);
	Light_Set(TL1_RED, system_lights);
	Light_Set(TL3_RED, system_lights);

}

/**
@brief Vertical_Has_Car, checks if there is a car in the vertical direction
@param void
@return bool, true if there is a car, false if not
*/
bool Vertical_Has_Car(void) {
    return (TL2_CAR_HIT() || TL4_CAR_HIT());
}

/**
@brief Horizontal_Has_Car, checks if there is a car in the horizontal direction
@param void
@return bool, true if there is a car, false if not
*/
bool Horizontal_Has_Car(void) {
    return (TL1_CAR_HIT() || TL3_CAR_HIT());
}

/**
@brief PL_Sequence, handles the pedestrian light sequence
@param uint32_t *system_lights, pointer to the system lights
uint32_t toggleFreq, toggle frequency
uint32_t pedestrianDelay, pedestrian delay
@return void
*/
void PL_Sequence(uint32_t *system_lights, uint32_t toggleFreq, uint32_t pedestrianDelay){
	uint32_t startTime = HAL_GetTick();
	while((HAL_GetTick() - startTime) < pedestrianDelay){
		Light_Toggle(PL2_BLUE, system_lights);
		HAL_Delay(toggleFreq);
	}
	Light_Clear(PL2_BLUE, system_lights);

}

/**
@brief TL_Switch_To_Red, handles the traffic light switch to red
@param uint32_t *system_lights, pointer to the system lights
uint32_t orangeDelay, orange delay
int lane, lane to switch to red
@return void
*/
void TL_Switch_To_Red(uint32_t *system_lights, uint32_t orangeDelay, int lane){
	switch (lane) {
	    case 1:
	    	Light_Clear(TL1_GREEN, system_lights);
	    	Light_Clear(TL3_GREEN, system_lights);
	    	Light_Clear(TL2_RED, system_lights);
	    	Light_Clear(TL4_RED, system_lights);
	    	Light_Clear(PL2_GREEN, system_lights);
	    	Light_Set(PL2_RED, system_lights);


	    	Light_Set(TL4_YELLOW, system_lights);
	    	Light_Set(TL2_YELLOW, system_lights);
	    	Light_Set(TL1_YELLOW, system_lights);
	    	Light_Set(TL3_YELLOW, system_lights);

	    	HAL_Delay(orangeDelay);

	    	Light_Clear(TL2_YELLOW, system_lights);
	    	Light_Clear(TL4_YELLOW, system_lights);
	    	Light_Clear(TL1_YELLOW, system_lights);
	    	Light_Clear(TL3_YELLOW, system_lights);

	    	Light_Set(TL1_RED, system_lights);
	    	Light_Set(TL3_RED, system_lights);
	    	Light_Set(TL4_GREEN, system_lights);
	    	Light_Set(TL2_GREEN, system_lights);

	        break; // Exits the switch block

	    case 2:
	    	Light_Clear(TL2_GREEN, system_lights);
	    	Light_Clear(TL4_GREEN, system_lights);
	    	Light_Clear(TL1_RED, system_lights);
	    	Light_Clear(TL3_RED, system_lights);


	    	Light_Set(TL4_YELLOW, system_lights);
	    	Light_Set(TL2_YELLOW, system_lights);
	    	Light_Set(TL1_YELLOW, system_lights);
	    	Light_Set(TL3_YELLOW, system_lights);

	    	HAL_Delay(orangeDelay);

	    	Light_Clear(TL2_YELLOW, system_lights);
	    	Light_Clear(TL4_YELLOW, system_lights);
	    	Light_Clear(TL1_YELLOW, system_lights);
	    	Light_Clear(TL3_YELLOW, system_lights);

	    	Light_Set(TL4_RED, system_lights);
	    	Light_Set(TL2_RED, system_lights);
	    	Light_Set(TL1_GREEN, system_lights);
	    	Light_Set(TL3_GREEN, system_lights);
	    	Light_Clear(PL2_RED, system_lights);
	    	Light_Set(PL2_GREEN, system_lights);

	        break;

	    default:
	        // Optional: Code to run if no cases match
	        break;
	}
}

/**
@brief TL_Switch_To_Green, handles the traffic light switch to green
@param uint32_t *system_lights, pointer to the system lights
uint32_t orangeDelay, orange delay
int lane, lane to switch to green
@return void
*/
void TL_Switch_To_Green(uint32_t *system_lights, uint32_t orangeDelay, int lane){
	switch (lane) {
	    case 1:
	    	Light_Clear(TL1_RED, system_lights);
	    	Light_Clear(TL3_RED, system_lights);
	    	Light_Clear(TL2_GREEN, system_lights);
	    	Light_Clear(TL4_GREEN, system_lights);



	    	Light_Set(TL4_YELLOW, system_lights);
	    	Light_Set(TL2_YELLOW, system_lights);
	    	Light_Set(TL1_YELLOW, system_lights);
	    	Light_Set(TL3_YELLOW, system_lights);

	    	HAL_Delay(orangeDelay);

	    	Light_Clear(TL2_YELLOW, system_lights);
	    	Light_Clear(TL4_YELLOW, system_lights);
	    	Light_Clear(TL1_YELLOW, system_lights);
	    	Light_Clear(TL3_YELLOW, system_lights);

	    	Light_Clear(PL2_RED, system_lights);
	    	Light_Set(PL2_GREEN, system_lights);
	    	Light_Set(TL1_GREEN, system_lights);
	    	Light_Set(TL3_GREEN, system_lights);
	    	Light_Set(TL4_RED, system_lights);
	    	Light_Set(TL2_RED, system_lights);
	    	break;

	    case 2:
	    	Light_Clear(TL1_GREEN, system_lights);
	    	Light_Clear(TL3_GREEN, system_lights);
	    	Light_Clear(TL2_RED, system_lights);
	    	Light_Clear(TL4_RED, system_lights);



	    	Light_Set(TL4_YELLOW, system_lights);
	    	Light_Set(TL2_YELLOW, system_lights);
	    	Light_Set(TL1_YELLOW, system_lights);
	    	Light_Set(TL3_YELLOW, system_lights);

	    	HAL_Delay(orangeDelay);

	    	Light_Clear(TL2_YELLOW, system_lights);
	    	Light_Clear(TL4_YELLOW, system_lights);
	    	Light_Clear(TL1_YELLOW, system_lights);
	    	Light_Clear(TL3_YELLOW, system_lights);

	    	Light_Clear(PL2_GREEN, system_lights);
	    	Light_Set(PL2_RED, system_lights);
	    	Light_Set(TL1_RED, system_lights);
	    	Light_Set(TL3_RED, system_lights);
	    	Light_Set(TL4_GREEN, system_lights);
	    	Light_Set(TL2_GREEN, system_lights);
	        break;

	    default:
	        // Optional: Code to run if no cases match
	        break;
	}
}
