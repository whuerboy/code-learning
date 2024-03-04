#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>
#include<cstring>
int Max = 99999;
class hashNode {
public:
	int data;
	int used=0;//是否被初始化过;
	hashNode() {
		data = Max;
		used = 0;
	}
	hashNode(const hashNode& temp) {
		this->data = temp.data;
		this->used = temp.used;
	}
	
};

class HashCode {
public:
	std::vector<hashNode> hash;

	HashCode(std::vector<int>data) {
		int length = 200;
		if (data.size() > 200) {
			return;//肯定加不完全
		}
		for (unsigned int i = 0; i <= length; i++) {
			hashNode has;
			hash.push_back(has);
		}
		for (unsigned int i = 0; i < data.size(); i++) {		
			int key = data[i];
			int index = key % 199;//哈希函数
			if (hash[index%length].used == 0) {
				//未被修改过
				hash[index%length].data = data[i];
				hash[index% length].used = 1;
			}
			else {
				while ( hash[index%length].used != 0 ) {
					++index;
				}
				hash[index%length].data = data[i];
				hash[index%length].used = 1;
			}
		}
	}

	void findValue(int value) {
		int index = value % 199;
		bool iFind=false;
		std::vector<int>result;
		int length = 200;
		unsigned int count = 0;
		while ( (hash[index%length].data != value )) {
			count++;
			if (count > hash.size()) {
				iFind = false;
				break;//已经查找了一轮还没找到，直接退出
			}
			if (hash[index% length].used == 0) {
				iFind = false;
				break;
			}
					
			
			result.push_back(hash[index% length].data);
			//std::cout << hash[index % 199].data << " ";
			index++;
			
		}

	if (hash[index % length].data == value) {
		iFind = true;
		result.push_back(hash[index % length].data);
		//std::cout << hash[index % 199].data << " ";
	}
	else {
		iFind = false;
	}

		std::ofstream ofs;
		ofs.open("out.txt");
		if (iFind) {
			ofs << "True" << "\n";
		}
		else {
			ofs << "False" << "\n";
		}
		for (auto i : result) {
			std::cout << i << " ";
			ofs << i << " ";
		}
		ofs.close();
	}
};




int main45() {
	std::fstream fst("in.txt");
	int value;
	fst >> value;//读取需要检索的内容.
	std::vector<int>data;
	while (1) {
		int num;
		fst >> num;
		data.push_back(num);
		if (fst.eof())break;
	}
	fst.close();
	
	HashCode hashcode(data);
	hashcode.findValue(value);
	
	return 0;
}


