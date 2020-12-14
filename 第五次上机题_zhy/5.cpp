#include<iostream>
using namespace std;
int main(){
    int i=1;
    int k[4]={0};
    int t=0;//记录报数个数总数
    int n;
    cin>>n;
    for(t=0;t<n;){
        if(i%7==0||i%10==7||i%100/10==7||i%1000/100==7||i/1000==7) k[i%4]++;
        else t++;
        i++;
    }
    cout<<k[1]<<endl;
    cout<<k[2]<<endl;
    cout<<k[3]<<endl;
    cout<<k[0]<<endl;
    return 0;
}