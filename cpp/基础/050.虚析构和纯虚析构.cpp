#include<iostream>
using namespace std;

//��̬��ʹ��ʱ����������������Կ��ٵ���������ô����ָ�����ͷ�ʱ�޷����õ��������������
//����������������е�����������Ϊ��������������
//����д�����������ô�������ǳ�����
//����������������ͬ����Ҫ�����ʵ��
class Animal {
public:
	Animal() {
		cout << "animal��zao��������" << endl;
	}
	virtual ~Animal() {
		cout << "animal������������" << endl;
	}
	virtual void speak() = 0;
};

class Cat1:public Animal {
public:
	Cat1(string name) {
		cout << "cat���캯������" << endl;
		this->name = new string(name);
	}

	void speak() {
		cout <<*name<< "Сè��˵��" << endl;
	}

	~Cat1() {
		if (name != NULL) {
			delete name;
			name = NULL;
			cout << "cat������������" <<endl;
		}
	}

	string *name;
};

int main50() {
	Animal *a = new Cat1("��ķ");//�����е�ָ��������ʱ����������������������������ڴ�й¶����ʱ��Ҫ�Ѹ�����������������
	a->speak();
	delete a;

	return 0;
}



