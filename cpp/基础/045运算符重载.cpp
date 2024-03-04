#include<iostream>
using namespace std;
//加号运算符重载：

//通过成员函数重载：
class Person1 {
public: 
	int a = 0, b = 0;
	int* age;
	Person1 operator+(Person1& p) {
		Person1 temp;
		temp.a = this->a + p.a;
		temp.b = this->b + p.b;
		return temp;
	}

	Person1() {

	}

	Person1(int age) {
		this->age = new int(age);//在堆区开辟空间
	}


	~Person1() {
		if (age != NULL) {
			delete age;
			age = NULL;
		}
	}
	


	//前置递增运算符重载：
		Person1& operator++ () {
			++a, ++b;
			return *this;
	}

	//后置递增运算符重载：
		Person1 operator++(int)//后置递增返回值而不是引用，因为temp在函数执行完后会被释放，再返回就是非法操作
		{
			//先：记录当时的结果
			Person1 temp = *this;

			//再：递增
			this->a++;
			this->b++;

			//后：返回当时结果

			return temp;
		}

	
		Person1& operator=(Person1& p);


};

//全局函数重载：
//Person operator+(Person& p1, Person& p2) {
//	Person temp;
//	temp.a = p1.a + p2.a;
//	temp.b = p1.b+ p2.b;
//	return temp;
//}



//左移运算符重载：一般不会用成员函数重载左移运算符，这样做不到cout,<的形式
ostream& operator<<(ostream &cout, Person1 p)//这里注意person之所以不用引用是因为后置++返回值是一个全新的类而不是引用
{
	cout << "a = " << p.a << endl;
	cout <<"b =  " << p.b << endl;
	return cout;//可以达到cout<< p <<p<<endl;的目的
}

 
//赋值运算符重载：当类中出现指针类型的属性时，若没有自己构建一个新的拷贝函数，则也可以通过重载赋值运算符来操作

Person1&  Person1::operator=(Person1& p) {
	if (this->age != NULL) {
		delete this->age;
		this->age = NULL;
	}
	this->age  = new int(*p.age);//深拷贝

	return *this;

}

//关系运算符重载：==  !=
bool operator==(Person1& p1, Person1& p2) {
	if (*p1.age == *p2.age) {
		return true;
	}
	else return false;
}


//函数调用运算符重载：函数运算符（）也可以重载，十分灵活，没有固定的形式
//也称为仿函数

class MyPrint {
public:

	void operator()(string text) {
		cout << text << endl;
	}


};

class Printfln {
public:
	void operator()(string test) {
		cout << test << endl;
	}

};



int main45() {
	//Person p1, p2,p3;
	//p1.a = 10, p1.b = 10;
	//p2.a = 20, p2.b = 20;
	//p3 = p1 + p2;
	//cout << "p3.a = " << p3.a << endl;
	//cout << p3<<endl;//配合友元可以出其不意
	//cout << ++(++p3)<<endl;
	//cout << p3 << endl;
	//cout << p3++ << endl;
	//cout << p3 << endl;
	//Person p4 = p3++;
	//cout << p3 << endl;
	//cout << p4 << endl;




	/*Person1 p1(18);
	cout << "p1的年龄为 " << *p1.age << endl;
	Person1 p2(20);
	cout << "p2的年龄为 " << *p2.age << endl;
	p2 = p1;
	
	cout << "p2的年龄为 " << *p2.age << endl;
	Person1 p3;
	p3 = p2 = p1;
	cout << "p3的年龄为" << *p3.age << endl;

	if (p3 == p1) {
		cout << "两者年龄相同" << endl;
	}
	else cout << "两者年龄不同" << endl;*/


	MyPrint m1;
	m1("hello world");//仿函数
	Printfln()("hello world");//匿名对象直接使用成员函数



	

	return 0;
}