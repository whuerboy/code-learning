#include<iostream>
class Entituty {
private:
	std::string m_Name;
	mutable int m_DebugCount;//mutable�������޸ĵ�ֵת���ɿ��޸ĵ�ֵ
public:
	Entituty(std::string name) {
		m_Name = name;
	}
	const std::string& GetName() const//���ڲ��������޸�
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
	auto f = [=]()mutable {//ֵ���ݲ��ܸı�ֵ����mutable����
		x++;
		std::cout <<"x=" << x << std::endl;
	};//һ���Ժ���
	f();

	auto g = [&] {
		x++;
		std::cout << "x=" << x << std::endl;
	};
	std::cout << "x=" << x << std::endl;
	g();
	return 0;
}