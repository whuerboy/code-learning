#include<iostream>
//����ջ�������ı�����һ��������ͻᱻ����

int* creatArray() {
	/*int a[50];
	return a;*///��ʵ����Ǵ���ģ�û���ڶ��Ϸ����ڴ棬�ں���ִ�����ᱻ���ٲ��ᱻ���أ�ֻ�������������ܳ����Żᱻ�޸ĳɿ���
	int* a = new int[50];
	return a;
}

class person {
private:
	std::string name;
public:
	person(std::string name) :name(name) {
		std::cout << "���캯������" << std::endl;
	}
	~person() {
		std::cout << "������������" << std::endl;
	}
};

class personstr {
private:
	person* p;
public:
	personstr(person* const p) :p(p) {

	}
	~personstr() {
		delete p;
	}
};


int main13() {
	{
		person* p1 =new person(std::string("С��"));
		//�ڶ����洴���ı�����ʹ����������Ҳ���ᱻ����;
		personstr p = new person("С��");//personstr��ʹ���ڶ��ϵĳ�Ա�����ǳ�����ΧҲ�ᱻǿ�����٣���Ϊ������������
		
	}
	int* a = creatArray();
	delete a;
	
	return 0;
}