#include<stdio.h>

int a[101];
int F[101];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0){
		F[0]=1;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			F[i]=1;
			for(int j=0;j<i;j++){
				if(F[j]+1>F[i]&&a[i]>a[j])
					F[i]=F[j]+1;
			}
		}
		int max=1;
		for(int i=0;i<n;i++){
			if(F[i]>max)
				max=F[i];
		}
		printf("%d\n",max);
	}
	return 0;
}
