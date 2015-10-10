/*****************************************************************************     
  Author: wxudong     
  Date: 2015-10-04
  Description: ����������ز���
  1���������Ľṹ�嶨��
  2������������
  3��ǰ�����򣬺�������
  4��������ĸ߶�
  5������������
  6���ж��Ƿ�Ϊ����
  7���ж��Ƿ�Ϊƽ���� 
******************************************************************************/
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
void preOrder(BitTree* T)
{
	if(T){				//��Ҫ�����ж� T 
		printf("%c ", T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}

/*** �������***/ 
void inOrder(BitTree* T)
{
	if(T){
		inOrder(T->lchild);
		printf("%c ", T->data);	
		inOrder(T->rchild);	
	}	
}

/*** �������***/ 
void postOrder(BitTree* T)
{
	
	if(T){
		postOrder(T->lchild);
		postOrder(T->rchild);
		printf("%c ", T->data);	
	}
}

/*** ��ȡ���ĸ߶�***/ 
int getBiTreeDepth(BitTree* T) 
{
	int left, right;
	if(T == NULL)
		return 0;
	left = getBiTreeDepth(T->lchild);
	right = getBiTreeDepth(T->rchild);
	return (left > right)?(left + 1):(right + 1);  //�ؼ���� 
}

/*** �������ľ���***/ 
void mirrorRecursively(BitTree* T)
{
	BitTree *temp;
	if(T == NULL)
		return;
	if(T->lchild == NULL && T->rchild == NULL)
		return;
	temp = T->lchild;
	T->lchild = T->rchild;
	T->rchild = temp;
	if(T->lchild)
		mirrorRecursively(T->lchild);
	if(T->rchild)
		mirrorRecursively(T->rchild);
}

/***�ж�root2�Ƿ�Ϊroot1������***/ 
int doseTree1HaveTree2(BitTree* root1, BitTree* root2)
{
	if(root2 == NULL)
		return 1;
	if(root1 == NULL)
		return 0;
	if(root1->data != root2->data)
		return 0;
	return doseTree1HaveTree2(root1->lchild, root2->lchild) 
				&&  doseTree1HaveTree2(root1->rchild, root2->rchild); 
}
int hasSubtree(BitTree* root1, BitTree* root2)
{
	int res = 0;
	if(root1 != NULL && root2 != NULL)
	{
		if(root1->data == root2->data)
			res = doseTree1HaveTree2(root1, root2);
		if(res == 0)
			res = hasSubtree(root1->lchild, root2);
		if(res == 0)
			res = hasSubtree(root1->rchild, root2);
	}
	return res;
}

/***�ж϶������Ƿ�Ϊƽ�������***/
int isBalancedTree(BitTree* T, int* depth)
{
	int left, right;
	if(T == NULL)
	{
		*depth = 0;
		return 1;
	}
	if(isBalancedTree(T->lchild, &left) && isBalancedTree(T->rchild, &right))
	{
		int diff = left - right;
		if(diff >= -1 && diff <= 1)
		{
			*depth = (left > right)?(left + 1):(right + 1);
			return 1;
		}
	}
	return 0;
} 


int main()
{
	BitTree *T;
	T = createBitTree();
	preOrder(T);
	printf("The BitTree depth is %d", getBiTreeDepth(T));
	return 0;
}

