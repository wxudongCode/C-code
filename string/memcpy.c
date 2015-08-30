#include<stdio.h>
#include<assert.h>

void *memcpy(void *des, const void *src, int count)
{
	assert((src != NULL) && (des != NULL));	
	char *pdes = des;
	const char *psrc = src;
	while(count--)
		*pdes++ = *psrc++;
	return des;
}

int main()
{
	return 0;
}

