#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;

//�ڽ���������

//negate   һԪ�º�����ȡ������
void testfu () {
	negate<int> n;//����ģ��
	cout << n(100)<<endl;
}

//plus ��Ԫ�º��� ��Ӻ���
void testplus() {
	plus<int> p;
	cout << p(10, 20) << endl;
}



//��ϵ�º�����
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

	sort(v.begin(), v.end(),greater<int>());//ʹ���ڽ���������

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;

	sort(v.begin(), v.end(), less<int>());//ʹ���ڽ���������
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

//�߼��º�����
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

	transform(v.begin(), v.end(), v1.begin(), logical_not<bool>());//�����㷨+ȡ���㷨


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