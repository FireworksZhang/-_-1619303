///////////////////////////////////////////////////////////////////////////////
// 输入正整数n、m（m<n），设有n个人坐成一圈，从第1个人开始循环报数，报到m的人出列，
// 然后再从下一个人开始报数，报到m的人又出列，如此重复，直到所有的人都出列为止。
// 要求用链式结构和顺序结构实现，按出列的先后顺序输出每个人的信息。
///////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#define n 10
#define m 3

typedef struct Node{
	int num;
	struct Node *next;
}*person;

int main()
{
	int i;
	person L, p, q;

	L = (person)malloc(sizeof(Node));
	L->num = 1;
	p = L;

	i = 1;
	while (i++ < n)
	{
		q = (person)malloc(sizeof(Node));
		q->num = i;
		p->next = q;
		p = q;
	}
	p->next = L;								//初始化完成

	p = L;

	if (m == 1)
	{
		for (i = 1; i <= n; i++)
			printf("%d	",i);
	}
	else
	{
		while (p != p->next)
		{
			for (i = 1; i < m - 1; i++)
				p = p->next;
			q = p->next;
			p->next = q->next;
			printf("%d	", q->num);
			free(q);
			p = p->next;
		}
		printf("%d", p->num);
	}

	printf("\nthe end");
	system("PAUSE");

}




