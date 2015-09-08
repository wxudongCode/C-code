/*****************************************************************************     
  Author: wxudong     
  Date: 2015-09-07
  Description: Ìæ»»×Ö·û´® 
******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

/*** BF·¨²éÕÒ×Ó×Ö·û´® ***/ 
char *strMatchBF(char *srcstr, char *substr)
{
	char *psub = substr;
	char *psrc = srcstr;
	int len = strlen(substr);
	while(*psrc != '\0')
	{
		if(*psrc == *psub)
		{
			psrc++;
			psub++;
		}
		else
		{
			srcstr++;
			psrc = srcstr;
			psub = substr;
		}
		if(*psub == '\0')
			return (char *)(psrc - len);
	}
	return 0;
}

int strReplace(char *result, char *source, char *seach, char *repstr)
{
	char *p;
	int num = 0;
	int slen = strlen(seach);
	int rlen = strlen(repstr);
	do
	{
		int nlen;
		p = strMatchBF(source, seach);
		if(p == 0)
		{
			strcpy(result, source);
			return num;
		}
		num++;
		nlen = p - source;
		memcpy(result, source, nlen);
		memcpy(result + nlen, repstr, rlen);
		source = p + slen;
		result = result + nlen + rlen;
	}while(p);
	return num;
}

int main(void)
{   
	char source[100];
	char seach[100];
	char repstr[100];
	char result[100];
	gets(source);
	gets(seach);
	gets(repstr);
	printf("replace num : %d\n", strReplace(result, source, seach, repstr));
	printf("replace result : %s\n", result);
   	return 0;  
}





