#include<stdio.h>
typedef  struct point {
	int x;
	int y;
}point;

 typedef  struct res {
	struct point t;
	struct point m;
}res;

int main9(void)
{
	int x = 0;
	int y = 0;
	point point1 = { x,y };
	point point2 = { 2 ,3 };
	res res1 = { point1,point2 };
	res1.m.x = 12;
	printf("%d\n", res1.m.y);
	printf("%d", res1.t.y);




	return 0;

}