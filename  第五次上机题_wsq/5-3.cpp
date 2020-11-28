#define _CRT_SECURE_NO_WARNINGS
//////////////////////////////////////////////////////////////////////////////////////////////////
//	����������ö�������洢����д�������Զ�������ÿ��Ԫ��ֵΪx�Ľ�㣬ɾ������Ϊ�������������ͷ���Ӧ�ռ䡣
//////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

typedef struct BiTNode {
	char data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

typedef struct Stack {
	BiTree node[20];
	int top = 0, base = 0;
}Stack;

void CreateBiTree(BiTree &T);
void DestroyBiTree(BiTree &T);
void DeleteChild(BiTree &T, BiTNode* &cur_p, int LR);
void PreOrderTraverse(BiTree T);
void push(Stack &S, BiTree n);
void pop(Stack &S, BiTree &n);
int StackEmpty(Stack S);

int main()
{
	BiTree T, p;
	printf("�������������");
	CreateBiTree(T);
	getchar();
	
	char x;
	printf("\n������x��ֵ��");
	scanf("%c", &x);
	
	Stack S;

	if (T)
		push(S, T);
	if (T->data == x) {
		DestroyBiTree(T);
		T = NULL;
	}
	else
	{
		while (!StackEmpty(S)) {
			pop(S, p);
			if (p->rchild)
				if (p->rchild->data == x)
					DeleteChild(T, p, 1);
				else
					push(S, p->rchild);
			if (p->lchild)
				if (p->lchild->data == x)
					DeleteChild(T, p, 0);
				else
					push(S, p->lchild);
		}
	}

	printf("\n�������ɾ������Ķ�������");
	PreOrderTraverse(T);

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

void DestroyBiTree(BiTree &T)
{
	if (T->lchild)
		DestroyBiTree(T->lchild);
	if (T->rchild)
		DestroyBiTree(T->rchild);
	free(T);
	T = NULL;
}

void DeleteChild(BiTree &T, BiTNode* &cur_p, int LR)
{
	if (LR) {
		DestroyBiTree(cur_p->rchild);
		cur_p->rchild = NULL;
	}
	else {
		DestroyBiTree(cur_p->lchild);
		cur_p->lchild = NULL;
	}
}

void PreOrderTraverse(BiTree T)
{
	printf("%c ", T->data);
	if (T->lchild)
		PreOrderTraverse(T->lchild);
	if (T->rchild)
		PreOrderTraverse(T->rchild);
}

void push(Stack &T, BiTree n)
{
	T.node[T.top] = n;
	T.top++;
}

void pop(Stack &S, BiTree &n)
{
	S.top--;
	n = S.node[S.top];
}

int StackEmpty(Stack S)
{
	if (S.top == S.base)
		return 1;
	else
		return 0;
}