#define _CRT_SECURE_NO_WARNINGS
////////////////////////////////////////////////////////////////////////////////////////////////////
//	输入稀疏矩阵，建立稀疏矩阵三元组顺序结构，实现矩阵的列序遍历转置和快速转置算法。
////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 10

typedef struct
{
	int i, j;
	int v;
}Triple;

typedef struct
{
	Triple arr[MAXSIZE + 1];
	int row, col, num;
}SqSMatrix;

void InitSMatrix(SqSMatrix &M, char* filename);
void TransposeSMatrix(SqSMatrix M, SqSMatrix &A);
void FastTransposeSMatrix(SqSMatrix M, SqSMatrix &A);
void printSMatrix(SqSMatrix M);

int main()
{
	SqSMatrix M, A, B;
	char filename[] = "smatrix.txt";
	InitSMatrix(M, filename);
	printSMatrix(M);

	printf("列序遍历转置:\n");
	TransposeSMatrix(M, A);
	printSMatrix(A);
	printf("快速转置:\n");
	FastTransposeSMatrix(M, B);
	printSMatrix(B);

	system("PAUSE");

}

void InitSMatrix(SqSMatrix &M, char* filename)
{
	int i, j, n, e;
	i = 0;
	j = 0;
	n = 0;

	FILE *fp;
	fp = fopen(filename, "r");

	e = fgetc(fp);
	while (!feof(fp)) {
		if (e == '\n') {
			i++;
			j = 0;
		}
		else if (e == '0')
			j++;
		else if (e != ' ') {
			M.arr[n].i = i;
			M.arr[n].j = j++;
			M.arr[n++].v = e - 48;
		}
		e = fgetc(fp);
	}//while
	M.row = ++i;
	M.col = j;
	M.num = n;

	fclose(fp);
}

void TransposeSMatrix(SqSMatrix M, SqSMatrix &A)
{
	int p, q, k;

	A.row = M.col;
	A.col = M.row;
	A.num = M.num;

	if (M.num > 0) {
		q = 0;
		for (k = 0; k < M.col; k++)
			for (p = 0; p < M.num; p++)
				if (M.arr[p].j == k) {
					A.arr[q].i = M.arr[p].j;
					A.arr[q].j = M.arr[p].i;
					A.arr[q].v = M.arr[p].v;
					q++;
				}
	}

}

void FastTransposeSMatrix(SqSMatrix M, SqSMatrix &A)
{
	A.row = M.col;
	A.col = M.row;
	A.num = M.num;

	if (M.num > 0) {
		int k, p, q, *rowNum, *rowStart;
		rowNum = (int *)malloc(sizeof(int) * M.col);
		rowStart = (int *)malloc(sizeof(int) * M.col);

		for (k = 0; k < M.col; k++)
			rowNum[k] = 0;
		for (k = 0; k < M.num; k++)
			rowNum[M.arr[k].j]++;

		rowStart[0] = 0;
		for (k = 1; k < M.col; k++)
			rowStart[k] = rowStart[k - 1] + rowNum[k - 1];

		for (p = 0; p < M.num; p++) {
			q = rowStart[M.arr[p].j];
			A.arr[q].i = M.arr[p].j;
			A.arr[q].j = M.arr[p].i;
			A.arr[q].v = M.arr[p].v;
			rowStart[M.arr[p].j]++;
		}
	}//if
}

void printSMatrix(SqSMatrix M)
{
	int i, j, k = 0;
	for (i = 0; i < M.row; i++) {
		for (j = 0; j < M.col; j++)
			if (k < M.num && M.arr[k].i == i && M.arr[k].j == j)
				printf("%d ", M.arr[k++].v);
			else
				printf("0 ");
		printf("\n");
	}
}
