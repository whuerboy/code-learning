#include<iostream>
using namespace std;

template<class T1,class T2>
class Person {
public:
	T1 name;
	T2 age;
	Person(T1 name, T2 age);
	void out();
};


//成员函数的类外实现:
template<class T1,class T2>
Person<T1, T2>::Person(T1 name, T2 age) {
	this->age = age;
	this->name = name;
}

template<class T1, class T2>
void Person<T1, T2>::out() {
cout << "name= " << this->name << "  age= " << this->age << endl;
}	

int main60() {
	Person<string, int>a("好", 18);
	a.out();
	return 0;
}