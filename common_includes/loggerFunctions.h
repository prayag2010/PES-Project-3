/*
 * loggerFunctions.h
 *
 *  Created on: Oct 20, 2019
 *      Author: rahul
 */

#ifndef LOGGERFUNCTIONS_H_
#define LOGGERFUNCTIONS_H_

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

extern bool loggerEnable;

void log_enable(void);
void log_disable(void);
bool log_status(void);
void log_data(uint32_t *inAddress, size_t length);
void log_string(char *inString);
void log_integer(int *inAddress);

#endif /* LOGGERFUNCTIONS_H_ */
