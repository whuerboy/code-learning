from myadder import  myAdder
import  unittest #python的测试库,可以构建自己的测试类

#在终端使用python -m unittest指令可以进行测试
class TestMyAdder(unittest.TestCase):
    def setUp(self) :#所有的测试方法在运行前都会执行这个方法，可以在这里构建对象
        print("hello")
    #测试函数必须以test_为开头这样测试库才能检测到
    def test_positive_with_positive(self):
        self.assertEqual(myAdder(5,3),8)
    def test_positive_with_negetive(self):
        self.assertEqual(myAdder(-1,2),1)
