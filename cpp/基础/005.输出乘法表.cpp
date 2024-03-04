#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main5(void) {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= i; j++) {
			cout << i << "x" << j << "=";
			if (i * j >= 1 && i * j <= 9) {
				printf("%1d  ", i * j);
			}
			else cout << i * j << " ";
		}
		cout << endl;
	}


	return 0;
}


