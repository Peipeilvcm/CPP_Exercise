//整除问题，n的阶乘整除a的k次方
#include<stdio.h>
#include<string.h>

bool mark[1001];
int prime[301];
int primeSize;
//素数筛选法,筛选出1000以内所有素数 
void init(){
	for(int i=2;i<1001;i++){
		if(mark[i])	continue;
		mark[i]=true;
		prime[primeSize++]=i;
		for(int j=i*i;j<1001;j+=i){
			mark[j]=true;
		}
	}
}

int cnt[1001];//n!分解幂指数
int cnt2[1001];//a中因子数

int main()
{
	int n,a;
	init();
	while(scanf("%d%d",&n,&a)!=EOF){
		for(int i=0;i<primeSize;i++)
			cnt[i]=cnt2[i]=0;
		for(int i=0;i<primeSize;i++){
			int t=n;
			while(t){
				cnt[i]+=t/prime[i];
				t/=prime[i];
			}
		}
		int ans=9999999;
		for(int i=0;i<primeSize;i++){
			while(a%prime[i]==0){
				cnt2[i]++;
				a/=prime[i];
			}
			if(cnt2[i]==0)	continue;
			if(cnt[i]/cnt2[i] < ans)	//商的最小值即为所求 
				ans=cnt[i]/cnt2[i];
		}
		printf("%d\n",ans); 
	}
	return 0;
 } 
