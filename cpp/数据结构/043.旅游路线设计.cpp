#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
const int maxn = 1e3 + 10;
const int inf = 0x3f3f3f;
int main043() {
	std::fstream fst;
	fst.open("in.txt");
	int colunum, nodeNum;
	fst >> nodeNum >> colunum;//读取边数和节点数
	std::vector<std::vector<int>> data;
	std::vector<std::vector<int>> dis;
	data.reserve(nodeNum);
	dis.reserve(nodeNum);
	for (int i = 0; i < nodeNum; i++) {
		std::vector<int> temp(nodeNum);
		data.push_back(temp);
		dis.push_back(temp);
	}//建立邻接矩阵
	for (int i = 0; i < nodeNum; i++)
		for (int j = 0; j < nodeNum; j++)
			data[i][j] = data[j][i] = dis[i][j] = dis[j][i] = inf;//初始化
	for (int i = 0; i < colunum; i++) {
		int m1, n1, weight;
		fst >> m1>> n1 >> weight;
		int m = m1 - 1, n = n1 - 1;
		if (weight < data[m][n]) {
			data[m][n] = data[n][m] = dis[n][m] = dis[m][n] = weight;
		}
	}

	int ans = inf;
	for (int k = 0; k < nodeNum; k++)
	{		
		for (int i = 0; i < k; i++)
			for (int j = i + 1; j < k; j++)//这里得是i+1,防止重复
				ans = std::min(ans, dis[i][j] + data[i][k] + data[k][j]);

		for (int i = 0; i < nodeNum; i++)
			for (int j = 0; j < nodeNum; j++)
				dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);//获取路径最短矩阵
	}

	if (ans == inf)puts("It's impossible.");
	else printf("%d\n", ans);


	return 0;
}