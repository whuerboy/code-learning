#include<iostream>
#include<vector>
using namespace std;

void SelectSort(vector<int>& v) {
	int n = v.size();
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (v[min] > v[j]) {
				min = j;
			}
		}
		if (min != i)
			swap(v[i], v[min]);
	}
}

int main57() {
	vector<int>arr = { 10,9,8,7,6,5,4,3,2,1,0 };
	SelectSort(arr);
	for (auto i : arr) {
		cout << i << " ";
	}
	return 0;
}