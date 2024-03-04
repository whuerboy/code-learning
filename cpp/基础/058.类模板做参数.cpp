#include<iostream>
using namespace std;

template <class  T1,class T2>
class Person {
public:
	Person(T1 name, T2 age) :name(name), age(age) {}
	void show() {
		cout << "名字：" << this->name << "   age:" << this->age << endl;
	}
	T1 name;
	T2 age;
};

//三种传入方式：
//1.指定传入类型--直接显示对象的数据类型
void printPerson1(Person<string, int>& p) {
	p.show();
}

//2.参数模板化--讲对象中的参数变为模板进行传递
template <class T1,class T2>
void printPerson2(Person<T1, T2>& p) {
	p.show();
	cout << "T1的类型是  " << typeid(T1).name() << endl;
	cout << "T2的类型是  " << typeid(T2).name() << endl;//获取模板在该参数下的数据类型
}



//3.整个类模板化--将这个对象类型模板化进行传递
template <class T>
void printPerson3(T& p) {
	p.show();
	cout << "T的数据类型： " << typeid(T).name() << endl;
}




int main58() {
	Person<string, int>p("sb", 18);
	printPerson1(p);
	cout << endl << endl;
	Person<string, int>p1("dsb", 188);
	printPerson2(p1);
	Person<string, int>p2("cjdsb", 1888);
	cout << endl << endl;
	printPerson3(p2);
	return 0;
}