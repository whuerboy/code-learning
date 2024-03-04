#include<iostream>
//多返回值可以通过返回数组，结构体，字符串的形式返回而不能直接返回
// 如果是返回两个参数可以返回pair或者元组tuple
//也可以通过引用传递作为参数的方法直接传回参数
struct name {
	int in;
	int out;
};

name adddan(int n) {
	return { n,2 * n };
}

int main17() {
	int in;
	int out;
	std::cin >> in;
	name n = adddan(in);
	std::cout << n.in << std::endl;
	std::cout << n.out << std::endl;
	return 0;
}