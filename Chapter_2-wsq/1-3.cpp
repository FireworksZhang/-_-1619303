/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	�����Ա�L��Ԫ��ֵΪ���͵��Ҵ�����ֵͬ���ֱ����˳��ṹ����ʽ�ṹ�洢����д����������ԭ�ռ䣬ɾ���ظ���Ԫ��ֵ��
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

//˳��ṹ

typedef struct{
	int *a;
	int length;
}SqList;

void deduplication_Sq(SqList &L)
{
	int i = 1, j;
	while (i < L.length) {
		for (j = 0; j < i; j++)
			if (L.a[j] == L.a[i]) {
				for (j = i; j < L.length - 1; j++)
					L.a[j] = L.a[j + 1];
				L.length--;
				break;
			}
		i++;
	}
}


//��ʽ�ṹ

typedef struct LNode {
	int data;
	LNode *next;
}LNode, *LinkList;

void deduplication_L(LinkList &L)
{
	if (L->next->next == NULL);
	else
	{
		LinkList p, v;
		p = L->next;
		v = L->next->next;

		while (v != NULL) {
			if (p->data == v->data)
				L->next = L->next->next;
			else
				while (p->next != v)
				{
					if (p->next->data == v->data) {
						p->next = p->next->next;
						break;
					}
					p = p->next;
				}
			v = v->next;
		}


	}

}
//���Գ���
void deduplication_Sq(SqList &L);
void deduplication_L(LinkList &L);
int main()
{
	int i;

	//˳��ṹ
	SqList Lsq;
	int a[5] = { 1, 3, 1, 2, 2 };
	Lsq.length = 5;
	Lsq.a = a;

	printf("before:	");
	for (i = 0; i < Lsq.length; i++)
		printf("%d	", Lsq.a[i]);
	deduplication_Sq(Lsq);
	printf("\nafter:	");
	for (int i = 0; i < Lsq.length; i++)
		printf("%d	", Lsq.a[i]);

	//��ʽ�ṹ
	LinkList Ll, p;
	Ll = (LinkList)malloc(sizeof(LNode));
	Ll->next = NULL;
	for (int i = 0; i < 5; i++) {
		p = (LinkList)malloc(sizeof(LNode));
		p->data = a[i];
		p->next = Ll->next;
		Ll->next = p;
	}

	printf("\n\nbefore:	");
	for (p = Ll->next; p != NULL; p = p->next)
		printf("%d	", p->data);
	deduplication_L(Ll);
	printf("\nafter:	");
	for (p = Ll->next; p != NULL; p = p->next)
		printf("%d	", p->data);

	system("PAUSE");
}
