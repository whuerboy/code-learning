#include<iostream>
#include<ctime>
using namespace std;

//临时数组作为循环数组操作
void TwoInsertSort(int a[], int n) {
	int* tmp = new int[n];     //临时数组
	int front = 0, rear = 0;   //记录当前tmp数组中最大值和最小值的位置,front记录最小值，rear记录最大值
	tmp[0] = a[0];             //初始化tmp

	for (int i = 1; i < n; i++) {
		int key = a[i];
		//如果当前插入的元素比最小的元素更小
		if (key < tmp[front]) {
			front = (front - 1 + n) % n;
			tmp[front] = key;
		}
		//如果当前插入元素比最大元素更大
		else if (key > tmp[rear]) {
			rear = (rear + 1 + n) % n;
			tmp[rear] = key;
		}
		//如果在当前最小和最大之间
		else {
			int k = (rear + n) % n;
			//将比当前插入值key大的进行后移
			while (tmp[(k + n) % n] > key) {
				tmp[(k + 1 + n) % n] = tmp[(k + n) % n];
				k = (k - 1 + n) % n;
			}

			tmp[(k + 1 + n) % n] = key; //当前插入值放到合适位置
			rear = (rear + 1 + n) % n;  //更新最大值位置(有序序列长度+1)
		}
	}

	//复制临时数组到原数组中
	for (int k = 0; k < n; k++)
		a[k] = tmp[(front + k) % n];
	delete[] tmp;
}


void show(int* a, int n) {
	for (int i = 0; i < n; i++)
		cout << *(a + i) << " ";
	cout << endl;
}


int main058() {
	int a[50];
	srand((int)time(0));
	int k = 0;
	while (k < 50)
		a[k++] = rand() % 100 + 1;   //数字范围[1,100]

	show(a, 50);

	TwoInsertSort(a, 50);

	cout << endl << endl;
	show(a, 50);
	return 0;
}