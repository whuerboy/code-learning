#include<iostream>
using namespace std;

//����ģ�壺
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
//template<typename T>//����һ��ģ�壬T��һ��ͨ�õ���������
////ģ�����Ҫȷ��T���������Ͳ���ʹ��
////typename�����滻��class
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
//	//����ѡ������
//	for (int i = ; i < lenth; i++) {
//		int max = i;//�϶����ֵΪi
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
//	//��ӡ����������
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
	cout << "ģ�����"<<endl;
}


//����ģ��Ҳ���Է�������
template<class T>
void myPrint(T a, T b,T c) {
	cout << "����ģ�����" << endl;
}

int main55() {
	//int a = 0, b = 1;
	//swapInt(a, b);
	//cout << "a = " << a << endl;
	//cout << "b = "<<b << endl;
	//mySwap(a, b);//��ʽ����,�Զ������Ƶ������뵼��һ�µ���������

	//cout << "a = " << a << endl;
	//cout << "b = " << b << endl;
	//
	////��ʽ����
	//mySwap<int>(a, b);
	//cout << "a = " << a << endl;
	//cout << "b = " << b << endl;

	//��֮û�¾�����ʽ���ã����ⷢ������Ҫ�Ĵ���
	//func<int>();//���û����ʽ�ĵ��õĸú����޷������ã���ΪTû�б�ȷ��

	/*int arr[] = { 0,2,5,4,6,7,8,9,10,1 };
	int num = sizeof(arr) / sizeof(int);
	 mysort<int>(arr,num);
	 */

	int a = 10, b = 20;
	myPrint(a, b);//���ȵ�����ͨ����
	cout << endl;
	//ͨ����ģ��Ĳ����б����ǿ�Ƶ��ú���ģ��
	myPrint<>(a, b);
	myPrint(a, b, 10);

	//�������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��
	char m = 'c';
	char n = 'b';
	myPrint(m, n);

	return 0;


}