#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
int main1(void) {

	char flag;
	while (1) {
		cout << "����������";
		cin >> flag;
		if (toupper(flag) == 'Y') {
			cout << "��������";
			break;
		}
		else if (toupper(flag) == 'N') {
			cout << "���ڲ�����";
			break;
		}
		 if(toupper(flag)!='Y' && toupper(flag)!='N') {
			continue;
		}
		
		return 0;
	}

}