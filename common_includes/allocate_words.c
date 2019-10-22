
#include "MemoryTest.h"
#include "MyMalloc.h"
#include "loggerFunctions.h"
//FIX
//enum mem_statusop mem_status;

uint32_t * allocate_words(size_t length)
{
//	if (length > ((4*1024)-24))
//	{
//		//mem_status = FAILED;
//		return NULL;
//	}
#if defined frdm_debug || frdm_release
	uint32_t *temp = malloc(length * sizeof(size_t));
#endif

#if defined pc_debug || pc_release
	uint32_t *temp = MyMalloc(length * sizeof(size_t));
#endif

	if( temp == NULL)
	{
		offLED();
		setRed();
		log_string("Memory allocation failed\n");
		return NULL;
	}
	else
		return (temp);
}
