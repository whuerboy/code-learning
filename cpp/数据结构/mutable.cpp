#include<iostream>
class Entituty {
private:
	std::string m_Name;
	mutable int m_DebugCount;//mutable将不可修改的值转化成可修改的值
public:
	Entituty(std::string name) {
		m_Name = name;
	}
	const std::string& GetName() const//类内参数不可修改
	{
		m_DebugCount++;
		return m_Name;
	}
};

int main9() {
	const Entituty e("shabi");
	e.GetName();
	std::cin.get();


	int x = 8;
	auto f = [=]()mutable {//值传递不能改变值，加mutable可以
		x++;
		std::cout <<"x=" << x << std::endl;
	};//一次性函数
	f();

	auto g = [&] {
		x++;
		std::cout << "x=" << x << std::endl;
	};
	std::cout << "x=" << x << std::endl;
	g();
	return 0;
}