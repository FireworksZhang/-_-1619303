#include<iostream>
using namespace std;

int main()
{
    int n,m,ans[1007],opera[1007];//ans[i]表示第i棵树最终剩多少个果子，opera[j]存储第i次的第j个操作。
    long long T = 0, D = 0, E = 0;
    bool IfFall[1007] = {0};//IfFall[i]用来记忆第i棵树是否掉过果子，1代表掉过，0代表没掉过
    cin >> n;
    for (int i = 1; i <= n; i++)    ans[i] = 0;//初始化ans数组，可以不进行
    for (int i = 1; i <= n; i++)
    {
        cin >> m;
        for (int j = 1; j <= m; j++)
        {
            cin >> opera[j];
        }//先进行数据存储
        for (int j = 1; j <= m; j++)
        {
            if (opera[j] > 0)//如果当前的操作存储的数据大于0，说明要进行比较。
            {
                if (ans[i] > opera[j])//如果当次统计比之前的记录小，说明有掉果子，更新IsFall数组
                {
                    IfFall[i] = 1;
                }
                ans[i] = opera[j];
            }
            else if (opera[j] <= 0)//如果当前操作存储的数据小于0，直接减就好了
            {
                ans[i] += opera[j];
            }
        }
    }
    //此时ans数组存的是全部的果树目前的果子数目
    //计算T只需要全部加上就好了
    //计算D只需要判断一下当次的IfFall数组是否为1
    //计算E需要额外判断后面2棵树是否掉过果子
    for (int i = 1; i <= n; i++)
    {
        T += ans[i];
        if(IfFall[i])  
        {
            D++;
            if(i <= n - 2)
            {
                if(IfFall[i+1] && IfFall[i+2])
                {
                    E++;
                }
            }
            else if(i == (n-1))
            {
                if(IfFall[n] && IfFall[1])
                {
                    E++;
                }
            }
            else
            {
                if(IfFall[1] && IfFall[2])
                {
                    E++;
                }
            }
        }
    }
    cout << T << " " << D << " " << E;
    return 0;
}