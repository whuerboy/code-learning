//����Ԫ���ڲ���ʱ�ᱻ����
//set�����в���������ͬ��ֵ
//set����������ָ����С,�д�С�ͽ��� size(),empty(),swap()
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

	//set�Ĳ����ɾ����
	s.erase(s.begin());
	printSet(s);
	s.erase(60);
	printSet(s);
	

	//set�Ĳ��Һ�ͳ�ƣ�
	set<int>::iterator it = s.find(70);
	if (it != s.end()) {
		cout << "�ҵ���" << endl;
	}
	cout << "70�ĸ����� " << s.count(20) << endl;//ֻ��0��1
}



//ָ�������������
class MyCompare {
public:
	bool operator() (int v1, int v2) const//�°汾
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

//�Զ�����������-����
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