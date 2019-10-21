/*
 * loggerFunctions.c
 *
 *  Created on: Oct 20, 2019
 *      Author: rahul
 */

#include "loggerFunctions.h"
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

void log_enable(void)
{
	loggerEnable = true;
}

void log_disable(void)
{
	loggerEnable = false;
}

bool log_status(void)
{
	return(loggerEnable);
}

void log_data(uint32_t *inAddress, size_t length)
{
	if(loggerEnable){
		printf("%p: ", inAddress);
		for(size_t i = 0; i < length; i++){
			printf("%d ",*(inAddress + i));
		}
		printf("\n");
	}
}

void log_string(char *inString)
{
	if(log_status)
		printf("%s\n", inString);
}

void log_integer(int *inAddress)
{
	if(loggerEnable)
		printf("%d\n", *inAddress);
}
