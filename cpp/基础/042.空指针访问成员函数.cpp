#include<iostream>
using namespace std;

class Person {
public:
	void showClassName() {
		cout << "this is Person class" << endl;
	}
	void showAge() {
		cout << "������  " << this->age << endl;
	}

	int age;
};

int main42() {
	Person* p = NULL;//��ָ���޷���������
	if (p == NULL)//��ߴ���Ľ�׳�ԣ���ֹ�ܵ��ƻ�
	{
		return 0;
	}
	else
	p->showClassName();

	return 0;


}