#include<queue>
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;


bool cilkcksort(vector<int>arr) {
	if (arr.size() < 2) {
		return true;
	}
	else if (arr.size() == 2) //当剩下的序列元素只有两个时
	{
		if (arr[0] < arr[1]) {
			return true;
		}
		else {
			return false;
		}
	}
	else//当元素个数为三个以上时
	{
		bool if_sorted = false;
		for (int i = 0; i < arr.size() - 2; i++) {
			if (arr[i] < arr[i + 1] && arr[i + 1] < arr[i + 2]) {
				if_sorted = true;
			}
			else {
				return false;
			}
		}
		return if_sorted;
	}
}

void sort(vector<int>& arr) {
	queue<int>result;
	//从vector中判断元素并传入queue中：

		for (int i = 0; i < arr.size(); i++) {
			if (i == 0) {
				if (arr[i] < arr[i + 1]) {
					result.push(arr[i]);
				}
			}
			else if (i == arr.size() - 1) {
				if (arr[i] > arr[i - 1]) {
					result.push(arr[i]);
					}
			}
			else {
				if (arr[i] > arr[i - 1] && arr[i] < arr[i + 1]) {
					result.push(arr[i]);
					}
			}
			
		}
	
	arr.clear();
	int size = result.size();
	for (int i = 0; i<size; i++) {
		int a = result.front();
		result.pop();
		arr.push_back(a);
	}

	if (!cilkcksort(arr)) {
		sort(arr);
	}
	
}

int main28() {
	fstream fts;
	fts.open("in.txt");
	//while (!fts.eof()) {
		int num;
		fts >> num;
		vector<int> arr;
		for (int i = 0; i < num; i++) {
			int value;
			fts >> value;
			arr.push_back(value);
		}
		//all.push_back(sum);

		sort(arr);
		//打印数据
		cout << arr.size() << endl;
		for (auto i : arr) {
			cout << i << " ";
		}
		cout << endl;
		fts.close();

	return 0;
}