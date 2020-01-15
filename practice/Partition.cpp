#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &nums,int l,int r)
{
	int pov = nums[l];
    int i = l, j = r;
    int temp;
    while(i < j)
    {
        while(i < j && nums[j] >= pov)
            --j;
        temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        while(i < j && nums[i] <= pov)
            ++i;
        temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    return i;
}


int main()
{
	vector<int> v(10,0);
	for(int i=0;i<10;++i)
		v[i]=9-i;
	v[9]=9;
	cout<<partition(v,0,9);
	return 0;
} 
