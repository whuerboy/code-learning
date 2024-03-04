#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
//ֻ��vector��queue�����ṩ��������������ͳ�!=��==֮��Ĺ�ϵ���㣺


//deque��˫�����ݣ����Զ�ͷ�˽��в���ɾ������
void printDeque(const deque<int>& d) {
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}


//deque�Ĺ��캯��
void testo() {
	deque<int> d;
	for(int i = 0;i<10;i++){
		d.push_back(i);
	}
	printDeque(d);
	cout << endl;

	deque<int>d1(d.begin() + 1, d.end());
	printDeque(d1);
}
//deque'�ĸ�ֵ������vector������ͬ


//deque�Ĵ�С����:
//resize(),resize(num,elemnt),Empty(),size(),dequeû�������ĸ���


//deque�Ĳ�����ɾ����
void testI() {
	deque<int> d;

	//β�壺
	d.push_back(10);
	d.push_back(20);

	//ͷ�壺
	d.push_front(1);
	d.push_front(2);
	printDeque(d);
	cout << endl;

	//ɾ��
	d.pop_front();
	printDeque(d);
	cout << endl;
	d.pop_back();
	printDeque(d);
	cout << endl;

	//����
	d.insert(d.begin(), 1000);
	d.insert(d.end() - 1, 666);
	printDeque(d);
	cout << endl;
	//������룺
	deque<int> d1;
	d1.push_back(1);
	d1.push_back(2);
	d1.push_back(3);
	d.insert(d.begin(), d1.begin(), d1.end());
	printDeque(d);

	//ɾ����
	d.erase(d.begin() + 1);
	printDeque(d);

	d.clear();
	if (d.empty()) {
		cout << "yes" << endl;
	}

}

//���ݴ�ȡ��

//sort�㷨����
void testII() {
	deque<int>d;
	d.push_back(10);
	d.push_back(20);

	//ͷ�壺
	d.push_front(1);
	d.push_front(2);
	printDeque(d);

	sort(d.begin(), d.end());//����
	printDeque(d);                                                                                                     
}


int main65() {
	testII();
	return 0;
}