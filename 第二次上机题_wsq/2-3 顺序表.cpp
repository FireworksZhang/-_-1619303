///////////////////////////////////////////////////////////////////////////////
// ����������n��m��m<n��������n��������һȦ���ӵ�1���˿�ʼѭ������������m���˳��У�
// Ȼ���ٴ���һ���˿�ʼ����������m�����ֳ��У�����ظ���ֱ�����е��˶�����Ϊֹ��
// Ҫ������ʽ�ṹ��˳��ṹʵ�֣������е��Ⱥ�˳�����ÿ���˵���Ϣ��
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
	}											//��ʼ�����

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
