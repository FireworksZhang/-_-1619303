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

void DestroyList(List &L)
{
	if(L.pdata != NULL)
	{	
		free(L.pdata);
		L.pdata = NULL;
	}
	L.size = 0 ;
	L.length = 0;
	cout << "链表销毁已完成" << endl;
	return;
}

void ClearList(List &L)
{
	L.length = 0;
	cout << "链表清空已完成" << endl;
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

bool ListEmpty(List L){
	if(L.length == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}	
}

int ListLength(List L)
{
	return L.length;
}

void GetElem(List L, int i ,int &e)
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
		e = *(L.pdata+i-1);
	}
	return;
}

int LocateElem(List L, int e)
{
	for(int i = 0 ; i < L.length ;  i++)
	{
		if( *(L.pdata + i) == e)
			return	i+1;
	}
	return 0;
}

void PriorElem(List L, int cur_e, int &pre_e)
{
	if(*(L.pdata) == cur_e)
	{
		cout << cur_e << "无前驱元素" << endl;
		system("pause");
		exit(1);
	}
	pre_e = *(L.pdata);
	for (int i = 0; i < L.length; i++){
		if(cur_e == *(L.pdata + i))
		{
			return;
		}
		pre_e = *(L.pdata + i);
	}
	exit(1);
}

void NextElem(List L, int cur_e, int &next_e)
{
	for (int i = 0; i < L.length - 1; i++)
	{
		next_e = *(L.pdata + i + 1);
		if(cur_e == *(L.pdata + i))
		{
			return;
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

void InsertElem(List &L, int i, int e)
{
	L.length += 1;
	int temp = e;
	for(int j = i ; j <= L.length ; j++)
	{
		temp = *(L.pdata + j - 1);
		*(L.pdata + j - 1) = e;
		e = temp;
	}
	return;
}

void DeleteElem(List &L, int i, int &e)
{
	e = *(L.pdata + i - 1);
	for(int j = i;j <= L.length; j++)
	{
		*(L.pdata + j - 1) = *(L.pdata + j);
	}
	L.length -= 1;
	return;
}

int main(){
	int i,e;
	InitList(SeqList);//初始化
	if(ListEmpty(SeqList))//
		cout << "链表此时为空链表" << endl;
	cout << "链表此时长度为："<<ListLength(SeqList) << endl;
	
	CreateList(SeqList);//建表
	if(!ListEmpty(SeqList))
		cout << "链表此时非空" << endl;
	cout << "链表此时长度为："<<ListLength(SeqList) << endl;
	ListTraverse(SeqList);//链表遍历
	
	cout << "--------查询链表的第i个数据--------" << endl
		 << "请输入要查询的链表的第i个数据：";
	
	cin >> i;
	GetElem(SeqList, i, e);
	cout <<"第" << i << "个数据是："<< e << endl;

	cout << "--------查询某个数据的位置--------" << endl
		 << "请输入要查询的数据：";
	cin >> e;
	if(LocateElem(SeqList,e))
		cout << e << "在链表的第" << LocateElem(SeqList,e) << "位" << endl;
	else
	{
		cout << "链表中无该数据" << endl;
	}

	cout << "--------前驱元素查找测试--------" << endl
		 << "要查询的数据是：";
	int pre_e;
	cin >> e;
	PriorElem(SeqList, e,pre_e);
	cout << e << "的前一个数据是" << pre_e << endl;

	cout << "--------后继元素查找测试--------" << endl
		 << "要查询的数据是：";
	int nxt_e;
	cin >> e;
	NextElem(SeqList, e, nxt_e);
	cout << e << "的后一个元素是：" << nxt_e << endl;

	cout << "--------链表元素替换测试--------" << endl
		 << "请输入要替换的数据：" ;
	cin >> e;
	cout << "请输入被替换数据的位置：" ;
	cin >> i;
	SetElem(SeqList, i, e);
	cout << "原数据是：" << e << endl;
	ListTraverse(SeqList);

	cout << "--------链表元素插入测试--------" << endl
		 <<"要插入的数据内容为：";
	cin >> e;
	cout << "要插入的位置是：";
	cin >> i;
	InsertElem(SeqList,i, e);
	ListTraverse(SeqList);
	
	cout << "--------链表元素删除测试--------" << endl
		 <<"要删除的数据位置为：";
	cin >> i;
	DeleteElem(SeqList,i, e);
	cout << "被删除的数据是：" << e;
	ListTraverse(SeqList);

	cout << "--------链表清空测试--------"<< endl;
	ClearList(SeqList);
	if(ListEmpty(SeqList))//
		cout << "链表此时为空链表" << endl;
	cout << "链表此时长度为："<<ListLength(SeqList) << endl;

	cout << "--------链表销毁测试--------" << endl;
	DestroyList(SeqList);
	return 0;
}