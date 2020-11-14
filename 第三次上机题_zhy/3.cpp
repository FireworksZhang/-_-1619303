
#include<iostream>
using namespace std;

int ans[101],ans1;
int n = 8,tot = 0,cnt = 0;
int f1[166],f2[166],f3[166];

void dfs(int k)
{
	if(k > n)	
	{
		if(tot<3)
		{
			for(int i = 1 ; i <= n ; i++)
				cout << ans[i] << " ";
			cout << endl;
		}
		tot++;
		return;	
	}
	for(int i = 1 ; i <= n ; i++)
		if((!f1[i])&&(!f2[i+k])&&(!f3[i-k+100]))
		{
			f1[i] = f2[i+k] = f3[i - k + 100] = 1;
			ans[++cnt] = i;
			dfs(k+1);
			f1[i] = f2[i+k] = f3[i - k + 100] = 0;
			cnt--; 
		}
}


int main()
{
	dfs(1);
	cout << tot;		
}
