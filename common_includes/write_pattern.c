#include "MemoryTest.h"
#include "MyMalloc.h"
#include "loggerFunctions.h"

mem_status write_pattern(uint32_t * loc, size_t length, int8_t seed)
{
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

	uint8_t *temp = gen_pattern(input, length, seed);

	if( temp == NULL)
	{
		offLED();
		setRed();
		log_string("Memory allocation failed\n");
	}
	for (int i = 0; i < length; i++)
		loc[i] = temp[i];//(*loc & 0xFFFFFF00) | *temp++;
	if (loc != NULL)
		return SUCCESS;
	else
	{
		offLED();
		setRed();
		return FAILED;
	}
}

