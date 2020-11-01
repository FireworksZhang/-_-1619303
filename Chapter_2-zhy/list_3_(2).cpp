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
    int GetElem(int i);
    void ListTraverse();
    //加工型操作
    void DeleteElem(int i);
    void DeleteDuplicateData();
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

int SListInfo::GetElem(int i)
{
    int e;
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
    return e;
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

int main()
{
    SListInfo test;
    test.CreateList();
    cout << "--------------------------------------------------" << endl;
    cout << "链表遍历" << endl;
    test.ListTraverse();
    
    cout << "--------------------------------------------------" << endl;
    cout << "链表去重" << endl;
    test.DeleteDuplicateData();
    
    cout << "--------------------------------------------------" << endl;
    cout << "链表遍历" << endl;
    test.ListTraverse();

    return 0;
}
