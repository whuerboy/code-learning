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
}//����һ�����������ڲ���ָ�������¾Ϳ��Ըı�main����ṹ������ֵ

struct date get(struct date* p)
{
	scanf_s("%d", & p->x);
	scanf_s("%d", &p->y);//��ʱ����ָ�����ı�ṹ������ֵ
	return *p;

}

void main5(void) {
	struct date s;
	struct date a;
	s = getstruct();
	printf("%d,%d", s.x, s.y);
	struct date* p = &a;
	//p->y = 12;//�ȼ��� (*p).y =12
	*p = get(p);
	printf("%d", p->x);
}

	