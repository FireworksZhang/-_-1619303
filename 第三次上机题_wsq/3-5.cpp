#define _CRT_SECURE_NO_WARNINGS
////////////////////////////////////////////////////////////////////////////////////////////////////
//	问题描述：给定n个数，请找出其中相差（差的绝对值）最小的两个数，输出它们的差值的绝对值。
//	输入格式：
//	输入第一行包含一个整数n。
//	第二行包含n个正整数，相邻整数之间使用一个空格分隔。
//	输出格式：
//	输出一个整数，表示答案。
//
//	样例输入：
//	5
//	1 5 4 8 20
//	样例输出：
//	1
//	样例说明：
//	相差最小的两个数是5和4，它们之间的差值是1。
//	样例输入：
//	5
//	9 3 6 1 3y
//	样例输出：
//	0
//	样例说明：
//	有两个相同的数3，它们之间的差值是0.
//	数据规模和约定：
//	对于所有评测用例，2≤n≤1000，每个给定的整数都是不超过10000的正整数。
////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
	int data;
	LNode *next;
}*LinkList, LNode;

int main()
{
	int n, i, cur, min, d, status = 0;	//status:	1存在相同数
	scanf("%d", &n);

	LinkList L, p, nn;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;

	for (i = 0; i < n; i++) {
		scanf("%d", &cur);
		p = L;
		while (p->next) {
			if (cur == p->next->data) {
				status = 1;
				break;
			}
			else if (cur > p->next->data) {
				nn = (LinkList)malloc(sizeof(LNode));
				nn->data = cur;
				nn->next = p->next;
				p->next = nn;
				break;
			}
			else
				p = p->next;
		}
		if (status)
			break;
		if (p->next == NULL) {
			nn = (LinkList)malloc(sizeof(LNode));
			nn->data = cur;
			nn->next = NULL;
			p->next = nn;
		}
	}
	if (status) 
		printf("0");
	else {
		min = 10000;
		p = L->next;
		while (p->next) {
			d = p->data - p->next->data;
			if (d < min)
				min = d;
			p = p->next;
		}
		printf("%d", min);
	}
}