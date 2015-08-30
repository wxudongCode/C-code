#include<stdio.h>
#include<assert.h>

void *memcpy(void *dst, const void *src, int count)
{
	assert((src != NULL) && (dst != NULL));	
	char *pdst = dst;
	const char *psrc = src;
	if((dst <= src) || (dst >= src + count)) //正想运算条件 
	{
		while(count--)
			*pdst++ = *psrc++;
	}
	else
	{
		pdst = dst + count - 1;  //注意后移的个数与--的关系  
		psrc = src + count - 1;
		while(count--)
			*pdst-- = *psrc--;
	}
	return dst;
}

int main()
{
	return 0;
}

