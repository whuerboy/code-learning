#include<iostream>
#include<iostream>
#include<vector>

class val {
public:
	std::vector<int> arr;
	int size;
	val(int m) {
		for (int i = 0; i < m; i++) {
			arr.push_back(i);
		}
		this->size = m;
	}
	void delt(int m) {
		int low = 0, high = 0;
		for (; high < this->arr.size(); high++) {
			if (arr[high] != m) {
				arr[low] = arr[high];
				low++;
			}
			else {
				size--;
				continue;
			}
		}
	}

	void print() {
		for (int i = 0; i < size; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}
};





void getArr(std::vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		arr[i] = arr[i] * arr[i];//数组元素平方
	}

	//数组排序
	int low = 0, high = arr.size() - 1;
	while (low <= high) {
		if (arr[low] > arr[high]) {
			std::cout << arr[low] << " ";
			low++;
		}
		else {
			std::cout << arr[high] << " ";
			high--;
		}
	}
	
}


int main() {
	//val v = val(5);
	//v.print();
	//v.delt(1);
	//v.print();

	std::vector<int> arr = { -9,-5,1,2,4,8 };
	getArr(arr);
	return 0;
}