#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int main3() {
	char data_write[100];
	
	ofstream ofs("small-speak.txt",ios::app);
	cout << " 开始输入文件数据 " << endl;
	cin.getline(data_write, 100);
	ofs << data_write << endl; 
	ofs.close();

	return 0;
}