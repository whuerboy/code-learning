#include<stdio.h>
struct point {
	int x;
	int y;
};//先定义小的再定义大的；
struct restruct {
	struct point m1  ;//定义一个结构为struct point的结构变量
	struct point m2;
};//这就有了结构里面的结构
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
	//则下面形式等价:
	//r.point1.x    ==   rp->point1.x  ==  (rp->point1).x   ==  (r.point1).x
	



	//return 0;
}