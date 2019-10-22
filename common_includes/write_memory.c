#include "MemoryTest.h"

mem_status write_memory(uint32_t * loc, uint8_t value)
{
		*loc = (*loc & 0xFFFFFF00) | value;
		if (loc != NULL)
			return SUCCESS;
		else
			return FAILED;
}
