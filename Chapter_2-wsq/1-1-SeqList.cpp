#define _CRT_SECURE_NO_WARNINGS
#define ElemType int
#define LISTINITSIZE 256
#define LISTINCREMENT 128

#include<stdio.h>
#include<stdlib.h>

typedef struct SeqList		//˳��� ��̬�洢
{
	ElemType *pData;
	int length;
	int size;
}SeqList;

//��ʼ�������ٺ���ղ���
void InitList(SeqList &L);		//�������������һ���յ����Ա�L
void CreateList(SeqList &L);	//�������������һ���յ����Ա�L����ֵ
void DestroyList(SeqList &L);	//��ʼ���������Ա�L�Ѵ���	//����������������Ա�L
void ClearList(SeqList &L);		//��ʼ���������Ա�L�Ѵ���	//��������������Ա�����Ϊ�ձ�
//�����Ͳ���
int ListEmpty(SeqList L);		//��ʼ���������Ա�L�Ѵ���	//��������������Ա�Ϊ�ձ��򷵻�1�����򷵻�0
int ListLength(SeqList L);		//��ʼ���������Ա�L�Ѵ���	//����������������Ա�L��Ԫ�ظ���
void GetE1em(SeqList L, int i, ElemType &e);				//��ʼ���������Ա��Ѵ��ڣ���1��i��ListLength(L)	//����������ò���e�������Ա�L�е�i��Ԫ�ص�ֵ
int LocateElem(SeqList L, ElemType e);						//��ʼ���������Ա�L�Ѵ���							//����������������Ա��е�һ�������e��ͬ������Ԫ�ص�λ�ã���������Ԫ�ز����ڣ��򷵻�0
void PriorE1em(SeqList L, ElemType cur_e, ElemType &pre_e);	//��ʼ���������Ա�L�Ѵ���							//�����������cur_ e�����Ա�L�е�����Ԫ�أ��Ҳ��ǵ�һ��Ԫ�أ�����pre_ e������ǰ��Ԫ�أ��������ʧ�ܣ�pre_ e������
void NextElem(SeqList L, ElemType cur_e, ElemType &next_e);	//��ʼ���������Ա�L�Ѵ���							//�����������cur_ e�����Ա�L�е�����Ԫ�أ��Ҳ������һ��Ԫ�أ�����next_ e��������Ԫ�أ��������ʧ�ܣ�next_ e������
void ListTraverse(SeqList L);	//��ʼ���������Ա�L�Ѵ���	//��������������Ա���һ��Ԫ�ؿ�ʼ�����η��ʲ�������Ա������Ԫ��
//3.�ӹ��Ͳ���
void SetElem(SeqList &L, int i, ElemType &e);		//��ʼ���������Ա�L�Ѵ��ڣ���1��i��Listlength(L)			//��������������Ա��е�i��Ԫ�ص�ֵ�ò���e�滻��������ֵ�ò���e����
void InsertElem(SeqList &L, int i, ElemType e);		//��ʼ���������Ա�L�Ѵ��ڣ���1��i��ListLength(L) + 1		//��������������Ա��е�i��λ���ϲ����µ�����Ԫ��e, ԭ����i������n��Ԫ����������ƶ�һ��λ�ã����Ա�L�ĳ��ȼ�1
void DeleteE1em(SeqList &L, int i, ElemType &e);	//��ʼ���������Ա��Ѵ��ڣ���1��i��ListLength(L)			//���������ɾ�����Ա��е�i��λ���ϵ�����Ԫ�أ����ò���e������Ԫ��ֵ��ԭ����i + 1������n��Ԫ��������ǰ�ƶ�һ��λ�ã����Ա��ĳ��ȼ�1

int main()
{
	int judge = 99;
	SeqList L;
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
			if (!L.pData)
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
			if (i < 1 || i > L.length + 1)
				printf("*iֵ����\n\n");
			else {
				InsertElem(L, i, e);
				printf("*����ɹ�\n\n");
			}
			break;
		case 14:
			printf("\n������i��ֵ��");
			scanf("%d", &i);
			if (i < 1 || i > L.length)
				printf("*iֵ����\n\n");
			else {
				DeleteE1em(L, i, e);
				printf("*ɾ���ɹ�����ɾ����Ԫ������Ϊ%d\n\n", e);
			}
			break;
		case 0:
		default:
			break;
		}
	}
	system("PAUSE");
}


void InitList(SeqList &L)
{
	L.pData = (ElemType *)malloc(sizeof(ElemType) * LISTINITSIZE);
	L.length = 0;
	L.size = LISTINITSIZE;
}

void CreateList(SeqList &L)
{
	InitList(L);
	int n;
	ElemType m;
	printf("\n�������ʼ�����ݵĸ���n��");
	scanf("%d", &n);
	while (L.size < n) {
		L.pData = (ElemType *)realloc(L.pData, (L.size + LISTINCREMENT) * sizeof(ElemType));
		L.size += LISTINCREMENT;
	}
	for (int i = 0; i < n; i++) {
		printf("�������%d�����ݣ�", i + 1);
		scanf("%d", &m);
		L.pData[i] = m;
	}
	L.length += n;
}

void DestroyList(SeqList &L)
{
	if (L.pData != NULL) {
		free(L.pData);
		L.pData = NULL;
	}
	L.size = 0;
	L.length = 0;
}

void ClearList(SeqList &L)
{
	L.length = 0;
}

int ListEmpty(SeqList L)
{
	if (L.length == 0)
		return 1;
	else
		return 0;
}

int ListLength(SeqList L)
{
	return L.length;
}

void GetE1em(SeqList L, int i, ElemType &e)
{
	if (i > 0 && i <= L.length)
		e = L.pData[i - 1];
	else
		e = NULL;
}

int LocateElem(SeqList L, ElemType e)
{
	for (int i = 0; i < L.length; i++)
		if (L.pData[i] == e)
			return i + 1;
	return 0;
}

void PriorE1em(SeqList L, ElemType cur_e, ElemType &pre_e)
{
	int i = LocateElem(L, cur_e);
	if (i > 1 && i <= L.length)
		pre_e = L.pData[i - 2];
	else
		pre_e = NULL;
}

void NextElem(SeqList L, ElemType cur_e, ElemType &next_e)
{
	int i = LocateElem(L, cur_e);
	if (i > 0 && i < L.length)
		next_e = L.pData[i];
	else
		next_e = NULL;
}

void ListTraverse(SeqList L)
{
	if (L.length == 0)
		printf("\n���Ա�Ϊ��\n\n");
	else {
		printf("\noutput:	");
		for (int i = 0; i < L.length; i++)
			printf("%d	", L.pData[i]);
		printf("\n\n");
	}
}

void SetElem(SeqList &L, int i, ElemType &e)
{
	ElemType temp;
	if (i > 0 && i <= L.length) {
		temp = L.pData[i - 1];
		L.pData[i - 1] = e;
		e = temp;
	}
}

void InsertElem(SeqList &L, int i, ElemType e)
{
	if (i < 1 || i > L.length + 1)
		;///////////
	else{
		if (L.length >= L.size) {
			L.pData = (ElemType *)realloc(L.pData, (L.size + LISTINCREMENT) * sizeof(ElemType));
			L.size += LISTINCREMENT;
		}
		for (int j = L.length - 1; j >= i - 1; j--)
			L.pData[j + 1] = L.pData[j];
		L.pData[i - 1] = e;
		L.length++;
	}//else
}

void DeleteE1em(SeqList &L, int i, ElemType &e)
{
	if (i < 1 || i > L.length)
		;///////////
	else {
		e = L.pData[i - 1];
		for (int j = i; j < L.length; j++)
			L.pData[j - 1] = L.pData[j];
		L.length--;
	}
}

