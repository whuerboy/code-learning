//����bool���͵ķº�����Ϊν��
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class BiggerThan5 {
public:
	bool operator()(int val) {
		return val > 5;
	}
};



//һԪν�ʣ�ֻ��һ������
void tet() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	//����Ƿ���>5��Ԫ��
	vector<int>::iterator it = find_if(v.begin(), v.end(), BiggerThan5());//��������
	if (it != v.end()) {
		cout << "���ڱ�5�����Ϊ" << *it << endl;

	}
	else {
		cout << "������" << endl;
	}
}

class Mycom {
public:
	bool operator()(int m, int n) {
		return m > n;
	}
};


//��Ԫν�ʣ���������
void tett() {
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20); v.push_back(50);
	v.push_back(30);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl;
	cout << "------------------------------" << endl;
	sort(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl;
	cout << "------------------------------" << endl;
	sort(v.begin(), v.end(), Mycom());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl;

}

	int main75() {
		tett();
		return 0;
	}
