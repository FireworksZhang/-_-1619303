#define _CRT_SECURE_NO_WARNINGS
////////////////////////////////////////////////////////////////////////////////////////////////////
//	��������������n���������ҳ���������ľ���ֵ����С����������������ǵĲ�ֵ�ľ���ֵ��
//	�����ʽ��
//	�����һ�а���һ������n��
//	�ڶ��а���n������������������֮��ʹ��һ���ո�ָ���
//	�����ʽ��
//	���һ����������ʾ�𰸡�
//
//	�������룺
//	5
//	1 5 4 8 20
//	���������
//	1
//	����˵����
//	�����С����������5��4������֮��Ĳ�ֵ��1��
//	�������룺
//	5
//	9 3 6 1 3y
//	���������
//	0
//	����˵����
//	��������ͬ����3������֮��Ĳ�ֵ��0.
//	���ݹ�ģ��Լ����
//	������������������2��n��1000��ÿ���������������ǲ�����10000����������
////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
	int data;
	LNode *next;
}*LinkList, LNode;

int main()
{
	int n, i, cur, min, d, status = 0;	//status:	1������ͬ��
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