#include<stdio.h>
#include<assert.h>

typedef struct node{
	int data;
	struct node *next;
}linklist;

/*** �ж������Ƿ��л�������з��ػ��ڵ�***/
linklist *findLoopNode(linklist *head)
{
	linklist *fast, *slow;
	if(head == NULL || head->next == NULL)  //��ֹfast��������� 
		return NULL;
	fast = slow = head;
	while(1)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(fast == NULL || fast->next == NULL)  //��ֹ���� 
			return NULL;
		if(fast == slow)  //���ڻ������� 
			break;
	}
	slow = head;   //ͷ�ڵ��뻷�ڵ�ͬʱ��1�������ڻ��ڵ����� 
	while(fast != slow)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

/*** �������Ľڵ㳤�� ***/
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

/*** �ж����������Ƿ��н���㣬����з��ؽ���� ***/
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

/*** ����2:�ж����������Ƿ��н���㣬����з��ؽ����***/
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

