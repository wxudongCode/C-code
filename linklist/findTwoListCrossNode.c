#include<stdio.h>
#include<assert.h>

typedef struct node{
	int data;
	struct node *next;
}linklist;

/*** 判断链表是否有环，如果有返回环节点***/
linklist *findLoopNode(linklist *head)
{
	linklist *fast, *slow;
	if(head == NULL || head->next == NULL)  //防止fast两步后出错 
		return NULL;
	fast = slow = head;
	while(1)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(fast == NULL || fast->next == NULL)  //终止条件 
			return NULL;
		if(fast == slow)  //存在环的条件 
			break;
	}
	slow = head;   //头节点与环节点同时走1步，必在环节点相遇 
	while(fast != slow)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

/*** 获得链表的节点长度 ***/
int getListLength(linklist *head)
{
	linklist *p;
	int length = 0;
	p = head;
	while(p->next!= NULL)
	{
		p = p->next;
		length++;
	}
	return length;
}

/*** 判断两个链表是否有交叉点，如果有返回交叉点 ***/
linklist *findTwoListCrossNode1(linklist *head1, linklist *head2)
{
	linklist *p, *val;
	p = head1;
	while(p->next == NULL)
		p = p->next;
	p->next = head2;
	val = findLoopNode(head1);
	return val;
}

/*** 方法2:判断两个链表是否有交叉点，如果有返回交叉点***/
linklist *findTwoListCrossNode2(linklist *head1, linklist *head2)
{
	linklist *plong, *pshort;
	int len1, len2, diff;
	len1 = getListLength(head1);
	len2 = getListLength(head2);
	if(len1 -len2 >=  0)
	{
		diff = len1 - len2;
		plong = head1;
		pshort = head2;
	}
	else
	{
		diff = len2 - len1;
		plong = head2;
		pshort = head1;
	}
	while(diff--)
		plong = plong->next;
	while(plong != NULL && pshort != NULL && plong != pshort)
	{
		plong = plong->next;
		pshort = pshort->next;
	}
	return plong;
}

int main()
{
	return 0;
}

