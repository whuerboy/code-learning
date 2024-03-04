#include<iostream>
using namespace std;

template<class T>
class Father {
public:T age;
};



class Son1 :public Father<int> {

};//在继承是要指定好父类中的T类型才能成功继承


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
};//若想灵活的指定数据类型，子类也需要模板化


int main59() {

	Son2<int, string>s2(17,"xiao");
	s2.out();
	return 0;
}