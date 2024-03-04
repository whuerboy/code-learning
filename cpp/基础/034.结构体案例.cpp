#include<iostream>
#include<string>
#include<ctime>//用于创建随机数种子
using namespace std;


struct student {
	string name;
	int scores;
};

struct teacher {
	string name;
	student stu[5];
};

//给老师和学生赋值的函数:
void creatvalue(teacher t[], int len) {

	string nameseed = "ABCDEFG";
	//给老师赋值
	for (int i = 0; i < len; i++)
	{
		t[i].name = "Teacher_";
		t[i].name += nameseed[i];

		//给老师带的学生赋值:
		for (int j = 0; j < 5; j++) {
			t[i].stu[j].name = "Student_";
			t[i].stu[j].name += nameseed[j];
			t[i].stu[j].scores = 60;
		}
	}

}

//打印所有的信息：
void printTea(teacher t[], int len) {
	for (int i = 0; i < len;i++) {
		cout << "老师的名字  " << t[i].name << endl;
		for (int j = 0; j < 5; j++) {
			cout << "\t学生的名字  " << t[i].stu[j].name;
			int random = rand() % 100;//
			t[i].stu[j].scores = random;
			cout << "  学生的成绩  " << t[i].stu[j].scores;
			cout << endl;

		}
	}
	

}



int main34(){

	//随机数种子
	srand((unsigned int)time(NULL));
	
	//创建老师的数组:
	teacher tea[3];

	//通过函数给老师赋值：
	int len = sizeof(tea) / sizeof(tea[0]);//计算老师的结构体数组的中元素的个数
	creatvalue(tea, len);

	//打印所有信息：
	printTea(tea, len);




	return 0;
}