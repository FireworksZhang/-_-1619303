#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+5;
struct edge{     //边集 
	int v,u;
	int cost;
}E[maxn];
int father[maxn];  
int n,m;

bool cmp(edge a,edge b){
	return a.cost<b.cost;
}

int findFather(int x){    
	int a=x;
	while(x!=father[x]){
		x=father[x];
	}
	while(a!=father[a]){
		int z=a;
		father[z]=x;
		a=father[a];
	}
	return x;
}

int kruskal(int n,int m){
	int ans=0;    //费用 
	int E_num=0;
	for(int i=0;i<m;i++){
		int fav=findFather(E[i].v);
		int fau=findFather(E[i].u);
		if(fav!=fau){    //如果两点不在同一集合 
			father[fau]=fav;   //合并 
			ans+=E[i].cost;    //加入边 
			E_num++;           //边数加一 
			if(E_num==n-1) break;   //已找到所有边 
		}
	}
	if(E_num==n-1) return ans;
	else return -1;  //图不连通 
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&E[i].v,&E[i].u,&E[i].cost);
	}
	sort(E,E+m,cmp);     //边按费用从小到大排序 
	for(int i=1;i<=n;i++){
		father[i]=i;     //初始化 
	}
	int res=kruskal(n,m);
	if(res!=-1) printf("%d",res);
	return 0;
}