from threading import  Thread


class MyThread(Thread):
    def __init__(self, name):
        super().__init__()
        self.name=name

    def run(self):
        for i in range(100):
            print(self.name,i)


if __name__=='__main__':
    t=MyThread('Thread1')
    t.start()
    t1=MyThread('Thread2')
    t1.start()

