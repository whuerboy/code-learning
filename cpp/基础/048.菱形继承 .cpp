#include<iostream>
using namespace std;

//菱形继承：两个派生类继承同一个基类，而又有某个类同时继承这两个派生类
//会造成二义性
//虚拟继承可以有效解决问题

	//动物类:虚基类
class Animals {
public:
	int age;
	int a;
};

//羊类：
class Sheep:virtual public Animals{};


//驼类：
class Tuo:virtual public Animals{};

//羊驼类：
class SheepTuo :public Sheep, public Tuo {

};

int main() {

	SheepTuo st;
	st.Sheep::age = 18;
	st.Tuo::age = 28;
	st.a = 1000;
	Sheep sp;
	Tuo tuo;
	Animals an;
	//菱形继承问题可以通过作用域来解决
	cout << "羊驼的年龄st.Sheep  " << st.Sheep::age << endl;
	cout << "羊驼的年龄st.Tuo  " << st.Tuo::age << endl;

	//虚继承之后只存在一个age
	cout << "羊驼的年龄  " << st.age << endl;
	cout << "sheep中的age的地址是  " << &sp.age << endl;
	cout << "tuo中age的地址是  " << &tuo.age << endl;
	cout << "base中的age的地址是  " << &an.age << endl;
	cout << "yangtuo中age 的地址是  " << &st.age << endl;


	return 0;
}