#include<stdio.h>
//#开头的是编译预处理的处理指令
#define pi 3.14//定义一个符号 
//定义宏后面不用加分号
//C语言的编译器在开始编译之前会进行预处理，将程序中的名字换成值
#define pri "%d\n"

#define prt printf("hello\n");\
		printf("world\n")
//预先定义的宏
// _FILE_     _LINE_    _DATE_     _TIME_

//宏的定义可以带参数
#define cube(x) ((x)*(x)*(x))
//错误的宏定义如下   #define rad1(x)  (x*57.14)
//	#define  rad2(x) (x)*57.14 
//原因  一切都要有括号  ，整个值要有括号，参数出现的每个地方也要有括号
#define rad1(x) ((x)*57.12)

//宏也可以带多个参数
#define min(a,b) ((a)>(b)?(b):(a))


int main16(void)
{	
	int i = 0;
	printf(pri, i);
	prt;
	printf("%d\n", cube(5));
	printf("%0.2f\n", 180 / (rad1(1)));
	printf("%f\n", rad1(5));

	int x = 0, y = 1;
	int d =min(x, y);
	printf("%d", d);

	return 0;


}