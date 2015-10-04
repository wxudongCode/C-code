/*****************************************************************************     
  Author: wxudong     
  Date: 2015-09-29
  Description: Ñî»ÔÈý½Ç 
******************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<math.h>


void YangHuiPrint(int num, int a[][10])
{
	int i, j;
	for(i=0; i<num; i++)
		a[i][0] = 1;
	for(i=1; i<num; i++)
		for(j=1; j<=i; j++)
			a[i][j] = a[i-1][j] + a[i-1][j-1];
	for(i=0; i<num; i++)
	{
		for(j=0; j<num; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	} 
} 
 
int main()
{
	int num;
	int a[10][10] = {0};
	scanf("%d", &num);
	YangHuiPrint(num, a);
	return 0;
}


