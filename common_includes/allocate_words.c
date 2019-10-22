
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
#ifdef frdm_debug
	uint32_t *temp = malloc(length * sizeof(size_t));
#endif

#ifdef pc_debug
	uint32_t *temp = MyMalloc(length * sizeof(size_t));
#endif

	if( temp == NULL)
	{
		offLED();
		setRed();
		log_string("Memory allocation failed\n");
	}
	else
		return (temp);
}
