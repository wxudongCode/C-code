#include<stdio.h>
#include<assert.h>

typedef struct BitTree{
	char data;
	struct BitTree *lchild;
	struct BitTree *rchild;
}BitTree;

/*** 创建二叉树***/ 
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

/*** 前序遍历***/ 
void preOrder(BitTree *T)
{
	if(T){				//不要忘记判断 T 
		printf("%c ", T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}

/*** 中序遍历***/ 
void inOrder(BitTree *T)
{
	if(T){
		inOrder(T->lchild);
		printf("%c ", T->data);	
		inOrder(T->rchild);	
	}	
}

/*** 后序遍历***/ 
void postOrder(BitTree *T)
{
	
	if(T){
		postOrder(T->lchild);
		postOrder(T->rchild);
		printf("%c ", T->data);	
	}
}

/*** 获取树的高度***/ 
int getBiTreeDepth(BitTree *T) 
{
	int left, right;
	if(T == NULL)
		return 0;
	left = getBiTreeDepth(T->lchild);
	right = getBiTreeDepth(T->rchild);
	return (left > right)?(left + 1):(right + 1);  //关键语句 
}

int main()
{
	BitTree *T;
	T = createBitTree();
	preOrder(T);
	printf("The BitTree depth is %d", getBiTreeDepth(T));
	return 0;
}

