#define _CRT_SECURE_NO_WARNINGS
#define ElemType int

#include<stdio.h>
#include<stdlib.h>

typedef struct LNode	//��ʽ�ṹ
{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

//��ʼ�������ٺ���ղ���
void InitList(LinkList &L);		//�������������һ���յ����Ա�L
void CreateList(LinkList &L);	//�������������һ���յ����Ա�L����ֵ
void DestroyList(LinkList &L);	//��ʼ���������Ա�L�Ѵ���	//����������������Ա�L
void ClearList(LinkList &L);		//��ʼ���������Ա�L�Ѵ���	//��������������Ա�����Ϊ�ձ�
//�����Ͳ���
int ListEmpty(LinkList L);		//��ʼ���������Ա�L�Ѵ���	//��������������Ա�Ϊ�ձ��򷵻�1�����򷵻�0
int ListLength(LinkList L);		//��ʼ���������Ա�L�Ѵ���	//����������������Ա�L��Ԫ�ظ���
void GetE1em(LinkList L, int i, ElemType &e);				//��ʼ���������Ա��Ѵ��ڣ���1��i��ListLength(L)	//����������ò���e�������Ա�L�е�i��Ԫ�ص�ֵ
int LocateElem(LinkList L, ElemType e);						//��ʼ���������Ա�L�Ѵ���							//����������������Ա��е�һ�������e��ͬ������Ԫ�ص�λ�ã���������Ԫ�ز����ڣ��򷵻�0
void PriorE1em(LinkList L, ElemType cur_e, ElemType &pre_e);	//��ʼ���������Ա�L�Ѵ���							//�����������cur_ e�����Ա�L�е�����Ԫ�أ��Ҳ��ǵ�һ��Ԫ�أ�����pre_ e������ǰ��Ԫ�أ��������ʧ�ܣ�pre_ e������
void NextElem(LinkList L, ElemType cur_e, ElemType &next_e);	//��ʼ���������Ա�L�Ѵ���							//�����������cur_ e�����Ա�L�е�����Ԫ�أ��Ҳ������һ��Ԫ�أ�����next_ e��������Ԫ�أ��������ʧ�ܣ�next_ e������
void ListTraverse(LinkList L);	//��ʼ���������Ա�L�Ѵ���	//��������������Ա���һ��Ԫ�ؿ�ʼ�����η��ʲ�������Ա������Ԫ��
//3.�ӹ��Ͳ���
void SetElem(LinkList &L, int i, ElemType &e);		//��ʼ���������Ա�L�Ѵ��ڣ���1��i��Listlength(L)			//��������������Ա��е�i��Ԫ�ص�ֵ�ò���e�滻��������ֵ�ò���e����
void InsertElem(LinkList &L, int i, ElemType e);		//��ʼ���������Ա�L�Ѵ��ڣ���1��i��ListLength(L) + 1		//��������������Ա��е�i��λ���ϲ����µ�����Ԫ��e, ԭ����i������n��Ԫ����������ƶ�һ��λ�ã����Ա�L�ĳ��ȼ�1
void DeleteE1em(LinkList &L, int i, ElemType &e);	//��ʼ���������Ա��Ѵ��ڣ���1��i��ListLength(L)			//���������ɾ�����Ա��е�i��λ���ϵ�����Ԫ�أ����ò���e������Ԫ��ֵ��ԭ����i + 1������n��Ԫ��������ǰ�ƶ�һ��λ�ã����Ա��ĳ��ȼ�1

int main()
{
	int judge = 99;
	LinkList L = NULL;
	while (judge) {
		printf("------------------------------------------------\n");
		printf("1.InitList	5.ListEmpty	10.NextElem \n");
		printf("2.CreateList	6.ListLength	11.ListTraverse \n");
		printf("3.DestroyList	7.GetE1em	12.SetElem \n");
		printf("4.ClearList	8.LocateElem	13.InsertElem \n");
		printf("0.exit		9.PriorE1em	14.DeleteE1em \n");
		printf("��ѡ��һ�ֲ�����");

		scanf("%d", &judge);
		int i;
		ElemType e, cur_e;
		switch (judge) {
		case 1:
			InitList(L);
			printf("\n*�ѳɹ�����һ�������Ա�L\n\n");
			break;
		case 2:
			CreateList(L);
			printf("\n*�ѳɹ��������Ա�L\n\n");
			break;
		case 3:
			DestroyList(L);
			printf("\n*�ѳɹ��������Ա�L\n\n");
			break;
		case 4:
			ClearList(L);
			printf("\n*�ѳɹ�������Ա�L\n\n");
			break;
		case 5:
			if (ListEmpty(L))
				printf("\nLΪ�ձ�\n\n");
			else
				printf("\nL�ǿձ�\n\n");
			break;
		case 6:
			printf("\n���Ա�L����Ϊ%d\n\n", ListLength(L));
			break;
		case 7:
			printf("\n������i��ֵ��");
			scanf("%d", &i);
			GetE1em(L, i, e);
			if (e)
				printf("L�е�%d������Ԫ��Ϊ%d\n\n", i, e);
			else
				printf("*iֵ����\n\n");
			break;
		case 8:
			printf("\n������e��ֵ��");
			scanf("%d", &e);
			if (LocateElem(L, e))
				printf("%d��L�е�%d��λ��\n\n", e, LocateElem(L, e));
			else
				printf("L�в����ڸ�����Ԫ��\n\n");
			break;
		case 9:
			printf("\n������e��ֵ��");
			scanf("%d", &cur_e);
			PriorE1em(L, cur_e, e);
			if (e != NULL)
				printf("%d��ǰһ����Ԫ��Ϊ%d\n\n", cur_e, e);
			else
				printf("����ʧ��\n\n");
			break;
		case 10:
			printf("\n������e��ֵ��");
			scanf("%d", &cur_e);
			NextElem(L, cur_e, e);
			if (e != NULL)
				printf("%d�ĺ�һ����Ԫ��Ϊ%d\n\n", cur_e, e);
			else
				printf("����ʧ��\n\n");
			break;
		case 11:
			if (L == NULL)
				printf("\n*�޷�ִ�еĲ���\n\n");
			else
				ListTraverse(L);
			break;
		case 12:
			printf("\n������i��ֵ��");
			scanf("%d", &i);
			printf("������e��ֵ��");
			scanf("%d", &e);
			SetElem(L, i, e);
			printf("*ִ��ǰ��λ��Ԫ������Ϊ%d\n\n", e);
			break;
		case 13:
			printf("\n������i��ֵ��");
			scanf("%d", &i);
			printf("������e��ֵ��");
			scanf("%d", &e);
//			if (i < 1 || i > L.length + 1)
//				printf("*iֵ����\n\n");
//			else {
				InsertElem(L, i, e);
				printf("*ִ�����\n\n");
//			}
			break;
		case 14:
			printf("\n������i��ֵ��");
			scanf("%d", &i);
//			if (i < 1 || i > L.length)
//				printf("*iֵ����\n\n");
//			else {
				DeleteE1em(L, i, e);
				printf("*ִ�����\n\n");
//			}
			break;
		case 0:
		default:
			break;
		}
	}
	system("PAUSE");
}


void InitList(LinkList &L)
{
	L = (LinkList)malloc(sizeof(LNode));
	L->data = NULL;
	L->next = NULL;
}

void CreateList(LinkList &L)
{
	L = (LinkList)malloc(sizeof(LNode));
	L->data = NULL;
	int n, m;
	LinkList p, nn;
	p = L;
	printf("\n�������ʼ�����ݵĸ���n��");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		nn = (LinkList)malloc(sizeof(LNode));
		printf("�������%d�����ݣ�", i + 1);
		scanf("%d", &m);
		nn->data = m;
		p->next = nn;
		p = p->next;
	}
	p->next = NULL;
}

void DestroyList(LinkList &L)
{
	ClearList(L);
	free(L);
	L = NULL;
}

void ClearList(LinkList &L)
{
	LinkList p;
	while (L->next) {
		p = L->next;
		L->next = L->next->next;
		free(p);
	}
	L->next = NULL;
}

int ListEmpty(LinkList L)
{
	if (L->next == NULL)
		return 1;
	else
		return 0;
}

int ListLength(LinkList L)
{
	int length = 0;
	LinkList p = L;
	while (p->next) {
		length++;
		p = p->next;
	}
	return length;
}

void GetE1em(LinkList L, int i, ElemType &e)
{
	LinkList p = L;
	int j = 0;
	while (p->next && j < i) {
		p = p->next;
		j++;
	}
	if (j == i)
		e = p->data;
	else
		e = NULL;
}

int LocateElem(LinkList L, ElemType e)
{
	LinkList p = L;
	int i = 0;
	while (p->next) {
		i++;
		p = p->next;
		if (p->data == e)
			return i;
	}
	return 0;
}

void PriorE1em(LinkList L, ElemType cur_e, ElemType &pre_e)
{
	if (ListEmpty(L))
		pre_e = NULL;
	else {
		LinkList p = L->next;
		pre_e = NULL;
		while (p->next)
		{
			if (p->next->data == cur_e) {
				pre_e = p->data;
				break;
			}
			p = p->next;
		}
	}
}

void NextElem(LinkList L, ElemType cur_e, ElemType &next_e)
{
	if (ListEmpty(L))
		next_e = NULL;
	else {
		LinkList p = L->next;
		next_e = NULL;
		while (p->next)
		{
			if (p->data == cur_e) {
				next_e = p->next->data;
				break;
			}
			p = p->next;
		}
	}
}

void ListTraverse(LinkList L)
{
	if (L->next == NULL)
		printf("\n���Ա�Ϊ��\n\n");
	else {
		printf("\noutput:	");
		LinkList p = L->next;
		while (p->next) {
			printf("%d	", p->data);
			p = p->next;
		}
		printf("%d\n\n", p->data);
	}
}

void SetElem(LinkList &L, int i, ElemType &e)
{
	ElemType temp;
	LinkList p = L;
	int j = 0;
	while (p->next && j < i) {
		p = p->next;
		j++;
	}
	if (i == j) {
		temp = e;
		e = p->data;
		p->data = temp;
	}
	else
		e = NULL;
}

void InsertElem(LinkList &L, int i, ElemType e)
{
	LinkList p = L;
	int j = 1;
	while (p->next && j < i) {
		p = p->next;
		j++;
	}
	if (i == j) {
		LinkList nn;
		nn = (LinkList)malloc(sizeof(LNode));
		nn->data = e;
		nn->next = p->next;
		p->next = nn;
	}
}

void DeleteE1em(LinkList &L, int i, ElemType &e)
{
	LinkList p = L;
	int j = 1;
	while (p->next && j < i) {
		p = p->next;
		j++;
	}
	if (i == j && p->next) {
		LinkList temp = p->next;
		p->next = p->next->next;
		free(temp);
	}
}

