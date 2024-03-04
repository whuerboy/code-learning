#include<stdio.h>
#include<stdlib.h>
int main2(void)
{
	//int putchar(int ),是一个字符串函数，表示向标准输出写一个字符，返回写了几个字符，EOF(-1)表示写失败
	//int getchar(void),从标准输入读入一个字符
 //   
	//int ch;
	//while ((ch = getchar()) != EOF) {
	//	putchar(ch);
	//}//EOF此时却不能结束程序，用CTRL-c强行结束进程，Ctrl-z结束

	//printf("EOF");
	////strlen 返回字符串的长度
	//char line[] = "hello";
	//printf("%lu\n", strlen(line));
	//printf("%lu", sizeof(line));

	//strcmp(s1,s2),比较两个字符串 o:si==s2, 1:s1>s2  -1:s1<s2
	char s1[] = "aab";
	char s2[] = "acd";
	printf("%d\n", strcmp(s1, s2));

	//strcpy(*restrict s1，*restrict s2 ),把后面数组的字符串拷贝到前面的数组并返回s1
	//restrict表示两个数组不重叠

	//strncpy(, , size_t n),表示最多拷贝n个字符  

	char* stc = "hello";
	char* dst = (char*)malloc(strlen(stc) + 1);
	strcpy(dst, stc);
	if (strcmp(stc, dst) == 0) {
		printf("yes");
	}
	free(dst);
	dst = NULL;

	//strcat(s1,s2),把s2拷贝到s1后面,但是不安全  strncat(, , n)最多连接n个字符  





	return 0;
}