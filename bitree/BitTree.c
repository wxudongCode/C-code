/*****************************************************************************     
  Author: wxudong     
  Date: 2015-10-04
  Description: 二叉树的相关操作
  1：二叉树的结构体定义
  2：创建二叉树
  3：前序，中序，后续遍历
  4：获得树的高度
  5：二叉树镜像
  6：判断是否为子树
  7：判断是否为平衡树 
******************************************************************************/
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
void preOrder(BitTree* T)
{
	if(T){				//不要忘记判断 T 
		printf("%c ", T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}

/*** 中序遍历***/ 
void inOrder(BitTree* T)
{
	if(T){
		inOrder(T->lchild);
		printf("%c ", T->data);	
		inOrder(T->rchild);	
	}	
}

/*** 后序遍历***/ 
void postOrder(BitTree* T)
{
	
	if(T){
		postOrder(T->lchild);
		postOrder(T->rchild);
		printf("%c ", T->data);	
	}
}

/*** 获取树的高度***/ 
int getBiTreeDepth(BitTree* T) 
{
	int left, right;
	if(T == NULL)
		return 0;
	left = getBiTreeDepth(T->lchild);
	right = getBiTreeDepth(T->rchild);
	return (left > right)?(left + 1):(right + 1);  //关键语句 
}

/*** 二叉树的镜像***/ 
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

/***判断root2是否为root1的子树***/ 
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

/***判断二叉树是否为平衡二叉树***/
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

