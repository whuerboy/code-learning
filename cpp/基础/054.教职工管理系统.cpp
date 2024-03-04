#include<iostream>
#include<string>
#include<string>
using namespace std;


//职工分类：普通员工，经理，老板
//管理系统的功能：退出管理程序；增加职工；删除职工；显示职工；修改职工；查找职工；按编号排序；清空
//职工的属性：编号，姓名，部门编号

//管理类：
class Manager {
public: 
	Manager();
	
	~Manager();//声明

	void showMenu();

	void outManager();

};

Manager::Manager() {
	cout << "hello";
}

Manager::~Manager() {
	cout << "hello";
}

 void  Manager::showMenu(){

	cout << "*********************************" << endl;
	cout << "******欢迎来到职工管理系统*******" << endl;
	cout << "*********0.退出管理系统**********" << endl;
	cout << "*********1.增加职工信息**********" << endl;
	cout << "*********2.显示职工信息**********" << endl;
	cout << "*********3.删除离职职工**********" << endl;
	cout << "*********4.修改职工信息**********" << endl;
	cout << "*********5.查找职工信息**********" << endl;
	cout << "*********6.按照编号排序**********" << endl;
	cout << "*********7.清空所有文档**********" << endl;
	cout << "*********************************" << endl;

}

void Manager::outManager() {
	
	cout << "欢迎使用职工管理系统" << endl;
	system("pause");
	exit(0);//结束程序

}


//职工抽象类：
class Worker {
public:
	//显示个人信息：
	void virtual showPerson() = 0;

	//获取岗位：

	string virtual getWorkName() = 0;


	int id;//职工编号
	string name;//职工姓名
	int workId;


};


//普通职工类：

class Employee :public Worker {
public:
	//构造函数：

	Employee(int id, string name, int workID)
	{
		this->id = id;
		this->name = name;
		this->workId = workID;
	}


	//显示个人信息：
	void virtual showPerson();

	//获取岗位：

	string virtual getWorkName();

};

string Employee::getWorkName() {
	return string("普通员工");
}

void Employee::showPerson(){
	cout << "职工编号： " << this->id << "\t职工姓名： " << this->name << "\t 岗位" << this->getWorkName() << endl;


}



//经理类：
class Managerperson :public Worker {
public:
	Managerperson(int id, string name, int did) {};

};




//int main() //测试函数功能
//{
//	Worker* worker = NULL;
//	worker = new Employee(1, "zhangsan", 1);
//	worker->showPerson();
//
//}


int main54() {
	Manager m;
	
	int select;//记录选项
	
	while (true) {
		m.showMenu();
		cout << "请输入您的选项" << endl;
		cin >> select;
		if (cin.good())//用于检测是不是整型
		{
			
				switch (select)
				{
				case 1://增加职工信息
					break;

				case 2://显示职工信息
					break;

				case 3://删除离职职工信息
					break;

				case 4://修改职工信息
					break;

				case 5://查找职工信息：
					break;

				case 6://按编号排序
					break;

				case 7://清空所有文档
					break;


				case 0://退出管理系统
					m.outManager();//结束程序

				default:
					cout << "无该选项，请重新输入" << endl;
					system("pause");
					system("cls");
					break;
				}

			
			
		}

		else {
			cout << "您输入的类型有误，请重新输入" << endl;
			cin.clear();
			while (cin.get() != '\n')
				continue;
			system("pause");
			system("cls");
			
		}

	}
	

}


