#include<stdio.h>
enum color { red, yellow, green,numcolors };
int main3(void)
{
	//ö�����û�������������ͣ��ùؼ���enum������
	//  enum ö����������{����0������1 ��������������n};
	//ֻ����int���Ҵ�0��ʼ�������ǳ����������޸�
	//����ö��ʱ����ָ��ֵ
	//enum color{red = 1,green = 5,numcolor};

	int color = -1;
    int t = red;
    printf("%d\n", t);//enum ��ʵ���Կ���int
	char* colornames[numcolors] = { "red","yellow","green" };//����һ����/0��
	char* colorname = NULL;//��һ�����ַ���
	printf("��������ϲ������ɫ����:");
	scanf_s("%d", &color);
	if (color >= 0 && color < numcolors) {
		colorname = colornames[color];
	}
	else colorname = "unknow";

	printf("��ϲ������ɫ��%s\n", colorname);


	return 0;
}