#include "MemoryTest.h"

void gen_pattern(uint8_t* pattern, uint8_t length, uint8_t seed)
{
	pattern[0] = seed;							//Initialise the first element in the patter byte with seed
	for (int i = 1; i <= length; i++)			//Loop from 1 to length
	{
		pattern[i] = (pattern[i-1] +5) % 139;	//Linear congruential generator
	}
}

