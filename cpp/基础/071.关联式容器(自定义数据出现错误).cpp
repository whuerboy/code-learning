//所有元素在插入时会被排序
//set容器中不允许有相同的值
//set不允许重新指定大小,有大小和交换 size(),empty(),swap()
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

void printSet(set<int>& s) {
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl;
}

void testset() 
{
	set<int> s;
	s.insert(10);
	s.insert(50);
	s.insert(20);
	s.insert(70);
	s.insert(60);
	s.insert(70);
	printSet(s);

	//set的插入和删除：
	s.erase(s.begin());
	printSet(s);
	s.erase(60);
	printSet(s);
	

	//set的查找和统计：
	set<int>::iterator it = s.find(70);
	if (it != s.end()) {
		cout << "找到了" << endl;
	}
	cout << "70的个数： " << s.count(20) << endl;//只有0和1
}



//指定排序规则排序：
class MyCompare {
public:
	bool operator() (int v1, int v2) const//新版本
	{
		return v1 > v2;
	}
};

void testt() {
	set<int,MyCompare> s;
	s.insert(10);
	s.insert(50);
	s.insert(20);
	s.insert(70);
	s.insert(60);
	s.insert(70);
	for (set<int,MyCompare>::iterator it1 = s.begin(); it1 != s.end(); it1++) {
		cout << *it1 << "  ";
	}
	cout << endl;
}

//自定义数据类型-排序：
class personset {
public:
	string name;
	int age;
	personset(string name, int age) :name(name), age(age) {

	};
};

class Compare {
public:
	bool operator()(const personset &p1,const personset &p2) const {
		return p1.age > p2.age;
	}
};


void tete() {
	set<personset,Compare> s;
	personset p1("liu", 66);
	personset p2("asu", 56);
	personset p3("zhuang", 654);
	personset p4("lsdg", 45);
	personset p5("ldhsg", 88);
	s.insert(p1);	s.insert(p2);	s.insert(p3);	s.insert(p4);	s.insert(p5);
	for (set<personset, Compare>::const_iterator it = s.begin(); it != s.end(); it++) {
		cout << "name = " << it->name << "  age = " << it->age << endl;
	}
}




int main71() {
	tete();
	return 0;
}