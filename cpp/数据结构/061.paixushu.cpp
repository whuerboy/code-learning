//#include<iostream>
//#include<vector>
//
//
//typedef struct BSTNode {
//	int data;
//	BSTNode* left;
//	BSTNode* right;
//	BSTNode() {
//		data = 0;
//		left = nullptr;
//		right = nullptr;
//	}
//	BSTNode(int data) {
//		this->data = data;
//		left = NULL;
//		right = NULL;
//	}
//}Node;
//
//class BSTree {
//public:
//	BSTNode* roof;
//	BSTree() {
//		roof = NULL;
//	}
//
//
//	void InsertBst(int data) {
//		this->roof = Insert(this->roof, data);
//	}
//
//	BSTNode* Insert(BSTNode* p, int data) {
//		if (p == NULL) {
//			p = new BSTNode(data);
//		}
//		else if (p->data > data) {
//			p->left = Insert(p->left, data);
//		}
//		else  {
//			p->right = Insert(p->right, data);
//		}
//		
//		return p;
//	}
//
//
//	void creat(std::vector<int>arr) {
//		for (unsigned int i = 0; i < arr.size(); i++) {
//			//InsertBst(arr[i]);
//			this->roof = Insert(this->roof, arr[i]);
//		}
//	}
//
//	BSTNode* find(BSTNode* b, int key, int& count) {
//		Node* temp = this->roof;
//		while (temp != NULL) {
//			count++;
//			if (temp->data == key) {
//				return temp;
//			}
//			else if(temp->data<key) {//在右子树里面寻
//				if (temp->right == NULL) {
//					return NULL;
//				}
//				else {
//					temp = temp->right;
//				}
//			}
//			else {
//				if (temp->left == NULL) {
//					return NULL;
//				}
//				else {
//					temp = temp->left;
//				}
//			}
//		}
//	}
//};
//
//void midorder1(Node* node, std::vector<int>& result)
//{
//	if (node != NULL) {
//		midorder1(node->left, result);
//		std::cout << node->data << " ";
//		result.push_back(node->data);
//		midorder1(node->right, result);
//	}
//}
//
//int BinSearch(std::vector<int>num, int target) {
//	int times = 0;
//	int front = 1;
//	unsigned int back = num.size();
//	while (front < back) {
//		int mid = (front + back) / 2;
//		times++;
//
//
//		if (num[mid - 1] == target) {
//			break;
//		}
//		else if (back == front) {
//			break;
//		}
//		else if (num[mid - 1] > target) {
//			back = mid - 1;
//		}
//		else if (num[mid - 1] < target) {
//			front = mid + 1;
//		}
//	}
//	return times;
//}
//
//void swap(int* a) {
//	std::cout << "swap函数" << a << " " << *a << std::endl;
//	*a=2;
//}
//
//
//int main() {
//	int size;
//	std::vector<int>arr = {9,8,7,6,5,4,3,2,1};
//
//	std::vector<int>result;
//	BSTree tree;
//	tree.creat(arr);
//	int find;
//	int count = 0;
//	std::cin >> find;
//	tree.find(tree.roof, find, count);
//	std::cout << count << std::endl;
//	midorder1(tree.roof, result);
//	std::cout << std::endl;
//	std::cout << BinSearch(result, find);
//	return 0;
//}
//


#include<iostream>
#include <vector>
using namespace std;

void maxSubstr(string s) {
	int maxi = 0, maxlen = 0, len, i, j, k;
	i = 0;
	while (i < s.length()) {
		j = i + 1;
		while (j < s.length()) {
			if (s[i] == s[j]) {//找一个字串，其起始下表为i，长度为len;
				len = 1;
				for (k = 1; s[i + k] == s[j + k]; k++) {
					len++;
				}
				if (len > maxlen) {
					maxi = i;
					maxlen = len;
				}
				j += len;
			}
			else {
				j++;
			}
		}
		i++;
	}
	
	for (int i = 0; i < maxlen; i++) {
		 cout<<s[maxi + i];
	}
	cout << endl;
}


void full(std::vector<int>& a, int size, int end,int& count) {
	if (end == 0) {
		//递归出口，完成一次全排列
		count++;
		for (auto i : a) {
			std::cout << i;
		}
		std::cout << std::endl;
	}
	else {
		for (int i = 0; i <= end; i++) {
			swap(a[i], a[end]);
			full(a, size, end - 1,count);
			swap(a[end], a[i]);
		}
	}
}

int main61() {
	int count = 0;
	string s = "abcdacbdeabcdefabcdefg";
	maxSubstr(s);
	std::vector<int>a = { 1,2,3,4,5 };
	full(a, a.size(), a.size() - 1,count);
	std::cout << count;
	return 0;
}