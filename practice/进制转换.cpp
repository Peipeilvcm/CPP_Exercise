#include<stdio.h>

int main()
{
	long long a,b;
	int m;
	while(scanf("%d",&m) != EOF){
		if(m == 0)
			break;
		scanf("%lld%lld",&a,&b);
		a = a + b;
		int ans[50],size = 0;
		while(a!=0){
			ans[size++]=a%m;
			a/=m; 
		}
		for(int i=size-1;i>=0;i--){
			printf("%d",ans[i]); 
		}
		printf("\n");
	}
	return 0;
}

//%lldת��long long
//%I64dת��__int64 
