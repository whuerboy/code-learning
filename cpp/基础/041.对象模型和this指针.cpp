#include<iostream>
using namespace std;

//在c++中类中的成员变量和成员函数分开储存
//只有非静态成员变量才属于类的对象上面,每个非静态成员函数只会生成一份函数实例
//也就是说对各同类型的对象共用一块代码，而通过this指针来区分多个对象对函数的调用
//this指针指向被调用的成员函数所属的对象

//this指针的用途：
//当形参和成员变量同名时，用this来区分（解决名称冲突）
//返回对象本身  return *this;

//this指针不能修改指向

class Person {
public:
	Person(double mage) {
		this->age = mage;
	}
	int age;

	Person() {

	}

	Person& addAge(Person &p) //要用引用类型，否则一旦调用一次该函数都会创建一个新的对象
	{
		this->age += p.age;
		return *this;//返回对象本体
	}

};

int main41(void){
	Person p1(10);
	cout << "p1的年龄  " << p1.age << endl;
	
	Person p2(20);
	cout << "p2的年龄是  " << p2.age << endl;
	p2.addAge(p1);
	cout << "p2的年龄是  " << p2.age << endl;
	p2.addAge(p1).addAge(p1).addAge(p1);
	cout << "p2的年龄是  " << p2.age << endl;
	return 0;
	

}