#include<iostream>
using namespace std;
//��Щ���������������Ҫ���廯�ķ���ʵ��
class Person {
public:
	string name;
	int age;
	Person(string name, int age);
};

Person::Person(string name, int age) {
	this->age = age;
	this->name = name;
}


template<class T>
bool myCompare(T& a, T& b) {
	if (a == b) {
		return true;
	}
	else return false;
}


//���þ��廯��Person�汾��ʵ�ֺ���ģ��
template<> bool myCompare(Person &p1, Person &p2) {
	if (p1.age == p2.age && p1.name == p2.name) {
		return true;
	}
	else return false;
}




int main56() {

	int a = 10, b = 20;
	bool is =myCompare<int>(a, b);
	if (is) {
		cout << "���" << endl;
	}
	else cout << "�����" << endl;


	Person p1("˧��", 10);
	Person p2("˧��", 11);
	bool is2 = myCompare(p1, p2);
	if (is2) {
		cout << "���" << endl;
	}
	else cout << "�����" << endl;
	return 0;
}