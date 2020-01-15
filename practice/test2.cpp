#include<iostream>
#include<cstdio>

//#include<vector>
//#include<map>
//#include<queue>
//#include<string>

using namespace std;

bool isB(int a, int b, int num){
	while(num){
		if(num%10 == a || num%10 == b){
			num /= 10;
		}else{
			return false;
		}
	}
	return true;
}

long long cal(int k,int i){
	long long res=1;
	if(i==0||i==k){
		return res;
	}
	if(i >= (k/2)){
		for(int j=i+1;j<=k;++j){
			res *= j;
            res /= (j-i);
            res %= 1000000007;
		}
		return res;
	}else{
		return cal(k, k-i);
	}
}

int test1(int a, int b, int k){
	if(a == b){
		if(isB(a,a,a*k)){
			return 1;
		}else{
			return 0;
		}
	}
	
	long long res=0;
	for(int i=0;i<=k;++i){
		if(isB(a,b,i*a+(k-i)*b)){
			res += cal(k,i);
            res %= 1000000007;
		}
	}
	return res;
}


int main(){
	int a,b,k;
	cin>>a>>b>>k;
//	cout<<cal(1000,50)<<endl;
	cout<<test1(a,b,k);
	
	return 0;
}
