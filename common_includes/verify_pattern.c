#include "MemoryTest.h"
#include "MyMalloc.h"
#include "loggerFunctions.h"

uint32_t * verify_pattern(uint32_t * loc, size_t length, int8_t seed)
{
	#if defined frdm_debug || frdm_release                        	//Allocate the list to be returned using inbuilt malloc for KL25Z
		uint32_t *list = malloc(length * sizeof(size_t));
	#endif

	#if defined pc_debug || pc_release							  	//Allocate the list to be returned using custom malloc for PC
		uint32_t *list = MyMalloc(length * sizeof(size_t));
	#endif

	if( list == NULL)											  	//Check if the malloc returns NULL
	{
		offLED();													
		setRed();												  	//Set Red LED on
		log_string("Memory allocation failed\n");				  	//Log the error
	}
	#if defined frdm_debug || frdm_release							//Allocate the byte array using inbuilt malloc for KL25Z	
		uint8_t* input= (uint8_t*)malloc(length * sizeof(uint8_t));	
	#endif

	#if defined pc_debug || pc_release								//Allocate the byte array using custom malloc for PC
		uint8_t* input= (uint8_t*)MyMalloc(length * sizeof(uint8_t));
	#endif

	if( input == NULL)												//Check if the malloc returns NULL
	{
		offLED();
		setRed();													//Set Red LED on
		log_string("Memory allocation failed\n");					//Log error
	}

	gen_pattern(input, length, seed);								//Generate a pattern based on length and seed


	for (int i = 0; i < length; i++)
	{
		if (loc[i] != (uint32_t)input[i])							//Check each location to verify the pattern 
		{
			offLED();												
			setRed();												//If any of the patterns don't match set Red LED on
			list[i] = (uint32_t)&loc[i];							//Store the address of unmatched pattern
		}
			else
			list[i] = 0;											//If patterns match write 0
	}
	return list;													//return the list

}
