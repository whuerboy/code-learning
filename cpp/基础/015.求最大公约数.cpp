#include<iostream>;
using namespace std;
int maxYue(int m, int n);
int main15() {
	int m, n;
	cin >> m >> n;
	int yue = maxYue(m, n);
	cout << yue << endl;
	


	return 0;
}

int maxYue(int m,int n){
	int yue;
	int min;
	if (m >= n)
		min = n;
	else min = m;
	for (int i=1; i <= min; i++) {
		if (m % i == 0 && n % i == 0) {
			yue = i;
		}

	}
	return yue;
}