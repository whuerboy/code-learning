//map中的所有元素都是pair，第一个元素是key值（用于索引），第二个是value，key不能相同
#include<iostream>
#include<map>
using namespace std;



class myCompany {
public:
	bool operator()(int m, int n) const
	{
		return m > n;
	}
};


void printMap(map<int, int,myCompany> m) {
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "key = " << it->first << "  value = " << it->second << endl;
	}
}

void tetst() {
	map<int, int,myCompany> m;//从大到小排序，默认从小到大
	m.insert(pair<int, int>(1, 143));
	m.insert(pair<int, int>(3, 134));
	m.insert(pair<int, int>(4, 13));
	m.insert(pair<int, int>(2, 40));
	m.insert(pair<int, int>(6, 10));
	printMap(m);

	//map的插入和删除：
	m.insert(make_pair(10, 100));
	m.insert(map<int, int>::value_type(5, 70));
	m[9] = 10;//但是不建议这样插入，可以用来找key为9时的value值
	//当容器中没有key为9的对组时编译器会自己创建一个而且value为0，这样后面再添加时就会添加不成功

	cout << endl; cout << endl;
	//删除：
	m.erase(3);//删除key为3的对组
	m.erase(m.begin());
	printMap(m);


	//map的查找与统计：
	map<int, int>::iterator pos = m.find(4);
	if (pos != m.end()) {
		cout << "找到了" <<"  value = "<<pos->second << endl;
	}
	else {
		cout << "不存在" << endl;
	}

	int num = m.count(3);
	cout << " num = " << num << endl;
	
}




int main73() {
	tetst();
	return 0;
}
