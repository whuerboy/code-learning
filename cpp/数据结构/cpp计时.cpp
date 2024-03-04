#include<iostream>
#include<chrono>
#include<thread>

namespace cpptime {
	class Timer {
	public:
		std::chrono::time_point<std::chrono::steady_clock> start, end;
		std::chrono::duration<float> duration;
		Timer() {
			start = std::chrono::high_resolution_clock::now();
		}
		~Timer() {
			end = std::chrono::high_resolution_clock::now();
			duration = end - start;
			std::cout << " time = " << (duration.count()) * 1000.0f << "ms\n"  ;
		}
	};

	void func() {
		Timer timer;
		int i = 0;
		while (i < 100) {
			std::cout << "hello " << std::endl;
			i++;
		}
	}
}

int main23() {


	//using namespace std::literals::chrono_literals;
	//auto start = std::chrono::high_resolution_clock::now();//获取现在的时间
	//std::this_thread::sleep_for(1s);
	//auto end = std::chrono::high_resolution_clock::now();
	//std::chrono::duration<float> dutation = end - start;//高精度计时
	//std::cout << "time = " <<dutation.count() << std::endl;


	cpptime::func();
	std::cin.get();
	return 0;
}