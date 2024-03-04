//内存分配4个区域：
//代码区：存放函数体的二进制代码，由操作系统进行管理,(共享和只读)，类的成员函数也在这里
//全局区：存放全局变量和静态变量以及常量
//栈区：由编译器自动分配释放，存放函数的参数值，局部变量等(注意：不要返回局部变量的地址)
//堆区：由程序员自行分配和释放，若程序员不释放，程序结束由操作系统回收.利用new关键字可以将数据开辟到堆区
//不同的区域存放的数据，赋予不同的生命周期


#include<iostream>
using namespace std;

//创建全局变量：
int all_g = 10;
const int all_b = 10;

int* func() {
	//利用new关键字可以将数据开辟到堆区
	int	a = 10;
	int* p = new int(a);//指针本质也是一个局部变量，放在栈区上，但是指向的数据在堆区
	//new返回的是一个该数据类型的指针
	return p;
}

void test01() {
	int* p = func();
	cout << "test01中的 指针指向的值：" << *p << endl;
	
	//如果想释放堆区的中的数据，用delete
	delete p;
	//cout << "test01中的 指针指向的值：" << *p << endl;  此时再次访问已经没有访问权限了、
	

}

void test02() {
	//在堆区中开辟一个数组
	int* arr = new int[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = i + 100;
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
		delete[] arr;//释放数组时要加一个[]
	}

}


int main36() {

	//全局区：
	//创建普通局部变量：
	int a = 10, b = 10;
	cout << "局部变量a的地址是： " << &a << endl;
	cout << "局部变量b的地址是:  " << &b << endl;
	cout << "全局变量all_g的地址是:  " << &all_g << endl;
	//创建静态变量：
	static int jing = 10;
	cout << "静态变量jing的地址是  " << &jing << endl;

	//常量：
		//字符串常量：
	cout << "字符串常量的地址： " << &"hello" << endl;
		//const修饰变量:
			//const修饰的全局变量：
	cout << "全局常量的地址:  " << &all_b << endl;
			//const修饰的局部变量：
	const int c = 10;
	cout << "局部常量的地址：  " << &c << endl;//局域部常量的地址不在全局区中，和局部变量同一个区

	
	//堆区：
	int* p = func();
	cout << "*p的值是  " << *p << endl;
	cout << "*p的值是  " << *p << endl;
		
	//new的基本语法
	test01();
	test02();
	


	return 0;
}