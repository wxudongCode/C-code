#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

/***字符串翻转***/
char *reverse(char *str)
{
	int start = 0;
	int end = strlen(str) - 1;
	while(start < end)
	{
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
	return str;
}

/***字符串转整型atoi***/
long strToInt(char *str) 
{
	long temp = 0;
	int flag = 1;
	if(str == NULL)
		return 0;
	if(*str == '-')
		flag = -1;
	if(*str == '-' || *str == '+')
		str++;
	while(*str >= '0' && *str<= '9')
	{
		temp = 10 * temp + *str - '0';
		str++;
	}
	temp = temp * flag;
	return temp;
}

/***整型转字符串itoa***/
void intToStr(long num, char *str) 
{
	int flag = 1;
	int i = 0;
	if(num < 0)
	{
		num = -num;
		flag = 0;
	}
	while(num > 0)
	{
		str[i++] = num % 10 + '0';
		num = num/10;
	}
	if(flag == 0)
		str[i++] = '-';
	str[i] = '\0';
	str = reverse(str);
}

int main()
{
	char a[100];
	char b[100] = {0};
	long num;
	gets(a);
	num = strToInt(a);
	printf("%ld \n", num);
	intToStr(num, b);
	printf("%s \n", b);
	return 0;
}


