#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
int main1(void) {

	char flag;
	while (1) {
		cout << "现在下雨吗";
		cin >> flag;
		if (toupper(flag) == 'Y') {
			cout << "现在下雨";
			break;
		}
		else if (toupper(flag) == 'N') {
			cout << "现在不下雨";
			break;
		}
		 if(toupper(flag)!='Y' && toupper(flag)!='N') {
			continue;
		}
		
		return 0;
	}

}