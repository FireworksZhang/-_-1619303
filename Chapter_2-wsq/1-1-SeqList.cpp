#define _CRT_SECURE_NO_WARNINGS
#define ElemType int
#define LISTINITSIZE 256
#define LISTINCREMENT 128

#include<stdio.h>
#include<stdlib.h>

typedef struct SeqList		//顺序表 动态存储
{
	ElemType *pData;
	int length;
	int size;
}SeqList;

//初始化、销毁和清空操作
void InitList(SeqList &L);		//操作结果：构造一个空的线性表L
void CreateList(SeqList &L);	//操作结果：构造一个空的线性表L并赋值
void DestroyList(SeqList &L);	//初始条件：线性表L已存在	//操作结果：销毁线性表L
void ClearList(SeqList &L);		//初始条件：线性表L已存在	//操作结果：将线性表工重置为空表
//访问型操作
int ListEmpty(SeqList L);		//初始条件：线性表L已存在	//操作结果：若线性表工为空表，则返回1，否则返回0
int ListLength(SeqList L);		//初始条件：线性表L已存在	//操作结果：返回线性表L的元素个数
void GetE1em(SeqList L, int i, ElemType &e);				//初始条件：线性表工已存在，且1≤i≤ListLength(L)	//操作结果：用参数e返回线性表L中第i个元素的值
int LocateElem(SeqList L, ElemType e);						//初始条件：线性表L已存在							//操作结果：返回线性表工中第一个与参数e相同的数据元素的位置；若这样的元素不存在，则返回0
void PriorE1em(SeqList L, ElemType cur_e, ElemType &pre_e);	//初始条件：线性表L已存在							//操作结果：若cur_ e是线性表L中的数据元素，且不是第一个元素，则用pre_ e返回其前驱元素；否则操作失败，pre_ e无意义
void NextElem(SeqList L, ElemType cur_e, ElemType &next_e);	//初始条件：线性表L已存在							//操作结果：若cur_ e是线性表L中的数据元素，且不是最后一个元素，则用next_ e返回其后继元素；否则操作失败，next_ e无意义
void ListTraverse(SeqList L);	//初始条件：线性表L已存在	//操作结果：从线性表工第一个元素开始，依次访问并输出线性表的数据元素
//3.加工型操作
void SetElem(SeqList &L, int i, ElemType &e);		//初始条件：线性表L已存在，且1≤i≤Listlength(L)			//操作结果：将线性表工中第i个元素的值用参数e替换，并将旧值用参数e返回
void InsertElem(SeqList &L, int i, ElemType e);		//初始条件：线性表L已存在，且1≤i≤ListLength(L) + 1		//操作结果：在线性表工中第i个位置上插入新的数据元素e, 原来第i个到第n个元素依次向后移动一个位置，线性表L的长度加1
void DeleteE1em(SeqList &L, int i, ElemType &e);	//初始条件：线性表工已存在，且1≤i≤ListLength(L)			//操作结果：删除线性表工中第i个位置上的数据元素，并用参数e返回其元素值，原来第i + 1个到第n个元素依次向前移动一个位置，线性表工的长度减1

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
		printf("请选择一种操作：");

		scanf("%d", &judge);
		int i;
		ElemType e, cur_e;
		switch (judge) {
		case 1:
			InitList(L);
			printf("\n*已成功构造一个空线性表L\n\n");
			break;
		case 2:
			CreateList(L);
			printf("\n*已成功构造线性表L\n\n");
			break;
		case 3:
			DestroyList(L);
			printf("\n*已成功销毁线性表L\n\n");
			break;
		case 4:
			ClearList(L);
			printf("\n*已成功清空线性表L\n\n");
			break;
		case 5:
			if (ListEmpty(L))
				printf("\nL为空表\n\n");
			else
				printf("\nL非空表\n\n");
			break;
		case 6:
			printf("\n线性表L长度为%d\n\n", ListLength(L));
			break;
		case 7:
			printf("\n请输入i的值：");
			scanf("%d", &i);
			GetE1em(L, i, e);
			if (e)
				printf("L中第%d个数据元素为%d\n\n", i, e);
			else
				printf("*i值有误\n\n");
			break;
		case 8:
			printf("\n请输入e的值：");
			scanf("%d", &e);
			if (LocateElem(L, e))
				printf("%d在L中第%d个位置\n\n", e, LocateElem(L, e));
			else
				printf("L中不存在该数据元素\n\n");
			break;
		case 9:
			printf("\n请输入e的值：");
			scanf("%d", &cur_e);
			PriorE1em(L, cur_e, e);
			if (e != NULL)
				printf("%d的前一数据元素为%d\n\n", cur_e, e);
			else
				printf("查找失败\n\n");
			break;
		case 10:
			printf("\n请输入e的值：");
			scanf("%d", &cur_e);
			NextElem(L, cur_e, e);
			if (e != NULL)
				printf("%d的后一数据元素为%d\n\n", cur_e, e);
			else
				printf("查找失败\n\n");
			break;
		case 11:
			if (!L.pData)
				printf("\n*无法执行的操作\n\n");
			else
				ListTraverse(L);
			break;
		case 12:
			printf("\n请输入i的值：");
			scanf("%d", &i);
			printf("请输入e的值：");
			scanf("%d", &e);
			SetElem(L, i, e);
			printf("*执行前该位置元素数据为%d\n\n", e);
			break;
		case 13:
			printf("\n请输入i的值：");
			scanf("%d", &i);
			printf("请输入e的值：");
			scanf("%d", &e);
			if (i < 1 || i > L.length + 1)
				printf("*i值有误\n\n");
			else {
				InsertElem(L, i, e);
				printf("*插入成功\n\n");
			}
			break;
		case 14:
			printf("\n请输入i的值：");
			scanf("%d", &i);
			if (i < 1 || i > L.length)
				printf("*i值有误\n\n");
			else {
				DeleteE1em(L, i, e);
				printf("*删除成功，所删除的元素数据为%d\n\n", e);
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
	printf("\n请输入初始化数据的个数n：");
	scanf("%d", &n);
	while (L.size < n) {
		L.pData = (ElemType *)realloc(L.pData, (L.size + LISTINCREMENT) * sizeof(ElemType));
		L.size += LISTINCREMENT;
	}
	for (int i = 0; i < n; i++) {
		printf("请输入第%d个数据：", i + 1);
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
		printf("\n线性表为空\n\n");
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

