//二分求幂
#include<stdio.h>

//求A的B次方的后三位 

int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		if(a==0&&b==0) break;
		int ans=1;
		while(b!=0){
			if(b&1 == 1){
				ans*=a;
				ans%=1000;//求后三位 
			}
			b = b>>1;
			a *= a;
			a%=1000; 
		}
		printf("%d\n",ans); 
	}
	return 0;
} 
