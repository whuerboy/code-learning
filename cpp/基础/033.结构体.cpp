#include<iostream>
#include<string>
using namespace std;
//�ṹ������û����Զ�����������
//�﷨��
//struct �ṹ������ {�ṹ���Ա����};


//����ѧ������������

struct student {
	//��Ա�б����£�
	string name;
	string sexy;
	
};

//�ṹ��Ƕ��:
struct teacher {
	long long id;
	string name;
	struct student stu;

};

//�ṹ��������������
void printstu(student s1, teacher t1) {
	cout << "�ں����д�ӡѧ����������  " << s1.name << endl; 
	cout << "�ں����д�ӡ��ʦ�����ֺ�id" << endl;
	cout << "��ʦ������ " << t1.name << "��ʦid " << t1.id << endl;
	cout << "��ʦ��ѧ���� : " << t1.stu.name << endl;
}

void changestu1(student *s1) {
	cout << "ѧ��������" << s1->name << endl;
	cout << "���ĸ�ѧ��������" << endl;
	cin >> s1->name;
	cout << "������ѧ���� " << s1->name << endl;

}

void printstu2(const student* arr) {
	int i = 0;
	cout << "����";
	cout << "      �Ա�     " << endl;


	for (i; i < 3; i++) {
		cout << arr[i].name;
		cout << "      " << arr[i].sexy << endl;
	}
}//�������е��βθ�Ϊָ��ʱ���Լ����ڴ�ռ䣬���Ҳ��Ḵ�Ƴ��µĸ���

int main33() {
	//ͨ������������ʵ�����,��ʱ�����ʡ��struct

	 student s1;
	//��s1��ֵ��Ҫͨ�� . ������
	 s1 = { "zhangsan","nan" };
	s1.name = "����";
	s1.sexy = "��";
	cout  << "������ " << s1.name << endl;

	struct student s2 = {
		"����","��"
	};
	cout << s2.name << endl<<endl<<endl<<endl;

	//�ṹ������

	student arr[3] = { {"����","man"},{"����","man"},{"����","man"} };
	int i = 0;
	cout << "����" ;
	cout << "      �Ա�     " << endl;
	for (i; i < 3; i++) {
		cout << arr[i].name ;
		cout << "      " << arr[i].sexy << endl;

	}

	cout << endl << endl << endl << endl;
	//�ṹ��ָ�� ��ͨ��ָ����ʽṹ��

	student* p = arr;
	
	for (int j = 0; j < 3; j++) {
		cout << "������  " << p->name << "   ";
		p->sexy = "һ��������man";
		cout << "�Ա���   " << p->sexy << endl;
		p++;
	}

	//�ṹ��Ƕ��
	teacher t1 = {
	2022302111019,"��˧��",s1
	};
	cout <<t1.name<<"��ѧ���� " << t1.stu.name << endl;
	teacher* p2 = &t1;
	cout << p2->name << "��id�� " << t1.id << endl; 

	//�ṹ����Ϊ��������:
	cout << endl << endl << endl << endl;
	printstu(s1, t1);
	changestu1(&s1);
	cout << endl << endl;
	cout << "��ѧ�������������� " << s1.name << endl;

	printstu2(arr);


	//const��ʹ�ó�����
	//�ں�����ʹ��ָ����Ϊ�β�ʱ��const���Է�ֹ�����ʹ���������ݷ����仯��




	return 0;
}