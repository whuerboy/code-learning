//string �ı�����һ����#
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void test()//string��Ĺ��캯����
{
	string s1;//�չ��캯��������һ���յ��ַ���
	const char* str = "I Love You";
	string s2(str);//�������Ĺ��캯��
	cout << "s2 = " << s2 << endl;
	string s3(4, 'o');//���캯��
	cout << "s3 = " << s3 << endl;
	string s4(s2);//�������캯��
	cout << "s4 =  " << s4 << endl;

}

void test12()//string��ֵ
{
	string str1 = "hello world";//string& operator+(const char* s);
	string str2 = str1;//string& operator=(const string &s);
	string s3;
	s3 = 'a';//string& operator=(const char c);
	string s4;
	s4.assign("what up");//string& assign(const char* s);
	string s5;
	s5.assign("you're a shit", 5);//���ַ�����ǰ��λ��ֵ
	cout << str1 << "  " << str2 << "  " << s3 << "  " << s4 << "  " << s5 << "  " << endl;

}


void test3()//�ַ���ƴ��
{
	string s1 = "��";
	s1 += "����";
	cout << "s1 = " << s1 << endl;
	string s3;
	s3.append("you love me");
	cout << "s3 = " << s3<< endl;

}


void text4()//�����ַ�����
{
	string s1 = "hello lover";
	for (int i = 0; i < s1.size(); i++) {
		cout << s1[i] <<endl;
	}

	for (int i = 0; i < s1.size(); i++) {
		cout << s1.at(i) << " ";
	}
}


void test5() //�ִ���ȡ
{
	string s1 = "1825176761@qq.com ";
	int pos = s1.find("@");

	string s2 = s1.substr(0, pos);
	cout << "s2 = " << s2 << endl;

}


int main64() {
	text4();
	cout << endl;
	test5();
	return 0;
}