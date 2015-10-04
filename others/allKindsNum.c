/*****************************************************************************     
  Author: wxudong     
  Date: 2015-09-29
  Description: 求各种数 
******************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<math.h>

#define Min(x, y, z) (((x)>(y)?(y):(x))>(z)?(z):((x)>(y)?(y):(x)))

/***判断是否为素数***/
int isPrimeNum(int num)
{
	int i, j;
	j = sqrt(num);
	for(i=2; i<=j; i++)
	{
		if(num%i == 0)
			break;
	}
	if(i > j)
		return 1;
	else 
		return 0;
}

/***判断是否为丑数***/
int isUglyNum(int num)
{
	while(num%2 == 0)
		num = num/2;
	while(num%3 == 0)
		num = num/3;
	while(num%5 == 0)
		num = num/5;
	if(num == 1)
		return 1;
	else
		return 0;
}

/***求第num个丑数的值***/
int getUglyNumber(int num)
{
	int i, val;
	int num2 = 0;
	int num3 = 0;
	int num5 = 0;
	int *ugly = (int*)malloc(sizeof(int)*num);
	ugly[0] = 1;
	for(i=1; i<num; i++)
	{
		ugly[i] = Min(ugly[num2]*2, ugly[num3]*3, ugly[num5]*5);
		if(ugly[i] == ugly[num2]*2)
			num2++;
		if(ugly[i] == ugly[num3]*3)
			num3++;
		if(ugly[i] == ugly[num5]*5)
			num5++;
	}
	val = ugly[num-1];
	free(ugly);
	return val;
}

/***求最大公约数和最小公倍数***/
void gongYueGongBei(int a, int b)
{
	int val, mul, temp, gongyue, gongbei;
	mul = a*b;
	if(a < b)
	{
		temp = a;
		a = b;
		b = temp;
	} 
	while(b != 0)
	{
		temp = a%b;  //辗转求余法 
		a = b;
		b = temp;
	}
	gongyue = a;
	gongbei = mul/a;  //相乘值除以公约数 
	printf("min gongyue is %d\n", gongyue);
	printf("max gongbei is %d\n", gongbei);
}
 
 /***打印出num一下的所有自守数***/
void ziShouNum(int num)
{
	int i;
	for(i=0; i<num; i++)
	{
		int n = i;
		int m = 0;
		while(1)
		{
			int k;
			if(n == 0)
			{
				printf("%d\n", i);
				break;
			}
			k = n%10;
			m = m + k*i;
			if(m%10 != k)
				break;
			m = m/10;
			n = n/10;
		}
	} 
}
 
 
int main()
{
	int num1, num2;
	scanf("%d", &num1);
	//scanf("%d", &num2);
	//gongYueGongBei(num1, num2);
	//ziShouNum(num1);
	printf("%d\n", getUglyNumber(num1));
	return 0;
}


