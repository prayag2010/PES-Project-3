#include "MemoryTest.h"
#include "MyMalloc.h"
#include "loggerFunctions.h"

uint32_t * verify_pattern(uint32_t * loc, size_t length, int8_t seed)
{
	uint32_t* list = (uint32_t*)malloc(length * sizeof(uint32_t));
	if( list == NULL)
		log_string("Memory allocation failed\n");
	uint8_t* input= (uint8_t*)malloc(length * sizeof(uint8_t));
	if( input == NULL)
			log_string("Memory allocation failed\n");
	//CHECK DATA TYPES
	uint8_t *temp = gen_pattern(input, length, seed);
	if( temp == NULL)
			log_string("Memory allocation failed\n");

	for (int i = 0; i < length; i++)
	{
		if (loc[i] != (uint32_t)temp[i])
			list[i] = &loc[i];
		else
			list[i] = 0;
	}
	return list;

}
