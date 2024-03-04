#include<iostream>
#include"hanshu.h"
using namespace std;
//值传递
void change1(int n) {
    cout << "值传递--函数操作地址" << &n << endl;         //显示的是拷贝的地址而不是源地址 
    n++;
}

//引用传递
void change2(int& n) {
    cout << "引用传递--函数操作地址" << &n << endl;
    n++;
    //形参相当于是实参的“别名”，对形参的操作其实就是对实参的操作，
    // 在引用传递过程中，被调函数的形式参数虽然也作为局部变量在栈中开辟了内存空间
    //但是这时存放的是由主调函数放进来的实参变量的地址。
    // 被调函数对形参的任何操作都被处理成间接寻址，
    //即通过栈中存放的地址访问主调函数中的实参变量。
    //正因为如此，被调函数对形参做的任何操作都影响了主调函数中的实参变量。
}

//指针传递
void change3(int* n) {
    cout << "指针传递--函数操作地址 " << n << endl;
    *n = *n + 1;
    cout << "3函数里面的指针本身的地址是 " << &n<<endl;
    int m = 10;
    n = &m;//此处指针指向的地址发生变化
    cout << "当指针在函数中改变是指向的地址是 " << n<<endl;
    *n += 1000;
    //在函数中改变指针的指向不会影响主函数中指针的指向
    // 指针作为参数时，函数会创建一个新的指针，这个指针和参数指针的指向地址相同，但两者没有啥关系
}

int main31() {
    int n = 10;
    cout << "实参的地址" << &n << endl;
    change1(n);
    cout << "after change1() n=" << n << endl;
    cout << endl;


    change2(n);
    cout << "after change2() n=" << n << endl;
    cout << endl;


    int* m = &n;
    change3(m);
    cout << "调用函数3后主函数中原指针指定的地址为 " << m<<endl;
    //这一步想探究的是被调函数中指针指向变化时会不会影响主函数中原指针的指向
    
    cout << "主函数中的m指针的地址是 " << &m << endl;
    //由此可以看出被调函数中的指针与主调函数的指针并不是同一个指针
    //只是这两个指针指向同一个地址罢了
   
    cout << "after change3() n=" << n << endl;
    cout << "after change3() *m = " << *m << endl;
    return 0;
}