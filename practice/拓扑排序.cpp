//��������,�ж������޻�ͼ
//�ö��л�ջ�������Ϊ0�Ľ��
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<int> edge[501];//�ڽӱ�
queue<int> Q;

int main(){
	int inDegree[501];
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0&&m==0){
			break;
		}
		for(int i = 0; i < n; i++){
			inDegree[i]=0;
			edge[i].clear();
		}
		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			inDegree[b]++;
			edge[a].push_back(b);
		}
		while(Q.empty()==false){
			Q.pop();//��ն��� 
		}
		for(int i=0;i<n;i++){
			if(inDegree[i]==0)
				Q.push(i);
		}
		int cnt=0;//�����ۼ��Ѿ�ȷ����������Ľ�����
		while(Q.empty()==false){
			int nowP=Q.front();
			Q.pop();
			cnt++;
			for(int i=0;i<edge[nowP].size();i++){
				inDegree[edge[nowP][i]]--;
				if(inDegree[edge[nowP][i]]==0){
					Q.push(edge[nowP][i]);
				}
			}
		}
		if(cnt==n)
			printf("YES\n");
		else
			printf("NO\n"); 
	}
	return 0;
} 
