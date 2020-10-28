#include<iostream>
using namespace std;

int main(){
	int a,pre_a,plus = 2,ans = 0,cnt = 1;
	cin >> a;
	while(a){
        if(a == 1){
			ans += 1;
            plus = 2;
        }
		else if(a == 2){
			if(pre_a == 1){
				ans += plus;
			}
			else{
                plus += 2;
				ans += plus;
			}
		}
        cnt++;
        pre_a = a;
		cin >> a;
	}
	cout << ans;
	return 0;
}