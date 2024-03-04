#include<iostream>
using namespace std;

//在程序里，友元可以让一些类外的函数或者类访问私有属性
//友元的三种实现：全局函数友元，类做友元，成员函数做友元

class Gay;
class Building;//做类的声明

class Goodgay;

class Gay {
public:
	Gay();//默认构造函数
	void visit2();
	Building* building;
};


class Building {
	friend void Gay::visit2();//成员函数做友元
	friend class Goodgay;//类做友元，这样的类可以访问该类中的私有成员
	friend void goodGay(Building* building);//全局函数做友元

public:



	Building() {
		sittingroom = "客厅";
		bedroom = "卧室";
	}

	string sittingroom;//客厅
	

private:
	string bedroom;//卧室
};

//全局函数
void goodGay(Building* building) {
	cout << "好基友全局函数正在访问:  " << building->sittingroom << endl;
	cout << "好基友全局函数正在访问:  " << building->bedroom << endl;
}




class Goodgay {
public:
	Goodgay() {
		//创造一个对象
		building = new Building;
	}

	void visit1();
	Building* building;

};

void Goodgay::visit1() {
	cout << "好基友对象正在访问  " << building->sittingroom << endl;
	cout << "好基友对象正在访问  " << building->bedroom<< endl;
}


//友元成员函数的实现
void Gay::visit2() {
	cout << "基友对象正在访问  " << building->sittingroom << endl;
	cout << "基友对象正在访问  " << building->bedroom << endl;

}

Gay::Gay() {
	building = new Building;
}






int main44() {

	Building building1;
	goodGay(&building1);//此时调用该函数时不用通过类调用，因为这个函数不属于类

	Goodgay goodgay;
	goodgay.visit1();

	delete goodgay.building;

	Gay gay;
	gay.visit2();
	delete gay.building;//析构函数

	return 0;
}