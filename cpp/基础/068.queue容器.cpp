//queue�������ƹ��������Ƚ��ȳ������ܱ���
//ֻ�ж�ͷ�Ͷ�β���Ա������ʣ��Ӷ�ͷ������βpush
#include<iostream>
#include<queue>
using namespace std;
void testIV() {
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	while (!q.empty()) {
		cout << "��ͷ:" << q.front() << endl;
		cout << "��β: " << q.back() << endl;
		q.pop();
		cout <<"����"<< endl;
		cout << endl;
	}

}

int main68() {
	testIV();
	return 0;
}