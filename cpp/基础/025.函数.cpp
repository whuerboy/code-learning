#include"hanshu.h"
#include<iostream>
using namespace std;
//附加特别说明：本文件的函数尽可能放在这

//函数的默认值：
//如果某个参数已经有默认值，那么这个参数往后的参数都应该要有参数值
//如果函数的声明有默认参数值，那么函数的实现不能有默认值.声明和实现只能有一个有默认参数
int add(int a, int b = 20, int c=30){
	return a + b + c;

}

//函数在形参列表中可以有占位参数：
void func(int) {
	cout << "   " << endl;
}


//当函数重载遇到默认参数时有可能会出现二义性

int main25() {


	int a, b;
	cin >> a >> b;
	swap(a, b);
	cout << "a的值是 " << a << endl;
	cout << "b的值是 " << b << endl;
	swap(&a, &b);
	cout << "a的值是 " << a << endl;
	cout << "b的值是 " << b << endl;
	
	change2(a);
	 
	int c = add(a);
	int d = add(a, b);
	func(10);
	func(a);


	return 0;
}