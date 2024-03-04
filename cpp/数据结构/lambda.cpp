#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

void forEach(std::vector<int>& values, const std::function<void(int)>& func) {
	for (auto value : values) {
		func(value);
	}
}

int main21() {
	std::vector<int> v = { 1,2,3,4,56 };
	int a = 5;
	auto lambda = [a](int value) {std::cout << " a= " << a << std::endl; std::cout << " value= " << value << std::endl; };//[��ʾ����ı����ķ�ʽ]
	//=��ʾȫ������ֵ���ݵķ�ʽ����&��ʾȫ���������ô��ݵķ�ʽ���񣻵�ȻҲ����ֱ�Ӵ���ĳ��������ֵ���ߵ�ַ
	forEach(v, lambda);
	return 0;
}