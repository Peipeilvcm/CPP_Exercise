void reverse(vector<int>& nums, int l, int r){
	for(int i=l,j=r;i<j;++i,--j){
		swap(nums[i],nums[j]);
	}
}

//字典序方法，求下一个排列
void nextPermutation(vector<int>& nums) {
	int n = nums.size();
	if(n<2){
		return;
	}
	
	int k=-1;
	for(int i=n-2;i>=0;--i){
		if(nums[i] < nums[i+1]){
			k = i;
			break;
		}
	}
	
	if(k==-1){
		sort(nums.begin(),nums.end());
		return;
	}
	
	for(int i=n-1;i>k;--i){
		if(nums[i] > nums[k]){
			swap(nums[i],nums[k]);
			reverse(nums,k+1,n-1);
			return;
		}
	}
	
}