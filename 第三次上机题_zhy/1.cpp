#include<iostream>
using namespace std;

const int StackMaxSize = 2048;

class Stack
{
public:
    Stack();
    void DestroyStack();
    void ClearStack();
    bool StackEmpty();
    int StackLength();
    int GetTop();
    void StcakTraverse();
    void Push(int temp);
    void Pop();
private:
    int *a;
    int length;
    int maxsize;
    int top;
};

int main()
{
    int a,n;
    cin >> n;
    Stack test;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a;
        test.Push(a);
    }
    while(!test.StackEmpty())
    {
        cout << test.GetTop() << " ";
        test.Pop();
    }
    return 0;
}

Stack::Stack()
{
    a = new int[StackMaxSize];
    length = 0;
    maxsize = StackMaxSize;
    top = 0;
    cout << "栈初始化成功"<<endl;
}

void Stack::DestroyStack()
{
    delete[] a;
    maxsize =0;
    length = 0;
    top = 0;
}

void Stack::ClearStack()
{
    length = 0;
    top = 0;
}

bool Stack::StackEmpty()
{
    if(length == 0) return 1;
    else return 0;
}

int Stack::StackLength()
{
    return length;
}
int Stack::GetTop()
{
    return *(a + top);
}
void Stack::StcakTraverse()
{
    for(int i = 0 ; i <= length ; i++)
    {
        cout << *(a + i) << " ";
    }
    cout << endl;
}
void Stack::Push(int temp)
{
    top++;
    length++;
    *(a+top) = temp;
}
void Stack::Pop()
{
    top--;
    length--;
}