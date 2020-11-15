#define _CRT_SECURE_NO_WARNINGS
///////////////////////////////////////////////////////////////////////////////////////////////////
//	ADT Stack 基本操作9个，用链式存储结构实现
///////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode, *QueuePtr;
typedef struct LinkQueue
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

//	1.初始化、销毁和清空操作 
void InitQueue(LinkQueue &Q);		//操作结果：构造一个空队列Q
void DestroyQueue(LinkQueue &Q);	// 初始条件：队列Q已存在 操作结果：销毁队列Q
void ClearQueue(LinkQueue &Q);	// 初始条件: 队列Q已存在 操作结果：将队列Q重置为空队列
//	2.访问型操作
int QueueEmpty(LinkQueue Q);	// 初始条件：队列Q已存在 操作结果：若队列Q为空队列，则返回1, 否则返回0
int QueueLength(LinkQueue Q);	// 初始条件：队列Q已存在 操作结果：返回队列Q中元素个数
void GetHead(LinkQueue Q, int &e);	// 初始条件：队列只已存在且非空 操作结果：用参数e返回队列Q的队头元素
void QueueTraverse(LinkQueue Q);	// 初始条件：队列Q已存在且非空 操作结果：从队头到队尾依次访问并输出队列Q的数据元素
//	3.加工型操作
void EnQueue(LinkQueue &Q, int e); //初始条件：队列Q已存在	操作结果：插入数据元素e作为新的队尾元素
void DeQueue(LinkQueue &Q, int &e);	// 初始条件：队列Q已存在且非空 操作结果：删除队列Q的队头元素，并用参数e返回其值

int main()
{
	int judge = 99;
	LinkQueue Q;
	while (judge) {
		printf("------------------------------------------------\n");
		printf("1.InitQueue	2.DestroyQueue	3.ClearQueue \n");
		printf("4.QueueEmpty	5.QueueLength	6.GetHead \n");
		printf("7.QueueTraverse	8.EnQueue	9.DeQueue \n");
		printf("0.exit \n");
		printf("请选择一种操作：");

		scanf("%d", &judge);
		int i, e;
		switch (judge) {
		case 1:
			InitQueue(Q);
			printf("\n*已成功构造一个空队列Q\n\n");
			break;
		case 2:
			DestroyQueue(Q);
			printf("\n*已成功销毁队列Q\n\n");
			break;
		case 3:
			ClearQueue(Q);
			printf("\n*已成功将队列Q重置为空队列\n\n");
			break;
		case 4:
			if (QueueEmpty(Q))
				printf("\n*队列Q为空队列\n\n");
			else
				printf("\n*队列Q非空队列\n\n");
			break;
		case 5:
			printf("\n*队列Q中元素个数为%d\n\n", QueueLength(Q));
			break;
		case 6:
			GetHead(Q, e);
			if (e)
				printf("\n*Q的队头元素为%d\n\n", e);
			break;
		case 7:
			printf("\n遍历队列中元素：");
			QueueTraverse(Q);
			printf("\n\n");
			break;
		case 8:
			printf("\n请输入e的值：");
			scanf("%d", &e);
			EnQueue(Q, e);
			printf("\n*已插入数据元素e作为新的队尾元素\n\n");
			break;
		case 9:
			DeQueue(Q, e);
			printf("\n*已删除队列Q的队头元素%d\n\n", e);
			break;
		case 0:
		default:
			break;
		}
	}
	system("PAUSE");
}

void InitQueue(LinkQueue &Q)
{
	Q.front = Q.rear = (LNode *)malloc(sizeof(LNode));
	if (Q.front == NULL)
		exit(0);
	Q.front->next = NULL;
}

void DestroyQueue(LinkQueue &Q)
{
	ClearQueue(Q);
	Q.front = NULL;
	Q.rear = NULL;
}

void ClearQueue(LinkQueue &Q)
{
	int e;
	while (!QueueEmpty(Q)) {
		DeQueue(Q, e);
	}
}

int QueueEmpty(LinkQueue Q)
{
	if (Q.rear == Q.front)
		return 1;
	else
		return 0;
}

int QueueLength(LinkQueue Q)
{
	QueuePtr p = Q.front;
	int i = 0;
	while (p != Q.rear) {
		i++;
		p = p->next;
	}
	return i;
}

void GetHead(LinkQueue Q, int &e)
{
	if (QueueEmpty(Q))
		e = NULL;
	else
		e = Q.front->next->data;
}

void QueueTraverse(LinkQueue Q)
{
	QueuePtr p = Q.front;
	while (p != Q.rear) {
		printf("%d	", p->next->data);
		p = p->next;
	}
}

void EnQueue(LinkQueue &Q, int e)
{
	QueuePtr s;
	s = (LNode *)malloc(sizeof(LNode));
	s->data = e;
	Q.rear->next = s;
	Q.rear = s;
}

void DeQueue(LinkQueue &Q, int &e)
{
	if (Q.front == Q.rear)
		e = NULL;
	else {
		QueuePtr p;
		p = Q.front->next;
		e = p->data;
		Q.front->next = p->next;
		if (Q.rear == p)
			Q.rear = Q.front;
		free(p);
	}
}