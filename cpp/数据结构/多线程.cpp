#include<iostream>
#include<thread>

static auto is_Finish = false;

void doMoreWork() {
	using namespace std::literals::chrono_literals;
	std::cout << "function thread id = " << std::this_thread::get_id() << std::endl;
	while (!is_Finish) {
		std::cout << "hello" << std::endl;
		std::this_thread::sleep_for(1s);//�������̵��ٶȣ�����cpuռ����
		//this_threadͬ�ڶԵ�ǰ�߳���ָ��
	}
}

int main22() {
	std::thread worker(doMoreWork);//�̵߳�����ͨ������ָ�����ʽ���еģ�
	std::cin.get();
	is_Finish = true;//ֱ������������ʱֹͣ���
	worker.join();//�ȴ�һ���߳�������Ĺ���
	std::cout << "main thread id = " << std::this_thread::get_id() << std::endl;
	std::cout << "thread finish" << std::endl;
	std::cin.get();
	return 0;
}