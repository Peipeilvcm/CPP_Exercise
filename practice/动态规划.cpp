#include<bits/stdc++.h>

using namespace std;

/*
记忆化搜索,自上而下
动态规划,自下而上 
*/
int integerBreak(int n) {
	if(n==1||n==2){
		return 1;
	}
	vector<int> v(n+1,-1);
	
	v[1]=1;
	v[2]=1;
	for(int i=3;i<=n;++i){
		int m=-1;
		for(int j=1;j<i;++j){
			int res = max(j*v[i-j],j*(i-j));
			if(m < res){
				m=res;
			}
		}
		v[i]=m;
	}
	
	return v[n];
}

//ld198. 自顶向下记忆化搜索,考虑抢劫index...nums.size()范围所有房子 
vector<int> memo;
int tryRob(vector<int>& nums, int index){
	if(index >= nums.size()){
		return 0;
	}
	
	if(memo[index]!=-1){
		return memo[index];
	}
	
	int res=max(tryRob(nums,index+1), nums[index]+tryRob(nums,index+2));
	memo[index]=res;
	return res;
}
int rob(vector<int>& nums){
	memo=vector<int>(nums.size(),-1);
	return tryRob(nums,0);
}
//动态规划,自底向上
int rob(vector<int>& nums, int index){
	int n=nums.size();
	if(n<=0){
		return 0;
	}
	//memo[i]表示考虑[i...n-1]所能获得最大收益 
	vector<int> memo(n,-1);
	memo[n-1]=nums[n-1];
	if(n==1){
		return nums[0];
	}
	memo[n-2]=max(nums[n-1],nums[n-2]);
	for(int i=n-3;i>=0;--i){
			memo[i]=max(memo[i+1],nums[i]+memo[i+2]);
	}
	return memo[0];
}

//0-1背包
//记忆化搜索,用0...index的物品,填充容积为c的最大价值 
vector<vector<int> > memo;
int bestValue(const vector<int>& w, const vector<int>& v, int index, int c){
	if(index < 0|| c<=0){
		return 0;
	}
	
	if(memo[index][c]!=-1){
		return memo[index][c];
	}
	
	int res=bestValue(w,v,index-1,c);
	if(c >= w[index]){
		res=max(res,v[index]+bestValue(w,v,index-1,c-w[index]));
	}
	memo[index][c]=res;
	return res;
}
int knapsack01(const vector<int>& w, const vector<int>& v, int C){
	int n=w.size();
	memo=vector<vector<int> >(n, vector<int>(C+1,-1));
	return bestValue(w,v,n-1,C);
}
//动态规划,时间O(n*C),空间(n*C)
int knapsack01(const vector<int>& w, const vector<int>& v, int C){
	int n=w.size();
	if(n==0){
		return 0;
	}
	vector<vector<int> > memo(n,vector<int>(C+1,0));
	for(int j=1;j<=C;++j){
		if(j>=w[0]){
			memo[0][j]=v[0];
		}
	}
	for(int i=1;i<n;++i){
		for(int j=1;j<=C;++j){
			if(j>=w[i]){
				int res=max(memo[i-1][j],v[i]+memo[i-1][j-w[i]]);
				memo[i][j]=res;
			}else{
				memo[i][j]=memo[i-1][j];
			}
			
		}
	}
	return memo[n-1][C];
}
//上面空间可优化,第i行只依赖于第i-1行,空间上O(2*C)
int knapsack01(const vector<int>& w, const vector<int>& v, int C){
	int n=w.size();
	if(n==0){
		return 0;
	}
	vector<vector<int> > memo(2,vector<int>(C+1,0));
	for(int j=1;j<=C;++j){
		if(j>=w[0]){
			memo[0][j]=v[0];
		}
	}
	for(int i=1;i<n;++i){
		for(int j=1;j<=C;++j){
			if(j>=w[i]){
				int res=max(memo[(i-1)%2][j],v[i]+memo[(i-1)%2][j-w[i]]);
				memo[i&1][j]=res;
			}else{
				memo[i&1][j]=memo[(i-1)&1][j];
			}
			
		}
	}
	return memo[n%2][C];
}
//之和更新之前的数有关,空间上只用O(C)
int knapsack01(const vector<int>& w, const vector<int>& v, int C){
	int n=w.size();
	if(n==0){
		return 0;
	}
	vector<int> memo(C+1,0);
	/*for(int j=w[0];j<=C;++j){
			memo[j]=v[0];
		}
	}*/
	for(int i=0;i<n;++i){
		for(int j=C;j>=w[i];--j){	//这里需要从右至左更新,因为更新需要用到(i-1)左边数据, 
			memo[j]=max(memo[j],v[i]+memo[j-w[i]]);
		}
	}
	return memo[C];
}

//ld494,转换为背包问题,转化为，找nums中的所有组合数，使得和为target
int findSum(const vector<int>& nums, int target){
	vector<int> memo(target+1,0);
	memo[0]=1;
	for(int num:nums){
		for(int j=target;j>=num;--j){
			memo[j] = memo[j] + memo[j-num];
		}
	}
	return memo[target];
}
int findTargetSumWays(vector<int>& nums, int S) {
	int n=nums.size();
	if(S<0){
		S= 0-S;
	}
	int sum=0;
	for(int i=0;i<n;++i){
		sum+=nums[i];
	}
	
	if(S>sum){
		return 0;
	}
	
	if((sum+S) & 1){
		return 0;
	}
	int target = (sum+S)>>1;
	
	//从nums找到和为target的组合方法
	return findSum(nums,target);
}

//ld474,约束条件是二维的有两个时.
void form(const string& str, int& m, int& n){
	int sm=0,sn=0;
	for(int i=0;i<str.size();++i){
		if(str[i]==1){
			sn++;
		}else{
			sm++;
		}
	}
}
int findMaxForm(vector<string>& strs, int m, int n) {
	vector<vector<int>> memo(m+1,vector<int>(n+1,0));
	for(int i=0;i<strs.size();++i){
		int sm,sn;
		form(strs[i],sm,sn);
		for(int j=m;j>=sm;--j){
			for(int k=n;k>=sn;--k){
				memo[j][k]=max(memo[j][k],memo[j-sm][k-sn]+1);
			}
		}
	}
	
	return memo[m][n];
}

//完全背包问题,每个物品无限使用 
//0-1与完全之间是多重背包问题,物品个数限制
//多重维度,考虑体积和重量限制
//物品间互相约束

//ld300最长上升子序列
//LIS(i)表示第i个数字为结尾的最长上升 
int lengthOfLIS(vector<int>& nums) {
	int n=nums.size();
    if(n<=1){
        return n;
    }

    vector<int> LIS(n,1);
    for(int i=1;i<n;++i){
        for(int j=i-1;j>=0;--j){
        	if(nums[i]>nums[j]){
        		LIS[i] = max(LIS[i],LIS[j]+1);
			}
        }
    }
    int m=0;
    for(int i=0;i<n;++i){
        if(LIS[i]>m){
            m=LIS[i];
        }
    }
    return m;
}

//最长公共子序列
//LCS(m,n)为S1[0..m]和S2[0..n]的最长公共子序列
int LCStemp(const string& s1, int m, const string& s2, int n){
	if(m<0||n<0){
		return 0;
	}
	
	if(s1[m]==s2[n]){
		return LCStemp(s1,m-1,s2,n-1)+1;
	}else{
		return max(LCStemp(s1,m-1,s2,n),LCStemp(s1,m,s2,n-1));
	}
}
int LCS(string s1,string s2){
	int m=s1.size();
	int n=s2.size();
	
	return LCS(s1,m-1,s2,n-1);
}
//动态规划
int LCS2(string s1,string s2){
	int m=s1.size();
	int n=s2.size();
	if(m==0||n==0){
		return 0;
	}
	
	vector<vector<int> > mem(m,vector<int>(n,0));
	if(s1[0]==s2[0]){
		mem[0][0]=1;
	}
	for(int i=1;i<m;++i){
		if(s1[i]==s2[0]){
			mem[i][0]=1;
		}else{
			mem[i][0]=mem[i-1][0];
		}
	}
	for(int j=1;j<n;++j){
		if(s1[0]==s2[j]){
			mem[0][j]=1;
		}else{
			mem[0][j]=mem[0][j-1];
		}
	}
	for(int i=1;i<m;++i){
		for(int j=1;j<n;++j){
			if(s1[i]==s2[j]){
				mem[i][j]=mem[i-1][j-1]+1;
			}else{
				mem[i][j]=max(mem[i-1][j],mem[i][j-1]);
			}
		}
	}
	
	return mem[m-1][n-1];
} 

//ld377,nums={1,2,3},target=4;target可用nums中数(可重复)组合相加表示的种类数
int combinationSum4(vector<int>& nums, int target) {
	int n=nums.size();
	if(n==0){
		return 0;
	}
	
	vector<int> memo(target+1,0);
	memo[0]=1;
	for(int i=1;i<=target;++i){
		for(int j=0;j<n;++j){
			if(i >= nums[j]){
				memo[i] += memo[i-nums[j]];
			}
		}
	}
	return memo[target];
}

// 最长回文子序列
int longestPalindrome(string s){
	int n = s.size();
	vector<vector<int> > dp(n, vector<int>(n, 0));

	for(int i = n-1; i >= 0; --i){
		dp[i][i] = 1;
		for(int j = i+1; j < n; ++j){
			if(s[i] == s[j]){
				dp[i][j] = dp[i+1][j-1] + 2;
			}else{
				dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
			}
		}
	}
	return dp[0][n-1];
}

// 最长回文子序列2, 两个字符串的非空子序列拼接成回文串
int longestPalindrome_2(string word1, string word2){
	string s = word1 + word2;
	int K = word1.size();
	int n = s.size();
	int ans = 0;
	vector<vector<int> > dp(n, vector<int>(n, 0));

	for(int i = n-1; i >= 0; --i){
		dp[i][i] = 1;
		for(int j = i+1; j < n; ++j){
			if(s[i] == s[j]){
				dp[i][j] = dp[i+1][j-1] + 2;
				if(j >= K && i < K){
					ans = max(ans, dp[i][j]);
				}
			}else{
				dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
			}
		}
	}
	return ans;
}


int main(){
	
	return 0;
}
