#include<iostream>
#include<fstream>
using namespace std;
//�Զ����Ƶķ�ʽ���ļ����ж�д����ʱ�򿪷�ʽָ��Ϊ�� 
//ios::binary
//�����Ʒ�ʽд�ļ���Ҫ������������ú���write
//�����Ʒ�ʽ��������д��������������int��������д�Զ�����������

class Person {
public:
	char name[64];//���������ַ���
	int age;
};


int main53() {

	//����������
	ofstream ofs;
	//ofstream ofs("person.txt", ios::out | ios::binary)
	
	//���ļ���
	ofs.open("person.txt", ios::out | ios::binary);

	//д�ļ���
	Person p = { "����",18 };
	ofs.write((const char*)&p,sizeof(Person));

	//�ر��ļ���
	ofs.close();





	//�����ƶ��ļ���
	ifstream ifs;
	ifs.open("person.txt", ios::in | ios::binary);
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ��" << endl;
	}
	else {
		Person p1;
		ifs.read((char*)&p1, sizeof(Person));
		cout << "������ " << p1.name << "  ����:  " << p1.age << endl;
	}

	ifs.close();


	return 0;
}
