#define _CRT_SECURE_NO_WARNINGS
///////////////////////////////////////////////////////////////////////////////////////////////////
//	ADT Stack ��������9������˳��洢�ṹʵ��
///////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>
#define STACKINITSIZE 256
#define STACKINCREMENT 128

typedef struct SeqStack
{
	int *pBase;
	int *pTop;
	int stacksize;
}SeqStack;

//	1.��ʼ�������ٺ���ղ��� 
void InitStack(SeqStack &S);		//�������������һ����ջS
void DestroyStack(SeqStack &S);		//��ʼ������ջS�Ѵ���			�������������ջS
void ClearStack(SeqStack &S);		//��ʼ������ջS�Ѵ���			�����������ջS����Ϊ��ջ
//	2.�����Ͳ���
int StackEmpty(SeqStack S);			//��ʼ������ջS�Ѵ���			�����������ջSΪ��ջ���򷵻�1, ���򷵻�0
int StackLength(SeqStack S);		//��ʼ������ջS�Ѵ���			�������������ջS��Ԫ�ظ���
void GetTop(SeqStack S, int &e);	//��ʼ������ջS�Ѵ����ҷǿ�		����������ò���e����ջS��ջ��Ԫ��
void StackTraverse(SeqStack S);		//��ʼ������ջS�Ѵ����ҷǿ�		�����������ջ�׵�ջ�����η��ʲ����ջS������Ԫ��
//	3.�ӹ��Ͳ���
void Push(SeqStack &S, int e);		//��ʼ������ջS�Ѵ���			�����������������Ԫ��e��Ϊ�µ�ջ��Ԫ��
void Pop(SeqStack &S, int &e);		//��ʼ������ջS�Ѵ����ҷǿ�		���������ɾ��ջS��ջ��Ԫ�أ����ò���e������ֵ

int main()
{
	int judge = 99;
	SeqStack S;
	while (judge) {
		printf("------------------------------------------------\n");
		printf("1.InitList	2.DestroyStack	3.ClearStack \n");
		printf("4.StackEmpty	5.StackLength	6.GetTop \n");
		printf("7.StackTraverse	8.Push		9.Pop \n");
		printf("0.exit \n");
		printf("��ѡ��һ�ֲ�����");

		scanf("%d", &judge);
		int i, e;
		switch (judge) {
		case 1:
			InitStack(S);
			printf("\n*�ѳɹ�����һ����ջS\n\n");
			break;
		case 2:
			DestroyStack(S);
			printf("\n*�ѳɹ�����ջS\n\n");
			break;
		case 3:
			ClearStack(S);
			printf("\n*�ѳɹ���ջS����Ϊ��ջ\n\n");
			break;
		case 4:
			if (StackEmpty(S))
				printf("\n*SΪ��ջ\n\n");
			else
				printf("\n*S�ǿ�ջ\n\n");
			break;
		case 5:
			printf("\n*ջS��Ԫ�ظ���Ϊ%d\n\n", StackLength(S));
			break;
		case 6:
			GetTop(S, e);
			if (e)
				printf("\n*ջS��ջ��Ԫ��Ϊ%d\n\n", e);
			break;
		case 7:
			printf("\n����ջ��Ԫ�أ�");
			StackTraverse(S);
			printf("\n\n");
			break;
		case 8:
			printf("\n������e��ֵ��");
			scanf("%d", &e);
			Push(S, e);
			printf("\n*�Ѳ�������Ԫ��e��Ϊ�µ�ջ��Ԫ��\n\n");
			break;
		case 9:
			Pop(S, e);
			printf("\n*��ɾ��ջS��ջ��Ԫ��%d\n\n", e);
			break;
		case 0:
		default:
			break;
		}
	}
	system("PAUSE");
}

void InitStack(SeqStack &S)
{
	S.pBase = (int *)malloc(sizeof(int) * STACKINITSIZE);
	if (S.pBase == NULL)
		exit(0);
	S.pTop = S.pBase;
	S.stacksize = STACKINITSIZE;
}

void DestroyStack(SeqStack &S)
{
	if (S.pBase != NULL)
	{
		free(S.pBase);
		S.pBase = NULL;
	}
	S.pTop = NULL;
	S.stacksize = 0;
}

void ClearStack(SeqStack &S)
{
	S.pTop = S.pBase;
}

int StackEmpty(SeqStack S)
{
	if (S.pBase == S.pTop)
		return 1;
	else
		return 0;
}

int StackLength(SeqStack S)
{
	int i = 0, *p = S.pBase;
	while (p != S.pTop) {
		i++;
		p++;
	}
	return i;
}

void GetTop(SeqStack S, int &e)
{
	if (S.pBase == S.pTop)
		e = NULL;
	else
		e = *(S.pTop - 1);
}

void StackTraverse(SeqStack S)
{
	int *p = S.pBase;
	while (p != S.pTop)
		printf("%d	", *(p++));
}

void Push(SeqStack &S, int e)
{
	if (S.pTop - S.pBase >= S.stacksize) {
		S.pBase = (int *)realloc(S.pBase, sizeof(int) * (STACKINCREMENT + STACKINITSIZE));
		if (S.pBase == NULL)
			exit(0);
		S.pTop = S.pBase + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.pTop = e;
	S.pTop++;
}

void Pop(SeqStack &S, int &e)
{
	if (S.pBase == S.pTop)
		e = NULL;
	else {
		e = *(S.pTop - 1);
		S.pTop--;
	}
}