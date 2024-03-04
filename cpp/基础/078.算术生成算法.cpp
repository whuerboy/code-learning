#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
#include<vector>
#include<numeric>//算法头文件


//accumulate:计算元素总和
void testadd() {
	vector<int> v;
	for (int i = 0; i < 1000; i++) {
		v.push_back(i);
	};
	int m = 0;
	m=accumulate(v.begin(), v.end(), 100);//第四个参数为起始累加值
	cout << " m = " << m<<endl;
}

void print001(int m) {
	cout << m << "  ";
}


//fill:填充算法
void testfill() {
	vector<int> v;
	v.resize(10);
	fill(v.begin(), v.end(), 100);
	for_each(v.begin(), v.end(), print001);
}



//集合算法：交集 set_intersection    并集 set_union     差集  set_difference
//这两个集合必须是有序容器
void testsetji() {
	vector<int> v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	vector<int> v;//接收结果
	v.resize(v1.size() + v2.size());//并集
	vector<int> v3;
	v3.resize(min(v1.size(), v2.size()));//交集

	vector<int>::iterator it= set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), it, print001);
	cout << endl;
	for_each(v3.begin(), v3.end(), print001);
	cout << endl;
	it = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());
	for_each(v.begin(), it, print001);
}


void main78() {
	//testadd();
	//testfill();
	testsetji();
}