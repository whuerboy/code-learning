#include<iostream>
using namespace std;
//�����øó���ʵ��ð������

void bubble(int * p, int len);
//����1�������׵�ַ
//����2������ĳ���

int main32() {
	void swap(int& a, int& b);//����һ����������,

	//1.����һ������
	int arr[11] = { 4,5,2,3,8,9,1,6,7,0 ,100};

	//2.��������ʵ��ð������
	int len = sizeof(arr) / sizeof(arr[0]);
	bubble(arr, len);

	//3.��ӡ���кõ�����
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
				//�ڴ˴�Ҳ����ʹ��ֵ���ݵķ�������Ϊ�����Ѿ���ָ����
				int a = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = a;
			}
		}
	}
}

