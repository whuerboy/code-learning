#include<stdio.h>
typedef union {
	int i;
	char ch[sizeof(int)];

} cd;

int main10(void) {
	//union �д������ã����г�Ա����һ���ռ䣬ͬһʱ��ֻ��һ����Ա����Ч�ģ�union�Ĵ�С�������ĳ�Ա
	//��ʼ�����Ե�һ����Ա����ʼ��
	cd s;
	int i;
	s.i = 1234;//1234��16������ox04d2;
	for (i = 0; i < sizeof(int); i++) {
		printf("%02hhx", s.ch[i]);
	}



	return 0;
}