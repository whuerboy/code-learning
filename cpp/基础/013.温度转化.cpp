#include<iostream>;
using namespace std;
double change(double m) {
	double c = 5*(m - 32)/9;
	return c;
}

int main13() {

	double f, s;
	cin >> f;
	s = change(f);
	cout << s;

	return 0;
}