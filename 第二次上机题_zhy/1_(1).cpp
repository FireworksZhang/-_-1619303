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
void CreateList(List &L);
//访问型操作
int GetElem(List L, int i);
void NextElem(List L, int cur_e, int &next_e);
void ListTraverse(List L);
//加工型操作
void SetElem(List &L, int i, int &e);
//INIT
void Sort(List &L);
int main()
{
	List test;
	InitList(test);
	CreateList(test);
	cout << "线性表遍历：" << endl;
	ListTraverse(test);
	cout << "线性表排序：" << endl;
	Sort(test);
	cout << "线性表遍历：" << endl;
	ListTraverse(test);
	
	return 0;
}

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

int GetElem(List L, int i)
{
	if(i > L.length)	
	{
		exit(1);
	}
	else if(i < 1)
	{
		exit(1);
	}
	else
	{
		return *(L.pdata+i-1);
	}
}

int NextElem(List L, int cur_e)
{
	int next_e;
	for (int i = 0; i < L.length - 1; i++)
	{
		next_e = *(L.pdata + i + 1);
		if(cur_e == *(L.pdata + i))
		{
			return next_e;
		}
	}
	cout << cur_e << "无后继元素" << endl;
	exit(1);
}

void ListTraverse(List L)
{
	cout << "数组遍历：" << endl;
	for (int i = 0; i < L.length; i++)
	{
		cout << i+1 << ":" << *(L.pdata + i) << endl;
	}
}
//加工型操作
void SetElem(List &L, int i, int &e)
{
	int temp = e;
	e = *(L.pdata + i - 1);
	*(L.pdata + i - 1) = temp;
	return;
}

void Sort(List &L)
{
	int temp;
	for(int i = 1 ; i <= L.length ; i++)
	{
		for(int j = 1 ; j <= L.length - i ;j++)
	 	{
	 		if(GetElem(L,j) > NextElem(L,GetElem(L,j)))
			{
				temp = GetElem(L,j);
				int t = NextElem(L, GetElem(L,j));
				SetElem(L,j,t);
				SetElem(L,j+1,temp);
			}	 	
	 	}
	 }
	 return;
}
