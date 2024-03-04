#include<iostream>
using namespace std;
//案例需求：将电脑的cpu，显卡，内存条封装成抽象类，并且提供不同厂商不同的零件
//创建电脑类提供让电脑工作的函数，并且调用每个零工件的接口

//抽象不同零部件：
class CPU {
public:
	virtual void calculate() = 0;//计算
	~CPU() {};
};

class VideoCard {
public:
	virtual void display() = 0;//显示
	~VideoCard() {};
};

class Memory {
public:
	virtual void storage() = 0;//储存
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

} //初始化电脑
void Computer::work() {
	cpu->calculate();
	mem->storage();
	vc->display();
}


//厂商封装：
//Intel厂商：
class IntelCPU :public CPU {
public:
	virtual void calculate() {
		cout << "Intel的cpu开始计算  "<<endl;
	}//计算
	~IntelCPU() {};

};

class IntelVC :public VideoCard {
public:
	virtual void display() {
		cout << "Intel的显卡开始工作" << endl;
	}//显示
	~IntelVC() {};
};


class IntelMemory :public Memory {
public:
	virtual void storage() {
		cout << "Intel的储存条开始工作了" << endl;
	}

	~IntelMemory() {};
};


//Lenvo厂商：

class LenvoCPU :public CPU {
public:
	virtual void calculate() {
		cout << "Lenvo的cpu开始计算  " << endl;
	}//计算

	~LenvoCPU() {};

};

class LenvoVC :public VideoCard {
public:
	virtual void display() {
		cout << "Lenvo的显卡开始工作" << endl;
	}//显示

	~LenvoVC() {};
};


class LenvoMemory :public Memory {
public:
	virtual void storage() {
		cout << "Lenvo的储存条开始工作了" << endl;
	}

	~LenvoMemory() {};
};




//思路2；


class Band {
public:
	virtual  void showband() = 0;
	virtual void calculate() {}
	virtual void storage() {}
	virtual void display() {}
};


class Kurui :public Band{
	void calculate() {
		cout << "kurui的CPU开始工作了" << endl;
	}

	void storage() {
		cout << "kurui的内存条开始工作了" << endl;
	}

	void display() {
		cout << "kurui的显卡开始工作了" << endl;
	}

	void showband() {
		cout << "kurui组装的电脑开始工作了" << endl;
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


	//组装第一台电脑：
	CPU* cpu = new IntelCPU;
	VideoCard* vc = new IntelVC;
	Memory* mem = new IntelMemory;
	Computer* c1=new Computer(cpu, vc, mem);
	c1->work();
	delete c1;
	cout << "******************" << endl;
	//第二台电脑：
	Computer* c2 = new Computer(new LenvoCPU, new LenvoVC, new LenvoMemory);
	c2->work();
	cout << "******************" << endl;
	//第三台电脑
	NewComputer* c3 = new NewComputer(new Kurui);
	c3->dowork();

	return 0;
}