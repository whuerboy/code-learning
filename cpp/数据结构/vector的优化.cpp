#include<iostream>
#include<vector>
struct vect {
private:
	double x, y, z;
public:
	vect(double x, double y, double z) :x(x), y(y), z(z) {

	};
	vect(const vect& v) {
		std::cout << "copy!" << std::endl;
	}
};
int main15() {
	std::vector<vect> v;
	v.reserve(3);//Ԥ��λ�ÿ���vector����ʱ������ʱ�������
	//����֮���Ի����������ο�����������Ϊvect�ڽ���ʱ����main����ջ�н����ģ���Ҫ��ӵ�vector�������ڵ��ڴ��л���Ҫ���п�������
	/*v.push_back(vect( 1,2,3 ));
	v.push_back(vect(4, 25 ,3));
	v.push_back(vect(15, 32, 3));*/
	v.emplace_back(1,2,3);
	v.emplace_back(4,5,6);
	v.emplace_back(7,8,9);//ֱ����vector���ڴ���ϼ�������
	return 0;
}