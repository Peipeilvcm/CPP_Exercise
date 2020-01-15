#include<stdio.h>


//完全背包,刚好装满,最大价值
int main(){
	int T = 0;
	scanf("%d",&T);

	int N, C;

	int v,w;
	int dp[50005];

	while(T--){
		scanf("%d%d", &N, &C);
		for(int i = 1; i <= C; ++i){
			dp[i] = -1;
		}
		dp[0] = 0;

		for(int i = 0; i < N; ++i){
			scanf("%d%d",&w, &v);
			for(int j = w; j <= C; ++j){
				if(dp[j - w] != -1){
					dp[j] = max(dp[j], dp[j - w] + v);
				}
			}
		}

		if(dp[C] != -1){
			printf("%d\n",dp[C]);
		}else{
			printf("NO\n");
		}
	}
	
	return 0;
} 
