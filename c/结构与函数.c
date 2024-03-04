#include<stdio.h>
#include<stdlib.h>
struct date {
	int x; int y;
};
struct date getstruct(void) {
	struct date p;
	scanf_s("%d", &p.x);
	scanf_s("%d", &p.y);
	return p;
}//构造一个函数可以在不用指针的情况下就可以改变main里面结构变量的值

struct date get(struct date* p)
{
	scanf_s("%d", & p->x);
	scanf_s("%d", &p->y);//此时利用指针来改变结构变量的值
	return *p;

}

void main5(void) {
	struct date s;
	struct date a;
	s = getstruct();
	printf("%d,%d", s.x, s.y);
	struct date* p = &a;
	//p->y = 12;//等价于 (*p).y =12
	*p = get(p);
	printf("%d", p->x);
}

	