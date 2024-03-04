#include<stdio.h>
enum color { red, yellow, green,numcolors };
int main3(void)
{
	//枚举是用户定义的数据类型，用关键字enum来定义
	//  enum 枚举类型名字{名字0，名字1 。。。。。名字n};
	//只能是int，且从0开始，而且是常量，不能修改
	//声明枚举时可以指定值
	//enum color{red = 1,green = 5,numcolor};

	int color = -1;
    int t = red;
    printf("%d\n", t);//enum 其实可以看成int
	char* colornames[numcolors] = { "red","yellow","green" };//还有一个“/0”
	char* colorname = NULL;//搞一个空字符串
	printf("请输入你喜欢的颜色代号:");
	scanf_s("%d", &color);
	if (color >= 0 && color < numcolors) {
		colorname = colornames[color];
	}
	else colorname = "unknow";

	printf("你喜欢的颜色是%s\n", colorname);


	return 0;
}