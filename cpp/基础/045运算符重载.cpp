#include<iostream>
using namespace std;
//�Ӻ���������أ�

//ͨ����Ա�������أ�
class Person1 {
public: 
	int a = 0, b = 0;
	int* age;
	Person1 operator+(Person1& p) {
		Person1 temp;
		temp.a = this->a + p.a;
		temp.b = this->b + p.b;
		return temp;
	}

	Person1() {

	}

	Person1(int age) {
		this->age = new int(age);//�ڶ������ٿռ�
	}


	~Person1() {
		if (age != NULL) {
			delete age;
			age = NULL;
		}
	}
	


	//ǰ�õ�����������أ�
		Person1& operator++ () {
			++a, ++b;
			return *this;
	}

	//���õ�����������أ�
		Person1 operator++(int)//���õ�������ֵ���������ã���Ϊtemp�ں���ִ�����ᱻ�ͷţ��ٷ��ؾ��ǷǷ�����
		{
			//�ȣ���¼��ʱ�Ľ��
			Person1 temp = *this;

			//�٣�����
			this->a++;
			this->b++;

			//�󣺷��ص�ʱ���

			return temp;
		}

	
		Person1& operator=(Person1& p);


};

//ȫ�ֺ������أ�
//Person operator+(Person& p1, Person& p2) {
//	Person temp;
//	temp.a = p1.a + p2.a;
//	temp.b = p1.b+ p2.b;
//	return temp;
//}



//������������أ�һ�㲻���ó�Ա�����������������������������cout,<����ʽ
ostream& operator<<(ostream &cout, Person1 p)//����ע��person֮���Բ�����������Ϊ����++����ֵ��һ��ȫ�µ������������
{
	cout << "a = " << p.a << endl;
	cout <<"b =  " << p.b << endl;
	return cout;//���Դﵽcout<< p <<p<<endl;��Ŀ��
}

 
//��ֵ��������أ������г���ָ�����͵�����ʱ����û���Լ�����һ���µĿ�����������Ҳ����ͨ�����ظ�ֵ�����������

Person1&  Person1::operator=(Person1& p) {
	if (this->age != NULL) {
		delete this->age;
		this->age = NULL;
	}
	this->age  = new int(*p.age);//���

	return *this;

}

//��ϵ��������أ�==  !=
bool operator==(Person1& p1, Person1& p2) {
	if (*p1.age == *p2.age) {
		return true;
	}
	else return false;
}


//����������������أ��������������Ҳ�������أ�ʮ����û�й̶�����ʽ
//Ҳ��Ϊ�º���

class MyPrint {
public:

	void operator()(string text) {
		cout << text << endl;
	}


};

class Printfln {
public:
	void operator()(string test) {
		cout << test << endl;
	}

};



int main45() {
	//Person p1, p2,p3;
	//p1.a = 10, p1.b = 10;
	//p2.a = 20, p2.b = 20;
	//p3 = p1 + p2;
	//cout << "p3.a = " << p3.a << endl;
	//cout << p3<<endl;//�����Ԫ���Գ��䲻��
	//cout << ++(++p3)<<endl;
	//cout << p3 << endl;
	//cout << p3++ << endl;
	//cout << p3 << endl;
	//Person p4 = p3++;
	//cout << p3 << endl;
	//cout << p4 << endl;




	/*Person1 p1(18);
	cout << "p1������Ϊ " << *p1.age << endl;
	Person1 p2(20);
	cout << "p2������Ϊ " << *p2.age << endl;
	p2 = p1;
	
	cout << "p2������Ϊ " << *p2.age << endl;
	Person1 p3;
	p3 = p2 = p1;
	cout << "p3������Ϊ" << *p3.age << endl;

	if (p3 == p1) {
		cout << "����������ͬ" << endl;
	}
	else cout << "�������䲻ͬ" << endl;*/


	MyPrint m1;
	m1("hello world");//�º���
	Printfln()("hello world");//��������ֱ��ʹ�ó�Ա����



	

	return 0;
}