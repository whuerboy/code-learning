#include<stdio.h>
int main1(void)
{

	char* s1 = "hello world";//�ַ����������ڴ�Ĵ���Σ���ֻ���ģ������޸�
	//s[0] = 'b';����
	printf("%c\n", s1[0]);
	//�����޸ģ�����������
	char s[] = "heelo world";//��������ֻ����hello world��������������ȥ

	s[0] = 'b';
	printf("%p\n", s);
	printf("%p\n", &s);

	char a[][10] = { "hello" "world" };//a��һ���ַ������飬ÿһ�ж���10���ַ���С
	//a[0]---->char[10]
	//char* b[] = "heelo ";
		//b[0]----->  char*



	return 0;
}