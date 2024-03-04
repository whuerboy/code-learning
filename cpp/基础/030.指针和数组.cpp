#include<iostream>
using namespace std;
int main30() {
	//利用指针来访问数组的元素
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << "直接用数组来访问数组的的一个元素  " << arr[0] << endl;
	int* p = arr;//arr就是数组的首地址
	cout << "利用指针来访问数组的第一个元素  " << *p << endl;
	p++;
	cout << "利用指针来访问第二个元素 " << *p << endl;
	//利用指针便利数组
	p = arr;
	for (int i = 0; i < 10; i++) {
		cout << "第 " << i + 1 << "个元素的值是 " << *p << endl;
		p++;
	}





	return 0;
}