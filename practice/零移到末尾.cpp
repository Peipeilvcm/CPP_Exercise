#include<stdio.h>
using namespace std;

#include<vector>


void moveZeros(vector<int>& nums){
	vector<int> nonZeros;
	
	int n = nums.size();
	for(int i=0;i<n; i++){
		if(nums[i]){
			nonZeros.push_back(nums[i]);
		}
	}
	int n2=nonZeros.size();
	for(int i=0;i<n2;i++){
		nums[i]=nonZeros[i];
	}
	for(int i=n2;i<n;i++){
		nums[i]=0;
	}
}

void moveZeros2(vector<int>& nums){
	int n=nums.size();
	int k = 0;
	for(int i=0;i<n;i++){
		if(nums[i]){
			if(i!=k){
				swap(nums[k++],nums[i]);
			}
			else{
				k++;
			}
			
		}
	}
} 

int main()
{
	vector<int> v;
	for(int i=0;i<10;i++){
		v.push_back(i);
	}
	v[5]=0;
	v[8]=0;
	
	moveZeros2(v);
	for(int i;i<10;i++){
		printf("%d ",v[i]);
	}
	
	return 0;
}
