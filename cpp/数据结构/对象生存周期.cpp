#include<iostream>
//基于栈上声明的变量，一出作用域就会被销毁

int* creatArray() {
	/*int a[50];
	return a;*///其实这个是错误的，没有在堆上分配内存，在函数执行完后会被销毁不会被返回，只不过由于这样很常见才会被修改成可行
	int* a = new int[50];
	return a;
}

class person {
private:
	std::string name;
public:
	person(std::string name) :name(name) {
		std::cout << "构造函数调用" << std::endl;
	}
	~person() {
		std::cout << "析构函数调用" << std::endl;
	}
};

class personstr {
private:
	person* p;
public:
	personstr(person* const p) :p(p) {

	}
	~personstr() {
		delete p;
	}
};


int main13() {
	{
		person* p1 =new person(std::string("小米"));
		//在堆上面创建的变量即使超出作用域也不会被销毁;
		personstr p = new person("小米");//personstr即使是在堆上的成员，但是超出范围也会被强制销毁，因为析构函数中有
		
	}
	int* a = creatArray();
	delete a;
	
	return 0;
}