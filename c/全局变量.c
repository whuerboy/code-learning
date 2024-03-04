#include<stdio.h>
//定义在函数外部的变量
int g = 12;
int f(void);//全局变量未初始化时系统自动赋值为0或null
//当函数内部有一个与全局变量同名的变量时，全局变量在该函数内会被隐藏

int main14(void) {
	printf(" main  g =%d\n", g);
	f();
	printf("   main g=%d\n", g);

	return 0;
}

int f(void) {
	printf(" f  g =%d\n", g);
	g++;
	printf(" f  g =%d\n", g);

	return g;
}