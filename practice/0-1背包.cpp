//0-1±³°ü,Ê±¼ä¸´ÔÓ¶ÈO(n*s) 

//时间复杂度n*C,空间C
//若有输入w和v两个数组,可以用两个变量代替
int knapsack01_1(const vector<int>& w, const vector<int>& v, int C){
	int n=w.size();
	if(n==0){
		return 0;
	}
	vector<int> memo(C+1,0);

	for(int i=0;i<n;++i){
		for(int j=C;j>=w[i];--j){	//这里需要从右至左更新,因为更新需要用到(i-1)左边数据, 
			memo[j]=max(memo[j],v[i]+memo[j-w[i]]);
		}
	}
	return memo[C];
}

//变种2, 改变dp对象,当n和C过大总价值较小时,dp[i][j]表示前i个物品价值为j的最小重量
int knapsack01_2(const vector<int>& w, const vector<int>& v, int C){
	int n=w.size();
	if(n==0){
		return 0;
	}

	int sum = 0;
	for(int i = 0; i < n; ++i){
		sum += v[i];
	}

	vector<int> memo(sum+1, MAX_INT);
	
	for(int i=0; i<n; ++i){
		for(int j = sum; j >= v[i]; --j){
			memo[j] = min(memo[j], w[i]+memo[j-v[i]]);
		}
	}

	for(int j = sum; j >= 0; --j){
		if(dp[j] <= C){
			return j;
		}
	}
	return 0;
}


//变种3, 完全背包,每个物品都有无限件可用
int knapsack01_3(const vector<int>& w, const vector<int>& v, int C){
	int n=w.size();
	if(n==0){
		return 0;
	}
	vector<int> memo(C+1,0);

	for(int i=0; i<n; ++i){
		for(int j = w[i]; j <= C; ++j){	//完全背包,从前往后循环
			memo[j] = max(memo[j], v[i]+memo[j-w[i]]);
		}
	}
	return memo[C];
}

//变种4, 01背包, 刚好装满
int knapsack01_4(const vector<int>& w, const vector<int>& v, int C){
	int n=w.size();
	if(n==0){
		return 0;
	}
	vector<int> memo(C+1, -1);
	memo[0] = 0;

	for(int i=0;i<n;++i){
		for(int j=C; j >=w [i]; --j){	//这里需要从右至左更新,因为更新需要用到(i-1)左边数据
			if(memo[j - w[i]] != -1){
				memo[j] = max(memo[j], v[i]+memo[j-w[i]]);
			}
		}
	}
	return memo[C];
}

//变种5, 完全背包+刚好装满,最大价值
int knapsack01_5(const vector<int>& w, const vector<int>& v, int C){
	int n=w.size();
	if(n==0){
		return 0;
	}
	vector<int> memo(C+1, -1);
	memo[0] = 0;

	for(int i=0; i<n; ++i){
		for(int j = w[i]; j <= C; ++j){	//完全背包,从前往后循环
			if(memo[j-w[i]] != -1){
				memo[j] = max(memo[j], v[i]+memo[j-w[i]]);
			}
		}
	}

	return memo[C];
}

//变种6, 完全背包+刚好装满,方案数量
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

//变种7, 01背包+刚好装满, 方案数量,需要手动输入w时可以用变量代替数组
int knapsack01_7(const vector<int>& w, int C){
	int n=w.size();
	if(n==0){
		return 0;
	}
	vector<int> memo(C+1,0);
	memo[0] = 1;

	for(int i=0; i < n; ++i){
		for(int j = C; j >= w[i]; ++j){	//01背包,从后往前循环
			memo[j] += memo[j - w[i]];
		}
	}

	return memo[C];
}