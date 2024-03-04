#include<iostream>
using namespace std;
int main7() {

	int currVal = 0, val = 0;
	if (cin >> currVal) {
		int cnt = 1;//保存我们正在处理的当前值的个数
		while (cin >> val) {//读取剩余的数
			if (currVal == val)
			{
				++cnt;
			}//如果值相同则加1
			else {//否则打印前一个个数的值
				cout << currVal << " occurs " << cnt << " times" << endl;
				currVal = val;//记住新值
				cnt = 1;//重置计数器
			}
			
			
		}
		cout << currVal << " occurs " << cnt << " times" << endl;
		//打印最后一个数
	
	}


	return 0;
}


