#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
typedef struct node
{
	int data;
	struct node *next;
}LI;//基数排序所需的链式结构

void getdata(LI *A,LI *B,int *a,int n);//获取n个随机数创建两个无序链表和一个数组
void showlist(LI *head);//显示链表数据
void showarray(int *a,int n);//显示数组数据
void mergesort(int *a,int n);//归并排序
void radixsort(LI *head);//基数排序
void bubblesort(LI *head);//冒泡排序
void dellist(LI *head);//销毁链表


int main()
{
	int *a,n;
	LI *A,*B;
	A=(LI *)malloc(sizeof(LI));
	B=(LI *)malloc(sizeof(LI));
	A->next=B->next=NULL;//创建两个空的带头链表
	printf("\n请输入数据规模:\n");
	scanf("%d",&n);
	while(n>0)
	{
		a=(int *)malloc((n+1)*sizeof(int));//0号位置不放数据
		getdata(A,B,a,n);//获取链表与数组数据
		radixsort(A);//基数排序
		mergesort(a,n);//归并排序
		bubblesort(B);//冒泡排序
		free(a);//释放数组空间
		dellist(A);//销毁链表
		dellist(B);//销毁链表
		printf("\n请输入数据规模:\n");//重新输入需要排序的数据规模
	    scanf("%d",&n);
	}
}

void getdata(LI *A,LI *B,int *a,int n)//获取n个随机数创建无序链表与数组
{
	
	LI *p;
	int i,x;
	srand(time(0));
	for(i=1;i<=n;i++)
	{
		x=rand();
		p=(LI *)malloc(sizeof(LI));
		p->data=x;
		p->next=A->next;
		A->next=p;
		p=(LI *)malloc(sizeof(LI));
		p->data=x;
		p->next=B->next;
		B->next=p;
		a[n-i+1]=x;//注意数组的有效元素是从a[1]----a[n]
	}
}

void showlist(LI *head)//显示链表内容
{
	int i=0;
	LI *p=head->next;
	while(p)
	{
		printf("%-6d ",p->data);
		i++;
		if(i%15==0)
			printf("\n");
		p=p->next;
	}
	printf("\n");
}

void showarray(int *a,int n)//显示数组内容
{
	int i,j;
	for(i=1,j=0;i<=n;i++)
	{
		printf("%-6d ",a[i]);
		j++;
		if(j%15==0)
			printf("\n");
	}
	printf("\n");
}

void dellist(LI *head)//销毁链表
{
	LI *p,*p2;
	p=head->next;
	head->next=NULL;
	while(p)
	{
		p2=p->next;
		free(p);
		p=p2;
	}
}

void mergesort(int *a,int n)//归并排序
{
	int *t;
	t=(int *)malloc((n+1)*sizeof(int));//辅助数组
	
	int i, j, k, len, mid, p1, p2, cnt;
	for(len = 2; len <= n; len <<= 1) {
		i = j = 1;
		while(j < n) {
			j = i + len - 1;
			if(j > n) j = n;
			mid = i + (len / 2) - 1;
			if(mid > n) break; 
			p1 = i;
			p2 = mid + 1;
			cnt = i;
			while(p1 <= mid && p2 <= j) {
				if(a[p1] <= a[p2]) {
					t[cnt++] = a[p1++];
				} else {
					t[cnt++] = a[p2++];
				}
			}
			while(p1 <= mid) t[cnt++] = a[p1++];
			while(p2 <= j) t[cnt++] = a[p2++];
			for(k = i; k <= j; k++) a[k] = t[k];
			i += len;
			
		}
		
	}
	
	len >>= 1;
	if(len < n) {
		mid = len;
		p1 = i = 1;
		j = n;
		p2 = len + 1;
		cnt = 1;
		while(p1 <= mid && p2 <= j) {
			if(a[p1] <= a[p2]) {
				t[cnt++] = a[p1++];
			} else {
				t[cnt++] = a[p2++];
			}
		}
		while(p1 <= mid) t[cnt++] = a[p1++];
		while(p2 <= j) t[cnt++] = a[p2++];
		for(k = i; k <= j; k++) a[k] = t[k];
	}

	printf("\n归并排序的结果：\n");
	showarray(a,n);
	free(t);
}

void bubblesort(LI *head)//冒泡排序
{
	LI *p = head->next, *pa = head;
	if(p && p->next) {
		int cnt = 1;
		while(p) {
			cnt++;
			p = p->next;
		}
		p = head->next, pa = head;
		LI *np = p->next;
		int flag;
		do {
			flag = 0;
			pa = head;
			p = head->next;
			np = p->next;
			int tmp = 0;
			cnt--;
			
			while(np) {
				tmp++;
				if(tmp == cnt) break;
				if(p->data > np->data) {
					flag = 1;
					pa->next = np;
					p->next = np->next;
					np->next = p;	
					pa = np;
					np = p->next;
				} else {
					pa = p;
					p = np;
					np = np->next;
				}
				
			}
			
		}while(flag);
	} 
	printf("\n冒泡排序的结果：\n");
	showlist(head);
}


void radixsort(LI *head)//基数排序
{
	LI *h[2], *r[2];
	LI *p = head->next;
	int d = 0, tmp_d = 0, tmp, i, pos;
	h[0] = (LI *)malloc(sizeof(LI));
	h[1] = (LI *)malloc(sizeof(LI));
	
	while(p) {
		tmp = p->data;
		tmp_d = 0;
		while(tmp) {
			tmp_d++;
			tmp >>= 1;
		}
		if(d < tmp_d) d = tmp_d;
		p = p->next;
	}
	
	for(i = 0; i < d; i++) {
		p = head->next;
		
		r[0] = r[1] = NULL;
		h[0]->next = h[1]->next = NULL;
		while(p) {
			tmp = p->data;
			pos = (tmp >> i) & 1;
			if(!h[pos]->next) {
				h[pos]->next = r[pos] = p;
			} else {
				r[pos]->next = p;
				r[pos] = p;
			}
			p = p->next;
		}
		if(r[0] && h[1]->next) r[0]->next = h[1]->next;
		if(h[0]->next) head->next = h[0]->next;
		else head->next = h[1]->next;
		if(r[1]) r[1]->next = NULL;
		else r[0]->next = NULL;
	}
	printf("\n基数排序的结果：\n");
	showlist(head);
}