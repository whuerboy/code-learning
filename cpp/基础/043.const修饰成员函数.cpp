#include<iostream>
using namespace std;

//const修饰成员函数，就是常函数
//常函数中不能修改成员属性
//成员属性在声明时加关键字mutable后，可以在常函数中修改

//常对象：
//常对象只能调用常函数和常对象,不能调用普通成员函数

class Person {
public:
	void showPerson() const //此时：this指针指向的值也不可以被修改
	{
		age = 100;
	}

	mutable	int age;
	int num;

};

int main43(void) {
	const Person p;
	p.age = 1000;
	
	//p.num = 100;不可修改
	return 0;
}

