#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

void TwoBubbleSort(vector<int>& v) {
	int left = 0, right = v.size() - 1, flag = 1;
	//�ֱ����ʼ(�����ŵ�����) ���ҿ�ʼ(����С�ŵ�����)   
	//flag���ڼ�¼����������λ��
	while (left < right) {
		//����
		for (int i = left; i < right; i++) {
			if (v[i] > v[i + 1]) {
				swap(v[i], v[i + 1]);
				flag = i;
			}
		}
		right = flag;
		//����
		for (int i = right; i > left; i--) {
			if (v[i] < v[i - 1]) {
				swap(v[i], v[i - 1]);
				flag = i;
			}
		}
		left = flag;
	}
	//��left==rightʱ,�����������
}


void show(vector<int>& v) {
	for (auto& x : v)
		cout << x << " ";
	cout << endl;
}


int	main056() {
	vector<int> v;
	srand((int)time(0));
	int n = 50;          //�������50������
	while (n--)
		v.push_back(rand() % 100 + 1);  //���ַ�Χ[1, 100]
	show(v);

	TwoBubbleSort(v);

	cout << endl << endl;
	show(v);
	return 0;
}