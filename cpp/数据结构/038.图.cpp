#include<iostream>
using namespace std;
#define Max 100
typedef struct VNode {
	int data;//
	struct VNode* next;
	int isvalid;
}VNode,*Nodelist;

typedef struct Graphy {
	Nodelist arr[Max];
	int size;//点的个数
	int* visited;
	Graphy(int vexnum) {
		size = vexnum;
		int* visited = new int[size];
		for (int i = 0; i < size; i++) {
			visited[i] = 0;//初始化访问数组；
		}
	}

	int FirstNeibor(int v) {
		if (arr[v]->next) {
			return arr[v]->next->data;//返回第一个
		}
		else return -1;
		
	}
	int Nextneibor(int v,int w) {
	//跳过第w个寻找下一个
		Nodelist p=arr[v];
		for (int i = 0; i < w; i++) {
			
			while (p->next) {
				p = p->next;
			}
		}
		if (p->next!=nullptr) {
			return p->next->data;
		}
		else {
			return -1;
		}
	}

} Graphy;

int deleteNode(Graphy& g,int num) {
	Nodelist p;
	for (int i = 1; i <= g.size; i++) {
		p = g.arr[i];
		while (p->next) {
			if (p->next->data == num) {
				p->next = p->next->next;
				break;
			}
			p = p->next;
		}
		g.arr[num]->next = nullptr;
		g.arr[num]->isvalid = -1;//置为无效
		g.size--;
	}
	return 1;
}

int CreatG(Graphy g, int vexnum, int arcnum) {
	g.size = vexnum;
	for (int i = 0; i < vexnum; i++) {
		g.arr[i] = new VNode;
		g.arr[i]->data = i;
		g.arr[i]->next = nullptr;
		g.arr[i]->isvalid = 1;//有效
	}
	for (int i = 0; i < arcnum; i++) {
		int v1, v2;
		cin >> v1>>v2;//读取一条边的两个结点
		Nodelist p1 = new VNode;
		p1->data = v2;
		p1->next = g.arr[v1]->next;
		g.arr[v1]->next = p1;
		Nodelist p2 = new VNode;
		p2->data = v1;
		p2->next = g.arr[v2]->next;
		g.arr[v2]->next = p2;//头插法
	}
	return 1;
}

void visit(int i, Graphy g) {
	cout << g.arr[i]->data<<" ";
}

void DFSprint(Graphy g,int v) {
	

	visit(v, g);//访问第一个元素
	g.visited[v] = 1;
	for (int w = g.FirstNeibor(0); w >= 0; w = g.Nextneibor(v, w)) {
		if (!g.visited[v]) {
			DFSprint(g, w);
		}
	}
}


int main003() {
	/*int vexnum, arcnum;
	cin >> vexnum >> arcnum;
	Graphy g(vexnum);
	CreatG(g, vexnum, arcnum);
	DFSprint(g, 0);*/
	float a = 2.0;
	long i = *(long*)&a;
	i >> 3;
	std::cout <<( *(float*)&i);
	return 0;
}