#include<iostream>
using namespace std;
int main7() {

	int currVal = 0, val = 0;
	if (cin >> currVal) {
		int cnt = 1;//�����������ڴ���ĵ�ǰֵ�ĸ���
		while (cin >> val) {//��ȡʣ�����
			if (currVal == val)
			{
				++cnt;
			}//���ֵ��ͬ���1
			else {//�����ӡǰһ��������ֵ
				cout << currVal << " occurs " << cnt << " times" << endl;
				currVal = val;//��ס��ֵ
				cnt = 1;//���ü�����
			}
			
			
		}
		cout << currVal << " occurs " << cnt << " times" << endl;
		//��ӡ���һ����
	
	}


	return 0;
}


