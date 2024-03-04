#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<string>
#include<cstring>
#include<cmath>
int dfs(std::vector<std::vector<int>>&data, int cur_i, int cur_j) {
	if (cur_i < 0 || cur_j < 0 || cur_i == data.size() || cur_j == data[0].size()||data[cur_i][cur_j]==0) {
		return 0;
	}
	data[cur_i][cur_j] = 0;//访问过就置0
	int di[4] = { 0,0,1,-1 };
	int dj[4] = { 1,-1,0,0 };
	int ans = 1;
	for (int index = 0; index < 4; ++index) {
		int next_i = cur_i + di[index], next_j = cur_j + dj[index];
		ans += dfs(data, next_i, next_j);
	}
	return ans;
}

int findMaxArea(std::vector<std::vector<int>>&data) {
	int ans = 0;
	for (int i = 0; i < data.size(); i++) {
		for (int j = 0; j < data[0].size(); ++j) {
			ans = std::max(ans, dfs(data, i, j));
		}
	}
	return ans;
}




int main044() {
	std::fstream fst;
	fst.open("in.txt");
	std::vector<std::vector<int>>data;
	int row = 0; int count = 0;
	std::string temp;
	while (std::getline(fst, temp, '\n')) {
		//std::cout << temp << std::endl;
		if (count == 0) {
			int back=0;//空格键
			for (int i = 0; i < temp.size()-1; i++) {
				if (temp[i] == ' ') {
					back++;
				}
			}
			row = temp.size() - back;
		}
		
			std::vector<int>line;
			std::istringstream ist(temp);
			for (int i = 0; i < row; i++) {
				std::string str_tep;
				ist >> str_tep;
				line.push_back(std::stoi(str_tep));
			}
			data.push_back(line);
		
		count++;
	}
	fst.close();
	std::cout << findMaxArea(data);
	return 0;
}