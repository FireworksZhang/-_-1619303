#pragma once
#include<vector>
#include<queue>
#include<iostream>
using namespace std;

struct nodesearch {
	int x, y;
};
class Search
{
private:
	long long length, width;
	int map[100][100];
	int dx[4] = { 1, -1, 0, 0 }; //����������������
	int dy[4] = { 0,0,1,-1 };//����������������
	int t, n, x, y, a, b, nx, ny, m;
	char str;//x,y�����ĺ�������,a,b���յ�ĺ�������,str�ǹ����Թ����ַ�
	bool pd, flag[100][100];//�����н���
	queue<nodesearch> road;
public:
	Search();
	void DFS(int x, int y);
};