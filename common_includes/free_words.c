#include "MemoryTest.h"
#include "MyMalloc.h"

void free_words(uint32_t* src)
{
	if (src == NULL)
	{
		//mem_status = WARNING;
		offLED();
		setRed();
		return;
	}
	else
	{
		MyFree(src);
	}
}
