#include<iostream>
#include<string.h>
using namespace std;

//һ���������Ϊ�����Աʱ���ڹ���ʱ�ȹ�����Ķ����ٹ��챾��Ķ���
//������ʱ��ʱ��������������������

class Phone {
public:
	string pname;
	Phone(string name) :pname(name) {
		cout << "Phone�Ĺ��캯���ĵ���" << endl;
	} 
	~Phone() {
		cout << "phone���������ĵ���" << endl;
	}
};

class Man {
public:
	string name;
	Phone phone;

	Man(string name, string pname) :name(name), phone(pname) {
		cout << "man�Ĺ��캯���ĵ���" << endl;
	}

	~Man() {
		cout << "man�����������ĵ���" << endl;
	}
};

void test00() {

	Man p("����", "ipone ");
	cout << "������ " << p.name << endl;
	cout << "�ֻ��� " << p.phone.pname << endl;
}

int main39() {

	test00();
	return 0;
}