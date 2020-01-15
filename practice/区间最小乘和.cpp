#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	vector<int> v(n,0);
	for(int i=0;i<n;++i){
		scanf("%d",&v[i]);
	}
    
	vector<int> sum(n,0);
    
    for(int i=0;i<n;++i){
        sum[i]=v[i];
        for(int j=i-1;j>=0;--j){
            if(v[j]>=v[i]){
                sum[i] += v[j];
            }else{
                break;
            }
        }
        for(int j=i+1;j<n;++j){
            if(v[j]>=v[i]){
                sum[i]+=v[j];
            }else{
                break;
            }
        }
    }
    
	int res = -1;
	for(int i=0;i<n;++i){
		res = max(res, sum[i]*v[i]);
	}
	printf("%d\n",res);

	return 0;
}
