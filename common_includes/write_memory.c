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
