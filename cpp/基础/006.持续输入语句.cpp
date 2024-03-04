#include<iostream>

using namespace std;
int main6() {
	int sum = 0, value = 0;
	while (cin >> value)//while会一直循环直到遇到文件结束符或者输入错误
		sum += value;
	cout << sum << endl;

	return 0;
}