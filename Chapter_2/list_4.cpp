#include<iostream>
using namespace std;

int main(){
	int r,y,g;//红绿灯的设置
	int n , k[1007] ,t[1007] , ans = 0;
	cin >> r >> y >> g >> n;
	int cycle = r + y + g;//代表红黄绿一个循环
	for(int i = 1 ;i <= n ; i++){
		cin >> k[i] >> t[i];
		//数据处理
		if(k[i] == 1){
			t[i] = r - t[i];
		}
		else if(k[i] == 2){
			t[i] = r + y - t[i];
		}
		else if(k[i] == 3){
			t[i] = cycle - t[i];
		}
	}

	for(int i = 1 ; i <= n ; i++){
		//过路
		if(k[i] == 0){
			ans += t[i];//直接加在总时间
			for(int j = i + 1 ; j <= n ; j++){
				if(k[j] == 0)
					continue;
				t[j] = (t[j] + t[i]) % cycle;//遍历后面的数据，减去过路的时间
			}
		}
		//过灯
		else{
            //红灯或黄灯
			if(t[i] <= r + y){
                ans += ((r + y) - t[i]);//加上等灯的时间
                for(int j = i + 1 ; j <= n ; j++){
					if(k[j] == 0)
						continue;
				    t[j] = (t[j] + ((r + y) - t[i])) % cycle;//遍历后面的数据，减去过路的时间
                }
            }
            else
                continue;//直接过
        }
	}
	cout << ans;
	
	return 0;
}