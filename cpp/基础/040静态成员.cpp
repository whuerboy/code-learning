#include<iostream>
using namespace std;

//��̬��Ա���������ж�����һ������,�ڱ���׶η����ڴ棬�������������ʼ��
//��̬��Ա������ĳ�����������ַ��ʷ�ʽ��ͨ��������ʻ���ͨ���������з���
//��̬��Ա����ͬ���з���Ȩ��

//��̬��Ա���������ж�����ͬһ��������ֻ�ܷ��ʾ�̬�ĳ�Ա����

class Person {
public:
	static int a;
	static void funcc() {
		a = 10000;
		cout << "��̬�����ĵ���" << endl;
		//c = 100;���ɷ���
	}
	void funbb() {
		funb();
	}

private:
	static int b;
	int c;
	void funb() {
		cout << a + b << endl;
	}

};

int Person::a = 100;
int Person::b = 1000;
int main40() {
	
	Person p1, p2;
	cout << "p1��a��  " << p1.a << endl;
	p2.a = 200;
	cout << "p1��a��  " << p1.a << endl;
	Person::a = 300;
	cout << "p1��a��  " << p1.a << endl;
	//Person::b = 2000;�������������
	p1.funcc();
	Person::funcc();
	cout << "p1��a��  " << p1.a << endl;
	p1.funbb();
	return 0;
}