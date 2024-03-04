#include<iostream>
using namespace std;

template<class T>
class Myarray {
private:
	//数组：
	T* Address;//指针指向堆区开辟的真shi数组
	//容量：
	int have;
		//大小：
	int size;
public:
	int getSize() {
		return this->size;
	}

	int getHave(){
		return this->have;
	}

	Myarray(int have)//含参数的构造函数
	{
		cout << "有参数的构造函数调用" << endl;
		this->have = have;
		this->Address = new T[this->have];
		this->size = 0;
	}

	~Myarray() {
		cout << "析构函数调用" << endl;
		if (this->Address != NULL) {
			delete Address;
			this->Address = NULL;
		}
	}


	Myarray(const Myarray& arr) {
		cout << "复制构造函数调用" << endl;
		this->have = arr.have;//可能报错的点位
		this->size = arr.size;
		this->Address = new T[arr.have];
		//数据深拷贝：
		for (int i = 0; i < this->size; i++) {
			this->Address[i] = arr.Address[i];
		}
	}


	//operator 防止浅拷贝的问题存在
	Myarray& operator=(const Myarray &arr) {
		cout << "=运算符重载"<<endl;
		//先判断原来的堆区是否有数据：
		if (this->Address != NULL) {
			delete this->Address;
			this->Address = NULL;
			this->have = 0;
			this->size = 0;
		}

		//接下来进行深拷贝操作：
		this->have = arr.have;//可能报错的点位
		this->size = arr.size;
		this->Address = new T[arr.have];
		//数据深拷贝：
		for (int i = 0; i < this->size; i++) {
			this->Address[i] = arr.Address[i];
		}

		return *this;
	}


	//尾插法插入数据：
	void push(const T value) {
		if (this->have == this->size) {
			cout << "数组已满无法添加数据" << endl;
			return;
		}

		this->Address[this->size] = value;
		this->size++;

	}

	//数据尾部删除：
	void popback() {
		if (this->size == 0) {
			return;
		}

		this->size--;
	}

	//数据访问：【】重载
	T& operator[](int index) {
		return this->Address[index];

	}


};

int main62() {
	Myarray<int> arr1(5);
	for (int i = 0; i < 5; i++) {
		arr1.push(i);
		cout << "  " << arr1[i];
	}
	return 0;
}