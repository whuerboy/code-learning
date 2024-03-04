#include<iostream>
using namespace std;
//构造函数用于对象的初始化，析构函数用于对象的清理
//构造函数没有返回值，也不要写void，同时函数名和类名一样
//析构函数： 不能有参数，无返回值也没有void，函数名前面有个 ~
//构造函数的分类：有参数和无参数，普通构造和拷贝构造
//当用户没有定义构造函数和拷贝构造函数还有析构函数时，编译器会为用户提供


//拷贝构造函数的类型：浅拷贝和深拷贝
//c++的初始化有两种方法：利用构造函数或初始化列表
//初始化列表语法: 构造函数（）：属性1（属性值），.... ，属性n（属性值）
//C++中规定了父类的成员属性只能用父类的构造函数初始化。


class Person {
public:
	//构造函数
	Person() {
		cout << "person 无参数构造函数的调用" << endl;
	}

	//初始化列表
	Person(int m,int*n) :age(m), height(n) {

	}

	Person(int a,int hight) {

		height = new int(hight);//开辟了一个堆区的数据
		cout << "有参数构造函数构造" << endl;
		age = a;

	}

	//拷贝构造函数:
	Person(const Person &p)//把一个人的数据拷贝给另一个人
	{
		//将传入人的所有属性都拷贝
		age = p.age;
		//深拷贝操作：
		height = new int(*p.height);

		cout << "拷贝构造函数的调用" << endl; 
	}


	//析构函数:不可以有函数参数。也就是说不能重载,对象在销毁前会调用析构函数，且只调用一次
	~Person() {

		//将堆区的数据释放
		if (height != NULL) {
			delete height;
			height = NULL;
		}
		cout << "person 析构函数的调用" << endl;
	}
	int getage()
	{
		return age;
	}

	int getH() {
		return *height;
	}
	int* height;//身高

private:
	int age;
	
};

//构造函数的调用：
void test04() {
	//括号法：

	Person p1;//默认构造函数调用,此时不用加（）
	//Person p1()   如果这样写，编译器会认为这是一个函数的声明
	
	Person p2(10,160);//有参数构造函数调用,此时是浅氏构造函数
	Person p3(p2);

	cout << "p2的年龄位 " << p2.getage() << endl;
	cout << "p3的年龄位 " << p3.getage() << endl;
	cout << "p2的身高为 " << p2.getH() << endl;
	cout << "p3的身高为 " <<  *p3.height<< endl;

}


void test05() {

	////显示法调用构造函数：
	Person p1;
	Person p2 = Person(100,180);
	Person p3 = Person(p2);

	Person(10,190);//匿名对象，特点：当前语句执行完后对象被释放
	cout << "aaa" << endl;

	//注意：不要用拷贝函数初始化匿名对象
	//Person(p3)--->Person p3  会发生重复定义


	//隐式构造函数:

	Person p4 = { 10,100 };//相当于Person p4 =Person (10);
	Person p5 = p4;//拷贝构造
}

void dowork(Person p) //以值传递的方式给函数参数传值，会调用拷贝函数
{

}

Person dowork2() //以返回值的形式调用构造函数
{
	Person p1;
	return p1;
}

void test06() {
	Person p1 = dowork2(); //当调用返回值为对象的函数时，并未按预想地调用复制构造函数

	//当调用返回值为对象的函数时，系统消耗调用复用构制构造函数、调造函数、调用析构函数的代价，
	// 为了减少消耗，编译器使用了一项名为返回值优化的技术，
	//使得调用函数时不需要调用复制构造函数
	//优化过程：编译器偷偷地增加了一个参数，传入了p的地址，直接在函数内部构造了p对象

}


int main38()
{
	Person p1;
	cout << "你好" << endl;
	p1.height = new int(10);
	Person p2(p1);
	cout << "p1的身高为 " << *p1.height << endl;
	cout << "p2的身高为 " << *p2.height << endl;
	//浅拷贝会造成堆区内存重复释放
	Person p(10,190);
	cout << "p的身高 " << *p.height << endl;


	return 0;
}