#include<iostream>
using namespace std;

//const���γ�Ա���������ǳ�����
//�������в����޸ĳ�Ա����
//��Ա����������ʱ�ӹؼ���mutable�󣬿����ڳ��������޸�

//������
//������ֻ�ܵ��ó������ͳ�����,���ܵ�����ͨ��Ա����

class Person {
public:
	void showPerson() const //��ʱ��thisָ��ָ���ֵҲ�����Ա��޸�
	{
		age = 100;
	}

	mutable	int age;
	int num;

};

int main43(void) {
	const Person p;
	p.age = 1000;
	
	//p.num = 100;�����޸�
	return 0;
}

