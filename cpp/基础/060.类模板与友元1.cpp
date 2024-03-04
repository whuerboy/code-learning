#include<iostream>
using namespace std;

template<class T1, class T2>
class Person;
//友元函数类外实现：
template<class T1, class T2>
void outing2(Person<T1, T2>& p) {
	cout << "name= " << p.name << "  age= " << p.age << endl;
}

template<class T1, class T2>
class Person {
	//全局函数 类内实现
	friend void outing(Person<T1, T2>& p) {
		cout << "name= " << p.name << "  age= " << p.age << endl;
	}


	//友元函数的类外实现，要加一个空的阿参数列表告诉编译器这是一个函数模板,而且要让编译器提前知道该函数的存在
	friend void outing2<>(Person<T1, T2>& p);

public:
	
	Person(T1 name, T2 age);
	void out();
private:
	T1 name;
	T2 age;
};




 //成员函数的类外实现:
 template<class T1, class T2>
 Person<T1, T2>::Person(T1 name, T2 age) {
	 this->age = age;
	 this->name = name;
 }




template<class T1, class T2>
void Person<T1, T2>::out() {
	cout << "name= " << this->name << "  age= " << this->age << endl;
}




int main61() {
	Person<string, int>a("hao", 1997);
	cout << "函数2：";
	outing2(a);
	cout << "函数1: ";
	Person<int, int>b(11, 1100);
	outing(b);

	return 0;
}