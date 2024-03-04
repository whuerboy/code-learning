#include<iostream>
#include<vector>
 //问题的核心就是利用Dijkstra算法，将四个村庄都作为选址
//  INT_MAX 10000;


class table {//用来记录结点的信息
public:
	bool visited;
	int distance, path;
};

class Graph {
public:
	std::vector<int> namelist;
	std::vector<std::vector<int>>edgelist;
	void creatGrphy(int num) {
		for (int i = 0; i < num; i++) {
			namelist.push_back(i);
			std::vector<int> arr(num);
			edgelist.push_back(arr);
		}
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				int weight;
				std::cin >> weight;
				edgelist[i][j] = weight;
			}
		}
	}
};

int Findmin(Graph* g, table* t) {   //找到距离最进的顶点
	int min = 10000;
	int adjmin = -1;
	for (int i = 0; i < g->namelist.size(); i++)
		if (!t[i].visited && t[i].distance < min && t[i].distance!=0) {
			min = t[i].distance;
			adjmin = i;
		}
	return adjmin;
}


int digiska(Graph* g, table* t,int flag) {

	//初始化table
	for (int i = 0; i < g->namelist.size(); i++) {
		t[i].distance = g->edgelist[flag][i];
		t[i].visited = false;
		t[i].path = flag;
	}

	t[flag].visited = true;
	int sum=0, adjmin;
	for (int i = 0; i < g->namelist.size()-1; i++) {   //因为flag顶点已被选出，因此还需选出n-1个顶点
		adjmin = Findmin(g, t);
		if (adjmin == -1) {
			continue;
		}
		t[adjmin].visited = true;
		for (int j = 0; j < g->namelist.size(); j++)
			if (!t[j].visited && g->edgelist[adjmin][j] <10000) {   //注：无向图一定要判断 g->edgelist[adjmin][j]<INT_MAX
				if (g->edgelist[adjmin][j] == 0) {
					sum = t[adjmin].distance + 10000;//我们在存储的时候用的是0代表权值，这会极大影响路径长度判断，要小心
				}
				else {
					sum = t[adjmin].distance + g->edgelist[adjmin][j];
				}
			
				if (sum < t[j].distance||t[j].distance==0) {
					t[j].distance = sum;
					t[j].path = adjmin;
				}
			}
	}
	//此时所有的数据都在table中
	int max = 0;
	for (int i = 0; i < g->namelist.size(); i++) {
		if (t[i].distance > max)
			max = t[i].distance;
	}
	return max;
}



int main39() {
	Graph g;
	int num;
	table t[10];
	std::cin >> num;//获取村庄的数量
	//图矩阵的初始化
	g.creatGrphy(num);
	std::vector<int>result;
	for (int i = 0; i < num; i++) {
		result.push_back(digiska(&g, t, i));
	}
	//选出最小的打印
	int min = 10000;
	int adjmin;
	for (int i = 0; i < result.size(); i++) {
		if (result[i] < min) {
			min = result[i];
			adjmin = i;
		}
	}
	std::cout << adjmin+1;
	return 0;
}