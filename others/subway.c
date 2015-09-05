/*****************************************************************************     
  Author: wxudong     
  Date: 2015-09-05
  Description: 地铁换乘
  已知2条地铁线路，其中A为环线，B为东西向线路，线路都是双向的。经过的站点名分别如下，两条线交叉的换乘点用T1、T2表示。
  编写程序，任意输入两个站点名称，输出乘坐地铁最少需要经过的车站数量（含输入的起点和终点，换乘站点只计算一次）。  
  地铁线A（环线）经过车站：A1 A2 A3 A4 A5 A6 A7 A8 A9 T1 A10 A11 A12 A13 T2 A14 A15 A16 A17 A18  
  地铁线B（直线）经过车站：B1 B2 B3 B4 B5 T1 B6 B7 B8 B9 B10 T2 B11 B12 B13 B14 B15  
  输入：输入两个不同的站名  
  输出：输出最少经过的站数及名称，含输入的起点和终点，换乘站点只计算一次   
******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#define STANUM   35    //总站台数
#define inf      1000  //定义无穷远距离 

char *staName[STANUM] = {"A1","A2","A3","A4","A5","A6","A7","A8","A9","A10",  
                         "A11","A12","A13","A14","A15","A16","A17","A18",  
                         "B1","B2","B3","B4","B5","B6","B7","B8","B9","B10",  
                         "B11","B12","B13","B14","B15","T1","T2"} ;  
   
typedef struct stack{
	int val[STANUM];
	int top;
}stack;

void stackPush(stack *s, int num)
{
	s->val[s->top] = num;
	s->top++;
}   
void stackPop(stack *s)
{
	s->top--;
}
int stackTop(stack *s)
{
	return s->val[(s->top) - 1];
}
int stackLen(stack *s)
{
	return s->top;
}
   
/*** floyd算法 ***/                         
void floyd(int dis[][STANUM],int path[][STANUM])  
{  
    int k, i, j, row, col;
	for(row=0; row<STANUM; row++)  
        for(col=0; col<STANUM; col++)  
            path[row][col] = row;  
  
    for(k=0; k<STANUM; k++)  
        for(i=0; i<STANUM; i++)  
            for(j=0; j<STANUM; j++)  
                if(dis[i][j]>dis[i][k] + dis[k][j])  
                {  
                    dis[i][j] = dis[i][k] + dis[k][j];  
                    path[i][j] = path[k][j];  
                }  
}  
/*** 转换车站的名字到矩阵的索引 ***/ 
int staNameToInt(char *str)  
{  
 	int i;     
  	for(i=0; i<STANUM; i++)  
  	{
	  	if(strcmp(str, staName[i]) == 0)
		 	return i;  
  	}  
} 
/*** 计算 ***/ 
void printres(int dis[][STANUM], int path[][STANUM], char *start, char *end)  
{
    int startkey, endkey, i, j;

    startkey = staNameToInt(start);
    endkey = staNameToInt(end);
    printf("start station to destination : %s -> %s\n", start, end);
    printf("distance : %d\n", dis[startkey][endkey]+1);  
    
    for(i=0; i<STANUM; i++)  
        for(j=0; j<STANUM; j++) 
		{
			if(i == startkey && j == endkey)
			{
  				stack pushout = {0, 0};
  				int k, t, len;
  				k = j;
  				do{
				  	k = path[i][k];
					stackPush(&pushout, k); 
	  			}while(k != i);
	  			len = stackLen(&pushout);
  				printf("path : ");
	  			for(t=0; t<len; t++)
	  			{
			  		printf("%s ", staName[stackTop(&pushout)]);
			  		stackPop(&pushout);
			  	}
			  	printf("%s \n", staName[endkey]);
			  	break;
			}
		} 
}

int main(void)
{   
    int i, j;	
    char start[4];
	char end[4];  
    int path[STANUM][STANUM];  
    int distance[STANUM][STANUM]; 
    int sa[21]={0,1,2,3,4,5,6,7,8,33,9,10,11,12,34,13,14,15,16,17,0}; 
    int sb[17]={18,19,20,21,22,33,23,24,25,26,27,34,28,29,30,31,32}; 
	 
    //初始化连接矩阵  
    for(i=0; i<STANUM; i++)  
    {  
        for(j=0; j<STANUM; j++)  
        {  
            if(i==j)  
                distance[i][j]=0;  
            else  
                distance[i][j]=inf;  
        }  
    }

    for(i=0; i<20; i++)  
    {  
        distance[sa[i]][sa[i+1]]=1;  
        distance[sa[i+1]][sa[i]]=1;  
    }
    for(i=0; i<16; i++)  
    {  
        distance[sb[i]][sb[i+1]]=1;  
        distance[sb[i+1]][sb[i]]=1;  
    }  
    
    floyd(distance,path);  
    printf("input start and destination\n");
	gets(start);
	gets(end);   
    printres(distance, path, start, end);  
    return 0;  
}





