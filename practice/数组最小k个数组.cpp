#include<iostream>
#include<vector>
using namespace std;

int partion(vector<int>& nums,int l,int r){
    int pov = nums[l];
    int i=l,j=r;
    while(i < j){
        while(i < j && nums[j] >= pov){
            --j;
        }
        swap(nums[i],nums[j]);
        while(i < j && nums[i] <= pov){
            ++i;
        }
        swap(nums[i],nums[j]);
    }
    return i;
}
void findK(vector<int>& input, int l, int r, int k){
    int loc = partion(input, l, r);
    if(loc - l + 1 == k){
        return;
    }else if(loc - l + 1 > k){
        findK(input, l, loc - 1, k);
    }else{
        findK(input, loc+1, r, k - loc + l - 1);
    }
}

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    vector<int> res;
    int n = input.size();
    if(k > n|| n==0){
        return res;
    }
    findK(input, 0, n-1, k);
    for(int i=0;i<k;++i){
        res.push_back(input[i]);
    }
    return res;
}

void printV(const vector<int> v){
	for(int i=0;i<v.size();++i){
		printf("%d ",v[i]);
	}
	printf("\n");
} 


int main()
{
	vector<int> v({3,1,6,2,8,7,9,4,5});
	
	printV(GetLeastNumbers_Solution(v, 9));
	return 0;
} 
