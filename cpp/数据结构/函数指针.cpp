#include<iostream>
#include<vector>

void printInt(int value) {
	std::cout << "value = " << value << std::endl;
}

void For_Each(const std::vector<int>& v, void(*func)(int))//����ָ�룬ʹ�����ܹ���Ϊ��һ�������Ĳ���
{
	for (auto value : v) {
		func(value);
	}
}

//lambda����һ�����⺯����һ�ü����ĺ�������ֻ����һ�κ��û���ˣ�һ���ڳ��ֺ���ָ��ĵط�����ʹ��lambda�����庯��������ר�ŵĶ���һ���µĺ�������


int main20() {
	std::vector<int> v = { 1,2,3,4,5,6 };
	For_Each(v, printInt);
	std::cout << "--------lambda-------------" << std::endl;
	For_Each(v, [](int value) {std::cout << "value: " <<value<< std::endl; });//����ͱ�����
	return 0;
}

