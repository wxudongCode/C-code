/*****************************************************************************     
  Author: wxudong     
  Date: 2015-09-07
  Description: four operations Àƒ‘Ú‘ÀÀ„ 
******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef struct stack{
	int val[64];
	int top;
}stack;

void stackpush(stack *s, int num)
{
	s->top++;
	s->val[s->top] = num;
}
int stackpop(stack *s)
{
	int res;
	res = s->val[s->top];
	s->top--;
	return res;
}
int stacktop(stack *s)
{
	return s->val[s->top];
} 

int calculate(int left, char oper, int right)
{
	if(oper == '+')
		return left + right;
	if(oper == '-')
		return left - right;
	if(oper == '*')
		return left * right;
	if(oper == '/')
		return left / right;	
}


int calcCondition(char ch, char opchTop)
{
	
	if(ch == '(')
		return 0; 
	if((ch == '*' || ch == '/') && (opchTop == '+' || opchTop == '-'))
		return 0;
	else 
		return 1;	
}

int expr(char *s)
{
	stack opnum = {0, 0};
	stack opch = {0, 0};
	stackpush(&opch, '#');
	while(*s != '\0')
	{
		if(*s >= '0' && *s <= '9')
			stackpush(&opnum, *s - '0');
		else
		{
			while((calcCondition(*s, stacktop(&opch)) == 1) && (stacktop(&opch) != '#') && (stacktop(&opch) != '('))
			{
				int left, right, res;
				right = stackpop(&opnum);
				left = stackpop(&opnum);
				res = calculate(left, stackpop(&opch), right);
				stackpush(&opnum, res);
			}
			if(stacktop(&opch) == '(' && *s == ')')
				stackpop(&opch);
			else
				stackpush(&opch, *s);
		}
		s++;
	}
	return stackpop(&opnum);
}

int main(void)
{   
   assert(expr("(1+1)#") == 2);
   assert(expr("1+6*(2-1)/2#") == 4);
   return 0;  
}





