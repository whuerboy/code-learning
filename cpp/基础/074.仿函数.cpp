#include<iostream>
#include<string>
using namespace std;

//�����������غ������ò��������࣬������Ϊ��������Ҳ�зº�����������һ����
//���������ڵ���ʱ��������ͨ�����������ã������в����ͷ���ֵ
//��������������Լ���״̬Ҳ��������
//�������������Ϊ��������

class MyPrint1 {
public:
	void operator()(string test) {
		cout << test << endl;
		this->count++;
		cout << "count = " <<this->count << endl;
	}

	int count;
	MyPrint1() {
		this->count = 0;
	}
};

int main74() {
	MyPrint1 myPrint;
	cout << "Myprint���ô���Ϊ " << myPrint.count << endl;
	myPrint("hello my boy");
	myPrint("hello my boy");
	myPrint("hello my boy");
	myPrint("hello my boy");
	cout << "Myprint���ô���Ϊ " << myPrint.count << endl;
	return 0;
}