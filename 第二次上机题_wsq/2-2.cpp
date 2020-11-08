//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	�����Ա�A��B��Ԫ��ֵΪ���ͣ��ҵݼ����򣬱�д������ʵ�����й��ܣ�
//	�Բ���˳��ṹ����ʽ�ṹ2�ִ洢�ṹ��Ҫ����A�Ŀռ��Ϲ���һ�������Ա�C����Ԫ��ΪA��BԪ�صĲ������ұ�C�е�Ԫ��ֵ�ݼ����򣨻�����ͬ����
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

//˳��ṹ

typedef struct SqList {
	int *a;
	int length;
}SqList;

void Merge_Sq(SqList &A, SqList B)
{
	int i = 0, j = 0, k;
	A.a = (int *)realloc(A.a, sizeof(int) * (A.length + B.length));
	while (i < A.length && j < B.length) {
		if (A.a[i] == B.a[j])
			j++;
		else if (A.a[i] > B.a[j])
			i++;
		else if (A.a[i] < B.a[j]) {
			for (k = A.length; k > i; k--)
				A.a[k] = A.a[k - 1];
			A.a[i] = B.a[j];
			A.length++;
			i++;
			j++;
		}
	}//while
	if (j < B.length) {
		for (k = i; j < B.length; j++, k++)
			A.a[k] = B.a[j];
		A.length = k;
	}
}


//��ʽ�ṹ

typedef struct LNode {
	int data;
	LNode *next;
}LNode, *LinkList;

void Merge_L(LinkList &A, LinkList &B)
{
	LinkList p, q, nn;
	p = A;
	q = B->next;
	while (p->next && q) {
		if (p->next->data == q->data)
			q = q->next;
		else if (p->next->data > q->data)
			p = p->next;
		else if (p->next->data < q->data) {
			nn = (LinkList)malloc(sizeof(LNode));
			nn->data = q->data;
			nn->next = p->next;
			p->next = nn;
			p = p->next;
			q = q->next;
		}
	}//while
	if (q)
		p->next = q;
}


//���Գ���
void Merge_Sq(SqList &A, SqList B);
void Merge_L(LinkList &A, LinkList &B);
int main()
{
	int i;

	//˳��ṹ
	SqList A_Sq, B_Sq;
	int a[5] = { 9, 8, 5, 4, 2 }, b[6] = { 7, 6, 5, 4, 3, 1 };
	A_Sq.length = 5;
	A_Sq.a = (int *)malloc(sizeof(int)*A_Sq.length);
	for (i = 0; i < A_Sq.length; i++)	A_Sq.a[i] = a[i];
	B_Sq.length = 6;
	B_Sq.a = (int *)malloc(sizeof(int)*B_Sq.length);
	for (i = 0; i < B_Sq.length; i++)	B_Sq.a[i] = b[i];

	printf("before:	\n");
	for (i = 0; i < A_Sq.length; i++)
		printf("%d	", A_Sq.a[i]);
	printf("\n");
	for (i = 0; i < B_Sq.length; i++)
		printf("%d	", B_Sq.a[i]);
	Merge_Sq(A_Sq, B_Sq);
	printf("\nafter:	\n");
	for (i = 0; i < A_Sq.length; i++)
		printf("%d	", A_Sq.a[i]);

	//��ʽ�ṹ
	LinkList A_L, B_L, p;
	A_L = (LinkList)malloc(sizeof(LNode));
	A_L->next = NULL;
	for (i = 5; i > 0; i--) {
		p = (LinkList)malloc(sizeof(LNode));
		p->data = a[i - 1];
		p->next = A_L->next;
		A_L->next = p;
	}
	B_L = (LinkList)malloc(sizeof(LNode));
	B_L->next = NULL;
	for (i = 6; i > 0; i--) {
		p = (LinkList)malloc(sizeof(LNode));
		p->data = b[i - 1];
		p->next = B_L->next;
		B_L->next = p;
	}

	printf("\n\nbefore:	\n");
	for (p = A_L->next; p != NULL; p = p->next)
		printf("%d	", p->data);
	printf("\n");
	for (p = B_L->next; p != NULL; p = p->next)
		printf("%d	", p->data);
	Merge_L(A_L, B_L);
	printf("\nafter:	\n");
	for (p = A_L->next; p != NULL; p = p->next)
		printf("%d	", p->data);

	system("PAUSE");
}