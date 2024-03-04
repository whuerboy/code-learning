#include<iostream>
#include<vector>

typedef struct BSTNode {
	int data;
	BSTNode* left;
	BSTNode* right;
	BSTNode() {
		data = 0;
		left = nullptr;
		right = nullptr;
	}
	BSTNode(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}
}Node;

class BSTree {
public:
	BSTNode* roof;
	BSTree() {
		roof = NULL;
	}


	void InsertBst(int data) {
		this->roof = Insert(this->roof, data);
	}

	BSTNode* Insert(BSTNode* p, int data) {
		if (p == NULL) {
			p = new BSTNode(data);
		}
		else if (p->data > data) {
			p->left = Insert(p->left, data);
		}
		else if (p->data < data) {
			p->right = Insert(p->right, data);
		}
		else {
			p->data = data;
		}
		return p;
	}


	void insert(int val) {//�����в�����
		Node* node = new Node;
		node->data = val;
		if (this->roof == NULL) {//����
			this->roof = node;
		}
		else {
			Node* temp = this->roof;
			while (temp != NULL) {
				if (val < temp->data) {
					if (temp->left == NULL) {
						temp->left = node;
						return;
					}
					else {
						temp = temp->left;
					}
				}
				else {
					if (temp->right == NULL) {
						temp->right = node;
						return;
					}
					else {
						temp = temp->right;
					}
				}
			}
		}
	}
	void creat(std::vector<int>arr) {
		for (unsigned int i = 0; i < arr.size(); i++) {
			InsertBst(arr[i]);
			//insert(arr[i]);
		}
	}

	BSTNode* find(BSTNode* b, int key,int& count) {
		count++;
		if (b == NULL) {
			return NULL;
		}
		if (b->data == key) {
			return b;
		}
		else if (b->data < key) {
			return find(b->right, key,count);
		}
		else {
			return find(b->left, key,count);
		}
		//Node* temp = this->roof;
		//int count = 0;
		//while (temp != NULL) {
		//	count++;
		//	if (temp->data == key) {
		//		break;//return temp;
		//	}
		//	else if(temp->data<key) {//������������Ѱ
		//		if (temp->right == NULL) {
		//			break;//return NULL;
		//		}
		//		else {
		//			temp = temp->right;
		//		}
		//	}
		//	else {
		//		if (temp->left == NULL) {
		//			break;//return NULL;
		//		}
		//		else {
		//			temp = temp->left;
		//		}
		//	}
		//	return count;
		//}
	}

	Node* findFather(int data) {
		Node* temp = this->roof;
		if (temp->data == data) {
			return NULL;//���ڵ�û�и��ڵ�
		}
		while (temp != NULL) {
			if (data > temp->data) {//������
				if (temp->right != NULL) {
					if (temp->right->data == data) {
						return temp;
					}
					else {
						temp = temp->right;
					}
				}
				else {
					return NULL;
				}
			}
			else {//������
				if (temp->left == NULL) {
					return NULL;
				}
				else {
					if (temp->left->data == data) {
						return temp;
					}
					else {
						temp = temp->left;
					}
				}
			}
		}
	}
	Node* getParant(Node* node, Node* find) {
		if (node == NULL || node->left == find || node->right == find) {
			return node;
		}
		if (node->data > find->data) {
			Node* left = getParant(node->left, find);
			if (left != NULL) {
				return left;
			}
		}
		else {
			Node* right = getParant(node->right, find);
			if (right) {
				return right;
			}
		}


		return NULL;
	}

	void Delete(Node* node) {
		Node* temp = getParant(this->roof, node);
		if (node->left == NULL && node->right == NULL) {
			if (temp->data > node->data) {//������
				temp->left = NULL;
			}
			else {
				temp->right = NULL;
			}
			
		}
		else if (node->left && !(node->right)) {//��������Ϊ��,����������Ϊ��
			if (temp->data > node->data) {//���ڵ��ֵ���ӽ���
				temp->left = node->left;
			}
			else {
				temp->right = node->left;
			}

		}
		else if (!(node->left) && node->right) {
			if (temp->data > node->data) {
				temp->left = node->right;
			}
			else
			{
				temp->right = node->right;
			}

		}
		else {//������������Ϊ�գ������ӵ����ҽ��
			Node* t = node->left;//��ʱ���
			while (t->right != NULL) {

				t = t->right;
			}
			int m = t->data;
			if (t->left) {
				if (getParant(node, t) != node) {
					getParant(node, t)->right = t->left;
				}
				else {
					node->left = t->left;
				}
			}
			else {
				if (getParant(node, t) != node) {
					getParant(node, t)->right = NULL;
				}
				else {
					node->left = NULL;
				}
			}
			node->data = m;

		}
		node = NULL;
	}

};
	//ɾ��


	void midorder(Node* node, std::vector<int>& result)
	{
		if (node != NULL) {
			midorder(node->left,result);
			std::cout << node->data << " ";
			result.push_back(node->data);
			midorder(node->right,result);
		}
	}

	int midFind(std::vector<int>arr,int key) {
		unsigned int low = 0;
		unsigned int height = arr.size() - 1;
		int mid = (low + height) >>2;
		int count = 0;
		while (mid <= height) {
			count++;
			if (arr[mid] == key) {break;}
			else if (arr[mid] > key) { height = mid - 1; }
			else { low = mid + 1; }
		}
		return count;
	}


int main052() {
	int size;
	std::cin >> size;
	std::vector<int>arr;
	for (int i = 0; i < size; i++) {
		int data = 0;
		std::cin >> data;
		arr.push_back(data);
	}
	std::vector<int>result;
	BSTree tree;
	tree.creat(arr);
	int find;
	int count = 0;
	std::cin >> find;
	tree.find(tree.roof, find, count);
	std::cout << count << std::endl;
	midorder(tree.roof, result);
	std::cout << std::endl;
	std::cout << midFind(result, find);
	return 0;
}

