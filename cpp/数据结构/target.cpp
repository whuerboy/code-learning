#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
fstream ifs;

void getPair(vector<int> arr,int target,int *b) {
	for (int i = 0; i < arr.size()-1; i++) {
		int tar = target - arr[i];
			for (int m = i + 1; m < arr.size()-1; m++)
			{
				if (arr[m]==tar)
				{
					b[0]=i;
					b[1] = m;
					return ;
				}
			}
	}
	b[0] = -1;
	b[1] = -1;
	return ;
}

int main10() {
	ifs.open("in.txt", ios::in);
	int i = 0;
	vector<int> arr ;
	while (!ifs.eof()) {
		int m;
		ifs >> m;
		arr.push_back(m);
		i++;
	}
	ifs.close();
	/*for (vector<int>::iterator it = arr.begin(); it != arr.end(); it++) {
		cout << *it << " ";
	}*/
	int target;
	target = arr.at(i-1);
	
	int b[2];
	getPair(arr, target,b);
	for (int i = 0; i < 2; i++) {
		cout << b[i] << " ";
	}


	return 0;
}
