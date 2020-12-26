#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

struct EDGE{
	int w,v,next;
}e[500010];

int head[100010],dis[100010],n,m,s,cnt;

struct node{
	int u,dis;
	bool operator <(const node&rhs)const{
		return dis>rhs.dis;
	} 
};

void addedge(int u,int v,int w){
	cnt++;
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}

void dijkstra(){
	priority_queue<node> Q;
	dis[s]=0;
	Q.push(node{s,0});
	while(!Q.empty()){
		node fnt=Q.top();
		Q.pop();
		int u=fnt.u,d=fnt.dis;
		if(d>dis[u]) continue;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				Q.push(node{v,dis[v]});
			}
		}
	}
}
int main(){
    cout << "输入格式:\n第一行为三个正整数 n, m, s。 第二行起 m 行，每行三个非负整数 ui, vi, wi ，表示从 ui 到 vi, 有一条权值为 wi 的有向边\n输出格式\n输出一行 n 个空格分隔的非负整数，表示 s 到每个点的距离。\n ";
    int i , j, k;
    cin>>n>>m>>s;
	for(i=1;i<=n;i++)
		dis[i]=2147483647;
	
	for(i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		addedge(a,b,c);
	}

	dijkstra();
	for(i=1;i<=n;i++){
		cout<<dis[i]<<" ";
	}	
	return 0;
} 