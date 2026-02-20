/*
 * test.c
 *
 *  Created on: Dec 2, 2025
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
@brief Test_Start_Sequence, tests the start sequence
@param uint32_t *system_lights, pointer to the system lights
@return void
*/
void Test_Start_Sequence(uint32_t *system_lights){
	Start_Sequence(system_lights);
}

/**
@brief Test_Car_Switch, tests the car switch
@param uint32_t *system_lights, pointer to the system lights
@return void
*/
void Test_Car_Switch(uint32_t *system_lights){
	ShiftRegInit();


	    Light_ForceUpdate(0);

	    while (1){

	        if(TL1_CAR_HIT() == true){

	            Light_Clear(TL1_RED, system_lights);
	            Light_Set(TL1_GREEN, system_lights);
	            HAL_Delay(100);
	        } else {

	            Light_Clear(TL1_GREEN, system_lights);
	            Light_Toggle(TL1_RED, system_lights);
	            HAL_Delay(100);
	        }


	        if(TL2_CAR_HIT() == true){
	            Light_Clear(TL2_RED, system_lights);
	            Light_Set(TL2_GREEN, system_lights);
	            HAL_Delay(100);
	        } else {
	            Light_Clear(TL2_GREEN, system_lights);
	            Light_Toggle(TL2_RED, system_lights);
	            HAL_Delay(100);
	        }


	        if(TL3_CAR_HIT() == true){
	            Light_Clear(TL3_RED, system_lights);
	            Light_Set(TL3_GREEN, system_lights);
	            HAL_Delay(100);
	        } else {
	            Light_Clear(TL3_GREEN, system_lights);
	            Light_Toggle(TL3_RED, system_lights);
	            HAL_Delay(100);
	        }


	        if(TL4_CAR_HIT() == true){
	            Light_Clear(TL4_RED, system_lights);
	            Light_Set(TL4_GREEN, system_lights);
	            HAL_Delay(100);
	        } else {
	            Light_Clear(TL4_GREEN, system_lights);
	            Light_Toggle(TL4_RED, system_lights);
	            HAL_Delay(100);
	        }
	    }
	}

/**
@brief Test_PL_Button, tests the pedestrian button
@param uint32_t *system_lights, pointer to the system lights
@return void
*/
void Test_PL_Button(uint32_t *system_lights){
	ShiftRegInit();
	while (1){
		  Light_Clear(PL2_BLUE, system_lights);
		  Light_Clear(PL2_RED, system_lights);
		if(PL_TOP_HIT()== true || PL_LEFT_HIT()== true ){
			Light_Toggle(PL2_BLUE, system_lights);
			 HAL_Delay(100);
		} else {
			Light_Toggle(PL2_RED, system_lights);
			 HAL_Delay(100);
		}

	}


}

/**
@brief Test_Light_Abs, tests the light abs
@param uint32_t *system_lights, pointer to the system lights
@return void
*/
void Test_Light_Abs(uint32_t *system_lights){

	  ShiftRegInit();
	

	    while (1) {
	        
	        Light_Set(PL2_GREEN, system_lights);
	        HAL_Delay(1000);

	        
	        Light_Set(TL1_RED, system_lights);
	        HAL_Delay(1000);

	        
	        Light_Toggle(TL1_YELLOW, system_lights);
	        HAL_Delay(200);
	        Light_Toggle(TL1_YELLOW, system_lights);
	        HAL_Delay(200);

	       
	        Light_Clear(PL2_GREEN, system_lights);
	        HAL_Delay(1000);
	    }
}


/**
@brief Test_LED_Sequence, tests the led sequence
@param void
@return void
*/
void Test_LED_Sequence(void) {
    // 1. Initialize the driver
    ShiftRegInit();

    // 2. Loop forever blinking LEDs one by one
    while (1) {
        // Loop through all 24 LEDs (0 to 23)
       /*for (int i = 0; i < 24; i++) {
            // Create a 32-bit value with only the i-th bit set
            uint32_t led_pattern = (i);

            // Send to shift registers
            ShiftRegUpdate(led_pattern);

            // Wait so we can see it
            HAL_Delay(1000);
        }*/
    	ShiftRegUpdate(1);

    }
}
