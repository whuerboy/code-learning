//map�е�����Ԫ�ض���pair����һ��Ԫ����keyֵ���������������ڶ�����value��key������ͬ
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
	map<int, int,myCompany> m;//�Ӵ�С����Ĭ�ϴ�С����
	m.insert(pair<int, int>(1, 143));
	m.insert(pair<int, int>(3, 134));
	m.insert(pair<int, int>(4, 13));
	m.insert(pair<int, int>(2, 40));
	m.insert(pair<int, int>(6, 10));
	printMap(m);

	//map�Ĳ����ɾ����
	m.insert(make_pair(10, 100));
	m.insert(map<int, int>::value_type(5, 70));
	m[9] = 10;//���ǲ������������룬����������keyΪ9ʱ��valueֵ
	//��������û��keyΪ9�Ķ���ʱ���������Լ�����һ������valueΪ0���������������ʱ�ͻ���Ӳ��ɹ�

	cout << endl; cout << endl;
	//ɾ����
	m.erase(3);//ɾ��keyΪ3�Ķ���
	m.erase(m.begin());
	printMap(m);


	//map�Ĳ�����ͳ�ƣ�
	map<int, int>::iterator pos = m.find(4);
	if (pos != m.end()) {
		cout << "�ҵ���" <<"  value = "<<pos->second << endl;
	}
	else {
		cout << "������" << endl;
	}

	int num = m.count(3);
	cout << " num = " << num << endl;
	
}




int main73() {
	tetst();
	return 0;
}
