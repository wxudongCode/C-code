#include<stdio.h>
#include<assert.h>


/***√∞≈›≈≈–Ú£¨∏¥‘”∂»O(n*n)***/
void bubbleSort(int *a, int len)
{
	int i, j;
	for(i = 0; i < len; i++)
	{
		for(j = 0; j < len-i-1; j++)
		{
			if(a[j] > a[j+1])
			{
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}
 
/***≤Â»Î≈≈–Ú£¨∏¥‘”∂»O(n*n)***/
void insertSort(int *a, int len)
{
	int i, j, temp;
	for(i = 0; i < len; i++)
	{
		if(a[i] > a[i+1])
		{
			temp = a[i+1];
			for(j = i; j>=0 && a[j]>temp; j--)
			{
				a[j+1] = a[j];
			}
			a[j+1] = temp;
		}
	} 
}

void print(int *a, int len)
{
	int i;
	for(i = 0; i<len; i++)
	{
		printf("%d ", a[i]); 
	}
	
	printf("\n");
}

int main()
{
	int a[5] = {0, 9, 5, 3, 8};	
	
	//bubbleSort(a, 5);
	//print(a, 5);
	
	insertSort(a, 5);
	print(a, 5);
	
	return 0;
}


