#include<stdio.h>

int h(void) {
	static int m = 0;
	printf("%d\n", m);
	m = m+ 2;
	printf("%d\n", m);
	return m;

}

int main15(void)
{
	//本地变量加上一个static时，在函数离开时静态本地变量会继续存在并保持其值，
	//静态本地变量的初始化只发生在第一次进入这个函数时，以后进入函数都会保持上次离开的值
	h();
	h();
	h();
	//返回本地变量的地址是危险的
	//返回全局变量和静态变量的地址是安全的
	//尽量不要使用全局变量来在函数传递参数和结果

	return 0;
}