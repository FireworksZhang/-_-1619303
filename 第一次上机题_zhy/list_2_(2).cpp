#include<iostream>
using namespace std;
#define InitList SListInfo;
typedef struct node//节点
{
	int val;
	struct node *next;
}LNode, *LinkList;

class SListInfo{
private:
    node *head;
    node *tail;
    node *ptrNode;
    int length;
public:
    //初始化、销毁、清空、建表
    SListInfo();//InitList
    void CreateList();
    //访问型操作
    void ListTraverse();
    //加工型操作
    void SetElem(int i, int &e);
    void ListReverse();
};

SListInfo::SListInfo()
{
    head = new node;
    if(head == NULL)
        exit(1);
    head->next = NULL;
    tail = head;
    ptrNode = head;
    length = 0;
    cout << "初始化完成" << endl;
}

void SListInfo::CreateList()
{
    cout << "请输入本次建表的数据数目：";
    cin >> length;
    tail = head;
    ptrNode = head;
    
    for (int i = 1; i <= length; i++)
    {
        node *temp = new node;
        cout << "请输入第" << i << "个数据：";
        cin >> temp->val;
        tail -> next = temp;
        tail = temp;
    }
    tail->next = NULL;
    cout << "建表完成" << endl;
    return;
}

void SListInfo::ListTraverse()
{
    if(head->next == NULL)
    {
        cout << "该链表是空链表" << endl;
        exit(1);
    }
    int j = 1;
    for (node *i = head->next; i != NULL ;i = i->next , j++)
    {
        cout << "第" << j << "个节点的值是：" << i->val << endl;
    }
}

void SListInfo::SetElem(int i, int &e)
{
    if(i > length){
        cout << "越界！" << endl;
        system("pause");
        exit(1);
    }
    int temp = e;
    ptrNode = head;
    for (int j = 1; j <= i;j++,ptrNode=ptrNode->next);
    e = ptrNode->val;
    ptrNode->val = temp;
}

void SListInfo::ListReverse()
{
    int temp[length],cnt = 0,j = 0;
    for (node *i = head->next; i != NULL;i = i->next,cnt++)
    {
        temp[cnt] = i->val;
    }
    for (cnt = length ; cnt > 0; cnt--)
    {
        SetElem(cnt, temp[j++]);
    }
    return;
}
int main()
{
    SListInfo test;
    test.CreateList();
    test.ListTraverse();
    cout << "--------逆置链表--------" << endl;
    test.ListReverse();
    test.ListTraverse();

    return 0;
}