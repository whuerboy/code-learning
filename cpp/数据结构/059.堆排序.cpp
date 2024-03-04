#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//void HeapChange(std::vector<int>& arr,int i,int len) {//����ĳ������Ϊ���ѽ��
//	int left = 2 * i + 1, right = 2 * i + 2;
//	int max = i;//Ĭ�ϵ�ǰ���Ϊ���ֵ
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
	int left = 2 * i + 1, right = 2 * i + 2;  //��������ǰ�ڵ�����ҽڵ������
	int maxindex = i;                         //��Ĭ��iΪ���ֵ���� ����ǰ��Ҷ�ӽڵ�

	if (left < len && v[left] > v[maxindex])   //�������ڵ�����ڵ�ֵ����
		maxindex = left;
	if (right < len && v[right] > v[maxindex]) //������ҽڵ����ҽڵ�ֵ����
		maxindex = right;

	if (maxindex != i) {
		//�������ֵ���ǵ�ǰ��Ҷ�ӽڵ㣬������� ���������ֵ����Ҷ�ӽڵ㴦
		swap(v[i], v[maxindex]);
		//����֮���ӽڵ�ֵ�����仯���ӽڵ���Ҳ�����ӽڵ㣬��������������ӽṹ
		Heapify(v, maxindex, len);            //�ݹ� ������
	}
}

//�������� ���������
void BuildMaxHeap(vector<int>& v, int len) {
	//�����һ����Ҷ�ӽڵ㿪ʼ����������ÿ���ӽṹ�������γɴ����
	for (int i = len / 2 - 1; i >= 0; i--)
		Heapify(v, i, len);
}

//������
void HeapSort(vector<int>& v) {
	int len = v.size();
	BuildMaxHeap(v, len);           //���������
	while (len > 1) {
		swap(v[0], v[len - 1]);     //������β����  β����� �ҳ����ں���λ��
		Heapify(v, 0, --len);       //���ô����
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