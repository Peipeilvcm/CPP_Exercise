#include<iostream>

using namespace std;

class A
{
	private:
		int value;
	public:
		A(int n){ 
			value = n;
		}
		A(const A &other){	//若是A other 会递归调用 
			value = other.value;	
		}
		
		void print(){
			cout<<value;
		}
};

int main()
{
	A a = 10;
	A b = a;
	b.print();
	return 0;
} 
