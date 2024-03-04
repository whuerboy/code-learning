#include<iostream>
#include<string>
//const更像一个承诺，一个不会改变的承诺


class entity {
private:
	int* m_X, m_Y;//m_X是指针 但是m_Y是Int
public:
	entity() {
		m_X = new int;
		m_Y = 0;
	}
	int* getX() const //只在类中生效，不能修改类的成员变量
	{
		return m_X;
	}

	int* getX() {
		return m_X;
	}

	void setX(int x) {
		*m_X= x;
	}
};

void getX(const entity& e) {
	std::cout << *e.getX() << std::endl;
}


int main11() {
	const int AGE = 100;
	int* a = new int;
	std::cout << *a << std::endl;
	*a = 1;
	std::cout << *a << std::endl;
	a = (int*)AGE;//违背承诺
	//std::cout << *a << std::endl;
	const entity e;
	getX(e);

	//当声明一个常量引用的对象的时候，只能调用对象中的const修饰的函数，因为常量引用不允许修改引用指向内容的值
	//只有类中的const修饰的函数才有这个作用
	return 0;
}