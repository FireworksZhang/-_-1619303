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
    void DestroyTree();
    void CreateTree();
    //访问型操作
    void PreOrderTraverse();
    void InOrderTraverse();
    void PostOrderTraverse();
    void LevelOrderTraverse();
    //第二题内容
    void PreOrderTraverseWithoutRecursion();
    void InOrderTraverseWithoutRecursion();
    void PostOrderTraverseWithoutRecursion();
    //第三题内容
    void DeleteAllxTree(status x);
    //辅助型操作
    void POOD(BiTree& T)//PostOrderDelete
    {
        if (!T)
        {
            cout << "树未创建" << endl;
            return;
        }
        if (T->lchild)
            POOD(T->lchild);
        if (T->rchild)
            POOD(T->rchild);
        T = NULL;
        free(T);
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
    void PROT(BiTree T)
    {
        if (T)
        {
            cout << T->val << " ";
            PROT(T->lchild);
            PROT(T->rchild);
        }
        return;
    }
    void IOT(BiTree T)
    {
        if (T)
        {
            IOT(T->lchild);
            cout << T->val << " ";
            IOT(T->rchild);
        }
        return;
    }
    void POOT(BiTree T)
    {
        if (T)
        {
            POOT(T->lchild);
            POOT(T->rchild);
            cout << T->val << " ";
        }
        return;
    }
    void DAxT(BiTree& T,status x)
    {
        if (!T)
            return;
        if (T->val == x)
        {
            POOD(T);
            return;
        }
        if (T->lchild)
            DAxT(T->lchild,x);
        if (T->rchild)
            DAxT(T->rchild,x);

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

void BinaryTree::DestroyTree()
{
    POOD(head);
    cout << "销毁完成" << endl;
}

void BinaryTree::CreateTree()
{
    cout << "请输入二叉树的数据" << endl;
    PROCreate(head);
    cout << "建树完成" << endl;
}

void BinaryTree::PreOrderTraverse()
{
    cout << "-----先序遍历-----" << endl;
    if (head)
        PROT(head);
    else
        cout << "二叉树为空";
    cout << endl << "-----遍历结束-----" << endl;
}

void BinaryTree::InOrderTraverse()
{
    cout << "-----中序遍历-----" << endl;
    if (head)
        IOT(head);
    else
        cout << "二叉树为空";
    cout << endl << "-----遍历结束-----" << endl;
}

void BinaryTree::PostOrderTraverse()
{
    cout << "-----后序遍历-----" << endl;
    if (head)
        POOT(head);
    else
        cout << "二叉树为空";
    cout << endl << "-----遍历结束-----" << endl;
}

void BinaryTree::LevelOrderTraverse()
{
    queue<node*> q1,q2;
    q1.push(head);
    while (!q1.empty())
    {
        if (q1.front()->lchild != NULL)
            q1.push(q1.front()->lchild);
        if (q1.front()->rchild != NULL)
            q1.push(q1.front()->rchild);
        q2.push(q1.front());
        q1.pop();
    }
    while (!q2.empty())
    {
        cout << q2.front()->val << " ";
        q2.pop();
    }
    cout << endl;
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

void BinaryTree::DeleteAllxTree(status x)
{
    DAxT(head, x);
    return;
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
                << "2.销毁二叉树" << endl
                << "3.先序遍历" << endl
                << "4.中序遍历" << endl
                << "5.后序遍历" << endl
                << "6.层次遍历" << endl
                << "7.先序遍历(非递归)" << endl
                << "8.中序遍历(非递归)" << endl
                << "9.后序遍历(非递归)" << endl
                << "10.删除值为x的所有子树" << endl
                << "11.退出" << endl
                << "------------------------" << endl;
            cin >> ope;
            switch (ope)
            {
            case 1:
                test.CreateTree();
                break;
                break;
            case 2:
                test.DestroyTree();
                break;
            case 3:
                test.PreOrderTraverse();
                break;
            case 4:
                test.InOrderTraverse();
                break;
            case 5:
                test.PostOrderTraverse();
                break;
            case 6:
                test.LevelOrderTraverse();
                break;
            case 7:
                test.PreOrderTraverseWithoutRecursion();
                break;
            case 8:
                test.InOrderTraverseWithoutRecursion();
                break;
            case 9:
                test.PostOrderTraverseWithoutRecursion();
                break;
            case 10:
            {
                cout << "请输入要删除的元素的值:";
                status x;
                cin >> x;
                test.DeleteAllxTree(x);
                break;
            }
            case 11:
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
