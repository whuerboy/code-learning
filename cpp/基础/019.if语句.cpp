#include<iostream>
using namespace std;
int main19() {

	int x, y, z;
	cin >> x >> y;
	//z = x > y ? x: y;
	if (x > y) {
		z = x;
	}
	else z = y;
	cout << z;
	return 0;
}