#include<iostream>
#include<thread>

static auto is_Finish = false;

void doMoreWork() {
	using namespace std::literals::chrono_literals;
	std::cout << "function thread id = " << std::this_thread::get_id() << std::endl;
	while (!is_Finish) {
		std::cout << "hello" << std::endl;
		std::this_thread::sleep_for(1s);//减缓进程的速度，减少cpu占用率
		//this_thread同于对当前线程下指令
	}
}

int main22() {
	std::thread worker(doMoreWork);//线程调用是通过函数指针的形式进行的，
	std::cin.get();
	is_Finish = true;//直到键盘有输入时停止输出
	worker.join();//等待一个线程完成他的工作
	std::cout << "main thread id = " << std::this_thread::get_id() << std::endl;
	std::cout << "thread finish" << std::endl;
	std::cin.get();
	return 0;
}