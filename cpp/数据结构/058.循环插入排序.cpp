#include<iostream>
#include<ctime>
using namespace std;

//��ʱ������Ϊѭ���������
void TwoInsertSort(int a[], int n) {
	int* tmp = new int[n];     //��ʱ����
	int front = 0, rear = 0;   //��¼��ǰtmp���������ֵ����Сֵ��λ��,front��¼��Сֵ��rear��¼���ֵ
	tmp[0] = a[0];             //��ʼ��tmp

	for (int i = 1; i < n; i++) {
		int key = a[i];
		//�����ǰ�����Ԫ�ر���С��Ԫ�ظ�С
		if (key < tmp[front]) {
			front = (front - 1 + n) % n;
			tmp[front] = key;
		}
		//�����ǰ����Ԫ�ر����Ԫ�ظ���
		else if (key > tmp[rear]) {
			rear = (rear + 1 + n) % n;
			tmp[rear] = key;
		}
		//����ڵ�ǰ��С�����֮��
		else {
			int k = (rear + n) % n;
			//���ȵ�ǰ����ֵkey��Ľ��к���
			while (tmp[(k + n) % n] > key) {
				tmp[(k + 1 + n) % n] = tmp[(k + n) % n];
				k = (k - 1 + n) % n;
			}

			tmp[(k + 1 + n) % n] = key; //��ǰ����ֵ�ŵ�����λ��
			rear = (rear + 1 + n) % n;  //�������ֵλ��(�������г���+1)
		}
	}

	//������ʱ���鵽ԭ������
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
		a[k++] = rand() % 100 + 1;   //���ַ�Χ[1,100]

	show(a, 50);

	TwoInsertSort(a, 50);

	cout << endl << endl;
	show(a, 50);
	return 0;
}