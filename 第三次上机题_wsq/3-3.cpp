#define _CRT_SECURE_NO_WARNINGS
///////////////////////////////////////////////////////////////////////////////////////////////////
//	����ջ����ʵ�ְ˻ʺ�������⡣	
///////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

typedef struct pos {
	int i;
	int j;
}pos;

typedef struct Stack {
	pos *base;
	pos *top;
}Stack;

int a[8][8] = { 0 };
int judge_position(int i, int j);
void initStack(Stack &S);
void Push(Stack &S, int i, int j);
void Pop(Stack &S, int &i, int &j);
int StackEmpty(Stack S);
void printStack(Stack S);

int main()
{
	int i, j;
	i = 0;
	j = 0;
	Stack S;
	initStack(S);
	while (j < 8) {
		if (judge_position(i, j)) {		//��ǰλ�ÿɷ��ã���ջ
			Push(S, i, j);
			if (i == 7) {				//���һ����
				printStack(S);
				Pop(S, i, j);
				while (j == 7 && !StackEmpty(S))
					Pop(S, i, j);
				j++;
			}
			else {						//��δ��ɽ�
				i++;
				j = 0;
			}
		}//if
		else {							//��ǰλ�ò��ɷ���
			if (j < 7)					//��ǰ������δ��ȫ����
				j++;
			else {						//��ǰ�����Ѿ���ȫ����
				while (j == 7 && !StackEmpty(S))
					Pop(S, i, j);
				j++;
			}	
		}//else
	}//while
	if (StackEmpty(S))
		;
	system("PAUSE");


}

int judge_position(int i, int j)
{
	int k;
	for (k = 0; k < i; k++) {
		if (a[k][j])
			return 0;
		if (j - k > 0)
			if (a[i - k - 1][j - k - 1])
				return 0;
		if (j + k < 7)
			if (a[i - k - 1][j + k + 1])
				return 0;
	}
	return 1;
}

void initStack(Stack &S)
{
	S.base = (pos *)malloc(sizeof(pos) * 8);
	S.top = S.base;
}

void Push(Stack &S, int i, int j)
{
	pos p;
	p.i = i;
	p.j = j;
	*S.top = p;
	S.top++;

	a[i][j] = 1;
}
void Pop(Stack &S, int &i, int &j)
{
	i = (S.top - 1)->i;
	j = (S.top - 1)->j;
	S.top--;

	a[i][j] = 0;
}

int StackEmpty(Stack S)
{
	if (S.top == S.base)
		return 1;
	else
		return 0;
}

void printStack(Stack S)
{
	pos *p = S.base;
	for (int i = 0; i < 8; i++) {
		printf("(%d, %d) ", p->i, p->j);
		p++;
	}
	printf("\n");
}