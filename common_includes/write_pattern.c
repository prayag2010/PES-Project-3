#include "MemoryTest.h"
#include "MyMalloc.h"
#include "loggerFunctions.h"

mem_status write_pattern(uint32_t * loc, size_t length, int8_t seed)
{
	#if defined frdm_debug || frdm_release                           //Allocate input byte array for gen_pattern using inbuilt malloc for KL25Z
		uint8_t* input= (uint8_t*)malloc(length * sizeof(uint8_t));
	#endif

	#if defined pc_debug || pc_release                               //Allocate input byte array for gen_pattern using custom malloc for PC
		uint8_t* input= (uint8_t*)MyMalloc(length * sizeof(uint8_t));
	#endif

	if( input == NULL)                                               //Check if the allocation fails
	{
		offLED();
		setRed();												     //Set Red LED on
		log_string("Memory allocation failed\n");					 //Log the erro
	}

	gen_pattern(input, length, seed);								 //Call the generate pattern function

	for (int i = 0; i < length; i++)
		loc[i] = input[i];											 //Write the generated attern to the memory
	if (loc != NULL)												 //Check if the pointer is NULL
		return SUCCESS;												 //Return success if no errors
	else
	{
		offLED();
		setRed();													//Set Red LED on
		return FAILED;												//Return failed in case of errors
	}
}

