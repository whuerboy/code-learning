#include<stdio.h>
//�����ں����ⲿ�ı���
int g = 12;
int f(void);//ȫ�ֱ���δ��ʼ��ʱϵͳ�Զ���ֵΪ0��null
//�������ڲ���һ����ȫ�ֱ���ͬ���ı���ʱ��ȫ�ֱ����ڸú����ڻᱻ����

int main14(void) {
	printf(" main  g =%d\n", g);
	f();
	printf("   main g=%d\n", g);

	return 0;
}

int f(void) {
	printf(" f  g =%d\n", g);
	g++;
	printf(" f  g =%d\n", g);

	return g;
}