#include<iostream>
#include"hanshu.h"
#include<string>
#include <algorithm>
using namespace std;
#define MAX  1000 
//通讯录的功能：添加联系人，显示联系人，删除联系人，查找联系人，修改联系人，清空联系人，退出通讯录
//添加联系人的方法：定义联系人的结构体，通讯录的结构体...
struct person {
	string name;
	int sexy;//性别： 1.男  2.女
	int age;
	string phonenum;
	string address;
};
struct tongxunlu {
	struct person p[MAX];//联系人数组
	int m_size;//通讯录当前记录的人数
};

//添加联系人的用户
void  addperson(struct tongxunlu* book) {
	//判断通讯录是否已满
	if (book->m_size == MAX) {
		cout << "通讯录的人数已满,无法添加" << endl;
	}
	else {
		int now = book->m_size;//定义一个变量来承载当前人数
		//添加联系人:
		//name:
		string name;
		cout << "请输入联系人的名称： " << endl;
		cin >> name;
		book->p[now].name = name;
		//性别:
		cout << "请输入性别：\n 1.男   2.女" << endl;

		int sexy = 0;
		while (true) {
			cin >> sexy;
			if (sexy == 1 || sexy == 2) //如果输入 1 . 2可以重新输入直到对为止
			{
				book->p[now].sexy = sexy;
				break;
			}
			else {
				cout << "输入有误，请重新输入" << endl;
			}
		}
		
		//年龄：
		cout << "请输入用户的年龄:" << endl;
		int age;
		cin>>age;
		book->p[now].age = age;

		//联系电话:
		cout << "请输入联系电话" << endl;
		string num;
		cin >> num;
		book->p[now].phonenum = num;

		//住址
		cout << "请输入家庭住宅" << endl;
		string address;
		cin >> address;
		book->p[now].address = address;

		//更新通讯录人数：
		book->m_size++;
		cout << endl<<"联系人添加成功" << endl;

		system("pause");//按任意键继续
		system("cls");//清屏
	}

}


//显示联系人的函数：
void showperson(tongxunlu* book) {
	//判断通讯录中人数是否为0：
	if (book->m_size == 0) {
		cout << "当前无联系人" << endl;
	}

	else {
		for (int i = 0; i < book->m_size; i++) {
			cout << "姓名:  " << book->p[i].name << "\t"; 
			cout << "性别： " << (book->p[i].sexy ==1?"男":"女") << "\t";
			cout << "电话:  " << book->p[i].phonenum << "\t";
			cout << "年龄： " << book->p[i].age << "\t";
			cout << "住址:  " << book->p[i].address << endl;
		}

	}
	system("pause");//按任意键继续
	system("cls");//清屏
}


//显示联系人是否存在的函数：如果存在，返回联系人数组所在的具体位置，如不在返回-1
int isExist(tongxunlu* book,string name) 
{
	for (int i = 0; i < book->m_size; i++) {
		if (book->p[i].name == name)//此时找到了
		{
			return i;
		}
	}
	cout << "您所要找的联系人不存在" << endl;
	
	//system("pause");//按任意键继续
	//system("cls");//清屏
	return -1;//如果遍历完都没有找到。返回-1
}

//打印所查找联系人的函数：
void findPerson(tongxunlu* book, int person) {
	if (person == -1) {
		cout << "您查找的联系人不存在" << endl;
	}
	else {
		cout << "您所要查找联系人的信息如下:" << endl;
		cout << "姓名： " << book->p[person].name << "\t";
		cout << "性别： " << (book->p[person].sexy == 1 ? "男" : "女") << "\t";
		cout << "电话:  " << book->p[person].phonenum << "\t";
		cout << "年龄： " << book->p[person].age << "\t";
		cout << "住址:  " << book->p[person].address << endl;
	}
	system("pause");//按任意键继续
	system("cls");//清屏

}

//创建一个修改联系人的额函数：
void changePerson(tongxunlu* book, int person) {
	
	if (person != -1) {
		int choice = 1;
		cout << "选择你要修改的列表：1：改名字\t2.改性别\t3.改联系方式\t4.改年龄\t5.改住址\t0.修改完成" << endl;
		while (choice != 0)
		{
			cin >> choice;
			switch (choice)
			{
			case 1:	cout << "请输入修改后联系人的姓名： " << endl;
				cin >> book->p[person].name;
				break;
			case 2:	cout << "请输入修改后联系人的性别：(1.男   2.女 ) " << endl;
				cin >> book->p[person].sexy;
				break;
			case 3:	cout << "请输入修改后联系人的电话: " << endl;
				cin >> book->p[person].phonenum;
				break;
			case 4:	cout << "请输入修改后联系人的年龄: " << endl;
				cin >> book->p[person].age;
			case 5:	cout << "请输入修改后联系人的住址: " << endl;
				cin >> book->p[person].address;
				break;

			}

			if (choice != 0) { cout << "请继续输入你要修改的信息： "; }//避免最后一次的累赘输出
			continue;
		}
		cout << endl << "修改完成!" << endl;
	}
	
	system("pause");//按任意键继续
	system("cls");//清屏
}


//删除联系人的函数:
void deleteperson(tongxunlu* book, int person) {

	if (person != -1) //判断所要找的联系人是否存在
	{
		 //查找到人后直接进行数据的覆盖，起到删除的功能，此举不可逆
		for (int i = person; i < book->m_size; i++) {
			//数据前移操作：
			book->p[i] = book->p[i+ 1];
		}
		book->m_size--;//更新通讯录中的人数
		cout << "删除成功" << endl;
	}
	system("pause");//按任意键继续
	system("cls");//清屏
}


	//清空联系人：将通讯录的所有联系人全部删除
	//实现思路：讲通讯录中的所有联系人的信息清除，只需要重置通讯录的联系人数即可，做逻辑清空。这样还可以继续使用改数组
	//否则如果直接清楚数组本体，则再次添加联系人时，原来的数组将无法使用
void cleanperson(tongxunlu* book) {
	book->m_size = 0;//重置联系人数
	cout << "通讯录已经清空" << endl;
	system("pause");//按任意键继续
	system("cls");//清屏
	 
}

//实现菜单功能：
//构建一个封装函数.

int main35(){
	tongxunlu book;
	book.m_size = 0;
	int select;
	char y = 'Y', n = 'N';//用于确定操作
	int person;//用于定位联系人的数组位置
	string name;//用于查找，删除,修改联系人
	cout << "欢迎使用通讯录" << endl;
	while (true) {
		showMenu();//显示菜单		
		cout << "请输入你的操作" << endl;	
		cin >> select;
			if (cin.good()) {//用于检验输入的是否是整型数据
				if (select == 0 || select == 1 || select == 2 || select == 3 || select == 4 || select == 5 || select == 6) {
					switch (select) {
					case 1://添加联系人
						addperson(&book);
						break;
					case 2://显示联系人
						cout << "接下来显示通讯录里的联系人" << endl;
						showperson(&book);
						break;
					case 3: //删除联系人
						cout << "请输入你想要删除的联系人" << endl;
						//删除联系人首先要检查联系人是否存在
						cin >> name;
						person = isExist(&book, name);//检擦人是否存在，如果存在就定位
						deleteperson(&book, person);

						break;
					case 4://查找联系人
						cout << "请输入你要查找的联系人" << endl;
						cin >> name;
						person = isExist(&book, name);//先找人是否存在
						findPerson(&book, person);					
						break;
					case 5://修改联系人
						cout << "请输入你要修改的联系人" << endl;
						cin >> name;
						person = isExist(&book, name);
						changePerson(&book, person);
						break;
					case 6://清空联系人
						cout << "是否确定清空联系人" << endl;
						char YorN;
						cin >> YorN;
						if (toupper(YorN) == y) {
							cleanperson(&book);
						}
						else if (toupper(YorN) == n) {
							cout << "未进行任何处理" << endl;
							system("pause");//按任意键继续
							system("cls");//清屏
						}
						break;
					case 0://退出通讯录
						cout << "欢迎下次使用通讯录" << endl;
						system("pause");
						return 0;//少了此步将无法跳出while循环
						break;

					default:
						break;

					}
				}
				else {
					cout << "无该选项，请重新输入" << endl;
					system("pause");//按任意键继续
					system("cls");//清屏
				}
			}
		else {
				cout << "您输入的数据类型有误,请重新输入" << endl;
				cin.clear();//当输入的数据类型被判断有错时，cin的输入功能会被禁用。下面的代码用于重新启用cin的输入功能。
				while (cin.get() != '\n')
					continue;
				system("pause");//按任意键继续
				system("cls");//清屏
				
			}
	}
	return 0;

}