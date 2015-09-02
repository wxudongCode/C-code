#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>


/***�������***/
/*1�������ڴ�
  2��ÿλ��ˣ���������
  3����λ����
  4���ҵ���0��ʼ��
  5���������ַ�����
  6��ĩβ'\0'
  7���ͷ��ڴ�*/  
void bigNumMul(char *str1, char *str2, char *res)
{
	int len1, len2, i, j;
	int *s;
	len1 = strlen(str1);
	len2 = strlen(str2);
	
	s = (int*)malloc(sizeof(int)*(len1 + len2));
	memset(s, 0, sizeof(int)*(len1 + len2));
	
	for(i=0; i<len1; i++)
		for(j=0; j<len2; j++)
			s[i+j+1] += (str1[i]-'0') * (str2[j]-'0');
			
 	for(i=len1+len2-1; i>0; i--)  //ע��i�ĳ�ʼֵ 
 	{
		if(s[i] > 9)
		{
			s[i-1] += s[i]/10;
			s[i] %= 10; 
		} 	
	}
	i = 0;
	while(s[i] == 0)
		i++;	
	for(j=0; j<len1+len2; i++, j++)
		res[j] = s[i] + '0';
	res[j] = '\0';
	free(s);
}
 
int main()
{
	char a[100];
	char b[100];
	char c[100]; 
	gets(a);
	gets(b);
	bigNumMul(a, b, c);
	printf("%s \n", c);
	return 0;
}


