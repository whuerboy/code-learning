#include<iostream>
using namespace std;

//�ڳ������Ԫ������һЩ����ĺ������������˽������
//��Ԫ������ʵ�֣�ȫ�ֺ�����Ԫ��������Ԫ����Ա��������Ԫ

class Gay;
class Building;//���������

class Goodgay;

class Gay {
public:
	Gay();//Ĭ�Ϲ��캯��
	void visit2();
	Building* building;
};


class Building {
	friend void Gay::visit2();//��Ա��������Ԫ
	friend class Goodgay;//������Ԫ������������Է��ʸ����е�˽�г�Ա
	friend void goodGay(Building* building);//ȫ�ֺ�������Ԫ

public:



	Building() {
		sittingroom = "����";
		bedroom = "����";
	}

	string sittingroom;//����
	

private:
	string bedroom;//����
};

//ȫ�ֺ���
void goodGay(Building* building) {
	cout << "�û���ȫ�ֺ������ڷ���:  " << building->sittingroom << endl;
	cout << "�û���ȫ�ֺ������ڷ���:  " << building->bedroom << endl;
}




class Goodgay {
public:
	Goodgay() {
		//����һ������
		building = new Building;
	}

	void visit1();
	Building* building;

};

void Goodgay::visit1() {
	cout << "�û��Ѷ������ڷ���  " << building->sittingroom << endl;
	cout << "�û��Ѷ������ڷ���  " << building->bedroom<< endl;
}


//��Ԫ��Ա������ʵ��
void Gay::visit2() {
	cout << "���Ѷ������ڷ���  " << building->sittingroom << endl;
	cout << "���Ѷ������ڷ���  " << building->bedroom << endl;

}

Gay::Gay() {
	building = new Building;
}






int main44() {

	Building building1;
	goodGay(&building1);//��ʱ���øú���ʱ����ͨ������ã���Ϊ���������������

	Goodgay goodgay;
	goodgay.visit1();

	delete goodgay.building;

	Gay gay;
	gay.visit2();
	delete gay.building;//��������

	return 0;
}