#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<ios>
using namespace std;

int main2() {
	string file_path = "small-speak.txt";
	fstream input;
	string data_in_file;
	vector<string> file_data;
	input.open(file_path,ios::out||ios::in);
	if (!input) {
		cout << "文件不存在" << endl;
	}
	while (!input.eof()) {
		getline(input, data_in_file);
		file_data.push_back(data_in_file);
	}
	for (vector<string>::iterator it = file_data.begin(); it != file_data.end(); it++) {
		cout << *it << endl;//当输出有出现中文乱码时，可能是txt文件的保存类型出现问题，修改即可
	}
	input.close();
	return 0;
}