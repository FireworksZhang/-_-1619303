#include<iostream>
#include<stack>
#include<queue>
using namespace std;
#define InitList SListInfo;
typedef char status;
typedef struct node//节点
{
    status val;
    struct node* lchild;
    struct node* rchild;
}TreeNode, * BiTree;

class BinaryTree {
private:
    node* head;
    node* TP;
    int depth=0,temp = 0;
public:
    //初始化、销毁、清空、建表
    
    BinaryTree();//InitBiTree
    void CreateTree();
 
    void PreOrderTraverseWithoutRecursion();
    void InOrderTraverseWithoutRecursion();
    void PostOrderTraverseWithoutRecursion();
    //加工型操作
    void Assign(BiTree &p,status value);
    void InsertChild(BiTree& p, bool LR, BiTree& c);
    void DeleteChild(BiTree& p, bool LR);
    //辅助型操作
    node* getTP()
    {
        return TP;
    }
    void PROCreate(BiTree& T)
    {
        status val;
        cin >> val;
        if (val == '0')
        {
            T = NULL;
            return;
        }
        else
        {
            temp++, depth = max(temp, depth);
            T = new node;
            T->val = val;
            TP = T;
            PROCreate(T->lchild);
            PROCreate(T->rchild);
            temp--;
        }
    }
};

BinaryTree::BinaryTree()
{
    head = new node;
    if (head == NULL)
        exit(1);
    head->lchild = NULL;
    head->rchild = NULL;
    TP = head;
    cout << "初始化完成" << endl;
}

void BinaryTree::CreateTree()
{
    cout << "请输入二叉树的数据" << endl;
    PROCreate(head);
    cout << "建树完成" << endl;
}


void BinaryTree::PreOrderTraverseWithoutRecursion()
{
    if (!head)   return;
    stack<node*> s;
    s.push(head);
    node* root;
    while (!s.empty())
    {
        root = s.top();
        s.pop();
        cout << root->val << " ";
        if (root->rchild)   s.push(root->rchild);
        if (root->lchild)   s.push(root->lchild);
    }
    cout << endl;

}

void BinaryTree::InOrderTraverseWithoutRecursion()
{
    if (!head)   return;
    stack<node*> s;
    node* root = head;
    while (!s.empty() || root)
    {
        if (root)
        {
            s.push(root);
            root = root->lchild;
        }
        else
        {
            root = s.top();
            s.pop();
            cout << root->val << " ";
            root = root->rchild;
        }
    }
    cout << endl;
}

void BinaryTree::PostOrderTraverseWithoutRecursion()
{
    if (!head)   return;
    stack<node*> s1,s2;
    node* root = head;
    s1.push(root);
    while (!s1.empty())
    {
        root = s1.top();
        s1.pop();
        s2.push(root);
        if (root->lchild)
            s1.push(root->lchild);
        if (root->rchild)
            s1.push(root->rchild);
    }
    while (!s2.empty())
    {
        cout << s2.top()->val << " ";
        s2.pop();
    }
    cout << endl;
}

class work
{
public:
    BinaryTree test;
    work()
    {
        int ope;
        while (1)
        {
            cout << "------------------------" << endl
                << "请选择要进行的操作" << endl
                << "1.构造二叉树" << endl
                << "2.先序遍历(非递归)" << endl
                << "3.中序遍历(非递归)" << endl
                << "4.后序遍历(非递归)" << endl
                << "5.退出" << endl
                << "------------------------" << endl;
            cin >> ope;
            switch (ope)
            {
            case 1:
                test.CreateTree();
                break;
            case 2:
                test.PreOrderTraverseWithoutRecursion();
                break;
            case 3:
                test.InOrderTraverseWithoutRecursion();
                break;
            case 4:
                test.PostOrderTraverseWithoutRecursion();
                break;
            case 5:
            {
                cout << "退出" << endl;
                system("pause");
                return;
            }
            default:
                break;
            }
        }
    }
};

int main()
{
    work worker;
    return 0;
}