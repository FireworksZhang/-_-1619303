///////////////////////////////////////////////////////////////////////////////
// ����������n��m��m<n��������n��������һȦ���ӵ�1���˿�ʼѭ������������m���˳��У�
// Ȼ���ٴ���һ���˿�ʼ����������m�����ֳ��У�����ظ���ֱ�����е��˶�����Ϊֹ��
// Ҫ������ʽ�ṹ��˳��ṹʵ�֣������е��Ⱥ�˳�����ÿ���˵���Ϣ��
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
	p->next = L;								//��ʼ�����

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




