#include"hanshu.h"
#include<iostream>
using namespace std;

void swap(int* m, int* n) {
	int a = *m;
	*m = *n;
	*n = a;
	cout << "�����ɹ�" << endl;
}