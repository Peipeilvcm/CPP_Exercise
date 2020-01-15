//ͼ���������·��Floyd ʱ��O(n^3)�ռ�O(n^2) 
//���Լ���ͼ�����н���֮�����·�� 
/*
��ʼʱ�ڽӾ���edge[i][j]��ʾi��j�����������м�����̾���
Ȼ���������ӽ��1,���2,...,���n,
�Ƚ�edge[i][k]+edge[k][j]�Ƿ�С�ڵ�ǰ��СֵȻ�����
������·������ȷ�� 
*/ 

/*
//ans[k][i][j]������ǰk�����,i��j�����·�� 
for(int k=1;k<=n;k++){//��1��nѭ��k 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(ans[k-1][i][k]==����||ans[k-1][k][j]==����){
				//i��j�����ܹ�ͨ��ǰk-1������k��ͨ 
				ans[k][i][j]=ans[k-1][i][j];
				continue;
			}
			if(ans[k-1][i][j]==����||ans[k-1][i][k]+ans[k-1][k][j]<ans[k-1][i][j]){
				//����ǰk-1����,i��j����ͨ���򾭹�k��·����ԭ������ 
				ans[k][i][j]=ans[k-1][i][k]+ans[k-1][k][j];
			}
			else{//����ԭ״ 
				ans[k][i][j]=ans[k-1][i][j];
			}
		}
	}
}

//�������� 
for(int k=1;k<=n;k++){//��1��nѭ��k 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(ans[i][k]==����||ans[k][j]==����)	continue; 
			if(ans[i][j]==����||ans[i][k]+ans[k][j]<ans[i][j])
				ans[i][j]=ans[i][k]+ans[k][j];
		}
	}
}
*/
//��1�ŵ�n�ŵ����·��
#include<stdio.h>
int ans[101][101];//�ڽӾ���
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m) != EOF){
		if(n==0&&m==0)
			break;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ans[i][j]=-1;//��ʼ��,-1�������� 
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


