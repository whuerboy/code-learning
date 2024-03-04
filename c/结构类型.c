#include<stdio.h>
//一个结构就是复合的数据类型
struct date {
	int month;
	int day;
	int year;
};//不要漏分号
//此时所有函数都可以使用，不然就是本地变量

int main4(void)
{
	struct date today = { 11,20,2022 };
	//today.day = 20;
	//today.month = 11;
	//today.year = 2022;
	struct date month = { .month = 22,.year = 2022 };//此时其余默认0
	 



	return 0;
}