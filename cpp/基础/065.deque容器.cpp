#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
//只有vector和queue容器提供迭代器算数运算和除!=和==之外的关系运算：


//deque是双端数据，可以对头端进行插入删除操作
void printDeque(const deque<int>& d) {
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}


//deque的构造函数
void testo() {
	deque<int> d;
	for(int i = 0;i<10;i++){
		d.push_back(i);
	}
	printDeque(d);
	cout << endl;

	deque<int>d1(d.begin() + 1, d.end());
	printDeque(d1);
}
//deque'的赋值操作和vector基本相同


//deque的大小操作:
//resize(),resize(num,elemnt),Empty(),size(),deque没有容量的概念


//deque的插入与删除：
void testI() {
	deque<int> d;

	//尾插：
	d.push_back(10);
	d.push_back(20);

	//头插：
	d.push_front(1);
	d.push_front(2);
	printDeque(d);
	cout << endl;

	//删：
	d.pop_front();
	printDeque(d);
	cout << endl;
	d.pop_back();
	printDeque(d);
	cout << endl;

	//插入
	d.insert(d.begin(), 1000);
	d.insert(d.end() - 1, 666);
	printDeque(d);
	cout << endl;
	//区间插入：
	deque<int> d1;
	d1.push_back(1);
	d1.push_back(2);
	d1.push_back(3);
	d.insert(d.begin(), d1.begin(), d1.end());
	printDeque(d);

	//删除：
	d.erase(d.begin() + 1);
	printDeque(d);

	d.clear();
	if (d.empty()) {
		cout << "yes" << endl;
	}

}

//数据存取：

//sort算法排序：
void testII() {
	deque<int>d;
	d.push_back(10);
	d.push_back(20);

	//头插：
	d.push_front(1);
	d.push_front(2);
	printDeque(d);

	sort(d.begin(), d.end());//升序
	printDeque(d);                                                                                                     
}


int main65() {
	testII();
	return 0;
}