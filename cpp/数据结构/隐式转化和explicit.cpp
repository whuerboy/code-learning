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
	enetity b = std::string("bob");//��ʽ������һ��enetity�����˹��캯��
	//enetity a = 22; explicit���εĹ��캯������Ҫ��ʽ����
	return 0;
	std::cin.get();
}