#include<cstdio>
#include<cstring>
#include<stdlib.h>
#include<cmath>
#include<ctime>
#define N 100
typedef struct node
{
	int data;
	struct node *left,*right;
}BST;

BST *createbst(int n);//创建二叉排序树
BST *insnode(BST *T,int x);//在二叉排序树中插入数据点x,并返回根节点指向
BST *delnode(BST *T,int x);//在二叉排序树中删除包含x的节点，并返回根节点指向
void showbst(BST *T);//显示二叉排序树

int main()
{
	int i,n,x;
	BST *T=NULL;
	printf("请输入数据规模：\n");
	scanf("%d",&n);
	while(n>0)
	{
		T=createbst(n);//创建BST
		printf("创建好的BST为：\n");
		showbst(T);//显示BST
		for(i=1;T&&i<=4;i++)
		{
            //做连续四次的删除，待删除数据随机生成
			x=rand()%23;
			printf(" \n删除数据%d后，BST为：\n",x);	
			T=delnode(T,x);//在BST中做删除
			showbst(T);
			printf("\n\n");	
		}
		printf("请输入数据规模：\n");
	    scanf("%d",&n);
	}
}


BST *createbst(int n)
{
	int i,x;
	BST *T=NULL;
	srand(time(0));
	for(i=0;i<n;i++)
	{
		x=rand()%23;//随机生成的数据均小于23，方便调试，这个可以自行调整
		T=insnode(T,x);
	}
	return T;
}

BST *delbst(BST *T)//销毁二叉排序树
{
	if(!T)
		return NULL;
	else
	{
		T->left=delbst(T->left);
		T->right=delbst(T->right);
		free(T);
		return NULL;
	}
}

BST *insnode(BST *T,int x)//在二叉排序树中做插入，并返回根节点指向
{
	if(!T) {
		T = (BST *)malloc(sizeof(BST));
		T->left = T->right = NULL;
		T->data = x;
		return T;
	} else
	if(T->data == x) return T;
	else if(T->data < x) T->right = insnode(T->right, x);
		else T->left = insnode(T->left, x);
	return T;
}



BST *delnode(BST *T,int x)//在BST中做删除并返回根节点指向。如果x不存在，给出提示信息“该数据不存在”
{
	BST *p = T, *pa = NULL, *q;
	
	while(p) {
		if(p->data == x) {
			break;
		} else 
		if(p->data < x) {
			pa = p;
			p = p->right;
		} else {
			pa = p;
			p = p->left;
		}
	}
	if(!p) return T;
	else if(!p->left && !p->right) {
		if(!pa) {
			free(p);
			return NULL;
		} else if(pa->data < x) pa->right = NULL;
		else pa->left = NULL;
		free(p);
		return T;
	} else
		if(!p->left && p->right) {
			if(!pa) {
				q = p->right;
				free(p);
				return q;
			} 
			else if(pa->data < x) {
				pa->right = p->right;
				free(p);
			} 
			else {
				pa->left = p->right;
				free(p);
			}
		} else
		if(p->left && !p->right) {
			if(!pa) {
				q = p->left;
				free(p);
				return q;
			} 
			else if(pa->data < x) {
				pa->right = p->left;
				free(p);
			} 
			else {
				pa->left = p->left;
				free(p);
			}
		} else {
			BST *o = p->left, *lch = p->left, *rch = p->right, *pao = p;
			while(o->right) pao = o, o = o->right;
			if(pao == p) {
				lch->right = rch;
				if(pa) {
					if(pa->data < x) pa->right = lch;
					else pa->left = lch;
				} else return lch;	
			} else {
				pao->right = o->left;
				o->left = lch;
				o->right = rch;
				if(pa) {
					if(pa->data < x) pa->right = o;
					else pa->left = o;
				} else return o;
			}
			free(p);
		}
	return T;
}

void showbst(BST *T)//显示BST
{
	if(T)
	{
		printf("%d",T->data);
		if(T->left||T->right)
		{
			printf("(");
			showbst(T->left);
			printf(",");
			showbst(T->right);
			printf(")");
		}
	}
}