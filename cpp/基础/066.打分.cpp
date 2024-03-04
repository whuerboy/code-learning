#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<ctime>
using namespace std;


class person 
{
public:
	person(string name) {
		this->name = name;
	}
	string name;
	deque<int> score;
};

void printScore(person& p) {
	for (deque<int>::iterator it = p.score.begin(); it != p.score.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//��ֺ�����
void getscore(person& p) {
	
	int m = 0;
	for (int i = 0; i < 10; i++) {
		m = rand() % 41 + 60;
		p.score.push_back(m);		
	}
	//cout << "�ó�Ա�ĳɼ�������:" << endl;
	//printScore(p);

	//ƽ���ֻ�ȡ��
	sort(p.score.begin(), p.score.end());
	p.score.pop_back();
	p.score.pop_front();
	int sum = 0;
	for (int i = 0; i < p.score.size(); i++) {
		sum += p.score[i];
	}
	cout << "sum = " << sum << "   ";
	cout << "ƽ���֣�" << sum / p.score.size() << endl;
}

int main66() {
	srand((unsigned int)time(NULL));
	//����ѡ�֣�
	person a("A"), b("B"), c("C"), d("D"), e("E");
	vector<person> men;
	men.push_back(a); men.push_back(b); men.push_back(c); men.push_back(d); men.push_back(e);
	//���;
	for (int i = 0; i < men.size(); i++) {
		cout << "���������ѡ�� " << men[i].name << "���" << endl; 
		getscore(men[i]);
	}
	return 0;
}