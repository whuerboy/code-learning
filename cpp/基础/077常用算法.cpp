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


//�����㷨�� for_each
void testeach() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);                                                                               
	}

	//�����㷨
	for_each(v.begin(), v.end(), print01);
	cout << endl;
	for_each(v.begin(), v.end(), print02());
}



//�����㷨�������㷨transform( , , , );


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

	vector<int> v1;//Ŀ������
	v1.resize(v.size());//Ŀ������Ҫ��ǰ���ٿռ�
	transform(v.begin(), v.end(), v1.begin(), Trans());//����ע��һ��Trans���غ����ķ�������������������<int>����
	cout << endl;
	for_each(v1.begin(), v1.end(), print01);
}


//�����㷨f ind:���ص���������������ڷ���end(),���Ҫ�����Զ�����������ͣ�Ҫ����==��                                   

void testfind() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it != v.end()) {
		cout << "�ҵ���" << endl;
	}
	else {
		cout << "�Ҳ���" << endl;
	}

}



//�����㷨��find_if ����������Ԫ�أ����ص�����

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
		cout << "�ҵ���" << endl;
	}
	else {
		cout << "û�ҵ�" << endl;
	}
}


//�����㷨��adjacent_find �������ظ����ڵ�Ԫ��
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
		cout << "�ֱ��ҵ���" << endl;
		cout << *it << endl;
	}
}

//�����㷨��binary_search ������fool������Ԫ���Ƿ���ڣ�����������������в���ʹ��
//�����������Ƿ��صĽ������֪
void testbinary() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	if (binary_search(v.begin(), v.end(), 9)) {
		cout << "�ҵ�9��" << endl;
	}
	else {
		cout << "�Ҳ���" << endl;
	}

 }


//�����㷨��count �������ݵĸ���,�����Զ�����������ʱҪ����==���ţ����������Զ������ж���
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
	cout << "10�ĸ���Ϊ " << sum << endl;
}


//�����㷨�� count_if ���������ң�����int
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
	personif p1("�ɷ�", 19);
	personif p2("С��", 1);
	personif p3("�к�", 14);
	personif p4("�ְ�", 39);
	personif p5("үү", 69);
	v.push_back(p1); v.push_back(p2); v.push_back(p3); v.push_back(p5); v.push_back(p4);
	int m = count_if(v.begin(), v.end(), personcount());
	cout << "��������������Ϊ m: " << m << endl;
}


//���������㷨��sort(v.begin(),v.end(),greater<int>());�Ӵ�С����


//random_shuffle:ϴ�ƣ�ֱ������
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

//mergr:�ϲ�����������������Ҵ�������һ��������,����֮����Ȼ����
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

	v2.resize(v.size() + v1.size());//��ǰ���ٿռ�

	merge(v1.begin(), v1.end(), v.begin(), v.end(), v2.begin());
	for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl;
}


//reverse:Ԫ�ط�ת
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


//�������滻�㷨��copy
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


//�滻�㷨��replace
void test_replace() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	cout << "�滻ǰ" << endl;
	for_each(v.begin(), v.end(), print01);
	cout << endl << "-------------------------" << endl;
	cout << "�滻��" << endl;
	replace(v.begin(), v.end(), 2, 200);//��2�滻��200;
	for_each(v.begin(), v.end(), print01);
}


//repalce_if:�������滻
void test_replace_if() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	cout << "�滻ǰ" << endl;
	for_each(v.begin(), v.end(), print01);
	cout << endl << "-------------------------" << endl;
	cout << "�滻��" << endl;
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