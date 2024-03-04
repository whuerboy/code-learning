#include<iostream>
#include<vector>
#include<fstream>
class Solution {
public:
	std::vector<std::vector<int>> generateMatrix(int n)
	{
		int i, j;//��¼�кź��к�
		int num = 1;//��¼��������ݣ������Է��ӳ���������Ĺ���
		std::vector<std::vector<int> > arr;
		for (int i = 0; i < n; i++) {
			std::vector<int> data(n);
			arr.push_back(data);
		}
		
	
		int start = 0, end = n - 1;
		int k = n;//����dimension�������ʱ���ı䣬��Ҫ�и���������¼

		//˼·����д�Ȱ������������飬Ȼ���������ƽ�.
		while (num <= k * k) {
			for (j = start; j < n; j++) {
				arr[start][j] = num;
				num++;
			}
			for (i = start + 1; i < n; i++) {
				arr[i][end] = num;
				num++;
			}
			for (j = end - 1; j >= start; j--) {
				arr[end][j] = num;
				num++;
			}
			for (i = end - 1; i >= start + 1; i--) {
				arr[i][start] = num;
				num++;
			}
			start++; end--; n--;
		}
		return arr;
	}
	
};
int main31() {
	int dimension;
	std::fstream fst;
	fst.open("in.txt");
	fst >> dimension;
	Solution slution;
	std::vector<std::vector<int>> arr;
	arr=slution.generateMatrix(dimension);
	std::cout << " [" << std::endl;
	int num = 0;
	for (auto i : arr) {
		std::cout << "[";
		for (int j = 0; j < i.size();j++) {
			if(j==i.size()-1){
				if (num != arr.size() - 1) {
					std::cout << i[j] << "],"<<std::endl;
				}
				else {
					std::cout << i[j] << "]" << std::endl;
				}
			}
			else {
			std::cout << i[j] << ",";
			}
			
		}
		num++;
	}
	std::cout << " ] ";
	return 0;
}

