#include<iostream>
#include<string>
using namespace std;

//函数对象：重载函数调用操作符的类，其对象称为函数对象，也叫仿函数，本质是一个类
//函数对象在调用时可以像普通函数那样调用，可以有参数和返回值
//函数对象可以有自己的状态也就是属性
//函数对象可以作为参数传递

class MyPrint1 {
public:
	void operator()(string test) {
		cout << test << endl;
		this->count++;
		cout << "count = " <<this->count << endl;
	}

	int count;
	MyPrint1() {
		this->count = 0;
	}
};

int main74() {
	MyPrint1 myPrint;
	cout << "Myprint调用次数为 " << myPrint.count << endl;
	myPrint("hello my boy");
	myPrint("hello my boy");
	myPrint("hello my boy");
	myPrint("hello my boy");
	cout << "Myprint调用次数为 " << myPrint.count << endl;
	return 0;
}