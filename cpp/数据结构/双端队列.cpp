#include<iostream>
#include<deque>
using namespace std;

void printScore(int number, int* score) {
	//��ѧ���ĳɼ�����a c b��˳�����˫�˶�����
	deque<int> out_socre;
	for (int i = 0; i < number; i++) {
		if (score[i] >= 90) {
			out_socre.push_back(score[i]);
		}
	}

	for (int i = 0; i < number; i++) {
		if (score[i] <= 60) {
			out_socre.push_back(score[i]);
		}
	}

	for (int i = 0; i < number; i++) {
		if (score[i] < 90&&score[i]>60) {
			out_socre.push_back(score[i]);
		}
	}


	
	int size = out_socre.size();
	for (int i = 0; i < size; i++) {
		if (i == size - 1) {
			cout << out_socre.front();
		}
		else {
cout << out_socre.front() << " ";
		out_socre.pop_front();
		}
		
	}
	
}

int main30() {
	int stu_Num;//����ѧ������
	cin >> stu_Num;
	int* score = new int[stu_Num];//������Ԥ��һ���Ĵ�С
	for (int i = 0; i < stu_Num; i++) {
		cin >> score[i];
	}
	cin.ignore();
	printScore(stu_Num, score);
	return 0;
}