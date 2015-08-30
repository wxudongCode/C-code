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
	p->next = head;
	return head; 	
}

void josephus(int num, int pwd)
{
	linklist *p, *q;
	int i, j;
	p =  createlist(num);
	printf("����˳�� "); 
	for(i=0; i<num; i++)
	{
		while(--pwd)   //�ҵ��ýڵ� 
			p = p->next;
		pwd = p->pwd;
		printf("%d ", p->num);
		p->num = p->next->num;
		p->pwd = p->next->pwd;
		q = p->next;  //�ȱ��棬�ٸ�ֵ�����ͷ� 
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

