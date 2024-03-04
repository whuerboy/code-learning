#include<iostream>
#include<fstream>
#include<vector>

class Matrix {
private:
	int line; int colunm;
	int subline, subcolunm;
public:
	std::vector<std::vector<int>>& matrix;
	Matrix(int x,int y, int subline,int subcolunm,std::vector<std::vector<int>>& matrix):line(x),colunm(y),subline(subline),subcolunm(subcolunm), matrix(matrix)
	{
	
	}
	int getLine() {
		return this->line;
	}
	int getColunm() {
		return this->colunm;
	}

	int getSubline() {
		return subline;
	}
	int getSubColunm() {
		return subcolunm;
	}
};

int findMaxInt(std::vector<int> arr,int colunm) {
	//首先先排序：
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr.size() - i-1; j++) {
			int max = 0;
			if (arr.at(j) < arr.at(j + 1)) {
				max = arr.at(j + 1);
				arr.at(j + 1) = arr.at(j);
				arr.at(j) = max;
			}
		}
	}

	//for (int i : arr) {
	//	std::cout << i << " ";
	//}
	int sum = 0;
	for (int i = 0; i < colunm; i++) {
		sum += arr.at(i);
	}
	return sum;
}

int findMax(Matrix maxMatrix) {

	//思路：先把每行里面每y项和找出来，再比较行之间的，最后得出结论

	std::vector<int> maxInt;
	std::vector<std::vector<int>>MaxInt;
		for (auto j : maxMatrix.matrix) {
			
			for (int h = 0; h <= maxMatrix.getColunm() - maxMatrix.getSubColunm();h++) {
				int max = 0;
				int mm = h;
				for (int m = 0; m < maxMatrix.getSubColunm(); m++) {
					max += j.at(mm);
					mm++;
				} 
				maxInt.push_back(max);
				//std::cout << max << " ";
			}
			//std::cout << std::endl;
			MaxInt.push_back(maxInt);
			maxInt.clear();
		}

	/*	for (auto i : MaxInt) {
			for (auto j : i) {
				std::cout << j << " ";
			}
			std::cout << std::endl;
		}*/

	
		std::vector<int>result;
		for (int j = 0; j <= maxMatrix.getColunm() - maxMatrix.getSubColunm(); j++) {
			for (int i = 0; i <= maxMatrix.getLine() - maxMatrix.getSubline(); i++) {
				int max = 0;
				int ii = i;
				for (int m = 0; m < maxMatrix.getSubline(); m++) {
					max += MaxInt[ii][j];
					ii = ii+1;
				}
				result.push_back(max);
			}
	}
		


	return findMaxInt(result,1);
}



int main51() {
	std::vector<std::vector<int>> matrix;//定义矩阵
	std::fstream fst;

	fst.open("in.txt");//打开文件
	int line, colunm, subline, subcolunm;//定义最先获取的四个基础变量
	fst >> line >> colunm >> subline >> subcolunm;
	int data = 0;
	std::vector<int> linedata;
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < colunm; j++) {
			fst >> data;
			linedata.push_back(data);
		}
		matrix.push_back(linedata);
		linedata.clear();
	}//读取矩阵

	Matrix maxMatrix = Matrix(line, colunm, subline, subcolunm, matrix);
	std::cout<<findMax(maxMatrix);
	/*std::vector<int>test;
	test.push_back(0); test.push_back(1); test.push_back(2); test.push_back(3); test.push_back(4);
	std::cout<<findMaxInt(test, 2);*/
	fst.close();
	return 0;
}