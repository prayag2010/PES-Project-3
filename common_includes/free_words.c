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
#if defined frdm_debug || frdm_release
		free(src);
#endif
#if defined pc_debug || pc_release
		MyFree(src);
#endif
	}
}
