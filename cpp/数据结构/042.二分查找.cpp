#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
bool halFind(std::vector<int>data,int key) {
	std::ofstream fst("out.txt");	
	bool ifFind=false;
	std::vector<int>result;
	std::sort(data.begin(), data.end());//从小到大排序
	int low = 0;
	int height = data.size()-1 ;
	while (low <= height) {
		int mid = (low + height) >> 1;
		result.push_back(data[mid]);
		if (data[mid] == key) {
			ifFind = true;
			break;
		}
		else if (data[mid] > key) height = mid - 1;
		else low = mid + 1;
	}
	if (ifFind) {
		fst << "True" << "\n";
	}
	else {
		fst << "False" << "\n";
	}
	for (auto i : result) {
		fst << i << " ";
	}
	return ifFind;
}

int main042() {
	//std::fstream fst("in.txt");
	//int sortNum;
	//std::vector<int>data;
	//fst >> sortNum;
	//while (1) {
	//	int num;
	//	fst >> num;
	//	data.push_back(num);
	//	if (fst.eof()) {
	//		break;
	//	}
	//}
	//fst.close();
	std::vector<int>data = { 2 ,3, 8, 30, 37, 45, 49, 54, 59, 59, 70, 71, 82, 84, 85, 93, 95 };
	int sortNum = 59;
	halFind(data, sortNum);
	return 0;
}