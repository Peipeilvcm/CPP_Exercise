#include<stdio.h>
#include<iostream> 
#include<vector>
#include<string>
#include<unordered_map>
#include<stack>
using namespace std;
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

	return LCStemp(s1,m-1,s2,n-1);
} 

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

//ld290
vector<string> split(const string& str){
    vector<string> res;
    int n=str.size();
    if(n==0){
        return res;
    }
    int index=0;
    while(index<n){
        for(int i=index;i<n;++i){
            if(i==n-1||str[i]==' '){
            	if(i==n-1){
            		res.push_back(str.substr(index,i-index+1));
				}else{
					res.push_back(str.substr(index,i-index));
				}
                
                index=i+1;
                break;
            }
        }
    }
    return res;
}
bool wordPattern(string pattern, string str) {
    int m=pattern.size();
    if(m==0){
        if(str.empty()){
            return true;
        }
        return false;
    }
    
    vector<string> strV = split(str);
    for(int i=0;i<strV.size();++i){
    	printf("%s\n",strV[i].c_str());
	}
//	printf("??");0
    
    if(strV.size()!=m){
        return false;
    }
    
    unordered_map<char,string> hash;
    
    for(int i=0;i<m;++i){
        if(hash.find(pattern[i])!=hash.end()){
            if(hash[pattern[i]] != strV[i]){
                return false;
            }
        }else{
            hash[pattern[i]]=strV[i];
        }
    }
    return true;
}

vector<string> split(const char c, const string str){
    vector<string> res;
    if(str.empty()){
        return res;
    }
    
    int n=str.size();
    int index=0;
    while(index<n&&str[index]==c){
        index++;
    }
    while(index < n){
        int cnt=1;
        int i;
        for(i=index+1;i<n;i++){
            if(str[i]==c){
                res.push_back(str.substr(index,cnt));
                break;
            }
            cnt++;
        }
        if(i==n){
        	res.push_back(str.substr(index,cnt));
		}
        index=i;
        while(index<n&&str[index]==c){
            index++;
        }
    }
    return res;
}

string simplifyPath(string path) {
    vector<string> sp=split('/',path);
    int n=sp.size();
    
    stack<string> st;
    for(int i=0;i<n;++i){
        if(sp[i]==".."){
            if(!st.empty()){
                st.pop();
            }
        }else if(sp[i]=="."){
            continue;
        }else{
            st.push(sp[i]);
        }
    }
    
    string res;
    if(st.empty()){
        res+='/';
        return res;
    }
    while(!st.empty()){
        res = '/'+st.top()+res;
        st.pop();
    }
    return res;
}

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    if(m==0){
        return -1;
    }
    int n = grid.size();
    if(n==0){
        return -1;
    }
    
    vector<vector<int>> sum(m,vector<int>(n,0));
    sum[0][0]=grid[0][0];
    
    for(int i=1;i<m;++i){
        sum[i][0]=sum[i-1][0]+grid[i][0];
    }
    for(int j=1;j<n;++j){
        sum[0][j]=sum[0][j-1]+grid[0][j];
    }
    for(int i=1;i<m;++i){
        for(int j=1;j<n;++j){
            sum[i][j]=min(sum[i-1][j],sum[i][j-1])+grid[i][j];
            printf("%d ",sum[i][j]);
        }
        printf("\n");
    }
    return sum[m-1][n-1];
}

int main(){
//	int a[]={10,9,2,5,3,4};
//	vector<int> v(a,a+6);
//	printf("\n%d\n",lengthOfLIS(v));
//	string s1("ABCD");
//	string s2("AEBD"); 
//	printf("%d\n",LCS2(s1,s2));
	
//	string pattern("abba");
//	string str("dog cat cat dog");
//	if(wordPattern(pattern,str)){
//		printf("true\n");
//	}
//	string path("/...");
//	cout<<simplifyPath(path); 
	
	vector<vector<int> > v({{1,2,5},{3,2,1}});
	printf("%d\n",minPathSum(v)); 
	
	return 0;
}
