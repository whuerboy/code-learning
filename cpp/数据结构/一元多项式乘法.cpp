#include<iostream>
#include<vector>
#include<fstream>
#include<ostream>


int main33() {

	std::fstream fst;
	fst.open("in.txt");
	int length1=0, length2 = 0;
	std::vector<int>arr1;
	std::vector<int>arr2;
	fst >> length1;
	for (int i = 0; i < length1; i++) {
		int data;
		fst >> data;
		arr1.push_back(data);
	}
	fst >> length2;
	for (int i = 0; i < length2; i++) {
		int data;
		fst >> data;
		arr2.push_back(data);
	}
	fst.close();
	int diminsion = (length1 - 1)+(length2 - 1);
	std::vector<int>result(diminsion+1);//Ô¤Áô¿Õ¼ä


	//³Ë·¨£º
	for (int i = 0; i < length1; i++) {
		for (int j = 0; j < length2; j++) {
			int sum = 0;
			sum = arr1[i] * arr2[j];
			result[i + j] += sum;
		}
	}

	fst.open("out.txt",std::ios::out);

	for (auto i : result) {
		fst << i<<" ";
		
	}

	return 0;
}