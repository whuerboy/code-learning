#include<iostream>
#include<fstream>//文件流
#include<string>
using namespace std;
ofstream ofs;//创建流对象，可以写文件
ifstream ifs;//读文件

//程序运行时产生的数据都属于临时数据，程序一旦结束就会被释放
//通过对文件操作可以将数据持久化
//文件类型：文本文件（以文本的AscII码形式存储在计算机中），二进制文件

 //操作文件三大类：ofstream（写操作） ifstream(读文件)  fstream(读写)

int main52() {

	//指定文件打开方式：
	ofs.open("通讯录.txt", ios::out);

	//往文件中写内容：
	ofs << "姓名：张三" << endl;
	ofs << "性别：男" << endl;
	ofs << "年龄：18" << endl;

	//关闭文件：
	ofs.close();

	ifs.open("通讯录.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "文件打开失败" << endl;
	}
	else {
		//读数据：
		// 第一种方法：
		//char buf[1024] = { 0 };//存放数据的数组
		//while (ifs >> buf)//将读到的数据放入数组中
		//{
		//	cout << buf << endl;
		//}


		//第二种方法：
		/*char buf[1024] = { 0 };
		while (ifs.getline(buf, sizeof(buf))) {
			cout << buf << endl;
		}*/

		 
		//第三种方法：
			string buf;
		while (getline(ifs, buf)) {
			cout << buf << endl;
		}

		//第四种方法：
		//char c;
		//while ((c = ifs.get()) != EOF) //EOF:文件的尾部
		//{
		//	cout << c;
		//}


	}
	ifs.close();

	return 0;

}

