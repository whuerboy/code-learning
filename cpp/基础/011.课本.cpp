#include<iostream>
using namespace std;
int main11(void) {

	int intOne;
	int &rSomeRef = intOne;
	cin >> intOne;
	cout << "intOne:\t" << intOne << endl;
	cout << "rSomeRef:\t" << rSomeRef << endl;
	int intTwo;
	cin >> intTwo;
	rSomeRef = intTwo;
	cout << "\nintOne:\t" << intOne << endl;
	cout << "intTwo:\t" << intTwo << endl;
	cout << "rSomeRef:\t" << rSomeRef << endl;
	return 0;
}