#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> nums;
	int n,temp;
	cin>>n;
	for(int i = 0; i < n; ++i)
	{
		cin>>temp;
		nums.push_back(temp);
	}
	
	vector<int> pre = vector<int>(n,0);
    int max1 = 0,max2=0;
    
    sum[0]=nums[0];
    for(int i = 1; i < n; ++i)
    {
        sum[i]=sum[i-1]+nums[i];
    }
    //cout<<"??"; 
    int l1=0,l2=0;
    int r1=n-1,r2=n-1;
    while(l2<r1)
    {
        while(l1<=l2)
        {
            if(max1<sum[l2]-sum[l1]+nums[l1])
            {
                max1 = sum[l2]-sum[l1]+nums[l1];
            }
            l1++;
        }
        l1 = 0;
        l2++;
        while(r2>=r1)
        {
            if(max2<sum[r2]-sum[r1]+nums[r1])
            {
                max2 = sum[r2]-sum[r1]+nums[r1];
            }
            r2--;
        }
        r2=n-1;
        r1--;
    }
    cout<<max1<<max2;
    cout<<max1+max2;
    return 0;
	
}
