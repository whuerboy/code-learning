//stl中的容器：将运用最广泛的一些数据结构实现出来

//vector数据结构和数组很类似，只不过数组是静态空间而vector是动态空间
//动态扩展并不是在原空间下往后扩展而是找一个更大的内存空间将元数据拷贝到这里释放原空间

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//vector存放内置数据类型
void Printvector(vector<int>& v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << "  ";
	}
}

void myout(int &m) {
	cout << m << endl;
}


  void test1() {
	vector<int> v;//创建一个容器，相当于数组

	//像容器中加入数据
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(20);

	//通过迭代器访问数据：
	//vector<int>::iterator itBegin = v.begin();//起始迭代器
	//vector<int>::iterator itEnd = v.end();//结束迭代器
	//while (itBegin != itEnd) {
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}


	/*for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}*/


	//标准算法：
	for_each(v.begin(), v.end(), myout);
}


void test2()//容器嵌套：多维数组
{
	vector<vector<int>>arr;//容器嵌套
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	vector<int>v4;
	for (int i=0; i < 4; i++) {
		v1.push_back(i + 1);
		v2.push_back(i + 5);
		v3.push_back(i + 10);
		v4.push_back(i + 15);
	}

	//外层容器添加数据
	arr.push_back(v1);
	arr.push_back(v2);
	arr.push_back(v3);
	arr.push_back(v4);

	for (vector<vector<int>>::iterator it = arr.begin(); it != arr.end(); it++) {
		for_each(it->begin(), it->end(), myout);
		cout << endl;
	}

}


//vector的构造函数：
void test6() {
	vector<int> v1;//默认无参数构造函数
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	Printvector(v1);
	cout << endl;

	//通过区间的形式构造：
	vector<int>v2(v1.begin(), v1.end());
	Printvector(v2);
	cout << endl;

	//多个相同的elem构造:
	vector<int>v3(10, 100);//10个100
	Printvector(v3);
	cout << endl;

	//拷贝构造：
	vector<int>v4(v3);
	Printvector(v4);

}


//VECTOR的赋值：
void test7() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	Printvector(v1);
	cout << endl;

	vector<int> v2;
	v2 = v1;//重载运算符之后可以直接赋值
	Printvector(v2);
	cout << endl;


	vector<int> v3;
	v3.assign(v1.begin() + 1, v1.end() - 1);
	Printvector(v3);
	cout << endl;

	vector<int> v4;
	v4.assign(10, 100);
	Printvector(v4);


}


//vector的容量和大小;
void test8() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	Printvector(v1);
	cout << endl;

	if (v1.empty()) {
		cout << "该容器为空" << endl;
	}
	else {
		cout << "v1不空" << endl;
		cout << "capacity = " << v1.capacity() << endl;
		cout << "rize = " << v1.size() << endl;
	}

	//resize 重新指定大小：
	v1.resize(20);
	Printvector(v1);
	cout << endl;

	v1.resize(25, 100);
	Printvector(v1);
	cout << endl;
	

	v1.resize(10);
	Printvector(v1);

}


//vector的插入和删除：需要迭代器
void test9() {
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	Printvector(v1);
	cout << endl;
	v1.pop_back();
	Printvector(v1);
	cout << endl;

	//插入：
	v1.insert(v1.begin(), 100);//第一个数据是一个迭代器,往前插入
	Printvector(v1);
	cout << endl;
	v1.insert(v1.end(), 100);
	Printvector(v1);
	cout << endl;
	v1.insert(v1.end() - 3, 10);
	Printvector(v1);
	cout << endl;
	v1.insert(v1.begin() + 1, 2, 66);
	Printvector(v1);
	cout << endl;

	//删除：
	v1.erase(v1.begin()+1);//参数也是迭代器
	Printvector(v1);
	cout << endl;

	v1.erase(v1.begin(), v1.begin() + 2);//注意区间是[m,n)的形式
	Printvector(v1);
	cout << endl;

	//清空：
	v1.clear();
	cout << endl;
	Printvector(v1);
	if (v1.empty()) {
		cout << "已被清空" << endl;
	}
}


//数据的存取：数据的索引
void test10() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << " ";
	 }
	cout << endl;

	//利用at访问：
	for (int t = 0; t < v1.size(); t++) {
		cout << v1.at(t) << " ";
	}
	//获取第一个元素：front()   最后一个元素： back();
}


//vector容器互换：
void test11() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	cout << "v1:";
	Printvector(v1);
	cout << endl;

	vector<int> v2;
	for (int i = 0; i < 10; i++) {
		v2.push_back(9-i);
	}
	cout << "v2:";
	Printvector(v2);
	cout << endl;

	//交换容器
	cout << "交换" << endl;
	v1.swap(v2);
	Printvector(v1);
	cout << endl;
	Printvector(v2);
	cout << endl;
	//swap可以缩小容器的容量
	vector<int> v;
	for (int i = 0; i < 10000; i++) {
		v.push_back(9 - i);
	}
	cout << "容器的容量 = " << v.capacity() << endl;
	cout << "size = " <<v.size() << endl;

	v.resize(10);
	cout << "容器的容量 = " << v.capacity() << endl;
	cout << "size = " << v.size() << endl;//只改变size没有改变容量造成空间浪费


	//用swap收缩
	vector<int>(v).swap(v);//用v初始化一个匿名对象然后和v交换，而且匿名对象会被编译器回收
	cout << "容器的容量 = " << v.capacity() << endl;
	cout << "size = " << v.size() << endl;

}


//容器空间预留：
//减少vector在动态拓展时容量的拓展次数，预留的位置不可以初始化，元素不能访问
void test13() {
	int num = 0;//统计开辟次数
	int* p = NULL;
	vector<int> v;
	for (int i = 0; i < 10000; i++) {
		v.push_back(i);
		if (p != &v[0]) {
			p = &v[0];
			num++;
		}
	}
	cout << "开辟空间的次数为 " << num<<endl;
	num = 0;
	p = NULL;
	vector<int>v2;
	v2.reserve(10000);//预留10000
	for (int i = 0; i < 10000; i++) {
		v2.push_back(i);
		if (p != &v2[0]) {
			p = &v2[0];
			num++;
		}
	}
	cout << "开辟空间的次数为 " << num;
}

int main63() {
	test9();
	return 0;
}