#include<iostream>
using namespace std;

template<class T1, class T2>
class Person;
//��Ԫ��������ʵ�֣�
template<class T1, class T2>
void outing2(Person<T1, T2>& p) {
	cout << "name= " << p.name << "  age= " << p.age << endl;
}

template<class T1, class T2>
class Person {
	//ȫ�ֺ��� ����ʵ��
	friend void outing(Person<T1, T2>& p) {
		cout << "name= " << p.name << "  age= " << p.age << endl;
	}


	//��Ԫ����������ʵ�֣�Ҫ��һ���յİ������б���߱���������һ������ģ��,����Ҫ�ñ�������ǰ֪���ú����Ĵ���
	friend void outing2<>(Person<T1, T2>& p);

public:
	
	Person(T1 name, T2 age);
	void out();
private:
	T1 name;
	T2 age;
};




 //��Ա����������ʵ��:
 template<class T1, class T2>
 Person<T1, T2>::Person(T1 name, T2 age) {
	 this->age = age;
	 this->name = name;
 }




template<class T1, class T2>
void Person<T1, T2>::out() {
	cout << "name= " << this->name << "  age= " << this->age << endl;
}




int main61() {
	Person<string, int>a("hao", 1997);
	cout << "����2��";
	outing2(a);
	cout << "����1: ";
	Person<int, int>b(11, 1100);
	outing(b);

	return 0;
}