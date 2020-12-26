#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int chess[4][4];   //存放棋局的全局矩阵 

//行满足 
bool RowWin(int role)
{
	for(int i=0;i<3;i++)
	{
		if(chess[i][0]==role&&chess[i][0]==chess[i][1]&&chess[i][1]==chess[i][2])
			return true;
	}
	return false;
}

//列满足 
bool ColWin(int role)
{
	for(int j=0;j<3;j++)
	{
		if(chess[0][j]==role&&chess[0][j]==chess[1][j]&&chess[1][j]==chess[2][j])
			return true;
	}
	return false;
}

//对角满足 
bool OppWin(int role)
{
	if(chess[0][0]==role&&chess[0][0]==chess[1][1]&&chess[1][1]==chess[2][2])
		return true;
	if(chess[0][2]==role&&chess[0][2]==chess[1][1]&&chess[1][1]==chess[2][0])
		return true;
	return false;
}

//判断当前棋局的空格子数 
int CountEmpty()
{
	int count=0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(chess[i][j]==0) count++;
		}
	}
	return count;
}

//判断哪一方是否获胜的函数 
int JudgeWin(int role)   
{
	int score=0;
	if(RowWin(role)) score=CountEmpty()+1;
	if(ColWin(role)) score=CountEmpty()+1;
	if(OppWin(role)) score=CountEmpty()+1;
	if(score){
		return (role-1)?-score:score;   //0-Alice,1-Bob
	}
	else return score;
}

//根据行棋方进行搜索 
int dfs(int role)
{
	if(!CountEmpty()) return 0;
	int Max=-10,Min=10;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(chess[i][j]==0)
			{
				chess[i][j]=role+1;
				int w=JudgeWin(role+1);
				if(w)
				{
					chess[i][j]=0;
					return w>0?max(Max,w):min(Min,w);  //关键：当前若是Alice,则返回最大;若是Bob,则返回最小值 
				}
				if(!role) Max=max(Max,dfs(1));  //Alice选择最大值(极大) 
				else Min=min(Min,dfs(0));   //Bob选择最小值(极小)
				chess[i][j]=0;
			}
		}
	} 
	return role?Min:Max;
}

int main()
{
	//freopen("input/chess.txt","r",stdin);
	int T;   //数据的组数
	cin>>T;
	while(T--)
	{
		int val=0;  //存放当前棋局得分 
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				cin>>chess[i][j];     //输入棋局 
			}
		}
		val=JudgeWin(1);   //判断初始棋局Alice是否获胜 
		if(val){
			cout<<val<<endl;
			continue;
		}
		val=JudgeWin(2);   //判断初始棋局Bob是否获胜
		if(val){
			cout<<val<<endl;
			continue;
		} 
		val=dfs(0);   //Alice行棋 
		cout<<val<<endl; 
	}
	
	return 0;
} 