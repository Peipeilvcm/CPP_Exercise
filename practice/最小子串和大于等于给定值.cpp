#include<stdio.h>
using namespace std;
#include<vector>

//»¬¶¯´°¿Ú 

int minSubArrayLen(int s,vector<int>& nums){
	int l = 0,r = -1;
	int sum = 0;
	int res = nums.size() + 1;
	
	int n = nums.size();
	while(l < n){
		if(r+1 < n && sum < s){
			++r;
			sum += nums[r];
		}
		else{
			sum -= nums[l];
			++l;
		}
		
		if(sum >= s){
			res = min(res,r-l+1);
		} 
	}
	
	if(res == nums.size() + 1)
		return 0;
	
	return res;
}

int main(){
	int a[] = {2,3,1,2,2,4,3};
	vector<int> v;
	for(int i=0;i<7;++i){
		v.push_back(a[i]);
	}
	printf("%d\n",minSubArrayLen(7,v));
	
	return 0;
}
