
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
	uint32_t *temp = malloc(length * sizeof(size_t));
	if( temp == NULL)
		log_string("Memory allocation failed\n");
	else
		return (temp);
}
