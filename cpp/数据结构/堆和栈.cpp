#include<iostream>
//�Ѻ�ջ�����ڴ�ram����ʵ���ڵ�����
//�����ڴ����ʱ�Ѻ�ջ�ķ��䷽ʽ�ǲ�һ����
//����������֮��ջ�Ͻ����ı������ڴ�ȫ�������գ������ϵ�Ҫ�Լ��ֶ��ͷŻ��ߵȵ��������

int main18() {
	int value;//��ջ�Ͽ���4���ֽڵ��ڴ洢��value��ֵ
	value = 5;
	int array[5];
	array[0] = 1;
	array[1] = 2;
	array[2] = 3;
	array[3] = 4;
	array[4] = 5;


	int* hvalue = new int;//�ڶ��Ͽ��ٿռ�
	*hvalue = 5;
	int* harray = new int[5];
	harray[0] = 1;
	harray[1] = 2;
	harray[2] = 3;
	harray[3] = 4;
	harray[4] = 5;
	delete hvalue;
	delete harray;
	hvalue = NULL;
	harray = NULL;
	return 0;
}