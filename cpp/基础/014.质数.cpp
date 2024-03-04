#include<iostream>;
using namespace std;
int isZhi(int m) {
	int c;
	if (m == 0|| m ==1) {
		c = -1;
	}
	else {
		int n = 2;
		while (n < m) {
			if (m % n == 0) {
				c = 1;
				break;
			}
			else {
				c = 0;
				n++;
			}
		}

	}
	return c;
}

int main14(){

	int con;
	cin >> con;
	int s = isZhi(con);
	if (s == 1) {
		cout << "con不是质数" << con << endl;
	}
	else if(s==0){
		cout << "con是质数" << con << endl;
	}
	else if (s == -1) {
		cout << "请重新输入";
	}
	


	return 0;
}