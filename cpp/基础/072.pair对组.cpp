#include<iostream>
using namespace std;


void testb() {
	pair<string, int> p("tom", 19);
	cout << "ÐÕÃû£º " << p.first << "ÄêÁä £º " << p.second << endl;

	pair<string, int> p1 = make_pair("jim", 1000);
	cout << p1.first << endl;
	cout << p1.second << endl;
}