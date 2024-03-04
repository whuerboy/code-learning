//返回bool类型的仿函数称为谓词
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



//一元谓词：只有一个参数
void tet() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	//检查是否有>5的元素
	vector<int>::iterator it = find_if(v.begin(), v.end(), BiggerThan5());//匿名对象
	if (it != v.end()) {
		cout << "存在比5大的数为" << *it << endl;

	}
	else {
		cout << "不存在" << endl;
	}
}

class Mycom {
public:
	bool operator()(int m, int n) {
		return m > n;
	}
};


//二元谓词：两个参数
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
