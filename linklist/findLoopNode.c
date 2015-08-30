#include<stdio.h>
#include<assert.h>

typedef struct node{
	int data;
	struct node *next;
}linklist;

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

int main()
{
	return 0;
}

