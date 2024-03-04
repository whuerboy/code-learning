#include<stdio.h>
typedef union {
	int i;
	char ch[sizeof(int)];

} cd;

int main10(void) {
	//union 有储存作用，所有成员共享一个空间，同一时间只有一个成员是有效的，union的大小是其最大的成员
	//初始化，对第一个成员做初始化
	cd s;
	int i;
	s.i = 1234;//1234的16进制是ox04d2;
	for (i = 0; i < sizeof(int); i++) {
		printf("%02hhx", s.ch[i]);
	}



	return 0;
}