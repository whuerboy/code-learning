#include<iostream>
using namespace std;
//继承的基本语法:
//class 子类(派生类): 继承方式  父类(基类)
//继承方式：公共继承，保护继承，私有继承




//继承页面实现：
class BasePage {
public:
	static int j;
	int m_a;
	BasePage() {
		m_a = 100;
	}
	void header() {
		cout << "首页，公开课，登录，注册。。。（公共头部）" << endl;
	}

	void footer() {
		cout << "Java Python C++ C# C...." << endl;
	}

	void line() {
		cout << "-----------------------------------" << endl;
	}

	void func() {
		cout << "base成员函数的调用" << endl;
	}

	void func(int a) {
		cout << "base(int) 的调用" << endl;
	}


protected:
	int m_b;
private:
	int m_c;

};

int BasePage::j = 200;

class Base {
public:
	int a;
	Base() {
		a = 100;
	}
};



//公共继承:
class Son1 :public BasePage {
public:
	void func() {
		m_a = 10;//父类中公共类成员能访问
		m_b = 20;//父类中的保护成员能访问
	}
};


//保护继承：
class Son2 :protected BasePage {
public:
	void func() {
		m_a = 100;
		m_b = 1000;//这两个都变成保护权限，无法在类外单独访问
	}
};



//私有继承：
class Son3 :private BasePage {
public:
	void func() {
		m_a = 1000;
		m_b = 10000;//此时都是私有成员
	}
};

class Son4:public Son3 {
public:
	void func() {
		//m_a = 100;  无法访问
	}

};


//当子类与父类出现同名的成员
class Son :public BasePage {
public:
	static int j;
	int m_a;
	Son() {
		m_a = 200;
	}

	void func() {
		cout << "son成员函数的调用" << endl;
	}

};
int Son::j = 100;

//多继承：多继承有可能引发父类中同名成员的出现，需要加作用域

class BigSon :public Base, public BasePage {
	BigSon() {
		a = 1000;
		m_a = 100;
	}
};



int main46(){
	Son s;
	cout << "(Son)m_a = " << s.m_a << endl;
	cout << "(Base)m_a = " << s.BasePage::m_a << endl;
	s.func();
	s.BasePage::func();
	//s.func(10);不行
	//如果子类中出现和父类同名的成员函数，子类的同名成员会隐藏掉父类中所有的同名成员函数
	//只能通过作用域来调用
	s.BasePage::func(10);

	//通过类直接访问静态数据：
	cout << "base下 j = " << BasePage::j << endl;
	cout << "son 下 j = " << Son::j << endl;
	cout << "通过son访问base下 j = " << Son::BasePage::j << endl;

	return 0;
}