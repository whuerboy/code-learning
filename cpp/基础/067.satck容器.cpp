//stack�����൱��һ��ˮͰ����һ���Ƚ���������ݽṹ��ֻ��һ�����ڣ������������Ϊ
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

void testIII() {
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	while (!s.empty()) {
		cout << "ջ��Ԫ�� " << s.top() << endl;
		s.pop();//��ջ
	}

	cout << "zhan�Ĵ�С" << s.size() << endl;
}

int main67() {
	testIII();
	return 0;
}