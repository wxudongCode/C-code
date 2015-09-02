#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>


/***�ж��ַ����Ƿ�Ϊ����***/ 
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

/***�ַ���������Ӵ�***/ 
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
		//�������ļ���
		left = pstr - 1;
		right = pstr + 1;
		while(left >= str && *right != '\0' && *left == *right)  //��Ҫ���� 
		{
			left--;
			right++;
			oddlen += 2; 
		}
		if(oddlen > maxlen)
			maxlen = oddlen;
			
		//ż�����ļ���
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
			
		pstr++; //���� 
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


