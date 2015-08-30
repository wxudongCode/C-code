#include<stdio.h>
#include<assert.h>

void *memcpy(void *dst, const void *src, int count)
{
	assert((src != NULL) && (dst != NULL));	
	char *pdst = dst;
	const char *psrc = src;
	while(count--)
		*pdst++ = *psrc++;
	return dst;
}

int main()
{
	return 0;
}

