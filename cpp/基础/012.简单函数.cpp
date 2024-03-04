#include<iostream>;
using namespace std;
int m(int& a, int& b) {
	int n;
	if (b != 0) {
		return a / b;
	}
	else return 0;

}

int main12() {
	int x, y;
	cin >> x >>y;
	int c = m(x, y);
	cout << c;
	return 0;
}