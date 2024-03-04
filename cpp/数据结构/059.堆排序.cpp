#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//void HeapChange(std::vector<int>& arr,int i,int len) {//构建某个结点称为最大堆结点
//	int left = 2 * i + 1, right = 2 * i + 2;
//	int max = i;//默认当前结点为最大值
//	
//	 if(left < len &&(arr[left] > arr[i])) {
//		max = left;
//	}
//	else if(right < len&&(arr[right] > arr[i])){
//		max = right;
//	}
//	if (max != i) {
//		std::swap(arr[i], arr[max]);
//		HeapChange(arr, max, len);
//	}
//}
//void BuildHeap(std::vector<int>& arr,int len) {
//	for (int i = arr.size() / 2; i >= 0; i--) {
//		HeapChange(arr, i,len);
//	}
//}
//
//void HeapSort(std::vector<int>& arr) {
//	int len = arr.size();
//	BuildHeap(arr,arr.size());
//	while (len>1) {
//		std::swap(arr[0], arr[len - 1]);
//		HeapChange(arr, 0, --len);
//	}
//}
void Heapify(vector<int>& v, int i, int len) {
	int left = 2 * i + 1, right = 2 * i + 2;  //二叉树当前节点的左右节点的索引
	int maxindex = i;                         //先默认i为最大值索引 即当前非叶子节点

	if (left < len && v[left] > v[maxindex])   //如果有左节点且左节点值更大
		maxindex = left;
	if (right < len && v[right] > v[maxindex]) //如果有右节点且右节点值更大
		maxindex = right;

	if (maxindex != i) {
		//发现最大值并非当前非叶子节点，则需调整 即交换最大值到非叶子节点处
		swap(v[i], v[maxindex]);
		//互换之后，子节点值发生变化，子节点若也有其子节点，则需继续调整其子结构
		Heapify(v, maxindex, len);            //递归 调整堆
	}
}

//无序数组 构建大根堆
void BuildMaxHeap(vector<int>& v, int len) {
	//从最后一个非叶子节点开始遍历，调整每个子结构，构建形成大根堆
	for (int i = len / 2 - 1; i >= 0; i--)
		Heapify(v, i, len);
}

//堆排序
void HeapSort(vector<int>& v) {
	int len = v.size();
	BuildMaxHeap(v, len);           //构建大根堆
	while (len > 1) {
		swap(v[0], v[len - 1]);     //交换首尾数据  尾部最大 且出现在合适位置
		Heapify(v, 0, --len);       //重置大根堆
	}
}


int main059() {
	std::vector<int>arr = {8,7,5,1,33,6,99,87,4,1,5,2,7};
	HeapSort(arr);
	for (auto i : arr) {
		std::cout << i << " ";
	}
	return 0;
}