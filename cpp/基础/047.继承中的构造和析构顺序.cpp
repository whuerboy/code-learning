#include<iostream>
using namespace std;
class Base{
public:
	Base() {
		cout << "base�Ĺ��캯������" << endl;
	}
	~Base() {
		cout << "base ��������������" << endl;
	}

};

class Son :public Base {
public:
	Son() {
		cout << "son�Ĺ��캯������" << endl;
	}
	~Son() {
		cout << "son��������������" << endl;
	}
};

int main47() {

	Son s1;//�ȹ��츸�࣬�ڹ������࣬���������࣬����������

	return 0;
}