#include<stdio.h>
#include<vector>
#include<map>
using namespace std;

/*
查找有无set
查找对应关系map 
insert
find
erase
change(map)
*/


//map查找两个数组中的交集,并没有重复数组 [1,2,2,1]、[2,2]=>[2,2] 
vector<int> intersect(vector<int>& nums1,vector<int>& nums2){
	map<int,int> record;
	//O(nlogn)
	for(int i=0;i<nums1.size();++i){
		
		if(record.find(nums1[i]) == record.end()){
			record.insert(make_pair(nums1[i],1));
		}
		else{
			record[nums1[i]]++;
		}
		
		//record[nums1[i]]++;	//已经插入 
	}
	
	vector<int> resultVec;
	for(int i=0;i<nums2.size();++i){
		if(record[nums2[i]]>0){
			resultVec.push_back(nums2[i]);
			record[nums2[i]]--;
		}
	}
	
	return resultVec;
}

void printVec(vector<int> nums){
	for(int i=0;i<nums.size();++i){
		printf("%d ",nums[i]);
	}
	printf("\n");
} 

int main(){
	int a[] = {1,2,2,1};
	int b[] = {2,2};
	
	vector<int> nums1(a, a+4);
	vector<int> nums2(b,b+2);
	
	printVec(intersect(nums1,nums2));
	
	return 0;
}
