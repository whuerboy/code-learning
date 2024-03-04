#include<iostream>
using namespace std;

template<class nt,class at=int> 
class Person {
public:
	nt name;
	at age;
	Person(nt name, at age) {
		this->age = age;
		this->name = name;
	}

	void fun1() {
		name.func();//不知道什么东西，但是没有调用就没有创建
	}
};

//注意，类模板中的成员函数不会一开始就创建出来，只有调用时才创建



int main57() {
	Person<string> p1("帅哥", 10);
	cout << p1.name << endl;
	cout << p1.age << endl;
	return 0;
}