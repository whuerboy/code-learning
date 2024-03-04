#include<iostream>
using namespace std;
class Base{
public:
	Base() {
		cout << "base的构造函数调用" << endl;
	}
	~Base() {
		cout << "base 的析构函数调用" << endl;
	}

};

class Son :public Base {
public:
	Son() {
		cout << "son的构造函数调用" << endl;
	}
	~Son() {
		cout << "son的析构函数调用" << endl;
	}
};

int main47() {

	Son s1;//先构造父类，在构造子类，先析构子类，再析构父类

	return 0;
}