#include<iostream>
#include<vector>

void printInt(int value) {
	std::cout << "value = " << value << std::endl;
}

void For_Each(const std::vector<int>& v, void(*func)(int))//函数指针，使函数能够称为另一个函数的参数
{
	for (auto value : v) {
		func(value);
	}
}

//lambda：是一个虚拟函数，一用即弃的函数，即只调用一次后就没用了，一般在出现函数指针的地方可以使用lambda来定义函数而不用专门的定义一个新的函数出来


int main20() {
	std::vector<int> v = { 1,2,3,4,5,6 };
	For_Each(v, printInt);
	std::cout << "--------lambda-------------" << std::endl;
	For_Each(v, [](int value) {std::cout << "value: " <<value<< std::endl; });//用完就被销毁
	return 0;
}

