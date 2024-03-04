#include<iostream>
using namespace std;

template<class T>
class Myarray {
private:
	//���飺
	T* Address;//ָ��ָ��������ٵ���shi����
	//������
	int have;
		//��С��
	int size;
public:
	int getSize() {
		return this->size;
	}

	int getHave(){
		return this->have;
	}

	Myarray(int have)//�������Ĺ��캯��
	{
		cout << "�в����Ĺ��캯������" << endl;
		this->have = have;
		this->Address = new T[this->have];
		this->size = 0;
	}

	~Myarray() {
		cout << "������������" << endl;
		if (this->Address != NULL) {
			delete Address;
			this->Address = NULL;
		}
	}


	Myarray(const Myarray& arr) {
		cout << "���ƹ��캯������" << endl;
		this->have = arr.have;//���ܱ���ĵ�λ
		this->size = arr.size;
		this->Address = new T[arr.have];
		//���������
		for (int i = 0; i < this->size; i++) {
			this->Address[i] = arr.Address[i];
		}
	}


	//operator ��ֹǳ�������������
	Myarray& operator=(const Myarray &arr) {
		cout << "=���������"<<endl;
		//���ж�ԭ���Ķ����Ƿ������ݣ�
		if (this->Address != NULL) {
			delete this->Address;
			this->Address = NULL;
			this->have = 0;
			this->size = 0;
		}

		//�������������������
		this->have = arr.have;//���ܱ���ĵ�λ
		this->size = arr.size;
		this->Address = new T[arr.have];
		//���������
		for (int i = 0; i < this->size; i++) {
			this->Address[i] = arr.Address[i];
		}

		return *this;
	}


	//β�巨�������ݣ�
	void push(const T value) {
		if (this->have == this->size) {
			cout << "���������޷��������" << endl;
			return;
		}

		this->Address[this->size] = value;
		this->size++;

	}

	//����β��ɾ����
	void popback() {
		if (this->size == 0) {
			return;
		}

		this->size--;
	}

	//���ݷ��ʣ���������
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