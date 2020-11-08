///////////////////////////////////////////////////////////////////////////////
// 输入正整数n、m（m<n），设有n个人坐成一圈，从第1个人开始循环报数，报到m的人出列，
// 然后再从下一个人开始报数，报到m的人又出列，如此重复，直到所有的人都出列为止。
// 要求用链式结构和顺序结构实现，按出列的先后顺序输出每个人的信息。
///////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#define n 10
#define m 3

typedef struct {
	int *num;
	int length;
}person;

int main()
{
	int i, *p, *q, *end;
	person L;

	L.num = (int*)malloc(n * sizeof(int));
	L.length = n;

	p = &(L.num[0]);
	for (i = 1; i <= n; i++)
	{
		*p = i;
		++p;
	}											//初始化完成

	p = &(L.num[0]);
	while (L.length > 1)
	{
		end = &(L.num[L.length - 1]);
		i = 1;
		while (i < m)
		{
			if (p == end)
				p = &(L.num[0]);
			else
				p++;
			++i;
		}
		printf("%d	", *p);

		q = p;
		while (q < end)
			*q = *((q++)+1);

		--L.length;
	}
	printf("%d	", L.num[0]);

	printf("\nthe end");
	system("PAUSE");
}
