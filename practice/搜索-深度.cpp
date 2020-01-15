//搜索,深度
//n*m网格,不能重复进入一个格,查找从s到d的一天时间为t的路径 
#include<stdio.h>
char maze[8][8];
int n,m,t;//地图大小n*m，时间t 

bool success;
int go[][2]={
	1,0,-1,0,0,1,0,-1
}; 

void DFS(int x,int y,int time){
	for(int i=0;i<4;i++){
		int nx=x+go[i][0];
		int ny=y+go[i][1];
		if(nx<1||nx>n||ny<1||ny>m)
			continue;//越界
		if(maze[nx][ny]=='X')
			continue;//为墙,跳过
		if(maze[nx][ny]=='D'){
			if(time+1==t){
				success=true;
				return;
			}
			else
				continue;
		}
		maze[nx][ny]='X';//已经经过后不能再经过,改为墙
		DFS(nx,ny,time+1);
		maze[nx][ny]='.';//后续状态遍历完，回溯
		if(success)	return;//已经成功直接返回 
	}
}

int main(){
	while(scanf("%d%d%d",&n,&m,&t)!=EOF){
		if(n==0&&m==0&&t==0){
			break;
		}
		for(int i=1;i<=n;i++){
			scanf("%s",maze[i]+1);
		}
		success=false;
		int sx,sy;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(maze[i][j]=='D'){
					sx=i;
					sy=j;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(maze[i][j]=='S'&&(i+j)%2==((sx+sy)%2+t%2)%2){
					maze[i][j]='X';
					DFS(i,j,0);
				}
			}
		}
		puts(success==true?"YES":"NO");
	}
	return 0;
}

