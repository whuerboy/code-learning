#include<iostream>

using namespace std;
int main6() {
	int sum = 0, value = 0;
	while (cin >> value)//while��һֱѭ��ֱ�������ļ������������������
		sum += value;
	cout << sum << endl;

	return 0;
}