#include<stdio.h>

using namespace std;

//ld455,贪心
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(),g.end(), greater<int>());	//从大到小排序 
    sort(s.begin(),s.end(),greater<int>());
    int si=0,gi=0;
    int res=0;
    while(gi<g.size()&&si<s.size()){
        if(s[si]>=g[gi]){
            res++;
            si++;
            gi++;
        }else{
            gi++;
        }
    }
    return res;
} 

//ld435,贪心与动态规划关系
bool comp(const Interval &a, const Interval &b){
    if(a.start!=b.start){
        return a.start<b.start;
    }
    return a.end<b.end;
}//动态规划,最长升序列类似 
int eraseOverlapIntervals(vector<Interval>& intervals) {
    if(intervals.size()==0){
        return 0;
    }
    sort(intervals.begin(),intervals.end(),comp);
    
    //memo[i]表示使用intervals[0..i]的区间能构成的最长不重叠区间序列
    vector<int> memo(intervals.size(),1);
    for(int i=1;i<intervals.size();++i){
        for(int j=0;j<i;++j){
            if(intervals[i].start>=intervals[j].end){
                memo[i]=max(memo[i],memo[j]+1);
            }
        }
    }
    int res=0;
    for(int i=0;i<memo.size();++i){
        res=max(res,memo[i]);
    }
    return intervals.size()-res;
}

//贪心算法做
bool comp2(const Interval &a, const Interval &b){
    if(a.end!=b.end){
        return a.end<b.end;
    }
    return a.start<b.start;
}
int eraseOverlapIntervals(vector<Interval>& intervals) {
    if(intervals.size()==0){
        return 0;
    }
    sort(intervals.begin(),intervals.end(),comp2);	//按结尾排序 
    
    int res=0;
    int pre=0;
    
    for(int i=1;i<intervals.size();++i){
    	if(intervals[i].start>=intervals[pre].end){
    		res++;
    		pre=i;
		}
	}
    
    return intervals.size()-res;
}

//ld376,找到序列中大小交替的序列。如1 3 2 7 6. 或6 3 4 1 9的长度
int wiggleMaxLength(vector<int>& nums) {
	int n=nums.size();
	if(n<2){
		return n;
	}
	
	int up=1,down=1;
	
	for(int i=1;i<n;++i){
		if(nums[i]>nums[i-1]){
			up = down+1;
		}
		else if(nums[i] < nums[i-1]){
			down = up+1;
		}
	}
	
	return max(up,down);
}

//ld392,判断s是否是t的子序列
bool isSubsequence(string s, string t) {
	int t_size = t.size();
	int s_size = s.size();
	
	int si=0;
	
	for(int ti=0; si<s_size&&ti<t_size; ++ti){
		if(s[si]==t[ti]){
			++si;
		}
	}
	return si==s_size;
}
//当有很多s时
string t;
vector<vector<int> > memo(26, vector<int>());
for(int i = 0; i < t.size(); ++i){
	memo[t[i]-'a'].push_back(i);
}
vector<bool> isSubsequence(vector<string> strs){
	vector<bool> res;
	int index[26];
	int pre;
	
	for(string str : strs){
		memset(index, -1 sizeof(index));
		pre = -1;
		
		for(int si = 0; si < str.size(); ++i){
			int j = str[si] - 'a';
			index[j]++;
			
			while(memo[j].size()>index[j]){
                if(memo[j][index[j]]<=pre){
                    index[j]++;
                }else{
                    break;
                }
            }
			if(memo[j].empty()||memo[j].size()<=index[j]){
				res.push_back(false);
				break;
			}
			pre = memo[j][index[j]];
		}
		res.push_back(true);
	}
	return res;
}

//ld121 只能买卖一次股票，求最赚的钱.贪心,若在第i天卖出，则买是在i前的最小值
int maxProfit(vector<int>& prices) {
	if(prices.size()<2){
		return 0;
	}
	int profit=0;
	int preMin=INT_MAX;
	
	for(int i=1;i<prices.size();++i){
		if(preMin > prices[i-1]){
			preMin=prices[i-1];
		}
		if(profit < prices[i]-preMin){
			profit=prices[i]-preMin;
		}
	}
	return profit;
}
 
int main(){
	
	return 0;
} 
