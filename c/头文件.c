#include<stdio.h>
#include "max.h"
//在源文件夹下建立一个  .h 的头文件，里面有对函数max的声明
//那么在别的代码中我们只需要引入头文件即可，不用对函数再声明
//我们甚至可以再头文件里面直接构造函数然后引入(特别注意)
//include 是编译预处理指令，在编译前就完成了，所以位置不一定在开头

//在.c文件中声明函数时前面加上static会使该函数变成局部函数，即只能在所在的编译单元中使用
//全局变量前加上static也是如此
int main18(void)

{
    int a = 12, b = 13;
    int c = max(a, b);
    extern int g ;//c语言可以使用在别的文件中定义的非static的全局变量，不过要加上extern,而且只允许一个.c文件对全局变量赋初始值
    printf("%d\n", c);
    printf("%d\n", g);
    g = 13;

    printf("%d\n", g);
    return 0;
}
