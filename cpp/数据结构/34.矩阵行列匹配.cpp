#include<iostream>
#include<fstream>
#include<vector>
#include<numeric>
int Acount(std::vector<std::vector<int>>arr, int line, int colunm) {
    std::vector<int>lineSum;
    std::vector<int>colunmSum;
    for (auto i : arr) {
        lineSum.push_back(accumulate(i.begin(), i.end(), 0));
    }//行求和
   
    //列求和：
    for (int i = 0; i < colunm; i++) {
        int sum = 0;
        for (int j = 0; j < line; j++) {
            
            sum += arr[j][i];
        }
        colunmSum.push_back(sum);
    }

    //比较相等：
    int acount = 0;
    for (auto i : lineSum) {
        for (auto j : colunmSum) {
            if (i != j) {
                continue;
            }
            acount++;
        }
    }
  
    return acount;
}

int main34() {
    std::fstream fst;
    fst.open("in.txt");
    int line = 0, colunm = 0;
    fst >> line >> colunm;
    std::vector<std::vector<int>>arr;
    for (int i = 0; i < line; i++) {
        std::vector<int>datas;
        for (int j = 0; j < colunm; j++) {
            int data;
            fst >> data;
            datas.push_back(data);
        }
        arr.push_back(datas);
    }
 /*   for (auto i : arr) {
        for (auto k : i) {
            std::cout << k << " ";
        }
        std::cout << std::endl;
    }*/
    fst.close();
    fst.open("out.txt", std::ios::out);
    fst << Acount(arr, line, colunm);


    return 0;
}