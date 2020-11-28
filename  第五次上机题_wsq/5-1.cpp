#define _CRT_SECURE_NO_WARNINGS
///////////////////////////////////////////////////////////////////////////////////////////////////
//	���ʵ����P75  ADT BinaryTree ��������20�����ö�������ṹʵ�֣�
///////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

typedef struct BiTNode
{
	char data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//1.��ʼ�������ٺ���ղ���
//void InitBiTree(BiTree &T);		//�������������һ���ն�����T
void DestroyBiTree(BiTree &T);	//��ʼ������������T����		������������ٶ�����T
void CreateBiTree(BiTree &T);	//��ʼ������definition����������T�Ķ���		�����������definition����������T
//void ClearBiTree(BiTree &T);	//��ʼ������������T����		�����������������������Ϊ����
//2.�����Ͳ���
int BiTreeEmpty(BiTree T);		//��ʼ������������T����		�����������������TΪ�������򷵻�1, ���򷵻�0
int BiTreeDepth(BiTree T);		//��ʼ������������������	������������ض�����T�����
void Root(BiTree T, char &e);	//��ʼ������������T����		������������ض�����T�ĸ���Ԫ��ֵ
void Value(BiTree T,BiTNode* cur_p, char &e);	//��ʼ������������T���ڣ�cur_p��T��ĳ�����ָ��		�������������cur_pָ��Ľ���ֵe
void Parent(BiTree T, BiTNode* cur_p, BiTNode* &parent);		//��ʼ������������T���ڣ�cur_p��T��ĳ�����ָ��		�����������cur_p��T�ĸ���㣬�򷵻�����˫��ָ�룬���򷵻�ֵΪ��
void LeftChild(BiTree T, BiTNode* cur_p, BiTNode* &leftChild);	//��ʼ������������T���ڣ�cur_p��T��ĳ�����ָ��		�������������cur_p������ָ�룬��û�����ӣ��򷵻�ֵΪ��
void RightChild(BiTree T, BiTNode* cur_p, BiTNode* &rightChild);	//��ʼ������������T���ڣ�cur_p��T��ĳ�����ָ��		�������������cur_p���Һ��ӣ���û���Һ��ӣ��򷵻�ֵΪ��
void LeftBrother(BiTree T, BiTNode* cur_p, BiTNode* &leftBrother);		//��ʼ������������T���ڣ�cur_p��T��ĳ�����ָ��		�������������cur_p�����ֵܣ���û�����ֵܣ��򷵻�ֵΪ��
void RightBrother(BiTree T, BiTNode* cur_p, BiTNode* &rightBrother);	//��ʼ������������T���ڣ�cur_p��T��ĳ�����ָ��		�������������cur_p�����ֵܣ���û�����ֵܣ��򷵻�ֵΪ��
void PreOrderTraverse(BiTree T);		//��ʼ������������T���ڣ�visit�ǶԽ����в�����Ӧ�ú���		����������������T����ÿ�������ú���visit()һ���ҽ�һ��; һ��visit()ʧ�ܣ������ʧ��
void InOrderTraverse(BiTree T);		//��ʼ������������T���ڣ�visit�ǶԽ����в�����Ӧ�ú���		����������������T����ÿ�������ú���visit()һ���ҽ�һ��; һ��visit()ʧ�ܣ������ʧ��
void PostOrderTraverse(BiTree T);		//��ʼ������������T���ڣ�visit�ǶԽ����в�����Ӧ�ú���		����������������T����ÿ�������ú���visit()һ���ҽ�һ��; һ��visit()ʧ�ܣ������ʧ��
void LevelOrderTraverse(BiTree T);		//��ʼ������������T���ڣ�visit�ǶԽ����в�����Ӧ�ú���		�����������α���T����ÿ�������ú���visit()һ���ҽ�һ��; һ��visit()ʧ�ܣ������ʧ��
//3.�ӹ��Ͳ���
void Assign(BiTree &T, BiTNode* &cur_p, char value);		//��ʼ������������T���ڣ�cur_p��T��ĳ�����ָ��		�����������cur_p���Ԫ�ظ�ֵΪvalue
void InsertChild(BiTree &T, BiTNode* &cur_p, int LR, BiTree &c);	//��ʼ������������T���ڣ�cur_pָ��T��ĳ����㣬LRΪ0��1���ǿն�����c��T���ཻ��������Ϊ��		�������������LRΪ0��1, ����c��ΪT��pָ���������������������p��ָ����ԭ�������������������Ϊc��������
void DeleteChild(BiTree &T, BiTNode* &cur_p, int LR);		//��ʼ������������T���ڣ�cur_pָ��T��ĳ����㣬LRΪ0��1	�������������LRΪ0��1��ɾ��T��pָ�������������������

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
		printf("��ѡ��һ�ֲ�����");

		scanf("%d", &judge);
		getchar();
		BiTree p;
		int i;
		char e;
		switch (judge) {
		case 1:
			printf("\n�������������");
			CreateBiTree(T);
			printf("\n*�ѳɹ�����һ��������T\n\n");
			break;
		case 2:
			DestroyBiTree(T);
			printf("\n*�ѳɹ����ٶ�����T\n\n");
			break;
		case 3:
			if (BiTreeEmpty(T))
				printf("\n*TΪ����\n\n");
			else
				printf("\n*T�ǿ���\n\n");
			break;
		case 4:
			printf("\nT�ĸ߶�Ϊ%d\n\n", BiTreeDepth(T));
			break;
		case 5:
			Root(T, e);
			printf("\nT�ĸ���Ԫ��ֵΪ%c\n\n", e);
			break;
		case 6:
			Value(T, T, e);
			printf("\nT�ĸ���Ԫ��ֵΪ%c\n\n", e);
			break;
		case 7:
			Parent(T, T, p);
			if (!p)
				printf("\ncur_pΪT�ĸ���㣬����ֵΪ��\n\n");
			else
				printf("\ncur_p��˫�׽��Ԫ��Ϊ%c\n\n", p->data);
			break;
		case 8:
			LeftChild(T, T, p);
			if (p)
				printf("\nT������Ԫ��ֵΪ%c\n\n", p->data);
			else
				printf("\nT������Ϊ��\n\n");
			break;
		case 9:
			RightChild(T, T, p);
			if (p)
				printf("\nT���Һ���Ԫ��ֵΪ%c\n\n", p->data);
			else
				printf("\nT���Һ���Ϊ��\n\n");
			break;
		case 10:
			LeftBrother(T, T->rchild, p);
			if (p)
				printf("\ncur_p�����ֵ�Ԫ��ֵΪ%c\n\n", p->data);
			else
				printf("\ncur_pû�����ֵܣ�����ֵΪ��\n\n");
			break;
		case 11:
			RightBrother(T, T->lchild, p);
			if (p)
				printf("\ncur_p�����ֵ�Ԫ��ֵΪ%c\n\n", p->data);
			else
				printf("\ncur_pû�����ֵܣ�����ֵΪ��\n\n");
			break;
		case 12:
			printf("\n���������\n");
			PreOrderTraverse(T);
			printf("\n\n");
			break;
		case 13:
			printf("\n���������\n");
			InOrderTraverse(T);
			printf("\n\n");
			break;
		case 14:
			printf("\n���������\n");
			PostOrderTraverse(T);
			printf("\n\n");
			break;
		case 15:
			printf("\n��α�����\n");
			LevelOrderTraverse(T);
			printf("\n\n");
			break;
		case 16:
			printf("\n������value��ֵ��");
			scanf("%c", &e);
			Assign(T, T, e);
			printf("�ѽ������Ԫ�ظ�ֵΪ%c\n\n", e);
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
			printf("\n�Ѳ��������c\n\n");
			break;
		case 18:
			DeleteChild(T, T, 1);
			printf("\n��ɾ��������������\n\n");
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