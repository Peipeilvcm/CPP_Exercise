#include<stdio.h>
using namespace std;
const int MAX_N = 1000;

int Tree[MAX_N];
int Rank[MAX_N];//树的高度

void init(int m){
	for(int i = 0; i < n; ++i){
		Tree[i] = i;
	}
	Rank[i] = 0;
}

// 查找树的根
int find(int x){
	if(Tree[x] == x){
		return x;
	}else{
		return Tree[x] = find(Tree[x]);
	}
}

// 合并x和y所属集合
void unite(int x, int y){
	x = find(x);
	y = find(y);
	if(x == y){
		return;
	}
	if(Rank[x] < Rank[y]){
		Tree[x] = y;
	}else{
		Tree[y] = x;
		if(Rank[x] == Rank[y]){
			Rank[x]++;
		}
	}
}

//判断是否在同一集合
bool same(int x, int y){
	return find(x) == find(y);
}