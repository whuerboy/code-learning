#include<iostream>
using namespace std;

//函数模板：
//void swapInt(int& a, int& b) {
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//void swapDouble(double& a, double& b) {
//	double temp = a;
//	a = b;
//	b = temp;
//}
//
//
//template<typename T>//声明一个模板，T是一个通用的数据类型
////模板必须要确定T的数据类型才能使用
////typename可以替换成class
//
//
//void mySwap(T& a, T& b) {
//	T temp=a;
//	a = b;
//	b = temp;
//}
//
//template<class T>
//void func() {
//	cout << "hanshu" << endl;
//}
//
//
//template<typename T>
//void mysort(T* arr, int lenth) {
//
//	//数组选择排序
//	for (int i = ; i < lenth; i++) {
//		int max = i;//认定最大值为i
//		for (int j = i + 1i < lenth; j++) {
//			if (arr[max] < arr[i]) {
//				max = j;
//			}
//		}
//		if (max != i) {
//			swap<int>(arr[max], arr[i]);
//		}
//	}
//
//	//打印排序后的数组
//	for (int m = 0; m < lenth; m++) {
//		cout << arr[m] << "\t";
//	}
//
//	
//}

void myPrint(int a, int b) {
	cout << "hanshu"<<endl;
}

template<class T>
void myPrint(T a, T b) {
	cout << "模板调用"<<endl;
}


//函数模板也可以发生重载
template<class T>
void myPrint(T a, T b,T c) {
	cout << "重载模板调用" << endl;
}

int main55() {
	//int a = 0, b = 1;
	//swapInt(a, b);
	//cout << "a = " << a << endl;
	//cout << "b = "<<b << endl;
	//mySwap(a, b);//隐式调用,自动类型推导，必须导出一致的数据类型

	//cout << "a = " << a << endl;
	//cout << "b = " << b << endl;
	//
	////显式调用
	//mySwap<int>(a, b);
	//cout << "a = " << a << endl;
	//cout << "b = " << b << endl;

	//总之没事就用显式调用，以免发生不必要的错误
	//func<int>();//如果没有显式的调用的该函数无法被调用，因为T没有被确定

	/*int arr[] = { 0,2,5,4,6,7,8,9,10,1 };
	int num = sizeof(arr) / sizeof(int);
	 mysort<int>(arr,num);
	 */

	int a = 10, b = 20;
	myPrint(a, b);//优先调用普通函数
	cout << endl;
	//通过空模板的参数列表可以强制调用函数模板
	myPrint<>(a, b);
	myPrint(a, b, 10);

	//如果函数模板可以产生更好的匹配，优先调用函数模板
	char m = 'c';
	char n = 'b';
	myPrint(m, n);

	return 0;


}