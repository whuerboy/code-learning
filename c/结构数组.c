#include<stdio.h>
struct time {
	int hours; int minutes; int seconds;
};
//struct time timeupdate(struct time now);//定义一个返回类型为struct time的函数，其参数为struct time now


int main6(void)
{
	//结构数组
	struct time testtime[5] = {
		{11,59,59},{12,0,0},{5,20,20},{24,2,20},{15,24,60}
	};//定义一个struct time类型的数组结构，第一个就是第一个数组的组成

	int i;
	for (i = 0; i < 5; i++) {
		printf("time now is %.2d\n", testtime[i].hours);
		
	}


	return 0;
}