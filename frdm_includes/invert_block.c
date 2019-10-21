#include "MemoryTest.h"

mem_status invert_block(uint32_t * loc, size_t length)
{
	for ( int i = 0; i < length; i++)
	{
		*loc = *loc ^ (0x000000FF << (i * 8));
	}
	if (loc != NULL)
		return SUCCESS;
	else
		return FAILED;
}
