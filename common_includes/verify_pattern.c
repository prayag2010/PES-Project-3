#include "MemoryTest.h"
#include "MyMalloc.h"
#include "loggerFunctions.h"

uint32_t * verify_pattern(uint32_t * loc, size_t length, int8_t seed)
{
#if defined frdm_debug || frdm_release
	uint32_t *list = malloc(length * sizeof(size_t));
#endif

#if defined pc_debug || pc_release
	uint32_t *list = MyMalloc(length * sizeof(size_t));
#endif

	if( list == NULL)
	{
		offLED();
		setRed();
		log_string("Memory allocation failed\n");
	}
#if defined frdm_debug || frdm_release
	uint8_t* input= (uint8_t*)malloc(length * sizeof(uint8_t));
#endif

#if defined pc_debug || pc_release
	uint8_t* input= (uint8_t*)MyMalloc(length * sizeof(uint8_t));
#endif

	if( input == NULL)
	{
		offLED();
		setRed();
		log_string("Memory allocation failed\n");
	}
	//CHECK DATA TYPES

	gen_pattern(input, length, seed);

	if( input == NULL)
	{
		offLED();
		setRed();
		log_string("Memory allocation failed\n");
	}

	for (int i = 0; i < length; i++)
	{
		if (loc[i] != (uint32_t)input[i])
		{
			offLED();
			setRed();
			list[i] = (uint32_t)&loc[i];
		}
			else
			list[i] = 0;
	}
	return list;

}
