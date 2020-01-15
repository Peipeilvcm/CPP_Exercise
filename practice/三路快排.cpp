#include<stdio.h>
#include<vector>
using namespace std;

//当包含大量重复元素时,三路快排很好用

//用来解0,1,2三个数的排序,如12020101211010->00000111111222 
void sortColors(vector<int>& nums){
	int zeros = -1;			//nums[0...zeros]==0 
	int two = nums.size();	//nums[two...n-1]==2
	
	for(int i=0;i<two;){
		if(nums[i]==1){
			i++;
		}
		else if(nums[i]==2){
			--two;
			swap(nums[i],nums[two]);
		}
		else{
			++zeros;
			swap(nums[i],nums[zeros]);
		}
	}
}


void threeQuickSort(vector<int>& nums,int l,int r){
	if(l>=r){
		return;
	}
	
	int pov = nums[l];
	//nums[l...lt]<pov
	//nums[lt+1...rt-1]==pov
	//nums[rt,r]>pov 
	int lt=l-1;
	int rt=r+1;
	
	for(int i=l;i<rt;){
		if(nums[i]==pov){
			i++;
		}
		else if(nums[i]>pov){
			--rt;
			swap(nums[i],nums[rt]);
		}
		else{
			++lt;
			swap(nums[i],nums[lt]); 
		} 
	}
	
	threeQuickSort(nums,l,lt);
	threeQuickSort(nums,rt,r);
}




int main(){
	int a[]={1,2,0,1,0,2,1,0,1,2};
	vector<int> v;
	for(int i=0;i<10;i++){
		v.push_back(a[i]);
	} 
	
	//sortColors(v);
	threeQuickSort(v,0,9);
	
	int n = v.size();
	for(int i=0;i<n;i++){
		printf("%d ",v[i]);
	}
	
	
	
	return 0;
}
