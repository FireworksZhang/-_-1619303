#include <iostream>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int answer = 0,weight = 0;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        weight += x;
        if(weight >= k){
            answer++;
            weight = 0;
        }
    }
    if(weight != 0){
        answer++;
    }
    cout << answer;
    return 0;
}