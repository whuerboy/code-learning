//string 的本质是一个类#
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void test()//string类的构造函数：
{
	string s1;//空构造函数，创建一个空的字符串
	const char* str = "I Love You";
	string s2(str);//带参数的构造函数
	cout << "s2 = " << s2 << endl;
	string s3(4, 'o');//构造函数
	cout << "s3 = " << s3 << endl;
	string s4(s2);//拷贝构造函数
	cout << "s4 =  " << s4 << endl;

}

void test12()//string赋值
{
	string str1 = "hello world";//string& operator+(const char* s);
	string str2 = str1;//string& operator=(const string &s);
	string s3;
	s3 = 'a';//string& operator=(const char c);
	string s4;
	s4.assign("what up");//string& assign(const char* s);
	string s5;
	s5.assign("you're a shit", 5);//把字符串的前五位赋值
	cout << str1 << "  " << str2 << "  " << s3 << "  " << s4 << "  " << s5 << "  " << endl;

}


void test3()//字符串拼接
{
	string s1 = "我";
	s1 += "爱你";
	cout << "s1 = " << s1 << endl;
	string s3;
	s3.append("you love me");
	cout << "s3 = " << s3<< endl;

}


void text4()//单个字符操作
{
	string s1 = "hello lover";
	for (int i = 0; i < s1.size(); i++) {
		cout << s1[i] <<endl;
	}

	for (int i = 0; i < s1.size(); i++) {
		cout << s1.at(i) << " ";
	}
}


void test5() //字串获取
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