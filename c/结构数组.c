#include<stdio.h>
struct time {
	int hours; int minutes; int seconds;
};
//struct time timeupdate(struct time now);//����һ����������Ϊstruct time�ĺ����������Ϊstruct time now


int main6(void)
{
	//�ṹ����
	struct time testtime[5] = {
		{11,59,59},{12,0,0},{5,20,20},{24,2,20},{15,24,60}
	};//����һ��struct time���͵�����ṹ����һ�����ǵ�һ����������

	int i;
	for (i = 0; i < 5; i++) {
		printf("time now is %.2d\n", testtime[i].hours);
		
	}


	return 0;
}