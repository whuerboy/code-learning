#include<iostream>
#include"hanshu.h"
#include<string>
#include <algorithm>
using namespace std;
#define MAX  1000 
//ͨѶ¼�Ĺ��ܣ������ϵ�ˣ���ʾ��ϵ�ˣ�ɾ����ϵ�ˣ�������ϵ�ˣ��޸���ϵ�ˣ������ϵ�ˣ��˳�ͨѶ¼
//�����ϵ�˵ķ�����������ϵ�˵Ľṹ�壬ͨѶ¼�Ľṹ��...
struct person {
	string name;
	int sexy;//�Ա� 1.��  2.Ů
	int age;
	string phonenum;
	string address;
};
struct tongxunlu {
	struct person p[MAX];//��ϵ������
	int m_size;//ͨѶ¼��ǰ��¼������
};

//�����ϵ�˵��û�
void  addperson(struct tongxunlu* book) {
	//�ж�ͨѶ¼�Ƿ�����
	if (book->m_size == MAX) {
		cout << "ͨѶ¼����������,�޷����" << endl;
	}
	else {
		int now = book->m_size;//����һ�����������ص�ǰ����
		//�����ϵ��:
		//name:
		string name;
		cout << "��������ϵ�˵����ƣ� " << endl;
		cin >> name;
		book->p[now].name = name;
		//�Ա�:
		cout << "�������Ա�\n 1.��   2.Ů" << endl;

		int sexy = 0;
		while (true) {
			cin >> sexy;
			if (sexy == 1 || sexy == 2) //������� 1 . 2������������ֱ����Ϊֹ
			{
				book->p[now].sexy = sexy;
				break;
			}
			else {
				cout << "������������������" << endl;
			}
		}
		
		//���䣺
		cout << "�������û�������:" << endl;
		int age;
		cin>>age;
		book->p[now].age = age;

		//��ϵ�绰:
		cout << "��������ϵ�绰" << endl;
		string num;
		cin >> num;
		book->p[now].phonenum = num;

		//סַ
		cout << "�������ͥסլ" << endl;
		string address;
		cin >> address;
		book->p[now].address = address;

		//����ͨѶ¼������
		book->m_size++;
		cout << endl<<"��ϵ����ӳɹ�" << endl;

		system("pause");//�����������
		system("cls");//����
	}

}


//��ʾ��ϵ�˵ĺ�����
void showperson(tongxunlu* book) {
	//�ж�ͨѶ¼�������Ƿ�Ϊ0��
	if (book->m_size == 0) {
		cout << "��ǰ����ϵ��" << endl;
	}

	else {
		for (int i = 0; i < book->m_size; i++) {
			cout << "����:  " << book->p[i].name << "\t"; 
			cout << "�Ա� " << (book->p[i].sexy ==1?"��":"Ů") << "\t";
			cout << "�绰:  " << book->p[i].phonenum << "\t";
			cout << "���䣺 " << book->p[i].age << "\t";
			cout << "סַ:  " << book->p[i].address << endl;
		}

	}
	system("pause");//�����������
	system("cls");//����
}


//��ʾ��ϵ���Ƿ���ڵĺ�����������ڣ�������ϵ���������ڵľ���λ�ã��粻�ڷ���-1
int isExist(tongxunlu* book,string name) 
{
	for (int i = 0; i < book->m_size; i++) {
		if (book->p[i].name == name)//��ʱ�ҵ���
		{
			return i;
		}
	}
	cout << "����Ҫ�ҵ���ϵ�˲�����" << endl;
	
	//system("pause");//�����������
	//system("cls");//����
	return -1;//��������궼û���ҵ�������-1
}

//��ӡ��������ϵ�˵ĺ�����
void findPerson(tongxunlu* book, int person) {
	if (person == -1) {
		cout << "�����ҵ���ϵ�˲�����" << endl;
	}
	else {
		cout << "����Ҫ������ϵ�˵���Ϣ����:" << endl;
		cout << "������ " << book->p[person].name << "\t";
		cout << "�Ա� " << (book->p[person].sexy == 1 ? "��" : "Ů") << "\t";
		cout << "�绰:  " << book->p[person].phonenum << "\t";
		cout << "���䣺 " << book->p[person].age << "\t";
		cout << "סַ:  " << book->p[person].address << endl;
	}
	system("pause");//�����������
	system("cls");//����

}

//����һ���޸���ϵ�˵Ķ����
void changePerson(tongxunlu* book, int person) {
	
	if (person != -1) {
		int choice = 1;
		cout << "ѡ����Ҫ�޸ĵ��б�1��������\t2.���Ա�\t3.����ϵ��ʽ\t4.������\t5.��סַ\t0.�޸����" << endl;
		while (choice != 0)
		{
			cin >> choice;
			switch (choice)
			{
			case 1:	cout << "�������޸ĺ���ϵ�˵������� " << endl;
				cin >> book->p[person].name;
				break;
			case 2:	cout << "�������޸ĺ���ϵ�˵��Ա�(1.��   2.Ů ) " << endl;
				cin >> book->p[person].sexy;
				break;
			case 3:	cout << "�������޸ĺ���ϵ�˵ĵ绰: " << endl;
				cin >> book->p[person].phonenum;
				break;
			case 4:	cout << "�������޸ĺ���ϵ�˵�����: " << endl;
				cin >> book->p[person].age;
			case 5:	cout << "�������޸ĺ���ϵ�˵�סַ: " << endl;
				cin >> book->p[person].address;
				break;

			}

			if (choice != 0) { cout << "�����������Ҫ�޸ĵ���Ϣ�� "; }//�������һ�ε���׸���
			continue;
		}
		cout << endl << "�޸����!" << endl;
	}
	
	system("pause");//�����������
	system("cls");//����
}


//ɾ����ϵ�˵ĺ���:
void deleteperson(tongxunlu* book, int person) {

	if (person != -1) //�ж���Ҫ�ҵ���ϵ���Ƿ����
	{
		 //���ҵ��˺�ֱ�ӽ������ݵĸ��ǣ���ɾ���Ĺ��ܣ��˾ٲ�����
		for (int i = person; i < book->m_size; i++) {
			//����ǰ�Ʋ�����
			book->p[i] = book->p[i+ 1];
		}
		book->m_size--;//����ͨѶ¼�е�����
		cout << "ɾ���ɹ�" << endl;
	}
	system("pause");//�����������
	system("cls");//����
}


	//�����ϵ�ˣ���ͨѶ¼��������ϵ��ȫ��ɾ��
	//ʵ��˼·����ͨѶ¼�е�������ϵ�˵���Ϣ�����ֻ��Ҫ����ͨѶ¼����ϵ�������ɣ����߼���ա����������Լ���ʹ�ø�����
	//�������ֱ��������鱾�壬���ٴ������ϵ��ʱ��ԭ�������齫�޷�ʹ��
void cleanperson(tongxunlu* book) {
	book->m_size = 0;//������ϵ����
	cout << "ͨѶ¼�Ѿ����" << endl;
	system("pause");//�����������
	system("cls");//����
	 
}

//ʵ�ֲ˵����ܣ�
//����һ����װ����.

int main35(){
	tongxunlu book;
	book.m_size = 0;
	int select;
	char y = 'Y', n = 'N';//����ȷ������
	int person;//���ڶ�λ��ϵ�˵�����λ��
	string name;//���ڲ��ң�ɾ��,�޸���ϵ��
	cout << "��ӭʹ��ͨѶ¼" << endl;
	while (true) {
		showMenu();//��ʾ�˵�		
		cout << "��������Ĳ���" << endl;	
		cin >> select;
			if (cin.good()) {//���ڼ���������Ƿ�����������
				if (select == 0 || select == 1 || select == 2 || select == 3 || select == 4 || select == 5 || select == 6) {
					switch (select) {
					case 1://�����ϵ��
						addperson(&book);
						break;
					case 2://��ʾ��ϵ��
						cout << "��������ʾͨѶ¼�����ϵ��" << endl;
						showperson(&book);
						break;
					case 3: //ɾ����ϵ��
						cout << "����������Ҫɾ������ϵ��" << endl;
						//ɾ����ϵ������Ҫ�����ϵ���Ƿ����
						cin >> name;
						person = isExist(&book, name);//������Ƿ���ڣ�������ھͶ�λ
						deleteperson(&book, person);

						break;
					case 4://������ϵ��
						cout << "��������Ҫ���ҵ���ϵ��" << endl;
						cin >> name;
						person = isExist(&book, name);//�������Ƿ����
						findPerson(&book, person);					
						break;
					case 5://�޸���ϵ��
						cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
						cin >> name;
						person = isExist(&book, name);
						changePerson(&book, person);
						break;
					case 6://�����ϵ��
						cout << "�Ƿ�ȷ�������ϵ��" << endl;
						char YorN;
						cin >> YorN;
						if (toupper(YorN) == y) {
							cleanperson(&book);
						}
						else if (toupper(YorN) == n) {
							cout << "δ�����κδ���" << endl;
							system("pause");//�����������
							system("cls");//����
						}
						break;
					case 0://�˳�ͨѶ¼
						cout << "��ӭ�´�ʹ��ͨѶ¼" << endl;
						system("pause");
						return 0;//���˴˲����޷�����whileѭ��
						break;

					default:
						break;

					}
				}
				else {
					cout << "�޸�ѡ�����������" << endl;
					system("pause");//�����������
					system("cls");//����
				}
			}
		else {
				cout << "�������������������,����������" << endl;
				cin.clear();//��������������ͱ��ж��д�ʱ��cin�����빦�ܻᱻ���á�����Ĵ���������������cin�����빦�ܡ�
				while (cin.get() != '\n')
					continue;
				system("pause");//�����������
				system("cls");//����
				
			}
	}
	return 0;

}