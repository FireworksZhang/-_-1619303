#define _CRT_SECURE_NO_WARNINGS
///////////////////////////////////////////////////////////////////////////////////////////////////
//	ʵ�ֶ��������������򡢺���������õݹ�ͷǵݹ鷽����ʵ�ֲ�α�����
///////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

typedef struct BiTNode{
	char data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

typedef struct Stack {
	BiTree node[20];
	int top = 0, base = 0;
}Stack;

//�������򡢺�������ĵݹ鷽���Ͳ�α�������5-1��д��
void CreateBiTree(BiTree &T);
void preordertraverse(BiTree T);
void inordertraverse(BiTree T);
void postordertraverse(BiTree T);

void push(Stack &S, BiTree n);
void pop(Stack &S, BiTree &n);
int StackEmpty(Stack S);

int main()
{
	BiTree T;
	CreateBiTree(T);
	printf("\n���������\n");
	preordertraverse(T);
	printf("\n\n���������\n");
	inordertraverse(T);
	printf("\n\n���������\n");
	postordertraverse(T);

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

void preordertraverse(BiTree T)
{
	Stack S;
	BiTree p;
	if (T)
		push(S, T);
	while (!StackEmpty(S)) {
		pop(S, p);
		printf("%c ", p->data);
		if (p->rchild)
			push(S, p->rchild);
		if (p->lchild)
			push(S, p->lchild);
	}//while
}

void inordertraverse(BiTree T)
{
	Stack S;
	BiTree p;
	p = T;
	while (!StackEmpty(S) || p) {
		if (p) {
			push(S, p);
			p = p->lchild;
		}
		else {
			pop(S, p);
			printf("%c ", p->data);
			p = p->rchild;
		}
	}//while
}

void postordertraverse(BiTree T)
{
	Stack S1, S2;
	BiTree p;
	if (T)
		push(S1, T);
	while (!StackEmpty(S1)) {
		pop(S1, p);
		push(S2, p);
		if (p->lchild)
			push(S1, p->lchild);
		if (p->rchild)
			push(S2, p->rchild);
	}
	while (!StackEmpty(S2)) {
		pop(S2, p);
		printf("%c ", p->data);
	}
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