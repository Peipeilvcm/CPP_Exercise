#include<iostream>

using namespace std;

template<class T>
class Stack{
private:
	Struct Node{
		T v;
		Node *next;
		Node(T _v, Node* n): v(_v), next(n){ }
	};
	Node *topPtr;
	int size;
	
public:
	Stack();
	~Stack();
	
	T top();
	void push(T t);
	void pop();
	int getSize();
};

template <class T>
Stack<T>::Stack(){
	size=0;
}
template<class T>
int Stack<T>::getSize(){
	return size;
}

template<class T>
T Stack<T>::top(){
	if(size > 0){
		return topPtr->v;
	}else{
		//exception
	}
}

template<class T>
void push(T t){
	Node* newN = new Node(t, NULL);
	newN->next = topPtr;
	topPtr = newN;
	++size;
}

template<class T>
T Stack<T>::pop(){
	if(size > 0){
		Node* temp = top;
		topPtr = topPtr->next;
		T t(temp->v);
		--size;
		delete  temp;
		return t;
	}else{
		//exception
	}
}
