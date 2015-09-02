#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>


/***判断字符串是否为回文***/ 
int isMoslem(char *str) 
{
	int low = 0;
	int high = strlen(str) - 1;
	while(low < high)
	{
		if(str[low] != str[high])
			return 0;
		low++;
		high--;
	}
	return 1;
}

/***字符串最长回文子串***/ 
int getMaxMoslem(char *str)
{
	if(str == NULL)
		return 0;
	char *pstr = str;
	int maxlen = 0;
	while(*pstr != '\0')
	{
		char *left, *right;
		int oddlen = 1;
		int evenlen = 0;
		//奇数回文计算
		left = pstr - 1;
		right = pstr + 1;
		while(left >= str && *right != '\0' && *left == *right)  //重要条件 
		{
			left--;
			right++;
			oddlen += 2; 
		}
		if(oddlen > maxlen)
			maxlen = oddlen;
			
		//偶数回文计算
		left = pstr;
		right = pstr + 1;
		while(left >= str && *right != '\0' && *left == *right) 
		{
			left--;
			right++;
			evenlen += 2; 
		}
		if(evenlen > maxlen)
			maxlen = evenlen;
			
		pstr++; //易忘 
	}
	return maxlen;
}
 
int main()
{
	char a[100];
	gets(a);	
	printf("%d \n", isMoslem(a));
	printf("%d \n", getMaxMoslem(a));
	return 0;
}


