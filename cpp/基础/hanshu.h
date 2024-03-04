#pragma once
#include<iostream>
using namespace std;
void swap(int& m, int& n); 
//头文件是c++的接口，不建议把函数的定义写在头文件中
void swap(int* m, int* n);
void change2(int& n);
void showMenu();
