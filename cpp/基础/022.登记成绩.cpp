#include<iostream>
#include<string.h>
using namespace std;
int main22() {

	//�����ά����
	//ѭ���Ǽǳɼ�
	string name[3] = { "����","����","����" };
	int scores[3][3] =
	{
		{100, 100, 100},
		{90,50,100},
		{60,70,60}
	};
	cout << "      "<<"��ѧ" << "  " << "����" << "   " << "��ѧ" << endl;
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
		cout << "�ܷ��� " << sum;
		cout << endl;
	}







	return 0;
}