#include<stdio.h>

using namespace std;

//ld455,̰��
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(),g.end(), greater<int>());	//�Ӵ�С���� 
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

//ld435,̰���붯̬�滮��ϵ
bool comp(const Interval &a, const Interval &b){
    if(a.start!=b.start){
        return a.start<b.start;
    }
    return a.end<b.end;
}//��̬�滮,����������� 
int eraseOverlapIntervals(vector<Interval>& intervals) {
    if(intervals.size()==0){
        return 0;
    }
    sort(intervals.begin(),intervals.end(),comp);
    
    //memo[i]��ʾʹ��intervals[0..i]�������ܹ��ɵ�����ص���������
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

//̰���㷨��
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
    sort(intervals.begin(),intervals.end(),comp2);	//����β���� 
    
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

//ld376,�ҵ������д�С��������С���1 3 2 7 6. ��6 3 4 1 9�ĳ���
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

//ld392,�ж�s�Ƿ���t��������
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
//���кܶ�sʱ
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

//ld121 ֻ������һ�ι�Ʊ������׬��Ǯ.̰��,���ڵ�i����������������iǰ����Сֵ
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
