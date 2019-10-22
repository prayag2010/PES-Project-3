#include "MemoryTest.h"
#include "MyMalloc.h"
#include "loggerFunctions.h"

uint32_t * verify_pattern(uint32_t * loc, size_t length, int8_t seed)
{
#ifdef frdm_debug
	uint32_t *list = malloc(length * sizeof(size_t));
#endif

#ifdef pc_debug
	uint32_t *list = MyMalloc(length * sizeof(size_t));
#endif

	if( list == NULL)
	{
		offLED();
		setRed();
		log_string("Memory allocation failed\n");
	}
#ifdef frdm_debug
	uint8_t* input= (uint8_t*)malloc(length * sizeof(uint8_t));
#endif

#ifdef pc_debug
	uint8_t* input= (uint8_t*)MyMalloc(length * sizeof(uint8_t));
#endif

	if( input == NULL)
	{
		offLED();
		setRed();
		log_string("Memory allocation failed\n");
	}
	//CHECK DATA TYPES

	uint8_t *temp = gen_pattern(input, length, seed);

	if( temp == NULL)
	{
		offLED();
		setRed();
		log_string("Memory allocation failed\n");
	}

	for (int i = 0; i < length; i++)
	{
		if (loc[i] != (uint32_t)temp[i])
		{
			offLED();
			setRed();
			list[i] = &loc[i];
		}
			else
			list[i] = 0;
	}
	return list;

}
