#include<iostream>
//智能指针是会在创建时自动分配内存然后自动在合适的时机销毁掉
class elevent {
public:
	elevent() {
		std::cout << "构造函数的调用" << std::endl;
	}
	~elevent() {
		std::cout << "析构函数的调用" << std::endl;
	}
	void print() {
		std::cout << "print" << std::endl;
	}
};

int main14() {
	{
		std::unique_ptr<elevent> e = std::make_unique<elevent>();//std::unique_ptr<ele>e(new ele())这种方法会出现异常安全的问题
		//智能指针不能通过赋值另一个指针得到，因为他们共指向一块内存，一个被删除后会导致内存泄露
		e->print();
	}


	{ 
		std::shared_ptr<elevent>s0;
		{
		std::shared_ptr<elevent> s = std::make_shared<elevent>();
		s0 = s;
		//std::shared_ptr<elevent>s(new elevent());一般不至这样，share_ptr中有一个控制块，使用new方法会开辟两块内存，而make方法直接将他们结合起来了
		//当进行share指针赋值时，会增加引用计数，当引用计数为0时，底层的eleveant才会被析构掉
		//果想要进行指针复制而增加引用计数的话，就要使用weak指针

		}	
	}


	{
		std::weak_ptr<elevent> w;
		{
			std::shared_ptr<elevent>s = std::make_shared<elevent>();
			w = s;
		}
	}


	return 0;
}