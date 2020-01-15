#include<stdio.h>
#include<vector>
#include<unordered_map>
using namespace std;

//Two Sum 对任意nums,返回i,j使得nums[i]+nums[j]=target 

vector<int> twoSum(vector<int>& nums,int target){
	//逐步放入map中
	unordered_map<int,int> record;
	for(int i=0;i<nums.size();++i){
		int comp = target - nums[i];
		if(record.find(comp) != record.end()){
			int res[2] = {record[comp],i};
			return vector<int>(res,res+2);
		}
		record[nums[i]]=i;
	}
	int res[2] = {-1,-1};
	return vector<int>(res,res+2);
}

//ld15,三数和,两指针,有序数组
vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int> >res;
	int n=nums.size();
	if(n<=0){
		return res;
	}
	
	sort(nums.begin(),nums.end());
	for(int i=0;i<n-2;){
		int a=nums[i];
		if(a>0){
			break;
		}
		if(a==0&&nums[i+2]==0){
			res.push_back(vector<int>({0,0,0}));
			break;
		}
		
		for(int j=i+1,k=n-1; j<k;){
			int b=nums[j];
			int c=nums[k];
			if(a+b+c==0){
				res.push_back(vector<int>({a,b,c}));
				while(nums[++j]==b){};
				while(nums[--k]==c){};
			}else if(a+b+c<0){
				while(nums[++j]==b){};
			}else{
				while(nums[--k]==c){};
			}
		}
		while(nums[++i]==a){};
	}
	
	return res;
}

//ld18,4数和,1+3sum
vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int> > res;
	int n=nums.size();
	if(n<4){
		return res;
	}
	
	sort(nums.begin(),nums.end());
	
	for(int i=0;i<n-3;){
		int a=nums[i];
		for(int j=i+1;j<n-2;){
			int b=nums[j];
			for(int k=j+1,p=n-1;k<p;){
				int c=nums[k];
				int d=nums[p];
				if(a+b+c+d==target){
					res.push_back(vector<int>({a,b,c,d}));
					while(nums[++k]==c){};
					while(nums[--p]==d){};
				}else if(a+b+c+d<target){
					while(nums[++k]==c){};
				}else{
					while(nums[--p]==d){};
				}
			}
			while(nums[++j]==b){};
		}
		while(nums[++i]==a){};
	}
	return res;
}

//16找到和离target最近的三个数
int threeSumClosest(vector<int>& nums, int target) {
	int n=nums.size();
	if(n<3){
		return -1;
	}
	int res;
	int cha=99999999;
	
	sort(nums.begin(),nums.end());
	for(int i=0;i<n-2;){
		int a=nums[i];
		for(int j=i+1,k=n-1; j<k;){
			int b=nums[j];
			int c=nums[k];
			
			if(a+b+c==target){
				return target;
			}else if(a+b+c<target){
				if(target-a-b-c<cha){
					res=a+b+c;
					cha=target-a-b-c;
				}
				while(nums[++j]==b){};
			}else{
				if(a+b+c-target<cha){
					res=a+b+c;
					cha=a+b+c-target;
				}
				while(nums[--k]==c){};
			}
		}
		while(nums[++i]==a){};
	}
	
	return res;
}

//ld49,对字符串排序然后找相同的字符串归为一类
string sortStr(const string str){
	string s=str;
	sort(s.begin(),s.end());
	return s;
}
vector<vector<string>> groupAnagrams(vector<string>& strs) {
	vector<vector<string> > res;
	int n=strs.size();
	if(n==0){
		return res;
	}
	
	int cnt=0;
	unordered_map<string,int> hash;
	for(int i=0;i<n;++i){
		string s=sortStr(strs[i]);
		if(hash.find(s)!=hash.end()){
			res[hash[s]].push_back(strs[i]);
		}else{
			hash[s]=cnt;
			res.push_back(vector<string>());
			res[cnt].push_back(strs[i]);
			cnt++;
		}
	}
	return res;
}

void printVec(vector<int> nums){
	for(int i=0;i<nums.size();++i){
		printf("%d ",nums[i]);
	}
	printf("\n");
} 

int main(){
	int a[] = {1,3,9,9,4,6,3,4,5};
	vector<int> v(a,a+9);
	
	printVec(twoSum(v,9));
	
	return 0;
}
