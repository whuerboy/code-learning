#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

void TwoBubbleSort(vector<int>& v) {
	int left = 0, right = v.size() - 1, flag = 1;
	//分别从左开始(将最大放到最右) 从右开始(将最小放到最左)   
	//flag用于记录左右已排序位置
	while (left < right) {
		//向右
		for (int i = left; i < right; i++) {
			if (v[i] > v[i + 1]) {
				swap(v[i], v[i + 1]);
				flag = i;
			}
		}
		right = flag;
		//向左
		for (int i = right; i > left; i--) {
			if (v[i] < v[i - 1]) {
				swap(v[i], v[i - 1]);
				flag = i;
			}
		}
		left = flag;
	}
	//当left==right时,即完成了排序
}


void show(vector<int>& v) {
	for (auto& x : v)
		cout << x << " ";
	cout << endl;
}


int	main056() {
	vector<int> v;
	srand((int)time(0));
	int n = 50;          //随机生成50个数字
	while (n--)
		v.push_back(rand() % 100 + 1);  //数字范围[1, 100]
	show(v);

	TwoBubbleSort(v);

	cout << endl << endl;
	show(v);
	return 0;
}