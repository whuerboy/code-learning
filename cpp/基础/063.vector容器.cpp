//stl�е���������������㷺��һЩ���ݽṹʵ�ֳ���

//vector���ݽṹ����������ƣ�ֻ���������Ǿ�̬�ռ��vector�Ƕ�̬�ռ�
//��̬��չ��������ԭ�ռ���������չ������һ��������ڴ�ռ佫Ԫ���ݿ����������ͷ�ԭ�ռ�

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//vector���������������
void Printvector(vector<int>& v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << "  ";
	}
}

void myout(int &m) {
	cout << m << endl;
}


  void test1() {
	vector<int> v;//����һ���������൱������

	//�������м�������
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(20);

	//ͨ���������������ݣ�
	//vector<int>::iterator itBegin = v.begin();//��ʼ������
	//vector<int>::iterator itEnd = v.end();//����������
	//while (itBegin != itEnd) {
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}


	/*for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}*/


	//��׼�㷨��
	for_each(v.begin(), v.end(), myout);
}


void test2()//����Ƕ�ף���ά����
{
	vector<vector<int>>arr;//����Ƕ��
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

	//��������������
	arr.push_back(v1);
	arr.push_back(v2);
	arr.push_back(v3);
	arr.push_back(v4);

	for (vector<vector<int>>::iterator it = arr.begin(); it != arr.end(); it++) {
		for_each(it->begin(), it->end(), myout);
		cout << endl;
	}

}


//vector�Ĺ��캯����
void test6() {
	vector<int> v1;//Ĭ���޲������캯��
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	Printvector(v1);
	cout << endl;

	//ͨ���������ʽ���죺
	vector<int>v2(v1.begin(), v1.end());
	Printvector(v2);
	cout << endl;

	//�����ͬ��elem����:
	vector<int>v3(10, 100);//10��100
	Printvector(v3);
	cout << endl;

	//�������죺
	vector<int>v4(v3);
	Printvector(v4);

}


//VECTOR�ĸ�ֵ��
void test7() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	Printvector(v1);
	cout << endl;

	vector<int> v2;
	v2 = v1;//���������֮�����ֱ�Ӹ�ֵ
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


//vector�������ʹ�С;
void test8() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	Printvector(v1);
	cout << endl;

	if (v1.empty()) {
		cout << "������Ϊ��" << endl;
	}
	else {
		cout << "v1����" << endl;
		cout << "capacity = " << v1.capacity() << endl;
		cout << "rize = " << v1.size() << endl;
	}

	//resize ����ָ����С��
	v1.resize(20);
	Printvector(v1);
	cout << endl;

	v1.resize(25, 100);
	Printvector(v1);
	cout << endl;
	

	v1.resize(10);
	Printvector(v1);

}


//vector�Ĳ����ɾ������Ҫ������
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

	//���룺
	v1.insert(v1.begin(), 100);//��һ��������һ��������,��ǰ����
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

	//ɾ����
	v1.erase(v1.begin()+1);//����Ҳ�ǵ�����
	Printvector(v1);
	cout << endl;

	v1.erase(v1.begin(), v1.begin() + 2);//ע��������[m,n)����ʽ
	Printvector(v1);
	cout << endl;

	//��գ�
	v1.clear();
	cout << endl;
	Printvector(v1);
	if (v1.empty()) {
		cout << "�ѱ����" << endl;
	}
}


//���ݵĴ�ȡ�����ݵ�����
void test10() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << " ";
	 }
	cout << endl;

	//����at���ʣ�
	for (int t = 0; t < v1.size(); t++) {
		cout << v1.at(t) << " ";
	}
	//��ȡ��һ��Ԫ�أ�front()   ���һ��Ԫ�أ� back();
}


//vector����������
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

	//��������
	cout << "����" << endl;
	v1.swap(v2);
	Printvector(v1);
	cout << endl;
	Printvector(v2);
	cout << endl;
	//swap������С����������
	vector<int> v;
	for (int i = 0; i < 10000; i++) {
		v.push_back(9 - i);
	}
	cout << "���������� = " << v.capacity() << endl;
	cout << "size = " <<v.size() << endl;

	v.resize(10);
	cout << "���������� = " << v.capacity() << endl;
	cout << "size = " << v.size() << endl;//ֻ�ı�sizeû�иı�������ɿռ��˷�


	//��swap����
	vector<int>(v).swap(v);//��v��ʼ��һ����������Ȼ���v������������������ᱻ����������
	cout << "���������� = " << v.capacity() << endl;
	cout << "size = " << v.size() << endl;

}


//�����ռ�Ԥ����
//����vector�ڶ�̬��չʱ��������չ������Ԥ����λ�ò����Գ�ʼ����Ԫ�ز��ܷ���
void test13() {
	int num = 0;//ͳ�ƿ��ٴ���
	int* p = NULL;
	vector<int> v;
	for (int i = 0; i < 10000; i++) {
		v.push_back(i);
		if (p != &v[0]) {
			p = &v[0];
			num++;
		}
	}
	cout << "���ٿռ�Ĵ���Ϊ " << num<<endl;
	num = 0;
	p = NULL;
	vector<int>v2;
	v2.reserve(10000);//Ԥ��10000
	for (int i = 0; i < 10000; i++) {
		v2.push_back(i);
		if (p != &v2[0]) {
			p = &v2[0];
			num++;
		}
	}
	cout << "���ٿռ�Ĵ���Ϊ " << num;
}

int main63() {
	test9();
	return 0;
}