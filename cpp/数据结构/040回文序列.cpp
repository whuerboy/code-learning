#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>
int  stringBack(std::string code) {
	if (code.size() == 0 || code.size() ==1 ) {
		return 1;
	}
	if (code[0] != code[code.size()-1]) {
		return 0;
	}
	return stringBack(code.substr(1,code.size()-2));
}

int ifBackCode(int num) {
	std::ostringstream ost;
	ost << num;
	std::string code = ost.str();
	return stringBack(code);
}

int main040() {
	std::fstream fst;
	fst.open("in.txt");
	int num;
	fst >> num;
	std::cout << ifBackCode(num);
	return 0;
}