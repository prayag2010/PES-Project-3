#include "MemoryTest.h"
#include "MyMalloc.h"
#include "loggerFunctions.h"

mem_status write_pattern(uint32_t * loc, size_t length, int8_t seed)
{
	uint8_t* input= (uint8_t*)malloc(length * sizeof(uint8_t));
	if( input == NULL)
		log_string("Memory allocation failed\n");

	uint8_t *temp = gen_pattern(input, length, seed);
	if( temp == NULL)
			log_string("Memory allocation failed\n");
	for (int i = 0; i < length; i++)
		loc[i] = temp[i];//(*loc & 0xFFFFFF00) | *temp++;
	if (loc != NULL)
		return SUCCESS;
	else
		return FAILED;
}
