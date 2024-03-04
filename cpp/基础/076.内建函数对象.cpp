#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;

//内建函数对象

//negate   一元仿函数，取反函数
void testfu () {
	negate<int> n;//函数模板
	cout << n(100)<<endl;
}

//plus 二元仿函数 相加函数
void testplus() {
	plus<int> p;
	cout << p(10, 20) << endl;
}



//关系仿函数：
void testgreat() {
	vector<int> v;
	v.push_back(40);
	v.push_back(20);
	v.push_back(50);
	v.push_back(10);
	v.push_back(70);

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;

	sort(v.begin(), v.end(),greater<int>());//使用内建函数对象

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;

	sort(v.begin(), v.end(), less<int>());//使用内建函数对象
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

//逻辑仿函数：
void testlogical() {
	vector<bool> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(0);
	v.push_back(1);
	for (vector<bool>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;

	vector<bool> v1;
	v1.resize (v.size());

	transform(v.begin(), v.end(), v1.begin(), logical_not<bool>());//搬运算法+取反算法


	for (vector<bool>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}



int main() {
	testfu();
	//testplus();
	//testgreat(); 
	testlogical();
	return 0;
}