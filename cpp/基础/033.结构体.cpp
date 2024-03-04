#include<iostream>
#include<string>
using namespace std;
//结构体就是用户的自定义数据类型
//语法：
//struct 结构体名字 {结构体成员序列};


//创建学生的数据类型

struct student {
	//成员列表如下：
	string name;
	string sexy;
	
};

//结构体嵌套:
struct teacher {
	long long id;
	string name;
	struct student stu;

};

//结构体做函数参数：
void printstu(student s1, teacher t1) {
	cout << "在函数中打印学生的名字是  " << s1.name << endl; 
	cout << "在函数中打印教师的名字和id" << endl;
	cout << "教师姓名： " << t1.name << "教师id " << t1.id << endl;
	cout << "教师的学生是 : " << t1.stu.name << endl;
}

void changestu1(student *s1) {
	cout << "学生的姓名" << s1->name << endl;
	cout << "更改该学生的姓名" << endl;
	cin >> s1->name;
	cout << "改名后学生叫 " << s1->name << endl;

}

void printstu2(const student* arr) {
	int i = 0;
	cout << "名字";
	cout << "      性别     " << endl;


	for (i; i < 3; i++) {
		cout << arr[i].name;
		cout << "      " << arr[i].sexy << endl;
	}
}//将函数中的形参改为指针时可以减少内存空间，而且不会复制出新的副本

int main33() {
	//通过类型来创建实体变量,这时候可以省略struct

	 student s1;
	//给s1赋值，要通过 . 来访问
	 s1 = { "zhangsan","nan" };
	s1.name = "张三";
	s1.sexy = "男";
	cout  << "姓名： " << s1.name << endl;

	struct student s2 = {
		"李四","男"
	};
	cout << s2.name << endl<<endl<<endl<<endl;

	//结构体数组

	student arr[3] = { {"张三","man"},{"李四","man"},{"王五","man"} };
	int i = 0;
	cout << "名字" ;
	cout << "      性别     " << endl;
	for (i; i < 3; i++) {
		cout << arr[i].name ;
		cout << "      " << arr[i].sexy << endl;

	}

	cout << endl << endl << endl << endl;
	//结构体指针 ：通过指针访问结构体

	student* p = arr;
	
	for (int j = 0; j < 3; j++) {
		cout << "姓名是  " << p->name << "   ";
		p->sexy = "一个真正的man";
		cout << "性别是   " << p->sexy << endl;
		p++;
	}

	//结构体嵌套
	teacher t1 = {
	2022302111019,"大帅逼",s1
	};
	cout <<t1.name<<"的学生是 " << t1.stu.name << endl;
	teacher* p2 = &t1;
	cout << p2->name << "的id是 " << t1.id << endl; 

	//结构体作为函数参数:
	cout << endl << endl << endl << endl;
	printstu(s1, t1);
	changestu1(&s1);
	cout << endl << endl;
	cout << "该学生的名字现在是 " << s1.name << endl;

	printstu2(arr);


	//const的使用场景：
	//在函数中使用指针作为形参时加const可以防止误操作使本来的数据发生变化。




	return 0;
}