#include<stdio.h>
#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
using namespace std;

/*
map,set是平衡二叉树实现logn
unordered_set,unorder_map是哈希表实现,O(1)查找,失去数据顺序性 

查找有无set
查找对应关系map 
insert
find
erase
change(map)
*/

//set查找两个数组中的交集,并没有重复数组 [1,2,2,1]、[2,2]=>[2] 
vector<int> intersection(vector<int>& nums1,vector<int>& nums2){
	
	/*
	set<int> record;
	for(int i=0;i<nums.size();i++){
		record.insert(nums1[i]);
	}*/
	//用vector转set O(nlogn) 
	set<int> record(nums1.begin(),nums1.end());
	
	//O(nlogn)
	set<int> resultSet;
	for(int i=0;i<nums2.size();i++){
		if(record.find(nums2[i])!=record.end()){
			resultSet.insert(nums2[i]);
		}
	}
	
	//set转vector 
	return vector<int>(resultSet.begin(),resultSet.end());
}

vector<int> intersection2(vector<int>& nums1,vector<int>& nums2){
	//用vector转unordered_set O(n) 
	unordered_set<int> record(nums1.begin(),nums1.end());
	
	//O(n)
	unordered_set<int> resultSet;
	for(int i=0;i<nums2.size();i++){
		if(record.find(nums2[i])!=record.end()){
			resultSet.insert(nums2[i]);
		}
	}
	
	//set转vector 
	return vector<int>(resultSet.begin(),resultSet.end());
}

void printVec(vector<int> nums){
	for(int i=0;i<nums.size();++i){
		printf("%d ",nums[i]);
	}
	printf("\n");
}

//Leetcode220,使用顺序性质
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    set<int> record;
    
    for(int i=0;i<nums.size();++i){
        if(record.lower_bound(nums[i]-t) != record.end() &&
           *record.lower_bound(nums[i]-t) <= nums[i] + t){
            return true;
        }
        
        record.insert(nums[i]);
        
        if(record.size() == k+1){
            record.erase(nums[i-k]);
        }
    }
    return false;
} 


int main(){
	int a[] = {1,2,2,1};
	int b[] = {2,2};
	
	vector<int> nums1(a, a+4);
	vector<int> nums2(b,b+2);
	
	printVec(intersection2(nums1,nums2));
	
	return 0;
}
