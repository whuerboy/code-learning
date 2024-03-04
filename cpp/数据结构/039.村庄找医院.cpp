#include<iostream>
#include<vector>
 //����ĺ��ľ�������Dijkstra�㷨�����ĸ���ׯ����Ϊѡַ
//  INT_MAX 10000;


class table {//������¼������Ϣ
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

int Findmin(Graph* g, table* t) {   //�ҵ���������Ķ���
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

	//��ʼ��table
	for (int i = 0; i < g->namelist.size(); i++) {
		t[i].distance = g->edgelist[flag][i];
		t[i].visited = false;
		t[i].path = flag;
	}

	t[flag].visited = true;
	int sum=0, adjmin;
	for (int i = 0; i < g->namelist.size()-1; i++) {   //��Ϊflag�����ѱ�ѡ������˻���ѡ��n-1������
		adjmin = Findmin(g, t);
		if (adjmin == -1) {
			continue;
		}
		t[adjmin].visited = true;
		for (int j = 0; j < g->namelist.size(); j++)
			if (!t[j].visited && g->edgelist[adjmin][j] <10000) {   //ע������ͼһ��Ҫ�ж� g->edgelist[adjmin][j]<INT_MAX
				if (g->edgelist[adjmin][j] == 0) {
					sum = t[adjmin].distance + 10000;//�����ڴ洢��ʱ���õ���0����Ȩֵ����Ἣ��Ӱ��·�������жϣ�ҪС��
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
	//��ʱ���е����ݶ���table��
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
	std::cin >> num;//��ȡ��ׯ������
	//ͼ����ĳ�ʼ��
	g.creatGrphy(num);
	std::vector<int>result;
	for (int i = 0; i < num; i++) {
		result.push_back(digiska(&g, t, i));
	}
	//ѡ����С�Ĵ�ӡ
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