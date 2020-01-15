//求包含元素最多集合,并输出该集合元素个数 
#include<stdio.h>
const int N=10000001;
int Tree[N];
int findRoot(int x){
	if(Tree[x]==-1)
		return x;
	else{//加入路径压缩 
		int tmp = findRoot(Tree[x]);
		Tree[x]=tmp;
		return tmp;
	}
}

int sum[N];//表示以结点i为根的树的结点个数,当Tree[i]为-1时有效

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<N;i++){
			Tree[i]=-1;
			sum[i]=1;
		}
		while(n-- != 0){
			int a,b;
			scanf("%d%d",&a,&b);
			a=findRoot(a);
			b=findRoot(b);
			if(a!=b){
				Tree[a]=b;
				sum[b]+=sum[a];
			}
		}
		int ans =1;
		for(int i=1;i<=N;i++){
			if(Tree[i]==-1&&sum[i]>ans)
				ans=sum[i];
		}
		printf("%d\n",ans);
	}
	return 0;
} 
