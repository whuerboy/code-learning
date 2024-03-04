#include<iostream>
#include<list>
#include<algorithm>

using namespace std;
//list֮���Ƕ����ģ��ɽ����ɣ����ڵ���ָ��������� ����ɣ�ÿ���ڵ��ָ�����¼������һ���ڵ��λ��
//�ŵ㣺���Զ�����λ�ý��п��ٲ����ɾ��Ԫ�ء���̬�ڴ���䣬��������ڴ���˷Ѻ����
//���Ǳ������ٶȽ���������ռ�ÿռ��

//stl�е�������һ��˫�������ָ������һ��ָ��ָ����һ���ڵ㣬��һ��ָ��ָ����һ���ڵ�
//˫���������ֻ֧��ǰ�ƺͺ���


void printList(const list<int> l) {
	for (list<int>::const_iterator it = l.begin(); it != l.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl;
}

bool myCompare(int m,int n) {
	//���򣺵�һ�����ڵڶ���
	return m > n;
}

//list�Ĺ��캯������ǰ�������ͬ
void test0() {
	list<int> l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	l.push_back(50);
	printList(l);

	//���乹�죺
	list<int> l1(l.begin(),l.end());
	printList(l1);
}


//list������
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


//list�Ĵ�С������empty()  size()

//list�Ĳ����ɾ����
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

	l.insert(++l.begin(), 1000);//���������Խ���++��--������������+��-�������
	printList(l);
	l.erase(--(--(--l.end())));
	l.remove(200);//remove(num)����ֱ�ӽ�list����������ֵ��numƥ���Ԫ��ȫ��ɾ��
	l.pop_front();
	printList(l);
}


//list���������ݴ�ȡ��֧��[],����at�������ʣ�ֻ֧�ֵ�������ǰ�ƺͺ��Ʋ������������Ľӿ�ֻ��front()��back����,�õ���β������Ԫ��

//list�����ķ�ת������
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

	l.reverse();//��ת����
	cout << "��ת��" << endl;
	printList(l);
	cout << "�����" << endl;

	//���в�֧��������ʵĵ����������Բ��ñ�׼�㷨�������ڲ����ṩ��Ӧ���㷨
	l.sort();//����
	printList(l);
	l.sort(myCompare);
	printList(l);
}




int main69() {
	
	return 0;
}