#include<stdio.h>
int main8(void)
{//typedef �����µ����͵����֣���������ĳ�����͵ı���
	typedef int len;//��ʱint�ı�������len
	len i = 0;
	 
	typedef struct adata {
		len x;
		len y;
	}date;//��ʱdate �� struct adata �ı���
	date date1 = { 1,2 };//�´������ṹ����ʱ�Ͳ������鷳��


	return 0; 
}