/*kruskal算法
初始所有点属于孤立集合
按边权值增序排序,遍历,若边两点不属于相同集合,则该边为最小生成树中的边
直到所有点都在一个集合中*/
/*
Prim算法,是找到最小代价的点去加入到集合中,然后扩展点集,
只有两个点集(一个是已扩展点集S,一个是未扩展点集V)
每次从V中选去有最小代价的连接到S的点u,把u加入到S 
*/ 
#include<stdio.h>
#include<algorithm>
using namespace std;
#define N 101
int Tree[N];
int findRoot(int x){
	if(Tree[x]==-1)
		return x;
	else{
		int tmp=findRoot(Tree[x]);
		Tree[x]=tmp;
		return tmp;
	}
}

struct Edge{
	int a,b;
	int cost;
	bool operator < (const Edge &A) const{
		return cost<A.cost;
	}
}edge[6000];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF && n!=0){
		for(int i=1;i<=n*(n-1)/2;i++){
			scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].cost);
		}
		sort(edge+1,edge+1+n*(n-1)/2);
		
		for(int i=1;i<=n;i++){
			Tree[i]=-1;//初始都是孤立的节点 
		}
		int ans=0;
		for(int i=1;i<=n*(n-1)/2;i++){
			int a=findRoot(edge[i].a);
			int b=findRoot(edge[i].b);
			if(a!=b){
				Tree[a]=b;
				ans+=edge[i].cost;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
