#include<iostream>
#include<string>
#include<ctime>//���ڴ������������
using namespace std;


struct student {
	string name;
	int scores;
};

struct teacher {
	string name;
	student stu[5];
};

//����ʦ��ѧ����ֵ�ĺ���:
void creatvalue(teacher t[], int len) {

	string nameseed = "ABCDEFG";
	//����ʦ��ֵ
	for (int i = 0; i < len; i++)
	{
		t[i].name = "Teacher_";
		t[i].name += nameseed[i];

		//����ʦ����ѧ����ֵ:
		for (int j = 0; j < 5; j++) {
			t[i].stu[j].name = "Student_";
			t[i].stu[j].name += nameseed[j];
			t[i].stu[j].scores = 60;
		}
	}

}

//��ӡ���е���Ϣ��
void printTea(teacher t[], int len) {
	for (int i = 0; i < len;i++) {
		cout << "��ʦ������  " << t[i].name << endl;
		for (int j = 0; j < 5; j++) {
			cout << "\tѧ��������  " << t[i].stu[j].name;
			int random = rand() % 100;//
			t[i].stu[j].scores = random;
			cout << "  ѧ���ĳɼ�  " << t[i].stu[j].scores;
			cout << endl;

		}
	}
	

}



int main34(){

	//���������
	srand((unsigned int)time(NULL));
	
	//������ʦ������:
	teacher tea[3];

	//ͨ����������ʦ��ֵ��
	int len = sizeof(tea) / sizeof(tea[0]);//������ʦ�Ľṹ���������Ԫ�صĸ���
	creatvalue(tea, len);

	//��ӡ������Ϣ��
	printTea(tea, len);




	return 0;
}