#include<iostream>
#include<vector>
#include<fstream>
#include<map>
#include<algorithm>
//接下来是打印：

bool mycompare(const std::pair<char, int>& s1,  const std::pair<char, int>& s2) {
	if (s1.second == s2.second) {
		return s1.first < s2.first;
	}
	else {
		return s1.second > s2.second;
	}
}

class myCompare {
public: 
	bool operator()(const std::pair<char, int>& s1, const std::pair<char, int>& s2) {
		return mycompare(s1, s2);
	}
};


void getResult1(std::vector<char>text) {
	std::map<char, int> result;
	for (auto i : text) {
		result[i]++;
	}
	//打印：
	//for (std::map<char, int>::iterator it = result.begin(); it != result.end(); it++)
	//{
	//	for (int i = 0; i < it->second; i++) {
	//		std::cout << it->first;
	//	}
	//}

	//排序：
	std::vector<std::pair<char, int>>data(result.begin(),result.end());
	std::sort(data.begin(), data.end(), myCompare());
	for (auto i : data) {
		for (int j = 0; j < i.second; j++) {
			std::cout << i.first;
		}
	}
}

int main050() {
	std::fstream fst;
	fst.open("in.txt", std::ios::in);
	std::vector<char> text;
	if (fst.is_open()) {

		char c;
		while (fst.get(c)) {
			text.push_back(c);
		}
	}
	fst.close();
	getResult1(text);
	return 0;
}