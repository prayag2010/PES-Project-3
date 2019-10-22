/*
 * @file write_memory.c
 * @brief Source file that writes a value to a memory location
 *
 * This source file takes an address and an integer as in input, and
 * writes the integer at that address
 *
 * @authors Rahul Ramaprasad, Prayag Milan Desai
 * @date October 20 2019
 * @verison 1.0
 */

#include "MemoryTest.h"

mem_status write_memory(uint32_t * loc, uint8_t value)
{
		*loc = (*loc & 0xFFFFFF00) | value;  //Write the last 8 bits to the memory
		if (loc != NULL)					 //Check if pointer is NULL
			return SUCCESS;					 //Return success enum if no erros
		else
		{
			offLED();		
			setRed();						 //Set Red LED on
			return FAILED;					 //Return failed enum in case of errors
		}
}
