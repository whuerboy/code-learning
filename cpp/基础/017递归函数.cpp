#include<iostream>;
using namespace std;
int add(int m) {
	if (m == 0) return 0;
	else return m + add(m - 1);
}

int getF(int n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	if (n >= 3) {
		return getF(n - 1) + getF(n - 2);
	}
}

int main17() {

	int m;
	cin >> m;
	int n = add(m);
	cout << n << endl;
	int f = getF(m);
	cout << f;

	return 0;
}
