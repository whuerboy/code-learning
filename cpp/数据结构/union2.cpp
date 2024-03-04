#include <iostream>
#include <fstream>

using namespace std;

fstream ioFile;

int* getData(int x) {
    int* arr = new int[x];
    for (int i = 0; i < x; i++) {
        ioFile >> arr[i];//����������ȷ
    }
    return arr;
}



int main7() {
    ioFile.open("in.txt", ios::in);
    if (ioFile.is_open()) {
        int a, b;
        ioFile >> a;
        ioFile >> b;//�����ո���Զ�ֹͣ��ȡ


        int* A = getData(a);//����A�����е�һ�����ݵĵ�ַ
        int* B = getData(b);//����B����ͬ��


        for (int i = 0; i < a; i++) {
            for (int j = i; j < a; j++) {
                if (*(A + i) > *(A + j)) {
                    int m;
                    m = *(A + i);
                    *(A + i) = *(A + j);
                    *(A + j) = m;
                }
            }
        }
        for (int i = 0; i < b; i++) {
            for (int j = i; j < b; j++) {
                if (*(B + i) > *(B + j)) {
                    int m;
                    m = *(B + i);
                    *(B + i) = *(B + j);
                    *(B + j) = m;
                }
            }
        }
        //��A��B����С�ź� ����дһ���㷨��������


        int x = 0;
        int y = 0;
        int* C = new int[a + b];
        int num = 0;


        while (x < a && y < b) {
            if (A[x] < B[y]) {
                C[num] = A[x]; num++; x++;
            }
            else if (A[x] > B[y]) {
                C[num] = B[y]; num++; y++;
            }
            else { C[num] = A[x]; x++; y++; num++; }
        }

        while (x < a) {
            C[num] = A[x];
            num++; x++;
        }
        while (y < b) {
            C[num] = B[y];
            num++; y++;
        }
        for (int i = 0; i < num; i++) {
            cout << C[i] << " ";
        }


        ioFile.close();
    }
    else {
        cout << "�ļ���ʧ��" << endl;
    }
    return 0;
}