/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	设线性表L，元素值为整型的且存在相同值，分别采用顺序结构和链式结构存储，编写函数，利用原空间，删除重复的元素值。
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

//顺序结构

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


//链式结构

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
//测试程序
void deduplication_Sq(SqList &L);
void deduplication_L(LinkList &L);
int main()
{
	int i;

	//顺序结构
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

	//链式结构
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
