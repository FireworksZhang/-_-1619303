#include<iostream>
using namespace std;

struct Node
{
    int val;
    Node* next;
};

class Queue
{
public:
    Queue();
    void DesTroyQueue();
    void ClearQueue();
    
    bool QueueEmpty();
    int QueueLength();
    int GetHead();
    void QueueTraverse();
    
    void push(int e);
    void pop();
private:
    Node* head;
    Node* tail;
    int length;  
}; 

int main()
{
    Queue test;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        test.push(a);
    }
    test.QueueTraverse();
    test.pop();
    test.QueueTraverse();
    return 0;
}

Queue::Queue()
{
    head = new Node;
    tail = head;
    length = 0;
}
void Queue::DesTroyQueue()
{
    Node *p;
    while(head != NULL)
    {
        p = head;
        head = p->next;
        free(p);        
    }
    head = NULL;
    tail = NULL;
    length = 0;
}
void Queue::ClearQueue()
{
    Node *p = head->next;
    while(p != NULL)
    {
        p->val = 0;
        p = p->next;
    }
    tail = head;
}
    
bool Queue::QueueEmpty()
{
    return !(length);
}
int Queue::QueueLength()
{
    return length;
}
int Queue::GetHead()
{
    return head->val;
}
void Queue::QueueTraverse()
{
    Node *p = head->next;
    while(p != NULL)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}
    
void Queue::push(int e)
{
    Node *temp = new Node;
    temp->val = e;
    tail->next = temp;
    tail = temp;
    tail->next = NULL;
    length++;
}
void Queue::pop()
{
    if(length == 0)
    {
        cout << "队列无数据" << endl;
        exit(1);
    }
    Node *temp = head->next;
    head->next = temp->next;
    free(temp);
    length--;
}