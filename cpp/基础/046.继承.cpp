#include<iostream>
using namespace std;
//�̳еĻ����﷨:
//class ����(������): �̳з�ʽ  ����(����)
//�̳з�ʽ�������̳У������̳У�˽�м̳�




//�̳�ҳ��ʵ�֣�
class BasePage {
public:
	static int j;
	int m_a;
	BasePage() {
		m_a = 100;
	}
	void header() {
		cout << "��ҳ�������Σ���¼��ע�ᡣ����������ͷ����" << endl;
	}

	void footer() {
		cout << "Java Python C++ C# C...." << endl;
	}

	void line() {
		cout << "-----------------------------------" << endl;
	}

	void func() {
		cout << "base��Ա�����ĵ���" << endl;
	}

	void func(int a) {
		cout << "base(int) �ĵ���" << endl;
	}


protected:
	int m_b;
private:
	int m_c;

};

int BasePage::j = 200;

class Base {
public:
	int a;
	Base() {
		a = 100;
	}
};



//�����̳�:
class Son1 :public BasePage {
public:
	void func() {
		m_a = 10;//�����й������Ա�ܷ���
		m_b = 20;//�����еı�����Ա�ܷ���
	}
};


//�����̳У�
class Son2 :protected BasePage {
public:
	void func() {
		m_a = 100;
		m_b = 1000;//����������ɱ���Ȩ�ޣ��޷������ⵥ������
	}
};



//˽�м̳У�
class Son3 :private BasePage {
public:
	void func() {
		m_a = 1000;
		m_b = 10000;//��ʱ����˽�г�Ա
	}
};

class Son4:public Son3 {
public:
	void func() {
		//m_a = 100;  �޷�����
	}

};


//�������븸�����ͬ���ĳ�Ա
class Son :public BasePage {
public:
	static int j;
	int m_a;
	Son() {
		m_a = 200;
	}

	void func() {
		cout << "son��Ա�����ĵ���" << endl;
	}

};
int Son::j = 100;

//��̳У���̳��п�������������ͬ����Ա�ĳ��֣���Ҫ��������

class BigSon :public Base, public BasePage {
	BigSon() {
		a = 1000;
		m_a = 100;
	}
};



int main46(){
	Son s;
	cout << "(Son)m_a = " << s.m_a << endl;
	cout << "(Base)m_a = " << s.BasePage::m_a << endl;
	s.func();
	s.BasePage::func();
	//s.func(10);����
	//��������г��ֺ͸���ͬ���ĳ�Ա�����������ͬ����Ա�����ص����������е�ͬ����Ա����
	//ֻ��ͨ��������������
	s.BasePage::func(10);

	//ͨ����ֱ�ӷ��ʾ�̬���ݣ�
	cout << "base�� j = " << BasePage::j << endl;
	cout << "son �� j = " << Son::j << endl;
	cout << "ͨ��son����base�� j = " << Son::BasePage::j << endl;

	return 0;
}