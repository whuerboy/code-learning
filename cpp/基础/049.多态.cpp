#include<iostream>
using namespace std;

//��̬����̬��̬�;�̬��̬
//��̬��̬������������
//�м̳й�ϵ,������д������麯������������ͬ����ֵ��ͬ������ͬ��

//��̬��̬��ʹ�ã������ָ���������ָ���������

class Animal {
public:
	virtual void speak() {
		
	}
};

class Cat :public Animal{
	void speak() {
		cout << "Сè��˵��" << endl;
	}
};

//ִ��˵���ĺ���
//��ַ���   �ڱ���׶�ȷ�������ĵ�ַ
//�����ִ����è˵����ô��������ĵ�ַ������ǰ�󶨣�Ҫ�����еĽ׶��ڽ��а�
void doSpeak(Animal& animal) {
	animal.speak();
}

class Dog:public Animal {
	void speak() {
		cout << "����" << endl;
	}
};




//��̬����1���������ࣺʵ��������������������


//��ͨд����
class Calculator1 {
public:
	int getResult(string oper) {
		if (oper == "+") {
			return num1 + num2;
		}
		else if (oper == "-") {
			return num1 - num2;
		}
		else if (oper == "*") {
			return num1 * num2;
		}
		else if(oper == "/") {
			return num1 / num2;
		}

		//�����Ҫ��չ�µĹ��ܣ���Ҫ�޸�Դ��
		//��ʵ�ʿ����У�����չ���п��������޸Ľ��йر�
	}

	int num1;
	int num2;

};


//��̬��Դ��:

class Calulator2 //�����࣬�޷�ʵ�����������������д���麯��������Ҳ�޷�ʵ����
{
public:
	static int num1;
	static int num2;
	virtual int getResult() = 0;//���麯��
};
int Calulator2::num1 = 1000;
int Calulator2::num2 = 10;

//�ӷ���������
class Add :public Calulator2 {
public:
	int getResult(){
		return num1 + num2;
	}
};

class Del :public Calulator2 {
public:
	int getResult() {
		return num1 - num2;
	}
};

class Cheng :public Calulator2 {
public :
	int getResult() {
		return num1 * num2;
	}
};


int doCalulate(Calulator2* c) {
	return c->getResult();
}


//��̬�����ĺô���
//��֯�ṹ�������ֹ���ȷ���ɶ���ǿ




int main49() {
	/*Cat cat;
	doSpeak(cat);
	Dog dog;
	doSpeak(dog)*/

	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	Calculator1 c;
	c.num1 = 100;
	c.num2 = 10;
	cout << c.num1 << "+" << c.num2 <<"=" << c.getResult("+") << endl;
	cout << c.num1 << "-" << c.num2 << "=" << c.getResult("-") << endl;
	cout << c.num1 << "*" << c.num2 << "=" << c.getResult("*") << endl;
	cout << c.num1 << "/" << c.num2 << "=" << c.getResult("/") << endl;
	cout << endl;
	cout << "*******************" << endl<<endl;

	Calulator2 *abc = new Add;
	
	cout << abc->num1 << "+" << abc->num2 << "=" << abc->getResult() << endl;
	delete abc;
	abc = new Del;
	
	cout << abc->num1 << "-" << abc->num2 << "=" << abc->getResult() << endl;
	delete abc;
	abc = new Cheng;
	
	cout << abc->num1 << "*" << abc->num2 << "=" << abc->getResult() << endl;


	return 0;
}