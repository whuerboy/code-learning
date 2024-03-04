#include<iostream>
#include<vector>
using namespace std;

void adData(vector<int>& v1,int length) {
	int data;
	for (int i = 0; i < length; i++) {
		cin >> data;
		v1.push_back(data);
	}
}


void downPrint(vector<int> v1,int length) {
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;//顺序输出

	//倒序输出：
	int half = length / 2;
	for (int i = 0; i < half; i++) {
		int m = length - i-1;//此处小心
		int middle;
		middle = v1[i];
		v1[i] = v1[m];
		v1[m] = middle;
	}
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}


int main6() {
	int length;
	cin >> length;
	vector<int> v1;
	adData(v1, length);
	downPrint(v1, length);
	return 0;
}