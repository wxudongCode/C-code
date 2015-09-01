#include<stdio.h>
#include<assert.h>

typedef struct node{
	int data;
	struct node *next;
}linklist;

/*** 创建单链表***/ 
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

/*** 打印链表***/ 
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

/*** 直接插入链表排序***/ 
linklist *insertSortList(linklist *head)
{
	linklist *oldhead;  //老链表的表头 
	linklist *newhead;  //新链表的表头 
	linklist *pre; //保存q前的节点 
	linklist *q;  //实时记录新链表 
	linklist *t;  //插入节点 
	newhead = head->next;       //head后的第一个节点 
	oldhead = head->next->next;   //head后的第二个节点 
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


