/*****************************************************************************     
  Author: wxudong     
  Date: 2015-09-07
  Description: ±≥∞¸Œ Ã‚ 
******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef struct Node{
     float weight;
     float value;
     float div;
}stNode;

void sort(int num, stNode *divsort)
{
	int i, j;
	for(i=0; i<num; i++)
		for(j=0; j<num-i-1; j++)
		{
			if(divsort[j].div < divsort[j+1].div)
			{
				stNode temp = divsort[j];
				divsort[j] = divsort[j+1];
				divsort[j+1] = temp; 		
			}
		}
}

void package(int num, float allweight, stNode *divsort)
{
	int i;
	for(i=0; i<num; i++)
	{
		if(divsort[i].weight > allweight) 
         	break; 
       	allweight = allweight - divsort[i].weight; 
       	printf("input goods %f.\n",divsort[i].weight); 
	}
}
void package0_1(int num, float allweight, stNode *divsort)
{
	int i;
	for(i=0; i<num; i++)
	{
		if(divsort[i].weight > allweight) 
         	break; 
       	allweight = allweight - divsort[i].weight; 
       	printf("input goods %f.\n",divsort[i].weight); 
	}
 	if(i <= num)
        printf("input goods %f of %f.\n",divsort[i].weight, allweight);  
}

int main(void)
{   
   int num, i;
   float allweight;
   stNode *goods;
   printf("input num : ");
   scanf("%d", &num);
   printf("input package weight : ");
   scanf("%f", &allweight);
   goods = (stNode *)malloc(sizeof(stNode) * num);
   for(i=0; i<num; i++)
   {
   		scanf("%f %f", &(goods[i].weight), &(goods[i].value));	
   		goods[i].div = (goods[i].value)/(goods[i].weight);
   }
   sort(num, goods);
   package0_1(num, allweight, goods);
   return 0;  
}





