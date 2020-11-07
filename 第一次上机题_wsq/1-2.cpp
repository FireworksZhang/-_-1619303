//////////////////////////////////////////////////////////////////////////////////////////////////////
//	2����Ԫ��ֵΪ���͵����Ա�L���ֱ����˳��ṹ����ʽ�ṹ�洢����д����ʵ�����Ա�ľ͵����á�
//////////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>

//˳��ṹ

typedef struct SqList{
	int *a;
	int length;
}SqList;

void ListReverse_Sq(SqList &L)
{
	int m, q, p;
	p = 0;
	q = L.length - 1;
	while (q != p && p < q)
	{
		m = L.a[p];
		L.a[p] = L.a[q];
		L.a[q] = m;
		++p;
		--q;
	}
}


//��ʽ�ṹ

typedef struct LNode {
	int data;
	LNode *next;
}LNode, *LinkList;

void ListReverse_L(LinkList &L)
{
	if (L->next->next == NULL);
	else
	{
		LinkList pre, visit, next;
		visit = L->next;
		next = L->next->next;


		while (next != NULL)
		{
			pre = visit;
			visit = next;
			next = visit->next;
			visit->next = pre;
		}

		pre = L->next;
		pre->next = next;
		L->next = visit;

	}

}
	//���Գ���
void ListReverse_Sq(SqList &L);
void ListReverse_L(LinkList &L);
int main()
{
	int i;

	//˳��ṹ
	SqList Lsq;
	int a[5] = { 1, 2, 3, 4, 5 };
	Lsq.length = 5;
	Lsq.a = a;

	printf("before:	");
	for (i = 0; i < 5; i++) 
		printf("%d	", Lsq.a[i]);
	ListReverse_Sq(Lsq);
	printf("\nafter:	");
	for (int i = 0; i < 5; i++) 
		printf("%d	", Lsq.a[i]);

	//��ʽ�ṹ
	LinkList Ll, p;
	Ll = (LinkList)malloc(sizeof(LNode)); 
	Ll->next = NULL;
	for (int i = 5; i > 0; i--) {
		p = (LinkList)malloc(sizeof(LNode));
		p->data = i;
		p->next = Ll->next;
		Ll->next = p;
	}

	printf("\n\nbefore:	");
	for (i = 0, p = Ll->next; i < 5; i++, p = p->next)
		printf("%d	", p->data);
	ListReverse_L(Ll);
	printf("\nafter:	");
	for (i = 0, p = Ll->next; i < 5; i++, p = p->next)
		printf("%d	", p->data);

	system("PAUSE");
}
		