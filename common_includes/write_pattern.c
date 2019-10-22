#include "MemoryTest.h"
#include "MyMalloc.h"
#include "loggerFunctions.h"

mem_status write_pattern(uint32_t * loc, size_t length, int8_t seed)
{
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

	gen_pattern(input, length, seed);

	if( input == NULL)
	{
		offLED();
		setRed();
		log_string("Memory allocation failed\n");
	}
	for (int i = 0; i < length; i++)
		loc[i] = input[i];//(*loc & 0xFFFFFF00) | *temp++;
	if (loc != NULL)
		return SUCCESS;
	else
	{
		offLED();
		setRed();
		return FAILED;
	}
}

