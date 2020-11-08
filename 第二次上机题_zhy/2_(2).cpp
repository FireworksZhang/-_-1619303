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
    void DestroyList();
    void CreateList();
    //访问型操作
    int GetElem(int i);
    int ListLength();
    void NextElem(int cur_e, int &next_e);
    void ListTraverse();
    //加工型操作
    void SetElem(int i, int e);
    void InsertElem(int i, int e);
    void InsertElem(int e);
    void Sort();
    void DeleteElem(int i);
    void DeleteDuplicateData();
    void MixList(SListInfo temp);
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

void SListInfo::DestroyList()
{
    node *p;
    while(head->next != NULL)
    {
        p = head->next;
        head->next = p->next;
        free(p);
    }
    head = NULL;
    tail = NULL;
    ptrNode = NULL;
    length = 0;
    cout << "销毁完成" << endl;
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

int SListInfo::GetElem(int i)
{
    int e;
    if(i > length)
    {
        cout << "越界" << endl;
        return 0;
    }
    ptrNode = head->next;
    for (int j = 1; j <= i ; j++)
    {
        e = ptrNode->val;
        ptrNode = ptrNode->next;
    }
    return e;
}

int SListInfo::ListLength()
{
    return length;
}
void SListInfo::NextElem(int cur_e, int &next_e)
{
    node *i = head->next, *nxt_i = i->next;
    for (; i->next != NULL ;i = i->next,nxt_i = nxt_i->next)
    {
        if(i->val == cur_e)
        {
            next_e = nxt_i->val;
            return;
        }
    }
    cout << "未找到" << cur_e << "的后继元素" << endl;
    system("pause");
    exit(1);
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

void SListInfo::SetElem(int i, int e)
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
    return;
}

void SListInfo::InsertElem(int i, int e)
{
    length++;
    if(i > length){
        cout << "越界！" << endl;
        system("pause");
        exit(1);
    }
    node *temp = new node;
    temp->val = e;
    ptrNode = head;
    for (int j = 1; j < i;j++,ptrNode=ptrNode->next);
    temp->next = ptrNode->next;
    ptrNode->next = temp;
    if(i == length)
        tail = temp;
    
    return;
}


void SListInfo::Sort()
{
    for (int i = 1; i <= length ; i++)
    {
        for (int j = 1; j <= length - i; j++)
        {
            if(GetElem(j) < GetElem(j+1))
            {
                int temp = GetElem(j);
                SetElem(j, GetElem(j + 1));
                SetElem(j + 1, temp);
            }
        }
    }
}

void SListInfo::DeleteElem(int i)
{
    if(i > length){
        cout << "越界！" << endl;
        system("pause");
        exit(1);
    }
    ptrNode = head->next;
    if(i == 1)
    {
        head->next = ptrNode->next;
        free(ptrNode);
    }
    else if(i == length)
    {
        for (int j = 1; j < i - 1; j++, ptrNode = ptrNode->next);
        ptrNode->next = NULL;
        free(tail);
        tail = ptrNode;
    }
    else
    {
        for (int j = 1; j < i-1; j++, ptrNode = ptrNode->next);
        node *temp = new node;
        temp = ptrNode->next;
        ptrNode->next = temp->next;
        free(temp);
    }
    length--;
    return;
}

void SListInfo::DeleteDuplicateData()
{
    for (int i = 1; i < length;i++)
    {
        for (int j = i + 1; j <= length; j++)
        {
            if(GetElem(i) == GetElem(j))
            {
                DeleteElem(j--);
                //因为删除了当前节点，所以节点顺序发生了变化，要重新检测当前节点是否为重复节点
            }
        }
    }
}

void SListInfo::MixList(SListInfo temp)
{
    ptrNode = tail;
    for (int i = 1; i <= temp.ListLength();i++)
    {
        InsertElem(length+1, temp.GetElem(i));
    }
    DeleteDuplicateData();
    Sort();
}

int main()
{
    SListInfo test1,test2;
    test1.CreateList();
    test2.CreateList();
    test1.Sort();
    test2.Sort();
    cout << "---------------------------------------------------------------------------" << endl;
    test1.MixList(test2);
    cout << "---------------------------------------------------------------------------" << endl;
    
    cout << "数组遍历" << endl;
    test1.ListTraverse();

    test1.DestroyList();
    test2.DestroyList();
    return 0;
}