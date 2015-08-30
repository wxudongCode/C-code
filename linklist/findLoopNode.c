#include<stdio.h>
#include<assert.h>

typedef struct node{
	int data;
	struct node *next;
}linklist;

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

int main()
{
	return 0;
}

