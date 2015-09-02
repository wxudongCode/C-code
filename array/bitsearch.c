#include<stdio.h>
#include<assert.h>

 
int bitSearch(int *a, int len, int temp)
{
	int low = 0;
	int high = len - 1;
	while(low <= high) //×¢ÒâµÈÓÚ 
	{
		int mid = (low + high)/2;
		if(a[mid] > temp)
			high = mid - 1;
		else if(a[mid] < temp)
			low = mid + 1;
		else if(a[mid] == temp)
			return 1;		
	}
	return 0;
}

int main()
{
	int a[5] = {0, 4, 5, 7, 9};
	assert(bitSearch(a, 5, 4) == 1);
	assert(bitSearch(a, 5, 9) == 1);
	assert(bitSearch(a, 5, 1) == 0);	
	printf("code done\n");
	return 0;
}


