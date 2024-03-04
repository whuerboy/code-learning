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
	v.reserve(3);//预留位置可以vector扩容时所花的时间的性能
	//但是之所以还调用了三次拷贝构造是因为vect在建立时是在main函数栈中建立的，想要添加到vector容器所在的内存中还需要进行拷贝复制
	/*v.push_back(vect( 1,2,3 ));
	v.push_back(vect(4, 25 ,3));
	v.push_back(vect(15, 32, 3));*/
	v.emplace_back(1,2,3);
	v.emplace_back(4,5,6);
	v.emplace_back(7,8,9);//直接在vector的内存堆上加入数据
	return 0;
}