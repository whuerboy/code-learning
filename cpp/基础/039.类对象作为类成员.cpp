#include<iostream>
#include<string.h>
using namespace std;

//一个类对象作为本类成员时，在构造时先构造类的对象，再构造本类的对象；
//在析构时则时本类先析构后另类析构

class Phone {
public:
	string pname;
	Phone(string name) :pname(name) {
		cout << "Phone的构造函数的调用" << endl;
	} 
	~Phone() {
		cout << "phone析构函数的调用" << endl;
	}
};

class Man {
public:
	string name;
	Phone phone;

	Man(string name, string pname) :name(name), phone(pname) {
		cout << "man的构造函数的调用" << endl;
	}

	~Man() {
		cout << "man的析构函数的调用" << endl;
	}
};

void test00() {

	Man p("张三", "ipone ");
	cout << "人名是 " << p.name << endl;
	cout << "手机是 " << p.phone.pname << endl;
}

int main39() {

	test00();
	return 0;
}