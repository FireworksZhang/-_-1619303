#define _CRT_SECURE_NO_WARNINGS
///////////////////////////////////////////////////////////////////////////////////////////////////
//	��д�������жϸ����Ķ������Ƿ�����ȫ��������
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
	printf("�������������");
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
		printf("\nT������ȫ������\n");
	else
		printf("\nT����ȫ������\n");

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