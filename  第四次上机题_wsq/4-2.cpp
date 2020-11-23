#define _CRT_SECURE_NO_WARNINGS
///////////////////////////////////////////////////////////////////////////////////////////////////
//	求矩阵的马鞍点。
///////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int e[20][20];
	int row, col;
}Matrix;

void InitMatrix(Matrix &M, char* filename);
void newMatrix(Matrix M, Matrix &A);

int main()
{
	Matrix M, A;
	char filename[] = "matrix.txt";
	InitMatrix(M, filename);
	newMatrix(M, A);
	
	int i, j, min, max;
	for (i = 0; i < M.row; i++) {
		min = M.e[i][0];
		for (j = 1; j < M.col; j++)
			if (M.e[i][j] < min)
				min = M.e[i][j];
		for (j = 0; j < M.col; j++)
			if (M.e[i][j] == min)
				A.e[i][j] = 1;
	}
	for (j = 0; j < M.col; j++) {
		max = M.e[0][j];
		for (i = 1; i < M.row; i++)
			if (M.e[i][j] > max)
				max = M.e[i][j];
		for (i = 0; i < M.row; i++)
			if (M.e[i][j] == max)
				A.e[i][j]++;
	}

	for (i = 0; i < M.row; i++) 
		for (j = 0; j < M.col; j++)
			if (M.e[i][j] == 2)
				printf("(%d, %d)\n", i, j);
	
	system("PAUSE");

}

void InitMatrix(Matrix &M, char* filename)
{
	int i, j, e;
	i = 0;
	j = 0;

	FILE *fp;
	fp = fopen(filename, "r");

	e = fgetc(fp);
	while (!feof(fp)) {
		if (e == '\n') {
			i++;
			j = 0;
		}
		else if (e != ' ') {
			M.e[i][j] = e - 48;
			j++;
		}
		e = fgetc(fp);
	}//while
	M.row = ++i;
	M.col = j;

	fclose(fp);
}

void newMatrix(Matrix M, Matrix &A)
{
	A.row = M.row;
	A.col = M.col;
	for (int i = 0; i < M.row; i++)
		for (int j = 0; j < M.col; j++)
			A.e[i][j] = 0;
}