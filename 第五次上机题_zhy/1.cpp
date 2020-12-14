#include<iostream>
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
    int depth=0;
public:
    //初始化、销毁、清空、建表
    BinaryTree();//InitBiTree
    void DestroyTree();
    void CreateTree();
    void ClearTree();
    //访问型操作
    bool BiTreeEmpty();
    int BiTreeDepth();
    status Root();
    status Value();
    TreeNode* Parent();
    TreeNode* LeftChild();
    TreeNode* RightChild();
    TreeNode* LeftBrother();
    TreeNode* RightBrother();
    void PreOrderTraverse();
    void InOrderTraverse();
    void PostOrderTraverse();
    void LevelOrderTraverse();
    //加工型操作
    void Assign(BiTree &p,status value);
    void InsertChild(BiTree& p, bool LR, status value);
    void DeleteChild(BiTree& p, bool LR);
    //辅助型操作
    void POOD(BiTree& T)//PostOrderDelete
    {
        if (!T)
        {
            cout << "树未创建" << endl;
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
            T = new node;
            T->val = val;
            PROCreate(T->lchild);
            PROCreate(T->rchild);
        }
    }
    void PROClear(BiTree& T)
    {
        if (T)
        {
            T->val = '-';
            PROClear(T->lchild);
            PROClear(T->rchild);
        }
        return;
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

};

BinaryTree::BinaryTree()
{
    head = new node;
    if (head == NULL)
        exit(1);
    head->lchild = NULL;
    head->rchild = NULL;
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

void BinaryTree::ClearTree()
{
    cout << "-----清空二叉树-----" << endl;
    PROClear(head);
    cout << "-----清空完成-----" << endl;
}

bool BinaryTree::BiTreeEmpty()
{
    if(head)
        return false;
    else
        return true;
}

int BinaryTree::BiTreeDepth()
{
    return depth;
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
                << "2.清空二叉树" << endl
                << "3.销毁二叉树" << endl
                << "4.判断树是否为空" << endl
                << "5.返回树的深度" << endl
                << "6.返回根节点的值" << endl
                << "7.返回p节点的值" << endl
                << "8.返回p节点的父节点指针" << endl
                << "9.返回p节点左儿子的指针" << endl
                << "10.返回p节点右儿子的指针" << endl
                << "11.返回p节点左兄弟的指针" << endl
                << "12.返回p节点右儿子的指针" << endl
                << "13.先序遍历" << endl
                << "14.中序遍历" << endl
                << "15.后序遍历" << endl
                << "16.层次遍历" << endl
                << "17.给p节点赋值" << endl
                << "18.插入节点成为p节点的左/右儿子" << endl
                << "19.删除p节点的左/右子树" << endl
                << "20.退出" << endl
                << "------------------------" << endl;
            cin >> ope;
            switch (ope)
            {
            case 1:
                test.CreateTree();
                break;
            case 2:
                test.ClearTree();
                break;
            case 3:
                test.DestroyTree();
                break;
            case 4:
                if (test.BiTreeEmpty())
                    cout << "二叉树为空" << endl;
                else
                    cout << "二叉树非空" << endl;
                break;
            case 5:
                cout << "树高为" << test.BiTreeDepth() << endl;
                break;
            case 6:
                /* code */
                break;
            case 7:
                /* code */
                break;
            case 8:
                /* code */
                break;
            case 9:
                /* code */
                break;
            case 10:
                /* code */
                break;
            case 11:
                /* code */
                break;
            case 12:
                /* code */
                break;
            case 13:
                test.PreOrderTraverse();
                break;
            case 14:
                /* code */
                break;
            case 15:
                /* code */
                break;
            case 16:
                /* code */
                break;
            case 17:
                /* code */
                break;
            case 18:
                /* code */
                break;
            case 19:
                /* code */
                break;
            case 20:
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