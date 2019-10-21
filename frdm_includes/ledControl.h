/*
 * ledControl.h
 *
 *  Created on: Oct 21, 2019
 *      Author: rahul
 */

#ifndef FRDM_INCLUDES_LEDCONTROL_H_
#define FRDM_INCLUDES_LEDCONTROL_H_

#include "../board/board.h"

void init_pins();

void offLED();

void setRed();

void setGreen();

void setBlue();

#endif /* FRDM_INCLUDES_LEDCONTROL_H_ */
