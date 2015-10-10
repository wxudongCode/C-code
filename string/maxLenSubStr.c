/*****************************************************************************     
  Author: wxudong     
  Date: 2015-09-07
  Description: 输出两个字符串的最长子串 
******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>


int maxLenSubStr(char *str1, char *str2, char *c)
{
	int i, j, row;
	int max = 0;
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int a[len1][len2];
	for(i=0; i<len1; i++)
		for(j=0; j<len2; j++)
			a[i][j] = 0;
			
	for(i=0; i<len1; i++)
		for(j=0; j<len2; j++)
		{
			if(str1[i] == str2[j])
			{
				a[i+1][j+1] = a[i][j] + 1;
				if(a[i+1][j+1] > max)
				{
					max = a[i+1][j+1];
					row = i;
				} 
			} 
		} 
	row = row - max + 1;
	for(i=0; i<max; i++)
	{
		c[i] = str1[row];
		row++;
	}
	c[i] = '\0';
}


int main(void)
{   
	char a[100];
	char b[100];
	char c[100];
	gets(a);
	gets(b);
	maxLenSubStr(a, b, c);
	printf("%s", c);
   	return 0;  
}





