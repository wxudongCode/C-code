#include<stdio.h>
#include<assert.h>

char *strcat(char *dst, const char *src)
{
	assert((src != NULL) && (dst != NULL));	
	char *address = dst;
	while(*dst != '\0')
		dst++;
	while(*src != '\0')
		*dst++ = *src++;
	return address;
}

int main()
{
	return 0;
}

