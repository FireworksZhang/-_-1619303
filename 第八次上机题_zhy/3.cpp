#include<iostream>
using namespace std;

int a[100500],n;

void quicksort(int l,int r)
{
	int	mid = a[(l + r) / 2];
	int i = l,j = r;
	do
	{

		while(a[j] > mid)	j--;
		while(a[i] < mid)	i++;
				
		if(i <= j)
		{
			swap(a[i],a[j]);
			i++;
			j--;
		} 
	}while(i <= j);
	if(l < j)	quicksort(l,j);
	if(i < r)	quicksort(i,r);
}

int main()
{
    cout << "请输入数据规模：";
    cin >> n;
    cout << "请输入数据内容：";
    for(int i = 1 ; i <= n ; i++)
		cin >> a[i];
	quicksort(1,n);
    cout << "排序后的数据：";
    for(int i = 1 ; i <= n ; i++)
		cout << a[i] << " " ;
	return 0;
}