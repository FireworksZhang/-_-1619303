#include<iostream>
#include<stack>
using namespace std;

int ans[101],ans1;
stack<int> _stack;//用STL定义栈
//...不写也没关系 如果只要一个答案，用递归就可以解决问题了。
//话说回来递归的原理也是栈
int n = 8,tot = 0,cnt = 0;
int f1[166],f2[166],f3[166];

void dfs(int k)
{
	if(k > n)	
	{
        // for (int i = 1; i <= n; i++)
        //     cout << ans[i] << " ";
        // cout << endl;
        //把这几行注释去掉可以输出所有的排列顺序，但只限于数组栈的那个方法
        tot++;
		return;
	}
	for(int i = 1 ; i <= n ; i++)
		if((!f1[i])&&(!f2[i+k])&&(!f3[i-k+100]))
		{
			f1[i] = f2[i+k] = f3[i - k + 100] = 1;
            //_stack.push(i);用STL写了一下
            ans[++cnt] = i;//数组操作顶端元素实现栈
            dfs(k+1);
			f1[i] = f2[i+k] = f3[i - k + 100] = 0;
            //_stack.pop();用STL写了一下
            cnt--; //数组操作顶端元素实现栈
        }
}

int main()
{
	dfs(1);
	cout << tot;
    return 0;
}
