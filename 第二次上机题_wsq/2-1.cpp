///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	��Ԫ��ֵΪ���͵����Ա�L���ֱ����˳��ṹ����ʽ�ṹ�洢����д��������ѡ��/ð�������㷨ʵ�����Ա�ı�����
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

//˳��ṹ

typedef struct SqList {
	int *a;
	int length;
}SqList;

void sort_Sq(SqList &L)
{
	int i, j, min, min_index;
	for (i = 0; i < L.length - 1; i++) {
		min = L.a[i];
		min_index = i;
		for (j = i + 1; j < L.length; j++)
			if (L.a[j] < min) {
				min = L.a[j];
				min_index = j;
			}
		if (min_index != i) {
			L.a[min_index] = L.a[i];
			L.a[i] = min;
		}//if
	}//for
}


//��ʽ�ṹ

typedef struct LNode {
	int data;
	LNode *next;
}LNode, *LinkList;

void sort_L(LinkList &L)
{
	LinkList p, q, min;
	int min_data;
	for (p = L->next; p->next != NULL; p = p->next) {
		min = p;
		for (q = p->next; q != NULL; q = q->next) {
			if (q->data < min->data)
				min = q;
		}
		if (min->data != p->data) {
			min_data = min->data;
			min->data = p->data;
			p->data = min_data;
		}//if
	}//for
}


//���Գ���
void sort_Sq(SqList &L);
void sort_L(LinkList &L);
int main()
{
	int i;

	//˳��ṹ
	SqList Lsq;
	int a[10] = { 2, 5, 4, 6, 1, 4, 2, 7, 3, 0 };
	Lsq.length = 10;
	Lsq.a = a;

	printf("before:	");
	for (i = 0; i < 10; i++)
		printf("%d	", Lsq.a[i]);
	sort_Sq(Lsq);
	printf("\nafter:	");
	for (i = 0; i < 10; i++)
		printf("%d	", Lsq.a[i]);

	//��ʽ�ṹ
	LinkList Ll, p;
	int b[10] = { 2, 5, 4, 6, 1, 4, 2, 7, 3, 0 };
	Ll = (LinkList)malloc(sizeof(LNode));
	Ll->next = NULL;
	for (i = 10; i > 0; i--) {
		p = (LinkList)malloc(sizeof(LNode));
		p->data = b[i - 1];
		p->next = Ll->next;
		Ll->next = p;
	}

	printf("\n\nbefore:	");
	for (p = Ll->next; p != NULL; p = p->next)
		printf("%d	", p->data);
	sort_L(Ll);
	printf("\nafter:	");
	for (p = Ll->next; p != NULL; p = p->next)
		printf("%d	", p->data);

	system("PAUSE");
}