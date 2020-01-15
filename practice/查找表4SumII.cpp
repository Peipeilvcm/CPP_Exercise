#include<stdio.h>
#include<unordered_map>
#include<vector>

using namespace std;

//454给定A,B,C,D,寻找i,j,k,l组合使得A[i]+..+D[l]==0 
int fourSumCount(vector<int>& A,vector<int>& B,vector<int>& C,vector<int>&D){
	
	unordered_map<int,int> record;
	for(int i=0;i<C.size();++i){
		for(int j=0;j<D.size();++j){
			record[C[i]+D[j]]++;
		}
	}
	
	int res = 0;
	for(int i=0;i<A.size();++i){
		for(int j=0;j<B.size();++j){
			if(record.find(0-A[i]-B[j]) != record.end()){
				res += record[0-A[i]-B[j]];
			}
		}
	}
	
	return res;
}

int main(){
	int a[] = {1,2,3,4};
	int b[] = {1,2,3};
	int c[] = {-1,-2,-3};
	int d[] = {-1,-2,-3,-4};
	
	vector<int> A(a,a+4);
	vector<int> B(b,b+3);
	vector<int> C(c,c+3);
	vector<int> D(d,d+4); 
	
	printf("%d\n",fourSumCount(A,B,C,D));
	return 0;
}
