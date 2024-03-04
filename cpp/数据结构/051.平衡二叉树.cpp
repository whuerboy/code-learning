#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<cmath>
class TreeNode {
public:
	std::string data;
	TreeNode* lchild;
	TreeNode* rchild;
	TreeNode() {
		data = " ";
		lchild = nullptr;
		rchild = nullptr;
	}
	TreeNode(std::string str) {
		this->data = str;
		lchild = nullptr;
		rchild = nullptr;
	}
};


	TreeNode *creaTree(std::vector<std::string>arr,int index) {
		if (index < arr.size()) {
			if (arr[index] == "null") {
				return NULL;
			}
			else {
				TreeNode* treenode = new TreeNode;//¿Õ½áµã
				treenode->data = arr[index];
				treenode->lchild = creaTree(arr, 2 * index + 1);
				treenode->rchild = creaTree(arr, 2 * index + 2);
				return treenode;
			}
		}
		else {
			return NULL;
		}
	}




int getHeight(TreeNode* b) {
	if (b == nullptr)
		return 0;
	else return std::max(getHeight(b->lchild), getHeight(b->rchild)) + 1;
}

bool ifBalance(TreeNode* root) {
	/*std::cout << getHeight(roof->lchild) << std::endl;
	std::cout << getHeight(roof->rchild) << std::endl;
	bool ib=std::abs(getHeight(roof->lchild) - getHeight(roof->rchild)) <= 1;
	return ib && ifBalncce(roof->lchild) && ifBalncce(roof->rchild);*/
	if (root == nullptr) {
		return true;
	}

	int leftHeight = getHeight(root->lchild);
	int rightHeight = getHeight(root->rchild);
	int maxHeight = std::max(leftHeight, rightHeight);

	return abs(leftHeight - rightHeight) <= 1 &&
		ifBalance(root->lchild) &&
		ifBalance(root->rchild);
	
}


int main051() {
	std::fstream fst("in.txt");
	std::string str;
	std::vector<std::string>data;
	while (1) {
		fst >> str;
		data.push_back(str);
		if (fst.eof()) {
			break;
		}
	}
	fst.close();
	std::ofstream ofs("out.txt");
	TreeNode* roof = creaTree(data, 0);
	if (ifBalance(roof)) {
		ofs << "True";
	}
	else {
		ofs << "False";
	}
	ofs.close();
	return 0;
}