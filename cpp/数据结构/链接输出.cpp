#include<iostream>
#include<list>
#include<vector>
#include<fstream>

using namespace std;

//自定义链表的迭代器

int main32() {
	ifstream fst;
	fst.open("in.txt");
	list<vector<int>> list1;
	int line1, colunm1;//定义矩阵的行和列;
	fst >> line1 >> colunm1;
	list1.push_back({ line1,colunm1 });//将基准数据向量放入
	vector<int>read_data;
	for (int i = 0; i < line1; i++) {
		for (int j = 0; j< colunm1; j++) {
			int data;
			fst >> data;
			read_data.push_back(data);
		}
		list1.push_back(read_data);
		read_data.clear();
	}//把第一个矩阵存入链表当中
	read_data.clear();



	int line2, colunm2;
	fst >> line2 >> colunm2;
	list<vector<int>>list2;
	list2.push_back({ line2,colunm2 });
	for (int i = 0; i < line2; i++) {
		for (int j = 0; j < colunm2; j++) {
			int data;

			fst >> data;
			read_data.push_back(data);
		}
		list2.push_back(read_data);
		read_data.clear();
	}//把第二个矩阵存入链表当中

	//定义迭代器
	list<vector<int>>::iterator it1 = ++list1.begin();//获取的是头元素的下一个元素的迭代器
	

	//从输入中获取要比较的内容：
	int com_line1, com_line2;//其实这里要比较的是lie，但是line好打.
	cin >> com_line1 >> com_line2;
	list<vector<int>>::iterator it2 = ++list2.begin();



	list<vector<int>>result;//最终输出的链表
	for (; it1 != list1.end(); it1++) {
		list<vector<int>>::iterator it2 = ++list2.begin();
		for (; it2 != list2.end(); it2++) {
			
			if ((*it1).at(com_line1 - 1) == (*it2).at(com_line2 - 1) ){
				vector<int> common((*it1));
				common.insert(common.end(), (*it2).begin(), (*it2).end());
				result.push_back(common);
				
			}

		}
	}


	fst.close();
	

	ofstream ofs;
	ofs.open("abc.out.txt",std::ofstream::out);

	for (list<vector<int>>::iterator it = result.begin(); it != result.end(); it++) {
		for (auto i : (*it)) {
			cout << i << " ";
			ofs << i ;
			ofs << " ";
		}
		ofs << "\n";
		cout << endl;

	}
	
	ofs.close();
	return 0;
}