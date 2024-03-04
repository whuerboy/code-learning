#当程序进行IO操作时，如input(),print()等，程序处于阻塞状态
#request。post（），get()同样也是
#协程：当程序阻塞时，可以选择性的切换到其他任务上，一般就是遇到IO操作时
#在微观上是一个任务切换到另一个操作，切换条件是遇到IO
#在宏观上就是多个任务异步执行，当然这是只有一个线程时的工作。





import asyncio
import  time
async def func1():
    print("hello world")
    await asyncio.sleep(1)
    print("hello world")

async def func2():
    print("python")
    await asyncio.sleep(2)
    print("python")

async def func3():
    print('java')
    await asyncio.sleep(3)
    print('java')

async  def main():
    tasks = [asyncio.create_task(func1()),
             asyncio.create_task(func2()),
             asyncio.create_task(func3())]
    await  asyncio.wait(tasks)


if __name__ =="__main__":
    start = time.time()
    asyncio.run(main())
    print(time.time()-start)