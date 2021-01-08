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
	int dx[4] = { 1, -1, 0, 0 }; //定义左右两个方向
	int dy[4] = { 0,0,1,-1 };//定义上下两个方向
	int t, n, x, y, a, b, nx, ny, m;
	char str;//x,y是起点的横纵坐标,a,b是终点的横纵坐标,str是构成迷宫的字符
	bool pd, flag[100][100];//后文有介绍
	queue<nodesearch> road;
public:
	Search();
	void DFS(int x, int y);
};