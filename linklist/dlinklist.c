#include<stdio.h>
#include<assert.h>

typedef struct node{
	int data;
	struct node *pre;
	struct node *next;
}dlinklist;

/*** 创建双链表***/ 
dlinklist *createList(int num)
{
	dlinklist *head;
	dlinklist *p, *val;
	int i;
	head = (dlinklist *)malloc(sizeof(dlinklist));
	head->next = head;   //head指向自己 
	head->pre = head;
	val = head;
	for(i=1; i<=num; i++)
	{
		printf("please input the %d node\n", i);
		p = (dlinklist *)malloc(sizeof(dlinklist));
		scanf("%d", &(p->data));
		val->next = p; //更改四个指向 
		p->pre = val;
		p->next = head;
		head->pre = p;
		val = p;
	}	
	return head;
}

/*** 打印双向链表***/ 
void printList(dlinklist *head)
{
	dlinklist *p, *val;
	p = val = head;
	while(p->next != val)  //条件变化 
	{
		printf("%d ", p->next->data);
		p = p->next;
	}
	printf("\n");
}

/*** 插入节点***/ 
dlinklist *insertList(dlinklist *head, int num)
{
	dlinklist *p, *q;
	p = head;
	while(--num)
		p = p->next;
	q = p->next;
	p->next = (dlinklist *)malloc(sizeof(dlinklist));
	printf("please input node data\n");
	scanf("%d", &(p->next->data));
	p->next->pre = p;
	p->next->next = q;	
	q->pre = p->next;
	return head;
}

/*** 删除节点***/ 
dlinklist *deleteList(dlinklist *head, int num)
{
	dlinklist *p, *q;
	p = head;
	while(--num)
		p = p->next;
	q = p->next;
	p->next = q->next;
	q->next->pre = p; 
	free(q); 	
	return head;
}



int main()
{
	dlinklist *head;
	int num;
	printf("please input node num\n");
	scanf("%d", &num);
	head = createList(num);
	printList(head);
	printList(insertList(head, 2));
	printList(deleteList(head, 2));	
	return 0;
}

