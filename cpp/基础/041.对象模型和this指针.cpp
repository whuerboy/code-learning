#include<iostream>
using namespace std;

//��c++�����еĳ�Ա�����ͳ�Ա�����ֿ�����
//ֻ�зǾ�̬��Ա������������Ķ�������,ÿ���Ǿ�̬��Ա����ֻ������һ�ݺ���ʵ��
//Ҳ����˵�Ը�ͬ���͵Ķ�����һ����룬��ͨ��thisָ�������ֶ������Ժ����ĵ���
//thisָ��ָ�򱻵��õĳ�Ա���������Ķ���

//thisָ�����;��
//���βκͳ�Ա����ͬ��ʱ����this�����֣�������Ƴ�ͻ��
//���ض�����  return *this;

//thisָ�벻���޸�ָ��

class Person {
public:
	Person(double mage) {
		this->age = mage;
	}
	int age;

	Person() {

	}

	Person& addAge(Person &p) //Ҫ���������ͣ�����һ������һ�θú������ᴴ��һ���µĶ���
	{
		this->age += p.age;
		return *this;//���ض�����
	}

};

int main41(void){
	Person p1(10);
	cout << "p1������  " << p1.age << endl;
	
	Person p2(20);
	cout << "p2��������  " << p2.age << endl;
	p2.addAge(p1);
	cout << "p2��������  " << p2.age << endl;
	p2.addAge(p1).addAge(p1).addAge(p1);
	cout << "p2��������  " << p2.age << endl;
	return 0;
	

}