#include<iostream>
using namespace std;

class P {

};//空类

class Point {
private:
	int x, y;
public:
	void setX(int x) {
		this->x = x;
	}
	int getX() {
		return x;
	}
	void setY(int y) {
		this->y = y;
	}
	int getY() {
		return y;
	}
};

class Circle {
private:
	int r;
	Point center;

public:
	void setR(int r) {
		this->r = r;
	}
	int getR() {
		return r;
	}

	void setcenter(Point center) {
		this->center = center;
	}
	Point getCenter() {
		return center;
	}

	void ifInCirlce(Circle& c, Point& p) {
		//计算两点之间的距离：
		int distance = (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) +
			(c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());

		//计算半径的平方：

		int rdistance = c.getR() * c.getR();

		//判断关系：
		if (distance == rdistance) {
			cout << "点在圆上" << endl;
		}
		else if (distance > rdistance) {
			cout << "点在园外" << endl;
		}
		else {
			cout << "点在圆内" << endl;
		}
	}
};

int main37() {

	Point p,o;
	p.setX(10);
	p.setY(0);
	o.setX(0);
	o.setY(0);
	Circle c;
	c.setcenter(o);
	c.setR(10);
	c.ifInCirlce(c,p);
	P p1;//空对象占内存空间为 ：1
	//编译器会给每一个空对象也分配一个字节空间，是为了区别空对象占的内存位置
	//每个空对象都有一个独一无二的地址



	return 0;
}

