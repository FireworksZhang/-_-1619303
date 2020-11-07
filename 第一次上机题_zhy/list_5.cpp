#include<iostream>
using namespace std;

int main(){
	int a,cnt,ans;
	cin >> a;//第一个数据特判
	ans = a;
	cnt = ans;
	while(ans)//第一步为0直接结束，程序出口放在循环中
	{
		cin >> a;
		if(a == 0)
			break;//结束
		else if(a == 1)//结果+1
		{
			cnt = 0;
			ans += 1;
		}
		else if(a == 2)
		{
			if( cnt >= 2)
			{
				cnt += 2;
				ans += cnt;
			}//上一次也是2，这次比上一次多加一个2
			else
			{
				cnt = 2;
				ans += 2;
			}//上一次不是2，这次只加2
		}
	}
	cout << ans;
	return 0;
}