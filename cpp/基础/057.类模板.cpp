#include<iostream>
using namespace std;

template<class nt,class at=int> 
class Person {
public:
	nt name;
	at age;
	Person(nt name, at age) {
		this->age = age;
		this->name = name;
	}

	void fun1() {
		name.func();//��֪��ʲô����������û�е��þ�û�д���
	}
};

//ע�⣬��ģ���еĳ�Ա��������һ��ʼ�ʹ���������ֻ�е���ʱ�Ŵ���



int main57() {
	Person<string> p1("˧��", 10);
	cout << p1.name << endl;
	cout << p1.age << endl;
	return 0;
}