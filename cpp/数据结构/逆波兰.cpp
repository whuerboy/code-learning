#include<iostream>
#include<fstream>
#include<stack>
#include <string>
#include<vector>


//�沨�������ȵ�һ�����׺��Եľ����沨�����ʽ�е�Ԫ�ؿ����Ǹ�������������Ļ��Ǿ�Ӧ�����ַ����ķ�ʽ��ȡ�ļ����������

double getReast(std::vector<std::string> text) {
	std::stack<int> number;
	for (std::string content : text) {
		
		if (content == "+" || content == "-" || content == "*" || content == "/") {
			int a = number.top(); number.pop();
			int b = number.top(); number.pop();
			char op =content.c_str()[0];
			switch (op)
			{
			case '+':
			{number.push(a + b); break; }
			case '-':
			{number.push(b - a); break; }
			case '*':
			{number.push(a * b); break; }
			case '/':
			{number.push(b / a); break; }
			default:
				break;
			}
		}
		else
		{
			number.push(atoi(content.c_str()));
		}
	}

	return number.top();
}

int main25() {
	std::fstream ifs;
	ifs.open("in.txt");
	if (!ifs) {
		std::cout << "���ļ�������" << std::endl;
	}
	std::vector<std::string> text;
	std::string read;
	while(!ifs.eof()){
		std::getline(ifs, read, ',');
		text.push_back(read);
	}
	std::cout << getReast(text);
	return 0;
}