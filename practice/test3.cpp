#include<iostream>
#include<cstdio>

#include<vector>
//#include<map>
//#include<queue>
//#include<string>

using namespace std;

struct E{
	int w;//½ð±Ò
	int v;//¼ÛÖµ 
}list[101];


int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int cnt=0;
	while(scanf("%d%d",&list[cnt+1].w, &list[cnt+1].v)!=EOF){
		cnt++;
	}
	vector<vector<int> > dp(n+1, vector<int>(m+1,0));
	
	for(int i=1;i<=cnt;i++){
		for(int j=n;j>=list[i].w;j--){
			for(int k=m;k>0;k--){
				dp[j][k]=max(dp[j][k],dp[j-list[i].w][k-1]+list[i].v); 
			}
		}
	}
	printf("%d\n",dp[n][m]);
	return 0;
}
