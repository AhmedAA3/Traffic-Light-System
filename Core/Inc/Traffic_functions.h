/*
 * Traffic_functions.h
 *
 *  Created on: Dec 9, 2025
 *      Author: lukasnoel
 */

#ifndef INC_TRAFFIC_FUNCTIONS_H_
#define INC_TRAFFIC_FUNCTIONS_H_


void Start_Sequence(uint32_t *system_lights);

bool Vertical_Has_Car(void);
bool Horizontal_Has_Car(void);
void PL_Sequence(uint32_t *system_lights, uint32_t toggleFreq, uint32_t pedestrianDelay);
void TL_Switch_To_Red(uint32_t *system_lights, uint32_t orangeDelay, int lane);
void TL_Switch_To_Green(uint32_t *system_lights, uint32_t orangeDelay, int lane);
bool No_Cars_Rest(int car);

#endif /* INC_TRAFFIC_FUNCTIONS_H_ */
