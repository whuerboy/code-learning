#include<iostream>
#include<vector>
#include<fstream>
#include<math.h>
bool ifPrime(int n) {
	if (n <= 3) {
		return true;
	}
	for (int i = 2; i <= (int)sqrt(n); i++) {//如果n被i整除，则返回false
		if (n % i == 0) {
			return false;
			break;
		}
	}
	return true;    // 反之则返回true 
}



int findMaxSu(std::vector<int> num) {
	int maxNum=0;
	int maxSum=1;
	for (auto i : num) {
		for (int j = i; j > 0; j--) {
			if (i % j == 0 && ifPrime(j)) {
				if (j > maxSum) {
					maxSum = j;
					maxNum = i;
				}
			}
		}
	}
	return maxNum;
}


int main041() {
	std::fstream fst("in.txt");
	int size;
	fst >> size;
	std::vector<int> num;
	for (int i = 0; i < size; i++) {
		int data;
		fst >> data;
		num.push_back(data);
	}
	std::cout << findMaxSu(num);
	return 0;
}