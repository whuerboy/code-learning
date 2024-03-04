//#include <iostream>
//#include <vector>
//
//void merge(std::vector<int>& arr, int left, int mid, int right) {
//    int i = left;
//    int j = mid + 1;
//    std::vector<int> temp;
//
//    while (i <= mid && j <= right) {
//        if (arr[i] <= arr[j]) {
//            temp.push_back(arr[i]);
//            i++;
//        }
//        else {
//            temp.push_back(arr[j]);
//            j++;
//        }
//    }
//
//    while (i <= mid) {
//        temp.push_back(arr[i]);
//        i++;
//    }
//
//    while (j <= right) {
//        temp.push_back(arr[j]);
//        j++;
//    }
//
//  /*  for (i = left; i <= right; i++) {
//        arr[i] = temp[i - left];
//    }*/
//    for (int m = left, n = 0; m <= right; m++, n++)//读取临时数组中的数
//        arr[m] = temp[n];
//}
//
//void mergeSort(std::vector<int>& arr, int left, int right) {
//    if (left < right) {
//        int mid = left + (right - left) / 2;
//        mergeSort(arr, left, mid);
//        mergeSort(arr, mid + 1, right);
//        merge(arr, left, mid, right);
//    }
//}
//
//void mergeSort(std::vector<int>& arr) {
//    mergeSort(arr, 0, arr.size() - 1);
//}
//
//int main() {
//    std::vector<int> arr = { 10,9,8,7,6,5,4,2,3,1 };
//    mergeSort(arr);
//
//    for (int i = 0; i < arr.size(); i++) {
//        std::cout << arr[i] << " ";
//    }
//    std::cout << std::endl;
//
//    return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//
//void merge(vector<int>& arr, int low, int mid, int high) {
//	int i = low, j = mid + 1;
//	vector<int>temp;
//	while (i <= mid && j < high) {
//		if (arr[i] < arr[j]) {
//			temp.push_back(arr[i]);
//			i++;
//		}
//		else {
//			temp.push_back(arr[j]);
//			j++;
//		}
//	}
//	while (i <= mid) {
//		temp.push_back(arr[i++]);
//	}
//	while (j < high) {
//		temp.push_back(arr[j++]);
//	}
//
//	//将其放回数组中
//	for (int m = low; m < high; m++) {
//		arr[m] = temp[m - low];
//	}
//}
//
//void mergeSort(vector<int>&arr, int low, int high) {
//	if (low < high) {
//		int mid = (high+low)/2;
//		mergeSort(arr, low, mid);
//		mergeSort(arr, mid + 1, high);
//		merge(arr, low, mid, high);
//	}
//}
//
//
//int main() {
//	vector<int>arr = { 10,9,8,7,6,5,4,3,2,1,0 };
//	mergeSort(arr, 0, arr.size());
//	for (auto i : arr) {
//		cout << i << " ";
//	}
//	return 0;
//}
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int low, int mid, int high) {
	if (low >= high)return;
	int i = low, j = mid + 1;
	vector<int>temp;
	while (i <= mid && j <= high) {
		if (arr[i] < arr[j]) {
			temp.push_back(arr[i]);
			i++;
		}
		else {
			temp.push_back(arr[j]);
			j++;
		}
	}
	while (i <= mid) {
		temp.push_back(arr[i++]);
	}
	while (j <= high) {
		temp.push_back(arr[j++]);
	}

	//将其放回数组中
	for (int m = low; m <= high; m++) {
		arr[m] = temp[m - low];
	}
}

void mergeSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size) {
        for (int left = 0; left < n - 1; left += 2 * curr_size) {
            int mid = std::min(left + curr_size - 1, n - 1);
            int right = std::min(left + 2 * curr_size - 1, n - 1);
            merge(arr, left, mid, right);
        }
    }
}

int main60() {
    std::vector<int> arr = {9,8,7,6,5,4,3,2,1,0 };
    int n = arr.size();

    mergeSort(arr);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}