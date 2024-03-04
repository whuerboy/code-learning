#include<iostream>
 namespace A  {
	 int b = 10;
	 int a = 20;

	 int add(int m, int n) {
		 return m + n;
	 }
}
 using namespace A;

 namespace std {
	 int add(int m,int n) {
		 return m + 100;
	 }
 }

 int main1() {
	 std::cout << " b = " << b<<std::endl;
	 std::cout << " a = " << a << std::endl;
	 using namespace std;
	 int a = 50;
	 int b = 20;
	 cout << "std: b = " << b << endl;
	 cout << "std: a = " << a << endl;
	 cout << "A: b = " << A::b << endl;
	 cout << "A: a = " << A::a << endl;
	 cout << "A;a+A:b = " << A::add(A::a, A::b) << endl;
	 cout << "a+b = " << std::add(a, b) << endl;
	 return 0;
 }