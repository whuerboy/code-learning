#include<iostream>
#include<string>
#include<string>
using namespace std;


//ְ�����ࣺ��ͨԱ���������ϰ�
//����ϵͳ�Ĺ��ܣ��˳������������ְ����ɾ��ְ������ʾְ�����޸�ְ��������ְ����������������
//ְ�������ԣ���ţ����������ű��

//�����ࣺ
class Manager {
public: 
	Manager();
	
	~Manager();//����

	void showMenu();

	void outManager();

};

Manager::Manager() {
	cout << "hello";
}

Manager::~Manager() {
	cout << "hello";
}

 void  Manager::showMenu(){

	cout << "*********************************" << endl;
	cout << "******��ӭ����ְ������ϵͳ*******" << endl;
	cout << "*********0.�˳�����ϵͳ**********" << endl;
	cout << "*********1.����ְ����Ϣ**********" << endl;
	cout << "*********2.��ʾְ����Ϣ**********" << endl;
	cout << "*********3.ɾ����ְְ��**********" << endl;
	cout << "*********4.�޸�ְ����Ϣ**********" << endl;
	cout << "*********5.����ְ����Ϣ**********" << endl;
	cout << "*********6.���ձ������**********" << endl;
	cout << "*********7.��������ĵ�**********" << endl;
	cout << "*********************************" << endl;

}

void Manager::outManager() {
	
	cout << "��ӭʹ��ְ������ϵͳ" << endl;
	system("pause");
	exit(0);//��������

}


//ְ�������ࣺ
class Worker {
public:
	//��ʾ������Ϣ��
	void virtual showPerson() = 0;

	//��ȡ��λ��

	string virtual getWorkName() = 0;


	int id;//ְ�����
	string name;//ְ������
	int workId;


};


//��ְͨ���ࣺ

class Employee :public Worker {
public:
	//���캯����

	Employee(int id, string name, int workID)
	{
		this->id = id;
		this->name = name;
		this->workId = workID;
	}


	//��ʾ������Ϣ��
	void virtual showPerson();

	//��ȡ��λ��

	string virtual getWorkName();

};

string Employee::getWorkName() {
	return string("��ͨԱ��");
}

void Employee::showPerson(){
	cout << "ְ����ţ� " << this->id << "\tְ�������� " << this->name << "\t ��λ" << this->getWorkName() << endl;


}



//�����ࣺ
class Managerperson :public Worker {
public:
	Managerperson(int id, string name, int did) {};

};




//int main() //���Ժ�������
//{
//	Worker* worker = NULL;
//	worker = new Employee(1, "zhangsan", 1);
//	worker->showPerson();
//
//}


int main54() {
	Manager m;
	
	int select;//��¼ѡ��
	
	while (true) {
		m.showMenu();
		cout << "����������ѡ��" << endl;
		cin >> select;
		if (cin.good())//���ڼ���ǲ�������
		{
			
				switch (select)
				{
				case 1://����ְ����Ϣ
					break;

				case 2://��ʾְ����Ϣ
					break;

				case 3://ɾ����ְְ����Ϣ
					break;

				case 4://�޸�ְ����Ϣ
					break;

				case 5://����ְ����Ϣ��
					break;

				case 6://���������
					break;

				case 7://��������ĵ�
					break;


				case 0://�˳�����ϵͳ
					m.outManager();//��������

				default:
					cout << "�޸�ѡ�����������" << endl;
					system("pause");
					system("cls");
					break;
				}

			
			
		}

		else {
			cout << "�������������������������" << endl;
			cin.clear();
			while (cin.get() != '\n')
				continue;
			system("pause");
			system("cls");
			
		}

	}
	

}


