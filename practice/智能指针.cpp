//C++11智能指针
//shared_ptr,unique_ptr,weak_ptr

#include<iostream>
#include<memory>
using namespace std;

class Child;
class Parent;

class Parent{
private:
	weak_ptr<Child> ChildPtr;
public:
	void setChild(shared_ptr<Child> child){
		this->ChildPtr = child;
	}
	void do{
		if(this->ChildPtr.lock()){
		
		}
	}
	~Parent(){
	}
};

class Child{
private:
	shared_ptr<Parent> ParentPtr;
public:
	void setParent(shared_ptr<Parent> parent){
		this->Parent = parent;
	}
	void do{
		if(this->ParentPtr.use_count()){
		}
	}
	~Child(){
	}
}

int main(){
	weak_ptr<Parent> wpp;
	weak_ptr<Child> wpc;
	{
		shared_ptr<Parent> p(new Parent());
		shared_ptr<Child> c(new Child());
		p->setChild(c);
		c->setParent(p);
		wpp = p;
		wpc = c;
		cout<<p.use_count()<<endl;//2
		cout<<c.use_count()<<endl;//1
	}
}

#include <iostream>
#include <memory>

template<typename T>
class SmartPointer {
private:
    T* _ptr;
    size_t* _count;
public:
    SmartPointer(T* ptr = nullptr) :
            _ptr(ptr) {
        if (_ptr) {
            _count = new size_t(1);
        } else {
            _count = new size_t(0);
        }
    }

    SmartPointer(const SmartPointer& ptr) {
        if (this != &ptr) {
            this->_ptr = ptr._ptr;
            this->_count = ptr._count;
            (*this->_count)++;
        }
    }

    SmartPointer& operator=(const SmartPointer& ptr) {
        if (this->_ptr == ptr._ptr) {
            return *this;
        }

        if (this->_ptr) {
            (*this->_count)--;
            if (this->_count == 0) {
                delete this->_ptr;
                delete this->_count;
            }
        }

        this->_ptr = ptr._ptr;
        this->_count = ptr._count;
        (*this->_count)++;
        return *this;
    }

    T& operator*() {
        assert(this->_ptr == nullptr);
        return *(this->_ptr);

    }

    T* operator->() {
        assert(this->_ptr == nullptr);
        return this->_ptr;
    }

    ~SmartPointer() {
        (*this->_count)--;
        if (*this->_count == 0) {
            delete this->_ptr;
            delete this->_count;
        }
    }

    size_t use_count(){
        return *this->_count;
    }
};

int main() {
    {
        SmartPointer<int> sp(new int(10));
        SmartPointer<int> sp2(sp);
        SmartPointer<int> sp3(new int(20));
        sp2 = sp3;
        std::cout << sp.use_count() << std::endl;
        std::cout << sp3.use_count() << std::endl;
    }
    //delete operator
}