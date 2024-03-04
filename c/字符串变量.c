#include<stdio.h>
int main1(void)
{

	char* s1 = "hello world";//字符串代码在内存的代码段，是只读的，不能修改
	//s[0] = 'b';不行
	printf("%c\n", s1[0]);
	//若想修改，则利用数组
	char s[] = "heelo world";//编译器将只读的hello world拷贝到数组那里去

	s[0] = 'b';
	printf("%p\n", s);
	printf("%p\n", &s);

	char a[][10] = { "hello" "world" };//a是一个字符串数组，每一行都有10个字符大小
	//a[0]---->char[10]
	//char* b[] = "heelo ";
		//b[0]----->  char*



	return 0;
}