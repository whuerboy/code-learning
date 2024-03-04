#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
#include<vector>
#include<numeric>//�㷨ͷ�ļ�


//accumulate:����Ԫ���ܺ�
void testadd() {
	vector<int> v;
	for (int i = 0; i < 1000; i++) {
		v.push_back(i);
	};
	int m = 0;
	m=accumulate(v.begin(), v.end(), 100);//���ĸ�����Ϊ��ʼ�ۼ�ֵ
	cout << " m = " << m<<endl;
}

void print001(int m) {
	cout << m << "  ";
}


//fill:����㷨
void testfill() {
	vector<int> v;
	v.resize(10);
	fill(v.begin(), v.end(), 100);
	for_each(v.begin(), v.end(), print001);
}



//�����㷨������ set_intersection    ���� set_union     �  set_difference
//���������ϱ�������������
void testsetji() {
	vector<int> v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	vector<int> v;//���ս��
	v.resize(v1.size() + v2.size());//����
	vector<int> v3;
	v3.resize(min(v1.size(), v2.size()));//����

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