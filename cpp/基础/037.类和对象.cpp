#include<iostream>
using namespace std;

class P {

};//����

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
		//��������֮��ľ��룺
		int distance = (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) +
			(c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());

		//����뾶��ƽ����

		int rdistance = c.getR() * c.getR();

		//�жϹ�ϵ��
		if (distance == rdistance) {
			cout << "����Բ��" << endl;
		}
		else if (distance > rdistance) {
			cout << "����԰��" << endl;
		}
		else {
			cout << "����Բ��" << endl;
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
	P p1;//�ն���ռ�ڴ�ռ�Ϊ ��1
	//���������ÿһ���ն���Ҳ����һ���ֽڿռ䣬��Ϊ������ն���ռ���ڴ�λ��
	//ÿ���ն�����һ����һ�޶��ĵ�ַ



	return 0;
}

