#include<iostream>
#include<stdio.h>
#include<vector> 
using namespace std;

#include<string>

int knapsack01_6(const vector<int>& w, int C){
	int n=w.size();
	if(n==0){
		return 0;
	}
	vector<int> memo(C+1,0);
	memo[0] = 1;

	for(int i=0; i < n; ++i){
		for(int j = w[i]; j <= C; ++j){	//完全背包,从前往后循环
			memo[j] += memo[j - w[i]];
		}
	}

	return memo[C];
}

int main(){
	int N, C;
	int memo[1000];
	int w;
	while(scanf("%d%d", &N, &C) != EOF){
		for(int i = 1; i <= C; ++i){
			memo[i] = 0;
		}
		memo[0] = 1;

		for(int i = 0; i < N; ++i){
			scanf("%d", &w);
			for(int j = w; j <= C; ++j){
				memo[j] += memo[j - w];
			}
		}

		printf("%d\n", memo[C]);
	}
	
	return  0;
} 
