#include<iostream>
#include<vector>
using namespace std;

void quickSort(vector<int>& arr) {
	if (arr.size() <= 1) {
		return ;
	}
	else {
		//ѡ���׼Ԫ��
		int prio = arr[arr.size()/2];
		vector<int>low;
		vector<int>high;
		for (unsigned int i = 0; i < arr.size(); i++) {
			if (arr[i] > prio) {
				high.push_back(arr[i]);
			}
			else if(arr[i]<prio) {
				low.push_back(arr[i]);
			}
			else {
				continue;
			}
		}
		quickSort(high);
		quickSort(low);
		arr.clear();
		for (auto i : low) {
			arr.push_back(i);
		}
		arr.push_back(prio);
		for (auto j : high) {
			arr.push_back(j);
		}
	}
}

void quickSort2(vector<int>& s, int begin, int end) {
	{
		if (begin < end) {
			int i = begin, j = end, x = s[begin];
			while (i < j)
			{
				while (i < j && s[j] >= x) // ���������ҵ�һ��С��x����
					j--;
				if (i < j)
				{
					s[i] = s[j];
					i++;
				}

				while (i < j && s[i] < x) // ���������ҵ�һ�����ڵ���x����
					i++;
				if (i < j)
				{
					s[j] = s[i];
					j--;
				}
				
			}
			s[i] = x;
			quickSort2(s, begin, i - 1); // �ݹ���� 
			quickSort2(s, i + 1, end);
		}
	}
}


void quickSort3(vector<int>&arr, int left, int right) {
	int i = left, j = right;
	int pivot = arr[(left + right) / 2];

	while (i <= j) {
		while (arr[i] < pivot) {
			i++;
		}
		while (arr[j] > pivot) {
			j--;
		}
		if (i <= j) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}

	if (left < j) {
		quickSort3(arr, left, j);
	}
	if (i < right) {
		quickSort3(arr, i, right);
	}
}


int main055() {
	vector<int>arr = { 10,9,8,7,6,5,4,3,2,1,0 };
	quickSort3(arr,0,arr.size()-1);
	for (auto i : arr) {
		std::cout << i << " ";
	}
	return 0;
}