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
	auto lambda = [a](int value) {std::cout << " a= " << a << std::endl; std::cout << " value= " << value << std::endl; };//[表示捕获的变量的方式]
	//=表示全部都是值传递的方式捕获，&表示全都都是引用传递的方式捕获；当然也可以直接传入某个变量的值或者地址
	forEach(v, lambda);
	return 0;
}