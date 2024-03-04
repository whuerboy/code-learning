#include<iostream>
using namespace std;

//多态：动态多态和静态多态
//动态多态的满足条件：
//有继承关系,子类重写父类的虚函数（函数名相同返回值相同参数相同）

//动态多态的使用：父类的指针或引用来指向子类对象

class Animal {
public:
	virtual void speak() {
		
	}
};

class Cat :public Animal{
	void speak() {
		cout << "小猫在说话" << endl;
	}
};

//执行说话的函数
//地址早绑定   在编译阶段确定函数的地址
//如果想执行让猫说，那么这个函数的地址不能提前绑定，要在运行的阶段在进行绑定
void doSpeak(Animal& animal) {
	animal.speak();
}

class Dog:public Animal {
	void speak() {
		cout << "狗叫" << endl;
	}
};




//多态案例1：计算器类：实现两个操作数进行运算


//普通写法：
class Calculator1 {
public:
	int getResult(string oper) {
		if (oper == "+") {
			return num1 + num2;
		}
		else if (oper == "-") {
			return num1 - num2;
		}
		else if (oper == "*") {
			return num1 * num2;
		}
		else if(oper == "/") {
			return num1 / num2;
		}

		//如果想要拓展新的功能，需要修改源码
		//在实际开发中：对拓展进行开发，对修改进行关闭
	}

	int num1;
	int num2;

};


//多态的源码:

class Calulator2 //抽象类，无法实例化对象，子类必须重写纯虚函数，否则也无法实力化
{
public:
	static int num1;
	static int num2;
	virtual int getResult() = 0;//纯虚函数
};
int Calulator2::num1 = 1000;
int Calulator2::num2 = 10;

//加法计算器：
class Add :public Calulator2 {
public:
	int getResult(){
		return num1 + num2;
	}
};

class Del :public Calulator2 {
public:
	int getResult() {
		return num1 - num2;
	}
};

class Cheng :public Calulator2 {
public :
	int getResult() {
		return num1 * num2;
	}
};


int doCalulate(Calulator2* c) {
	return c->getResult();
}


//多态带来的好处：
//组织结构清晰，分工明确；可读性强




int main49() {
	/*Cat cat;
	doSpeak(cat);
	Dog dog;
	doSpeak(dog)*/

	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	Calculator1 c;
	c.num1 = 100;
	c.num2 = 10;
	cout << c.num1 << "+" << c.num2 <<"=" << c.getResult("+") << endl;
	cout << c.num1 << "-" << c.num2 << "=" << c.getResult("-") << endl;
	cout << c.num1 << "*" << c.num2 << "=" << c.getResult("*") << endl;
	cout << c.num1 << "/" << c.num2 << "=" << c.getResult("/") << endl;
	cout << endl;
	cout << "*******************" << endl<<endl;

	Calulator2 *abc = new Add;
	
	cout << abc->num1 << "+" << abc->num2 << "=" << abc->getResult() << endl;
	delete abc;
	abc = new Del;
	
	cout << abc->num1 << "-" << abc->num2 << "=" << abc->getResult() << endl;
	delete abc;
	abc = new Cheng;
	
	cout << abc->num1 << "*" << abc->num2 << "=" << abc->getResult() << endl;


	return 0;
}