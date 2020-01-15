#include<stdio.h>

int min(int a,int b){
	return a<b ? a : b;
}
int max(int a,int b){
	return a>b ? a : b;
}

int main(){
	int x,y,z;
	int res = 0;
	scanf("%d%d%d",&x,&y,&z);
	
	int a = min(x,min(y,z));
	int c = max(x,max(y,z));
	int b = x + y + z - a - c;
	
	if(c >= a+b){
		c = a+b-1;
	}
	
	res += (a*a*a+a)/2;//a a a
	res += a*a*(b-a);//a b b
	
	//Çó½âa b b --> a b c 
	for(int i=1;i<=c-b;++i){
		res += ((i-1)*i + a*a - (2*i-1)*a)/2;
	}
	
	printf("%d\n",res);
	
	return 0;
}
