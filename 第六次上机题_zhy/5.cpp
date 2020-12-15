#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int Bmap[15][10];
int Smap[4][4];
struct Node {
	int x;
	int y;
}num[4];

int main()
{
	for(int i=0; i<15; i++)
		for(int j=0; j<10; j++)
			cin >> Bmap[i][j];
	int index = 0;
	int maxi = 0;
	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
		{
			cin >> Smap[i][j];
			if(Smap[i][j])
			{
				num[index].x = i;
				num[index].y = j;
				if(i > num[maxi].x)
					maxi = index;
				index++;
			}
		}
	int start;
	cin >> start;
	//纠正在大方格图的纵坐标位置 
	for(int i=0; i<4; i++)
		num[i].y += (start-1);	
	//往下移动 (注意不要越界)
	while(1)
	{
		if(!Bmap[num[0].x][num[0].y]&&!Bmap[num[1].x][num[1].y]&&!Bmap[num[2].x][num[2].y]&&!Bmap[num[3].x][num[3].y]&&num[maxi].x<15)
			for(int i=0; i<4; i++)
				num[i].x++;
		else
		{
			for(int i=0; i<4; i++)
				Bmap[num[i].x-1][num[i].y] = 1;
			break;
		}
	}
	for(int i=0; i<15; i++)
	{
		for(int j=0; j<10; j++)
			cout << Bmap[i][j] << " ";
		cout << endl;	
	}
	return 0;
}
