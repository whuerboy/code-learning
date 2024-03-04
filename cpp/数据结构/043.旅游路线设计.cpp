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
	fst >> nodeNum >> colunum;//��ȡ�����ͽڵ���
	std::vector<std::vector<int>> data;
	std::vector<std::vector<int>> dis;
	data.reserve(nodeNum);
	dis.reserve(nodeNum);
	for (int i = 0; i < nodeNum; i++) {
		std::vector<int> temp(nodeNum);
		data.push_back(temp);
		dis.push_back(temp);
	}//�����ڽӾ���
	for (int i = 0; i < nodeNum; i++)
		for (int j = 0; j < nodeNum; j++)
			data[i][j] = data[j][i] = dis[i][j] = dis[j][i] = inf;//��ʼ��
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
			for (int j = i + 1; j < k; j++)//�������i+1,��ֹ�ظ�
				ans = std::min(ans, dis[i][j] + data[i][k] + data[k][j]);

		for (int i = 0; i < nodeNum; i++)
			for (int j = 0; j < nodeNum; j++)
				dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);//��ȡ·����̾���
	}

	if (ans == inf)puts("It's impossible.");
	else printf("%d\n", ans);


	return 0;
}