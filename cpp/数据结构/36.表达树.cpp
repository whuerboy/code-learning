#include<iostream>
#include<vector>
#include<sstream>
#include<stack>
#include<stack>
#define cmp(c) (c=='+'||c=='-'||c=='*'||c=='/') //��������ıȽ�


struct node {//�������������ݽṹ
	char data;
	node* left;
	node *right;
	node() {
		data = NULL;
		left = nullptr;
		right = nullptr;
	}
	node(char data) : data(data), left(nullptr), right(nullptr) {}
};

class Tree {
public: 
	node head;
	Tree() {//���������
		
		head.data = NULL;
		head.left = nullptr;
		head.right = nullptr;
	}

	void geTree(std::vector<char> dbacklist,std::stack<node>&treeNode)//����׺���ʽת���ɶ�����
	{
		for (auto i : dbacklist) {
			if (isdigit(i)) {//����������ֱ�Ӵ������Ȼ����ջ
				node temp;
				temp.data = i;
				temp.left = nullptr;
				temp.right = nullptr;
				treeNode.push(temp);
				temp.left = NULL;
				temp.right = NULL;
			}
			else{//�����������
				node temp;
				node* left = new node();
				node* right = new node();
				temp.data = i;//�ǵü��жϣ�����Ȼ��������ص��ڴ����
				temp.left = &(treeNode.top());
				treeNode.pop();
				temp.right = &(treeNode.top());
				treeNode.pop();			
				treeNode.push(temp);
				temp.left = NULL;
				temp.right = NULL;
			}
		}
		this->head = treeNode.top();

	}



	void aheadGet( node *nod)//ǰ�����
	{
		if (nod != nullptr) {
			std::cout << nod->data;
			aheadGet(nod->left);
			aheadGet(nod->right);
		}
		std::cout << std::endl;
	}

};


int getPriority(char op)//�������ȼ�
{
	int priority=-1;
	if (op == '*' || op == '/')
		priority = 2;
	if (op == '+' || op == '-')
		priority = 1;
	if (op == '(')
		priority = 0;
	return priority;
}

std::vector<char> changeToBack(std::vector<char> data) {
	std::stack<char> op;
	std::vector<char> result;
	for (auto i : data) {
		if (isdigit(i) != 0)//�⺯�����ж��ַ��Ƿ�������
		{
			result.push_back(i);
		}
		else {//������������ţ�
			if (op.empty()) {
				op.push(i);
			}
			else if (i == '(') {
				op.push(i);
			}
			else if (i == ')') {
				while (op.top() != '(')//�����ж�����д��ɡ��������´���
				{
					char temp = op.top();
					result.push_back(temp);
					op.pop();
				}
				op.pop();//�����ų�ջ
			}
			else {
				//ջ��Ϊ��ʱ����Ҫ�������ȼ�:
				while (getPriority(op.top()) >= getPriority(i)) {
					//��ջ��Ԫ�ص����ȼ���Ҫ��ջ��>=ʱ��ջ��Ԫ�س�ջ;
					char temp = op.top();
					result.push_back(temp);
					op.pop();
					if (op.empty())//��Ϊ��һ��û���ж�Ϊ�յ��±���
					{
						break;
					}
				}
				op.push(i);
			}
		}

	}
	while (!op.empty()) {
		char temp = op.top();
		result.push_back(temp);
		op.pop();
	}
	return result;
}




int main36() {
	std::string data;
	std::cin >> data;
	std::vector<char> backlist;//��¼��׺���ʽ
	std::vector<char> atring;//��stringת����char
	std::stack<node> treeNode;//��¼���
	Tree tree;
	for (int i = 0; i < data.length()-1; i++) //�ȺŲ���ȡ
	{
		if (data[i] == ' ') {
			continue;
		}
		atring.push_back(data[i]);
	}
	backlist = changeToBack(atring);
	for (auto i : backlist) {
		std::cout << i;
	}
	tree.geTree(backlist, treeNode);
	node* roof = new node;
	roof = &tree.head;
	tree.aheadGet(roof);
	return 0;
	
}