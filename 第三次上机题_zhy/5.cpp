#include<iostream>
#include<algorithm>
using namespace std;

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