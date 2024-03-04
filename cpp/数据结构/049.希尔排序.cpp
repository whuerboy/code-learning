#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
void Sort(vector<int>& array,int length) {
	/*int h = length / 2;
	while (h >= 1) {
		for (int i = h; i < length; i++) {
			for (int j = i; j >= h && array[j] < array[j - h]; j -= h) {
				std::swap(array[j], array[j - h]);
			}
		}
		h = h / 2;
	}*/
	int d, i, j;
	for (d = length / 2; d >= 1; d = d / 2) {
		for (i = d + 1; i < length; i++) {
			if (array[i] < array[i - d]) {
				array[0] = array[i];
				for (j = i - d; j > 0 && array[0] < array[j]; j -= d) {
					array[j + d] = array[j];
				}
				array[j + d] = array[0];
			}
		}
	}
}

int main049() {
	fstream fst("in.txt");
	vector<int>data;
	data.push_back(0);
	while (1) {
		int temp;
		fst >>temp;
		data.push_back(temp);
		if (fst.eof()) {
			break;
		}
	}
	fst.close();
	Sort(data, data.size());
	ofstream ofs("out.txt");
	data.erase(data.begin());
	for (auto i : data) {
		std::cout << i << " ";
		ofs << i << " ";
	}
	return 0;
}