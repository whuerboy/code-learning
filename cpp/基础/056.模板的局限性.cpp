#include<iostream>
using namespace std;
//有些特殊的数据类型需要具体化的方法实现
class Person {
public:
	string name;
	int age;
	Person(string name, int age);
};

Person::Person(string name, int age) {
	this->age = age;
	this->name = name;
}


template<class T>
bool myCompare(T& a, T& b) {
	if (a == b) {
		return true;
	}
	else return false;
}


//利用具体化的Person版本来实现函数模板
template<> bool myCompare(Person &p1, Person &p2) {
	if (p1.age == p2.age && p1.name == p2.name) {
		return true;
	}
	else return false;
}




int main56() {

	int a = 10, b = 20;
	bool is =myCompare<int>(a, b);
	if (is) {
		cout << "相等" << endl;
	}
	else cout << "不相等" << endl;


	Person p1("帅哥", 10);
	Person p2("帅哥", 11);
	bool is2 = myCompare(p1, p2);
	if (is2) {
		cout << "相等" << endl;
	}
	else cout << "不相等" << endl;
	return 0;
}