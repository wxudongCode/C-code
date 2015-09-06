/*****************************************************************************     
  Author: wxudong     
  Date: 2015-09-06
  Description: 一条长廊里依次装有n(1≤n≤65535)盏电灯，从头到尾编号1、2、3、…n-1、n。开始，电灯全部关着。
  有n个学生穿过。第一个学生把号码凡是1的倍数的电灯的拉一下；接着第二个学生把号码凡是2的倍数的电灯的拉一下；
  如此继续下去，最后第n个学生把号码凡是n的倍数的电灯的开关拉一下。走完后，长廊里电灯有几盏亮着。
  
  分析： 要求哪些灯还亮着，就是问哪些灯的编号的因数有奇数个．显然完全平方数有奇数个因数。
  每个数除以一个数A等于另一个数B，那么A和B都是它的因数，于是因数是成对出现的，但是要因数是奇数，
  就必须A=B所以这个数就必须是一个是的平方得到的。
******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#define MAX 65536
int GetLightLampNum(int num)
{
	
	int i;
	int res = 0;
	for(i=1; ; i++)
	{
		if(i*i > num)
			break;
		res++;
	}
	return res;	
}

int main(void)
{   
   int num;
   printf("input num : ", GetLightLampNum(num));
   scanf("%d", &num);
   printf("Light Lamp Num : %d ", GetLightLampNum(num));
   return 0;  
}





