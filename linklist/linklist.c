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

/*** ����ڵ�***/ 
linklist *insertList(linklist *head, int num)
{
	linklist *p, *q;
	p = head;
	while(num > 1)
	{
		p = p->next;
		num--;
	}
	q = p->next;
	p->next = (linklist *)malloc(sizeof(linklist));
	printf("please input node data\n");
	scanf("%d", &(p->next->data));
	p->next->next = q;	
	return head;
}

/*** ɾ���ڵ�***/ 
linklist *deleteList(linklist *head, int num)
{
	linklist *p, *q;
	p = head;
	while(num > 1)
	{
		p = p->next;
		num--;
	}
	q = p->next;
	p->next = q->next;
	free(q); 	
	return head;
}

/*** ��������***/ 
linklist *reverseList(linklist *head)
{
	linklist *pPre, *pNext, *p;
	p = head->next;
	pPre = NULL;
	while(p != NULL)
	{
		pNext = p->next; 
		p->next = pPre;
		pPre = p; 
		p = pNext;
	}
	head->next = pPre;
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
	printList(insertList(head, 2));
	printList(deleteList(head, 2));
	printList(reverseList(head));
	
	return 0;
}

