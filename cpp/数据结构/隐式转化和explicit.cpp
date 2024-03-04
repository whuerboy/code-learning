#include<iostream>
#include<string>
class enetity {
private:
	std::string m_Name;
	int m_Age;
public:
	enetity(const std::string name) {
		m_Name = name;
		m_Age = -1;
	}
	explicit enetity(const int age) {
		this->m_Age = age;
		this->m_Name = "UnKnown";
	}
};

int main12() {
	enetity c("bob");
	enetity b = std::string("bob");//隐式构造了一个enetity调用了构造函数
	//enetity a = 22; explicit修饰的构造函数必须要显式调用
	return 0;
	std::cin.get();
}