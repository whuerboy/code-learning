//queue容器类似公交车，先进先出，不能遍历
//只有队头和队尾可以被外界访问，从对头出，队尾push
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
		cout << "队头:" << q.front() << endl;
		cout << "队尾: " << q.back() << endl;
		q.pop();
		cout <<"出队"<< endl;
		cout << endl;
	}

}

int main68() {
	testIV();
	return 0;
}