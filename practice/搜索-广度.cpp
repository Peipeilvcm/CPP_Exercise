//搜索,广度优先搜素
//立方体寻路,x,y,z确定一个最小t,其它t都无效 
#include<stdio.h>
#include<queue>
using namespace std;

bool mark[50][50][50];//标记
int maze[50][50][50];//保存立方体信息
struct N{
	int x,y,z;
	int t;
};

queue<N> Q;
int go[][3]={
//x,y,z扩展坐标由x+go[i][0],y+go[i][1],z+go[i][2]得到 
	1,0,0,
	-1,0,0,
	0,1,0,
	0,-1,0,
	0,0,1,
	0,0,-1
};

int BFS(int a,int b,int c){
	while(Q.empty()==false){
		N now=Q.front();
		Q.pop();
		for(int i=0;i<6;i++){
			int nx=now.x+go[i][0];
			int ny=now.y+go[i][1];
			int nz=now.z+go[i][2];
			if(nx<0||nx>=a||ny<0||ny>=b||nz<0||nz>=c)
				continue;//丢弃该坐标
			if(maze[nx][ny][nz]==1)
				continue;//位置为墙 
			if(mark[nx][ny][nz]==true)
				continue;//该坐标已经得到过,丢弃
			N tmp;
			tmp.x=nx;
			tmp.y=ny;
			tmp.z=nz;
			tmp.t=now.t+1;
			Q.push(tmp);
			mark[nx][ny][nz]=true;
			if(nx==a-1&&ny==b-1&&nz==c-1)
				return tmp.t; 
		}
	}
	return -1;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int a,b,c,t;
		scanf("%d%d%d%d",&a,&b,&c,&t);
		for(int i=0;i<a;i++){
			for(int j=0;j<b;j++){
				for(int k=0;k<c;k++){
					scanf("%d",&maze[i][j][k]);
					mark[i][j][j]=false; 
				}
			}
		}
		while(Q.empty()==false){
			Q.pop();
		}
		mark[0][0][0]=true;
		N tmp;
		tmp.t=tmp.x=tmp.y=tmp.z=0;
		Q.push(tmp);
		int rec=BFS(a,b,c);
		if(rec<=t)
			printf("%d\n",rec);
		else
			printf("-1\n");
	}
	return 0;
} 
