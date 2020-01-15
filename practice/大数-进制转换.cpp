//大数-进制转换
#include<stdio.h>
#include<string.h>

struct bigInteger{
	int digit[1000];
	int size;
	
	void init(){
		for(int i=0;i<1000;i++){
			digit[i]=0;
		}
		size=0;
	}
	
	void set(int x){
		init();
		while(x!=0){
			digit[size++]=x%10000;
			x/=10000;
		}
	}
	
	void output(){
		for(int i=size-1;i>=0;i--){
			if(i!=size-1)
				printf("%04d",digit[i]);
			else
				printf("%d",digit[i]);
		}
		printf("\n");
	}
	
	//大数与普通整数的乘积 
	bigInteger operator * (int x) const{
		bigInteger ret;
		ret.init();
		int carry=0;//进位
		for(int i=0;i<size;i++){
			int tmp=x*digit[i]+carry;
			carry = tmp/10000;	//进位计算
			tmp%=10000;
			ret.digit[ret.size++] = tmp; 
		}
		if(carry!=0){//最高位进位 
			ret.digit[ret.size++]=carry;
		}
		return ret;
	}
	
	bigInteger operator + (const bigInteger &A) const{
		bigInteger ret;
		ret.init();
		int carry=0;
		for(int i=0;i<A.size||i<size;i++){
			int tmp = A.digit[i]+digit[i]+carry;
			carry=tmp/10000;
			tmp%=10000;
			ret.digit[ret.size++]=tmp;
		}
		if(carry!=0){
			ret.digit[ret.size++]=carry;
		}
		return ret;
	}
	
	bigInteger operator / (int x) const{
		bigInteger ret;
		ret.init();
		int remainder=0;//余数
		for(int i=size-1;i>=0;i--){//从高位开始计算 
			int t=(remainder*10000 + digit[i])/x;
			int r=(remainder*10000 + digit[i])%x;
			ret.digit[i]=t;
			remainder=r;
		}
		ret.size=0;
		for(int i=0;i<100;i++){
			if(digit[i]!=0)	ret.size=i;
		}
		ret.size++;
		return ret;
	}
	
	int operator % (int x) const{
		int remainder = 0;//余数
		for(int i=size-1;i>=0;i--){
			int t=(remainder*10000+digit[i])/x;
			int r=(remainder*10000+digit[i])%x;
			remainder=r;
		}
		return remainder;
	}
}a,b,c;

char str[10000];
char ans[10000];

int main(){
	int n,m;
	while(scanf("%d%d",&m,&n)!=EOF){
		scanf("%s",str);
		int L =strlen(str);
		a.set(0);//用来保存转换成10进制的m进制数 
		b.set(1);//在m进制向10进制转换过程中，代表每一位的权重 
		
		for(int i=L-1;i>=0;i--){
			int t;
			if(str[i]>'0'&&str[i]<='9'){
				t=str[i]-'0';
			}
			else{
				t=str[i]-'A'+10;
			}
			a=a+b*t;
			b=b*m;
		}
		int size=0;
		while(a.digit[0]!=0||a.size!=1){
			int t=a%n;
			if(t>=10)
				ans[size++]=t-10+'A';
			else
				ans[size++]=t+'0';
			a=a/n;
		}
		for(int i=size-1;i>=0;i--){
			printf("%c",ans[i]);
		}
		printf("\n");
	}
	return 0;
} 
