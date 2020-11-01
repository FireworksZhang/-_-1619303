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
    void ClearList();
    //访问型操作
    bool ListEmpty();
    int ListLength();
    void GetElem(int i, int &e);
    int LocateElem(int e);
    void PriorElem(int cur_e, int &pre_e);
    void NextElem(int cur_e, int &next_e);
    void ListTraverse();
    //加工型操作
    void SetElem(int i, int &e);
    void InsertElem(int i, int e);
    void DeleteElem(int i, int &e);
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

void SListInfo::ClearList()
{
    node *p;
    while(head->next != NULL)
    {
        p = head->next;
        head->next = p->next;
        free(p);
    }
    tail = head;
    length = 0;
    cout << "链表已清空" << endl;
}

bool SListInfo::ListEmpty()
{
    if(head == tail && length == 0)
        return 1;
    else
        return 0;
}

int SListInfo::ListLength()
{
    return length;
}

void SListInfo::GetElem(int i, int &e)
{
    if(i > length)
    {
        cout << "越界" << endl;
        exit(1);
    }
    ptrNode = head->next;
    for (int j = 1; j <= i ; j++)
    {
        e = ptrNode->val;
        ptrNode = ptrNode->next;
    }
}

int SListInfo::LocateElem(int e)
{
    int i = 1;
    for (ptrNode = head->next;ptrNode != NULL; ptrNode = ptrNode->next,i++)
    {
        if(ptrNode->val == e)
            return i;
    }
    cout << "Not Found" << endl;
    return 0;
}

void SListInfo::PriorElem(int cur_e, int &pre_e)
{
    node *i = head->next,*pre_i = head;
    if(i->val == cur_e)
    {
        cout << "该元素无前驱元素" << endl;
        system("pause");
        exit(1);
    }
    pre_i = pre_i->next;
    i = i->next;
    for (; i != NULL;i=i->next,pre_i = pre_i->next)
    {
        if(i->val == cur_e)
        {
            pre_e = pre_i->val;
            return;
        }
    }
    cout << "未查找到该元素" << endl;
    system("pause");
    exit(1);
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

void SListInfo::DeleteElem(int i, int &e)
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
        e = ptrNode->val;
        free(ptrNode);
    }
    else if(i == length)
    {
        for (int j = 1; j < i - 1; j++, ptrNode = ptrNode->next);
        cout << ptrNode->val;
        ptrNode->next = NULL;
        e = tail->val;
        free(tail);
        tail = ptrNode;
    }
    else
    {
        for (int j = 1; j < i-1; j++, ptrNode = ptrNode->next);
        node *temp = new node;
        temp = ptrNode->next;
        e = temp->val;
        ptrNode->next = temp->next;
        free(temp);
    }
    length--;
    return;
}

int main()
{
    SListInfo test;
    int i,temp,pre_temp,nxt_temp;
    test.CreateList();
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "数组遍历" << endl;
    test.ListTraverse();
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "请输入要查询的位置：";
    cin >> i;
    test.GetElem(i, temp);
    cout << "第" << i << "个节点的值是：" << temp << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "请输入要查找的数据：";
    cin >> temp;
    i = test.LocateElem(temp);
    cout << temp << "在链表的第" << i << "个节点" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "请输入要查找的数据：(前驱元素部分）";
    cin >> temp;
    test.PriorElem(temp, pre_temp);
    cout << temp << "的前驱元素是" << pre_temp << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "请输入要查找的数据：(前驱元素部分）";
    cin >> temp;
    test.NextElem(temp, nxt_temp);
    cout << temp << "的后继元素是" << nxt_temp << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "请输入要被替换的元素位置：";
    cin >> i;
    cout << "请输入要替换进去的元素值：";
    cin >> temp;
    test.SetElem(i, temp);
    cout << "第" << i << "位的元素原值是：" << temp << endl;
    test.ListTraverse();
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "请输入要插入的元素位置：";
    cin >> i;
    cout << "请输入要插入进去的元素值：";
    cin >> temp;
    test.InsertElem(i, temp);
    test.ListTraverse();

    cout << "---------------------------------------------------------------------------" << endl;
    cout << "请输入要删除的元素位置：";
    cin >> i;
    test.DeleteElem(i, temp);
    test.ListTraverse();

    test.DestroyList();
    return 0;
}