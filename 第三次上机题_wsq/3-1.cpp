#define _CRT_SECURE_NO_WARNINGS
///////////////////////////////////////////////////////////////////////////////////////////////////
//	ADT Stack 基本操作9个，用顺序存储结构实现
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

//	1.初始化、销毁和清空操作 
void InitStack(SeqStack &S);		//操作结果：构造一个空栈S
void DestroyStack(SeqStack &S);		//初始条件：栈S已存在			操作结果：销毁栈S
void ClearStack(SeqStack &S);		//初始条件：栈S已存在			操作结果：将栈S重置为空栈
//	2.访问型操作
int StackEmpty(SeqStack S);			//初始条件：栈S已存在			操作结果：若栈S为空栈，则返回1, 否则返回0
int StackLength(SeqStack S);		//初始条件：栈S已存在			操作结果：返回栈S中元素个数
void GetTop(SeqStack S, int &e);	//初始条件：栈S已存在且非空		操作结果：用参数e返回栈S的栈顶元素
void StackTraverse(SeqStack S);		//初始条件：栈S已存在且非空		操作结果：从栈底到栈顶依次访问并输出栈S的数据元素
//	3.加工型操作
void Push(SeqStack &S, int e);		//初始条件：栈S已存在			操作结果：插入数据元素e作为新的栈顶元素
void Pop(SeqStack &S, int &e);		//初始条件：栈S已存在且非空		操作结果：删除栈S的栈顶元素，并用参数e返回其值

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
		printf("请选择一种操作：");

		scanf("%d", &judge);
		int i, e;
		switch (judge) {
		case 1:
			InitStack(S);
			printf("\n*已成功构造一个空栈S\n\n");
			break;
		case 2:
			DestroyStack(S);
			printf("\n*已成功销毁栈S\n\n");
			break;
		case 3:
			ClearStack(S);
			printf("\n*已成功将栈S重置为空栈\n\n");
			break;
		case 4:
			if (StackEmpty(S))
				printf("\n*S为空栈\n\n");
			else
				printf("\n*S非空栈\n\n");
			break;
		case 5:
			printf("\n*栈S中元素个数为%d\n\n", StackLength(S));
			break;
		case 6:
			GetTop(S, e);
			if (e)
				printf("\n*栈S中栈顶元素为%d\n\n", e);
			break;
		case 7:
			printf("\n遍历栈中元素：");
			StackTraverse(S);
			printf("\n\n");
			break;
		case 8:
			printf("\n请输入e的值：");
			scanf("%d", &e);
			Push(S, e);
			printf("\n*已插入数据元素e作为新的栈顶元素\n\n");
			break;
		case 9:
			Pop(S, e);
			printf("\n*已删除栈S的栈顶元素%d\n\n", e);
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