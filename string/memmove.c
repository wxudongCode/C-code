#include<stdio.h>
#include<assert.h>

void *memcpy(void *dst, const void *src, int count)
{
	assert((src != NULL) && (dst != NULL));	
	char *pdst = dst;
	const char *psrc = src;
	if((dst <= src) || (dst >= src + count)) //������������ 
	{
		while(count--)
			*pdst++ = *psrc++;
	}
	else
	{
		pdst = dst + count - 1;  //ע����Ƶĸ�����--�Ĺ�ϵ  
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

