#include<iostream>
using namespace std;

//静态成员变量：所有对象共享一份数据,在编译阶段分配内存，类内声明类外初始化
//静态成员不属于某个对象，有两种访问方式：通过对象访问或者通过类名进行访问
//静态成员变量同样有访问权限

//静态成员函数：所有对象共享同一个函数，只能访问静态的成员变量

class Person {
public:
	static int a;
	static void funcc() {
		a = 10000;
		cout << "静态函数的调用" << endl;
		//c = 100;不可访问
	}
	void funbb() {
		funb();
	}

private:
	static int b;
	int c;
	void funb() {
		cout << a + b << endl;
	}

};

int Person::a = 100;
int Person::b = 1000;
int main40() {
	
	Person p1, p2;
	cout << "p1的a是  " << p1.a << endl;
	p2.a = 200;
	cout << "p1的a是  " << p1.a << endl;
	Person::a = 300;
	cout << "p1的a是  " << p1.a << endl;
	//Person::b = 2000;不可在类外访问
	p1.funcc();
	Person::funcc();
	cout << "p1的a是  " << p1.a << endl;
	p1.funbb();
	return 0;
}