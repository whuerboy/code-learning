#include<iostream>
#include<vector>
#include<fstream>
#include <string>
#include<cstdio>
struct DataNode {
	char word;
	std::string code;
	DataNode(char word, std::string code) {
		this->word = word;
		this->code = code;
	}
};

struct  HFMNode {
	char data;
	HFMNode* lchild;
	HFMNode* rchild;
	HFMNode() {
		data = NULL;
		lchild = nullptr;
		rchild = nullptr;
	}
};

class HFMTree {
public:
	HFMNode* roof;//根节点
	HFMTree() {
		roof = new HFMNode;
		roof->data = NULL;
		roof->lchild = nullptr;
		roof->rchild = nullptr;
	}


   void getHFM(std::vector<DataNode> nodes)//构造哈夫曼树
	{
		for (auto i : nodes) {
			HFMNode *temp = roof;
			for (int j = 0; j < i.code.length(); j++) {
				if (i.code[j] == '0') {
					if (temp->lchild == nullptr) {
						temp->lchild = new HFMNode;
					}
					temp = temp->lchild;
				}
				else {
					if (temp->rchild == nullptr) {
						temp->rchild = new HFMNode;
					}
					temp = temp->rchild;
				}
				
			}
			temp->data = i.word;
		}
	
	}
};

void getHFM(std::string hfmCode, HFMTree hfm) {
	HFMNode* temp = hfm.roof;
	for (unsigned int i = 0; i < hfmCode.length(); i++) {
		if (hfmCode[i] == '0') {
			temp = temp->lchild;
			if (temp->data != NULL) {
				std::cout << temp->data;
				temp = hfm.roof;
			}
		}
		if(hfmCode[i]=='1') {
			temp = temp->rchild;
			if (temp->data != NULL) {
				std::cout << temp->data;
				temp = hfm.roof;
			}
		}
	}

	delete temp;
}


int main37() {
	int size;
	std::cin >> size;
	std::vector<DataNode> nodes;
	std::cin.ignore();//如果不清空缓冲区，则会造成下面的读取少一次；
	for (int i = 0; i < size; i++) {
		std::string data;
		char word; std::string code;
		//std::cin >> data;
		getline(std::cin, data);
		word = data[0];
		for (int i = 2; i < data.length(); i++) {
			code += data[i];
		}
		DataNode node(word, code);
		nodes.push_back(node);
	}
	HFMTree hfm;
	hfm.getHFM(nodes);
	std::ifstream ifs("in.txt");
	std::string hfmCode;
	ifs >> hfmCode;
	getHFM(hfmCode, hfm);
	return 0;
}