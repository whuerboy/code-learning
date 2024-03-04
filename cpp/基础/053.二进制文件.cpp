#include<iostream>
#include<fstream>
using namespace std;
//以二进制的方式对文件进行读写操作时打开方式指定为： 
//ios::binary
//二进制方式写文件主要利用流对象调用函数write
//二进制方式不仅可以写内置数据类型如int，还可以写自定义数据类型

class Person {
public:
	char name[64];//尽量少用字符串
	int age;
};


int main53() {

	//创建流对象：
	ofstream ofs;
	//ofstream ofs("person.txt", ios::out | ios::binary)
	
	//打开文件：
	ofs.open("person.txt", ios::out | ios::binary);

	//写文件：
	Person p = { "张三",18 };
	ofs.write((const char*)&p,sizeof(Person));

	//关闭文件：
	ofs.close();





	//二进制读文件：
	ifstream ifs;
	ifs.open("person.txt", ios::in | ios::binary);
	if (!ifs.is_open()) {
		cout << "文件打开失败" << endl;
	}
	else {
		Person p1;
		ifs.read((char*)&p1, sizeof(Person));
		cout << "姓名： " << p1.name << "  年龄:  " << p1.age << endl;
	}

	ifs.close();


	return 0;
}
