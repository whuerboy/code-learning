#include<stdio.h>
#include<stdlib.h>
int main2(void)
{
	//int putchar(int ),��һ���ַ�����������ʾ���׼���дһ���ַ�������д�˼����ַ���EOF(-1)��ʾдʧ��
	//int getchar(void),�ӱ�׼�������һ���ַ�
 //   
	//int ch;
	//while ((ch = getchar()) != EOF) {
	//	putchar(ch);
	//}//EOF��ʱȴ���ܽ���������CTRL-cǿ�н������̣�Ctrl-z����

	//printf("EOF");
	////strlen �����ַ����ĳ���
	//char line[] = "hello";
	//printf("%lu\n", strlen(line));
	//printf("%lu", sizeof(line));

	//strcmp(s1,s2),�Ƚ������ַ��� o:si==s2, 1:s1>s2  -1:s1<s2
	char s1[] = "aab";
	char s2[] = "acd";
	printf("%d\n", strcmp(s1, s2));

	//strcpy(*restrict s1��*restrict s2 ),�Ѻ���������ַ���������ǰ������鲢����s1
	//restrict��ʾ�������鲻�ص�

	//strncpy(, , size_t n),��ʾ��࿽��n���ַ�  

	char* stc = "hello";
	char* dst = (char*)malloc(strlen(stc) + 1);
	strcpy(dst, stc);
	if (strcmp(stc, dst) == 0) {
		printf("yes");
	}
	free(dst);
	dst = NULL;

	//strcat(s1,s2),��s2������s1����,���ǲ���ȫ  strncat(, , n)�������n���ַ�  





	return 0;
}