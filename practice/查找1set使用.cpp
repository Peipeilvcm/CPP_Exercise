#include<stdio.h>
#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
using namespace std;

/*
map,set��ƽ�������ʵ��logn
unordered_set,unorder_map�ǹ�ϣ��ʵ��,O(1)����,ʧȥ����˳���� 

��������set
���Ҷ�Ӧ��ϵmap 
insert
find
erase
change(map)
*/

//set�������������еĽ���,��û���ظ����� [1,2,2,1]��[2,2]=>[2] 
vector<int> intersection(vector<int>& nums1,vector<int>& nums2){
	
	/*
	set<int> record;
	for(int i=0;i<nums.size();i++){
		record.insert(nums1[i]);
	}*/
	//��vectorתset O(nlogn) 
	set<int> record(nums1.begin(),nums1.end());
	
	//O(nlogn)
	set<int> resultSet;
	for(int i=0;i<nums2.size();i++){
		if(record.find(nums2[i])!=record.end()){
			resultSet.insert(nums2[i]);
		}
	}
	
	//setתvector 
	return vector<int>(resultSet.begin(),resultSet.end());
}

vector<int> intersection2(vector<int>& nums1,vector<int>& nums2){
	//��vectorתunordered_set O(n) 
	unordered_set<int> record(nums1.begin(),nums1.end());
	
	//O(n)
	unordered_set<int> resultSet;
	for(int i=0;i<nums2.size();i++){
		if(record.find(nums2[i])!=record.end()){
			resultSet.insert(nums2[i]);
		}
	}
	
	//setתvector 
	return vector<int>(resultSet.begin(),resultSet.end());
}

void printVec(vector<int> nums){
	for(int i=0;i<nums.size();++i){
		printf("%d ",nums[i]);
	}
	printf("\n");
}

//Leetcode220,ʹ��˳������
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
