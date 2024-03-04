#include<iostream>
using namespace std;
//下面用该程序实现冒泡排序

void bubble(int * p, int len);
//参数1：数组首地址
//参数2：数组的长度

int main32() {
	void swap(int& a, int& b);//声明一个交换函数,

	//1.创建一个数组
	int arr[11] = { 4,5,2,3,8,9,1,6,7,0 ,100};

	//2.创建函数实现冒泡排序
	int len = sizeof(arr) / sizeof(arr[0]);
	bubble(arr, len);

	//3.打印排列好的数组
	for (int i = 0; i < len; i++) {
		cout << arr[i] << endl;
	}

	return 0;
}
void bubble(int* arr, int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				//swap(arr[j], arr[j + 1]);
				//在此处也可以使用值传递的方法，因为参数已经是指针了
				int a = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = a;
			}
		}
	}
}

