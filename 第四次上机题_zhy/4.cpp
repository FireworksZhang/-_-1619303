#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int p;
	int remain[25];                           //每行剩余的座位的数组 

	for(int i = 1; i <= 20; i++)              //memset是按字节赋值的，只能赋值0，true，false，INF，一个int变量是4个字节，故不可以 
	{										  //以后最好还是用循环进行数组赋值 
		remain[i] = 5;
	}
	while(n--)
	{
		cin >> p;
		for(int i = 1; i <= 20; i++)
		{
			if(remain[i] >= p)
			{
				for(int j = 1; j <= p; j++)
				{
					cout << (i-1)*5 + 5-remain[i]+j << ' ';	
				}
				remain[i] -= p;
				p = 0;
				break; 	
			}	
		}
		for(int i = 1; i <= 20 && p; i++)
		{
			if(remain[i] != 0)
			{
				if(p > remain[i])
				{
					for(int j = 1; j <= remain[i]; j++)
					{
						cout << (i-1)*5 + 5-remain[i]+j << ' ';
					}
					p -= remain[i];
					remain[i] = 0;	
				}
				else
				{
					for(int j = 1; j <= p; j++)
					{
						cout << (i-1)*5 + 5-remain[i]+j << ' ';
					}
					remain[i] -= p; 
					p = 0;
				}
			}
		}
		putchar('\n');
	}
	return 0;	
} 
