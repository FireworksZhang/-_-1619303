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
	cout << "������������꣺";
	cin >> x >> y;
	cout << "������������꣺";
	cin >> a >> b;
	road.push(nodesearch{ x,y });
	DFS(x, y);
	if (!pd)	cout << "δ�ҵ�·��";
}

void Search::DFS(int x, int y)
{
	for (int i = 0; i < 4; i++)//�ж�4�������ĸ�������
	{
		nx = x + dx[i];//����������������,�ж��Ƿ������
		ny = y + dy[i];//����������������,�ж��Ƿ������
		if (nx >= 0 && nx < width && ny >= 0 && ny < length && !map[nx][ny]) //nx��ny�ж��Ƿ񵽴�߽磬fyg�жϿɲ�������([nx][ny]�ǲ���#)
		{
			map[nx][ny] = true;//��־���Ѿ��߹�
			nodesearch now;
			now.x = nx, now.y = ny;
			road.push(now);
			if (nx == a && ny == b)//����������յ�
			{
				cout << "YES" << endl;//���YES
				while (road.size()>1)
				{
					cout << "(" << road.front().x << "," << road.front().y << ")->";
					road.pop();
				}
				cout << "(" << road.front().x << "," << road.front().y << ")";
				road.pop();
				pd = true;//�ж��Ƿ񵽴����յ㣬����ֵΪ��,Ŀ����main���������"NO"ʱ�����ж�
				break;//����ѭ����������һ������
			}
			else DFS(nx, ny);//���û���յ㣬�ʹӸõ��ٴα���
		}
	}
}
