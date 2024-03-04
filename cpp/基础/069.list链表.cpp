#include<iostream>
#include<list>
#include<algorithm>

using namespace std;
//list之间是独立的，由结点组成，而节点由指针域和数据 域组成，每个节点的指针域记录的是下一个节点的位置
//优点：可以对任意位置进行快速插入或删除元素。动态内存分配，不会造成内存的浪费和溢出
//但是遍历的速度较慢，而且占用空间大

//stl中的链表是一个双向的链表，指针域中一个指针指向下一个节点，另一个指针指向上一个节点
//双向迭代器，只支持前移和后移


void printList(const list<int> l) {
	for (list<int>::const_iterator it = l.begin(); it != l.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl;
}

bool myCompare(int m,int n) {
	//降序：第一个大于第二个
	return m > n;
}

//list的构造函数：和前面基本相同
void test0() {
	list<int> l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	l.push_back(50);
	printList(l);

	//区间构造：
	list<int> l1(l.begin(),l.end());
	printList(l1);
}


//list交换：
void test002() {
	list<int> l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	l.push_back(50);
	printList(l);

	list<int>l2;
	l2.assign(10, 100);
	printList(l2);

	l2.swap(l);
	printList(l);
	printList(l2);
	cout << "l2.size = " << l2.size() << endl;
}


//list的大小操作：empty()  size()

//list的插入和删除：
void test003() {
	list<int> l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	l.push_back(50);
	printList(l);
	l.push_front(100);
	l.push_front(200);
	l.push_front(300);
	printList(l); 

	l.insert(++l.begin(), 1000);//迭代器可以进行++，--操作但不可以+，-具体的数
	printList(l);
	l.erase(--(--(--l.end())));
	l.remove(200);//remove(num)可以直接将list容器中所有值与num匹配的元素全部删除
	l.pop_front();
	printList(l);
}


//list容器的数据存取不支持[],还有at函数访问，只支持迭代器的前移和后移操作，所有他的接口只有front()和back（）,得到首尾的两个元素

//list容器的反转和排序：
void test004() {
	list<int> l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	l.push_back(50);
	l.push_front(100);
	l.push_front(200);
	l.push_front(300);
	printList(l);

	l.reverse();//反转操作
	cout << "反转后" << endl;
	printList(l);
	cout << "排序后" << endl;

	//所有不支持随机访问的迭代器不可以采用标准算法，但是内部会提供对应的算法
	l.sort();//升序
	printList(l);
	l.sort(myCompare);
	printList(l);
}




int main69() {
	
	return 0;
}