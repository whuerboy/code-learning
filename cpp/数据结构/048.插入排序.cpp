#include<iostream>
#include<fstream>
#include<vector>


    void Insert_Sort(int* A, int n)
    {
        int tmp, i = n - 1;
        if (n == 0)  return;
        Insert_Sort(A, n - 1);
        while (i >= 1 && A[i] < A[i - 1])//比较
        {
            //在比较之后互换位置
            tmp = A[i];
            A[i] = A[i - 1];
            A[i - 1] = tmp;
            i--;
        }

        
    }


int main048() {
	int arr[] = {2,6,5,4,9997,8,9,1,0};
    Insert_Sort(arr, 9);
    for (int i = 0; i < 9; i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}