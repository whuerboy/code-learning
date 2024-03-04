#include<iostream>
using namespace std;

template <class  T1,class T2>
class Person {
public:
	Person(T1 name, T2 age) :name(name), age(age) {}
	void show() {
		cout << "���֣�" << this->name << "   age:" << this->age << endl;
	}
	T1 name;
	T2 age;
};

//���ִ��뷽ʽ��
//1.ָ����������--ֱ����ʾ�������������
void printPerson1(Person<string, int>& p) {
	p.show();
}

//2.����ģ�廯--�������еĲ�����Ϊģ����д���
template <class T1,class T2>
void printPerson2(Person<T1, T2>& p) {
	p.show();
	cout << "T1��������  " << typeid(T1).name() << endl;
	cout << "T2��������  " << typeid(T2).name() << endl;//��ȡģ���ڸò����µ���������
}



//3.������ģ�廯--�������������ģ�廯���д���
template <class T>
void printPerson3(T& p) {
	p.show();
	cout << "T���������ͣ� " << typeid(T).name() << endl;
}




int main58() {
	Person<string, int>p("sb", 18);
	printPerson1(p);
	cout << endl << endl;
	Person<string, int>p1("dsb", 188);
	printPerson2(p1);
	Person<string, int>p2("cjdsb", 1888);
	cout << endl << endl;
	printPerson3(p2);
	return 0;
}