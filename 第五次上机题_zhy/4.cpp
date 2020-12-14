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
    //第四题内容
    bool IsCompleteBinaryTree();
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

bool BinaryTree::IsCompleteBinaryTree()
{
    if (!head) {
        return true;
    }
    node* temp = head;
    queue<node*> qcbt;
    qcbt.push(temp);
    node* front = NULL;
    while (front = qcbt.front()) {  
        qcbt.push(front->lchild);
        qcbt.push(front->rchild);
        qcbt.pop();
    }
    while (!qcbt.empty()) {
        if (qcbt.front() != NULL) {  
            return false;
        }
        qcbt.pop();
    }
    return true;    
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
                << "3.判断树是不是完全二叉树" << endl
                << "4.退出" << endl
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
            {
                if (test.IsCompleteBinaryTree()) cout << "是完全二叉树" << endl;
                else cout << "不是完全二叉树" << endl;
                break;
            }
            case 4:
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
