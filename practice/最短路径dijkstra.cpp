//Dijkstra,某特定结点到其它所有结点的最短路径,单源最短路径
//点集分为两部分属于K和不属于K,K中最短路径已经确定,然后找从K到非K的最短路径 
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

struct E{
	int next;
	int c;
};

vector<E> edge[101];//领接表
bool mark[101];//标记,当mark[j]为true时,表示j的最短路径已经得到,属于集合K
int Dis[101];//当mark[i]为true时,其对应最短距离

int V;
typedef pair<int, int> P;//first是最短距离,second是顶点编号
void dijkstra(int s){
	priority_queue<P, vector<P>, greater<P> > que;
	fill(Dis, Dis+V; INF);
	Dis[s]=0;
}

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0&&m==0)
			break;
		for(int i=1;i<=n;i++){
			edge[i].clear();	//初始化邻接表 
		}
		while(m--){
			int a,b,c;
			scnaf("%d%d%d",&a,&b,&c);
			E tmp;
			tmp.c=c;
			tmp.next=b;
			edge[a].push_back(tmp);
			tmp.next=a;
			edge[b].push_back(tmp);	//无向图 
		}
		
		for(int i=1;i<=n;i++){//初始化 
			Dis[i]=-1;
			mark[i]=false;
		}
		Dis[1]=0;
		mark[1]=true;
		
		int newP=1;	//集合K中新加入节点1
		for(int i=1;i<n;i++){//循环n-1次,确定其他n-1个点的最短路径 
			for(int j=0;j<edge[newP].size();j++){
				int t=edge[newP][j].next();
				int c=edge[newP][j].c;
				if(mark[t]==true)	continue;
				if(Dis[t]==-1||Dis[t]>Dis[newP]+c){
					Dis[t]=Dis[newP]+c;
				}
			}
			int min=123123123;
			for(int j=1;j<=n;j++){
				if(mark[j]==true)
					continue;
				if(Dis[j]==-1)
					continue;
				if(Dis[j]<min){
					min=Dis[j];
					newP=j;
				}
			}
			mark[newP]=true;
		}
		printf("%d\n".Dis[n]);
	}
	return 0;
} 
