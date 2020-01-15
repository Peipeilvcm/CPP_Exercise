//图中两点最短路径Floyd 时间O(n^3)空间O(n^2) 
//可以计算图上所有结点对之间最短路径 
/*
初始时邻接矩阵edge[i][j]表示i到j不经过其它中间点的最短距离
然后依次增加结点1,结点2,...,结点n,
比较edge[i][k]+edge[k][j]是否小于当前最小值然后更新
最后最短路径可以确定 
*/ 

/*
//ans[k][i][j]代表经过前k个结点,i到j的最短路径 
for(int k=1;k<=n;k++){//从1至n循环k 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(ans[k-1][i][k]==无穷||ans[k-1][k][j]==无穷){
				//i或j不能能够通过前k-1个点与k连通 
				ans[k][i][j]=ans[k-1][i][j];
				continue;
			}
			if(ans[k-1][i][j]==无穷||ans[k-1][i][k]+ans[k-1][k][j]<ans[k-1][i][j]){
				//经过前k-1个点,i和j不连通；或经过k点路径比原来更短 
				ans[k][i][j]=ans[k-1][i][k]+ans[k-1][k][j];
			}
			else{//保持原状 
				ans[k][i][j]=ans[k-1][i][j];
			}
		}
	}
}

//化简如下 
for(int k=1;k<=n;k++){//从1至n循环k 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(ans[i][k]==无穷||ans[k][j]==无穷)	continue; 
			if(ans[i][j]==无穷||ans[i][k]+ans[k][j]<ans[i][j])
				ans[i][j]=ans[i][k]+ans[k][j];
		}
	}
}
*/
//求1号到n号的最短路径
#include<stdio.h>
int ans[101][101];//邻接矩阵
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m) != EOF){
		if(n==0&&m==0)
			break;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ans[i][j]=-1;//初始化,-1代表无穷 
			}
			ans[i][i]=0;
		}
		while(m--){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			ans[a][b]=ans[b][a]=c;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(ans[i][k]==-1||ans[k][j]==-1)	continue;
					if(ans[i][j]==-1||ans[i][k]+ans[k][j]<ans[i][j]){
						ans[i][j]=ans[i][k]+ans[k][j];
					}
				}
			}
		}
		printf("%d\n",ans[1][n]);
	}
	return 0;
} 


