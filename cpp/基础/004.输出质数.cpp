#include<iostream>
#include<cmath>
using namespace std;
int main4()
{
	int i, j, k, flag;
	i = 2;
	while (i <= 100) {
		flag = 1;
		k =(int) sqrt(i);//sqrt�ǿ�ƽ�����õ�����double���ͣ�Ҫǿ��ת��ΪINT����Ȼ��������ݶ�ʧ��
		j = 2;
		while (j <= k) {
			if (i % j == 0) { flag = 0;
			break; 
			}
			j++;
		}
		if (flag) {
			cout << i << "������." << endl;	
		}
		i++;
	}
	return 0;
}