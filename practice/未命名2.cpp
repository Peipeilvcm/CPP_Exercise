#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<unordered_map>
using namespace std;
 
vector<int> split(const string& str, const string& delim) {
	vector<int> res;
	//先将要切割的字符串从string类型转换为char*类型
	char * strs = new char[str.length() + 1] ; //不要忘了
	strcpy(strs, str.c_str()); 
 
	char * d = new char[delim.length() + 1];
	strcpy(d, delim.c_str());
 
	char *p = strtok(strs, d);
	while(p) {
		string s = p; //分割得到的字符串转换为string类型
		int t = stoi(s);
		res.push_back(t); //存入结果数组
		p = strtok(NULL, d);
	}
 
	return res;
}

const int N = 1000; 
int Tree[N];
int w[N];
int findRoot(int x){
	if(Tree[x]==-1){
		return x;
	}
	else{
		int tmp = findRoot(Tree[x]);
		Tree[x] = tmp;
		return tmp;
	}
}


int main(){
	int N;
	cin>>N;
	string str;
	vector<vector<int> > v(N,vector<int>());
	fflush(stdin);
	for(int i=0;i<N;i++){//初始化,都是孤立结点 
		Tree[i]=-1;
	}
	for(int i=0;i<N;++i){
		getline(cin,str);
		v[i] = split(str, " ");
	}
	for(int i=0;i<N;++i){
		w[i]=v[i].size();
	}
	
	unordered_map<int,int> hash;
	
	for(int i=0;i<N;++i){
		for(int a:v[i]){
			if(hash.find(a)!=hash.end()){
				int a = findRoot(hash[a]);
				int b = findRoot(i);
				if(a!=b){
					Tree[a]=b;
					w[b]+=w[a]-1;
				}
			}
			hash[a] = i;
		}
	}
	int ans = 0,maxI=INT_MIN;
	for(int i=0;i<N;++i){
		if(Tree[i] == -1){
			ans++;
			maxI = max(maxI,w[i]);
		}
			
	}
	printf("%d\n%d\n",ans,maxI);
	
	return 0;
} 
