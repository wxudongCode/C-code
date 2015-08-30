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


/*** 合并两个有序链表 ***/
linklist *mergeListNoHead(linklist *list1, linklist *list2)
{
	linklist *p;
	if(list1 == NULL)
		return list2;
	if(list2 == NULL)
		return list1;
	if(list1->data < list2->data)
	{
		p = list1;
		p->next = mergeListNoHead(list1->next, list2);
	}
	else
	{
		p = list2;
		p->next = mergeListNoHead(list1, list2->next);
	}
	return p;
}

linklist *mergeTwoOrderList(linklist *head1, linklist *head2)
{
	linklist *list1, *list2;
	list1 = head1->next;
	list2 = head2->next;
	if(list1 == mergeListNoHead(list1, list2))
	{
		free(head2);
		return head1;
	}
	if(list2 == mergeListNoHead(list1, list2))
	{
		free(head1);
		return head2;
	}
}

int main()
{
	linklist *head1, *head2;
	int num1, num2;
	
	printf("please input head1 node num\n");
	scanf("%d", &num1);
	head1 = createList(num1);
	printList(head1);
	
	printf("please input head2 node num\n");
	scanf("%d", &num2);
	head2 = createList(num2);
	printList(head2);
	
	printList(mergeTwoOrderList(head1, head2)); 
	return 0;
}

