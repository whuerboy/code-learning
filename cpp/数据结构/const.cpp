#include<iostream>
#include<string>
//const����һ����ŵ��һ������ı�ĳ�ŵ


class entity {
private:
	int* m_X, m_Y;//m_X��ָ�� ����m_Y��Int
public:
	entity() {
		m_X = new int;
		m_Y = 0;
	}
	int* getX() const //ֻ��������Ч�������޸���ĳ�Ա����
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
	a = (int*)AGE;//Υ����ŵ
	//std::cout << *a << std::endl;
	const entity e;
	getX(e);

	//������һ���������õĶ����ʱ��ֻ�ܵ��ö����е�const���εĺ�������Ϊ�������ò������޸�����ָ�����ݵ�ֵ
	//ֻ�����е�const���εĺ��������������
	return 0;
}