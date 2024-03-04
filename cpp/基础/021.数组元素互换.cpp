#include<iostream>
using namespace std;
int main21() {
	int arr[6] = { 1,2,3,4,5,6 };
	int brr[6];
	for (int i = 0; i < 6; i++) {
		brr[i] = arr[i];
	} 
	for (int i = 0; i < 6; i++) {
		arr[i] = brr[5 - i];
	}
	for (int i = 0; i < 6; i++) {
		cout << arr[i] << "  ";
	}




	return 0;

}