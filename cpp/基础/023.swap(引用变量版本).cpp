#include"hanshu.h"
#include<iostream>
using namespace std;





 void swap(int &m, int& n)//引用变量做参数可以是实参发生变化
 {

	 int a;
	 a = m;
	 m = n;
	 n = a;
	 cout << "交换成功" << endl;
	 
}