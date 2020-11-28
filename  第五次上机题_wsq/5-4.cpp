#define _CRT_SECURE_NO_WARNINGS
///////////////////////////////////////////////////////////////////////////////////////////////////
//	编写函数，判断给定的二叉树是否是完全二叉树。
///////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

typedef struct BiTNode {
	char data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

void CreateBiTree(BiTree &T);

int main()
{
	BiTree T, level[20], p;
	printf("请输入二叉树：");
	CreateBiTree(T);
	
	int i, j;
	i = 0;
	j = 0;
	level[j++] = T;
	p = level[i];
	while (i != j && p) {
		level[j++] = p->lchild;
		level[j++] = p->rchild;
		i++;
		p = level[i];
	}

	for (; i < j; i++)
		if (level[i] != NULL)
			break;

	if (i < j)
		printf("\nT不是完全二叉树\n");
	else
		printf("\nT是完全二叉树\n");

	system("PAUSE");
}

void CreateBiTree(BiTree &T)
{
	char c;
	scanf("%c", &c);
	if (c == ' ')
		T = NULL;
	else {
		T = (BiTree)malloc(sizeof(BiTNode));
		T->data = c;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}