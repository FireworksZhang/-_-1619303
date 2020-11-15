#define _CRT_SECURE_NO_WARNINGS
///////////////////////////////////////////////////////////////////////////////////////////////////
//	ADT Stack ��������9��������ʽ�洢�ṹʵ��
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

//	1.��ʼ�������ٺ���ղ��� 
void InitQueue(LinkQueue &Q);		//�������������һ���ն���Q
void DestroyQueue(LinkQueue &Q);	// ��ʼ����������Q�Ѵ��� ������������ٶ���Q
void ClearQueue(LinkQueue &Q);	// ��ʼ����: ����Q�Ѵ��� ���������������Q����Ϊ�ն���
//	2.�����Ͳ���
int QueueEmpty(LinkQueue Q);	// ��ʼ����������Q�Ѵ��� ���������������QΪ�ն��У��򷵻�1, ���򷵻�0
int QueueLength(LinkQueue Q);	// ��ʼ����������Q�Ѵ��� ������������ض���Q��Ԫ�ظ���
void GetHead(LinkQueue Q, int &e);	// ��ʼ����������ֻ�Ѵ����ҷǿ� ����������ò���e���ض���Q�Ķ�ͷԪ��
void QueueTraverse(LinkQueue Q);	// ��ʼ����������Q�Ѵ����ҷǿ� ����������Ӷ�ͷ����β���η��ʲ��������Q������Ԫ��
//	3.�ӹ��Ͳ���
void EnQueue(LinkQueue &Q, int e); //��ʼ����������Q�Ѵ���	�����������������Ԫ��e��Ϊ�µĶ�βԪ��
void DeQueue(LinkQueue &Q, int &e);	// ��ʼ����������Q�Ѵ����ҷǿ� ���������ɾ������Q�Ķ�ͷԪ�أ����ò���e������ֵ

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
		printf("��ѡ��һ�ֲ�����");

		scanf("%d", &judge);
		int i, e;
		switch (judge) {
		case 1:
			InitQueue(Q);
			printf("\n*�ѳɹ�����һ���ն���Q\n\n");
			break;
		case 2:
			DestroyQueue(Q);
			printf("\n*�ѳɹ����ٶ���Q\n\n");
			break;
		case 3:
			ClearQueue(Q);
			printf("\n*�ѳɹ�������Q����Ϊ�ն���\n\n");
			break;
		case 4:
			if (QueueEmpty(Q))
				printf("\n*����QΪ�ն���\n\n");
			else
				printf("\n*����Q�ǿն���\n\n");
			break;
		case 5:
			printf("\n*����Q��Ԫ�ظ���Ϊ%d\n\n", QueueLength(Q));
			break;
		case 6:
			GetHead(Q, e);
			if (e)
				printf("\n*Q�Ķ�ͷԪ��Ϊ%d\n\n", e);
			break;
		case 7:
			printf("\n����������Ԫ�أ�");
			QueueTraverse(Q);
			printf("\n\n");
			break;
		case 8:
			printf("\n������e��ֵ��");
			scanf("%d", &e);
			EnQueue(Q, e);
			printf("\n*�Ѳ�������Ԫ��e��Ϊ�µĶ�βԪ��\n\n");
			break;
		case 9:
			DeQueue(Q, e);
			printf("\n*��ɾ������Q�Ķ�ͷԪ��%d\n\n", e);
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