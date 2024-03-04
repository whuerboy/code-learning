#include<fstream>
#include<iostream>
#include<vector>
#include<map>
#include <iomanip> //���ȿ��Ƶ�ͷ�ļ�
#include<string>
int main046() {
	std::fstream fst;
	fst.open("in.txt");

	std::vector<std::string>data;
	std::string str;
	while (std::getline(fst, str)) {
		if (str != " ") {
		data.push_back(str);
		}

	}
	std::map<std::string, int> reslut;
	for (auto i : data) {
		if ( reslut.find(i)!=reslut.end()) {//֮ǰ����
			reslut[i]++;
		}
		else {//֮ǰ������
			reslut.insert(std::make_pair(i, 1));
		}
	}
	//ͳ��ģ�飺
	float sum = 0;
	for (std::map<std::string, int>::iterator it = reslut.begin(); it != reslut.end(); it++)
	{
		sum += it->second;//ͳ������ֵ
	}
	for (std::map<std::string, int>::iterator it = reslut.begin(); it != reslut.end(); it++)
	{
		float count = (it->second) / sum;
		std::cout << it->first << " "<<std::fixed << std::setprecision(4) <<count*100 ;
		std::cout << std::endl;
	}

	return 0;
}