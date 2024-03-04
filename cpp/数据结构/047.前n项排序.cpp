#include <iostream>
#include <algorithm>
#include <cstdio>
#include<fstream>
#include <cstring>
#include<vector>
using namespace std;


void BulleSort(std::vector<int>&data, int size) {
    bool ifSorted = false;
    int temp = 0;
 
        ifSorted = false;
        for (int j = data.size()-1; j > data.size()-size; j--) {
            //从大到小排序
            if (data[j] >= data[j - 1]) {
                temp = data[j];
                data[j] = data[j - 1];
                data[j - 1] = temp;
                ifSorted = true;
            }
        }
        if (!ifSorted) {
            return;//递归的出口
        }
    
        BulleSort(data, size - 1);
}


int main047(void)
{


    int num, size;
    std::vector<int>data;
    fstream fst;
    fst.open("in.txt");
    fst >> num >> size;
    for (int i = 0; i < num; i++) {
        int temp;
        fst >> temp;
        data.push_back(temp);
    }
    BulleSort(data, data.size());
    for (auto i : data) {
        std::cout << i << " ";
  }

    return 0;
}
