#include<iostream>
#include<thread>
#include<mutex>
#include<Windows.h>

using namespace std;

mutex mu;	//�̻߳������
int totalNum = 10;	//ȫ�ֱ����������� 

void func1(){
	while(totalNum > 0){
		mu.lock();
		cout<<totalNum<<endl;
		Sleep(100);
		mu.unlock();
	}
}

void func2(){
	while(totalNum > 0){
		mu.lock();
		cout<<"Num--"<<endl;
		totalNum--;
		Sleep(100);
		mu.unlock();
	}
}

int main(){
	thread t1(func1);
	thread t2(func2);
	t1.detach();	//detach�����̴߳��������з���,��������,�����������߳� 
	t2.detach();	//join���������߳�,���߳�ִ�����ż���ִ�����߳� 
	
	system("pause");
}
