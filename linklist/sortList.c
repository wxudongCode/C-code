#include<stdio.h>
#include<assert.h>

typedef struct node{
	int data;
	struct node *next;
}linklist;

/*** ����������***/ 
linklist *createList(int num)
{
	linklist *head;
	linklist *p, *pre;
	int i;
	head = (linklist *)malloc(sizeof(linklist));
	head->next == NULL;
	pre = head;
	for(i=1; i<=num; i++)
	{
		printf("please input the %d node\n", i);
		p = (linklist *)malloc(sizeof(linklist));
		scanf("%d", &(p->data));
		pre->next = p;
		pre = p;
	}	
	p->next= NULL;	
	return head;
}

/*** ��ӡ����***/ 
void printList(linklist *head)
{
	linklist *p;
	p = head;
	while(p->next != NULL)
	{
		printf("%d ", p->next->data);
		p = p->next;
	}
	printf("\n");
}

/*** ֱ�Ӳ�����������***/ 
linklist *insertSortList(linklist *head)
{
	linklist *oldhead;  //������ı�ͷ 
	linklist *newhead;  //������ı�ͷ 
	linklist *pre; //����qǰ�Ľڵ� 
	linklist *q;  //ʵʱ��¼������ 
	linklist *t;  //����ڵ� 
	newhead = head->next;       //head��ĵ�һ���ڵ� 
	oldhead = head->next->next;   //head��ĵڶ����ڵ� 
	newhead->next= NULL;
	while(oldhead)
	{
		for(t = oldhead, q = newhead; (q != NULL)&&(q->data < t->data)
			; pre = q, q = q->next);
		oldhead = oldhead->next;
		if(q == newhead)
			newhead = t;
		else
			pre->next = t;
		t->next = q; 
	}
	head->next = newhead;
	return head;	
}

int main()
{
	linklist *head;
	int num;
	printf("please input node num\n");
	scanf("%d", &num);
	head = createList(num);
	printList(head);
	printList(insertSortList(head));
	return 0;
}


