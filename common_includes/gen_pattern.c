#include "MemoryTest.h"

uint8_t* gen_pattern(uint8_t* pattern, uint8_t length, uint8_t seed)
{
	pattern[0] = seed;
	for (int i = 1; i <= length; i++)
	{
		pattern[i] = (pattern[i-1] +5) % 139;
		//printf("%hhu",pattern[i]);
	}
	return pattern;
}
