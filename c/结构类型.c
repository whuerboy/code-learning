#include<stdio.h>
//һ���ṹ���Ǹ��ϵ���������
struct date {
	int month;
	int day;
	int year;
};//��Ҫ©�ֺ�
//��ʱ���к���������ʹ�ã���Ȼ���Ǳ��ر���

int main4(void)
{
	struct date today = { 11,20,2022 };
	//today.day = 20;
	//today.month = 11;
	//today.year = 2022;
	struct date month = { .month = 22,.year = 2022 };//��ʱ����Ĭ��0
	 



	return 0;
}