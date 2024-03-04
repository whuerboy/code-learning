try:
    weigth = float(input("请输入您的体重： "))
    height = float(input("请输入您的身高:  "))
    BMI = weigth/height**2
except ValueError:
    print("请输入正确的数字 ")
except ZeroDivisionError:
    print("您的身高不能为0大傻逼: ")
except:
    print("发生未知错误")
else :
    print(f"BMI的值为{BMI}")
finally:
    print("程序运行结束")