#include<iostream>
using namespace std;
int a[1000][1000],i,j,maxn[1000],minn[1000],c=0,row,col;
int main()
{
    cout << "输入矩阵的行数列数:" << endl;
    cin >> row >> col;
    cout << "请输入矩阵" << endl;
    for(i=1;i<=row;i++)
        for(j=1;j<=col;j++)
            cin>>a[i][j];
    for(i=1;i<=row;i++)
    {
        maxn[i]=a[i][1];
        for(j=1;j<=col;j++)
        {
            if(a[i][j]>maxn[i])
            maxn[i]=a[i][j];
        }
    }
    for(j=1;j<=col;j++)
    {
        minn[j]=a[1][j];
        for(i=1;i<=row;i++)
        {
            if(a[i][j]<minn[j])
            minn[j]=a[i][j];
        }
    }
    for(i=1;i<=row;i++)
        for(j=1;j<=col;j++)
        {
            if(a[i][j]==maxn[i]&&a[i][j]==minn[j])
                cout<< "鞍点的横坐标是："<<i<<"，纵坐标是："<<j<<"，该点的值是："<<a[i][j];
            else
                c++;
        }
    if(c==row*col)
        cout<<"not found";
    return 0;
}