#include<iostream>
#include<string.h>
using namespace std;
int main22() {

	//创造二维数组
	//循环登记成绩
	string name[3] = { "张三","李四","王五" };
	int scores[3][3] =
	{
		{100, 100, 100},
		{90,50,100},
		{60,70,60}
	};
	cout << "      "<<"数学" << "  " << "物理" << "   " << "化学" << endl;
	for (int i = 0; i < 3; i++) {
		int sum = 0;
		cout << name[i]<<"  ";
		for (int j = 0; j < 3; j++) {

			cout << scores[i][j] << "   ";
			sum += scores[i][j];
			if (scores[i][j] < 100) {
				cout << " ";
			}
		}
		cout << "总分是 " << sum;
		cout << endl;
	}







	return 0;
}