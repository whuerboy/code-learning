#include <iostream>
#include <vector>
#include<queue>
#include <sstream>
#include <stack>

using namespace std;


stringstream stream;

struct bitnode {
public:
	string data;
	bitnode* lchild;
	bitnode* rchild;
	bitnode() {
		data = "";
		lchild = rchild = NULL;
	}
	bitnode(string data) {
		this->data = data;
		lchild = rchild = NULL;
	}
};


bool isOperator(char ch) {
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int getPrecedence(char op) {
	if (op == '+' || op == '-') {
		return 1;
	}
	else if (op == '*' || op == '/') {
		return 2;
	}
	return 0;
}//���ȼ�

vector<string> convertToRPN(const string& expression) {
	vector<string> rpn;
	stack<char> operators;
	istringstream iss(expression);
	string token;
	char ch;

	while (iss >> ch) {
		if (ch >= '0' && ch <= '9') {
			string number;
			number += ch;
			while (iss >> ch && ch >= '0' && ch <= '9') {
				number += ch;
			}
			rpn.push_back(number);
		}

		if (isOperator(ch)) {
			while (!operators.empty() && operators.top() != '(' &&
				getPrecedence(operators.top()) >= getPrecedence(ch)) {
				rpn.push_back(string(1, operators.top()));
				operators.pop();
			}
			operators.push(ch);
		}

		if (ch == '(') {
			operators.push(ch);
		}

		if (ch == ')') {
			while (!operators.empty() && operators.top() != '(') {
				rpn.push_back(string(1, operators.top()));
				operators.pop();
			}
			if (!operators.empty() && operators.top() == '(') {
				operators.pop();
			}
		}
	}

	while (!operators.empty()) {
		rpn.push_back(string(1, operators.top()));
		operators.pop();
	}

	return rpn;
}

int result(vector<string> all) {
	int results = 0;

	stack<int>st;

	int len = all.size();
	for (int j = 0; j < len; j++) {
		string s = all[j];//ÿһ�����ŵ�Ԫ��
		if (s == "+" || s == "-" || s == "*" || s == "/") {
			int x1 = 0, x2 = 0, x3 = 0;
			x1 = st.top();
			st.pop();
			x2 = st.top();
			st.pop();
			if (s == "+") { x3 = x2 + x1; }
			if (s == "-") { x3 = x2 - x1; }
			if (s == "*") { x3 = x2 * x1; }
			if (s == "/") { x3 = x2 / x1; }
			st.push(x3);
		}
		else {
			stream << all[j];
			int number;
			stream >> number;
			st.push(number);//���������
			stream.clear();
		}
	}
	if (!st.empty()) {
		results = st.top();
		st.pop();
	}
	else {
		// ջΪ�գ���ʾ����ʧ��
		throw std::runtime_error("Calculation failed");
	}
	return results;
}//������

bitnode* creatTree(vector<bitnode*>nodes) {
	stack<bitnode*>creat;
	for (unsigned int i = 0; i < nodes.size(); i++) {
		if (nodes[i]->data == "+" || nodes[i]->data == "-" || nodes[i]->data == "*" || nodes[i]->data == "/") {
			bitnode* right = new bitnode();
			bitnode* left = new bitnode();
			right = creat.top();
			creat.pop();
			left = creat.top();
			creat.pop();
			nodes[i]->lchild = left;
			nodes[i]->rchild = right;
			creat.push(nodes[i]);
		}
		else {
			creat.push(nodes[i]);
		}
	}

	bitnode* root = new bitnode();
	root = creat.top();
	creat.pop();

	return root;
}

void preorder(bitnode* root) {
	if (root != NULL) {
		if (root->data != "+" && root->data != "-" && root->data != "*" && root->data != "/") {
			cout << root->data << "#";
		}
		else {
			cout << root->data;
		}

		preorder(root->lchild);
		preorder(root->rchild);
	}
}

void inorder(bitnode* root) {
	if (root != NULL) {
		inorder(root->lchild);
		if (root->data != "+" && root->data != "-" && root->data != "*" && root->data != "/") {
			cout << root->data << "#";
		}
		else {
			cout << root->data;
		}
		inorder(root->rchild);
	}
}

void postorder(bitnode* root) {
	if (root != NULL) {
		postorder(root->lchild);
		postorder(root->rchild);

		if (root->data != "+" && root->data != "-" && root->data != "*" && root->data != "/") {
			cout << root->data << "#";
		}
		else {
			cout << root->data;
		}
	}
}

void levelorder(bitnode* root) {
	if (root != NULL) {
		queue<bitnode*>last;
		last.push(root);
		while (!last.empty()) {

			bitnode* b = last.front();
			if (b->data != "+" && b->data != "-" && b->data != "*" && b->data != "/") {
				cout << b->data << "#";
			}
			else {
				cout << b->data;
			}
			last.pop();
			if (b->lchild != NULL) {
				last.push(b->lchild);
			}
			if (b->rchild != NULL) {
				last.push(b->rchild);
			}
		}
	}
}

int main38() {
	string s;
	cin >> s;//�������ʽ
	string ss = "";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '=') {
			break;
		}
		if (s[i] != ' ') {
			ss += s[i];
		}
	}

	vector<string>bolan(convertToRPN(ss));
	vector<bitnode*>nodes;

	for (unsigned int i = 0; i < bolan.size(); i++) {
		bitnode* b = new bitnode(bolan[i]);
		nodes.push_back(b);//ͨ���沨�����ʽ
	}

	bitnode* root = creatTree(nodes);//����������

	preorder(root);//ǰ�����
	cout << endl;
	inorder(root);//�������
	cout << endl;
	postorder(root);//�������
	cout << endl;
	levelorder(root);//��α���
	cout << endl;
	int end = result(bolan);
	cout << end << endl;;
	return 0;
}