//stack容器相当于一个水桶，是一种先进后出的数据结构，只有一个出口，不允许遍历行为
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
		cout << "栈顶元素 " << s.top() << endl;
		s.pop();//出栈
	}

	cout << "zhan的大小" << s.size() << endl;
}

int main67() {
	testIII();
	return 0;
}