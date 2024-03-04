#include<iostream>
#include<vector>
#include<fstream>
#include<map>
	//接下来是打印：

void getResult(std::vector<char>text) {
	std::map<char, int> result;
	for (auto i : text) {
		result[i]++;
	}
	//打印：
	/*for (std::map<char, int>::iterator it = result.begin(); it != result.end(); it++)
	{
		std::cout << it->first << " " << it->second << " ";
	}*/
	for (auto i : text) {
		if (result[i] != 0) {
			if (result[i] == 1) {
				std::cout << i << " ";
			}
			else {
				if (result[i] > 9) {
					std::cout << i / 10 << " " << i % 10 << " ";
				}
				std::cout << i << " " << result[i] << " ";
			}

		result.erase(i);
		}

	}
}

int main035() {
	std::fstream fst;
	fst.open("in.txt",std::ios::in);
	std::vector<char> text;
	//while (fst.peek()!=EOF)
	//{
	//	
	//	char data;

	//	fst.get(data);
	//	if (data == ' ') {
	//		continue;
	//	}
	//	if (fst.eof()) {
	//		break;
	//	}
	//	text.push_back(data);
	//}//文件的数据读取完成
	if (fst.is_open()) {

		char c;
		while (fst.get(c)) {
			text.push_back(c);
		}
	}
	fst.close();
	for (auto i : text) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	getResult(text);
	return 0;
}