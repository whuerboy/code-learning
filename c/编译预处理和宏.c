#include<stdio.h>
//#��ͷ���Ǳ���Ԥ����Ĵ���ָ��
#define pi 3.14//����һ������ 
//�������治�üӷֺ�
//C���Եı������ڿ�ʼ����֮ǰ�����Ԥ�����������е����ֻ���ֵ
#define pri "%d\n"

#define prt printf("hello\n");\
		printf("world\n")
//Ԥ�ȶ���ĺ�
// _FILE_     _LINE_    _DATE_     _TIME_

//��Ķ�����Դ�����
#define cube(x) ((x)*(x)*(x))
//����ĺ궨������   #define rad1(x)  (x*57.14)
//	#define  rad2(x) (x)*57.14 
//ԭ��  һ�ж�Ҫ������  ������ֵҪ�����ţ��������ֵ�ÿ���ط�ҲҪ������
#define rad1(x) ((x)*57.12)

//��Ҳ���Դ��������
#define min(a,b) ((a)>(b)?(b):(a))


int main16(void)
{	
	int i = 0;
	printf(pri, i);
	prt;
	printf("%d\n", cube(5));
	printf("%0.2f\n", 180 / (rad1(1)));
	printf("%f\n", rad1(5));

	int x = 0, y = 1;
	int d =min(x, y);
	printf("%d", d);

	return 0;


}