//Dijkstra,ĳ�ض���㵽�������н������·��,��Դ���·��
//�㼯��Ϊ����������K�Ͳ�����K,K�����·���Ѿ�ȷ��,Ȼ���Ҵ�K����K�����·�� 
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

struct E{
	int next;
	int c;
};

vector<E> edge[101];//��ӱ�
bool mark[101];//���,��mark[j]Ϊtrueʱ,��ʾj�����·���Ѿ��õ�,���ڼ���K
int Dis[101];//��mark[i]Ϊtrueʱ,���Ӧ��̾���

int V;
typedef pair<int, int> P;//first����̾���,second�Ƕ�����
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
			edge[i].clear();	//��ʼ���ڽӱ� 
		}
		while(m--){
			int a,b,c;
			scnaf("%d%d%d",&a,&b,&c);
			E tmp;
			tmp.c=c;
			tmp.next=b;
			edge[a].push_back(tmp);
			tmp.next=a;
			edge[b].push_back(tmp);	//����ͼ 
		}
		
		for(int i=1;i<=n;i++){//��ʼ�� 
			Dis[i]=-1;
			mark[i]=false;
		}
		Dis[1]=0;
		mark[1]=true;
		
		int newP=1;	//����K���¼���ڵ�1
		for(int i=1;i<n;i++){//ѭ��n-1��,ȷ������n-1��������·�� 
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
