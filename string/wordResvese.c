#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

/***字符串逆序***/
void strResvese(char *str, int start, int end) 
{
	int i = start;
	int j = end;
	while(i < j)
	{
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--; 
	}
}

/***单词逆序***/
void wordReverse(char *str)
{
	int len = strlen(str);
	int start, end;
	int i = 0;
	strResvese(str, 0, len-1);
	start = end = 0;
	while(str[i] != '\0')
	{
		if(str[i] == ' ')
		{
			strResvese(str, start, end-1);  //注意end的值 
			start = end+1;
			end = end+1;
		} 		
		else
			end++;
		i++;
	}
	strResvese(str, start, end-1);	
} 

int main()
{
	char a[100];
	gets(a);
	wordReverse(a);
	printf("%s\n", a);
	return 0;
}


