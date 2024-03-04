#include<iostream>
#include<list>
#include<algorithm>
#include<string>
using namespace std;
//list排序案例：
class personlist {
public:
	int age;
	int height;
	string name;
	personlist(int age, int height, string name) {
		this->age = age;
		this->height = height;
		this->name = name;
	};
};

ostream& operator<<(ostream& cout, personlist& p) {
	/*cout << "姓名：" << p.name << "," << "年龄：" << p.age;*/
	return cout;
}


void test0x() {
	list<personlist> l;
	personlist p1(35, 175, "zoo");
	personlist p2(45, 180, "cao");
	personlist p3(40, 170, "zhao");
	personlist p4(24, 190, "ma");
	personlist p5(35, 160, "zhsnag");
	personlist p6(35, 200, "gaun");

	l.push_back(p1); 
	l.push_back(p2);
	l.push_back(p3); 
	l.push_back(p4);
	l.push_back(p5); 
	l.push_back(p6);
	for (list<personlist>::const_iterator it = l.begin(); it != l.end(); it++) {
		cout << "姓名： " << (*it).name << " 年龄: " << (*it).age << " 身高： " << (*it).height << endl;
	}
}


int main70() {
	test0x();
	return 0;
}