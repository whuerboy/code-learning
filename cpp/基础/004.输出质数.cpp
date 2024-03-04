#include<iostream>
#include<cmath>
using namespace std;
int main4()
{
	int i, j, k, flag;
	i = 2;
	while (i <= 100) {
		flag = 1;
		k =(int) sqrt(i);//sqrt是开平方，得到的是double类型，要强制转换为INT，不然会造成数据丢失。
		j = 2;
		while (j <= k) {
			if (i % j == 0) { flag = 0;
			break; 
			}
			j++;
		}
		if (flag) {
			cout << i << "是质数." << endl;	
		}
		i++;
	}
	return 0;
}