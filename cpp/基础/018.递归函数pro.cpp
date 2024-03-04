#include<iostream>;
using namespace std;
int getD(int n, int m) {
	if (n == 0) return 1;
	else if (n == 1) return m;
	else if (n > 1)
		return (2 * n - 1) * m * getD(n - 1, m) - (n - 1) * getD(n - 2, m);

}

int getPower(int x, int y) {
	if (y == 0) return 1;
	else return x * getPower(x, y - 1);
}

int main18() {

	int n, m;
	cin >> m>> n;
	cout << m << "的" << n << "阶类让的多项式的值是" << getD(n, m)<<endl;
	cout << getPower(m, n);
	return 0;
}