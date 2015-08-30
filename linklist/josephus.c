#include<stdio.h>
#include<assert.h>

typedef struct node{
	int num;
	int pwd;
	struct node *next;
}linklist;

linklist *createlist(int num)
{
	linklist *head, *p, *q;
	int i;
	for(i=1; i<=num; i++)
	{
		if(i == 1)
			head = p = (linklist *)malloc(sizeof(linklist));
		else
		{
			q = (linklist *)malloc(sizeof(linklist));
			p->next = q;
			p = q; 
		}
		p->num = i;
		printf("please input password for node %d\n", i);
		scanf("%d", &(p->pwd));
	}
	p->next = head;  //头相连，形成循环链表
	return head; 	
}

void josephus(int num, int pwd)
{
	linklist *p, *q;
	int i, j;
	p =  createlist(num);
	printf("出列顺序： "); 
	for(i=0; i<num; i++)
	{
		while(--pwd)   //找到该节点 
			p = p->next;
		pwd = p->pwd;
		printf("%d ", p->num);
		p->num = p->next->num;
		p->pwd = p->next->pwd;
		q = p->next;  //先保存，再赋值，后释放 
		p->next = p->next->next;		
		free(q);
	}
	printf("\n"); 
}

int main()
{
	linklist *head;
	int num, pwd;
	printf("please input node num\n");
	scanf("%d", &num);
	printf("please input first password\n");
	scanf("%d", &pwd);
	josephus(num, pwd);
	return 0;
}

