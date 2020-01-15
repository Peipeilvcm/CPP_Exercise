#include<stdio.h>
#include<vector>
using namespace std;

void quickSort(vector<int> &nums, int left, int right){
	if(left >= right){
		return;
	}
	int l = left, r = left + 1;
	int pivot = nums[left];
	while(r <= right){
		if(nums[r] < pivot){
			l++;
			swap(nums[l], nums[r]);
		}
		r++;
	}
	swap(nums[left], nums[l]);
	
	quickSort(nums, left, l-1);
	quickSort(nums, l+1, right);
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
	int a[10]={3,2,5,7,1,34,8,4,10,3};
	vector<int> v;
	
	for(int i=0;i<10;i++){
		v.push_back(a[i]);
	}
	
	//quickSort(v,0,9);
	threeQuickSort(v,0,9);
	
	int n=v.size();
	for(int i=0;i<n;i++){
		printf("%d ",v[i]);
	}
	
	return 0;
}

// 链表快排
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
void quickSort(ListNode* head, ListNode* tail){
	if(head == tail || head->next == tail){
		return;
	}
	int pivot = head->val;
	ListNode* left = head;
	ListNode* right = head->next;
	while(right != tail){
		if(right->val < pivot){
			left = left->next;
			swapp(left->val, right->val);
		}
		right = right->val;
	}
	swapp(head->val, left->val);

	quickSort(head, left);
	quickSort(left->next, tail);
}


//归并排序
vector<int> tmp(nums.size(),0);
void mergeSort(vector<int>& nums, int l, int r){
	if(r - l < 1){
		return;
	}
	int mid = l + (r - l)/2;
	mergeSort(nums, l, m);
	mergeSort(nums, m+1,r);
	merge(nums, l, m, r);
}

void merge(vector<int>&nums, int l, int m, int r){
	int i=l, j=m+1;
	int k=l;
	while(i<=m||j<=r){
		if(i>m){
			tmp[k] = nums[j];
			j++;
		}else if(j>r){
			tmp[k] = nums[i];
			i++;
		}else if(nums[i] < nums[j]){
			tmp[k] = nums[i];
			i++;
		}else{
			tmp[k] = nums[j];
			j++;
			//this.cnt += m - i + 1; //nums[i] >= nums[j]，说明 nums[i...mid] 都大于 nums[j]
		}
		for (k = l; k <= r; k++)
        	nums[k] = tmp[k];
	}
}
