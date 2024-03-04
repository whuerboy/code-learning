#include<iostream>
#include<deque>
using namespace std;

void printScore(int number, int* score) {
	//将学生的成绩按照a c b的顺序放入双端队列中
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
	int stu_Num;//定义学生人数
	cin >> stu_Num;
	int* score = new int[stu_Num];//用括号预留一定的大小
	for (int i = 0; i < stu_Num; i++) {
		cin >> score[i];
	}
	cin.ignore();
	printScore(stu_Num, score);
	return 0;
}