#include<stdio.h>
struct point {
	int x;
	int y;
};//�ȶ���С���ٶ����ģ�
struct restruct {
	struct point m1  ;//����һ���ṹΪstruct point�Ľṹ����
	struct point m2;
};//������˽ṹ����Ľṹ
struct book {
	char title;
	char author;
};

struct res {
	struct book   ;
	struct point ;
};



int main7(void)
{
	struct restruct* rp;
	int x = 0, y = 0;
	struct point point1 = { x,y }; 
	struct point point2 = { y,x*y };
	struct restruct r = { point1,point2 };
	rp = &r;
	//��������ʽ�ȼ�:
	//r.point1.x    ==   rp->point1.x  ==  (rp->point1).x   ==  (r.point1).x
	



	//return 0;
}