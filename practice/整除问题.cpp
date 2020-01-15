//�������⣬n�Ľ׳�����a��k�η�
#include<stdio.h>
#include<string.h>

bool mark[1001];
int prime[301];
int primeSize;
//����ɸѡ��,ɸѡ��1000������������ 
void init(){
	for(int i=2;i<1001;i++){
		if(mark[i])	continue;
		mark[i]=true;
		prime[primeSize++]=i;
		for(int j=i*i;j<1001;j+=i){
			mark[j]=true;
		}
	}
}

int cnt[1001];//n!�ֽ���ָ��
int cnt2[1001];//a��������

int main()
{
	int n,a;
	init();
	while(scanf("%d%d",&n,&a)!=EOF){
		for(int i=0;i<primeSize;i++)
			cnt[i]=cnt2[i]=0;
		for(int i=0;i<primeSize;i++){
			int t=n;
			while(t){
				cnt[i]+=t/prime[i];
				t/=prime[i];
			}
		}
		int ans=9999999;
		for(int i=0;i<primeSize;i++){
			while(a%prime[i]==0){
				cnt2[i]++;
				a/=prime[i];
			}
			if(cnt2[i]==0)	continue;
			if(cnt[i]/cnt2[i] < ans)	//�̵���Сֵ��Ϊ���� 
				ans=cnt[i]/cnt2[i];
		}
		printf("%d\n",ans); 
	}
	return 0;
 } 
