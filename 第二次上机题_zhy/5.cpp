#include<iostream>
using namespace std;

int main() {
	int n = 0,MaxM = 0;
	cin >> n;
	int start=0, end=0;
	int * cross = new int[1000000];//cross[i]表示以i为开头的这一分钟是否在广场
	int total = 0;
	for (int i = 0; i < n; i++) {
		cin >> start >> end;
		for (int k = start; k < end; k++)
			cross[k] = 1;
        MaxM = max(MaxM, end);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> start >> end;
        for (int k = start; k < end; k++)
        {
            if (cross[k] == 1)
                total++;
        }
    }
	cout << total << endl;
    return 0;
}