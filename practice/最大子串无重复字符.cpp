#include<stdio.h>
#include<string>
using namespace std;


//滑动窗口 

int maxSubArrayLen(string s){
	
	int freq[256] = {0}; 
	
	int l = 0,r = -1;
	int res = 0;
	
	int n = s.size();
	while(r < n-1){
		if(r + 1 < n && freq[s[r + 1]] == 0){
			++r;
			freq[s[r]] ++;
		}
		else{
			freq[s[l]]--;
			l++;
		}
		res = max(res,r-l+1);
	}
	
	return res;
}

//ld76,最小长度子传包含序列
string minWindow(string s, string t) {
        
	int m=s.size();
	int n=t.size();
	
	pair<int, int> res=make_pair(-1,m+1);
	
	if(m==0||m<n){
		return "";
	}
	
	unordered_map<char,int> hash;
	for(int i=0;i<n;++i){
		hash[t[i]]++;
	}
	
	int l=-1;
	int r=-1;
	int count=0;
	
	int flag=1;//扩充
	
	l=0;
	while(l<m&&r<m){
		if(flag==1){
			r++;
			if(hash.find(s[r])!=hash.end()){
				if(hash[s[r]]>0){
					count++;
				}
				hash[s[r]]--;
				if(count==n){
					flag=2;//收缩,收缩时确认长度
					
				}
			}
		}
		else{
			if(hash.find(s[l])!=hash.end()){
				if(hash[s[l]]==0){
					if(res.second > r-l+1){
						res.first = l;
						res.second = r-l+1;
					}
					count--;
					flag=1;
				}
				hash[s[l]]++;
			}
			l++;
		}
	}
	if(res.second!=m+1){
		return s.substr(res.first,res.second);
	}else{
		return "";
	}

}

int main(){
	
	string s("abcbcabvacas");
	
	printf("%d\n",maxSubArrayLen(s));
	
	return 0;
}
