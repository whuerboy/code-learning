#include"hanshu.h"
#include<iostream>
using namespace std;
//�����ر�˵�������ļ��ĺ��������ܷ�����

//������Ĭ��ֵ��
//���ĳ�������Ѿ���Ĭ��ֵ����ô�����������Ĳ�����Ӧ��Ҫ�в���ֵ
//���������������Ĭ�ϲ���ֵ����ô������ʵ�ֲ�����Ĭ��ֵ.������ʵ��ֻ����һ����Ĭ�ϲ���
int add(int a, int b = 20, int c=30){
	return a + b + c;

}

//�������β��б��п�����ռλ������
void func(int) {
	cout << "   " << endl;
}


//��������������Ĭ�ϲ���ʱ�п��ܻ���ֶ�����

int main25() {


	int a, b;
	cin >> a >> b;
	swap(a, b);
	cout << "a��ֵ�� " << a << endl;
	cout << "b��ֵ�� " << b << endl;
	swap(&a, &b);
	cout << "a��ֵ�� " << a << endl;
	cout << "b��ֵ�� " << b << endl;
	
	change2(a);
	 
	int c = add(a);
	int d = add(a, b);
	func(10);
	func(a);


	return 0;
}