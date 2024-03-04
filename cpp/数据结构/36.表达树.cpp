#include<iostream>
#include<vector>
#include<sstream>
#include<stack>
#include<stack>
#define cmp(c) (c=='+'||c=='-'||c=='*'||c=='/') //方便后续的比较


struct node {//二叉树结点的数据结构
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
	Tree() {//构造空树：
		
		head.data = NULL;
		head.left = nullptr;
		head.right = nullptr;
	}

	void geTree(std::vector<char> dbacklist,std::stack<node>&treeNode)//将后缀表达式转化成二叉树
	{
		for (auto i : dbacklist) {
			if (isdigit(i)) {//遇到数字则直接创建结点然后入栈
				node temp;
				temp.data = i;
				temp.left = nullptr;
				temp.right = nullptr;
				treeNode.push(temp);
				temp.left = NULL;
				temp.right = NULL;
			}
			else{//遇到运算符：
				node temp;
				node* left = new node();
				node* right = new node();
				temp.data = i;//记得加判断！！不然会造成严重的内存错误
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



	void aheadGet( node *nod)//前序遍历
	{
		if (nod != nullptr) {
			std::cout << nod->data;
			aheadGet(nod->left);
			aheadGet(nod->right);
		}
		std::cout << std::endl;
	}

};


int getPriority(char op)//定义优先级
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
		if (isdigit(i) != 0)//库函数，判断字符是否是数字
		{
			result.push_back(i);
		}
		else {//是运算符和括号：
			if (op.empty()) {
				op.push(i);
			}
			else if (i == '(') {
				op.push(i);
			}
			else if (i == ')') {
				while (op.top() != '(')//由于判断条件写错成’）‘导致错误
				{
					char temp = op.top();
					result.push_back(temp);
					op.pop();
				}
				op.pop();//左括号出栈
			}
			else {
				//栈不为空时，则要考虑优先级:
				while (getPriority(op.top()) >= getPriority(i)) {
					//当栈顶元素的优先级比要入栈的>=时，栈顶元素出栈;
					char temp = op.top();
					result.push_back(temp);
					op.pop();
					if (op.empty())//因为第一次没有判断为空导致报错
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
	std::vector<char> backlist;//记录后缀表达式
	std::vector<char> atring;//将string转化成char
	std::stack<node> treeNode;//记录结点
	Tree tree;
	for (int i = 0; i < data.length()-1; i++) //等号不读取
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