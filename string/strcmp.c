#include<stdio.h>
#include<assert.h>

int strcmp(const char *str1, const char *str2)
{
	while(*str1 == *str2)
	{
		if(*str1 == '\0')   
			return 0;
		str1++;
		str2++;
	}
	return *str1 - *str2;
}

int main()
{
	assert(strcmp("abc","abc") == 0);
	assert(strcmp("ab","abc") < 0); // '\0' = 0
	assert(strcmp("abc","aba") > 0);
	return 0;
}

