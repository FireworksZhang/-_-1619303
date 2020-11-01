#include<iostream>
using namespace std;
#define LISTINITSIZE 2048

struct List{
	int *pdata;
	int length;
	int size;
}SeqList;

//初始化、销毁、清空、建表
void InitList(List &L);
void DestroyList(List &L);
void CreateList(List &L);
void ClearList(List &L);
//访问型操作
bool ListEmpty(List L);
int ListLength(List L);
void GetElem(List L, int i, int &e);
int LocateElem(List L, int e);
void PriorElem(List L, int cur_e, int &pre_e);
void NextElem(List L, int cur_e, int &next_e);
void ListTraverse(List L);
//加工型操作
void SetElem(List &L, int i, int &e);
void InsertElem(List &L, int i, int e);
void DeleteElem(List &L, int i, int &e);
//INIT
void InitList(List &L)
{
	L.pdata = new int[LISTINITSIZE];
	if(L.pdata == NULL)
		 exit(1);
	L.size = LISTINITSIZE;
	L.length = 0;
	cout << "初始化成功" << endl
		 << "L.size:" << L.size << endl
		 << "L.length:" << L.length<<endl;
	return;
}

void CreateList(List &L)
{
	int n;
	cout << "创建链表，请输入链表长度：";
	cin >> n;
	L.length = n;
	for (int i = 0; i < n; i++)
	{
		cout << "请输入第" << i+1 << "个数据：";
		cin >> *(L.pdata + i);
	}
	cout << "链表创建完成!";
	return;
}

void ListTraverse(List L)
{
	cout << "线性表遍历：" << endl;
	for (int i = 0; i < L.length; i++)
	{
		cout << i+1 << ":" << *(L.pdata + i) << endl;
	}
}

void ListReverse(List &L)
{
    int temp;
    for (int i = 0; i < L.length / 2;i++)
    {
        temp = *(L.pdata + i);
        *(L.pdata + i) = *(L.pdata + L.length - i-1);
        *(L.pdata + L.length - i - 1) = temp;
    }
    return;
}

int main()
{
    List test;
    InitList(test);
    CreateList(test);
    ListTraverse(test);
    ListReverse(test);
    ListTraverse(test);

    return 0;
}