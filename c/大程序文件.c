#include<stdio.h>

int max(int a, int b);
//此时我在此声明有一个这样的函数，而且这个函数的代码就在该文件夹下，那么也可以使用，但是注意仍然只能有一个main函数存在
  //c语言在同一个源文件夹下函数名不可以相同，否则就不能起这样的作用
int main17(void)
{	
    int a = 10, b = 12;
    int c = max(a, b);
    printf("%d\n", c);
    int d = h();//h（）函数在静态本地变量的文件中，但是其中的main函数不能起作用，因此不影响
    printf("%d\n", d);

	 return 0;
}