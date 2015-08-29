#include<stdio.h>
#include<assert.h>
char *strcpy(char *des, const char *src)
{
	assert((src != NULL) && (des != NULL));	
	char *address = des;
	while((*des++ = *src++) != '\0');
	return address;
}

int main()
{
	return 0;
}

