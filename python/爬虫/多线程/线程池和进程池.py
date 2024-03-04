#线程池：一次性开辟多个线程，直接给线程池提交任务，线程任务的调度交给线程池来完成

from concurrent.futures import ThreadPoolExecutor 

def func(name):
    for i in range(100):
        print(name,i)

if __name__=="__main__":
    with ThreadPoolExecutor(50) as f:
        for i in range(100):
            f.submit(func,name=f"Thread{i}")

    print(123)

