#include<iostream>
using namespace std;
int main30() {
	//����ָ�������������Ԫ��
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << "ֱ������������������ĵ�һ��Ԫ��  " << arr[0] << endl;
	int* p = arr;//arr����������׵�ַ
	cout << "����ָ������������ĵ�һ��Ԫ��  " << *p << endl;
	p++;
	cout << "����ָ�������ʵڶ���Ԫ�� " << *p << endl;
	//����ָ���������
	p = arr;
	for (int i = 0; i < 10; i++) {
		cout << "�� " << i + 1 << "��Ԫ�ص�ֵ�� " << *p << endl;
		p++;
	}





	return 0;
}