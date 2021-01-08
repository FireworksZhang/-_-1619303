#include "Search.h"
#include<fstream>
Search::Search()
{
	ifstream in;
	in.open("map.txt", ios::in);
	in >> length >> width;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			in >> map[i][j];
		}
	}
	for(int i = 0 ; i <= length ; i++)
	{
		for (int j = 0; j <= width; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << "请输入入口坐标：";
	cin >> x >> y;
	cout << "请输入出口坐标：";
	cin >> a >> b;
	road.push(nodesearch{ x,y });
	DFS(x, y);
	if (!pd)	cout << "未找到路径";
}

void Search::DFS(int x, int y)
{
	for (int i = 0; i < 4; i++)//判断4个方向哪个可以走
	{
		nx = x + dx[i];//搜索左右两个方向,判断是否可以走
		ny = y + dy[i];//搜索上下两个方向,判断是否可以走
		if (nx >= 0 && nx < width && ny >= 0 && ny < length && !map[nx][ny]) //nx和ny判断是否到达边界，fyg判断可不可以走([nx][ny]是不是#)
		{
			map[nx][ny] = true;//标志着已经走过
			nodesearch now;
			now.x = nx, now.y = ny;
			road.push(now);
			if (nx == a && ny == b)//如果到达了终点
			{
				cout << "YES" << endl;//输出YES
				while (road.size()>1)
				{
					cout << "(" << road.front().x << "," << road.front().y << ")->";
					road.pop();
				}
				cout << "(" << road.front().x << "," << road.front().y << ")";
				road.pop();
				pd = true;//判断是否到达了终点，并赋值为真,目的是main函数里输出"NO"时进行判断
				break;//跳出循环并进行下一组数据
			}
			else DFS(nx, ny);//如果没到终点，就从该点再次遍历
		}
	}
}
