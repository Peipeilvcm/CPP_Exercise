//标记素数的倍数为非素数,素数筛选法 
#include<stdio.h>

int prime[10000];
int primeSize=0; 
bool mark[10001];
void init(){
	for(int i = 1; i<=10000; ++i){
		mark[i] = false;
	}
	primeSize=0;
	for(int i=2;i<=10000;i++){
		if(mark[i]==true)	continue;
		prime[primeSize++]=i;
		for(int j=i*i;j<=10000;j+=i){
			mark[j]=true;
		}
	}
}

int main()
{
	init();
	int n;
	while(scanf("%d",&n) != EOF){;
		for(int i=0;prime[i]<n;i++){
			printf("%d ",prime[i]);
		}
		printf("\n");
	}
	return 0;
} 
