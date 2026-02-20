/*
 * Traffic_logic.c
 *
 *  Created on: Dec 9, 2025
 *      Author: lukasnoel
 */




#include "main.h"
#include <string.h>
#include "button_handler.h"
#include "light_abs.h"
#include <stdbool.h>
#include "switch_handler.h"
uint32_t toggleFreq = 300;
uint32_t pedestrianDelay = 5000;
uint32_t orangeDelay = 1000;
uint32_t walkingDelay = 5000;
uint32_t greenDelay = 5000;
uint32_t redDelayMax = 5000;



/**
@brief TrafficState, enum for the traffic state
@enum TrafficState, enum for the traffic state
@var STATE_VERTICAL_GREEN, vertical green state
@var STATE_HORIZONTAL_GREEN, horizontal green state
*/
typedef enum {
    STATE_VERTICAL_GREEN,
    STATE_HORIZONTAL_GREEN
} TrafficState;

/**
@brief trafficlight, main traffic light function
@param void
@return void
*/
void trafficlight(void){
    uint32_t system_lights = 0;


    Start_Sequence(&system_lights);

    TrafficState currentState = STATE_VERTICAL_GREEN;
    uint32_t stateEntryTime = HAL_GetTick(); // Track when the current light turned green

    while(1){
        uint32_t currentTime = HAL_GetTick();
        uint32_t timeInState = currentTime - stateEntryTime;

        switch (currentState) {

            case STATE_VERTICAL_GREEN:
                bool switchNeeded = false;


                // If empty switch now
                if (!Vertical_Has_Car() && Horizontal_Has_Car()) {
                    switchNeeded = true;
                }

                // Max wait time.
                // If they are waiting, and we have been green too long
                else if (Horizontal_Has_Car() && (timeInState > redDelayMax)) {
                    switchNeeded = true;
                }


                // If NO cars anywhere, swap periodically
                else if (!Vertical_Has_Car() && !Horizontal_Has_Car() && (timeInState > greenDelay)) {
                    switchNeeded = true;
                }




                // Transistion
                if (switchNeeded) {

                    TL_Switch_To_Red(&system_lights, orangeDelay, 2);

                    currentState = STATE_HORIZONTAL_GREEN;
                    stateEntryTime = HAL_GetTick(); // Reset timer for new state
                }
                break;


            case STATE_HORIZONTAL_GREEN:
                switchNeeded = false;


                if (!Horizontal_Has_Car() && Vertical_Has_Car()) {
                    switchNeeded = true;
                }


                else if (Vertical_Has_Car() && (timeInState > redDelayMax)) {
                    switchNeeded = true;
                }


                else if (!Horizontal_Has_Car() && !Vertical_Has_Car() && (timeInState > greenDelay)) {
                    switchNeeded = true;
                }


                if (switchNeeded) {

                    TL_Switch_To_Red(&system_lights, orangeDelay, 1);

                    currentState = STATE_VERTICAL_GREEN;
                    stateEntryTime = HAL_GetTick();
                }
                break;
        }


        if (PL_TOP_HIT() == true) {

             if (currentState == STATE_VERTICAL_GREEN) {
            	 PL_Sequence(&system_lights, toggleFreq, pedestrianDelay);
            	 TL_Switch_To_Red(&system_lights, orangeDelay, 2);
            	 HAL_Delay(walkingDelay);
            	 TL_Switch_To_Green(&system_lights, orangeDelay, 2);
             }
        }

        // Small delay
        HAL_Delay(10);
    }
}
