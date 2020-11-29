#include<bits/stdc++.h>
using namespace std;
int n, k, t, Xl, Yd, Xr, Yu;
int x, y; 
//判断在不在高危区域上 
bool check(int x, int y){
	if(x>=Xl && x<=Xr && y>=Yd && y<=Yu){
		return true;
	}
	return false;
}
int main(){
	int JingGuo = 0, DouLiu = 0; 
	cin>>n>>k>>t>>Xl>>Yd>>Xr>>Yu; 
	for(int i=0;i<n;i++){
		int time = 0;
		int cnt = 0;
		for(int j=0;j<t;j++){
			//第i个人在j时刻的位置 
			cin>>x>>y;
			if(check(x, y)){
				cnt ++;
				if(cnt > time){
					time = cnt;
				}
			}else{
				//如果中途离开了，需要重新计时 
				cnt = 0;
			}
		}
		if(time > 0){
			JingGuo ++;
		}
		if(time >= k){
			DouLiu ++;
		}
	} 
	cout<<JingGuo<<endl<<DouLiu;
	return 0;
}
