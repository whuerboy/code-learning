#include<iostream>
using namespace std;

class Person {
public:
	void showClassName() {
		cout << "this is Person class" << endl;
	}
	void showAge() {
		cout << "年龄是  " << this->age << endl;
	}

	int age;
};

int main42() {
	Person* p = NULL;//空指针无法访问属性
	if (p == NULL)//提高代码的健壮性，防止受到破坏
	{
		return 0;
	}
	else
	p->showClassName();

	return 0;


}