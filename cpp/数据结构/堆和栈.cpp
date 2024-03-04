#include<iostream>
//堆和栈都是内存ram中真实存在的区域
//进行内存分配时堆和栈的分配方式是不一样的
//超出作用域之后栈上建立的变量的内存全部被回收，而堆上的要自己手动释放或者等到程序结束

int main18() {
	int value;//在栈上开辟4个字节的内存储存value的值
	value = 5;
	int array[5];
	array[0] = 1;
	array[1] = 2;
	array[2] = 3;
	array[3] = 4;
	array[4] = 5;


	int* hvalue = new int;//在堆上开辟空间
	*hvalue = 5;
	int* harray = new int[5];
	harray[0] = 1;
	harray[1] = 2;
	harray[2] = 3;
	harray[3] = 4;
	harray[4] = 5;
	delete hvalue;
	delete harray;
	hvalue = NULL;
	harray = NULL;
	return 0;
}