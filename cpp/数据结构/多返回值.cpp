#include<iostream>
//�෵��ֵ����ͨ���������飬�ṹ�壬�ַ�������ʽ���ض�����ֱ�ӷ���
// ����Ƿ��������������Է���pair����Ԫ��tuple
//Ҳ����ͨ�����ô�����Ϊ�����ķ���ֱ�Ӵ��ز���
struct name {
	int in;
	int out;
};

name adddan(int n) {
	return { n,2 * n };
}

int main17() {
	int in;
	int out;
	std::cin >> in;
	name n = adddan(in);
	std::cout << n.in << std::endl;
	std::cout << n.out << std::endl;
	return 0;
}