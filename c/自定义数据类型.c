#include<stdio.h>
int main8(void)
{//typedef 声明新的类型的名字，新名字是某种类型的别名
	typedef int len;//此时int的别名就是len
	len i = 0;
	 
	typedef struct adata {
		len x;
		len y;
	}date;//此时date 是 struct adata 的别名
	date date1 = { 1,2 };//下次声明结构变量时就不用再麻烦了


	return 0; 
}