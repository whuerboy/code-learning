#include<iostream>
using namespace std;
//�������󣺽����Ե�cpu���Կ����ڴ�����װ�ɳ����࣬�����ṩ��ͬ���̲�ͬ�����
//�����������ṩ�õ��Թ����ĺ��������ҵ���ÿ���㹤���Ľӿ�

//����ͬ�㲿����
class CPU {
public:
	virtual void calculate() = 0;//����
	~CPU() {};
};

class VideoCard {
public:
	virtual void display() = 0;//��ʾ
	~VideoCard() {};
};

class Memory {
public:
	virtual void storage() = 0;//����
	~Memory() {};
};

class Computer {
public: 
	void work();
	Computer(CPU* cpu, VideoCard* vc, Memory* mem);
	~Computer() {
		if (cpu != NULL) {
			delete cpu;
			cpu = NULL;
		}

		if (vc != NULL) {
			delete vc;
			vc = NULL;
		}

		if (mem != NULL) {
			delete mem;
			mem = NULL;
		}
	}
private:
	CPU* cpu;
	VideoCard* vc;
	Memory* mem;
};


Computer::Computer(CPU* cpu, VideoCard* vc, Memory* mem) :cpu(cpu), vc(vc), mem(mem) {

} //��ʼ������
void Computer::work() {
	cpu->calculate();
	mem->storage();
	vc->display();
}


//���̷�װ��
//Intel���̣�
class IntelCPU :public CPU {
public:
	virtual void calculate() {
		cout << "Intel��cpu��ʼ����  "<<endl;
	}//����
	~IntelCPU() {};

};

class IntelVC :public VideoCard {
public:
	virtual void display() {
		cout << "Intel���Կ���ʼ����" << endl;
	}//��ʾ
	~IntelVC() {};
};


class IntelMemory :public Memory {
public:
	virtual void storage() {
		cout << "Intel�Ĵ�������ʼ������" << endl;
	}

	~IntelMemory() {};
};


//Lenvo���̣�

class LenvoCPU :public CPU {
public:
	virtual void calculate() {
		cout << "Lenvo��cpu��ʼ����  " << endl;
	}//����

	~LenvoCPU() {};

};

class LenvoVC :public VideoCard {
public:
	virtual void display() {
		cout << "Lenvo���Կ���ʼ����" << endl;
	}//��ʾ

	~LenvoVC() {};
};


class LenvoMemory :public Memory {
public:
	virtual void storage() {
		cout << "Lenvo�Ĵ�������ʼ������" << endl;
	}

	~LenvoMemory() {};
};




//˼·2��


class Band {
public:
	virtual  void showband() = 0;
	virtual void calculate() {}
	virtual void storage() {}
	virtual void display() {}
};


class Kurui :public Band{
	void calculate() {
		cout << "kurui��CPU��ʼ������" << endl;
	}

	void storage() {
		cout << "kurui���ڴ�����ʼ������" << endl;
	}

	void display() {
		cout << "kurui���Կ���ʼ������" << endl;
	}

	void showband() {
		cout << "kurui��װ�ĵ��Կ�ʼ������" << endl;
	}

};

class NewComputer{
private:
	Band* band;

public:

	NewComputer(Band* band) {
		this->band = band;
	}

	void dowork() {
		band->showband();
		band->calculate();
		band->display();
		band->storage();
	}

	~NewComputer() {
		if (band != NULL) {
			delete band;
			band = NULL;
		}
	}

};




int main51() {


	//��װ��һ̨���ԣ�
	CPU* cpu = new IntelCPU;
	VideoCard* vc = new IntelVC;
	Memory* mem = new IntelMemory;
	Computer* c1=new Computer(cpu, vc, mem);
	c1->work();
	delete c1;
	cout << "******************" << endl;
	//�ڶ�̨���ԣ�
	Computer* c2 = new Computer(new LenvoCPU, new LenvoVC, new LenvoMemory);
	c2->work();
	cout << "******************" << endl;
	//����̨����
	NewComputer* c3 = new NewComputer(new Kurui);
	c3->dowork();

	return 0;
}