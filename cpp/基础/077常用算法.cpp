#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
#include<vector>

void print01(int m) {
	cout << m<<"  ";
}

class print02 {
public:
	void operator()(int m) {
		cout << m << "  ";
	}
};


//遍历算法： for_each
void testeach() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);                                                                               
	}

	//遍历算法
	for_each(v.begin(), v.end(), print01);
	cout << endl;
	for_each(v.begin(), v.end(), print02());
}



//遍历算法：搬运算法transform( , , , );


class Trans {
public: 
	int operator()(int m)
	{
	cout << m<<"  ";
	return m+100;
	}
};


void testran() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), print01);
	cout << endl;

	vector<int> v1;//目标容器
	v1.resize(v.size());//目标容器要提前开辟空间
	transform(v.begin(), v.end(), v1.begin(), Trans());//这里注意一下Trans重载函数的返回类型由容器的类型<int>决定
	cout << endl;
	for_each(v1.begin(), v1.end(), print01);
}


//查找算法f ind:返回迭代器，如果不存在返回end(),如果要查找自定义的数据类型，要重载==号                                   

void testfind() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it != v.end()) {
		cout << "找到惹" << endl;
	}
	else {
		cout << "找不到" << endl;
	}

}



//查找算法：find_if 按条件查找元素，返回迭代器

class greater1 {
public:
	bool operator()(int m) {
		return m > 5;
	}
};

void testif() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	vector<int>::iterator it= find_if(v.begin(), v.end(), greater1());
	if (it != v.end()) {
		cout << "找到热" << endl;
	}
	else {
		cout << "没找到" << endl;
	}
}


//查找算法：adjacent_find ：查找重复相邻的元素
void testadj() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(40);
	v.push_back(30);
	v.push_back(10);
	v.push_back(20);
	v.push_back(20);
	v.push_back(10);

	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it != v.end()) {
		cout << "又被找到惹" << endl;
		cout << *it << endl;
	}
}

//查找算法：binary_search ，返回fool，查找元素是否存在，不能在无须的序列中不能使用
//如果是无序的那返回的结果不可知
void testbinary() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	if (binary_search(v.begin(), v.end(), 9)) {
		cout << "找到9了" << endl;
	}
	else {
		cout << "找不到" << endl;
	}

 }


//查找算法：count 查找数据的个数,查找自定义数据类型时要重载==符号，而且是在自定义类中定义
void testcount() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(40);
	v.push_back(30);
	v.push_back(10);
	v.push_back(20);
	v.push_back(20);
	v.push_back(10);

	int sum		= count(v.begin(), v.end(), 10);
	cout << "10的个数为 " << sum << endl;
}


//查找算法： count_if 按条件查找，返回int
class personif {
public:
	string  name;
	int  age;
	personif(string name, int age) :name(name), age(age) {

	}
};

class personcount {
public:
	bool operator()(personif& p1) {
		return p1.age < 18;
	}
};


void test_count_if() {
	vector<personif> v;
	personif p1("丈夫", 19);
	personif p2("小孩", 1);
	personif p3("男孩", 14);
	personif p4("爸爸", 39);
	personif p5("爷爷", 69);
	v.push_back(p1); v.push_back(p2); v.push_back(p3); v.push_back(p5); v.push_back(p4);
	int m = count_if(v.begin(), v.end(), personcount());
	cout << "满足条件的人数为 m: " << m << endl;
}


//常用排序算法：sort(v.begin(),v.end(),greater<int>());从大到小排序


//random_shuffle:洗牌，直接乱序
void testrandom() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	srand((unsigned int)time(NULL));
	random_shuffle(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//mergr:合并两个有序的容器并且储存在另一个容器中,排完之后任然有序
void testmerge() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i+100);
	}

	vector<int> v2;

	v2.resize(v.size() + v1.size());//提前开辟空间

	merge(v1.begin(), v1.end(), v.begin(), v.end(), v2.begin());
	for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl;
}


//reverse:元素反转
void testreverse() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl;
	cout << "--------------------" << endl;
	reverse(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << "  ";
	}
}


//拷贝的替换算法：copy
void test_copy() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), print01);
	cout << endl;
	vector<int>v1;
	v1.resize(v.size());
	copy(v.begin(), v.end(), v1.begin());
	for_each(v1.begin(), v1.end(), print01);
}


//替换算法：replace
void test_replace() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	cout << "替换前" << endl;
	for_each(v.begin(), v.end(), print01);
	cout << endl << "-------------------------" << endl;
	cout << "替换后：" << endl;
	replace(v.begin(), v.end(), 2, 200);//将2替换成200;
	for_each(v.begin(), v.end(), print01);
}


//repalce_if:按条件替换
void test_replace_if() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	cout << "替换前" << endl;
	for_each(v.begin(), v.end(), print01);
	cout << endl << "-------------------------" << endl;
	cout << "替换后：" << endl;
	replace_if(v.begin(), v.end(), greater1(), 200);;
	for_each(v.begin(), v.end(), print01);
}

//swap()


int main77() {
	
	//testeach();
	//testran();
	cout << endl;
	//testcount();
	//test_count_if();
	//testrandom();
	//testmerge();
	//testreverse();
	//test_copy();
	test_replace_if();
	return 0;
}