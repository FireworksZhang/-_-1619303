#define _CRT_SECURE_NO_WARNINGS
///////////////////////////////////////////////////////////////////////////////////////////////////
//	编程实现书P75  ADT BinaryTree 基本操作20个，用二叉链表结构实现；
///////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

typedef struct BiTNode
{
	char data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//1.初始化、销毁和清空操作
//void InitBiTree(BiTree &T);		//操作结果：构造一个空二叉树T
void DestroyBiTree(BiTree &T);	//初始条件：二叉树T存在		操作结果：销毁二叉树T
void CreateBiTree(BiTree &T);	//初始条件：definition给出二叉树T的定义		操作结果：按definition构造树二叉T
//void ClearBiTree(BiTree &T);	//初始条件：二叉树T存在		操作结果：将二叉树工重置为空树
//2.访问型操作
int BiTreeEmpty(BiTree T);		//初始条件：二叉树T存在		操作结果：若二叉树T为空树，则返回1, 否则返回0
int BiTreeDepth(BiTree T);		//初始条件：二叉树工存在	操作结果：返回二叉树T的深度
void Root(BiTree T, char &e);	//初始条件：二叉树T存在		操作结果：返回二叉树T的根的元素值
void Value(BiTree T,BiTNode* cur_p, char &e);	//初始条件：二叉树T存在，cur_p是T中某个结点指针		操作结果：返回cur_p指向的结点的值e
void Parent(BiTree T, BiTNode* cur_p, BiTNode* &parent);		//初始条件：二叉树T存在，cur_p是T中某个结点指针		操作结果：若cur_p非T的根结点，则返回它的双亲指针，否则返回值为空
void LeftChild(BiTree T, BiTNode* cur_p, BiTNode* &leftChild);	//初始条件：二叉树T存在，cur_p是T中某个结点指针		操作结果：返回cur_p的左孩子指针，若没有左孩子，则返回值为空
void RightChild(BiTree T, BiTNode* cur_p, BiTNode* &rightChild);	//初始条件：二叉树T存在，cur_p是T中某个结点指针		操作结果：返回cur_p的右孩子，若没有右孩子，则返回值为空
void LeftBrother(BiTree T, BiTNode* cur_p, BiTNode* &leftBrother);		//初始条件：二叉树T存在，cur_p是T中某个结点指针		操作结果：返回cur_p的左兄弟，若没有左兄弟，则返回值为空
void RightBrother(BiTree T, BiTNode* cur_p, BiTNode* &rightBrother);	//初始条件：二叉树T存在，cur_p是T中某个结点指针		操作结果：返回cur_p的右兄弟，若没有右兄弟，则返回值为空
void PreOrderTraverse(BiTree T);		//初始条件：二叉树T存在，visit是对结点进行操作的应用函数		操作结果：先序遍历T，对每个结点调用函数visit()一次且仅一次; 一旦visit()失败，则操作失败
void InOrderTraverse(BiTree T);		//初始条件：二叉树T存在，visit是对结点进行操作的应用函数		操作结果：中序遍历T，对每个结点调用函数visit()一次且仅一次; 一旦visit()失败，则操作失败
void PostOrderTraverse(BiTree T);		//初始条件：二叉树T存在，visit是对结点进行操作的应用函数		操作结果：后序遍历T，对每个结点调用函数visit()一次且仅一次; 一旦visit()失败，则操作失败
void LevelOrderTraverse(BiTree T);		//初始条件：二叉树T存在，visit是对结点进行操作的应用函数		操作结果：层次遍历T，对每个结点调用函数visit()一次且仅一次; 一旦visit()失败，则操作失败
//3.加工型操作
void Assign(BiTree &T, BiTNode* &cur_p, char value);		//初始条件：二叉树T存在，cur_p是T中某个结点指针		操作结果：将cur_p结点元素赋值为value
void InsertChild(BiTree &T, BiTNode* &cur_p, int LR, BiTree &c);	//初始条件：二叉树T存在，cur_p指向T中某个结点，LR为0或1，非空二叉树c与T不相交且右子树为空		操作结果：根据LR为0或1, 插入c作为T中p指向结点的左子树或右子树。p所指结点的原有左子树或右子树则成为c的右子树
void DeleteChild(BiTree &T, BiTNode* &cur_p, int LR);		//初始条件：二叉树T存在，cur_p指向T中某个结点，LR为0或1	操作结果：根据LR为0或1，删除T中p指向结点的左子树或右子树

int main()
{
	int judge = 99;
	BiTree T = NULL;
	while (judge) {
		printf("------------------------------------------------\n");
		printf("1.CreateBiTree	2.DestroyBiTree	3.BiTreeEmpty	4.BiTreeDepth	5.Root\n");
		printf("6.Value		7.Parent	8.LeftChild	9.RightChild	10.LeftBrother\n");
		printf("11.RightBrother	12.PreOrderTraverse	13.InOrderTraverse	14.PostOrderTraverse	15.LevelOrderTraverse\n");
		printf("16.Assign	17.InsertChild	18.DeleteChild\n");
		printf("0.exit \n");
		printf("请选择一种操作：");

		scanf("%d", &judge);
		getchar();
		BiTree p;
		int i;
		char e;
		switch (judge) {
		case 1:
			printf("\n请输入二叉树：");
			CreateBiTree(T);
			printf("\n*已成功构造一个二叉树T\n\n");
			break;
		case 2:
			DestroyBiTree(T);
			printf("\n*已成功销毁二叉树T\n\n");
			break;
		case 3:
			if (BiTreeEmpty(T))
				printf("\n*T为空树\n\n");
			else
				printf("\n*T非空树\n\n");
			break;
		case 4:
			printf("\nT的高度为%d\n\n", BiTreeDepth(T));
			break;
		case 5:
			Root(T, e);
			printf("\nT的根的元素值为%c\n\n", e);
			break;
		case 6:
			Value(T, T, e);
			printf("\nT的根的元素值为%c\n\n", e);
			break;
		case 7:
			Parent(T, T, p);
			if (!p)
				printf("\ncur_p为T的根结点，返回值为空\n\n");
			else
				printf("\ncur_p的双亲结点元素为%c\n\n", p->data);
			break;
		case 8:
			LeftChild(T, T, p);
			if (p)
				printf("\nT的左孩子元素值为%c\n\n", p->data);
			else
				printf("\nT的左孩子为空\n\n");
			break;
		case 9:
			RightChild(T, T, p);
			if (p)
				printf("\nT的右孩子元素值为%c\n\n", p->data);
			else
				printf("\nT的右孩子为空\n\n");
			break;
		case 10:
			LeftBrother(T, T->rchild, p);
			if (p)
				printf("\ncur_p的左兄弟元素值为%c\n\n", p->data);
			else
				printf("\ncur_p没有左兄弟，返回值为空\n\n");
			break;
		case 11:
			RightBrother(T, T->lchild, p);
			if (p)
				printf("\ncur_p的右兄弟元素值为%c\n\n", p->data);
			else
				printf("\ncur_p没有右兄弟，返回值为空\n\n");
			break;
		case 12:
			printf("\n先序遍历：\n");
			PreOrderTraverse(T);
			printf("\n\n");
			break;
		case 13:
			printf("\n中序遍历：\n");
			InOrderTraverse(T);
			printf("\n\n");
			break;
		case 14:
			printf("\n后序遍历：\n");
			PostOrderTraverse(T);
			printf("\n\n");
			break;
		case 15:
			printf("\n层次遍历：\n");
			LevelOrderTraverse(T);
			printf("\n\n");
			break;
		case 16:
			printf("\n请输入value的值：");
			scanf("%c", &e);
			Assign(T, T, e);
			printf("已将根结点元素赋值为%c\n\n", e);
			break;
		case 17:
			BiTree nt, ntlc;
			nt = (BiTree)malloc(sizeof(BiTNode));
			ntlc = (BiTree)malloc(sizeof(BiTNode));
			ntlc->data = 'N';
			ntlc->lchild = NULL;
			ntlc->rchild = NULL;
			nt->data = 'M';
			nt->lchild = ntlc;
			nt->rchild = NULL;

			InsertChild(T, T, 1, nt);
			printf("\n已插入二叉树c\n\n");
			break;
		case 18:
			DeleteChild(T, T, 1);
			printf("\n已删除根结点的右子树\n\n");
			break;
		case 0:
		default:
			break;
		}
	}
	system("PAUSE");
}

/*
void InitBiTree(BiTree &T)
{
	T = (BiTree)malloc(sizeof(BiTNode));
	T->data = NULL;
	T->lchild = NULL;
	T->rchild = NULL;
}
*/

void DestroyBiTree(BiTree &T)
{
	if (T->lchild)
		DestroyBiTree(T->lchild);
	if (T->rchild)
		DestroyBiTree(T->rchild);
	T = NULL;
	free(T);
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

/*
void ClearBiTree(BiTree &T)
{
	if (T->lchild)
		DestroyBiTree(T->lchild);
	if (T->rchild)
		DestroyBiTree(T->rchild);
	T = NULL;
}
*/

int BiTreeEmpty(BiTree T)
{
	if (T->lchild || T->rchild)
		return 0;
	else
		return 1;
}

int BiTreeDepth(BiTree T)
{
	int depth[100], i = 0, j = 0;
	BiTree n[100], t;
	depth[j] = 1;
	n[j++] = T;
	while (i != j) {
		if (n[i]->lchild) {
			depth[j] = depth[i] + 1;
			n[j++] = n[i]->lchild;
		}
		if (n[i]->rchild) {
			depth[j] = depth[i] + 1;
			n[j++] = n[i]->rchild;
		}
		i++;
	}
	return depth[--j];
}

void Root(BiTree T, char &e)
{
	e = T->data;
}

void Value(BiTree T, BiTNode* cur_p, char &e)
{
	e = cur_p->data;
}

void findparent(BiTree T, BiTNode* cur_p, BiTNode* &parent);
void findparent(BiTree T, BiTNode* cur_p, BiTNode* &parent)
{
	if (!T->lchild && !T->rchild)
		return;
	else {
		if (T->lchild == cur_p || T->rchild == cur_p)
			parent = T;
		else if (T->lchild)
			findparent(T->lchild, cur_p, parent);
		if (!parent && T->rchild)
			findparent(T->rchild, cur_p, parent);
	}
}
void Parent(BiTree T, BiTNode* cur_p, BiTNode* &parent)
{
	parent = NULL;
	if (T == cur_p)
		return;
	else
		findparent(T, cur_p, parent);
}

void LeftChild(BiTree T, BiTNode* cur_p, BiTNode* &leftChild)
{
	leftChild = cur_p->lchild;
}

void RightChild(BiTree T, BiTNode* cur_p, BiTNode* &rightChild)
{
	rightChild = cur_p->rchild;
}

void LeftBrother(BiTree T, BiTNode* cur_p, BiTNode* &leftBrother)
{
	BiTNode *p;
	Parent(T, cur_p, p);
	if (p && p->rchild == cur_p)
		leftBrother = p->lchild;
	else
		leftBrother = NULL;
}

void RightBrother(BiTree T, BiTNode* cur_p, BiTNode* &rightBrother)
{
	BiTNode *p;
	Parent(T, cur_p, p);
	if (p && p->lchild == cur_p)
		rightBrother = p->rchild;
	else
		rightBrother = NULL;
}

void pre_visit(BiTree T)
{
	printf("%c ", T->data);
	if (T->lchild)
		pre_visit(T->lchild);
	if (T->rchild)
		pre_visit(T->rchild);
}


void PreOrderTraverse(BiTree T)
{
	pre_visit(T);
}

void in_visit(BiTree T)
{
	if (T->lchild)
		in_visit(T->lchild);
	printf("%c ", T->data);
	if (T->rchild)
		in_visit(T->rchild);
}

void InOrderTraverse(BiTree T)
{
	in_visit(T);
}

void post_visit(BiTree T)
{
	if (T->lchild)
		post_visit(T->lchild);
	if (T->rchild)
		post_visit(T->rchild);
	printf("%c ", T->data);
}

void PostOrderTraverse(BiTree T)
{
	post_visit(T);
}

void LevelOrderTraverse(BiTree T)
{
	int i = 0, j = 0;
	BiTree n[100];
	n[j++] = T;
	while (i != j) {
		printf("%c ", n[i]->data);
		if (n[i]->lchild)
			n[j++] = n[i]->lchild;
		if (n[i]->rchild)
			n[j++] = n[i]->rchild;
		i++;
	}
}

void Assign(BiTree& T, BiTNode* &cur_p, char value)
{
	cur_p->data = value;
}

void InsertChild(BiTree &T, BiTNode* &cur_p, int LR, BiTree &c)
{
	if (LR) {
		c->rchild = cur_p->rchild;
		cur_p->rchild = c;
	}
	else {
		c->rchild = cur_p->lchild;
		cur_p->lchild = c;
	}
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