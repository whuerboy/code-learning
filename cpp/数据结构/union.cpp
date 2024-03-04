#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;
ifstream ifs("in.txt", ios::in);
void getNum( vector<int>& v,int size) {
	for (int i = 0; i < size; i++) {
		ifs >> v[i];
	}
}



void getVec(vector<int>v1, vector<int>v2) {
	int m1 = 0, m2 = 0;
	while (m1 != (v1.size()) && m2 != (v2.size())) {
		
		if (v1[m1] > v2[m2]) {
			cout << v2[m2] << " ";
			m2++;
		}
		else if (v1[m1] < v2[m2]) {
			cout << v1[m1] << " ";
			m1++;
		}
		else {
			cout << v1[m1]<<" ";
			m1++; m2++;
		}
	}

	if (m1 == v1.size()) {
		for (; m2 < v2.size(); m2++) {
			cout << v2[m2] << " ";
		}
	}
	if (m2 == v2.size()) {
		for (; m1 < v1.size(); m1++) {
			cout << v1[m1] << " ";
		}
	}
}

int main8() {
	
	vector<int> txt(10);
	if (!ifs) {
		cout << "open err!" << endl;
		exit(0);
	}
	int a, b;
	ifs >> a;
	ifs >> b;

	vector<int>v1(a);
	vector<int>v2(b);
	getNum( v1, a);
	getNum( v2, b );
	ifs.close();
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	getVec(v1, v2);
	return 0;
}