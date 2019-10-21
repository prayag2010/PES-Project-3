
#include "MemoryTest.h"
#include "MyMalloc.h"

//FIX
//enum mem_statusop mem_status;

uint32_t * allocate_words(size_t length)
{
	if (length > ((4*1024)-24))
	{
		//mem_status = FAILED;
		return NULL;
	}
	else
	{
		return ((uint32_t*)malloc(length * sizeof(size_t)));
	}
}
