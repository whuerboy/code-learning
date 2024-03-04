#include<iostream>
using namespace std;
double division(double x, double y) {
	if (y == 0) {
		throw 15;
	}
	else {
		return x / y;
	}
}

int main4(string args[]) {
	double x;
	double y;
	cin >> x;
	cin >> y;
	try {
		cout << division(x, y) << endl;
	}
	catch (int s) {
		cerr << s << endl;
	}
	
	cout << "err" << endl;
	
	return 0;
}