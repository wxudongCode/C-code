#include<stdio.h>
#include<assert.h>

typedef struct BitTree{
	char data;
	struct BitTree *lchild;
	struct BitTree *rchild;
}BitTree;

/*** ����������***/ 
BitTree *createBitTree()
{
	char ch;
	BitTree *T;
	scanf("%c", &ch);
	if(ch == '#')
		return NULL;
	else
	{
		T = (BitTree *)malloc(sizeof(BitTree));
		T->data = ch;
		T->lchild = createBitTree();
		T->rchild = createBitTree();	
	}
	return T;
}

/*** ǰ�����***/ 
void preOrder(BitTree *T)
{
	if(T){				//��Ҫ�����ж� T 
		printf("%c ", T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}

/*** �������***/ 
void inOrder(BitTree *T)
{
	if(T){
		inOrder(T->lchild);
		printf("%c ", T->data);	
		inOrder(T->rchild);	
	}	
}

/*** �������***/ 
void postOrder(BitTree *T)
{
	
	if(T){
		postOrder(T->lchild);
		postOrder(T->rchild);
		printf("%c ", T->data);	
	}
}

/*** ��ȡ���ĸ߶�***/ 
int getBiTreeDepth(BitTree *T) 
{
	int left, right;
	if(T == NULL)
		return 0;
	left = getBiTreeDepth(T->lchild);
	right = getBiTreeDepth(T->rchild);
	return (left > right)?(left + 1):(right + 1);  //�ؼ���� 
}

int main()
{
	BitTree *T;
	T = createBitTree();
	preOrder(T);
	printf("The BitTree depth is %d", getBiTreeDepth(T));
	return 0;
}

