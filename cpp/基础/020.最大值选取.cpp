#include<iostream>
using namespace std;
int main20() {
	int pig[5]; 
	for (int i = 0; i < 5; i++) {
		cin >> pig[i];
	}
	int max = pig[0];
	for (int i = 1; i < 5; i++) {
		max = pig[i] > max? pig[i] : max;
	}
	cout << max;


	return 0;
}