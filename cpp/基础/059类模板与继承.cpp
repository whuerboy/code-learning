#include<iostream>
using namespace std;

template<class T>
class Father {
public:T age;
};



class Son1 :public Father<int> {

};//�ڼ̳���Ҫָ���ø����е�T���Ͳ��ܳɹ��̳�


template <class T1,class T2>
class Son2 :public Father<T1> {
public:T2 name;
	Son2(T1 age, T2 name) {
		this->age = age;
		this->name = name;
	};
	void out() {
		cout << "name= " << this->name << "  age= " << this->age << endl;
	}
};//��������ָ���������ͣ�����Ҳ��Ҫģ�廯


int main59() {

	Son2<int, string>s2(17,"xiao");
	s2.out();
	return 0;
}