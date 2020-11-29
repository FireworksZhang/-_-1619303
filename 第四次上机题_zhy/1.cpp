/*
稀疏矩阵的实现
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
//存储域
const int MAX_N = 100;
class elem_node
{
public:
	int elem_row;//元素行号
	int elem_col;//元素列号
	int elem_value;//元素值
};
 
class Node
{
public:
	int total_row;//总行数
	int total_col;//总列数
	int total_num;//非0元素总数
	elem_node data[MAX_N];//非0元素数组
};
 
class Matrix
{
public:
	Matrix(){}
	~Matrix(){}
	//构建稀疏矩阵三元组
	void CreateMat(string filename, int rows, int cols)
	{
		int i, j;
		int fdata;
		ifstream readFile;
		mat.total_num = 0;
		mat.total_col = cols;//总行数
		mat.total_row = rows;//总列数
		readFile.open(filename,ios::in);
		//打开错误
		if (readFile.bad() || readFile.fail())
		{
			exit(0);
		}
		//文件正常打开
		if (readFile.is_open())
		{
			for (i = 1; i <= rows; i++)
			{
				for (j = 1; j <= cols; j++)
				{
					readFile >> fdata;
					if (readFile.good() && fdata )
					{
						mat.data[mat.total_num].elem_row = i;//元素行号
						mat.data[mat.total_num].elem_col = j;//元素列号
						mat.data[mat.total_num].elem_value = fdata;//元素值
						mat.total_num++;//存储数组下标+1
					}
				}
			}
		}
		readFile.close();
	}
	//输出三元组
	void DispMat()
	{
		if (mat.total_num <= 0)
		{
			return;
		}
		else
		{
			int i;
			for (i = 0; i < mat.total_num; i++)
			{
				cout << "<" << mat.data[i].elem_row << "," << mat.data[i].elem_col << "," << mat.data[i].elem_value << ">" << endl;
			}
		}
	}
	//输出三元组
	void DispMat(Node mat)
	{
		if (mat.total_num <= 0)
		{
			return;
		}
		else
		{
			int i;
			for (i = 0; i < mat.total_num; i++)
			{
				cout << "<" << mat.data[i].elem_row << "," << mat.data[i].elem_col << "," << mat.data[i].elem_value << ">" << endl;
			}
		}
	}
	//转置矩阵
	Node TranMat()
	{
		Node tranMat;
		tranMat.total_col = 0;
		tranMat.total_row = 0;
		tranMat.total_num = 0;
		if (mat.total_num <= 0)
		{
			return tranMat;
		}
		else
		{
			int p = 0, i, c;
			tranMat.total_col = mat.total_col;
			tranMat.total_row = mat.total_row;
			tranMat.total_num = mat.total_num;
			for (i = 1; i <= mat.total_row; i++)//遍历所有行
			{
				for (c = 0; c < mat.total_num; c++)//对于行，遍历所有三元组元素
				{
					if (i == mat.data[c].elem_row)//若三元组中存在行号与i相等的组，则转置
					{
						tranMat.data[p].elem_row = mat.data[c].elem_col;
						tranMat.data[p].elem_col = mat.data[c].elem_row;
						tranMat.data[p].elem_value = mat.data[c].elem_value;
						p++;
					}
				}
			}
			
			return tranMat;
		}
	}
	Node FastTranMat()
	{
		Node FastTranMat;
		FastTranMat.total_col = 0;
		FastTranMat.total_row = 0;
		FastTranMat.total_num = mat.total_num;

		if(mat.total_num <= 0)
		{
			return FastTranMat;
		}
		else
		{
			int k, p, q, rowNum[1000], rowStart[1000];

			for (k = 0; k <= mat.total_col; k++)
				rowNum[k] = 0;
			for (k = 0; k < mat.total_num; k++)
				rowNum[mat.data[k].elem_col]++;

			rowStart[0] = 0;
			for (k = 1; k <= mat.total_col; k++)
				rowStart[k] = rowStart[k - 1] + rowNum[k - 1];

			for (p = 0; p < mat.total_num; p++) {
				q = rowStart[mat.data[p].elem_col];
				FastTranMat.data[q].elem_row = mat.data[p].elem_col;
				FastTranMat.data[q].elem_col = mat.data[p].elem_row;
				FastTranMat.data[q].elem_value = mat.data[p].elem_value;
				rowStart[mat.data[p].elem_col]++;
			}
			return FastTranMat;
		}
	}
	


private:
	Node mat;
};
 
//三元组操作
class operation
{
public:
	operation()
	{
		m_mat.CreateMat("data",7,6);
	}
	~operation(){}
	//输出
	void display()
	{
		cout << "Output" << endl;
		m_mat.DispMat();
	}
	//矩阵转置
	void trange()
	{
		cout << "Change" << endl;
		m_mat.DispMat(m_mat.TranMat());
	}
	//矩阵快速转置
	void fasttrange()
	{
		cout << "Fasttrange" << endl;
		m_mat.DispMat(m_mat.FastTranMat());
	}
private:
	Matrix m_mat;
};
int main()
{
	operation m_opr;
	m_opr.display();//输出

	m_opr.trange();//转置

	m_opr.fasttrange();
	return 0;
}