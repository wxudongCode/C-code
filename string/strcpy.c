#include<stdio.h>
#include<assert.h>
char *strcpy(char *dst, const char *src)
{
	assert((src != NULL) && (dst != NULL));	
	char *address = dst;
	while((*dst++ = *src++) != '\0');
	return address;
}

int main()
{
	return 0;
}

