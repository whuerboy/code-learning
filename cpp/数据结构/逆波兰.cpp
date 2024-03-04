#include<iostream>
#include<fstream>
#include<stack>
#include <string>
#include<vector>


//逆波兰：首先第一个容易忽略的就是逆波兰表达式中的元素可能是负数，如果这样的话那就应该以字符串的方式读取文件的数据最好

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
		std::cout << "该文件不存在" << std::endl;
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