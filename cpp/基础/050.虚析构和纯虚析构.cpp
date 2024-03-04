#include<iostream>
using namespace std;

//多态在使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码
//解决方法：将父类中的析构函数改为虚析构或纯虚析构
//如果有纯虚析构，那么这个类就是抽象类
//纯虚析构和虚析构同样需要代码的实现
class Animal {
public:
	Animal() {
		cout << "animal构zao函数调用" << endl;
	}
	virtual ~Animal() {
		cout << "animal析构函数调用" << endl;
	}
	virtual void speak() = 0;
};

class Cat1:public Animal {
public:
	Cat1(string name) {
		cout << "cat构造函数调用" << endl;
		this->name = new string(name);
	}

	void speak() {
		cout <<*name<< "小猫在说话" << endl;
	}

	~Cat1() {
		if (name != NULL) {
			delete name;
			name = NULL;
			cout << "cat析构函数调用" <<endl;
		}
	}

	string *name;
};

int main50() {
	Animal *a = new Cat1("汤姆");//父类中的指针在析构时不会调用子类的析构函数，会造成内存泄露，这时候要把父类的析构变成虚析构
	a->speak();
	delete a;

	return 0;
}



