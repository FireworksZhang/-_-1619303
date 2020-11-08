#include<queue>
#include<iostream>
using namespace std;
#define LISTINITSIZE 2048

struct List{
	int *pdata;
	int length;
	int size;
}SeqList;

void InitList(List &L);
void CreateList(List &L);
int GetElem(List L, int i);
bool ListEmpty(List L);
int ListLength(List L);
void ListTraverse(List L);
void DeleteElem(List &L, int i);
void DeleteDuplicateData(List &L);

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

void CreateList(List &L, int n)
{
    L.length = n;
    for (int i = 0; i < n; i++)
	{
        *(L.pdata + i) = i+1;
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
		return*(L.pdata+i-1);
	}
}

void ListTraverse(List L)
{
	cout << "线性表遍历：" << endl;
	for (int i = 0; i < L.length; i++)
	{
		cout << i+1 << ":" << *(L.pdata + i) << endl;
	}
}
//加工型操作
void DeleteElem(List &L, int i)
{
	for(int j = i;j <= L.length; j++)
	{
		*(L.pdata + j - 1) = *(L.pdata + j);
	}
	L.length -= 1;
	return;
}

void DeleteDuplicateData(List &L)
{
    for (int i = 1; i < L.length;i++)
    {
        for (int j = i + 1; j <= L.length; j++)
        {
            if(GetElem(L,i) == GetElem(L,j))
            {
                DeleteElem(L, j);
            }
        }
    }
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


 




int main(){
    int n, m, i = 1;
    queue<int> Que;
    cin >> n >> m;
    List test;
    InitList(test);
    CreateList(test, n);
    ListTraverse(test);
    while(!ListEmpty(test))
    {
        for (int j = 1; j <= ListLength(test); j++,i++)
        {
            if(i % m == 0)
            {
                Que.push(GetElem(test,j));
                DeleteElem(test, j--);
            }
        }
    }
    while(!Que.empty())
    {
        cout << Que.front() << " ";
        Que.pop();
    }


    return 0;
}