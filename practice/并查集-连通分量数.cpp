//并查集,集合信息,确定集合中有哪些元素,判断两元素是否在同一集合中,求集合中元素数量
//通过两个元素所在树的根节点相同判定它们属于同一集合
//用双亲结点来表示树结构 

//计算连通分量个数 
#include<stdio.h>
using namespace std;
const int N = 1000; 
int Tree[N];
int findRoot(int x){
	if(Tree[x]==-1){
		return x;
	}
	else{
		int tmp = findRoot(Tree[x]);
		Tree[x] = tmp;
		return tmp;
	}
}

int main(){
	int n,m;
	while(scanf("%d",&n)!=EOF&&n!=0){
		scanf("%d",&m);
		for(int i=1;i<=n;i++){//初始化,都是孤立结点 
			Tree[i]=-1;
		}
		while(m-- != 0){
			int a,b;
			scanf("%d%d",&a,&b);
			a=findRoot(a);
			b=findRoot(b);
			if(a!=b)	Tree[a]=b;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(Tree[i]==-1)	ans++;
		}
		printf("%d\n",ans-1);
	}
	return 0;
}
