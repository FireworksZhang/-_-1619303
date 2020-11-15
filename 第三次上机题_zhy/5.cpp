#include<iostream>
#include<algorithm>
using namespace std;

//使用algorithm库中的sort函数进行排序，然后遍历一遍数组求出相邻两个数的差，再用一个min_变量存储差的最小值就解决了。
int main()
{
    int n,a[1007],ans[1007];
    int min_ = 2147483647;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i]; 
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i < n;i++)
    {
        ans[i] = a[i + 1] - a[i];
        min_ = min(min_, ans[i]);
    }
    cout << min_;

    return 0;
}