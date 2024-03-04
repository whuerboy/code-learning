#include<iostream>
using namespace std;
int main29() {
	//1.const修饰指针 ：常量指针 
	//特点：指针指向可以改，但是指针指向的值不能改
	int m = 10;
	const int* p = &m;
	
	
	
	cout << *p << endl;
	int n = 100;
	p = &n;//是指向的值不能改变，但是如果后面指向的地址的内容和原本指向地址的内容不同是可以的 
	cout << *p << endl;
	//“指向常量的指针”可以改变指向。
	//*p = 20; 会报错
	//“指向常量的指针”不可以通过解引用改变指向的数值。
	//“指向常量的指针”所指向的数据，可以通过改变被指向的变量进行改变。（没有修饰符的那种）
	n = 1000;
	cout << "当n的改变时指针p的指向的值为 " << *p << endl;


	//2.const修饰常量：指针常量：
	//指针的指向不可以改，但是指向的值可以改
	int* const p2 =&m;
	//p2 = &m;初始化后不可改
	cout << "未改变前m的值是" << m << endl;
	*p2 = 1000;
	cout << "此时m的值是 " << m << endl;

	//const同时修饰指针和常量：
	const int* const p3 = &n;
	//指针的指向和指针指向的值都不能改.
	//*p3 = 1000;
	//p3 = &m;  都会报错
	cout << "n的地址是 " << &n << endl;
	cout << "p3的地址是" << p3<<endl;
	cout << "p3指向的值是 " << *p3<<endl;

	

	return 0;
}