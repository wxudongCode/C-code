#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

/***斐波那契数列***/
long long Pheponatch(int num) 
{
	int i;
	long long one, two, temp;
	if(num == 0)
		return 0;
	if(num == 1)
		return 1;
	one = 0;
	two = 1;
	for(i=2; i<=num; i++)
	{
		temp = one + two;
		one = two;
		two = temp;
	}
	return temp;
}



int main()
{
	printf("%ld ", Pheponatch(10));
	return 0;
}


